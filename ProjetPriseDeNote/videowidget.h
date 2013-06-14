#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include "video.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
namespace Ui {
class videowidget;
}

class videowidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit videowidget(Video* v ,QWidget *parent = 0);
    ~videowidget();
    void setTitre(const QString& titre);
    void setDesc(const QString& desc);
    void setVideo(const QString& chemin);
private:
    Ui::videowidget *ui;
    Video* actu_video;
    //QMediaPlayer* player;
    //QVideoWidget* film;
    //QMediaPlaylist* playlist;
    //bool enCoursdeLecture;



signals:
    void videoDescChanged(const QString&);
    void videoTitreChanged(const QString&,const QString&, bool);

public slots :

    void actuTitre();
    void actuDesc();


};

#endif // VIDEOWIDGET_H
