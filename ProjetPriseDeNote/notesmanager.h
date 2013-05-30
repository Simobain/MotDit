#ifndef NOTESMANAGER_H
#define NOTESMANAGER_H
#include <iostream>
#include <QString>
#include "notefactory.h"
#include "articlefactory.h"
#include "videofactory.h"
#include "documentfactory.h"
#include "imagefactory.h"
#include "audiofactory.h"
#include <map>
#include <QSet>

#include "note.h"

class NotesManager {

    std::map < QString,NoteFactory* > factories;
    QSet<Note*> ensnotes;
    static NotesManager* instance;

    NotesManager();
    ~NotesManager();
    //NotesManager(const NoteManager&);
    NotesManager& operator=(const NotesManager&);


public:

    static NotesManager* getInstance();
    void libereInstance();
    void creerNote(const QString& type_note, const QString& titre);

};


#endif // NOTESMANAGER_H
