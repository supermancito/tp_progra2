#include <iostream>
#include "juego.h"
using namespace std;
#pragma once

tablero::tablero(int longitud_, char simbolo_[7]) : barcos(longitud_, simbolo_){};

// construirTablero pone los puntos en los lugares del tablero
/*void tablero::gentamaño(){  cout << "Poner el tamaño del tablero:" << endl;
    cout << "fila: ";
    cin >> fil;
    cout << "columna: ";
    cin >> col;
    cout << endl;
    f = &fil;
    c = &col;}*/

void tablero::construirTablero()
{
    cout << "Poner el tamaño del tablero:" << endl;
    cout << "fila: ";
    cin >> fil;
    cout << "columna: ";
    cin >> col;
    cout << endl;
    f = &fil;
    c = &col;
    for (int i = 1; i < (*f + 1); i++)
    {
        for (int j = 1; j < (*c + 1); j++)
        {
            cas[i][j] = '.';
        }
    }
    /* for (int i = 1; i < (fil+1); i++)
     {
         for (int j = 1; j < (col+1); j++)
         {
             lug[i][j] = '.';
         }
     }*/
}
// Muestra el tablero en consola
void tablero::mostrar()
{
    cout << endl;
    cout << endl;
    for (int i = 1; i < (*f + 1); i++)
    {
        for (int j = 1; j < (*c + 1); j++)
        {
            cout << cas[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

// colocar barcos en un solo lugar
void tablero::colocarbarco()
{
    int fila, columna;
    char orientacion;
    cout << "-- COLOCAR FLOTA --" << endl;
    cout << "-- TODO LOS BARCOS SERAN COLOCADOS HACIA LA DERECHA O HACIA ABAJO DEL LUGAR INDICADO, DE SER POSIBLE --" << endl;

    for (int i = 0; i < 7; i++)
    {
        bool lugarvalido = true;
        bool fueraTablero = true;
        cout << "Colocar Barco numero " << i + 1 << endl;
        do
        {
            cout << "Indicar primero fila entre 1 y 9: ";
            cin >> fila;
            cout << "Indicar ahora, columna entre 1 y 9: ";
            cin >> columna;
            if (fila < 1 || *f < fila)
            {
                cout << "Colocar valores validos para fila" << endl;
            }
            if (columna < 1 || *c < columna)
            {
                cout << "Colocar valores validos para columna" << endl;
            }
        } while (fila < 1 || *f < fila || columna < 1 || *f < columna);

        barcos::setSimbolo(i);
        barcos::setlongitud();
        cout << "Indicar Orientacion: vertical (v) y horizontal (h)" << endl;
        cin >> orientacion;
        while (orientacion != 'v' && orientacion != 'h')
        {
            cout << "Coloque un simbolo valido vertical (v) y horizontal(h) " << endl;
            cin >> orientacion;
        }
        if (orientacion == 'h')
        {
            for (int j = columna; j < columna + barcos::getlongitud(); j++)
            {
                if (j >= *c)
                {
                    fueraTablero = false;
                    break;
                }
                if (cas[fila][j] != '.')
                {
                    lugarvalido = false;
                }
            }
            if (lugarvalido && fueraTablero)
            {
                for (int j = columna; j < columna + barcos::getlongitud(); j++)
                {
                    cas[fila][j] = barcos::getsimbolo();
                }
            }
            else
            {
                if (lugarvalido == false)
                {
                    cout << "Lugares en el tabler ocupados, intente nuevamente" << endl;
                    i--;
                }

                if (fueraTablero == false)
                {
                    cout << "El barco se sale del espacio de juego" << endl;
                    i--;
                }
            }
        }
        if (orientacion == 'v')
        {
            for (int j = fila; j < fila + barcos::getlongitud(); j++)
            {
                if (j >= *f)
                {
                    fueraTablero = false;
                    break;
                }
                if (cas[j][columna] != '.')
                {
                    lugarvalido = false;
                }
            }
            if (lugarvalido && fueraTablero)
            {
                for (int j = fila; j < fila + barcos::getlongitud(); j++)
                {
                    cas[j][columna] = barcos::getsimbolo();
                }
            }
            else
            {
                if (lugarvalido == false)
                {
                    cout << "Lugares en el tabler ocupados, intente nuevamente" << endl;
                    i--;
                }

                if (fueraTablero == false)
                {
                    cout << "El barco se sale del espacio de juego" << endl;
                    i--;
                }
            }
        }
        mostrar();
    }
}
void tablero::tirarmisil()
{
    int fila, columna;
    int k = 1;
    do
    {
        if (k == 0)
            cout << "YA UTILIZASTE ESE CASILLERO O ESTA FUERA DEL MAPA" << endl;
        cout << "colocar coordenadas de misil: " << endl;
        cout << "fila: ";
        cin >> fila;
        cout << "  columna: ";
        cin >> columna;
        k = 0;
    } while (cas[fila][columna] == 'x' || cas[fila][columna] == 48 || fila > *f || columna > *c);

    bool barcoHundido = true;
    // Estto dice si le pegaste o no ||  || cas[fila][columna] == 's' || cas[fila][columna] == 'B' || cas[fila][columna] == 'V' || cas[fila][columna] == 'f'
    if (cas[fila][columna] == 'L')
    {
        cas[fila][columna] = 'x';
        cout << "ACERTASTE" << endl;
        for (int i = 1; i < (*f + 1); i++) // reocorre filas

        {
            for (int j = 1; j < (*c + 1); j++) // recorre columnas
            {
                if (cas[i][j] == 'L')
                {
                    cout << "el barco de 1 sigue en pie" << endl;
                    i = *f;
                    barcoHundido = false;
                    break;
                }
            }
        }
        if (barcoHundido)
        {
            cout << "Hundiste el barco de 1 casillero " << endl;
        }
    }
    if (cas[fila][columna] == 'S')
    {
        cas[fila][columna] = 'x';
        cout << "ACERTASTE" << endl;
        for (int i = 1; i < (*f + 1); i++) // reocorre filas

        {
            for (int j = 1; j < (*c + 1); j++) // recorre columnas
            {
                if (cas[i][j] == 'S')
                {
                    cout << "el barco de 2 casilleros sigue en pie" << endl;
                    i = *f;
                    barcoHundido = false;
                    break;
                }
            }
        }
        if (barcoHundido)
        {
            cout << "Hundiste el barco de 2 casillero " << endl;
        }
    }
    if (cas[fila][columna] == 's')
    {
        cas[fila][columna] = 'x';
        cout << "ACERTASTE" << endl;
        for (int i = 1; i < (*f + 1); i++) // reocorre filas

        {
            for (int j = 1; j < (*c + 1); j++) // recorre columnas
            {
                if (cas[i][j] == 's')
                {
                    cout << "el barco de 2 casilleros sigue en pie" << endl;
                    i = *f;
                    barcoHundido = false;
                    break;
                }
            }
        }
        if (barcoHundido)
        {
            cout << "Hundiste el barco de 2  casillero " << endl;
        }
    }
    if (cas[fila][columna] == 'B')
    {
        cas[fila][columna] = 'x';
        cout << "ACERTASTE" << endl;
        for (int i = 1; i < (*f + 1); i++) // reocorre filas

        {
            for (int j = 1; j < (*c + 1); j++) // recorre columnas
            {
                if (cas[i][j] == 'B')
                {
                    cout << "el barco de 3 casilleros sigue en pie" << endl;
                    i = *f;
                    barcoHundido = false;
                    break;
                }
            }
        }
        if (barcoHundido)
        {
            cout << "Hundiste el barco de 3  casillero " << endl;
        }
    }
    if (cas[fila][columna] == 'b')
    {
        cas[fila][columna] = 'x';
        cout << "ACERTASTE" << endl;
        for (int i = 1; i < (*f + 1); i++) // reocorre filas

        {
            for (int j = 1; j < (*c + 1); j++) // recorre columnas
            {
                if (cas[i][j] == 'b')
                {
                    cout << "el barco de 3 casillero sigue en pie" << endl;
                    i = *f;
                    barcoHundido = false;
                    break;
                }
            }
        }
        if (barcoHundido)
        {
            cout << "Hundiste el barco de 3  casillero " << endl;
        }
    }
    if (cas[fila][columna] == 'V')
    {
        cas[fila][columna] = 'x';
        cout << "ACERTASTE" << endl;
        for (int i = 1; i < (*f + 1); i++) // reocorre filas

        {
            for (int j = 1; j < (*c + 1); j++) // recorre columnas
            {
                if (cas[i][j] == 'V')
                {
                    cout << "el barco de 3 casilleros sigue en pie" << endl;
                    i = *f;
                    barcoHundido = false;
                    break;
                }
            }
        }
        if (barcoHundido)
        {
            cout << "Hundiste el barco de 3 casillero " << endl;
        }
    }
    if (cas[fila][columna] == 'P')
    {
        cas[fila][columna] = 'x';
        cout << "ACERTASTE" << endl;
        for (int i = 1; i < (*f + 1); i++) // reocorre filas

        {
            for (int j = 1; j < (*c + 1); j++) // recorre columnas
            {
                if (cas[i][j] == 'P')
                {
                    cout << "el barco de 4 casillas sigue en pie" << endl;
                    i = *f;
                    barcoHundido = false;
                    break;
                }
            }
        }
        if (barcoHundido)
        {
            cout << "Hundiste el barco de 4 casillero " << endl;
        }
    }
    if (cas[fila][columna] == '.')
    {
        cas[fila][columna] = 48;
        cout << "En fila: " << fila << " \n Columna:" << columna << "\n AGUA";
    }
    // esto revisa el tablero en busca de mas partes del mismo barco}
    bool barcoPie = true;

    tablero::mostrar();
}