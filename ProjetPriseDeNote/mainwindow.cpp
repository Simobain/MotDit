
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





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), last_widget(0)
{
    ui->setupUi(this);

    QObject :: connect(ui->actionArticle, SIGNAL(triggered()), this, SLOT(creerArticle()));
    QObject :: connect(ui->actionImage, SIGNAL(triggered()), this, SLOT(creerImage()));
    //QObject :: connect(ui->actionDocument, SIGNAL(triggered()), this, SLOT(creerDocument()));
    QObject :: connect(ui->actionFermer, SIGNAL(triggered()), this, SLOT(close()));
    QObject :: connect(ui->actionSauvegarder,SIGNAL(triggered()),this,SLOT(sauverClicked()));
    //To Do trouver solution pour que quand on clique sur bouton et pas de changement.
    //NB : je pense qu'il vaut mieux que le bouton soit toujours activé et qu'on lance un QmessageBox si il n'y a rien"Rien à sauver"

    QObject :: connect(ui->listView,SIGNAL(clicked(const QModelIndex&)),this,SLOT(itemClicked(const QModelIndex&)));
    QObject :: connect(ui->sauver,SIGNAL(clicked()),this,SLOT(sauverClicked()));
    QObject :: connect(ui->suppr, SIGNAL(clicked()), this, SLOT(supprClicked()));
    QObject :: connect(ui->onglets, SIGNAL(currentChanged(int)), this, SLOT(ongletChange(int)));
    QObject :: connect(ui->actionDefinir_un_nouvel_espace_de_travail, SIGNAL(triggered()), this, SLOT(changerEspaceTravail()));


    ui->onglets->setTabText(0, "Edit");
    ui->onglets->setTabText(1, "HTML");
    ui->onglets->setTabText(2, "TeX");
    ui->onglets->setTabText(3, "Text");

    ui->listView->setMovement(QListView::Static);
    ui->listView->setFlow(QListView::TopToBottom);
    ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setSelectionMode(QListView::ExtendedSelection);
    model=new QStringListModel();

    ui->sauver->setEnabled(false);

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
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::creerArticle(){
    creerNote("article");
}

void MainWindow::creerImage(){

    QString path=QFileDialog::getOpenFileName(this,tr("choix de la source"), qApp->applicationDirPath(), tr("Images (*.jpg, *.png)"));
    qDebug()<<"le chemin de départ"<<path;
    creerNote("image", path);

}

void MainWindow::creerNote(const QString& type, const QString& path){
    bool ok;
    QString titre = QInputDialog::getText(this, tr("Choix du titre"),tr("Saisissez le titre :"), QLineEdit::Normal,"", &ok);
    if (ok){
        NotesManager* n = NotesManager::getInstance();
        n->creerNote(type, titre, path);
        liste.append(titre);
        model->setStringList(liste);
    }

}

void MainWindow::afficherArticle(Article* article){
    bool sauver=article->isSaved();
    ArticleWidget* artWidget= new ArticleWidget(article);
    if (last_widget!=0) {
        ui->onglet_edit->layout()->removeWidget(last_widget) ;
        delete last_widget;
        last_widget=0;}
    artWidget->setTitre(article->getTitre());
    artWidget->setTexte(article->getTexte());
    last_widget=artWidget;
    ui->onglet_edit->layout()->addWidget(artWidget);
    QObject::connect(artWidget, SIGNAL(articleTexteChanged(const QString&)), this, SLOT(noteChanged(const QString&))) ;
    QObject::connect(artWidget, SIGNAL(articleTitreChanged(const QString&,const QString&, bool)), SLOT(noteTitreChanged(const QString&, const QString&, bool)));
    article->setSaved(sauver);


}

void MainWindow::afficherImage(Image* im){
    bool sauver=im->isSaved();
    qDebug()<<"1";
    ImageWidget* imWidget= new ImageWidget(im);
    qDebug()<<"2";
    if (last_widget!=0) {
        ui->onglet_edit->layout()->removeWidget(last_widget) ;
        delete last_widget;
        last_widget=0;}
    imWidget->setTitre(im->getTitre());
    imWidget->setDesc(im->getDescription());
    imWidget->setChemin(im->getChemin());
    last_widget=imWidget;
    ui->onglet_edit->layout()->addWidget(imWidget);
    QObject::connect(imWidget, SIGNAL(imageDescChanged(const QString&)), this, SLOT(noteChanged(const QString&))) ;
    QObject::connect(imWidget, SIGNAL(imageTitreChanged(const QString&,const QString&, bool)), SLOT(noteTitreChanged(const QString&, const QString&, bool)));
    im->setSaved(sauver);

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

    last_clicked=index;
    NotesManager* gestnote=NotesManager::getInstance();
    QString titre=index.data().toString();
    if (titre.endsWith("*")) titre.remove("*");// si la note est modifié est non enregistré elle possède une étoile dans la liste
    Note* note=gestnote->getNoteFromTitre(titre);
    if (note->isSaved()) ui->sauver->setEnabled(false);
    else ui->sauver->setEnabled(true);

    switch(note->getType()){
    case Note::ARTICLE :
        afficherArticle((Article*) note);
        break;
    case Note::IMAGE :
        afficherImage((Image*) note);
        break;
    default :
        QMessageBox::critical(this,"Erreur","ERREUR !!");
    }

}

void MainWindow::sauverClicked(){
    NotesManager* gestnote=NotesManager::getInstance();

    if (last_clicked.data().toString()!="") {
        QString titre=last_clicked.data().toString();
        // SOUCI si on met une * en fin de titre... on ne peut plus la retrouver...
        if (titre.endsWith("*")) titre.remove("*");// si la note est modifié et non enregistrée elle possède une étoile dans la liste
        Note* note=gestnote->getNoteFromTitre(titre);
        note->save(gestnote->getEspaceDeTravail());
        replaceInListe(titre+"*", titre); // On enlève l'étoile pour indiquer que la note est sauvée
        ui->sauver->setEnabled(false);
        QMessageBox::information(this,"Sauvegarde","Sauvegarde effectuée");

    }
    else  QMessageBox::critical(this,"Erreur","Aucune note selectionée");

 }

void MainWindow::supprClicked(){


    NotesManager* gestnote=NotesManager::getInstance();
    if (last_clicked.data().toString()!=""){
        QString titre=last_clicked.data().toString();
        QString titre2=titre;
        if (titre2.endsWith("*")) titre2.remove("*");// si la note est modifié et non enregistrée elle possède une étoile dans la liste
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
        qDebug()<<"pb !!!";
        break;
    }
}

void MainWindow::ongletTexteClicked(){

    NotesManager* gestnote=NotesManager::getInstance();
    if (last_clicked.data().toString()!=""){
    QString titre=last_clicked.data().toString();
    if (titre.endsWith("*")) titre.remove("*");
    Note* note=gestnote->getNoteFromTitre(titre);
    QString texte=gestnote->exportNote(note, "texte");
    ui->textEdit->setText(texte);}
    else QMessageBox::critical(this,"Erreur","Aucune note selectionée");
}

void MainWindow::ongletHtmlClicked(){

    NotesManager* gestnote=NotesManager::getInstance();
    if (last_clicked.data().toString()!=""){
    QString titre=last_clicked.data().toString();
    if (titre.endsWith("*")) titre.remove("*");
    Note* note=gestnote->getNoteFromTitre(titre);
    QString texte=gestnote->exportNote(note, "html");
    ui->textEdit_2->setText(texte);
    qDebug()<<ui->textEdit_2->toPlainText(); // il faut empecher le text edit d'intrepreter l'html
    }
    else QMessageBox::critical(this,"Erreur","Aucune note selectionée");
}

void MainWindow::ongletTexClicked(){
    NotesManager* gestnote=NotesManager::getInstance();
    if (last_clicked.data().toString()!=""){
    QString titre=last_clicked.data().toString();
    if (titre.endsWith("*")) titre.remove("*");
    Note* note=gestnote->getNoteFromTitre(titre);
    QString texte=gestnote->exportNote(note, "latex");
    ui->textEdit_3->setText(texte);
    }
    else QMessageBox::critical(this,"Erreur","Aucune note selectionée");
}

void MainWindow::changerEspaceTravail(){
    QString espace  = QFileDialog::getExistingDirectory(this, tr("Open Directory"),qApp->applicationDirPath(),QFileDialog::ShowDirsOnly| QFileDialog::DontResolveSymlinks); // Renvoie une erreur mais espace possède la bonne valeur
    //qDebug()<<espace;
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
