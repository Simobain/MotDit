#include "latexexport.h"

LaTexExport::LaTexExport()
{
}
QString LaTexExport::header(Note* n)
{
    QString head="\documentclass[a4paper,11pt]{report}\n";
            head+="\\usepackage{graphicx} \n";
            head+="\\usepackage[french]{babel} \n";
            head+="\\usepackage[latin1]{inputenc}\n";
            head+="\\usepackage[T1]{fontenc}\n";
            head+="\\begin{document}\n";

    return head;
}

QString LaTexExport::footer(Note* n)
{
    return "\end{document}";
}
QString LaTexExport::exportNote(Document* d , unsigned int titreLvl)
{
    return"";
}
QString LaTexExport::exportNote(Article* a , unsigned int titreLvl)
{
    QString texte="\chapter{"+a->getTitre()+"}\n";
    texte=texte+a->getTexte()+"\n";

    return texte;
}
QString LaTexExport::exportNote(Video* v , unsigned int titreLvl){return"";}
QString LaTexExport::exportNote(Audio* a , unsigned int titreLvl){return"";}
QString LaTexExport::exportNote(Image* i , unsigned int titreLvl){return"";}
