#ifndef AUDIOWIDGET_H
#define AUDIOWIDGET_H

#include <QWidget>
#include "audio.h"
#include <QMediaPlayer>

namespace Ui {
class audiowidget;
}

class audiowidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit audiowidget(Audio* a, QWidget *parent = 0);
    ~audiowidget();
    void setTitre(const QString& titre);
    void setDesc(const QString& desc);
    void setMusique(const QString& chemin);

private:
    Ui::audiowidget *ui;
    Audio* actu_audio;
    QMediaPlayer* player;
    bool enCoursdeLecture;
signals:
    void audioDescChanged(const QString&);
    void audioTitreChanged(const QString&,const QString&, bool);

public slots :
    void actuTitre();
    void actuDesc();
    void playPause();

};

#endif // AUDIOWIDGET_H
