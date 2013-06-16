#ifndef TEXTEXPORT_H
#define TEXTEXPORT_H
#include "exportstrategy.h"
/*!
 * \file textexport.h
 * \brief Classe TextExport : permet d'exporter les notes en fichier texte.
 * \author Pauline Cuche/Simon Robain
 */
/*!
 * \class TextExport
 * \brief Cette classe permet d'exporter les différents types de notes en fichier texte.
 *Elle hérite de ExportStrategy
 */
class TextExport : public ExportStrategy
{
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe TextExport
         */
    TextExport();
    /*!
         *  \brief Cette methode permet de rentrer les balises ouvrantes d'un fichier .txt
         */
    QString header(Note*);
    /*!
         *  \brief Cette methode permet de rentrer les balises fermantes d'un fichier .txt
         */
    QString footer(Note*);
    /*!
         *  \brief Cette methode permet d'exporter un Document en .txt
         */
    QString exportNote(Document* d , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter un Article en .txt
         */
    QString exportNote(Article* a , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter une Video en .txt
         */
    QString exportNote(Video* v , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter un Audio en .txt
         */
    QString exportNote(Audio* a , unsigned int titreLvl);
    /*!
         *  \brief Cette methode permet d'exporter une Image en .txt
         */
    QString exportNote(Image* i , unsigned int titreLvl);
};

#endif // TEXTEXPORT_H
