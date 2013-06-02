#include "latexexport.h"

LaTexExport::LaTexExport()
{
}
QString LaTexExport::header(Note* n)
{
    return"";
}

QString LaTexExport::footer(Note* n)
{

    return "";
}
QString LaTexExport::exportNote(Document* d , unsigned int titreLvl)
{
    return"";
}
QString LaTexExport::exportNote(Article* a , unsigned int titreLvl)
{

    return"";
}
QString LaTexExport::exportNote(Video* v , unsigned int titreLvl){return"";}
QString LaTexExport::exportNote(Audio* a , unsigned int titreLvl){return"";}
QString LaTexExport::exportNote(Image* i , unsigned int titreLvl){return"";}
