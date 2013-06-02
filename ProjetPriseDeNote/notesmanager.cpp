#include "notesmanager.h"
#include <QMessageBox>
#include <QApplication>
#include <QSettings>

NotesManager* NotesManager::instance=0;

NotesManager::NotesManager() : EspaceDeTravail(qApp->applicationDirPath())//A modifier plus tard mais suffit pour le moment
{
    factories["article"]=new ArticleFactory;
   /* factories["document"]= new DocumentFactory;
    factories["image"]= new ImageFactory;
    factories["video"]=new VideoFactory;
    factories["audio"]=new AudioFactory;*/
   // strategies["HTML"]=new HTMLexport;
    /*strategies["LaTex"]=new LaTexExport;
    strategies["Texte"]=new TextExport;*/
    chargerNotes();


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

Note* NotesManager::getNoteFromTitre(const QString& titre){
    QSet<Note*>::iterator it= ensnotes.begin();
    while ((*it)->getTitre()!=titre && it!=ensnotes.end()){
        it++;
    }
    if ((*it)->getTitre()==titre)
    return (*it);
    else return 0;// TODO : traiter le cas ou il y a un pb

}
void NotesManager::setEspaceDeTravail(const QString& e)
{
    EspaceDeTravail=e;
}

void NotesManager::chargerNotes(){
    QString cheminEntier=EspaceDeTravail+"/"+"fileDescript.txt";
    QFile fichier (cheminEntier);
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString texte;
        QTextStream flux(&fichier);
        QString delimiter="@";
        NoteFactory* factory;
        while(!flux.atEnd()){
            texte = flux.readLine();
            QStringList typID= texte.split(delimiter);
            factory=factories[typID[0]];
            Note* newNote=factory->chargerNote(texte, EspaceDeTravail);
            ensnotes<<newNote;

        }

        fichier.close();


    }
    else std::cout<<"Impossible d'ecrire' !"<<"\n";
}
