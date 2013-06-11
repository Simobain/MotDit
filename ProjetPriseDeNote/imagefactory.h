#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H
#include "notefactory.h"
#include "image.h"

class NotesManager;

class ImageFactory : public NoteFactory
{
public:
    ImageFactory();
    QString getNewId();
    Note* buildNote(const QString& id,const QString& title, const QString& path="");
    Note* buildNewNote(const QString& title);
    Note* buildNotecopy(const Note* n);
    Note* chargerNote(const QString& id, const QString& chemin);
};

#endif // IMAGEFACTORY_H
