#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QTextStream>
#include <QFile>

class ExportStrategy;


class Note { //classe abstraite
    QString id;
protected :
    QString titre;            
    bool modified;
    bool loaded;

public :

    Note();
    Note(const QString& i, const QString& t);
    QString getTitre() const {return titre;} //accesseur titre
    QString getId() const {return id;} //accesseur id (nom du fichier)
    bool modif() const {return modified;} // savoir si la note a été modifié
    void setTitre(const QString& t); // permet de modifier le titre d'une note
    virtual QString ExportNote(ExportStrategy* es);
    virtual QString ExportAsPart(ExportStrategy* es, unsigned int titlelevel);
    void addSubNote(Note* n);
    void removeSubNote(QString i);
    Note* getSubNote(QString id);
    virtual void load(const QString& path)=0;





};




#endif

