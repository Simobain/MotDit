#ifndef HTMLEXPORT_H
#define HTMLEXPORT_H

#include "exportstrategy.h"
/*!
 * \file htmlexport.h
 * \brief Classe HTMLexport : permet d'exporter les notes en HTML5.
 * \author Pauline Cuche/Simon Robain
 */
/*!
 * \class HTMLexport
 * \brief Cette classe permet d'exporter les différents types de notes en HTML5.
 *Elle hérite de ExportStrategy
 */
class HTMLexport : public ExportStrategy
{
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe HTMLexport
         */
    HTMLexport();
    /*!
         *  \brief Cette methode permet de rentrer les balises ouvrantes d'un fichier .html
         */
    QString header(Note*);
    /*!
         *  \brief Cette methode permet de rentrer les balises fermantes d'un fichier .html
         */
    QString footer(Note*);
    /*!
         *  \brief Cette methode permet d'exporter un Document en HTML5
         */
    QString exportNote(Document* d , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter un Article en HTML5
         */
    QString exportNote(Article* a , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter une Video en HTML5
         */
    QString exportNote(Video* v , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter un Audio en HTML5
         */
    QString exportNote(Audio* a , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter une Image en HTML5
         */
    QString exportNote(Image* i , unsigned int titreLvl);
};

#endif // HTMLEXPORT_H
