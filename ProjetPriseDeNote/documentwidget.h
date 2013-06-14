#ifndef DOCUMENTWIDGET_H
#define DOCUMENTWIDGET_H

#include <QWidget>
#include <QListWidget>

namespace Ui {
class DocumentWidget;
}

class DocumentWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit DocumentWidget(QWidget *parent = 0);
    ~DocumentWidget();
    
private:
    Ui::DocumentWidget *ui;
    QListWidget* listeSupp;
    QFrame* frame;
public slots:
    void choisirNote();

};

#endif // DOCUMENTWIDGET_H
