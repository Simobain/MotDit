#include "audio.h"


Audio::Audio() : Binary()
{
}
Audio::Audio(const QString& id, const QString& titre, const QString &path, const QString &desc) : Binary(id,titre,path,desc)
{
}
Note::NoteType Audio::getType() const{
    return AUDIO;
}
