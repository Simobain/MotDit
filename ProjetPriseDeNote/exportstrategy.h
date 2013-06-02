#ifndef EXPORTSTRATEGY_H
#define EXPORTSTRATEGY_H

#include <QString>
#include "document.h"
#include "image.h"
#include "video.h"
#include "audio.h"
#include "article.h"
#include "note.h"
#include "QMap"


class ExportStrategy
{
public:
    ExportStrategy();
    virtual QString header(Note *n)=0;
    virtual QString footer(Note *n)=0;
    //virtual QString exportNote(Note* n, unsigned int titreLvl);
    virtual QString exportNote(Document* d , unsigned int titreLvl)=0;
    virtual QString exportNote(Article* a , unsigned int titreLvl)=0;
    virtual QString exportNote(Video* v , unsigned int titreLvl)=0;
    virtual QString exportNote(Audio* a , unsigned int titreLvl)=0;
    virtual QString exportNote(Image* i , unsigned int titreLvl)=0;

    //static QMap<QString, ExportStrategy*> getExportStrategy();
};

#endif // EXPORTSTRATEGY_H
