#include "mainwindow.h"
#include <QApplication>
#include "note.h"
#include "article.h"
#include <iostream>
#include <time.h>
#include <sstream>
#include "notesmanager.h"
#include <QSettings>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    //NotesManager* n=NotesManager::getInstance();
    //QString cheminAcces=n->getEspaceDeTravail();
    /*QWidget* fen=new QWidget();
    fen->resize(200,200);
    QLabel *label = new QLabel(fen);
    label->setPixmap(QPixmap(QApplication::applicationDirPath() +"chat.png"));
    fen->show();*/



    w.show();

    
    return a.exec();

}
