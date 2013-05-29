#ifndef HTMLEXPORT_H
#define HTMLEXPORT_H

#include "exportstrategy.h"

class HTMLexport : public ExportStrategy
{
public:
    HTMLexport();
    QString header(Note*);
    QString footer(Note*);
    QString exportNote(Document* d , unsigned int titreLvl);
    QString exportNote(Article* a , unsigned int titreLvl);
    QString exportNote(Video* v , unsigned int titreLvl);
    QString exportNote(Audio* a , unsigned int titreLvl);
    QString exportNote(Image* i , unsigned int titreLvl);
};

#endif // HTMLEXPORT_H
