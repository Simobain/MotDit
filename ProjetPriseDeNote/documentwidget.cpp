#include "documentwidget.h"
#include "ui_documentwidget.h"

DocumentWidget::DocumentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DocumentWidget)
{
    ui->setupUi(this);
}

DocumentWidget::~DocumentWidget()
{
    delete ui;
}
