#ifndef ARTICLEWIDGET_H
#define ARTICLEWIDGET_H

#include <QWidget>

namespace Ui {
class ArticleWidget;
}

class ArticleWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ArticleWidget(QWidget *parent = 0);
    ~ArticleWidget();
    void setTitre(const QString& titre);
    void setTexte(const QString& texte);
    
private:
    Ui::ArticleWidget *ui;
};

#endif // ARTICLEWIDGET_H
