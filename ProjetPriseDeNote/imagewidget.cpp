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
    pixmap=0;
    QObject ::connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(actuDesc()));
    QObject ::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(actuTitre()));

    setTitre(im->getTitre());
    setDesc(im->getDescription());
    setChemin(im->getChemin());
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
    delete pixmap;
    pixmap=new QPixmap(chemin);
    *pixmap=pixmap->scaled(QSize(100,100), Qt::KeepAspectRatio);
    ui->label->setPixmap(*pixmap);

}


void ImageWidget::actuDesc(){
    actu_image->setDescription(ui->textEdit->toPlainText());
    if (actu_image->isSaved()){
    actu_image->setSaved(false);
    emit imageDescChanged(actu_image->getTitre());
        }
}

void ImageWidget::actuTitre(){
    QString ancienTitre = actu_image->getTitre();
    actu_image->setTitre(ui->lineEdit->text());
    if (actu_image->isSaved()){
        actu_image->setSaved(false);
        emit imageTitreChanged(actu_image->getTitre(), ancienTitre, true );
    }
    else emit imageTitreChanged(actu_image->getTitre(), ancienTitre, false );

}
