#ifndef DOCUMENTWIDGET_H
#define DOCUMENTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include "document.h"

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
    QListWidget* listeSupp;
    Document* actu_document;
public slots:
    void choisirNote();
    void actuTitre();


signals:
    void documentTitreChanged(const QString&,const QString&, bool);

};

#endif // DOCUMENTWIDGET_H
