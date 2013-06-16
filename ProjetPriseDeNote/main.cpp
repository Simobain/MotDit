#include "mainwindow.h"
#include <QApplication>
#include "note.h"
#include "article.h"
#include <iostream>
#include <time.h>
#include <sstream>
#include "notesmanager.h"
#include <QSettings>
#include "document.h"
#include "article.h"

/**
*@mainpage Rapport du Projet LO21 réalisé avec joie par Pauline Cuche et Simon Robain
*
*<h1>  Description de l'architecture du projet </h1>
*
*<h2> Note et ses heritages </h2>
*<p>
*Nous avons décidé de diviser tous les types de notes.
*La classe mère Note est une classe abstraite, elle est héritée par Article et Binary.
*La classe Binary est une classe abstraite, elle a été créé suite à de nombreux points communs entre les notes de types Audio, Video et Image.
*
*La classe Note possède une fonction getType virtuelle pure.
*Cette fonction est surchargé dans chacune des classes filles et retourne le type la Note.
*Cela permet de connaitre a tout instant le type d'un pointeur sur Note.
*
*
*</p>
*<h2>L'unique NotesManager </h2>
*<p>
*NotesManager est la classe qui gère les Note.
*Cette classe ne devant être instanciée qu'une seule fois nous avons utilisé le design pattern singleton.
*Ses fonctions permettent de créer ou supprimer des notes.
*La création se fait à l'aide des classes filles de NoteFactory.
*Pour appeler la classe factory adaptée nous utilisons une std::map.
*Ce type de container permet de retrouver à partir d'une clé une valeur.
*Dans notre cas les clés étaient le type de Note, et les valeurs un objet de la classe factory adaptée.
*Grâce à cette méthode lors de futures mises à jour de notre logiciel, nous pourrons ajouter d'autres types de Note
*sans avoir à modifier grandement notre architecture.
*</p>
*<p>
*Le NotesManager gèrent aussi l'espace de travail dans lequel l'utilisateur souhaite travailler.
*Pour stocker les notes nous avons choisi d'utiliser un QSet de Note.
*Cette QClasse nous a permis de parcourir facilement nos Note notamment grace à des iterateurs fournis par Qt.
*De plus un QSet évite les doublons.
*</p>
*<p>
*Le NoteManager permet également d'appeler les diverses fonctions d'exportation de nos Note via une std::map.
*</p>
*<p>
*Une fonction utile de notre manager consiste à retrouver une Note à partir de son id et/ou de son titre.
*</p>
*
*
*
*<h2> Les factories méthodes </h2>
*<p>
*Nous avons décidé d'utiliser le design pattern factory method pour instancier tous les objets hérités de la classe Note.
*L'avantage de cette technique consiste à pouvoir utiliser la même méthode NotesManager::creerNote pour instancier different type de Note.
*De plus, comme nous l'avons dit plus haut, la mise à jour (ajout de nouveau type de Note) est facilitée.
*</p>
*
*<h2> La stratégie export </h2>
*<p>
*Pour gérer l'exportation nous avons créer une classe abstraite ExportStrategy et 3 classes filles correspondant au type d'export désiré
*ici HTMLexport, LaTexExport et TextExport.
*Dans chacune de ses fonctions nous avons définis un ExportStrategy::header et un ExportStrategy::footer correspondant à l'entête et le pied de page nécessaire à chaque langage.
*Puis nous avons défini une fonction ExportStrategy::exportNote surchargée pour chaque type de Note.
*De cette façon, rajouter un type d'export est très simple. Il suffit simplement d'ajouter une nouvelle classe fille à ExportStrategy.
*Ainsi comme précédement le code est facile à maintenir en cas d'évoltution.
*</p>
*
*<h2> L'interface graphique MainWindow et ses widgets </h2>
*<p>
*Notre interface utilisateur s'inspire grandement de l'exemple proposé dans le sujet.
*Nous avons utilisé une MainWindow pour gérer l'ensemble des fonctionalités.
*
*Nous avons composé le MainWindow de :
*   <ul>
*   <li>une QListView recenssant toutes les Note chargées </li>
*   <li>un QTabWidget composé de 4 onglets correspondant à un mode edit, et des exports </li>
*   <li>une barre de menu donnant accès à toutes les fonctionnalités excepté l'edition </li>
*   </ul>
*
*
*Nous avons créé un type de widget hérité de QWidget par type de Note.
*De cette façon lors d'un clic sur une note d'un certain type nous ajoutons au layout de l'onglet edit un Widget du type correspondant.
*
*</p>
*
*<h1>Gestionnaire de Tags</h1>
*<p>
*Malheureusement nous n'avons pas eu le temps de réaliser le TagManager.
*Néanmoins voici comment nous aurions procédé pour gérer ce système.
*</p>
*<p>
*Tout d'abord nous aurions créé une classe Tag ayant pour attribut un nom, un booleen checked permettant de savoir si il est coché, et un QSet de Note contenant la liste des Note liées à ce Tag.
*Cette classe aurait des méthodes permettant d'ajouter ou de supprimer une Note dans son QSet et d'accéder/setter ses attributs.
*Ensuite nous aurions créé une classe TagManager similaire à NotesManager.
*Elle bénéficierait également d'un design pattern singleton, d'un QSet de Tag et de fonctions permettant de gérer les Tag.
*Comme par exemple: creerTag, supprimerTag, chargerTag  et d'une fonction addTag(Note* n, QString nomTag) et suppTag(Note* n, QString nomTag) qui cherche le Tag correspondant dans son QSet
*et qui ajoute la note dans le QSet du Tag a l'aide des méthodes de ce même Tag.
*
*Visuellement nous aurions ajouté à notre MainWindow une QList de CheckBox au dessus de notre QListView pour filtrer les Note à l'aide des Tag.
*Ainsi l'utilisateur aurait pu cocher les Tag correspondant à son choix et seules les Note tagguées auraient été affichées dans la QListView principale.
*
*</p>
*
*<h1>Evolutions Possibles </h1>
*<p>
*Dans le futur nous pourrions ajouter différentes fonctionnalités au logiciel MotDit :
*<ul>
*<li>Ajouter d'autre type hérité de Note
*<ul>
*   <li>un type Tableau permettant de faire un tableau de String</li>
*   <li>un type Todo permettant de creer une liste de tâche</li>
*   <li>un type Mail permettant de gerer des brouillons de mail</li>
*</ul>
*</li>
*
*<li>Ajouter d'autre type d'export et completer les exports
*<ul>
*   <li>un fichier css pour l'export html</li>
*   <li>un export PDF, SQL, XML, JSon...</li>
*</ul>
*</li>
*<li>Ajouter une corbeille afin d'eviter une suppression malencontreuse</li>
*</ul>
*<li>Ameliorer l'interface avec par exemple un systeme de glissé/déposé</li>
*<li>Développer une application mobile liant via une base de données les notes contenus sur l'ordinateur et le smartphone </li>
*</p>
*
*<h1>Conclusion</h1>
*
*Grâce à ce projet nous avons pu pratiquer des théories vues en cours.
*De plus, nous avons appris à utiliser Qt et sa documentation (où nous nous sommes perdus moulte fois :p)
*Ce fut la première fois que nous avions eu à gérer un projet de cette ampleur. Nous sommes fier que notre projet compile.
*Pour gérer les différentes versions de notre projet nous avons du apprendre à utiliser un gestionnaire de version (GIT).
*
*Bonne vidéo !
*
*/
int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    MainWindow w;

    w.show();
    return a.exec();
}
