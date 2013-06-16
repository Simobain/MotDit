#ifndef DOCUMENTFACTORY_H
#define DOCUMENTFACTORY_H
#include "notefactory.h"
#include "document.h"
#include "notesmanager.h"
//class NotesManager;

/*!
 * \file documentfactory.h
 * \brief Classe DocumentFactory permettant de construire une note de type Document
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class DocumentFactory
 * \brief Classe permettant d'instancier des objets de types Document
 *Elle hérite de NoteFactory
 */
class DocumentFactory : public NoteFactory
{
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe DocumentFactory
         */
    DocumentFactory();
    /*!
         *  \brief Détermine un ID unique
         *
         *  Renvoie un id unique précédé du type de Note ici Document
         */
    QString getNewId();
    /*!
         *  \brief Fabrique un Document
         *
         *  \param id : id du Document
         *  \param titre : titre du Document
         *  \param contenu : vide par défaut, ce champ n'est pas renseigné pour les Document
         *  \param desc : vide par défaut, ce champ n'est pas renseigné pour les Document
         *  \return Note* : un pointeur sur notre Document nouvellement créé
         */
    Note* buildNote(const QString& id,const QString& titre, const QString& contenu="", const QString& desc="");
    /*!
         *  \brief Fabrique un nouveau Document
         *
         *  Cette methode créée un nouvel ID en appelant getNewId() et appelle buildNote()
         *  \param titre : titre du Document
         *  \param path : chemin d'accès au Document, vide par défaut
         *  \return Note* : un pointeur sur notre Document créé
         *
         */
    Note* buildNewNote(const QString& titre, const QString& path="");
    Note* buildNotecopy(const Note* n);
    /*!
         *  \brief Charge un Document déjà existant
         *  \param id : id du Document
         *  \param chemin : chemin d'accès au Document
         *  \return Note* : un pointeur sur notre Document venant d'être chargé
         *
         */
    Note* chargerNote(const QString& id, const QString& chemin);
};

#endif // DOCUMENTFACTORY_H
