#include "articlefactory.h"


ArticleFactory::ArticleFactory()
{
}

QString ArticleFactory::getNewId()
{
    QString ajout="article@";
    return ajout+NoteFactory::getNewId();
}

Note* ArticleFactory::buildNote(const QString& id, const QString& titre, const QString& texte, const QString &desc){
    Article* art=new Article(id, titre, texte);
    return art;
}

Note* ArticleFactory::buildNewNote(const QString& titre, const QString &path){
    QString id;
    id=getNewId();
    return buildNote(id, titre);
}

Note* ArticleFactory::chargerNote(const QString& id, const QString& chemin){

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
        return 0;}

}
