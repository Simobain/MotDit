#ifndef ARTICLE_H
#define ARTICLE_H
#include <QString>
#include "note.h"
class NotesManager;



class Article : public Note {
    QString texte;
    Article(const Article& a);
    Article& operator=(const Article& a);


public:
    Article();
    Article(const QString& id, const QString& titre, const QString& text="");
    QString getTexte() const {return texte;}
    void setTexte(const QString& t);
    void load(const QString& chemin);
    void save(const QString& directory);
    NoteType getType() const;

};


#endif // ARTICLE_H
