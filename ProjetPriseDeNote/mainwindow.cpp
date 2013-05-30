
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <iostream>
#include <QFileDialog>
#include <QFile>
#include "notesmanager.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject :: connect(ui->actionArticle_2,SIGNAL(triggered()), this, SLOT(ouvrirArticle()));
    QObject :: connect(ui->actionArticle, SIGNAL(triggered()), this, SLOT(creerArticle()));
    //QObject :: connect(ui->actionDocument, SIGNAL(triggered()), this, SLOT(creerDocument()));




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
    }

}


