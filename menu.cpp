#include <iostream>
#include "menu.h"
#include "modoUnJugador.h"
#include "dados.h"
#include "creditos.h"
#include "jugador.h"
#include "estadisticas.h"
#include "modoDosJugadores.h"
#include "reglas.h"
#include "rlutil.h"

using namespace std;

void mostrarMenu()
{
    system("cls");
    cout << "|-----------------MENU PRINCIPAL----------------|" << endl;
    cout << "|                                               |" << endl;
    cout << "|-1) PRESIONE 1 PARA MODO UN JUGADOR------------|" << endl;
    cout << "|                                               |" << endl;
    cout << "|-2) PRESIONE 2 PARA MODO DOS JUGADORES---------|" << endl;
    cout << "|                                               |" << endl;
    cout << "|-3) PRESIONE 3 PARA ESTADISTICAS---------------|" << endl;
    cout << "|                                               |" << endl;
    cout << "|-4) PRESIONE 4 PARA CREDITOS-------------------|" << endl;
    cout << "|                                               |" << endl;
    cout << "|-5) PRESIONE 5 PARA REGLAS---------------------|" << endl;
    cout << "|                                               |" << endl;
    cout << "|-0) PRESIONE 0 PARA SALIR----------------------|" << endl;
    cout << "|                                               |" << endl;
    cout << "|---------------INGRESE UNA OPCION--------------|" << endl;
    cout << "|_______________________________________________|" << endl;
}

void menu(string &actualMejorJugador, int &actualMejorPuntuacion)
{
    bool juego = true;
    int opcion;

    do
    {
        mostrarMenu();
        cin >> opcion;

        switch (opcion)
        {
        case 0:
            system("cls");
            cout << "Saliendo del juego..." << endl;
            system("pause");
            juego = false;
            break;
        case 1:
            system("cls");
            cout << "Por favor indique su nombre." << endl;
            // En C++ las funciones antes de ejecutar las instrucciones, primero resuelve los parametros (en este caso, el jugador tiene que escribir su nombre)
            jugarModoSolitario(nombreJugador(), actualMejorJugador, actualMejorPuntuacion);
            system("pause");
            break;

        case 2:
            system("cls");
            cout << "Modo dos jugadores" << endl;
            cout << "Por favor indiquen sus nombres." << endl;
            modoDosJugadores(nombreJugador2(), nombreJugador1(), actualMejorJugador, actualMejorPuntuacion);
            system("pause");
            break;

        case 3:
            system("cls");
            cout << "Estadisticas" << endl;
            mostrarEstadisticas(actualMejorJugador, actualMejorPuntuacion);
            system("pause");
            break;

        case 4:
            system("cls");
            cout << "Creditos" << endl;
            mostrarCreditos();
            break;

        case 5:
            system("cls");
            rlutil::setColor(rlutil::GREEN);
            reglas();
            system("pause");
            rlutil::setColor(rlutil::MAGENTA);
            break;

        default:
            system("cls");
            rlutil::setColor(rlutil::RED);
            cout << "Opción incorrecta!!" << endl;
            system("pause");
            rlutil::setColor(rlutil::MAGENTA);
            break;
        }

    }

    while (opcion != 0);
};
