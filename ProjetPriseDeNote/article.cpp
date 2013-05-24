#include "article.h"

Aticle::Article():Note(), texte(""){}

void Article::setTexte(const QString& t){
    texte=t;
}
