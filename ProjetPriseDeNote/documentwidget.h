#ifndef DOCUMENTWIDGET_H
#define DOCUMENTWIDGET_H

#include <QWidget>
#include <QStringList>
#include <QListWidget>
#include "document.h"
#include "articlewidget.h"
#include "imagewidget.h"
#include "videowidget.h"
#include "audiowidget.h"
#include "documentwidget.h"

#include <QMessageBox>

class NotesManager;

namespace Ui {
class DocumentWidget;
}

/*!
 * \file documentwidget.h
 * \brief Classe DocumentWidget permettant d'afficher une note de type Document
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class DocumentWidget
 * \brief Classe Interface Utilisateur assurant l'affichage d'un Document
 */
class DocumentWidget : public QWidget
{
    Q_OBJECT
    
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe ArticleWidget
         *\param d : pointeur vers le Document concerné par le widget
         *\param parent : fenêtre mère du DocumentWidget
         */
    explicit DocumentWidget(Document* d ,QWidget *parent = 0);
    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe DocumentWidget
         */
    ~DocumentWidget();
    /*!
         *  \brief Setteur du titre du Document
         *  \param titre : titre que l'on souhaite donner au Document
         */
    void setTitre(const QString& titre);
    
private:
    Ui::DocumentWidget *ui;
    QStringList listeNote;/*!< Liste des titres de toutes les notes que l'on peut ajouter au document*/
    //QListWidget* listeSupp;
    Document* actu_document;/*!< Pointeur vers le document affiché*/
    /*!
         *  \brief Permet l'affichage des sous-notes du Document dans le DocumentWidget
         *  Cette méthode privée utitlise un layout pour ajouter une à une des noteswidget au DocumentWidget
         */
    void afficherSousNotes();
    /*!
         *  \brief Permet le chargement des sous-notes du Document dans le DocumentWidget lors du lancement du logiciel MotDit
         *  Cette méthode privée lis le fichier descriptif du Document pour ajouter une à une ses sous-noteswidget au DocumentWidget
         */
    void chargerSousNotes();
public slots:
    ///  \brief Slot permettant d'actualiser le titre
    void actuTitre();


signals:
    /*!
         *  \brief Signal envoyant le nouveau titre rentré par l'utilisateur de l'DocumentWidget
         *  \param n : nouveau titre que l'on souhaite donner au Document
         *  \param o : ancien titre de l'article
         *  \param s : booléen permettant de savoir si l'article à déjà été sauvegardé
         */
    void documentTitreChanged(const QString& n,const QString& o, bool s);

};

#endif // DOCUMENTWIDGET_H
