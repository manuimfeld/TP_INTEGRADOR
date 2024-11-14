#include <iostream>
#include "dibujos.h"
#include "rlutil.h"

using namespace std;

/// DIBUJAR LOS CUADRADOS DE LOS DADOS

void dibujarCuadrado(int posx, int posy)
{
    rlutil::setColor(rlutil::WHITE);
    for (int x = posx; x <= posx + 7; x++)
    {
        for (int y = posy; y <= posy + 3; y++)
        {
            rlutil::locate(x, y);
            cout << (char)219;
        }
    }
}

void dibujarDados(int numero, int posx, int posy)
{
    dibujarCuadrado(posx, posy); // Dibuja el cuadrado del dado

    // Configura el color de los puntos
    rlutil::setColor(rlutil::BLACK);
    rlutil::setBackgroundColor(rlutil::WHITE);

    // Dibuja los puntos del dado según el número
    switch (numero)
    {
    case 1:
        // Punto central
        rlutil::locate(posx + 4, posy + 2);
        cout << (char)254;
        break;

    case 2:
        // Esquinas opuestas
        rlutil::locate(posx + 2, posy + 1); // Esquina superior izquierda
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 3); // Esquina inferior derecha
        cout << (char)254;
        break;

    case 3:
        // Dos esquinas y el centro
        rlutil::locate(posx + 2, posy + 1); // Esquina superior izquierda
        cout << (char)254;
        rlutil::locate(posx + 4, posy + 2); // Centro
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 3); // Esquina inferior derecha
        cout << (char)254;
        break;

    case 4:
        // Cuatro esquinas
        rlutil::locate(posx + 2, posy + 1); // Esquina superior izquierda
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 1); // Esquina superior derecha
        cout << (char)254;
        rlutil::locate(posx + 2, posy + 3); // Esquina inferior izquierda
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 3); // Esquina inferior derecha
        cout << (char)254;
        break;

    case 5:
        // Cuatro esquinas y el centro
        rlutil::locate(posx + 2, posy + 1); // Esquina superior izquierda
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 1); // Esquina superior derecha
        cout << (char)254;
        rlutil::locate(posx + 4, posy + 2); // Centro
        cout << (char)254;
        rlutil::locate(posx + 2, posy + 3); // Esquina inferior izquierda
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 3); // Esquina inferior derecha
        cout << (char)254;
        break;

    case 6:
        // Tres puntos en cada lado
        rlutil::locate(posx + 2, posy + 1); // Esquina superior izquierda
        cout << (char)254;
        rlutil::locate(posx + 2, posy + 2); // Lado izquierdo medio
        cout << (char)254;
        rlutil::locate(posx + 2, posy + 3); // Esquina inferior izquierda
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 1); // Esquina superior derecha
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 2); // Lado derecho medio
        cout << (char)254;
        rlutil::locate(posx + 6, posy + 3); // Esquina inferior derecha
        cout << (char)254;
        break;
    }

    // Restablece los colores después de dibujar el dado
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
}