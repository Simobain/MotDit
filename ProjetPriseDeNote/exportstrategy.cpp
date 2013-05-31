#include "exportstrategy.h"

ExportStrategy::ExportStrategy()
{
}


QMap<QString, ExportStrategy*>* ExportStrategy:: getExportStrategy()//A comprendre bien comment cela fonctionne
{
   QMap<QString, ExportStrategy*>* strategies=new QMap<QString, ExportStrategy*>;
   strategies->insert("html",new htmlexport);
   strategies->insert("laTex",new latexexport);
   strategies->insert("texte", new texteexport);

   return strategies;

}
