#include "imagefactory.h"

ImageFactory::ImageFactory()
{
}
QString ImageFactory::getNewId()
{
    QString ajout="image@";
    return ajout+NoteFactory::getNewId();
}




Note* ImageFactory::buildNote(const QString& id, const QString& titre, const QString &path){
    Image* im=new Image(id, titre, path);
    return im;
}

Note* ImageFactory::buildNewNote(const QString& titre){
    QString id;
    id=getNewId();
    return buildNote(id, titre);
}


Note* ImageFactory::chargerNote(const QString& id, const QString& chemin){
/*
    QFile fichier(chemin+"/"+id+".txt");
    QString contenu;
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QTextStream flux(&fichier);
        QString titre(flux.readLine());
        while(!flux.atEnd()) contenu += flux.readLine()+"\n";
        Note* n= buildNote(id, titre, contenu);
        n->setInTheFile(true);
        return n;
    }
    else {
        qDebug()<<"note pas charger";
        return 0;}*/
    return 0;

}
