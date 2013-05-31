#ifndef TEXEXPORT_H
#define TEXEXPORT_H

#include "exportstrategy.h"


class LaTexExport : public ExportStrategy
{
public:
    LaTexExport();
    QString header(Note*);
    QString footer(Note*);
    QString exportNote(Document* d , unsigned int titreLvl);
    QString exportNote(Article* a , unsigned int titreLvl);
    QString exportNote(Video* v , unsigned int titreLvl);
    QString exportNote(Audio* a , unsigned int titreLvl);
    QString exportNote(Image* i , unsigned int titreLvl);
};

#endif // TEXEXPORT_H
