#include "note.h"
#include <fstream>



Note::Note():id(001), titre(""), modified(false), saved(true), inTheFile(false){}//constructeur par defaut de Note

Note::Note(const QString& i, const QString& t): id(i), titre(t),modified(false), saved(true), inTheFile(false){}

void Note::setTitre(const QString& t){
    titre=t;
    //saved=false;
}

void Note::saveInTheFile(const QString& id, const QString& chemin){
    qDebug()<<"entrer save in the file";
    QFile fileDesc(chemin+"/"+"fileDescript.txt");
    if(fileDesc.open(QIODevice::WriteOnly |QIODevice::Append| QIODevice::Text))
    {
        QTextStream flux(&fileDesc);
        flux<<id<<"\n";
        inTheFile=true;
        fileDesc.close();
    }
    else qDebug()<<"pb d'enregistrement";//std::cout<<"Impossible d'ecrire' !"<<"\n";
    qDebug()<<"sortie save in the file";
}
