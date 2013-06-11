#include "image.h"

Image::Image() : Binary()
{
}

Image::Image(const QString& id, const QString& titre, const QString& path, const QString &desc) : Binary(id,titre,path,desc)
{
}

Note::NoteType Image::getType()const{
    return IMAGE;
}
