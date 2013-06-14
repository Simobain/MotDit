#ifndef AUDIOFACTORY_H
#define AUDIOFACTORY_H
#include "notefactory.h"
#include "audio.h"

class NotesManager;

class AudioFactory : public NoteFactory
{
public:
    AudioFactory();
    QString getNewId();
    Note* buildNote(const QString& id,const QString& title, const QString& path="", const QString& desc="");
    Note* buildNewNote(const QString& title, const QString &path);
    Note* buildNotecopy(const Note* n);
    Note* chargerNote(const QString& id, const QString& chemin);

};

#endif // AUDIOFACTORY_H
