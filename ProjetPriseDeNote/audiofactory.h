#ifndef AUDIOFACTORY_H
#define AUDIOFACTORY_H
#include "notefactory.h"
#include "audio.h"

/*!
 * \file audiofactory.h
 * \brief Classe AudioFactory permettant de construire une note de type Audio
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class AudioFactory
 * \brief Classe permettant d'instancier des objets de types Audio
 *Elle hérite de NoteFactory
 */
class NotesManager;

class AudioFactory : public NoteFactory
{
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe AudioFactory
         */
    AudioFactory();
    /*!
         *  \brief Détermine un ID unique
         *
         *  Renvoie un id unique précédé du type de Note ici audio
         */
    QString getNewId();
    /*!
         *  \brief Fabrique un Audio
         *
         *  \param id : id de l'Audio
         *  \param titre : titre de l'Audio
         *  \param path : chemin d'accès au fichier représentant l'Audio note, vide par défaut
         *  \param desc : descriptif de l'Audio vide par défaut
         *  \return Note* : un pointeur sur notre Audio nouvellement créé
         */
    Note* buildNote(const QString& id,const QString& title, const QString& path="", const QString& desc="");
    /*!
         *  \brief Fabrique un nouvel Audio
         *
         *  Cette methode créée un nouvel ID en appelant getNewId() et appelle buildNote()
         *  \param titre : titre de l'audio
         *  \param path : chemin d'accès à l'audio, vide par défaut
         *  \return Note* : un pointeur sur notre Audio créé
         *
         */
    Note* buildNewNote(const QString& title, const QString &path);
    Note* buildNotecopy(const Note* n);
    /*!
         *  \brief Charge un Audio déjà existant
         *  \param id : id de l'Audio
         *  \param chemin : chemin d'accès à l'Audio
         *  \return Note* : un pointeur sur notre Audio venant d'être chargé
         *
         */
    Note* chargerNote(const QString& id, const QString& chemin);

};

#endif // AUDIOFACTORY_H
