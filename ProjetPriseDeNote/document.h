#ifndef DOCUMENT_H
#define DOCUMENT_H
#include "note.h"
#include <QSet>


class Document : public Note
{
    QSet<Note*> ensNotes;
    Document(const Document&);
    Document& operator=(const Document&);
    void load();

public:
    Document();
    //QString ExportAsPart(ExportStrategy *es, unsigned int titlelevel);
    void addSubNote(Note *n);
    void addSubNote(Note *n, QString id);
    void removeSubNote(QString id);
    Note* getSubNote(QString id);



};

#endif // DOCUMENT_H
