#include "article.h"
#include "notefactory.h"
#include <iostream>
#include "exportstrategy.h"


Article::Article():Note(), texte(""){}

Article::Article(const QString& id, const QString& titre) : Note(id, titre),texte(""){}

Note::NoteType Article::getType() const{
    return ARTICLE;
}


void Article::setTexte(const QString& t){
    texte=t;
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

void Article::save(const QString &nomFichier){//je pense qu'il faut le sauver selon son id

    QFile fichier (nomFichier);//getId().txt
    if(fichier.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream flux(&fichier);
        flux<<getTitre()<<"\n"<<getTexte();
        fichier.close();
        QSettings descrip("BinomeLO21","ProjetPriseDeNotes");// création d'un fichier de description
        QString chem="Notes/Articles/";
        descrip.setValue(chem+getTitre(),getId());


    }
    else std::cout<<"Impossible d'ecrire' !"<<"\n";
}

