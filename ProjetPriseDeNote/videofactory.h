#ifndef VIDEOFACTORY_H
#define VIDEOFACTORY_H
#include "notefactory.h"
#include "video.h"

class NotesManager;

class VideoFactory : public NoteFactory
{
public:
    VideoFactory();
    QString getNewId();
    Note* buildNote(const QString& id,const QString& title, const QString& path="",const QString& desc="");
    Note* buildNewNote(const QString& title, const QString &path);
    Note* buildNotecopy(const Note* n);
    Note* chargerNote(const QString& id, const QString& chemin);
};

#endif // VIDEOFACTORY_H
