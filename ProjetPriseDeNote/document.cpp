#include "document.h"

Document::Document() : Note()
{
}

Note::NoteType Document::getType()const {
    return DOCUMENT;
}
