#include "videowidget.h"
#include "ui_videowidget.h"

videowidget::videowidget(Video* v, QWidget *parent) :
    QWidget(parent),
    actu_video(v),
    //enCoursdeLecture(false),
    ui(new Ui::videowidget)
{
    qDebug()<<"entre videowidget cstror";
    QFont titreFont("Times", 14, QFont::Bold);
    QFont texteFont("Times", 10);
    ui->setupUi(this);
    ui->lineEdit->setFont(titreFont);
    ui->textEdit->setFont(texteFont);

    //player = new QMediaPlayer;
    //playlist = new QMediaPlaylist(player);
    //film = new QVideoWidget(this);
    //player->setVideoOutput(film);
    //film->show();



    QObject ::connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(actuDesc()));
    QObject ::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(actuTitre()));

    setTitre(v->getTitre());
    setDesc(v->getDescription());
    setVideo(v->getChemin());
    qDebug()<<"sortie videowidget cstror";
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

void videowidget::setVideo(const QString& chemin){
    //playlist->addMedia(QUrl(chemin));
    //playlist->setCurrentIndex(1);
    //player->play();
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

