#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>

namespace Ui {
class imagewidget;
}

class imagewidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit imagewidget(QWidget *parent = 0);
    ~imagewidget();
    
private:
    Ui::imagewidget *ui;
};

#endif // IMAGEWIDGET_H
