#include "imagefactory.h"

ImageFactory::ImageFactory()
{
}
QString getNewId()
{
    QString ajout="image";
    return s=ajout+NoteFactory::getNewId();
}
