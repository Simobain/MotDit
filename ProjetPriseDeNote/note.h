#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QTextStream>
#include"exportstrategy.h"

class Note { //classe abstraite
    QString id;
protected :
    QString titre;            
    bool modified;
    bool loaded;

public :
    Note(QString id,const string& titre);
    QString getTitre() const {return titre;} //accesseur titre
    virtual QString getId() const {return id;} //accesseur id (nom du fichier)
    bool modif() const {return modifier;} // savoir si la note a été modifié
    void setTitre(const QString& t); // permet de modifier le titre d'une note
    QString ExportNote(ExportStrategy* es);
    QString ExportAsPart(ExportStrategy* es, unsigned int titlelevel);
    void addSubNote(Note* n);
    void removeSubNote(QString i);
    Note* getSubNote(QString id);
    load(const QString& path);





};




#endif

