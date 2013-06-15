#ifndef IMAGEFACTORY_H
#define IMAGEFACTORY_H
#include "notefactory.h"
#include "image.h"

class NotesManager;

/*!
 * \file imagefactory.h
 * \brief Classe ImageFactory permettant de construire une note de type Image
 * \author Pauline Cuche/Simon Robain
 */

class ImageFactory : public NoteFactory
{
public:
    ImageFactory();
    QString getNewId();
    Note* buildNote(const QString& id,const QString& title, const QString& path="", const QString& desc="");
    Note* buildNewNote(const QString& title, const QString &path);
    Note* buildNotecopy(const Note* n);
    Note* chargerNote(const QString& id, const QString& chemin);
};

#endif // IMAGEFACTORY_H
