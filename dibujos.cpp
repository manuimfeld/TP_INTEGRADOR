#include <iostream>
#include "dibujos.h"
#include "rlutil.h"

using namespace std;



/// DIBUJAR LOS CUADRADOS DE LOS DADOS

void dibujarCuadrado (int posx , int posy){
    rlutil::setColor(rlutil::WHITE);
    for (int x=posx+1 ; x<=posx+7 ; x++){
        for (int y=posy ; y<=posy+2 ; y++){
            rlutil::locate(x , y);
            cout << (char) 219;
        }
    }
}
void dibujarDados(int numero, int posx, int posy){
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);
    switch(numero){
    case 1:
            rlutil::locate(posx+4 , posy+1);
            cout << (char) 254;
        break;

        case 2:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
        break;

        case 3:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+4 , posy+1);
            cout << (char) 254;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
        break;

        case 4:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+6 , posy);
            cout << (char) 220;
            rlutil::locate(posx+2 , posy+2);
            cout << (char) 223;
        break;

        case 5:
            rlutil::locate(posx+2 , posy);
            cout << (char) 220;
            rlutil::locate(posx+6 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+6 , posy);
            cout << (char) 220;
            rlutil::locate(posx+2 , posy+2);
            cout << (char) 223;
            rlutil::locate(posx+4 , posy+1);
            cout << (char) 254;
        break;

    }

    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);

}
