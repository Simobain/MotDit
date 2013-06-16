#include "latexexport.h"
#include "notesmanager.h"

LaTexExport::LaTexExport() : ExportStrategy()
{
}
QString LaTexExport::header(Note* n)
{
    QString head="\\documentclass[a4paper,11pt]{report}\n";
            head+="\\usepackage{graphicx} \n";
            head+="\\usepackage[french]{babel} \n";
            head+="\\usepackage[latin1]{inputenc}\n";
            head+="\\usepackage[T1]{fontenc}\n";
            head+="\\begin{document}\n";

    return head;
}

QString LaTexExport::footer(Note* n)
{
    return "\\end{document}";
}
QString LaTexExport::exportNote(Document* d , unsigned int titreLvl)
{

    QString level="";

    if (titreLvl<1) titreLvl=1;
    if (titreLvl==1) level="chapter";
    else {
        titreLvl-=2;
        while(titreLvl!=0) level+="sub";
        level+="section";
    }
    QString texte="\\"+level+"{"+d->getTitre()+"}\n";
    QSet<Note*>::const_iterator it= d->getSousNotes().cbegin();
    NotesManager* nm=NotesManager::getInstance();
    for(it;it!=d->getSousNotes().cend();it++)
    {
        texte+=nm->exportNoteAsPart((*it),"latex",titreLvl+1);
    }
    return texte;

}
QString LaTexExport::exportNote(Article* a , unsigned int titreLvl)
{
    QString level="";

    if (titreLvl<1) titreLvl=1;
    if (titreLvl==1) level="chapter";
    else {
        titreLvl-=2;
        while(titreLvl!=0) level+="sub";
        level+="section";
    }
    QString texte="\\"+level+"{"+a->getTitre()+"}\n";
    texte+=a->getTexte()+"\n";

    return texte;
}
QString LaTexExport::exportNote(Video* v , unsigned int titreLvl){
    QString level="";

    if (titreLvl<1) titreLvl=1;
    if (titreLvl==1) level="chapter";
    else {
        titreLvl-=2;
        while(titreLvl!=0) level+="sub";
        level+="section";
    }
    QString texte="\\"+level+"{"+v->getTitre()+"}\n";
    texte+="Emplacement de la video : \\newline"+v->getChemin()+"\n";
    texte+="\\newline \n \\newline \n"+v->getDescription()+"\n";
    return texte;
}
QString LaTexExport::exportNote(Audio* a , unsigned int titreLvl){
    QString level="";

    if (titreLvl<1) titreLvl=1;
    if (titreLvl==1) level="chapter";
    else {
        titreLvl-=2;
        while(titreLvl!=0) level+="sub";
        level+="section";
    }
    QString texte="\\"+level+"{"+a->getTitre()+"}\n";
    texte+="Emplacement du fichier audio : \\newline"+a->getChemin()+"\n";
    texte+="\\newline \n \\newline \n"+a->getDescription()+"\n";
    return texte;}
QString LaTexExport::exportNote(Image* i , unsigned int titreLvl){

    QString level="";

    if (titreLvl<1) titreLvl=1;
    if (titreLvl==1) level="chapter";
    else {
        titreLvl-=2;
        while(titreLvl!=0) level+="sub";
        level+="section";
    }
    QString texte="\\"+level+"{"+i->getTitre()+"}\n";
    texte+="\\begin{center}\n \\includegraphics{"+i->getChemin()+"}\n";
    texte+="\\end{center}\n";

    texte+="\\newline \n \\newline \n"+i->getDescription()+"\n";
    return texte;}
