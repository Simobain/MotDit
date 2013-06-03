#ifndef ARTICLEWIDGET_H
#define ARTICLEWIDGET_H

#include <QWidget>
#include "article.h"

namespace Ui {
class ArticleWidget;
}

class ArticleWidget : public QWidget
{
    Q_OBJECT
    Article* actu_article;
public:
    explicit ArticleWidget(Article* a, QWidget *parent = 0);
    ~ArticleWidget();
    void setTitre(const QString& titre);
    void setTexte(const QString& texte);
    
private:
    Ui::ArticleWidget *ui;

signals :
    void articleTexteChanged(const QString& titre);
    void articleTitreChanged(const QString& newTitre, const QString& oldTitre, bool saved);

public slots :
    void actuTitre();
    void actuTexte();



};

#endif // ARTICLEWIDGET_H
