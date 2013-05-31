#include "htmlexport.h"
#include<QSet>
#include"notesexception.h"

HTMLexport::HTMLexport()
{
}

QString HTMLexport::header(Note* n)
{
    return "<!DOCTYPE html><html><head><meta charset=\"utf-8\" /><link rel=\"stylesheet\" href=\"Test.css\"/><title>"+ n->getTitre()+"</title></head><body>";
}
QString HTMLexport::footer(Note* n)
{

    return "</body></html>";
}
QString HTMLexport::exportNote(Document* d , unsigned int titreLvl)
{
    if (titreLvl<=6){
    QString s="<h"+titreLvl+">"+d->getTitre()+"</h"+titreLvl+">\n";
    typedef const_iterator it=d->ensNotes.constBegin();
    for(it;it!=d->ensNotes.constEnd();it++)
    {
        s+=exportNote(*it,titreLvl-1);
    }
    return s;
    }
    else throw NotesException("Taille du titre trop élevée");
}
QString HTMLexport::exportNote(Article* a , unsigned int titreLvl)
{
    return "<h"+titreLvl+">"+a->getTitre()+"</h"+titreLvl+">\n"+"<p>"+a->getTexte()+"</p>";
}
QString HTMLexport::exportNote(Video* v , unsigned int titreLvl){}
QString HTMLexport::exportNote(Audio* a , unsigned int titreLvl){}
QString HTMLexport::exportNote(Image* i , unsigned int titreLvl){}
