#include "htmlexport.h"




HTMLexport::HTMLexport() : ExportStrategy()
{
}

QString HTMLexport::header(Note* n)

{
    return "<!DOCTYPE html><html><head><meta charset=\"utf-8\" /><title>"+ n->getTitre()+"</title></head><body>";
}

QString HTMLexport::footer(Note*)
{
    return "</body></html>";
}
QString HTMLexport::exportNote(Document* d , unsigned int titreLvl)
{
    if (titreLvl>6) titreLvl;
    QString s="<h"+QString::number(titreLvl)+">"+d->getTitre()+"</h"+QString::number(titreLvl)+">\n";
    QSet<Note*>::iterator it= d->getSousNotes().begin();
    for(it;it!=d->getSousNotes().end();it++)
    {
        //Note* n=(typeid(*it).name) *it;
        //s+=exportNote((*it),titreLvl-1); TODO : probleme exportNote n'existe pas pour une note*
    }

    return s;

    //else throw NotesException("Taille du titre trop élevée");*/
    //return"";
}
QString HTMLexport::exportNote(Article* a , unsigned int titreLvl)
{
    QString texte="<h"+QString::number(titreLvl)+">"+a->getTitre()+"</h"+QString::number(titreLvl)+">\n"+"<p>"+a->getTexte()+"</p>";
    return texte;

}
QString HTMLexport::exportNote(Video* v , unsigned int titreLvl){return"";}
QString HTMLexport::exportNote(Audio* a , unsigned int titreLvl){return"";}
QString HTMLexport::exportNote(Image* i , unsigned int titreLvl){return"";}
