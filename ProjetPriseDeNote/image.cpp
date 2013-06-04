#include "image.h"

Image::Image() : Binary()
{
}

Note::NoteType Image::getType()const{
    return IMAGE;
}
