#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>
#include "video.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaPlaylist>
namespace Ui {
class videowidget;
}
/*!
 * \file videowidget.h
 * \brief Classe VideoWidget permettant d'afficher une note de type video
 * \author Pauline Cuche/Simon Robain
 */

/**
 *\class videowidget
 * \brief Classe Interface Utilisateur assurant l'affichage d'une note Video
 */
class videowidget : public QWidget
{
    Q_OBJECT
    
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe videowidget
         *\param v : pointeur vers la Video concernée par le widget
         *\param parent : fenêtre mère du videowidget
         */
    explicit videowidget(Video* v ,QWidget *parent = 0);
    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe videowidget
         */
    ~videowidget();
    /*!
         *  \brief Setteur du titre de la Video
         *  \param titre : titre que l'on souhaite donner à la Video
         */
    void setTitre(const QString& titre);
    /*!
         *  \brief Setteur de la description de la Video
         *  \param desc : descriptif que l'on souhaite ajouter à la Video
         */
    void setDesc(const QString& desc);
    /*!
         *  \brief Setteur de la vidéo à mettre dans notre Video note
         *  \param chemin : chemin d'accès à la vidéo concernée
         */
    void setVideo(const QString& chemin);
private:
    Ui::videowidget *ui;
    Video* actu_video;/*!< Pointeur vers la Video affichée*/
    //QMediaPlayer* player;
    //QVideoWidget* film;
    //QMediaPlaylist* playlist;
    //bool enCoursdeLecture;



signals:
    /*!
         *  \brief Signal envoyant la nouvelle description rentrée par l'utilisateur du videowigdet
         *  \param desc : descriptif que l'on souhaite transmettre
         */
    void videoDescChanged(const QString&);
    /*!
         *  \brief Signal envoyant le nouveau titre rentré par l'utilisateur du videowigdet
         *  \param newTitre : nouveau titre que l'on souhaite donner à la Video
         *  \param oldTitre : ancien titre de la Video
         *  \param saved : booléen permettant de savoir si la video à déjà été sauvegardée
         */
    void videoTitreChanged(const QString&,const QString&, bool);

public slots :
    ///  \brief Slot permettant d'actualiser le titre
    void actuTitre();
    ///  \brief Slot permettant d'actualiser le descpriptif
    void actuDesc();


};

#endif // VIDEOWIDGET_H
