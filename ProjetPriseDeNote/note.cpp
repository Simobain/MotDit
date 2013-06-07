#include "note.h"
#include <fstream>



Note::Note():id(001), titre(""), modified(false), loaded(false), saved(true), inTheFile(false){}//constructeur par defaut de Note

Note::Note(const QString& i, const QString& t): id(i), titre(t),modified(false),loaded(false), saved(true), inTheFile(false){}

void Note::setTitre(const QString& t){
    titre=t;
    //saved=false;
}

void Note::saveInTheFile(const QString& id, const QString& chemin){
    QFile fileDesc(chemin+"/"+"fileDescript.txt");
    if(fileDesc.open(QIODevice::WriteOnly |QIODevice::Append| QIODevice::Text))
    {
        QTextStream flux(&fileDesc);
        flux<<id<<"\n";
        inTheFile=true;
        fileDesc.close();
    }
    else qDebug()<<"pb d'enregistrement";//std::cout<<"Impossible d'ecrire' !"<<"\n";
}
