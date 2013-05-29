#ifndef NOTEFACTORY_H
#define NOTEFACTORY_H
#include "note.h"
#include<QString>
#include <QMap>
#include<sstream>

class NoteFactory
{
public:
    NoteFactory();
    virtual Note* buildNote(QString& id,QString& title);
    virtual Note* buildNewNote(QString& title);
    virtual Note* buildNotecopy();
    //static QMap<Qstring, NoteFactory*> getFactories();

protected :
    virtual QString getNewId();//Renvoie un ID unique

};

#endif // NOTEFACTORY_H
