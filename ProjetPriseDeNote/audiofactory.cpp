#include "audiofactory.h"

AudioFactory::AudioFactory()
{
}
QString AudioFactory::getNewId()
{
    QString ajout="audio@";
    return ajout+NoteFactory::getNewId();
}


Note* AudioFactory::buildNote(const QString& id, const QString& titre, const QString &path, const QString &desc){
    Audio* a=new Audio(id, titre,path, desc);
    return a;
}

Note* AudioFactory::buildNewNote(const QString& titre, const QString& path){
    QString id;
    id=getNewId();
    return buildNote(id, titre, path);
}


Note* AudioFactory::chargerNote(const QString& id, const QString& chemin){

    QFile fichier(chemin+"/"+id+".txt");
    QString desc;
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
    QTextStream flux(&fichier);
    QString titre(flux.readLine());
    QString path(flux.readLine());
    while(!flux.atEnd()) desc += flux.readLine()+"\n";
    Note* n= buildNote(id, titre, path,desc);

    n->setInTheFile(true);
    return n;
    }
    else {
        qDebug()<<"note pas charger";
        return 0;}
}
