#include "video.h"
#include "exportstrategy.h"

Video::Video() : Binary()
{
}

Note::NoteType Video::getType()const {
    return VIDEO;
}
