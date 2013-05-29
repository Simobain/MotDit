#include "documentfactory.h"

DocumentFactory::DocumentFactory()
{
}
QString getNewId()
{
    QString ajout="document";
    return s=ajout+NoteFactory::getNewId();
}
