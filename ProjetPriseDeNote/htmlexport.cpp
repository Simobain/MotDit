#include "htmlexport.h"
#include "notesmanager.h"




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
    QString texte="<h"+QString::number(titreLvl)+">"+d->getTitre()+"</h"+QString::number(titreLvl)+">\n";
    QSet<Note*>::const_iterator it= d->getSousNotes().cbegin();
    for(it;it!=d->getSousNotes().cend();it++)
    {
        if (titreLvl>5) titreLvl=5;
        NotesManager* nm=NotesManager::getInstance();
        texte+=nm->exportNoteAsPart((*it),"html",titreLvl+1);
    }
    return texte;



}
QString HTMLexport::exportNote(Article* a , unsigned int titreLvl)
{
    QString texte="<h"+QString::number(titreLvl)+">"+a->getTitre()+"</h"+QString::number(titreLvl)+">\n"+"<p>"+a->getTexte()+"</p>";
    return texte;

}
QString HTMLexport::exportNote(Video* v , unsigned int titreLvl)
{
    qDebug()<<"chemin=*********************"<<v->getChemin();
   QString texte="<h"+QString::number(titreLvl)+">"+v->getTitre()+"</h"+QString::number(titreLvl)+">";
   texte+="<p><video width=\"640\" height=\"480\" controls>\n";
   texte+="<source src=\"file:///"+v->getChemin()+"\" type=\"video/mp4\">\n";
   texte+="<source src=\"file:///"+v->getChemin()+"\" type=\"video/avi\">\n";
   texte+="<source src=\"file:///"+v->getChemin()+"\" type=\"video/mov\">\n";
   texte+="Le logiciel MotDit ne gere pas ce format, en revanche vous pouvez l'exporter pour que ça fonctionne.</video></p>\n";
   return texte;
}
QString HTMLexport::exportNote(Audio* a , unsigned int titreLvl)
{
    QString texte="<h"+QString::number(titreLvl)+">"+a->getTitre()+"</h"+QString::number(titreLvl)+">\n";
    texte+="<audio controls><source src=\""+a->getChemin()+"\"></source>\n";
    texte+="<p>Le logiciel MotDit ne gere pas ce format, en revanche vous pouvez l'exporter pour que ça fonctionne.</p>\n";
    texte+="</audio><p>"+a->getDescription()+"</p>";
    return texte;
}
QString HTMLexport::exportNote(Image* i , unsigned int titreLvl){
    QString texte="<h"+QString::number(titreLvl)+">"+i->getTitre()+"</h"+QString::number(titreLvl)+">\n"+"<p>\n";
    texte+="<img src=\""+i->getChemin()+"\" border=\"0\" align=\"center\"></img>\n</p>";
    texte+="<p>\n"+i->getDescription()+"\n</p>\n";

    return texte;}
