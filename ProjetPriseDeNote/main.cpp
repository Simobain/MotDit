#include "mainwindow.h"
#include <QApplication>
#include "note.h"
#include "article.h"
#include <iostream>
#include <time.h>
#include<sstream>
#include "notesmanager.h"
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    NotesManager* n=NotesManager::getInstance();
    QString cheminAcces=n->getEspaceDeTravail();
    //Test fonction load et save
    Article* art=new Article();
    art->setTitre("article1");
    art->setTexte("Ceci est mon premier article");
    art->save(n->getEspaceDeTravail());
    //art->load("article001.txt");
    //std::cout<<art->getTitre().toStdString()<<"\n"<<art->getTexte().toStdString()<<"\n";
    //QSettings descrip("BinomeLO21","ProjetPriseDeNote");

    //std::cout<<cheminAcces.toStdString()<<descrip.value("ok","non").toString().toStdString();




    w.show();

    
    return a.exec();

}
