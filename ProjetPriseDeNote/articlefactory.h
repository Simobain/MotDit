#ifndef ARTICLEFACTORY_H
#define ARTICLEFACTORY_H
#include "notefactory.h"

class ArticleFactory : public NoteFactory
{
public:
    ArticleFactory();
    QString getNewId();
    Note* buildNote(QString& id,QString& title);
    Note* buildNewNote(QString& title);
    Note* buildNotecopy(const Note* n);
};

#endif // ARTICLEFACTORY_H
