#ifndef AUDIO_H
#define AUDIO_H
#include "binary.h"
#include <QString>

class Audio : public Binary
{
    QString genererId();
public:
    Audio();
};

#endif // AUDIO_H
