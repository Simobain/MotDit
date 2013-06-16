#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDebug>

class ExportStrategy;

/*!
 * \file note.h
 * \brief Classe de base permettant de définir toutes les notes
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class Note
 * \brief Classe abstraite représentant toutes les Notes
 *Elle est héritée par tout les types de Note.
 */

class Note { //classe abstraite
    QString id;/*!< ID unique correspondant à une seule Note*/
protected :
    QString titre;  /*!< Titre de la Note*/
    bool modified; /*!< Booleen témoignant si la note a été modifiée ou non*/
    bool saved; /*!< Booleen témoignant si la note a été sauvegardée ou non*/
    bool inTheFile;  /*!< Booleen témoignant si la note a été prise en compte dans le fichier de description ou non*/

public :
    /**
     * \enum NoteType
     * \brief Constantes des différents types de notes
     */
    enum NoteType{ARTICLE, DOCUMENT, AUDIO, IMAGE, VIDEO};
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe Note
         */
    Note();
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe Note
         *\param i : ID de la Note
         *\param t : titre de la Note
         */
    Note(const QString& i, const QString& t);
    /*!
         *  \brief Accesseur de l'attribut titre
         *\return titre : titre de la Note
         */
    QString getTitre() const {return titre;} //accesseur titre
    /*!
         *  \brief Accesseur de l'attribut id
         *\return id : id de la Note
         */
    QString getId() const {return id;} //accesseur id (nom du fichier)
    /*!
         *  \brief Accesseur de l'attribut mofdified
         *\return modified : booléen true si la note a été modifiée false sinon
         */
    bool modif() const {return modified;} // savoir si la note a été modifiée
    /*!
         *  \brief Accesseur de l'attribut inTheFile
         *\return inTheFile : booléen true si la note est dans le fichier de description false sinon
         */
    bool isInTheFile()const {return inTheFile;}
    /*!
         *  \brief Setteur de l'attribut inTheFile
         *  Permet de mettre à jour l'attribut inTheFile
         *\param b : booléen
         */
    void setInTheFile(bool b){inTheFile=b;}
    /*!
         *  \brief Sauvegarde de la Note dans le fichier de description
         *\param id : id de la Note à sauvegarder
         *\param chemin : chemin d'accès de l'espace de travail
         */
    void saveInTheFile(const QString& id, const QString& chemin);
    /*!
         *  \brief Setteur de l'attribut titre
         *\param t : titre que l'on souhaite rentrer dans la Note
         */
    void setTitre(const QString& t); // permet de modifier le titre d'une note
    //virtual QString ExportNote(ExportStrategy* es)=0;
    //virtual QString ExportAsPart(ExportStrategy* es, unsigned int titlelevel)=0;
    /*!
         *  \brief Accesseur virtuel pur du type de la note
         *\return NoteType : type de la note renvoyée
         */
    virtual NoteType getType()const=0;
    /*!
         *  \brief Accesseur de l'attribut saved
         *\return saved : booléen true si la note a été sauvée false sinon
         */
    bool isSaved(){return saved;}
    /*!
         *  \brief Setteur de l'attribut saved
         *  Permet de mettre à jour l'attribut saved
         *\param ok : booléen
         */
    void setSaved(bool ok){saved=ok;}
    /*!
         *  \brief Sauvegarde d'une Note
         *Methode Virtuelle pure qui permet la sauvegarde d'une Note
         *\param directory : chemin d'accès à l'espace de travail
         */
    virtual void save(const QString& directory)=0;

};

#endif

