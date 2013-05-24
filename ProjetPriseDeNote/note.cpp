#include "note.h"
#include <fstream>
#include <QFile>

Note::Note():titre(""), id(genererId()){}

void Note::setTitre(const QString& t){
    titre=t;
}
