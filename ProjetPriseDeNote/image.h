#ifndef IMAGE_H
#define IMAGE_H
#include "binary.h"

class Image : public Binary
{
    Image(const Image& i);
    Image& operator=(const Image& i);

public:
    Image();
    Image(const QString& id, const QString& titre, const QString &path="");
    NoteType getType() const;

};

#endif // IMAGE_H
