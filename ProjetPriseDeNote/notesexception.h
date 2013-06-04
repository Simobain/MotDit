#ifndef NOTESEXCEPTION_H
#define NOTESEXCEPTION_H
#include <QString>
#include <QDebug>


class NotesException{
public:
    NotesException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};

#endif // NOTESEXCEPTION_H
