#include "imagefactory.h"

ImageFactory::ImageFactory()
{
}
QString ImageFactory::getNewId()
{
    QString ajout="image@";
    return ajout+NoteFactory::getNewId();
}

Note* ImageFactory::buildNote(const QString& id, const QString& titre, const QString &path, const QString& desc){
    Image* im=new Image(id, titre, path, desc);
    return im;
}

Note* ImageFactory::buildNewNote(const QString& titre, const QString& path){
    QString id;
    id=getNewId();
    return buildNote(id, titre, path);
}


Note* ImageFactory::chargerNote(const QString& id, const QString& chemin){

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
