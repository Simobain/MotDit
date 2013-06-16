#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QInputDialog>
#include <QMessageBox>
#include <QStringListModel>
#include <QStringList>
#include <QSettings>
#include <QMessageBox>
#include <QListView>
#include <QIcon>




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), last_widget(0)
{
    ui->setupUi(this);
    QObject :: connect(ui->actionArticle, SIGNAL(triggered()), this, SLOT(creerArticle()));
    QObject :: connect(ui->actionImage, SIGNAL(triggered()), this, SLOT(creerImage()));
    QObject :: connect(ui->actionVid_o, SIGNAL(triggered()), this, SLOT(creerVideo()));
    QObject :: connect(ui->actionAudio, SIGNAL(triggered()), this, SLOT(creerAudio()));
    QObject :: connect(ui->actionDocument, SIGNAL(triggered()), this, SLOT(creerDocument()));
    QObject :: connect(ui->actionDefinir_un_nouvel_espace_de_travail, SIGNAL(triggered()), this, SLOT(changerEspaceTravail()));

    QObject :: connect(ui->actionFermer, SIGNAL(triggered()), this, SLOT(close()));
    QObject :: connect(ui->actionSauvegarder,SIGNAL(triggered()),this,SLOT(sauverClicked()));

    QObject :: connect(ui->listView,SIGNAL(clicked(const QModelIndex&)),this,SLOT(itemClicked(const QModelIndex&)));
    QObject :: connect(ui->sauver,SIGNAL(clicked()),this,SLOT(sauverClicked()));
    QObject :: connect(ui->suppr, SIGNAL(clicked()), this, SLOT(supprClicked()));
    QObject :: connect(ui->onglets, SIGNAL(currentChanged(int)), this, SLOT(ongletChange(int)));
    QObject :: connect(ui->exphtml, SIGNAL(clicked()), this, SLOT(saveExportHtml()));
    QObject :: connect(ui->explatex, SIGNAL(clicked()), this, SLOT(saveExportLatex()));
    QObject :: connect(ui->exptxt, SIGNAL(clicked()), this, SLOT(saveExportText()));


    QObject :: connect(ui->ajout, SIGNAL(clicked()), this, SLOT(ajoutSousNotes()));
    QObject :: connect(ui->suppSous, SIGNAL(clicked()), this, SLOT(suppSousNotes()));

    qDebug()<<"1";
    ui->onglets->setTabText(0, "Edit");
    ui->onglets->setTabText(1, "HTML");
    ui->onglets->setTabText(2, "TeX");
    ui->onglets->setTabText(3, "Text");

    ui->listView->setMovement(QListView::Static);
    ui->listView->setFlow(QListView::TopToBottom);
    ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setEditTriggers(0);
    model=new QStringListModel();

    ui->sauver->setEnabled(false);
    ui->sauver->setIcon(QIcon("disquette.png"));
    ui->sauver->setIconSize(QSize(15,15));
    ui->suppr->setIcon(QIcon("poubelle.png"));
    ui->suppr->setIconSize(QSize(20,20));

    ui->ajout->setHidden(true);
    ui->suppSous->setHidden(true);

    // On ajoute les notes a la liste pour pouvoir les afficher dans la listview

    NotesManager* nm=NotesManager::getInstance();
    const QSet<Note*>& listeNotes = nm->getEnsnote();
    QSet<Note*>::const_iterator it=listeNotes.begin();
    while(it!=listeNotes.end()){

        liste.append((*it)->getTitre());
        it++;
    }
    model->setStringList(liste);
    ui->listView->setModel(model);

    listeAjout= new QListView;
    listeAjout->setMovement(QListView::Static);
    listeAjout->setFlow(QListView::TopToBottom);
    listeAjout->setViewMode(QListView::ListMode);
    modelAjout= new QStringListModel;
    listeAjout->setModel(modelAjout);
    QObject::connect(listeAjout,SIGNAL(clicked(const QModelIndex&)), this, SLOT(sousNotesSelected(const QModelIndex&))) ;

    listeSupp= new QListView;
    listeSupp->setMovement(QListView::Static);
    listeSupp->setFlow(QListView::TopToBottom);
    listeSupp->setViewMode(QListView::ListMode);
    modelSupp= new QStringListModel;
    listeSupp->setModel(modelSupp);
    QObject::connect(listeSupp,SIGNAL(clicked(const QModelIndex&)), this, SLOT(sousNotesASuppSelected(const QModelIndex&))) ;

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::creerArticle(){
    creerNote("article");
}

void MainWindow::creerImage(){

    QString path=QFileDialog::getOpenFileName(this,tr("Choix de l'image"), qApp->applicationDirPath(), tr("*.jpg, *.png"));// j'ai enlevé le debut des filtres et maintenant ça remarche.
    creerNote("image", path);

}

void MainWindow::creerVideo(){

    QString path=QFileDialog::getOpenFileName(this,tr("Choix de la video"), qApp->applicationDirPath(), tr("*.mp4, *.avi, *.mov"));
    creerNote("video", path);

}

void MainWindow::creerAudio(){

    QString path=QFileDialog::getOpenFileName(this,tr("Choix de la source"), qApp->applicationDirPath());
    creerNote("audio", path);
}

void MainWindow::creerDocument(){
    creerNote("document");
}

void MainWindow::creerNote(const QString& type, const QString& path){
    bool ok;
    if(path!="" || type=="article" || type=="document"){
        QString titre = QInputDialog::getText(this, tr("Choix du titre"),tr("Saisissez le titre :"), QLineEdit::Normal,"", &ok);
        if (ok){
            NotesManager* n = NotesManager::getInstance();
            while(titre.endsWith("*")) titre.chop(1);
            if(liste.contains(titre)) titre+="1";
            n->creerNote(type, titre, path);
            liste.append(titre);
            model->setStringList(liste);
        }
    }

}

void MainWindow::afficherArticle(Article* article){
    bool sauver=article->isSaved();
    ArticleWidget* artWidget= new ArticleWidget(article);
    if (last_widget!=0) {
        ui->onglet_edit->layout()->removeWidget(last_widget) ;
        delete last_widget;
        last_widget=0;}
    last_widget=artWidget;
    ui->onglet_edit->layout()->addWidget(artWidget);
    QObject::connect(artWidget, SIGNAL(articleTexteChanged(const QString&)), this, SLOT(noteChanged(const QString&))) ;
    QObject::connect(artWidget, SIGNAL(articleTitreChanged(const QString&,const QString&, bool)), SLOT(noteTitreChanged(const QString&, const QString&, bool)));
    article->setSaved(sauver);


}

void MainWindow::afficherImage(Image* im){
    bool sauver=im->isSaved();
    ImageWidget* imWidget= new ImageWidget(im);
    if (last_widget!=0) {
        ui->onglet_edit->layout()->removeWidget(last_widget) ;
        delete last_widget;
        last_widget=0;}
    last_widget=imWidget;
    ui->onglet_edit->layout()->addWidget(imWidget);
    QObject::connect(imWidget, SIGNAL(imageDescChanged(const QString&)), this, SLOT(noteChanged(const QString&))) ;
    QObject::connect(imWidget, SIGNAL(imageTitreChanged(const QString&,const QString&, bool)), SLOT(noteTitreChanged(const QString&, const QString&, bool)));
    im->setSaved(sauver);

}

void MainWindow::afficherVideo(Video* v){
    bool sauver=v->isSaved();
    videowidget* vWidget= new videowidget(v);
    if (last_widget!=0) {
        ui->onglet_edit->layout()->removeWidget(last_widget) ;
        delete last_widget;
        last_widget=0;}
    last_widget=vWidget;
    ui->onglet_edit->layout()->addWidget(vWidget);
    QObject::connect(vWidget, SIGNAL(videoDescChanged(const QString&)), this, SLOT(noteChanged(const QString&))) ;
    QObject::connect(vWidget, SIGNAL(videoTitreChanged(const QString&,const QString&, bool)), SLOT(noteTitreChanged(const QString&, const QString&, bool)));
    v->setSaved(sauver);

}

void MainWindow::afficherAudio(Audio* a){
    bool sauver=a->isSaved();
    audiowidget* aWidget= new audiowidget(a);
    if (last_widget!=0) {
        ui->onglet_edit->layout()->removeWidget(last_widget) ;
        delete last_widget;
        last_widget=0;}
    last_widget=aWidget;
    ui->onglet_edit->layout()->addWidget(aWidget);
    QObject::connect(aWidget, SIGNAL(audioDescChanged(const QString&)), this, SLOT(noteChanged(const QString&))) ;
    QObject::connect(aWidget, SIGNAL(audioTitreChanged(const QString&,const QString&, bool)), SLOT(noteTitreChanged(const QString&, const QString&, bool)));
    a->setSaved(sauver);

}

void MainWindow::afficherDocument(Document* d){
    qDebug()<<"entrer afficherDocument : "<<d->getTitre();
    bool sauver=d->isSaved();
    DocumentWidget* docWidget= new DocumentWidget(d);
    if (last_widget!=0) {
        ui->onglet_edit->layout()->removeWidget(last_widget) ;
        delete last_widget;
        last_widget=0;}
    last_widget=docWidget;
    ui->onglet_edit->layout()->addWidget(docWidget);
    QObject::connect(docWidget, SIGNAL(documentTitreChanged(const QString&,const QString&, bool)), SLOT(noteTitreChanged(const QString&, const QString&, bool)));
    d->setSaved(sauver);
    qDebug()<<"sortie afficherDocument : "<<d->getTitre();
}

void MainWindow::replaceInListe(const QString& oldName,const QString& newName){
    QStringList::Iterator it=liste.begin();

    unsigned int index=0;
    while((*it)!= oldName && it!=liste.end()){
        index++;
        it++;
    }

    if ((*it)==oldName){
        liste[index]=newName;
    }
    model->setStringList(liste);
}

void MainWindow::noteChanged(const QString& titre){

    replaceInListe(titre, titre+"*");
    ui->sauver->setEnabled(true);

}

void MainWindow::noteTitreChanged(const QString &newTitre, const QString& oldTitre, bool saved){

        if (saved)replaceInListe(oldTitre, newTitre+"*");
        else replaceInListe(oldTitre+"*", newTitre+"*" );
        last_clicked.data().toString()=newTitre+"*";
        ui->sauver->setEnabled(true);


}

void MainWindow::itemClicked(const QModelIndex & index){
    ui->onglets->setCurrentIndex(0);
    last_clicked=index;
    NotesManager* gestnote=NotesManager::getInstance();
    QString titre=index.data().toString();
    while (titre.endsWith("*")) titre.chop(1);// si la note est modifié est non enregistré elle possède une étoile dans la liste
    Note* note=gestnote->getNoteFromTitre(titre);
    if (note->isSaved()) ui->sauver->setEnabled(false);
    else ui->sauver->setEnabled(true);

    switch(note->getType()){
    case Note::ARTICLE :
        ui->ajout->setHidden(true);
        ui->suppSous->setHidden(true);
        afficherArticle((Article*) note);
        break;
    case Note::IMAGE :
        ui->ajout->setHidden(true);
        ui->suppSous->setHidden(true);
        afficherImage((Image*) note);
        break;
    case Note::VIDEO :
        ui->ajout->setHidden(true);
        ui->suppSous->setHidden(true);
        afficherVideo((Video*) note);
        break;
    case Note::AUDIO :
        ui->ajout->setHidden(true);
        ui->suppSous->setHidden(true);
        afficherAudio((Audio*) note);
        break;
    case Note::DOCUMENT :
        afficherDocument((Document*) note);
        ui->ajout->setHidden(false);
        ui->suppSous->setHidden(false);
        break;
    default :
        QMessageBox::critical(this,"Erreur","ERREUR PB DANS ITEM CLICKED");
    }
}

void MainWindow::sauverClicked(){
    NotesManager* gestnote=NotesManager::getInstance();

    if (last_clicked.data().toString()!="") {
        QString titre=last_clicked.data().toString();
        // SOUCI si on met une * en fin de titre... on ne peut plus la retrouver...
        while (titre.endsWith("*")) titre.chop(1);// si la note est modifié et non enregistrée elle possède une étoile dans la liste
        Note* note=gestnote->getNoteFromTitre(titre);
        note->save(gestnote->getEspaceDeTravail());
        qDebug()<<"sauverClecked après save";
        replaceInListe(titre+"*", titre); // On enlève l'étoile pour indiquer que la note est sauvée
        qDebug()<<"1";
        ui->sauver->setEnabled(false);
        QMessageBox::information(this,"Sauvegarde","Sauvegarde effectuée");
    }
    else  QMessageBox::critical(this,"Erreur","Aucune note selectionée");

    qDebug()<<"sortie de sauverClecked";
 }

void MainWindow::supprClicked(){


    NotesManager* gestnote=NotesManager::getInstance();
    if (last_clicked.data().toString()!=""){
        QString titre=last_clicked.data().toString();
        QString titre2=titre;
        while (titre2.endsWith("*")) titre2.chop(1);// si la note est modifié et non enregistrée elle possède une étoile dans la liste
        Note* note=gestnote->getNoteFromTitre(titre2);
        gestnote->supprNote(note); //TO supprNote dans notesManager

        QStringList::Iterator it=liste.begin();

        unsigned int index=0;
        while((*it)!= titre && it!=liste.end()){
            index++;
            it++;
        }

        if ((*it)==titre){
            liste.removeAt(index);
        }
        model->setStringList(liste);
        ui->onglet_edit->layout()->removeWidget(last_widget);
        delete last_widget;
        last_widget=0;
    }
    else QMessageBox::critical(this,"Erreur","Aucune note selectionée");


}

void MainWindow::ongletChange(int index){
    switch (index) {
    case 0:
        itemClicked(last_clicked);
        break;
    case 1:
        ongletHtmlClicked();
        break;
    case 2:
        ongletTexClicked();
        break;
    case 3:
        ongletTexteClicked();
        break;
    default:
        QMessageBox::critical(this,"Erreur","Aucune onglet selectionée");
        break;
    }
}

void MainWindow::ongletTexteClicked(){

    NotesManager* gestnote=NotesManager::getInstance();
    if (last_clicked.data().toString()!=""){
        QString titre=last_clicked.data().toString();
        while (titre.endsWith("*")) titre.chop(1);
        Note* note=gestnote->getNoteFromTitre(titre);
        QString texte=gestnote->exportNote(note, "texte");
        ui->textEdit->setText(texte);}
    else QMessageBox::critical(this,"Erreur","Aucune note selectionée");
}

void MainWindow::ongletHtmlClicked(){
    NotesManager* gestnote=NotesManager::getInstance();

    if (last_clicked.data().toString()!=""){
        QString titre=last_clicked.data().toString();
        while (titre.endsWith("*")) titre.chop(1);
        Note* note=gestnote->getNoteFromTitre(titre);
        QString texte=gestnote->exportNote(note, "html");
        ui->textEdit_2->setText(texte);
    }
    else QMessageBox::critical(this,"Erreur","Aucune note selectionée");
}

void MainWindow::ongletTexClicked(){
    NotesManager* gestnote=NotesManager::getInstance();
    if (last_clicked.data().toString()!=""){
        QString titre=last_clicked.data().toString();
        while (titre.endsWith("*")) titre.chop(1);
        Note* note=gestnote->getNoteFromTitre(titre);
        QString texte=gestnote->exportNote(note, "latex");
        ui->textEdit_3->setText(texte);
    }
    else QMessageBox::critical(this,"Erreur","Aucune note selectionée");
}

void MainWindow::changerEspaceTravail(){
    QString espace  = QFileDialog::getExistingDirectory(this, tr("Open Directory"),qApp->applicationDirPath(),QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks); // Renvoie une erreur mais espace possède la bonne valeur
    NotesManager* gestnote=NotesManager::getInstance();
     gestnote->setEspaceDeTravail(espace);

     liste.clear();
     gestnote->chargerNotes();
     const QSet<Note*>& listeNotes = gestnote->getEnsnote();
     if (!listeNotes.isEmpty()){
     QSet<Note*>::const_iterator it=listeNotes.begin();
     while(it!=listeNotes.end()){
         liste.append((*it)->getTitre());
         it++;
     }}
     model->setStringList(liste);
     ui->listView->setModel(model);
     ui->onglet_edit->layout()->removeWidget(last_widget);
     delete last_widget;
     last_widget=0;
}

void MainWindow::ajoutSousNotes(){

    listeTemp=liste;
    listeTemp.removeOne(last_clicked.data().toString());
    modelAjout->setStringList(listeTemp);   
    listeAjout->show();

}

void MainWindow::sousNotesSelected(const QModelIndex& index){

    NotesManager* gestnote=NotesManager::getInstance();
    QString titreDoc=last_clicked.data().toString();
    while (titreDoc.endsWith("*")) titreDoc.chop(1);
    Note* noteD=gestnote->getNoteFromTitre(titreDoc);

    QString titreNote=index.data().toString();
    while (titreNote.endsWith("*")) titreNote.chop(1);
    Note* note=gestnote->getNoteFromTitre(titreNote);
    qDebug()<<"sous notes a ajoutée"<<note->getTitre();

    Document* doc=(Document*) noteD;
    doc->addSubNote(note);
    listeAjout->close();
    listeTemp.clear();
    qDebug()<<"on appelle afficherDoc pour mettre à jour l'affichage";
    afficherDocument(doc);
    noteChanged(doc->getTitre());
}

void MainWindow::suppSousNotes()
{

    listeDesSousNotes.clear();
    NotesManager* gestnote=NotesManager::getInstance();
    QString titreDoc=last_clicked.data().toString();
    while (titreDoc.endsWith("*")) titreDoc.chop(1);
    Note* noteD=gestnote->getNoteFromTitre(titreDoc);
    Document* d=(Document*) noteD;
    qDebug()<<d->getTitre();


    for(QSet<Note*>::const_iterator it=d->getSousNotes().cbegin(); it!=d->getSousNotes().cend(); it++)
    {
        listeDesSousNotes.append((*it)->getTitre());
    }

    modelSupp->setStringList(listeDesSousNotes);
    listeSupp->show();
}

void MainWindow::sousNotesASuppSelected(const QModelIndex& index)
{
    qDebug()<<"entrée dans le sousNotesASuppSelected";
    NotesManager* gestnote=NotesManager::getInstance();
    QString titreDoc=last_clicked.data().toString();
    while (titreDoc.endsWith("*")) titreDoc.chop(1);
    Note* noteD=gestnote->getNoteFromTitre(titreDoc);

    QString titreNote=index.data().toString();
    qDebug()<<titreNote;
    while (titreNote.endsWith("*")) titreNote.chop(1);
    Note* note=gestnote->getNoteFromTitre(titreNote);
    qDebug()<<note->getTitre();
    qDebug()<<listeDesSousNotes.last();

    Document* doc=(Document*) noteD;
    doc->removeSubNote(note);
    listeSupp->close();
    afficherDocument(doc);

}

void MainWindow::saveExportHtml(){

    QString path=QFileDialog::getExistingDirectory(this, tr("Enregistrer vers "),qApp->applicationDirPath(),QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    QFile fichier (path+"/"+last_clicked.data().toString()+".html");
    QString titre=last_clicked.data().toString();
    if (titre.endsWith("*")) titre.chop(1);
    NotesManager* gestnote=NotesManager::getInstance();
    Note* note=gestnote->getNoteFromTitre(titre);
    QString texte=gestnote->exportNote(note,"html");
    if(fichier.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream flux(&fichier);
        flux<<texte;
        fichier.close();
        QMessageBox::information(this,"Export","La note a été exportée en .html !");
    }
    else QMessageBox::critical(this,"Erreur","Le chemin choisis est inaccessible ");
}

void MainWindow::saveExportLatex(){

    QString path=QFileDialog::getExistingDirectory(this, tr("Enregistrer vers "),qApp->applicationDirPath(),QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    QFile fichier (path+"/"+last_clicked.data().toString()+".tex");
    if(fichier.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream flux(&fichier);
        flux<<ui->textEdit_3->toPlainText();
        fichier.close();
        QMessageBox::information(this,"Export","La note a été exportée en .TeX !");
    }
    else QMessageBox::critical(this,"Erreur","Le chemin choisis est inaccessible ");

}

void MainWindow::saveExportText(){

    QString path=QFileDialog::getExistingDirectory(this, tr("Enregistrer vers "),qApp->applicationDirPath(),QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks);
    QFile fichier (path+"/"+last_clicked.data().toString()+".txt");
    if(fichier.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream flux(&fichier);
        flux<<ui->textEdit->toPlainText();
        fichier.close();
        QMessageBox::information(this,"Export","La note a été exportée en .txt !");
    }
    else QMessageBox::critical(this,"Erreur","Le chemin choisis est inaccessible ");
}
