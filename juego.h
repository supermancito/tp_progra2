#include <iostream>

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
      }

    barcos() {};
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
    char cas[100][100];
  
public:
    int *getF() ;

    int *getC() ;

    tablero();
    tablero(int longitud_, char simbolo_[7]);


    void gentamano();

    void construirTablero1();
    void construirTablero2(int* fil, int* col);
      void colocarbarco();
      void mostrar(); // pantallas con barcos
      void tirarmisil();

    void mostrarPantalla(); // pantalla sin barcos

    void colocarbarcoauto();

    void tirarmisilauto();
    bool enPie();
};

class jugador : public tablero {
private:
public:
    jugador(int longitud, char *simbolo);
};
    /*
    tablero jgetTablero(){
    return jt;
}

void jconstruirjtlero(){
  jt.construirTablero1();
}
void jcolocarbarco(){
  jt.colocarbarco();
}
void jmostrar(){
  jt.mostrar();
}
void jtirarmisil(tablero tab_){
  jt_.tirarmisil();

}
};
*/
/*
j1.jtirarmisil(j2.jgetablero())

j1.jtablero();
j2.jtablero();
*/