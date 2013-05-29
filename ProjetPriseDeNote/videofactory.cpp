#include "videofactory.h"

VideoFactory::VideoFactory()
{
}
QString getNewId()
{
    QString ajout="video";
    return s=ajout+NoteFactory::getNewId();
}
