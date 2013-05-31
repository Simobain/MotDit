#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    
private:
    Ui::MainWindow *ui;
    //QStringList liste;

public slots :
    void ouvrirArticle();
    void creerArticle();
    void ajoutListe();
};

#endif // MAINWINDOW_H
