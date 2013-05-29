#ifndef VIDEO_H
#define VIDEO_H
#include "binary.h"

class Video : public Binary
{
    Video(const Video& v);
    Video& operator=(const Video& v);
public:
    Video();
};

#endif // VIDEO_H
