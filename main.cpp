#include <iostream>
#include <ctime>
#include "creditos.h"
#include "menu.h"
#include "modosDeJuego.h"
#include "dados.h"

using namespace std;

int main()
{
     srand(time(0));
     string actualMejorJugador = "";
     int actualMejorPuntuacion = 0;

     menu(actualMejorJugador, actualMejorPuntuacion);

     return 0;
}
