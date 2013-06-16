#include "textexport.h"
#include "NotesManager.h"

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
{   QString text=d->getTitre();
    text+="\n==============================\n\n";
    QSet<Note*>::const_iterator it= d->getSousNotes().cbegin();
    NotesManager* nm=NotesManager::getInstance();
    for(it;it!=d->getSousNotes().cend();it++)
    {
        text+=nm->exportNoteAsPart((*it),"texte",1);
    }

    return text;
}
QString TextExport::exportNote(Article* a , unsigned int titreLvl)
{
    QString text=a->getTitre();
    text+="\n==============================";
    text+="\n\n\n";
    text+=a->getTexte()+"\n\n";
    return text;
}
QString TextExport::exportNote(Video* v , unsigned int titreLvl){
    QString text=v->getTitre();
    text+="\n==============================";
    text+="\n\n\n";
    text+=v->getChemin();
    text+="\n"+v->getDescription()+"\n\n";
    return text;
}
QString TextExport::exportNote(Audio* a , unsigned int titreLvl){
    QString text=a->getTitre();
    text+="\n==============================";
    text+="\n\n\n";
    text+=a->getChemin();
    text+="\n"+a->getDescription()+"\n\n";
    return text;
}
QString TextExport::exportNote(Image* i , unsigned int titreLvl){
    QString text=i->getTitre();
    text+="\n==============================";
    text+="\n\n\n";
    text+=i->getChemin();
    text+="\n"+i->getDescription()+"\n\n";
    return text;
}
