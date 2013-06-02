#include "htmlexport.h"
#include<QSet>
#include"notesexception.h"

HTMLexport::HTMLexport() : ExportStrategy()
{
}

QString HTMLexport::header(Note* n)

{/*
    return "<!DOCTYPE html><html><head><meta charset=\"utf-8\" /><title>"+ n->getTitre()+"</title></head><body>";
    */
    return"";
}

QString HTMLexport::footer(Note* n)
{

    return "</body></html>";
}
QString HTMLexport::exportNote(Document* d , unsigned int titreLvl)
{
   /* if (titreLvl<=6){
    QString s="<h"+QString::number(titreLvl)+">"+d->getTitre()+"</h"+QString::number(titreLvl)+">\n";

    for(QSet<Note*>::iterator it=d->begin();it!=d->constEnd();it++)
    {
        s+=exportNote(*it,titreLvl-1);
    }
    return s;
    }
    else throw NotesException("Taille du titre trop élevée");*/
    return"";
}
QString HTMLexport::exportNote(Article* a , unsigned int titreLvl)
{
    /*
    return "<h"+titreLvl+">"+a->getTitre()+"</h"+titreLvl+">\n"+"<p>"+a->getTexte()+"</p>";
    */
    return"";
}
QString HTMLexport::exportNote(Video* v , unsigned int titreLvl){return"";}
QString HTMLexport::exportNote(Audio* a , unsigned int titreLvl){return"";}
QString HTMLexport::exportNote(Image* i , unsigned int titreLvl){return"";}
