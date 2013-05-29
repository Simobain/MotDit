#include "audiofactory.h"

AudioFactory::audioFactory()
{
}
QString getNewId()
{
    QString ajout="audio";
    return s=ajout+NoteFactory::getNewId();
}
