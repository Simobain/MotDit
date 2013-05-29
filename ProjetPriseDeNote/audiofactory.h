#ifndef AUDIOFACTORY_H
#define AUDIOFACTORY_H
#include "notefactory.h"

class AudioFactory : public NoteFactory
{
public:
    AudioFactory();
    QString getNewId();
    Note* buildNote(QString& id,QString& title);
    Note* buildNewNote(QString& title);
    Note* buildNotecopy(const Note* n);
};

#endif // AUDIOFACTORY_H
