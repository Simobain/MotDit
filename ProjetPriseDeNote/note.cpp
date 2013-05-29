#include "note.h"
#include <fstream>
#include <QFile>

Note::Note():id(getNewId()),titre(""),modified(false),loaded(false){}

void Note::setTitre(const QString& t){
    titre=t;
}
