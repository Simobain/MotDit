#include "articlefactory.h"


ArticleFactory::ArticleFactory()
{
}

QString ArticleFactory::getNewId()
{
    QString ajout="article";
    return ajout+NoteFactory::getNewId();
}
