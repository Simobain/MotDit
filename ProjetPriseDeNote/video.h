#ifndef VIDEO_H
#define VIDEO_H
#include "binary.h"

class Video : public Binary
{
    Video(const Video& v);
    Video& operator=(const Video& v);
public:
    Video();
    Video(const QString& id, const QString& titre, const QString& path="", const QString& desc="");
    NoteType getType() const;
};

#endif // VIDEO_H
