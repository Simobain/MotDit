#include "image.h"
#include "exportstrategy.h"

Image::Image() : Binary()
{
}

Note::NoteType Image::getType()const{
    return IMAGE;
}
