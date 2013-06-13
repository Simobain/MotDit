#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include "video.h"

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
    void setChemin(const QString& chemin);
private:
    Ui::videowidget *ui;
    Video* actu_video;


signals:
    void videoDescChanged(const QString&);
    void videoTitreChanged(const QString&,const QString&, bool);

public slots :

    void actuTitre();
    void actuDesc();


};

#endif // VIDEOWIDGET_H
