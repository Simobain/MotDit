#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    Ui::MainWindow *ui;
    QStringList liste;

public slots :

    void creerArticle();
    //void ajoutListe();
    void itemClicked(const QModelIndex & index);
    void noteChanged(const QString &titre);
    void sauverClicked();
};

#endif // MAINWINDOW_H
