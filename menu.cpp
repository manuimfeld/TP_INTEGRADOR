#include <iostream>
#include "menu.h"
#include "juego.h"
#include "dados.h"

using namespace std;

void mostrarCreditos()
{
    cout << "Creditos: Equipo X" << endl;
    cout << "Integrantes:" << endl;
    cout << "Fiaschi Bernardo - Legajo X" << endl;
    cout << "Peña Pariona Cinthia - Legajo X" << endl;
    cout << "Serafini Nicolas - Legajo X" << endl;
    cout << "Imfeld Jair Manuel - Legajo 30397" << endl;
    system("pause");
};

void menu()
{
    bool juego = true;

    int opc;

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
        cin >> opc;

        switch (opc)
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
            cout << "Modo un jugador" << endl;
            jugarModoSolitario(1);
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

    while (opc != 0);
};
