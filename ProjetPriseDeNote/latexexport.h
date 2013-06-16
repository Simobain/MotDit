#ifndef TEXEXPORT_H
#define TEXEXPORT_H

#include "exportstrategy.h"

/*!
 * \file latexexport.h
 * \brief Classe LaTexExport : permet d'exporter les notes en LaTex
 * \author Pauline Cuche/Simon Robain
 */
/*!
 * \class LaTexExport
 * \brief Cette classe permet d'exporter les différents types de notes en LaTex.
 *Elle hérite de ExportStrategy
 */
class LaTexExport : public ExportStrategy
{
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe LaTexExport
         */
    LaTexExport();
    /*!
         *  \brief Cette methode permet de rentrer les balises ouvrantes d'un fichier .Tex
         */
    QString header(Note*);
    /*!
         *  \brief Cette methode permet de rentrer les balises fermantes d'un fichier .Tex
         */
    QString footer(Note*);
    /*!
         *  \brief Cette methode permet d'exporter un Document en LaTex
         */
    QString exportNote(Document* d , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter un Article en LaTex
         */
    QString exportNote(Article* a , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter une Video en LaTex
         */
    QString exportNote(Video* v , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter un Audio en LaTex
         */
    QString exportNote(Audio* a , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter une Image en LaTex
         */
    QString exportNote(Image* i , unsigned int titreLvl);
};

#endif // TEXEXPORT_H
