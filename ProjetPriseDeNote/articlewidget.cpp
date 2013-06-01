#include "articlewidget.h"
#include "ui_articlewidget.h"

ArticleWidget::ArticleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ArticleWidget)
{
    ui->setupUi(this);

}

ArticleWidget::~ArticleWidget()
{
    delete ui;
}

void ArticleWidget::setTitre(const QString& titre){
    ui->lineEdit->setText(titre);
}

void ArticleWidget::setTexte(const QString& texte){
    ui->textEdit->setText(texte);
}
