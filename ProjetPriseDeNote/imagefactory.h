#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H
#include "notefactory.h"

class ImageFactory : public NoteFactory
{
public:
    ImageFactory();
    QString getNewId();
    Note* buildNote(QString& id,QString& title);
    Note* buildNewNote(QString& title);
    Note* buildNotecopy(const Note* n);
};

#endif // IMAGEFACTORY_H
