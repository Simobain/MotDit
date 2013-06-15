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



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void creerNote(const QString& type, const QString &path="");
    void afficherArticle(Article* article);
    void afficherImage(Image* im);
    void afficherVideo(Video* v);
    void afficherAudio(Audio* a);
    void afficherDocument(Document* d);

private:
    QWidget* last_widget;
    QModelIndex last_clicked;
    Ui::MainWindow *ui;
    QStringList liste;
    QStringList listeTemp;
    QStringListModel* model;
    QStringListModel* modelAjout;
    QListView* listeAjout;

    void replaceInListe(const QString& oldName,const QString &newName);
    void ongletTexteClicked();
    void ongletHtmlClicked();
    void ongletTexClicked();

public slots :

    void creerArticle();
    void creerImage();
    void creerVideo();
    void creerAudio();
    void creerDocument();
    void itemClicked(const QModelIndex & index);
    void noteTitreChanged(const QString &newTitre, const QString& oldTitre, bool saved);
    void noteChanged(const QString &titre);    
    void sauverClicked();
    void supprClicked();
    void ongletChange(int index);
    void changerEspaceTravail();
    void ajoutSousNotes();
    void sousNotesSeleted(const QModelIndex &index);



};

#endif // MAINWINDOW_H
