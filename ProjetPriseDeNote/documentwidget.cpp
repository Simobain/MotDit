#include "documentwidget.h"
#include "ui_documentwidget.h"

DocumentWidget::DocumentWidget(Document *d, QWidget *parent) :
    QWidget(parent),
    actu_document(d),
    ui(new Ui::DocumentWidget)
{
    ui->setupUi(this);
    listeSupp= new QListWidget;
    ui->frame->setLineWidth(4);

    QVBoxLayout* layout = new QVBoxLayout();
    ui->frame->setLayout(layout);
    QObject :: connect(ui->deleteNote, SIGNAL(clicked()), this, SLOT(choisirNote()));
    QObject ::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(actuTitre()));
}

DocumentWidget::~DocumentWidget()
{
    delete ui;
}

void DocumentWidget::choisirNote()
{
    listeSupp->show();
}

void DocumentWidget::setTitre(const QString& titre){
    ui->lineEdit->setText(titre);
}

void DocumentWidget::actuTitre(){
    QString ancienTitre = actu_document->getTitre();
    actu_document->setTitre(ui->lineEdit->text());
    if (actu_document->isSaved()){
        actu_document->setSaved(false);
        emit documentTitreChanged(actu_document->getTitre(), ancienTitre, true );
    }
    else emit documentTitreChanged(actu_document->getTitre(), ancienTitre, false );

}

