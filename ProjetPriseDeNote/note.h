#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <QTextStream>
#include <QFile>
#include <QDebug>

class ExportStrategy;

/*!
 * \file note.h
 * \brief Classe de base permettant de définir toutes les notes
 * \author Pauline Cuche/Simon Robain
 */

class Note { //classe abstraite
    QString id;
protected :
    QString titre;            
    bool modified;
    bool saved;
    bool inTheFile;

public :
    enum NoteType{ARTICLE, DOCUMENT, AUDIO, IMAGE, VIDEO};

    Note();
    Note(const QString& i, const QString& t);
    QString getTitre() const {return titre;} //accesseur titre
    QString getId() const {return id;} //accesseur id (nom du fichier)
    bool modif() const {return modified;} // savoir si la note a été modifié
    bool isInTheFile()const {return inTheFile;}
    void setInTheFile(bool b){inTheFile=b;}
    void saveInTheFile(const QString& id, const QString& chemin);
    void setTitre(const QString& t); // permet de modifier le titre d'une note
    //virtual QString ExportNote(ExportStrategy* es)=0;
    //virtual QString ExportAsPart(ExportStrategy* es, unsigned int titlelevel)=0;
    virtual NoteType getType()const=0;
    bool isSaved(){return saved;}
    void setSaved(bool ok){saved=ok;}
    virtual void save(const QString& directory)=0;
    //virtual void load(const QString& path)=0;

};

#endif

