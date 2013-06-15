#include "documentwidget.h"
#include "ui_documentwidget.h"

DocumentWidget::DocumentWidget(Document *d, QWidget *parent) :
    QWidget(parent),
    actu_document(d),
    ui(new Ui::DocumentWidget)
{
    ui->setupUi(this);

    QFont titreFont("Times", 14, QFont::Bold);
    ui->lineEdit->setFont(titreFont);

    listeSupp= new QListWidget;
    //ui->frame->setLineWidth(4);

    QObject ::connect(ui->deleteNote, SIGNAL(clicked()), this, SLOT(choisirNote()));
    QObject ::connect(ui->lineEdit, SIGNAL(textChanged(QString)), this, SLOT(actuTitre()));

    setTitre(d->getTitre());
    afficherSousNotes();

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
    QSet<Note*> ensSousNotes=actu_document->getSousNotes();
    QSet<Note*>::iterator it=ensSousNotes.begin();
    it= ensSousNotes.begin();
    while(it!=ensSousNotes.end() && !ensSousNotes.isEmpty()){
        switch((*it)->getType()){
        case Note::ARTICLE :
            qDebug()<<"ajouter article";
            ui->verticalLayout_2->addWidget(new ArticleWidget((Article*)*it));
            break;
        case Note::IMAGE :
            qDebug()<<"ajouter image";
            ui->verticalLayout_2->addWidget(new ImageWidget((Image*)*it));
            break;
        case Note::VIDEO :
            qDebug()<<"ajouter video";
            ui->verticalLayout_2->addWidget(new videowidget((Video*)*it));
            break;
        case Note::AUDIO :
            qDebug()<<"ajouter audio";
            ui->verticalLayout_2->addWidget(new audiowidget((Audio*)*it));
            break;
        case Note::DOCUMENT :
            qDebug()<<"ajouter document";
            ui->verticalLayout_2->addWidget(new DocumentWidget((Document*)*it));
            break;
        default :
            QMessageBox::critical(this,"Erreur","ERREUR PB DS AFFICHER SOUS NOTES");
        }
        it++;
    }
}
