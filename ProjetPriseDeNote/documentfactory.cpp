#include "documentfactory.h"

DocumentFactory::DocumentFactory()
{
}
QString DocumentFactory::getNewId()
{
    QString ajout="document@";
    return ajout+NoteFactory::getNewId();
}
