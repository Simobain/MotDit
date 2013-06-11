#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include "image.h"

namespace Ui {
class ImageWidget ;
}

class ImageWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit ImageWidget(Image *im, QWidget *parent = 0);
    ~ImageWidget();
    void setTitre(const QString& titre);
    void setDesc(const QString& desc);
    void setChemin(const QString& chemin);
    
private:
    Ui::ImageWidget *ui;
    Image* actu_image;
    //QPixmap* pixmap;

signals:
    void imageDescChanged(const QString&);
    void imageTitreChanged(const QString&,const QString&, bool);

public slots :
    void actuTitre();
    void actuDesc();
};

#endif // IMAGEWIDGET_H
