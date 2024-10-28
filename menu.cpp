#include <iostream>
#include "menu.h"
#include "juego.h"
#include "dados.h"
#include "creditos.h"
#include "jugador.h"
#include "estadisticas.h"

using namespace std;

void menu(string &actualMejorJugador, int &actualMejorPuntuacion)
{
    bool juego = true;
    int opcion;

    do
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
        cout << "|-0) PRESIONE 0 PARA SALIR----------------------|" << endl;
        cout << "|                                               |" << endl;
        cout << "|---------------INGRESE UNA OPCION--------------|" << endl;
        cout << "|_______________________________________________|" << endl;
        cin >> opcion;

        switch (opcion)
        {
        case 0:
            /// PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
            system("cls");
            cout << "Saliendo del juego..." << endl;
            system("pause");
            juego = false;
            break;
        case 1:
            /// PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
            system("cls");
            cout << "Por favor indique su nombre." << endl;
            // En C++ las funciones antes de ejecutar las instrucciones, primero resuelve los parametros (en este caso, el jugador tiene que escribir su nombre)
            jugarModoSolitario(nombreJugador(), actualMejorJugador, actualMejorPuntuacion);
            system("pause");
            break;

        case 2:
            /// PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
            system("cls");
            cout << "Modo dos jugadores" << endl;
            system("pause");
            break;

        case 3:
            /// PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
            system("cls");
            cout << "Estadisticas" << endl;
            mostrarEstadisticas(actualMejorJugador, actualMejorPuntuacion);
            system("pause");
            break;

        case 4:
            /// PlaySound(TEXT("MENU.wav"),NULL,SND_SYNC);
            system("cls");
            cout << "Créditos" << endl;
            mostrarCreditos();
            break;

        default:
            /// PlaySound(TEXT("WRONG.wav"),NULL,SND_SYNC);
            system("cls");
            cout << "Opción incorrecta!!" << endl;
            system("pause");
            break;
        }

    }

    while (opcion != 0);
};
