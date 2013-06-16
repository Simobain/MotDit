#ifndef NOTEFACTORY_H
#define NOTEFACTORY_H


#include<sstream>
#include <iostream>

#include <QDebug>
#include<QSettings>
#include <QMap>

#include "time.h"
#include "note.h"

/*!
 * \file notefactory.h
 * \brief Classe NoteFactory permettant de construire tout les types de notes
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class NoteFactory
 * \brief Classe permettant d'instancier tout les types de Note
 *Elle est héritée par toutes les autres factory.
 *
 */
class NoteFactory
{
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe NoteFactory
         */
    NoteFactory();
    /*!
         *  \brief Fabrique une Note
         *Methode virtuelle pure redéfinie pour chaque type de Note
         *  \param id : id de Note
         *  \param title : titre de la Note
         *  \param contenu : contenu de la Note, vide par défaut
         *  \param desc : descriptif de la Note, vide par défaut
         *  \return Note* : un pointeur sur notre Note nouvellement créée
         */
    virtual Note* buildNote(const QString& id,const QString& title, const QString& contenu, const QString& desc)=0;
    /*!
         *  \brief Fabrique une nouvelle Note
         *Methode virtuelle pure redéfinie pour chaque type de Note
         *  Cette methode virtuelle pure créée un nouvel ID en appelant getNewId() et appelle buildNote()
         *  \param title : titre de la Note
         *  \param path : chemin source du contenu vide par défaut
         *  \return Note* : un pointeur sur notre Note créée
         *
         */
    virtual Note* buildNewNote(const QString& title, const QString& path="")=0;
    /*!
         *  \brief Charge une Note déjà existante
         *Methode virtuelle pure redéfinie pour chaque type de Note
         *  \param id : id de la Note
         *  \param chemin : chemin d'accès à l'espace de travail
         *  \return Note* : un pointeur sur notre Note venant d'être chargée
         *
         */
    virtual Note* chargerNote(const QString& id, const QString& chemin)=0;
    //virtual Note* buildNotecopy()=0;
    //static QMap<Qstring, NoteFactory*> getFactories();

protected :
    /*!
         *  \brief Détermine un ID unique
         *\return id : un id unique
         */
    virtual QString getNewId();//Renvoie un ID unique

};

#endif // NOTEFACTORY_H
