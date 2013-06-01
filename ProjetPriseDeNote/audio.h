#ifndef AUDIO_H
#define AUDIO_H
#include "binary.h"
#include <QString>

class Audio : public Binary
{
    Audio(const Audio& a);
    Audio& operator=(const Audio& a);
public:
    Audio();
    NoteType getType() const;
};

#endif // AUDIO_H
