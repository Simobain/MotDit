#ifndef ARTICLEWIDGET_H
#define ARTICLEWIDGET_H

#include <QWidget>
#include "article.h"

namespace Ui {
class ArticleWidget;
}
/*!
 * \file articlewidget.h
 * \brief Classe ArticleWidget permettant d'afficher une note de type article
 * \author Pauline Cuche/Simon Robain
 */

/**
 *\class ArticleWidget
 * \brief Classe Interface Utilisateur assurant l'affichage d'un article
 */
class ArticleWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe ArticleWidget
         *\param a : pointeur vers l'article concerné par le widget
         *\param parent : fenêtre mère de l'ArticleWidget
         */
    explicit ArticleWidget(Article* a, QWidget *parent = 0);
    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe ArticleWidget
         */
    ~ArticleWidget();
    /*!
         *  \brief Setteur du titre de l'article
         *  \param titre : titre que l'on souhaite donner à l'article
         */
    void setTitre(const QString& titre);
    /*!
         *  \brief Setteur du texte de l'article
         *  \param texte : texte que l'on souhaite ajouter à l'article
         */
    void setTexte(const QString& texte);
    
private:
    Ui::ArticleWidget *ui;
    Article* actu_article;/*!< Pointeur vers l'article affiché*/

signals :
    /*!
         *  \brief Signal envoyant le nouveau texte rentré par l'utilisateur de l'ArticleWidget
         *  \param titre : texte que l'on souhaite ajouter à l'article
         */
    void articleTexteChanged(const QString& titre);
    /*!
         *  \brief Signal envoyant le nouveau titre rentré par l'utilisateur de l'ArticleWidget
         *  \param newTitre : nouveau titre que l'on souhaite donner à l'article
         *  \param oldTitre : ancien titre de l'article
         *  \param saved : booléen permettant de savoir si l'article à déjà été sauvegardé
         */
    void articleTitreChanged(const QString& newTitre, const QString& oldTitre, bool saved);

public slots :

    ///  \brief Slot permettant d'actualiser le titre
    void actuTitre();
    ///  \brief Slot permettant d'actualiser le texte
    void actuTexte();



};

#endif // ARTICLEWIDGET_H
