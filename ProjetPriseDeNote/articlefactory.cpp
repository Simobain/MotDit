#include "articlefactory.h"


ArticleFactory::ArticleFactory()
{
}

QString ArticleFactory::getNewId()
{
    QString ajout="article";
    return ajout+NoteFactory::getNewId();
}

Note* ArticleFactory::buildNote(const QString& id, const QString& titre){
    Article* art=new Article(id, titre);
    return art;
}

Note* ArticleFactory::buildNewNote(const QString& titre){
    QString id;
    id=getNewId();
    return buildNote(id, titre);
}
