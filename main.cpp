#include <iostream>
#include "juego.cpp"
#include "juego.h"
using namespace std;
int main(){
    char sim[7];
   tablero t(1, sim);
   jugador j1(1,sim);
   jugador j2(1,sim);

   /*
   PRUEBA CON TABLERO
   
   t.gentamaño();
   t.construirTablero();
   t.mostrar();
   t.colocarbarco();
   
   t.mostrar();
   t.tirarmisil();
   t.tirarmisil();
   t.tirarmisil();
*/
/*PRUEBA CON JUGADOR*/
   t.gentamano();
j1.jconstruirTablero();
j2.jconstruirTablero();
  
    return 0;
}