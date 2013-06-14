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

    //QVBoxLayout* layout = new QVBoxLayout();
    //ui->frame->setLayout(layout);
    QObject ::connect(ui->deleteNote, SIGNAL(clicked()), this, SLOT(choisirNote()));
    QObject ::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(actuTitre()));

    void afficherSousNotes();


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

void DocumentWidget::afficherSousNotes(){
    QSet<Note*>::iterator it= actu_document->getSousNotes().begin();
    while(it!=actu_document->getSousNotes().end()){
        switch((*it)->getType()){
        case Note::ARTICLE :
            ui->verticalLayout_3->addWidget(new ArticleWidget((Article*)*it));
            break;
        case Note::IMAGE :
            ui->verticalLayout_3->addWidget(new ImageWidget((Image*)*it));
            break;
        case Note::VIDEO :
            ui->verticalLayout_3->addWidget(new videowidget((Video*)*it));
        case Note::AUDIO :
            ui->verticalLayout_3->addWidget(new audiowidget((Audio*)*it));
            break;
        case Note::DOCUMENT :
            ui->verticalLayout_3->addWidget(new DocumentWidget((Document*)*it));
        default :
            QMessageBox::critical(this,"Erreur","ERREUR PB DS AFFICHER SOUS NOTES");
        }
    }

}
