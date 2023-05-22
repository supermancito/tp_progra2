#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

const int TAM_TABLERO = 5;
const char VACIO = '-';
const char BARCO = 'B';
const char ACIERTO = 'X';
const char FALLO = 'O';

class Tablero {
public:
    Tablero() {
        tablero.resize(TAM_TABLERO, std::vector<char>(TAM_TABLERO, VACIO));
    }

    void imprimir() const {
        for (int i = 0; i < TAM_TABLERO; ++i) {
            for (int j = 0; j < TAM_TABLERO; ++j) {
                std::cout << tablero[i][j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    bool esCoordenadaValida(int fila, int columna) const {
        return fila >= 0 && fila < TAM_TABLERO && columna >= 0 && columna < TAM_TABLERO;
    }

    void colocarBarcos(int numBarcos) {
        for (int i = 0; i < numBarcos; ++i) {
            int fila, columna;
            do {
                fila = rand() % TAM_TABLERO;
                columna = rand() % TAM_TABLERO;
            } while (tablero[fila][columna] == BARCO);
            tablero[fila][columna] = BARCO;
        }
    }

    bool esAcierto(int fila, int columna) const {
        return tablero[fila][columna] == BARCO;
    }

    void actualizar(int fila, int columna, char estado) {
        tablero[fila][columna] = estado;
    }

private:
    std::vector<std::vector<char>> tablero;
};

class JuegoBatallaNaval {
public:
    JuegoBatallaNaval() {
        tableroJugador = Tablero();
        tableroCPU = Tablero();
        numBarcos = 5;
    }

    void jugar() {
        tableroCPU.colocarBarcos(numBarcos);
        int numIntentos = 0;

        while (numBarcos > 0) {
            std::cout << "Tablero del jugador:" << std::endl;
            tableroJugador.imprimir();

            int fila, columna;
            std::cout << "Ingrese las coordenadas de disparo (fila columna): ";
            std::cin >> fila >> columna;

            if (!tableroJugador.esCoordenadaValida(fila, columna)) {
                std::cout << "Coordenadas inválidas. Inténtelo nuevamente." << std::endl;
                continue;
            }

            if (tableroJugador.esAcierto(fila, columna)) {
                std::cout << "Ya has disparado en esas coordenadas. Inténtelo nuevamente." << std::endl;
                continue;
            }

            ++numIntentos;

            if (tableroCPU.esAcierto(fila, columna)) {
                std::cout << "¡Has acertado a un barco!" << std::endl;
                tableroJugador.actualizar(fila, columna, ACIERTO);
                tableroCPU.actualizar(fila, columna, ACIERTO);
                --numBarcos;
            } else {
                std::cout << "¡Has fallado el disparo!" << std::endl;
                tableroJugador.actualizar(fila, columna, FALLO);
            }
        }

        std::cout << "¡Has hundido todos los barcos en " << numIntentos << " intentos!" << std::endl;
    }

private:
    Tablero tableroJugador;
    Tablero tableroCPU;
    int numBarcos;
};

int main() {
    srand(time(NULL));

    JuegoBatallaNaval juego;
    juego.jugar();

    return 0;
}
