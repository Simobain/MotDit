#ifndef DOCUMENT_H
#define DOCUMENT_H
#include "note.h"
#include <QSet>

/*!
 * \file document.h
 * \brief Classe de base permettant de définir des notes de type Document
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class Document
 * \brief Classe représentant les Documents, les documents sont des agrégats de notes.
 */
class Document : public Note
{
    QSet<Note*> sousNotes;/*!< Ensemble des notes composant le document*/
    Document(const Document&);
    Document& operator=(const Document&);
    bool loaded;/*!< Booléen permettant de savoir si le document a déjà été chargé ou non*/

public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Document
         *\param id : ID du document
         *\param titre : titre du Document
         */
    Document(const QString& id,const QString& titre);
    //QString ExportAsPart(ExportStrategy *es, unsigned int titlelevel);
    /*!
         *  \brief Ajout d'une sous-note
         *
         *  Cette méthode permet d'ajouter une sous-note à l'attribut sousNotes
         *\param n : pointeur sur la sous-note à ajouter au Document
         */
    void addSubNote(Note *n);
    //void addSubNote(Note *n, QString id);
    /*!
         *  \brief Retrait d'une sous-note
         *
         *  Cette méthode permet de retirer une sous-note à l'attribut sousNotes
         *\param n : pointeur sur la sous-note à retirer du Document
         */
    void removeSubNote(Note *n);
    /*!
         *  \brief Accesseur à sousNotes
         *
         *  Cette méthode permet d'acceder à l'attribut sousNotes
         *\return sousNotes : ensemble des sous-notes du Document
         */
    QSet<Note*> getSousNotes();
    //Note* getSubNote(QString id);
    /*!
         *  \brief Accesseur du type de la note (ici DOCUMENT)
         *\return NoteType : type de la note renvoyée
         */
    NoteType getType() const;
    /*!
         *  \brief Sauvegarde d'un Document
         *Methode qui permet la sauvegarde d'un Document
         *\param directory : chemin d'accès du lieu ou l'on souhaite sauvegarder le Document
         */
    void save(const QString &directory);
    /*!
         *  \brief Accesseur à l'attribut loaded
         *\return loaded : true si la note a déjà été chargé, false sinon
         */
    bool getLoaded() const  {return loaded;}
    /*!
         *  \brief Setteur de l'attribut loaded
         *\param b : true si la note a déjà été chargé, false sinon
         */
    void setLoaded(bool b){loaded=b ;}
};

#endif // DOCUMENT_H
