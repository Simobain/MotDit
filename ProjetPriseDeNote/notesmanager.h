#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H
#include <iostream>
#include <map> //Bug si on remplace toutes les map par des QMap (au niveau de l'iterateur qui doit pas être exactement le même

#include <QMessageBox>
#include <QApplication>
#include <QSettings>
#include <QDebug>

#include "articlefactory.h"
#include "videofactory.h"
#include "documentfactory.h"
#include "imagefactory.h"
#include "audiofactory.h"

#include "htmlexport.h"
#include "latexexport.h"
#include "textexport.h"
/*!
 * \file notesmanager.h
 * \brief Classe permettant de gérer l'ensemble des notes du logiciel MotDit
 * \author Pauline Cuche/Simon Robain
 */

/**
 *\class NotesManager
 * \brief Classe chapeautant toutes les notes.
 *Elle peut les instancier, les supprimer, les exporter et choisir l'espace de travail
 *
 */
class NotesManager {

    std::map < QString,NoteFactory* > factories;/*!< Map permettant d'appeler les différentes filles de NoteFactory*/
    std::map < QString,ExportStrategy* > strategies;/*!< Map permettant d'appeler les différentes filles de ExportStrategy*/
    QSet<Note*> ensnotes;/*!< Ensemble de toutes les notes d'un espace de travail*/
    QString EspaceDeTravail;/*!< Espace de travail dans lequel l'utilisateur souhaite travailler*/
    static NotesManager* instance; /*!< Pointeur permettant d'accèder à l'unique instance de NotesManager */

    /*!
         *  \brief Constructeur Par Defaut, il est non-accessible pour garantir l'unicité du NotesManager
         *
         *  Constructeur par défaut de la classe NotesManager
         */
    NotesManager();
    /*!
         *  \brief Destructeur Privé,il est non-accessible pour garantir l'unicité du NotesManager
         *
         *  Destructeur de la classe NotesManager.
         */
    ~NotesManager();
    NotesManager& operator=(const NotesManager&);



public:
    /*!
         *  \brief Methode qui permet d'accèder à l'unique instance du NotesManager
         *\return NotesManager* : un pointeur sur l'instance du NotesManager
         */
    static NotesManager* getInstance();
    /*!
         *  \brief Methode qui permet de libérer l'unique instance du NotesManager
         */
    void libereInstance();
    /*!
         *  \brief Création d'une Note
         *\param type_note : type de la note que le NotesManager va créer
         *\param titre : titre de la note que le NotesManager va créer
         *\param path : chemin d'accès à la source du contenu, vide par défaut
         */
    void creerNote(const QString& type_note, const QString& titre,const QString& path="");
    /*!
         *  \brief Suppression d'une Note
         */
    void supprNote (Note* n);
    /*!
         *  \brief Retrouve une note à partir de son titre
         *\param titre : titre de la note dont on veut retrouver le pointeur
         */
    Note* getNoteFromTitre(const QString& titre);
    /*!
         *  \brief Setteur d'EspaceDeTravail
         *\param e : chemin vers le nouvel espace de travail
         */
    void setEspaceDeTravail(const QString& e);
    /*!
         *  \brief Accesseur d'EspaceDeTravail
         *\return e : chemin vers l'espace de travail
         */
    QString getEspaceDeTravail()const {return EspaceDeTravail;}
    /*!
         *  \brief Methode qui charge toutes les Note dès le lancement du logiciel MotDit
         */
    void chargerNotes();
    /*!
         *  \brief Accesseur d'ensnotes
         *\return ensnotes: Attribut contenant toutes les Note
         */
    const QSet<Note *>& getEnsnote()const;
    /*!
         *  \brief Fonction pour exporter tout type de note
         *\param n : la note à exporter
         *\param typeExport : type de l'export souhaité
         */
    QString exportNote(Note* n, QString typeExport);
    /*!
         *  \brief Fonction pour exporter les sous notes d'un document
         *\param n : la sous-note à exporter
         *\param typeExport : type de l'export souhaité
         */
    QString exportNoteAsPart(Note* n, QString typeExport);
    /*!
         *  \brief Retrouve une note à partir de son id
         *\param id : id de la note dont on veut retrouver le pointeur
         */
    Note * getNoteFromId(const QString& id);

};


#endif // NOTESMANAGER_H
