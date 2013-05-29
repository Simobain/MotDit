#ifndef VIDEOFACTORY_H
#define VIDEOFACTORY_H
#include "notefactory.h"

class VideoFactory : public NoteFactory
{
public:
    VideoFactory();
    QString getNewId();
    Note* buildNote(QString& id,QString& title);
    Note* buildNewNote(QString& title);
    Note* buildNotecopy(const Note* n);
};

#endif // VIDEOFACTORY_H
