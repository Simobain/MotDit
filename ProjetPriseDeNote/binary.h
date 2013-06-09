#ifndef BINARY_H
#define BINARY_H
#include"note.h"


class Binary : public Note //classe abstraite
{
    QString chemin;//chemin d'accès au fichier binaire
    QString description;
    Binary(const Binary& b);
    Binary& operator=(const Binary& b);

public:
    Binary();
    Binary(const QString& i, const QString& t, const QString& c, const QString& d="");
    QString getDescription() const {return description;}
    QString getChemin() const {return chemin;}
    void setDescription(const QString& d);
    void setChemin(const QString& c);
    void load(const QString& chemin);
    void save(const QString& directory);
};

#endif // BINARY_H
