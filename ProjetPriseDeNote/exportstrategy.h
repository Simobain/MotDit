#ifndef EXPORTSTRATEGY_H
#define EXPORTSTRATEGY_H

#include <QString>
#include "note.h"

class ExportStrategy
{
public:
    ExportStrategy();
    virtual QString header(Note *n);
    virtual QString footer(Note *n);
    virtual QString exportNote(Note *n , unsigned int titreLvl);
    //static map<QString, ExportStrategy*> getExportStrategy();

};

#endif // EXPORTSTRATEGY_H
