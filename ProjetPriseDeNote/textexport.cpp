#include "textexport.h"

TextExport::TextExport(): ExportStrategy()
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
{  /* QString text=d->getTitre();
    text+="\n==============================";*/
    return "";
}
QString TextExport::exportNote(Article* a , unsigned int titreLvl)
{
    QString text=a->getTitre();
    text+="\n==============================";
    text+="\n\n\n";
    text+=a->getTexte();
    return text;
}
QString TextExport::exportNote(Video* v , unsigned int titreLvl){return"";}
QString TextExport::exportNote(Audio* a , unsigned int titreLvl){return"";}
QString TextExport::exportNote(Image* i , unsigned int titreLvl){return"";}
