#include "document.h"

Document::Document(const QString& id,const QString& titre) : Note(id,titre)
{

}


Note::NoteType Document::getType()const {
    return DOCUMENT;
}

void Document::addSubNote(Note *n){
    sousNotes<<n;
}

void Document::removeSubNote(Note *n){
    sousNotes.remove(n);
}

QSet<Note*> Document::getSousNotes() const{
    return sousNotes;
}

void Document::save(const QString &directory){
    setSaved(true);
    QString cheminEntier=directory+"/"+getId()+".txt";
    QFile fichier (cheminEntier);
    if(fichier.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {

        QTextStream flux(&fichier);
        flux<<getTitre()<<"\n";
        QSet<Note*>::const_iterator it = sousNotes.begin();
        while (it!=sousNotes.end()){
            flux<<(*it)->getId()<<"\n";
        }
        fichier.close();
    }
    else qDebug()<<"Impossible d'ecrire' !"<<"\n";
    if(!isInTheFile())saveInTheFile(getId(), directory);
}

