#ifndef IMAGE_H
#define IMAGE_H
#include "binary.h"

/*!
 * \file image.h
 * \brief Classe de base permettant de définir des notes de type image.
 * \author Pauline Cuche/Simon Robain
 */

/**
 *\class Image
 * \brief Classe représentant les Images
 */

class Image : public Binary
{
    Image(const Image& i);
    Image& operator=(const Image& i);

public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe Article
         */
    Image();
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Image
         *\param id : ID de l'Image
         *\param titre : titre de l'Image
         *\param path : chemin d'accès à l'image vide par défaut
         *\param desc : descriptif de l'image vide par défaut
         */
    Image(const QString& id, const QString& titre, const QString &path="", const QString& desc="");
    /*!
         *  \brief Accesseur du type de la note (ici IMAGE)
         *\return NoteType : type de la note renvoyée
         */
    NoteType getType() const;



};

#endif // IMAGE_H
