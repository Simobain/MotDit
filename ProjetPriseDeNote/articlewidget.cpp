#include "articlewidget.h"
#include <QFont>
#include "ui_articlewidget.h"

ArticleWidget::ArticleWidget(Article *a, QWidget *parent) :
    actu_article(a), QWidget(parent),
    ui(new Ui::ArticleWidget)
{
    QFont titreFont("Times", 14, QFont::Bold);
    QFont texteFont("Times", 10);
    ui->setupUi(this);
    ui->lineEdit->setFont(titreFont);
    ui->textEdit->setFont(texteFont);
    QObject ::connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(actuTexte()));
    QObject ::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(actuTitre()));

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

void ArticleWidget::actuTexte(){
    actu_article->setTexte(ui->textEdit->toPlainText());
}

void ArticleWidget::actuTitre(){
    actu_article->setTitre(ui->lineEdit->text());
}
