#include "video.h"


Video::Video() : Binary()
{
}
Video::Video(const QString& id, const QString& titre, const QString &path, const QString &desc) : Binary(id,titre,path,desc)
{
}

Note::NoteType Video::getType()const {
    return VIDEO;
}
