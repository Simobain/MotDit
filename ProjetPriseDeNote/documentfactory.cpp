#include "documentfactory.h"

DocumentFactory::DocumentFactory()
{
}
QString DocumentFactory::getNewId()
{
    QString ajout="document@";
    return ajout+NoteFactory::getNewId();
}



Note* DocumentFactory::buildNote(const QString& id,const QString& titre, const QString& contenu, const QString& desc){
    Document* doc=new Document(id, titre);
    return doc;
}

Note* DocumentFactory::buildNewNote(const QString& titre, const QString& path){
    QString id;
    id=getNewId();
    return buildNote(id, titre);
}

Note* DocumentFactory::chargerNote(const QString& id, const QString& chemin){

    QFile fichier(chemin+"/"+id+".txt");
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QTextStream flux(&fichier);
        QString titre(flux.readLine());
        Note* n= buildNote(id, titre);
        Document* doc=(Document*)n;
        while(!flux.atEnd()){
            NotesManager* nm=NotesManager::getInstance();;
            Note* ssNote=nm->getNoteFromId(flux.readLine());
            doc->addSubNote(ssNote);
        }

        doc->setInTheFile(true);
        return n;
    }
    else {
        qDebug()<<"note pas charger";
        return 0;}

}
