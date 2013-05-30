#include "mainwindow.h"
#include <QApplication>
#include "note.h"
#include "article.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    /* Test fonction load et save
    Article* art=new Article();
    art->setTitre("article1");
    art->setTexte("Ceci est mon premier article");
    art->save("article001.txt");
    art->load("article001.txt");
    std::cout<<art->getTitre().toStdString()<<"\n"<<art->getTexte().toStdString()<<"\n";*/

    w.show();
    
    return a.exec();
}
