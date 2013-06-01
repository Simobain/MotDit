#include "mainwindow.h"
#include <QApplication>
#include "note.h"
#include "article.h"
#include <iostream>
#include <time.h>
#include<sstream>
//#include <unistd.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QString cheminAcces=argv[0];//Recherche du chemin d'accès (je l'ai adapté seulement pour mon ordi)
    //j'en cherche un commun Docu Qt a fond les ballons :)
    cheminAcces.chop(113);
    //Test fonction load et save
    Article* art=new Article();
    art->setTitre("article1");
    art->setTexte("Ceci est mon premier article");
    art->save(cheminAcces+"article001.txt");
    //art->load("article001.txt");
    //std::cout<<art->getTitre().toStdString()<<"\n"<<art->getTexte().toStdString()<<"\n";





    w.show();

    
    return a.exec();

}
