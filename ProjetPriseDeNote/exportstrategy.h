#ifndef EXPORTSTRATEGY_H
#define EXPORTSTRATEGY_H

#include <QString>
#include "document.h"
#include "image.h"
#include "video.h"
#include "audio.h"
#include "article.h"
#include "note.h"


class ExportStrategy
{
public:
    ExportStrategy();
    /*virtual QString header(Note *n)=0;
    virtual QString footer(Note *n)=0;
    virtual QString exportNote(Note *n , unsigned int titreLvl)=0;
    //static map<QString, ExportStrategy*> getExportStrategy();
    */
};

#endif // EXPORTSTRATEGY_H
