#include "binary.h"
#include "exportstrategy.h"

Binary::Binary():Note(), description(""), chemin(""){}

void Binary:: setDescription(const QString& d){
    description=d;
}
void Binary::setChemin(const QString& c){
    chemin=c;
}
