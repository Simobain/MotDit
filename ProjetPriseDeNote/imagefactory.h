#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H
#include "notefactory.h"
#include "image.h"

class NotesManager;

/*!
 * \file imagefactory.h
 * \brief Classe ImageFactory permettant de construire une note de type Image
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class ImageFactory
 * \brief Classe permettant d'instancier des objets de type Image
 *Elle hérite de NoteFactory
 */
class ImageFactory : public NoteFactory
{
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe ArticleFactory
         */
    ImageFactory();
    /*!
         *  \brief Détermine un ID unique
         *
         *  Renvoie un id unique précédé du type de Note ici Image
         */
    QString getNewId();
    /*!
         *  \brief Fabrique une Image
         *
         *  \param id : id de l'Image
         *  \param title : titre de l'Image
         *  \param path : chemin d'accès à l'image que l'on souhaite incorporée dans notre note Image, vide par défaut
         *  \param desc : descriptif de l'Image
         *  \return Note* : un pointeur sur notre Image nouvellement créée
         */

    Note* buildNote(const QString& id,const QString& title, const QString& path="", const QString& desc="");
    /*!
         *  \brief Fabrique une nouvelle Image
         *
         *  Cette methode créée un nouvel ID en appelant getNewId() et appelle buildNote()
         *  \param title : titre de l'image
         *  \param path : chemin d'accès à l'image référencée par la note Image, vide par défaut
         *  \return Note* : un pointeur sur notre Image créée
         *
         */
    Note* buildNewNote(const QString& title, const QString &path);
    Note* buildNotecopy(const Note* n);
    /*!
         *  \brief Charge une Image déjà existante
         *  \param id : id de l'Image
         *  \param chemin : chemin d'accès à l'Image
         *  \return Note* : un pointeur sur notre Image venant d'être chargé
         *
         */
    Note* chargerNote(const QString& id, const QString& chemin);
};

#endif // IMAGEFACTORY_H
