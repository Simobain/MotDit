#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include "notesmanager.h"
#include "articlewidget.h"
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
    void creerNote(const QString& type);
    void afficherArticle(Article* article);

private:
    QWidget* last_widget;
    QModelIndex last_clicked;
    Ui::MainWindow *ui;
    QStringList liste;
    QStringListModel* model;
    void replaceInListe(const QString& oldName,const QString& newName);
    void ongletTexteClicked();
    void ongletHtmlClicked();
    void ongletTexClicked();

public slots :

    void creerArticle();
    void creerImage();
    void itemClicked(const QModelIndex & index);
    void noteTitreChanged(const QString &newTitre, const QString& oldTitre, bool saved);
    void noteChanged(const QString &titre);    
    void sauverClicked();
    void supprClicked();
    void ongletChange(int index);
    void changerEspaceTravail();

};

#endif // MAINWINDOW_H
