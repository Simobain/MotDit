#include "documentwidget.h"
#include "ui_documentwidget.h"

DocumentWidget::DocumentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DocumentWidget)
{
    ui->setupUi(this);
    listeSupp= new QListWidget;
    ui->frame->setLineWidth(4);

    QVBoxLayout* layout = new QVBoxLayout();
    ui->frame->setLayout(layout);
    QObject :: connect(ui->deleteNote, SIGNAL(clicked()), this, SLOT(choisirNote()));
}

DocumentWidget::~DocumentWidget()
{
    delete ui;
}

void DocumentWidget::choisirNote()
{
    listeSupp->show();
}
