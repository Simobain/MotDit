#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include "notesmanager.h"
#include "articlewidget.h"
#include "imagewidget.h"
#include "videowidget.h"
#include "audiowidget.h"
#include "documentwidget.h"
#include "document.h"
#include <QStringListModel>


/*!
 * \file mainwindow.h
 * \brief Classe mainwidow : elle gère la fenêtre principale du logiciel MotDit.
 * \author Pauline Cuche/Simon Robain
 */
/*!
 * \class MainWindow
 * \brief Cette classe gère la fenêtre principale du logiciel MotDit.
 * Elle représente la plus grande partie de l'interface utilisateur
 */
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    /*!
         *  \brief Constructeur Par Defaut
         *
         *  Constructeur par défaut de la classe MainWindow
         */
    explicit MainWindow(QWidget *parent = 0);
    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe MainWindow.
         */
    ~MainWindow();
    /*!
         *  \brief Methode qui permet de créer tout type de Note
         *Elle appelle le bon constructeur via le NotesManager
         *\param type : type de la note que l'utilisateur souhaite créer
         *\param path : chemin d'accès à l'espace de travail
         */
    void creerNote(const QString& type, const QString &path="");
    /*!
         *  \brief Affichage d'une Note de type Article
         *\param article : pointeur sur l'Article que l'on souhaite afficher
         */
    void afficherArticle(Article* article);
    /*!
         *  \brief Affichage d'une Note de type Image
         *\param im : pointeur sur l'Image que l'on souhaite afficher
         */
    void afficherImage(Image* im);
    /*!
         *  \brief Affichage d'une Note de type Video
         *\param v : pointeur sur la Video que l'on souhaite afficher
         */
    void afficherVideo(Video* v);
    /*!
         *  \brief Affichage d'une Note de type Audio
         *\param a : pointeur sur l'Audio que l'on souhaite afficher
         */
    void afficherAudio(Audio* a);
    /*!
         *  \brief Affichage d'une Note de type Document
         *\param d : pointeur sur le Document que l'on souhaite afficher
         */
    void afficherDocument(Document* d);

private:
    QWidget* last_widget;/*!< Pointeur vers le dernier widget affiché*/
    QModelIndex last_clicked;/*!< Pointeur vers le dernier index cliqué*/
    Ui::MainWindow *ui;
    QStringList liste;/*!< Liste de toute les notes chargées*/
    QStringList listeTemp;/*!< Liste Temporaire permettant l'affichage des notes à ajouter à un document*/
    QStringListModel* model;/*!< Modèle qui permet de générer la listeView de toutes les notes chargées*/
    QStringListModel* modelAjout;/*!< Modèle qui permet de générer listeAjout*/
    QListView* listeAjout;/*!< Pointeur vers la QListeView qui affiche listeTemp*/
    QListView* listeSupp;/*!< Pointeur vers la QListeView qui affiche listeDesSousNotes */
    QStringList listeDesSousNotes;/*!< Liste de toutes les sous-Notes d'un Document*/
    QStringListModel* modelSupp;/*!< Modèle qui permet de générer listeSupp*/
    /*!
         *  \brief Mise à Jour de la liste suite à la modification du titre d'une Note
         *\param oldName : ancien titre de la Note
         *\param newName : nouveau titre de la Note
         */
    void replaceInListe(const QString& oldName,const QString &newName);
    /*!
         *  \brief Methode qui permet d'afficher dans l'éditeur l'export de la dernière Note cliquée en .txt
         */
    void ongletTexteClicked();
    /*!
         *  \brief Methode qui permet d'afficher dans l'éditeur l'export d'une Note en .html
         */
    void ongletHtmlClicked();
    /*!
         *  \brief Methode qui permet d'afficher dans l'éditeur l'export d'une Note en .Tex
         */
    void ongletTexClicked();

public slots :
    /*!
         *  \brief Slot qui créé un Article
         *  Il se déclenche lorsque l'on clique sur Fichier->Nouveau->Article
         */
    void creerArticle();
    /*!
         *  \brief Slot qui créé une Image
         *  Il se déclenche lorsque l'on clique sur Fichier->Nouveau->Image
         */
    void creerImage();
    /*!
         *  \brief Slot qui créé une Video
         *  Il se déclenche lorsque l'on clique sur Fichier->Nouveau->Video
         */
    void creerVideo();
    /*!
         *  \brief Slot qui créé un Audio
         *  Il se déclenche lorsque l'on clique sur Fichier->Nouveau->Audio
         */
    void creerAudio();
    /*!
         *  \brief Slot qui créé un Document
         *  Il se déclenche lorsque l'on clique sur Fichier->Nouveau->Document
         */
    void creerDocument();
    /*!
         *  \brief Slot qui affiche la Note lorque l'on clique dessus
         *\param index : dernier index cliqué
         */
    void itemClicked(const QModelIndex & index);
    /*!
         *  \brief Slot qui appelle ReplaceInListe lorsque l'utilisateur modifie le titre
         *\param newTitre : ancien titre de la Note
         *\param oldTitre : nouveau titre de la Note
         */
    void noteTitreChanged(const QString &newTitre, const QString& oldTitre, bool saved);
    /*!
         *  \brief Slot qui appelle ReplaceInListe lorsque l'utilisateur modifie la Note
         *Cela ajoute une * à la fin de son titre, notifiant ainsi l'utilisateur que la note doit être sauvegardée
         *\param Titre :titre de la Note
         */
    void noteChanged(const QString &titre);
    /*!
         *  \brief Slot qui sauvegarde la note courante lorsque l'on clique sur le bouton Sauver
         */
    void sauverClicked();
    /*!
         *  \brief Slot qui supprime la note courante lorsque l'on clique sur le bouton Sauver
         */
    void supprClicked();
    /*!
         *  \brief Slot qui gère les différents onglets de la mainWindow
         */
    void ongletChange(int index);
    /*!
         *  \brief Slot qui permet de changer d'espace de travail
         */
    void changerEspaceTravail();
    /*!
         *  \brief Slot qui permet d'ajouter des sous-notes à un Document
         */
    void ajoutSousNotes();
    /*!
         *  \brief Slot qui permet de récupérer la sous note selectionnée et qui l'ajoute au Document
         *\param index : index de la sous note selectionnée
         */
    void sousNotesSelected(const QModelIndex &index);
    /*!
         *  \brief Slot qui permet de supprimer des sous-notes d'un Document
         */
    void suppSousNotes();
    /*!
         *  \brief Slot qui permet de récupérer la sous note selectionnée et qui la supprime du Document
         *\param index : index de la sous note selectionnée
         */
    void sousNotesASuppSelected(const QModelIndex& index);
    /*!
         *  \brief Slot qui permet de sauver une Note en .html
         */
    void saveExportHtml();
    /*!
         *  \brief Slot qui permet de sauver une Note en .Tex
         */
    void saveExportLatex();
    /*!
         *  \brief Slot qui permet de sauver une Note en .txt
         */
    void saveExportText();

};

#endif // MAINWINDOW_H
