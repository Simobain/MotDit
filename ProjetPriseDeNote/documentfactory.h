#ifndef DOCUMENTFACTORY_H
#define DOCUMENTFACTORY_H
#include "notefactory.h"
#include "document.h"
#include "notesmanager.h"
//class NotesManager;

class DocumentFactory : public NoteFactory
{
public:
    DocumentFactory();
    QString getNewId();
    Note* buildNote(const QString& id,const QString& titre, const QString& contenu="", const QString& desc="");
    Note* buildNewNote(const QString& titre, const QString& path="");
    Note* buildNotecopy(const Note* n);
    Note* chargerNote(const QString& id, const QString& chemin);
};

#endif // DOCUMENTFACTORY_H
