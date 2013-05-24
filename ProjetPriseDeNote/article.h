#ifndef ARTICLE_H
#define ARTICLE_H
#include <QString>
#include "note.h"


class Article : public Note {
    QString texte;
    QString genererId();

public:
    Article();
    QString getTexte() const {return texte;}
    void setTexte(const QString& t);


};


#endif // ARTICLE_H
