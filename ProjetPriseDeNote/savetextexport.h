/*#ifndef SAVETEXTEXPORT_H
#define SAVETEXTEXPORT_H

#include "exportstrategy.h"

class SaveTextExport : public ExportStrategy
{
public:
    SaveTextExport();
    QString header(Note*);
    QString footer(Note*);
    QString exportNote(Document* d , unsigned int titreLvl);
    QString exportNote(Article* a , unsigned int titreLvl);
    QString exportNote(Video* v , unsigned int titreLvl);
    QString exportNote(Audio* a , unsigned int titreLvl);
    QString exportNote(Image* i , unsigned int titreLvl);
};

#endif // SAVETEXTEXPORT_H
*/
