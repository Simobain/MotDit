#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include "article.h"

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
    void replaceInListe(const QString& oldName,const QString& newName);

public slots :

    void creerArticle();
    //void ajoutListe();
    void itemClicked(const QModelIndex & index);
    void noteTitreChanged(const QString &newTitre, const QString& oldTitre, bool saved);
    void noteChanged(const QString &titre);    
    void sauverClicked();
};

#endif // MAINWINDOW_H
