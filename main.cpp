#include <iostream>
#include <ctime>
#include <windows.h>
#include "creditos.h"
#include "menu.h"
#include "modoUnJugador.h"
#include "modoDosJugadores.h"
#include "rlutil.h"


using namespace std;


int main()
{
     rlutil::setColor(rlutil::MAGENTA);
     srand(time(0));
     string actualMejorJugador = "";
     int actualMejorPuntuacion = 0;

     menu(actualMejorJugador, actualMejorPuntuacion);

     return 0;
}

