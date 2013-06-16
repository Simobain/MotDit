#ifndef ARTICLE_H
#define ARTICLE_H
#include "note.h"
class NotesManager;
/*!
 * \file article.h
 * \brief Classe de base permettant de définir une note de type article
 * \author Pauline Cuche/Simon Robain
 */

/**
 *\class Article
 * \brief Classe représentant les Articles
 */

class Article : public Note {
    QString texte; /*!< Texte de l'article*/
    Article(const Article& a);
    Article& operator=(const Article& a);


public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe Article
         */
    Article();
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Article
         *\param id : ID de l'Article
         *\param titre : titre de l'Article
         *\param texte : texte de l'Article (vide par défaut)
         */
    Article(const QString& id, const QString& titre, const QString& text="");
    /*!
         *  \brief Accesseur de l'attribut texte
         *\return texte : texte de l'Article
         */
    QString getTexte() const {return texte;}
    /*!
         *  \brief Setteur de l'attribut texte
         *\param texte : texte que l'on souhaite rentrer dans l'Article
         */
    void setTexte(const QString& t);
    /*!
         *  \brief Sauvegarde d'un Article
         *Methode qui permet la sauvegarde d'un Article
         *\param directory : chemin d'accès à l'espace de travail
         */
    void save(const QString& directory);
    /*!
         *  \brief Accesseur du type de la note (ici ARTICLE)
         *\return NoteType : type de la note renvoyée
         */
    NoteType getType() const;

};


#endif // ARTICLE_H
