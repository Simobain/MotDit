#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QTextStream>

class Note { //classe abstraite
    QString titre;
    QString id;
  //  bool modifier;

public :
    Note();
    QString getTitre() const {return titre;} //accesseur titre
    virtual QString getId() const {return id;} //accesseur id (nom du fichier)
   // bool modif() const {return modifier;} // savoir si la note a été modifié
    void setTitre(const QString& t); // permet de modifier le titre d'une note
    virtual QString genererId() const=0;




};




#endif

