
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>
#include <iostream>
#include <QFileDialog>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject :: connect(ui->actionArticle_2,SIGNAL(triggered()), this, SLOT(ouvrirArticle()));



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::ouvrirArticle(){


}


