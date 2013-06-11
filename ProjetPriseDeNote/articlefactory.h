#ifndef ARTICLEFACTORY_H
#define ARTICLEFACTORY_H
#include "notefactory.h"
#include "article.h"


class ArticleFactory : public NoteFactory
{
public:
    ArticleFactory();
    QString getNewId();//Renvoie un id unique précédé du type de Note ici Article
    Note* buildNote(const QString& id, const QString& titre, const QString &texte="", const QString& desc="");
    Note* buildNewNote(const QString &titre, const QString& path="");
    Note* buildNotecopy(const Note* n);
    Note* chargerNote(const QString& id, const QString& chemin);
};

#endif // ARTICLEFACTORY_H
