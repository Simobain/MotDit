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
         *\param id : ID de l'article
         *\param titre : titre de l'article
         *\param texte : texte de l'article (vide par défaut)
         */
    Article(const QString& id, const QString& titre, const QString& text="");
    /*!
         *  \brief Accesseur de l'attribut texte
         *\return texte : texte de l'article
         */
    QString getTexte() const {return texte;}
    /*!
         *  \brief Setteur de l'attribut texte
         *\param texte : texte que l'on souhaite rentrer dans l'article
         */
    void setTexte(const QString& t);
    /*!
         *  \brief Sauvegarde d'un article
         *Methode qui permet la sauvegarde d'un article
         *\param directory : chemin d'accès du lieu ou l'on souhaite sauvegarder l'article
         */
    void save(const QString& directory);
    /*!
         *  \brief Accesseur du type de la note (ici ARTICLE)
         *\return NoteType : type de la note renvoyée
         */
    NoteType getType() const;

};


#endif // ARTICLE_H
