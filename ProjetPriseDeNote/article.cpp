#include "article.h"
#include <iostream>



Article::Article():Note(), texte(""){}

Article::Article(const QString& id, const QString& titre, const QString& text) : Note(id, titre),texte(text){}


Note::NoteType Article::getType() const{
    return ARTICLE;
}


void Article::setTexte(const QString& t){
    texte=t;
    //saved=false;
}
void Article::load(const QString &chemin){

    QFile fichier (chemin);
    QString contenu;
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        QTextStream flux(&fichier);
        setTitre(flux.readLine());
        while(!flux.atEnd())
                contenu += flux.readLine();
        setTexte(contenu);
        fichier.close();
    }

    else std::cout<<"Impossible d'ouvrir le fichier !"<<"\n";

}

void Article::save(const QString &directory){
    setSaved(true);
    QString cheminEntier=directory+"/"+getId()+".txt";
    QFile fichier (cheminEntier);
    if(fichier.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream flux(&fichier);
        flux<<getTitre()<<"\n"<<getTexte();
        fichier.close();


    }
    else std::cout<<"Impossible d'ecrire' !"<<"\n";
    if(!isInTheFile())saveInTheFile(getId(), directory);
    //saved=true;
}


