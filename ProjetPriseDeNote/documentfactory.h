#ifndef DOCUMENTFACTORY_H
#define DOCUMENTFACTORY_H
#include "notefactory.h"

class DocumentFactory : public NoteFactory
{
public:
    DocumentFactory();
    QString getNewId();
    Note* buildNote(QString& id,QString& title);
    Note* buildNewNote(QString& title);
    Note* buildNotecopy(const Note* n);
};

#endif // DOCUMENTFACTORY_H
