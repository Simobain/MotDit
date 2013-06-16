#ifndef ARTICLEFACTORY_H
#define ARTICLEFACTORY_H
#include "notefactory.h"
#include "article.h"

/*!
 * \file articlefactory.h
 * \brief Classe ArticleFactory permettant de construire une note de type Article
 * \author Pauline Cuche/Simon Robain
 */

/**
 *\class ArticleFactory
 * \brief Classe permettant d'instancier des objets de type Article
 *Elle hérite de NoteFactory
 */
class ArticleFactory : public NoteFactory
{
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe ArticleFactory
         */
    ArticleFactory();
    /*!
         *  \brief Détermine un ID unique
         *
         * \return id : Renvoie un id unique précédé du type de Note ici Article
         */
    QString getNewId();
    /*!
         *  \brief Fabrique un Article
         *
         *  \param id : id de Article
         *  \param titre : titre de l'Article
         *  \param texte : texte de l'Article, vide par défaut
         *  \param desc : vide par défaut, ce champ n'est pas renseigné pour les Article
         *  \return Note* : un pointeur sur notre Article nouvellement créé
         */
    Note* buildNote(const QString& id, const QString& titre, const QString &texte="", const QString& desc="");
    /*!
         *  \brief Fabrique un nouvel Article
         *
         *  Cette methode créée un nouvel ID en appelant getNewId() et appelle buildNote()
         *  \param titre : titre de l'Article
         *  \param path : vide par défaut
         *  \return Note* : un pointeur sur notre Article créé
         *
         */
    Note* buildNewNote(const QString &titre, const QString& path="");
    Note* buildNotecopy(const Note* n);
    /*!
         *  \brief Charge un Article déjà existant
         *  \param id : id de l'Article
         *  \param chemin : chemin d'accès à l'espace de travail
         *  \return Note* : un pointeur sur notre Article venant d'être chargé
         *
         */
    Note* chargerNote(const QString& id, const QString& chemin);
};

#endif // ARTICLEFACTORY_H
