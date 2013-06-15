#ifndef IMAGE_H
#define IMAGE_H
#include "binary.h"

/*!
 * \file image.h
 * \brief Classe de base permettant de définir des notes de type image.
 * \author Pauline Cuche/Simon Robain
 */

class Image : public Binary
{
    Image(const Image& i);
    Image& operator=(const Image& i);

public:
    Image();
    Image(const QString& id, const QString& titre, const QString &path="", const QString& desc="");
    NoteType getType() const;



};

#endif // IMAGE_H
