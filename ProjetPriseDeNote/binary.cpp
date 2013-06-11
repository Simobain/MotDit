#include "binary.h"


Binary::Binary():Note(), description(""), chemin(""){}

Binary::Binary(const QString& i, const QString& t, const QString& c, const QString& d):Note(i,t), chemin(c), description(d){}

void Binary:: setDescription(const QString& d){
    description=d;
}
void Binary::setChemin(const QString& c){
    chemin=c;
}

void Binary::save(const QString &directory){
    setSaved(true);
    QString cheminEntier=directory+"/"+getId()+".txt";
    QFile fichier (cheminEntier);
    if(fichier.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream flux(&fichier);
        flux<<getTitre()<<"\n"<<getChemin()<<"\n"<<getDescription();
        fichier.close();


    }
    else qDebug()<<"Impossible d'ecrire' !"<<"\n";
    if(!isInTheFile())saveInTheFile(getId(), directory);
}

/*
void Binary::load(const QString& chemin){

    QFile fichier (chemin);
    QString desc;
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream flux(&fichier);
        setTitre(flux.readLine());
        qDebug()<<"titre : "<<getTitre();
        setChemin(flux.readLine());
        qDebug()<<"chemin"<<getChemin();
        while(!flux.atEnd())
                desc += flux.readLine();
        qDebug()<<desc;
        setDescription(desc);
        fichier.close();
    }

    else qDebug()<<"Impossible d'ouvrir le fichier !"<<"\n";

}*/
