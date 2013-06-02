#ifndef NOTEFACTORY_H
#define NOTEFACTORY_H

#include<QString>
#include <QMap>
#include<sstream>
#include<QSettings>
#include "note.h"




class NoteFactory
{
public:
    NoteFactory();
    virtual Note* buildNote(const QString& id,const QString& title, const QString& contenu)=0;
    virtual Note* buildNewNote(const QString& title)=0;
    virtual Note* chargerNote(const QString& id, const QString& chemin)=0;
    //virtual Note* buildNotecopy()=0;
    //static QMap<Qstring, NoteFactory*> getFactories();

protected :
    virtual QString getNewId();//Renvoie un ID unique

};

#endif // NOTEFACTORY_H
