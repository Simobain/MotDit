#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H
#include <iostream>
#include <QString>
#include "articlefactory.h"
#include "videofactory.h"
#include "documentfactory.h"
#include "imagefactory.h"
#include "audiofactory.h"
#include <map>
#include <QSet>
#include "htmlexport.h"
#include "latexexport.h"
#include "textexport.h"
#include "note.h"


class NotesManager {

    std::map < QString,NoteFactory* > factories;
    //std::map < QString,ExportStrategy* > strategies;
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
    void creerNote(const QString& type_note, const QString& titre);
    Note* getNoteFromTitre(const QString& titre);
    void setEspaceDeTravail(const QString& e);
    QString getEspaceDeTravail()const {return EspaceDeTravail;}
    void chargerNotes();


};


#endif // NOTESMANAGER_H
