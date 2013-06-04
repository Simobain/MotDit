
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "articlewidget.h"
#include <QObject>
#include <iostream>
#include <QFileDialog>
#include <QFile>
#include "notesmanager.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QStringListModel>
#include <QStringList>
#include <QSettings>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), last_widget(0)
{
    ui->setupUi(this);

    QObject :: connect(ui->actionArticle, SIGNAL(triggered()), this, SLOT(creerArticle()));
    //QObject :: connect(ui->actionDocument, SIGNAL(triggered()), this, SLOT(creerDocument()));

    ui->onglets->setTabText(0, "Edit");
    ui->onglets->setTabText(1, "HTML");
    ui->onglets->setTabText(2, "TeX");
    ui->onglets->setTabText(3, "Text");

    ui->listView->setMovement(QListView::Static);
    ui->listView->setFlow(QListView::TopToBottom);
    ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setSelectionMode(QListView::ExtendedSelection);

    ui->sauver->setEnabled(false);

    QObject :: connect(ui->listView,SIGNAL(clicked(const QModelIndex&)),this,SLOT(itemClicked(const QModelIndex&)));
    QObject :: connect(ui->sauver,SIGNAL(clicked()),this,SLOT(sauverClicked()));

    NotesManager* nm=NotesManager::getInstance();
    const QSet<Note*>& listeNotes = nm->getEnsnote();
    QSet<Note*>::const_iterator it=listeNotes.begin();
    while(it!=listeNotes.end()){

        liste.append((*it)->getTitre());
        it++;
    }
    ui->listView->setModel(new QStringListModel(liste));
}


MainWindow::~MainWindow()
{
    delete ui;
}



  void MainWindow::creerArticle(){
    creerNote("article");
}

void MainWindow::creerNote(const QString& type){
    bool ok;
    QString titre = QInputDialog::getText(this, tr("Choix du titre"),tr("Saisissez le titre :"), QLineEdit::Normal,"", &ok);
    if (ok){
        NotesManager* n = NotesManager::getInstance();
        n->creerNote(type, titre);
        liste.append(titre);
        ui->listView->setModel(new QStringListModel(liste));
    }

}

void MainWindow::afficherArticle(Article* article){

    ArticleWidget* artWidget= new ArticleWidget(article);

    if (last_widget!=0) ui->onglet_edit->layout()->removeWidget(last_widget);

    artWidget->setTitre(article->getTitre());
    artWidget->setTexte(article->getTexte());
    last_widget=artWidget;
    ui->onglet_edit->layout()->addWidget(artWidget);
    QObject::connect(artWidget, SIGNAL(articleTexteChanged(const QString&)), this, SLOT(noteChanged(const QString&))) ;
    QObject::connect(artWidget, SIGNAL(articleTitreChanged(const QString&,const QString&, bool)), SLOT(noteTitreChanged(const QString&, const QString&, bool)));
    article->setSaved(true);


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
    ui->listView->setModel(new QStringListModel(liste));
}


void MainWindow::noteChanged(const QString& titre){

    replaceInListe(titre, titre+"*");
    ui->sauver->setEnabled(true);

}

void MainWindow::noteTitreChanged(const QString &newTitre, const QString& oldTitre, bool saved){

    if (saved)replaceInListe(oldTitre, newTitre+"*");
    else replaceInListe(oldTitre+"*", newTitre+"*" );
    ui->sauver->setEnabled(true);

}

void MainWindow::itemClicked(const QModelIndex & index){
    //QMessageBox::information(this,"Hello!","You Clicked: \n"+index.data().toString());
    last_clicked=index;
    NotesManager* gestnote=NotesManager::getInstance();
    QString titre=index.data().toString();
    if (titre.endsWith("*")) titre.remove("*");// si la note est modifié est non enregistré elle possède une étoile dans la liste
    Note* note=gestnote->getNoteFromTitre(titre);


    switch(note->getType()){
    case Note::ARTICLE :

        afficherArticle((Article*) note);

        break;
    default :
        QMessageBox::information(this,"Erreur","pb :)");
    }

}

 void MainWindow::sauverClicked()
 {
    NotesManager* gestnote=NotesManager::getInstance();
    QString titre=last_clicked.data().toString();//Pas bon si on change le titre
    qDebug()<<titre;// SOUCI si on met une * en fin de titre... on ne peut plus la retrouver...
    if (titre.endsWith("*")) titre.remove("*");// si la note est modifié est non enregistrée elle possède une étoile dans la liste
    Note* note=gestnote->getNoteFromTitre(titre);// SOUCI lorque l'on sauve un nouveau titre, on appelle avec l'ancien et du coup on le trouve pas
    qDebug()<<note->getTitre();
    switch(note->getType()){
        case Note::ARTICLE :
            Article* notA=(Article*) note;
            notA->save(gestnote->getEspaceDeTravail());

            break;
    /*
        default :
            QMessageBox::information(this,"Erreur","pb :)");TODO: Rechercher le pb*/
        }

    QStringList::Iterator it=liste.begin();
    unsigned int i=0;
    while((*it)!= titre+"*" && it!=liste.end()){
        i++;
        it++;
    }

    if ((*it)==titre+"*"){
        liste[i]=titre;
        ui->listView->setModel(new QStringListModel(liste));
    }
    ui->sauver->setEnabled(false);//Si on rechange ne se remet pas enable :s

 }

