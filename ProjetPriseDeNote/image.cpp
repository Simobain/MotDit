#include "image.h"

Image::Image() : Binary()
{
}

Image::Image(const QString& id, const QString& titre) : Binary(id,titre)
{
}

Note::NoteType Image::getType()const{
    return IMAGE;
}

