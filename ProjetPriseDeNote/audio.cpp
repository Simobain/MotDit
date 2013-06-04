#include "audio.h"


Audio::Audio() : Binary()
{
}

Note::NoteType Audio::getType() const{
    return AUDIO;
}
