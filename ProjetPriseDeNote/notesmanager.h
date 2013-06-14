#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H
#include <iostream>
#include <map> //Bug si on remplace toutes les map par des QMap (au niveau de l'iterateur qui doit pas être exactement le même

#include <QMessageBox>
#include <QApplication>
#include <QSettings>
#include <QDebug>

#include "articlefactory.h"
#include "videofactory.h"
#include "documentfactory.h"
#include "imagefactory.h"
#include "audiofactory.h"

#include "htmlexport.h"
#include "latexexport.h"
#include "textexport.h"

class NotesManager {

    std::map < QString,NoteFactory* > factories;
    std::map < QString,ExportStrategy* > strategies;
    QSet<Note*> ensnotes;
    QString EspaceDeTravail;
    static NotesManager* instance;


    NotesManager();
    ~NotesManager();
    //NotesManager(const NoteManager&);
    NotesManager& operator=(const NotesManager&);



public:

    static NotesManager* getInstance();
    void libereInstance();
    void creerNote(const QString& type_note, const QString& titre,const QString& path="");
    void supprNote (Note* n);
    Note* getNoteFromTitre(const QString& titre);
    void setEspaceDeTravail(const QString& e);
    QString getEspaceDeTravail()const {return EspaceDeTravail;}
    void chargerNotes();
    const QSet<Note *>& getEnsnote()const;
    QString exportNote(Note* n, QString typeExport);
    QString exportNoteAsPart(Note* n, QString typeExport);
    Note * getNoteFromId(const QString& id);

};


#endif // NOTESMANAGER_H
