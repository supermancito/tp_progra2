#include <iostream>
#include "juego.h"
/*void tablero::victoria(){
for (auto i:cas) {
    int j = sizeof(cas) / sizeof(int);
    if ( i == 0){
    j--;
    }
    if (j ==0){
        cout << "El jugador " <<" a ganado la partida";
    }
}
}*/
void tablero::asignar_casilleros(){
    for (int i = 1; i < 10; i++)
    {
        cout<<"0"<<" ";
        for (int j = 1; j < 10; j++)
        {
            cout<<" 0 ";
        }
        cout<< endl;
        
    }
    

}