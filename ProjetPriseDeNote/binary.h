#ifndef BINARY_H
#define BINARY_H
#include"note.h"

/*!
 * \file article.h
 * \brief Classe de base permettant de définir des notes de type binaire (audio,video,image)
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class Binary
 * \brief Classe Abstraite héritée par toutes les notes "binaires"
 */
class Binary : public Note //classe abstraite
{
    QString chemin;/*!< chemin d'accès au fichier binaire*/
    QString description;/*!< description de la note*/
    Binary(const Binary& b);
    Binary& operator=(const Binary& b);

public:
public:
    /*!
         *  \brief Constructeur Par Defaut
         *  Constructeur par défaut de la classe Audio
         */
    Binary();
    /*!
         *  \brief Constructeur
         *
         *  Constructeur par défaut de la classe Audio
         *\param i : ID de la note
         *\param t : titre de la note
         *\param c : chemin d'accès au fichier référencé par la note (vide par défaut)
         *\param d : description de la note (vide par défaut)
         */
    Binary(const QString& i, const QString& t, const QString& c="", const QString& d="");
    /*!
         *  \brief Accesseur de l'attribut description
         *\return description : description de la note
         */
    QString getDescription() const {return description;}
    /*!
         *  \brief Accesseur de l'attribut chemin
         *\return chemin : chemin d'accès à la note
         */
    QString getChemin() const {return chemin;}
    /*!
         *  \brief Setteur de l'attribut descrption
         *\param d : description que l'on souhaite rentrer dans la note
         */
    void setDescription(const QString& d);
    /*!
         *  \brief Setteur de l'attribut chemin
         *\param c: chemin d'accès au fichier référencé par la note
         */
    void setChemin(const QString& c);

    /*!
         *  \brief Sauvegarde d'une note de type binaire
         *Methode qui permet la sauvegarde d'une note binaire
         *\param directory : chemin d'accès du lieu ou l'on souhaite sauvegarder la note
         */
    void save(const QString& directory);
};

#endif // BINARY_H
