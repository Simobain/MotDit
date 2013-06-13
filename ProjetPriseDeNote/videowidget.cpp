#include "videowidget.h"
#include "ui_videowidget.h"

videowidget::videowidget(Video* v, QWidget *parent) :
    actu_video(v),
    QWidget(parent),
    ui(new Ui::videowidget)
{
    QFont titreFont("Times", 14, QFont::Bold);
    QFont texteFont("Times", 10);
    ui->setupUi(this);
    ui->lineEdit->setFont(titreFont);
    ui->textEdit->setFont(texteFont);
    QObject ::connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(actuDesc()));
    QObject ::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(actuTitre()));

}

videowidget::~videowidget()
{
    delete ui;
}

void videowidget::setTitre(const QString& titre){
    ui->lineEdit->setText(titre);
}

void videowidget::setDesc(const QString& desc){
    ui->textEdit->setText(desc);
}

void videowidget::setChemin(const QString& chemin){
    //trouver fonction pour afficher video sous Qt
    ui->label->setText(chemin);

}
void videowidget::actuDesc(){
    actu_video->setDescription(ui->textEdit->toPlainText());
    if (actu_video->isSaved()){
    actu_video->setSaved(false);
    emit videoDescChanged(actu_video->getTitre());
        }
}

void videowidget::actuTitre(){
    QString ancienTitre = actu_video->getTitre();
    actu_video->setTitre(ui->lineEdit->text());
    if (actu_video->isSaved()){
        actu_video->setSaved(false);
        emit videoTitreChanged(actu_video->getTitre(), ancienTitre, true );
    }
    else emit videoTitreChanged(actu_video->getTitre(), ancienTitre, false );

}

