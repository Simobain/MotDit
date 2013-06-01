#ifndef IMAGE_H
#define IMAGE_H
#include <QString>
#include "binary.h"

class Image : public Binary
{
    Image(const Image& i);
    Image& operator=(const Image& i);

public:
    Image();
    NoteType getType() const;

};

#endif // IMAGE_H
