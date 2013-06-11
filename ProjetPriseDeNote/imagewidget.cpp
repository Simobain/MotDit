#include "imagewidget.h"
#include "ui_imagewidget.h"

ImageWidget::ImageWidget(Image *im,QWidget *parent) :
    actu_image(im),
    QWidget(parent),
    ui(new Ui::ImageWidget)
{
    //ui->setupUi(this);
    QFont titreFont("Times", 14, QFont::Bold);
    QFont texteFont("Times", 10);
    ui->setupUi(this);
    ui->lineEdit->setFont(titreFont);
    ui->textEdit->setFont(texteFont);
    //pixmap=0;
    //QObject ::connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(actuDesc()));
    //QObject ::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(actuTitre()));

}

ImageWidget::~ImageWidget()
{
    delete ui;
}

void ImageWidget::setTitre(const QString& titre){
    ui->lineEdit->setText(titre);
}

void ImageWidget::setDesc(const QString& desc){
    ui->textEdit->setText(desc);
}

void ImageWidget::setChemin(const QString& chemin){
    //delete pixmap;
    ui->label->setPixmap(QPixmap(chemin));
}
