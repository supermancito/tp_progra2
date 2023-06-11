#include <iostream>

#include "juego.cpp"
using namespace std;
int main()
{

  char sim[7];
  jugador j1(1, sim), j2(1, sim);
  char num;
  cout << "Bienvenido a la batalla naval" << endl;
  cout << "Poner el modo de juego que desee" << endl;

  do
  {
    cout << "Poner 1 para j1 vs j2: " << endl;
    cout << "Poner 2 para j1 vs cpu: " << endl;
    cout << "Poner 0 para salir: " << endl;
    cin >> num;

    if (num != '1' && num != '0' && num != '2')
    {
      cout << "Colocar  los valores que aparecen en pantalla " << endl;
    }

  } while (num != '1' && num != '2' && num != '0');

  if (num == '1')
  {
    j1.gentamano();
    j1.construirTablero1();
    j2.construirTablero2(j1.getF(), j1.getC());
    cout << "Turno de colocar barcos del j1" << endl;
    j1.colocarbarco();
    cout << "Turno de colocar barcos del j2" << endl;
    j2.colocarbarco();
    do
    {
      cout << "TIRA JUGADOR 1" << endl;
      j2.tirarmisil();
      if (!j2.enPie())
      {
        cout << " Gano jugador 1" << endl;
        break;
      }
      cout << "TIRA JUGADOR 2" << endl;
      j1.tirarmisil();
      if (!j1.enPie())
      {
        cout << " Gano jugador 2" << endl;
        break;
      }
    } while (j1.enPie() && j2.enPie());
  }
  if (num == '2')
  {
    j1.gentamano();
    j1.construirTablero1();
    j2.construirTablero2(j1.getF(), j1.getC());
    cout << "Turno de colocar barcos del j1" << endl;
    j1.colocarbarco();
    cout << "Turno de colocar barcos del cpu" << endl;
    j2.colocarbarcoauto();
    do
    {
      cout << "TIRA JUGADOR 1" << endl;
      j2.tirarmisil();
      if (!j2.enPie())
      {
        cout << " Gano jugador 1" << endl;
        break;
      }
      cout << "TIRA EL CPU" << endl;
      j1.tirarmisilauto();
      if (!j1.enPie())
      {
        cout << " Gano jugador cpu" << endl;
        break;
      }
    } while (j1.enPie() && j2.enPie());
  }
  if (num == '0')
  {
    cout<<"--Gracias por jugar nuestro juego-- "<<endl;
    cout<<"'Ruben Blanco y Fabrizzio Castro: Futuros ing. Electronicos'";
  }
  


return 0;
}

// INICIO TABLEROS JUGADORES
// tablero t1(1, sim);tablero t2(1, sim);
//

/*j1.gentamano();
j1.construirTablero1();
j2.construirTablero2(j1.getF(), j1.getC());*/
// METODOS DE INTRODUCCION MANUAL
/*j1.colocarbarco();
j1.tirarmisil();
j2.colocarbarco();
j2.tirarmisil();*/
// METODOS AUOMATICOS
/*j1.colocarbarcoauto();
j1.tirarmisilauto();
j2.colocarbarcoauto();
j2.tirarmisilauto();*/
/*do
{
  cout << "TIRA JUGADOR 1" << endl;
  j2.tirarmisilauto();
  if (!j2.enPie())
  {
    cout << " Gano jugador 1" << endl;
    break;
  }
  cout << "TIRA JUGADOR 2" << endl;
  j1.tirarmisilauto();
  if (!j1.enPie())
  {
    cout << " Gano jugador 2" << endl;
    break;
  }
} while (j1.enPie() && j2.enPie());*/

// INICIO TABLEROS cpu

/*FORMA DE TABLEROS
t1.gentamano();
t1.construirTablero1();
t2.construirTablero2(t1.getF(),t1.getC());*/
/*MUESTO TABLEROS
cout<<endl;
cout<<"tablero 1 \n";
t1.mostrar();
cout<<"tablero 2 \n";
t2.mostrar();*/

// CREO FLOTAS
// t1.colocarbarco();
// PROBANDO COLOCAR RANDOM
// t2.colocarbarcoauto();

/* PRUEBO PANTALLAS CON TIRAR

t1.tirarmisil();
t1.tirarmisil();
t1.tirarmisil();
t1.mostrarPantalla();

PRUEBO PANTALLAS CON TIRAR Random
    t2.mostrarPantalla();
t2.tirarmisilauto();
t2.tirarmisilauto();
t2.tirarmisilauto();
t2.tirarmisilauto();
t2.tirarmisilauto();
t2.tirarmisilauto();
t2.tirarmisilauto();
t2.tirarmisilauto();
t2.tirarmisilauto();
t2.tirarmisilauto();
t2.tirarmisilauto();
t2.tirarmisilauto();

 */

/*
PRUEBA CON TABLERO

t.gentamaño();
t.construirTablero1();
t.mostrar();
t.colocarbarco();

t.mostrar();
t.tirarmisil();
t.tirarmisil();
t.tirarmisil();
*/
/*PRUEBA CON JUGADOR*/
// t.gentamano();
