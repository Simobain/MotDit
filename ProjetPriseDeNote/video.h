#ifndef VIDEO_H
#define VIDEO_H
#include "binary.h"

class Video : public Binary
{
    QString genererId();
public:
    Video();
};

#endif // VIDEO_H
