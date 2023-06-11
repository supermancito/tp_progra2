#include <iostream>
#pragma once
using namespace std;
class barcos
{
    private:
      int longitud;
      char simbolo[7] = {'L', 'S','s', 'B', 'b', 'V','P'};
      char simboloBarco;

    public:
      barcos(int longitud_, char simbolo_[7])
      {
        longitud = longitud_;
        simbolo[7] = simbolo_[7];
      };
      int setlongitud()
      {
        char sim = getsimbolo();
        if (sim == 'L') longitud = 1;
        if (sim =='S') longitud = 2;
        if (sim =='s') longitud = 2;
        if (sim == 'B') longitud = 3;
        if (sim == 'b') longitud = 3;
        if (sim == 'v') longitud = 3;
        if (sim == 'P') longitud = 4;
      };
      int getlongitud() { return longitud; };
      void setSimbolo(int i ){

        simboloBarco = simbolo[i];

      }
      char getsimbolo( )
      {
        return simboloBarco;
      };
};
class tablero : public barcos
{
private:
    int *f, *c;
    int fil = 0, col = 0;
    char cas[1000][1000];
  
public:
  tablero(int longitud_, char simbolo_[7]);
  
  void gentamano();

  void construirTablero();
  void colocarbarco();
  void mostrar();
  void tirarmisil();
};
class jugador{
  private:
  tablero tab;
  public:
  jugador(int longitud_, char simbolo_[7]):tab(longitud_,simbolo_){
    
  };
  tablero jgetTablero(){
    return tab;
  }
  void jconstruirTablero(){
    tab.construirTablero();
  }
  void jcolocarbarco(){
    tab.colocarbarco();
  }
  void jmostrar(){
    tab.mostrar();
  }
  void jtirarmisil(tablero tab_){
    tab_.tirarmisil();

  }
};

/*  
j1.jtirarmisil(j2.jgetablero())

j1.jtablero();
j2.jtablero();
*/