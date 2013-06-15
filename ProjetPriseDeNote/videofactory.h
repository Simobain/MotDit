#ifndef VIDEOFACTORY_H
#define VIDEOFACTORY_H
#include "notefactory.h"
#include "video.h"

class NotesManager;

/*!
 * \file videofactory.h
 * \brief Classe VideoFactory permettant de construire une note de type vidéo
 * \author Pauline Cuche/Simon Robain
 */
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
