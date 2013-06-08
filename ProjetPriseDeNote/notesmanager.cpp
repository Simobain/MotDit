#include "notesmanager.h"


NotesManager* NotesManager::instance=0;

NotesManager::NotesManager() : EspaceDeTravail(qApp->applicationDirPath())//A modifier plus tard mais suffit pour le moment
{
    factories["article"]=new ArticleFactory;
   /* factories["document"]= new DocumentFactory;
    factories["image"]= new ImageFactory;
    factories["video"]=new VideoFactory;
    factories["audio"]=new AudioFactory;*/
    strategies["html"]=new HTMLexport;
    strategies["latex"]=new LaTexExport;
    strategies["texte"]=new TextExport;
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

const QSet<Note*>& NotesManager::getEnsnote()const{
    return ensnotes;
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
    else {qDebug()<<"l'article n'est pas dans la liste !"; return 0;};// TODO : traiter le cas ou il y a un pb

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

void NotesManager::supprNote (Note* n){
    QString cheminEntier=EspaceDeTravail+"/"+"fileDescript.txt";
    QString buffer = ""; //Variable contenant le texte à réécrire dans le fichier
    QFile fichier (cheminEntier);
    if(fichier.open(QIODevice::ReadOnly |QIODevice::Text))
    {
        QString texte;
        QTextStream flux(&fichier);

        while(!flux.atEnd()){
            texte = flux.readLine();
            if (n->getId()!=texte) buffer+=texte+"\n"; //si ce n'est pas l'id a supprimer on le met dans le buffer
        }
        fichier.close();
    }
    else std::cout<<"Impossible de lire le fichier !"<<"\n";

    //on ouvre le fichier et on réecrit le buffer à la place
    if (fichier.open(QIODevice::WriteOnly | QIODevice::Truncate|QIODevice::Text)){
        QTextStream flux(&fichier);
        flux<<buffer;
        fichier.close();
    }
    else std::cout<<"impossible d'ecrire ds le fichier"<<"\n";

    ensnotes.remove(n);

    //to do mettre n dans la corbeille
}


QString NotesManager::exportNote(Note* n, QString typeExport){

    ExportStrategy* strategy;
    strategy=strategies[typeExport];
    QString texte=strategy->header(n);
    switch(n->getType()){
    case Note::ARTICLE :
        texte+=strategy->exportNote((Article*) n,1);

        break;
    default :
        qDebug()<<"pb fonction NoteManager::exportNote je suis le default du switch \n ";
    }

    texte+=strategy->footer(n);
    return texte;
}
