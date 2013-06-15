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
 * \file notesfactory.h
 * \brief Classe NoteFactory permettant de construire tout les types de notes
 * \author Pauline Cuche/Simon Robain
 */

class NoteFactory
{
public:
    NoteFactory();
    virtual Note* buildNote(const QString& id,const QString& title, const QString& contenu, const QString& desc)=0;
    virtual Note* buildNewNote(const QString& title, const QString& path="")=0;
    virtual Note* chargerNote(const QString& id, const QString& chemin)=0;
    //virtual Note* buildNotecopy()=0;
    //static QMap<Qstring, NoteFactory*> getFactories();

protected :
    virtual QString getNewId();//Renvoie un ID unique

};

#endif // NOTEFACTORY_H
