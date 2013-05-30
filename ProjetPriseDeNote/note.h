#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QTextStream>
//#include"exportstrategy.h"
#include <QFile>

class Note { //classe abstraite
    QString id;
protected :
    QString titre;            
    bool modified;
    bool loaded;

public :

    Note();
    QString getTitre() const {return titre;} //accesseur titre
    virtual QString getId() const {return id;} //accesseur id (nom du fichier)
    bool modif() const {return modified;} // savoir si la note a été modifié
    void setTitre(const QString& t); // permet de modifier le titre d'une note
   // virtual QString ExportNote(ExportStrategy* es);
    //virtual QString ExportAsPart(ExportStrategy* es, unsigned int titlelevel);
    void addSubNote(Note* n);
    void removeSubNote(QString i);
    Note* getSubNote(QString id);
    virtual void load(const QString& path)=0;





};




#endif

