#include "articlefactory.h"


ArticleFactory::ArticleFactory()
{
}

QString getNewId()
{
    QString ajout="article";
    return s=ajout+NoteFactory::getNewId();
}
