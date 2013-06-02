#include "textexport.h"

TextExport::TextExport()
{
}
QString TextExport::header(Note* n)
{
    return"";
}

QString TextExport::footer(Note* n)
{

    return "";
}
QString TextExport::exportNote(Document* d , unsigned int titreLvl)
{
    return"";
}
QString TextExport::exportNote(Article* a , unsigned int titreLvl)
{

    return"";
}
QString TextExport::exportNote(Video* v , unsigned int titreLvl){return"";}
QString TextExport::exportNote(Audio* a , unsigned int titreLvl){return"";}
QString TextExport::exportNote(Image* i , unsigned int titreLvl){return"";}
