#ifndef IMAGE_H
#define IMAGE_H
#include <QString>
#include "binary.h"

class Image : public Binary
{
    QString genererId();
public:
    Image();

};

#endif // IMAGE_H
