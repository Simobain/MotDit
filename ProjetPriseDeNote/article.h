#ifndef ARTICLE_H
#define ARTICLE_H
#include <QString>
#include "note.h"


class Article : public Note {
    QString texte;
    Article(const Article& a);
    Article& operator=(const Article& a);
    void load();

public:
    Article();
    QString getTexte() const {return texte;}
    void setTexte(const QString& t);


};


#endif // ARTICLE_H
