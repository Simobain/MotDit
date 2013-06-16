#ifndef VIDEO_H
#define VIDEO_H
#include "binary.h"

/*!
 * \file video.h
 * \brief Classe de base permettant de définir des notes de type video.
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class Video
 * \brief Classe représentant les Video
 */

class Video : public Binary
{
    Video(const Video& v);
    Video& operator=(const Video& v);
public:
    /*!
         *  \brief Constructeur Par Defaut
         *  Constructeur par défaut de la classe Video
         */
    Video();
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Video
         *\param id : ID de la Video
         *\param titre : titre de la Video
         *\param path : chemin d'accès à la vidéo que l'on souhaite référencer (vide par défaut)
         *\param desc : description de la Video (vide par défaut)
         */
    Video(const QString& id, const QString& titre, const QString& path="", const QString& desc="");
    /*!
         *\brief Accesseur du type de la note (ici VIDEO)
         *\return NoteType : type de la note renvoyée
         */
    NoteType getType() const;
};

#endif // VIDEO_H
