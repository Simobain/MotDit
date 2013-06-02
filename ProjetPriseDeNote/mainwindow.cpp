
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
    //QObject :: connect(ui->actionArticle_2,SIGNAL(triggered()), this, SLOT(ouvrirArticle()));
    QObject :: connect(ui->actionArticle, SIGNAL(triggered()), this, SLOT(creerArticle()));
    //QObject :: connect(ui->actionDocument, SIGNAL(triggered()), this, SLOT(creerDocument()));

    ui->onglets->setTabText(0, "Edit");
    ui->onglets->setTabText(1, "HTML");
    ui->onglets->setTabText(2, "TeX");
    ui->onglets->setTabText(3, "Text");

    ui->listView->setMovement(QListView::Static);
    ui->listView->setFlow(QListView::TopToBottom);
    ui->listView->setViewMode(QListView::ListMode);


    //QObject :: connect(ui->actionAdd,SIGNAL(triggered()), this, SLOT(ajoutListe()));
    QObject :: connect(ui->listView,SIGNAL(clicked(const QModelIndex&)),this,SLOT(itemClicked(const QModelIndex&)));
    QObject :: connect(ui->sauver,SIGNAL(clicked()),this,SLOT(sauverClicked()));



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
    QObject::connect(artWidget, SIGNAL(articleChanged(const QString&)), this, SLOT(noteChanged(const QString&))) ;
    article->setSaved(true);


}


void MainWindow::noteChanged(const QString& titre){
    QStringList::Iterator it=liste.begin();
    unsigned int index=0;
    while((*it)!= titre && it!=liste.end()){
        index++;
        it++;
    }
    if ((*it)==titre){
        //liste.replace(index, titre+"*");
        std::cout<<"changed\n";
        liste[index]=titre+"*";
    }

    ui->listView->setModel(new QStringListModel(liste));

}

void MainWindow::itemClicked(const QModelIndex & index){
    //QMessageBox::information(this,"Hello!","You Clicked: \n"+index.data().toString());
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
    QModelIndex index= ui->listView->currentIndex();
    NotesManager* gestnote=NotesManager::getInstance();
    QString titre=index.data().toString();
    if (titre.endsWith("*")) titre.remove("*");// si la note est modifié est non enregistré elle possède une étoile dans la liste
    Note* note=gestnote->getNoteFromTitre(titre);
    switch(note->getType()){

    case Note::ARTICLE :
        Article* notA=(Article*) note;
        notA->save(gestnote->getEspaceDeTravail());
        break;

    /*default :
        QMessageBox::information(this,"Erreur","pb :)");*/
    }

 }

