#ifndef VIDEOFACTORY_H
#define VIDEOFACTORY_H
#include "notefactory.h"
#include "video.h"

class NotesManager;

/*!
 * \file videofactory.h
 * \brief Classe VideoFactory permettant de construire une note de type vidéo
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class VideoFactory
 * \brief Classe permettant d'instancier des objets de types Video
 *Elle hérite de NoteFactory
 */
class VideoFactory : public NoteFactory
{
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe VideoFactory
         */
    VideoFactory();
    /*!
         *  \brief Détermine un ID unique
         *
         *  Renvoie un id unique précédé du type de Note ici video
         */
    QString getNewId();
    /*!
         *  \brief Fabrique une Video
         *
         *  \param id : id de l'Video
         *  \param titre : titre de l'Video
         *  \param path : chemin d'accès au fichier représentant la Video note, vide par défaut
         *  \param desc : descriptif de la Video vide par défaut
         *  \return Note* : un pointeur sur notre Video nouvellement créée
         */
    Note* buildNote(const QString& id,const QString& title, const QString& path="",const QString& desc="");
    /*!
         *  \brief Fabrique une nouvelle note Video
         *
         *  Cette methode créée un nouvel ID en appelant getNewId() et appelle buildNote()
         *  \param titre : titre de l'Video
         *  \param path : chemin d'accès à la Video, vide par défaut
         *  \return Note* : un pointeur sur notre Video créée
         *
         */
    Note* buildNewNote(const QString& title, const QString &path);
    Note* buildNotecopy(const Note* n);
    /*!
         *  \brief Charge une note Video déjà existante
         *  \param id : id de la Video
         *  \param chemin : chemin d'accès à l'Video
         *  \return Note* : un pointeur sur notre Video venant d'être chargée
         *
         */
    Note* chargerNote(const QString& id, const QString& chemin);
};

#endif // VIDEOFACTORY_H
