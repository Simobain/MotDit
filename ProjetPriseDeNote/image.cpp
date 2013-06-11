#include "image.h"

Image::Image() : Binary()
{
}

Image::Image(const QString& id, const QString& titre, const QString& path) : Binary(id,titre,path)
{
}

Note::NoteType Image::getType()const{
    return IMAGE;
}

