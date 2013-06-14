#ifndef DOCUMENTWIDGET_H
#define DOCUMENTWIDGET_H

#include <QWidget>
#include <QStringList>
#include <QListWidget>
#include "document.h"
#include "articlewidget.h"
#include "imagewidget.h"
#include "videowidget.h"
#include "audiowidget.h"
#include "documentwidget.h"
#include <QMessageBox>

namespace Ui {
class DocumentWidget;
}

class DocumentWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit DocumentWidget(Document* d ,QWidget *parent = 0);
    ~DocumentWidget();
    void setTitre(const QString& titre);
    
private:
    Ui::DocumentWidget *ui;
    QStringList listeNote;
    QListWidget* listeSupp;
    Document* actu_document;
    void afficherSousNotes();
public slots:
    void choisirNote();
    void actuTitre();


signals:
    void documentTitreChanged(const QString&,const QString&, bool);

};

#endif // DOCUMENTWIDGET_H
