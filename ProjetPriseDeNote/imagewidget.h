#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>
#include "image.h"

namespace Ui {
class ImageWidget ;
}
/*!
 * \file imagewidget.h
 * \brief Classe ImageWidget permettant d'afficher une note de type Image
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class ImageWidget
 * \brief Classe Interface Utilisateur assurant l'affichage d'une note de type Image
 */
class ImageWidget : public QWidget
{
    Q_OBJECT
    
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe ImageWidget
         *\param im : pointeur vers l'Image concerné par le widget
         *\param parent : fenêtre mère de l'ImageWidget
         */
    explicit ImageWidget(Image *im, QWidget *parent = 0);
    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe ArticleWidget
         */
    ~ImageWidget();
    /*!
         *  \brief Setteur du titre de l'Image
         *  \param titre : titre que l'on souhaite donner à l'Image
         */
    void setTitre(const QString& titre);
    /*!
         *  \brief Setteur de la description de l'Image
         *  \param desc : descriptif que l'on souhaite ajouter à l'Image
         */
    void setDesc(const QString& desc);
    /*!
         *  \brief Setteur du chemin de l'image affichée par l'ImageWidget
         *  \param chemin : chemin de l'image affichée par l'ImageWidget
         */
    void setChemin(const QString& chemin);

private:
    Ui::ImageWidget *ui;
    Image* actu_image;/*!< Pointeur vers l'Image affichée*/
    QPixmap* pixmap;/*!< Pointeur vers un QPixmap permettant d'affiché une image*/

signals:
    /*!
         *  \brief Signal envoyant la nouvelle description rentrée par l'utilisateur de l'ImageWidget
         *  \param desc : description que l'on souhaite ajouter à l'Image
         */
    void imageDescChanged(const QString& desc);
    /*!
         *  \brief Signal envoyant le nouveau titre rentré par l'utilisateur de l'ImageWidget
         *  \param n : nouveau titre que l'on souhaite donner à l'Image
         *  \param o : ancien titre de l'Image
         *  \param s : booléen permettant de savoir si l'Image a déjà été sauvegardée
         */
    void imageTitreChanged(const QString& n,const QString& o, bool s);

public slots :
    ///  \brief Slot permettant d'actualiser le titre
    void actuTitre();
    ///  \brief Slot permettant d'actualiser la description
    void actuDesc();
};

#endif // IMAGEWIDGET_H
