#include "article.h"
#include "notefactory.h"

Article::Article():Note(), texte(""){}

void Article::setTexte(const QString& t){
    texte=t;
}
