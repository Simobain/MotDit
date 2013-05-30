#include "notesmanager.h"
#include <QMessageBox>

NotesManager* NotesManager::instance=0;

NotesManager::NotesManager()
{
    factories["article"]=new ArticleFactory;
   /* factories["document"]= new DocumentFactory;
    factories["image"]= new ImageFactory;
    factories["video"]=new VideoFactory;
    factories["audio"]=new AudioFactory;*/

}

NotesManager::~NotesManager(){
    std::map<QString, NoteFactory*> ::iterator it=factories.begin();
    for (;it!=factories.end();++it){
        delete it->second;
    }
    // todo supprimer le set de note
}

NotesManager* NotesManager::getInstance(){
    if (!instance) instance=new NotesManager;
    return instance;
}

void NotesManager::libereInstance(){
    if(instance) delete instance;
    instance=0;
}

void NotesManager::creerNote(const QString& type_note, const QString& titre){
    NoteFactory* factory;
    factory=factories[type_note];
    Note* newNote=factory->buildNewNote(titre);
    ensnotes<<newNote;

}
