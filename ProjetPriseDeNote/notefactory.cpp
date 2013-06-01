#include "notefactory.h"
#include "time.h"
#include <iostream>

NoteFactory::NoteFactory()
{

}

QString  NoteFactory::getNewId()
{
        time_t tim=time(NULL);
        tm * now=localtime(&tim);
        tim=mktime(now);
        std::stringstream s;
        s<<tim;
        return QString::fromStdString(s.str()) ;

}

