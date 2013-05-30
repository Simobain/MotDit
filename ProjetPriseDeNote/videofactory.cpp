#include "videofactory.h"

VideoFactory::VideoFactory()
{
}
QString VideoFactory::getNewId()
{
    QString ajout="video";
    return ajout+NoteFactory::getNewId();
}
