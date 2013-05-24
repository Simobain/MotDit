#ifndef DOCUMENT_H
#define DOCUMENT_H
#include "note.h"
#include <QSet>


class document : public Note
{
    QSet<Note*> ensNotes;

public:
    document();
};

#endif // DOCUMENT_H
