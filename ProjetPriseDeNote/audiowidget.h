#ifndef AUDIOWIDGET_H
#define AUDIOWIDGET_H

#include <QWidget>
#include "audio.h"
#include <QMediaPlayer>

namespace Ui {
class audiowidget;
}

/*!
 * \file audiowidget.h
 * \brief Classe AudioWidget permettant d'afficher une note de type audio
 * \author Pauline Cuche/Simon Robain
 */
/**
 *\class AudioWidget
 * \brief Classe Interface Utilisateur assurant l'affichage d'un audio
 */
class audiowidget : public QWidget
{
    Q_OBJECT
    
public:
    /*!
         *  \brief Constructeur
         *
         *  Constructeur de la classe ArticleWidget
         *\param a : pointeur vers l'audio concerné par le widget
         *\param parent : fenêtre mère de l'AudioWidget
         */
    explicit audiowidget(Audio* a, QWidget *parent = 0);
    /*!
         *  \brief Destructeur
         *
         *  Destructeur de la classe AudioWidget
         */
    ~audiowidget();
    /*!
         *  \brief Setteur du titre de l'audio
         *  \param titre : titre que l'on souhaite donner à l'audio
         */
    void setTitre(const QString& titre);
    /*!
         *  \brief Setteur de la description de l'audio
         *  \param desc : descriptif que l'on souhaite ajouter à l'audio
         */
    void setDesc(const QString& desc);
    /*!
         *  \brief Setteur de la musique à mettre dans notre note
         *  \param chemin : chemin d'accès à le musique concernée
         */
    void setMusique(const QString& chemin);

private:
    Ui::audiowidget *ui;
    Audio* actu_audio; /*!< Pointeur vers l'audio affiché*/
    QMediaPlayer* player; /*!< Pointeur vers le player*/
    bool enCoursdeLecture;
signals:
    /*!
         *  \brief Signal envoyant la nouvelle description rentrée par l'utilisateur de l'AudioWidget
         *  \param desc : descriptif que l'on souhaite transmettre
         */
    void audioDescChanged(const QString&);
    /*!
         *  \brief Signal envoyant le nouveau titre rentré par l'utilisateur de l'AudioWidget
         *  \param newTitre : nouveau titre que l'on souhaite donner à l'audio
         *  \param oldTitre : ancien titre de l'audio
         *  \param saved : booléen permettant de savoir si l'audio à déjà été sauvegardé
         */
    void audioTitreChanged(const QString&,const QString&, bool);

public slots :
    ///  \brief Slot permettant d'actualiser le titre
    void actuTitre();
    ///  \brief Slot permettant d'actualiser le descpriptif
    void actuDesc();
    /// \brief Slot permettant de mettre en pause la musique lorsqu'elle est en cours de lecture et de la jouée dans le cas contraire
    void playPause();

};

#endif // AUDIOWIDGET_H
