#include <iostream>
#include "juego.h"
#include <stdexcept>
#include <limits>
using namespace std;

tablero::tablero(int longitud_, char simbolo_[7]) : barcos(longitud_, simbolo_){};

// construirTablero1 pone los puntos en los lugares del tablero
void tablero::gentamano()
{ /*

     do {
         cout << "Poner el tamaño del tablero:" << endl;
         cout << "fila: ";
         cin >> fil;
         try {
             if (cin.fail()) {
                 throw runtime_error("Pusiste una letra en vez de un numero");


             }
         } catch (const exception& e) {
             cout << e.what() << '\n';
             cin.clear(); // Clear error state
             continue; // Restart the loop

         }

         cout << "columna: ";
         cin >> col;
         cout << endl;
         f = &fil;
         c = &col;

         if (*f < 9 || *c < 9) {
             cout << "El tamaño tiene que ser un numero mayor a 8." << endl;
         }
     } while (*f < 9 || *c < 9 || cin.fail());*/
    // Additional checks can be added to ensure that both fila and columna are integers greater than 8.
    bool exceptionOccurred = false;

    do
    {
        cout << "Poner el tamaño del tablero:" << endl;
        cout << "fila: ";
        cin >> fil;
        cout << "columna: ";
        cin >> col;
        cout << endl;
        f = &fil;
        c = &col;
        try
        {
            if (cin.fail())
            {
                
                cin.clear(); // Clear error state
                cin.ignore();
                throw runtime_error("Pusiste una letra en vez de un numero");
                // Restart the loop
                

            }
        }
            catch (exception e)
            {
               //cout << e.what() << '\n';
                cin.clear(); // Clear error state
                cout <<"Pusiste una letra en vez de un numero" << "\n";
                cin.ignore();
                continue;
            }
    }while ( *f < 9 || *c < 9);
}
void tablero::construirTablero1()
{

    for (int i = 1; i < (*f + 1); i++)
    {
        for (int j = 1; j < (*c + 1); j++)
        {
            cas[i][j] = '.';
        }
    }
    cout << "tablero1 de " << *f << " x " << *c << " creado\n";
    /* for (int i = 1; i < (fil+1); i++)
     {
         for (int j = 1; j < (col+1); j++)
         {
             lug[i][j] = '.';
         }
     }*/
}
void tablero::construirTablero2(int *fil, int *col)
{
    f = fil;
    c = col;
    for (int i = 1; i < (*f + 1); i++)
    {
        for (int j = 1; j < (*c + 1); j++)
        {
            cas[i][j] = '.';
        }
    }
    cout << "tablero 2 de " << *fil << " x " << *col << " creado\n";
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
    for (int i = 0; i < (*f + 1); i++)
    {
        if (i == 0)
        {
            cout << "   ";
        }
        else
        {
            if (i < 10)
            {
                cout << i << "  ";
            }

            else
                cout << i << " ";
        }

        for (int j = 1; j < (*c + 1); j++)
        {
            if (i == 0 && j < 9)
            {
                cout << j << "";
            }
            if (i == 0 && 8 < j)
            {
                cout << j << " ";
            }

            else
                cout << cas[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}
// Muestra el tablero con barcos ocultos o acertados en consola 'L', 'S','s', 'B', 'b', 'V','P'
void tablero::mostrarPantalla()
{
    cout << endl;
    cout << endl;
    for (int i = 0; i < (*f + 1); i++)
    {
        if (i == 0)
        {
            cout << "   ";
        }
        else
        {
            if (i < 10)
            {
                cout << i << "  ";
            }

            else
                cout << i << " ";
        }

        for (int j = 1; j < (*c + 1); j++)
        {
            if (i == 0)
            {
                if (j < 9)
                {
                    cout << j << "  ";
                }
                if (8 < j)
                {
                    cout << j << " ";
                }
            }
            else
            {
                if (cas[i][j] == 'L' || cas[i][j] == 'S' || cas[i][j] == 's' || cas[i][j] == 'B' || cas[i][j] == 'b' || cas[i][j] == 'V' || cas[i][j] == 'P')
                {
                    cout << '.' << "  ";
                }
                else
                {
                    cout << cas[i][j] << "  ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

// COLOCA BARCOS MANUALMENTE
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
            cout << "Indicar primero fila entre 1 y " << *f << ":";
            cin >> fila;
            cout << "Indicar ahora, columna entre " << *c << ":";
            cin >> columna;

            try
        {
            if (cin.fail())
            {
                
                cin.clear(); // Clear error state
                cin.ignore();
                throw runtime_error("Pusiste una letra en vez de un numero");
                // Restart the loop
                

            }
        }
            catch (exception e)
            {
               //cout << e.what() << '\n';
                cin.clear(); // Clear error state
                cout <<"Pusiste una letra en vez de un numero" << "\n";
                cin.ignore();
                continue;
            }

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
                    cout << "Lugares en el tablero ocupados, intente nuevamente" << endl;
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

// COLOCA BARCOS AUTOMATICAMENTE
void tablero::colocarbarcoauto()
{
    srand(time(0));
    int fila, columna;
    char orientacion;
    cout << "-- COLOCAR FLOTA --" << endl;
    cout << "-- TODO LOS BARCOS SERAN COLOCADOS HACIA LA DERECHA O HACIA ABAJO DEL LUGAR INDICADO, DE SER POSIBLE --" << endl;

    for (int i = 0; i < 7; i++)
    {
        bool lugarvalido = true;
        bool fueraTablero = true;
        do
        { // SELECCION ALEATORIA DE FILA Y COLUMNA, DENTRO DE LOS VALORES DEL TABLERO
            fila = 1 + (rand() % *f);
            columna = 1 + (rand() % *c);
            // ESTA SECCION QUEDA SOLO A MODO DE CONTROL DE LOS VALORES AUTOGENERADOS
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
        // cout << "Indicar Orientacion: vertical (v) y horizontal (h)" << endl;
        // cin >> orientacion;
        int selOr = 1 + rand() % 2; // valor aleatorio entre 1 y 2
        if (selOr == 1)
            orientacion = 'v';
        else
            orientacion = 'h';
        if (orientacion != 'v' && orientacion != 'h')
        {
            cout << "el selOr no funciona" << endl;
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
                if (lugarvalido == false || fueraTablero == false)
                {
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
                if (lugarvalido == false || fueraTablero == false)
                {
                    i--;
                }
            }
        }
        mostrar();
    }
}
// pone las cordenadas del misil y dice si acertaste o no
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
         try
        {
            if (cin.fail())
            {
                
                cin.clear(); // Clear error state
                cin.ignore();
                throw runtime_error("Pusiste una letra en vez de un numero");
                // Restart the loop
                

            }
        }
            catch (exception e)
            {
               //cout << e.what() << '\n';
                cin.clear(); // Clear error state
                cout <<"DEBE COLOCAR SOLO NUMEROS DENTRO DE EL TABLERO" << "\n";
                cin.ignore();
                continue;
            }
        k = 0;
        // falta poner que si pone 0, 0 no tire error SOLUCIONADO
    } while (cas[fila][columna] == 'x' || cas[fila][columna] == 48 || fila > *f || columna > *c || fila == 0 || columna == 0);

    bool barcoHundido = true;
    // Estto dice si le pegaste o no ||  || cas[fila][columna] == 's' || cas[fila][columna] == 'B' || cas[fila][columna] == 'V' || cas[fila][columna] == 'f'
    if (cas[fila][columna] == 'L')
    {
        cas[fila][columna] = 'x';
        cout << "ACERTO JUGADOR " << endl;
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
        cout << "ACERTO JUGADOR " << endl;
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
        cout << "ACERTO JUGADOR " << endl;
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
        cout << "ACERTO JUGADOR " << endl;
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
        cout << "ACERTO JUGADOR " << endl;
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
        cout << "ACERTO JUGADOR " << endl;
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
        cout << "ACERTO JUGADOR " << endl;
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

    tablero::mostrarPantalla();
}
void tablero::tirarmisilauto()
{
    int fila, columna;
    int k = 1;
    srand(time(0));
    do
    {

        // SELECCION ALEATORIA DE FILA Y COLUMNA, DENTRO DE LOS VALORES DEL TABLERO
        fila = 1 + (rand() % *f);
        columna = 1 + (rand() % *c);
    } while (cas[fila][columna] == 'x' || cas[fila][columna] == 48 || fila > *f || columna > *c);

    bool barcoHundido = true;
    // Estto dice si le pegaste o no ||  || cas[fila][columna] == 's' || cas[fila][columna] == 'B' || cas[fila][columna] == 'V' || cas[fila][columna] == 'f'
    if (cas[fila][columna] == 'L')
    {
        cas[fila][columna] = 'x';
        cout << "ACERTO CPU  " << endl;
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
        cout << "ACERTO CPU  " << endl;
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
        cout << "ACERTO CPU  " << endl;
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
        cout << "ACERTO CPU  " << endl;
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
        cout << "ACERTO CPU  " << endl;
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
        cout << "ACERTO CPU  " << endl;
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
        cout << "ACERTO CPU  " << endl;
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

    tablero::mostrarPantalla();
}

tablero::tablero() {}

int *tablero::getF()
{
    return f;
}

int *tablero::getC()
{
    return c;
}
// Esto busca algun barco sino encuentra se termino el juego
bool tablero::enPie()
{

    for (int i = 1; i < *f; i++)
    {
        for (int j = 1; j < *c; j++)
        {
            if (cas[i][j] == 'P' || cas[i][j] == 'V' || cas[i][j] == 'b' || cas[i][j] == 'B' || cas[i][j] == 's' || cas[i][j] == 'S' || cas[i][j] == 'L')
            {
                i = *f;
                return true;
                break;
            }
        }
    }
    return false;
}

jugador::jugador(int longitud, char *simbolo) : tablero(longitud, simbolo) {}
