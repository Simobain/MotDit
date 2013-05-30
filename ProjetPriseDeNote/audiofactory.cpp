#include "audiofactory.h"

AudioFactory::AudioFactory()
{
}
QString AudioFactory::getNewId()
{
    QString ajout="audio";
    return ajout+NoteFactory::getNewId();
}
