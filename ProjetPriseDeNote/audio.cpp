#include "audio.h"
#include "exportstrategy.h"

Audio::Audio() : Binary()
{
}

Note::NoteType Audio::getType() const{
    return AUDIO;
}
