#ifndef DOCUMENT_H
#define DOCUMENT_H
#include "note.h"
#include <QSet>


class Document : public Note
{
    QSet<Note*> sousNotes;
    Document(const Document&);
    Document& operator=(const Document&);
    bool loaded;
    void load();

public:
    Document(const QString& id,const QString& titre);
    //QString ExportAsPart(ExportStrategy *es, unsigned int titlelevel);
    void addSubNote(Note *n);
    //void addSubNote(Note *n, QString id);
    void removeSubNote(Note *n);
    QSet<Note*> getSousNotes();
    //Note* getSubNote(QString id);
    NoteType getType() const;
    void save(const QString &directory);
    void setLoaded(bool b){loaded=b ;}
    bool getLoaded() const  {return loaded;}
};

#endif // DOCUMENT_H
