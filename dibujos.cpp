#include <iostream>
#include "dibujos.h"
#include "rlutil.h"

using namespace std;

/// DIBUJAR LOS CUADRADOS DE LOS DADOS

void dibujarCuadrado(int posx, int posy)
{

    rlutil::setColor(rlutil::WHITE);

    rlutil::setColor(rlutil::WHITE);

    for (int x = posx; x < posx + 9; x++) // Ancho de 9
    {
        for (int y = posy; y < posy + 5; y++) // Altura de 5
        {
            rlutil::locate(x, y);
            cout << (char)219;
        }
    }
    rlutil::resetColor();
}

void dibujarDados(int numero, int posx, int posy, bool fueBloqueado)
{
    dibujarCuadrado(posx, posy); // Dibuja el cuadrado del dado

    // Seteamos el color de los puntos del dado
    if (fueBloqueado)
    {
        rlutil::setColor(rlutil::RED);
        rlutil::setBackgroundColor(rlutil::WHITE);
    }
    else
    {
        rlutil::setColor(rlutil::BLACK);
        rlutil::setBackgroundColor(rlutil::WHITE);
    }

    // Dibujamos los puntitos en los dados
    switch (numero)
    {
    case 1:
        rlutil::locate(posx + 4, posy + 2);
        cout << (char)254;
        break;

    case 2:
        rlutil::locate(posx + 2, posy + 1);
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 3);
        cout << (char)254;
        break;

    case 3:
        rlutil::locate(posx + 2, posy + 1);
        cout << (char)254;
        rlutil::locate(posx + 4, posy + 2);
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 3);
        cout << (char)254;
        break;

    case 4:
        rlutil::locate(posx + 2, posy + 1);
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 1);
        cout << (char)254;
        rlutil::locate(posx + 2, posy + 3);
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 3);
        cout << (char)254;
        break;

    case 5:
        rlutil::locate(posx + 2, posy + 1);
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 1);
        cout << (char)254;
        rlutil::locate(posx + 4, posy + 2);
        cout << (char)254;
        rlutil::locate(posx + 2, posy + 3);
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 3);
        cout << (char)254;
        break;

    case 6:
        rlutil::locate(posx + 2, posy + 1);
        cout << (char)254;
        rlutil::locate(posx + 2, posy + 2);
        cout << (char)254;
        rlutil::locate(posx + 2, posy + 3);
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 1);
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 2);
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 3);
        cout << (char)254;
        break;
    }

    // Reseteamos los colores después de dibujar el dado
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
}