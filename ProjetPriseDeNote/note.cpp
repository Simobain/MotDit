#include "note.h"
#include <fstream>
#include <QFile>
#include "exportstrategy.h"

//Note::Note():id(getNewId()),titre(""),modified(false),loaded(false){}
Note::Note():id(001), titre(""), modified(false), loaded(false){}

Note::Note(const QString& i, const QString& t): id(i), titre(t),modified(false),loaded(false){}


void Note::setTitre(const QString& t){
    titre=t;
}

