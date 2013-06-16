#ifndef EXPORTSTRATEGY_H
#define EXPORTSTRATEGY_H

#include "document.h"
#include "image.h"
#include "video.h"
#include "audio.h"
#include "article.h"

#include <QMap>

/*!
 * \file exportstrategy.h
 * \brief Classe ExportStrategy : permet d'exporter les notes dans type d'exports.
 * \author Pauline Cuche/Simon Robain
 */
/*!
 * \class ExportStrategy
 * \brief Cette classe virtuelle permet d'exporter les différents types de notes dans différents types d'exports.
 *Elle est héritée par chacun des exports correspondants.
 */
class ExportStrategy
{
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe ExportStrategy
         */
    ExportStrategy();
    /*!
         *  \brief Cette Methode Virtuelle Pure permet de rentrer les balises ouvrantes dans le fichier d'export correspondant
         */
    virtual QString header(Note *n)=0;
    /*!
         *  \brief Cette Methode Virtuelle Pure permet de rentrer les balises fermantes dans le fichier d'export correspondant
         */
    virtual QString footer(Note *n)=0;
    /*!
         *  \brief Cette Methode Virtuelle Pure permet d'exporter un Document dans le fichier d'export correspondant
         */
    virtual QString exportNote(Document* d , unsigned int titreLvl)=0;
    /*!
         *  \brief Cette Methode Virtuelle Pure permet d'exporter un Article dans le fichier d'export correspondant
         */
    virtual QString exportNote(Article* a , unsigned int titreLvl)=0;
    /*!
         *  \brief Cette Methode Virtuelle Pure permet d'exporter une Video dans le fichier d'export correspondant
         */
    virtual QString exportNote(Video* v , unsigned int titreLvl)=0;
    /*!
         *  \brief Cette Methode Virtuelle Pure permet d'exporter un Audio dans le fichier d'export correspondant
         */
    virtual QString exportNote(Audio* a , unsigned int titreLvl)=0;
    /*!
         *  \brief Cette Methode Virtuelle Pure permet d'exporter une Image dans le fichier d'export correspondant
         */
    virtual QString exportNote(Image* i , unsigned int titreLvl)=0;

    //static QMap<QString, ExportStrategy*> getExportStrategy();
};

#endif // EXPORTSTRATEGY_H
