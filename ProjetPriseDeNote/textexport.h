#ifndef TEXTEXPORT_H
#define TEXTEXPORT_H
#include "exportstrategy.h"

class TextExport : public ExportStrategy
{
public:
    TextExport();
    QString header(Note*);
    QString footer(Note*);
    QString exportNote(Document* d , unsigned int titreLvl);
    QString exportNote(Article* a , unsigned int titreLvl);
    QString exportNote(Video* v , unsigned int titreLvl);
    QString exportNote(Audio* a , unsigned int titreLvl);
    QString exportNote(Image* i , unsigned int titreLvl);
};

#endif // TEXTEXPORT_H
