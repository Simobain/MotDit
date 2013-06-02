#include "imagefactory.h"

ImageFactory::ImageFactory()
{
}
QString ImageFactory::getNewId()
{
    QString ajout="image@";
    return ajout+NoteFactory::getNewId();
}
