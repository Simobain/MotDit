#include "audiowidget.h"
#include "ui_audiowidget.h"

audiowidget::audiowidget(Audio *a, QWidget *parent) :
    actu_audio(a),
    QWidget(parent),
    enCoursdeLecture(false),
    ui(new Ui::audiowidget)
{
    QFont titreFont("Times", 14, QFont::Bold);
    QFont texteFont("Times", 10);
    ui->setupUi(this);
    ui->lineEdit->setFont(titreFont);
    ui->textEdit->setFont(texteFont);
    QObject ::connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(actuDesc()));
    QObject ::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(actuTitre()));
    player = new QMediaPlayer;
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(playPause()));

    setTitre(a->getTitre());
    setDesc(a->getDescription());
    setMusique(a->getChemin());
}

audiowidget::~audiowidget()
{
    delete ui;
}

void audiowidget::setTitre(const QString& titre){
    ui->lineEdit->setText(titre);
}

void audiowidget::setDesc(const QString& desc){
    ui->textEdit->setText(desc);
}

void audiowidget::setMusique(const QString& chemin){
    player->setMedia(QUrl::fromLocalFile(chemin));
    player->setVolume(50);
}

void audiowidget::actuDesc(){
    actu_audio->setDescription(ui->textEdit->toPlainText());
    if (actu_audio->isSaved()){
    actu_audio->setSaved(false);
    emit audioDescChanged(actu_audio->getTitre());
        }
}

void audiowidget::actuTitre(){
    QString ancienTitre = actu_audio->getTitre();
    actu_audio->setTitre(ui->lineEdit->text());
    if (actu_audio->isSaved()){
        actu_audio->setSaved(false);
        emit audioTitreChanged(actu_audio->getTitre(), ancienTitre, true );
    }
    else emit audioTitreChanged(actu_audio->getTitre(), ancienTitre, false );

}

void audiowidget::playPause()
{
    if(enCoursdeLecture) {
        player->pause();
        enCoursdeLecture=false;}
    else {
        player->play();
        enCoursdeLecture=true;}
}
