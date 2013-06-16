#include "mainwindow.h"
#include <QApplication>
#include "note.h"
#include "article.h"
#include <iostream>
#include <time.h>
#include <sstream>
#include "notesmanager.h"
#include <QSettings>
#include "document.h"
#include "article.h"

/**
*@mainpage Rapport du Projet LO21 réalisé avec joie par Pauline Cuche et Simon Robain
*
*1 comment avons fait cela ?
*2 pourquoi ?
*
*/
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MainWindow w;

    w.show();
    return a.exec();
}
