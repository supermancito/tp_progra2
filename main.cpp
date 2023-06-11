#include <iostream>
#include "juego.cpp"
#include "juego.h"
using namespace std;
int main(){
    char sim[7];
   tablero t(1, sim);
   t.construirTablero();
   t.mostrar();
   t.colocarbarco();
   
   t.mostrar();
   t.tirarmisil();
   t.tirarmisil();
   t.tirarmisil();

   /*1_ j vsj o 2_ j vs cpu
   t.gentamaño();
   j.generar tablero*/
    return 0;
}