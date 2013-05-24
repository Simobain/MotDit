#ifndef EXPORTSTRATEGY_H
#define EXPORTSTRATEGY_H

#include <QString>
#include "notes.h"

class ExportStrategy
{
public:
    ExportStrategy();
    QString header(Note*);
    QString footer(Note*);
    QString exportNote(Note* n , unsigned int titreLvl);
    static map<QString, ExportStrategy*> getExportStrategy();

};

#endif // EXPORTSTRATEGY_H
