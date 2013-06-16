#ifndef AUDIO_H
#define AUDIO_H
#include "binary.h"

/*!
 * \file audio.h
 * \brief Classe de base permettant de définir une note de type Audio
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class Audio
 * \brief Classe représentant les Audio
 */
class Audio : public Binary
{
    Audio(const Audio& a);
    Audio& operator=(const Audio& a);
public:
    /*!
         *  \brief Constructeur Par Defaut
         *  Constructeur par défaut de la classe Audio
         */
    Audio();
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Audio
         *\param id : ID de l'Audio
         *\param titre : titre de l'Audio
         *\param path : chemin d'accès à la musique que l'on souhaite référencer (vide par défaut)
         *\param desc : description de l'Audio (vide par défaut)
         */
    Audio(const QString& id, const QString& titre, const QString& path="", const QString& desc="");
    /*!
         *\brief Accesseur du type de la note (ici AUDIO)
         *\return NoteType : type de la note renvoyée
         */
    NoteType getType() const;
};

#endif // AUDIO_H
