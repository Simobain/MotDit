#include "imagewidget.h"
#include "ui_imagewidget.h"

imagewidget::imagewidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::imagewidget)
{
    ui->setupUi(this);
}

imagewidget::~imagewidget()
{
    delete ui;
}
