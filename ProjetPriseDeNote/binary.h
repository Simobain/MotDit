#ifndef BINARY_H
#define BINARY_H
#include"note.h"


class Binary : public Note
{
    QString description;
    QString chemin; //chemin d'accès au fichier binaire
    void load();

public:
    Binary();
    QString getDescription() const {return description;}
    QString getChemin() const {return chemin;}
    void setDescription(const QString& d);
    void setChemin(const QString& c);
};

#endif // BINARY_H
