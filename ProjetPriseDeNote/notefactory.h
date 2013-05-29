#ifndef NOTEFACTORY_H
#define NOTEFACTORY_H
#include "note.h"
#include<QString>
#include <QMap>

class NoteFactory
{
public:
    NoteFactory();
    virtual Note* buildNote(QString& id,QString& title);
    virtual Note* buildNewNote(QString& title);
    virtual Note* buildNotecopy();
    //static map<Qstring, NoteFactory*> getFactories();

protected :
    virtual QString getNewId();

};

#endif // NOTEFACTORY_H
