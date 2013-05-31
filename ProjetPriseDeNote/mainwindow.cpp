
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <iostream>
#include <QFileDialog>
#include <QFile>
#include "notesmanager.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QStringListModel>
#include <QStringList>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QObject :: connect(ui->actionArticle_2,SIGNAL(triggered()), this, SLOT(ouvrirArticle()));
    QObject :: connect(ui->actionArticle, SIGNAL(triggered()), this, SLOT(creerArticle()));
    //QObject :: connect(ui->actionDocument, SIGNAL(triggered()), this, SLOT(creerDocument()));

    ui->listView->setMovement(QListView::Static);
    ui->listView->setFlow(QListView::TopToBottom);
    ui->listView->setViewMode(QListView::ListMode);


    QObject :: connect(ui->actionAdd,SIGNAL(triggered()), this, SLOT(ajoutListe()));




    }

    MainWindow::~MainWindow()
    {
        delete ui;
    }



    void MainWindow::ouvrirArticle(){

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

    void MainWindow::ajoutListe()
    {


    }

