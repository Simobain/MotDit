#ifndef AUDIO_H
#define AUDIO_H
#include "binary.h"

class Audio : public Binary
{
    Audio(const Audio& a);
    Audio& operator=(const Audio& a);
public:
    Audio();
    Audio(const QString& id, const QString& titre, const QString& path="", const QString& desc="");
    NoteType getType() const;
};

#endif // AUDIO_H
