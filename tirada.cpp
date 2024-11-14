#include <iostream>
#include <limits>
#include "dados.h"
#include "puntaje.h"
#include "rlutil.h"
#include "dibujos.h"

using namespace std;

void mostrarResultadosTirada(int dados[], int dadosDisponibles, int bloqueador1, int bloqueador2, int puntajeTirada)
{
    mostrarBloqueadores(bloqueador1, bloqueador2);
    mostrarDados(dados, dadosDisponibles, bloqueador1, bloqueador2);
    cout << "Puntaje de la tirada: " << puntajeTirada << endl;
}

int ejecutarTirada(int dados[5], int dadosDisponibles, int bloqueador1, int bloqueador2, int tiradaActual, int &puntajeTurno)
{
    tiradaDeDados(dados, dadosDisponibles);                                                 // Tiramos los dados segun los dados disponibles que tenga el jugador
    int puntajeTirada = calcularPuntaje(dados, dadosDisponibles, bloqueador1, bloqueador2); // Calculamos el puntaje de la tirada y lo guardamos en la variable

    // Mostrar los resultados de la tirada
    cout << endl;
    cout << "---------------------" << endl;
    cout << "Tirada: " << tiradaActual << endl;
    cout << "Dados: ";
    mostrarDados(dados, dadosDisponibles, bloqueador1, bloqueador2);
    cout << endl
         << endl;
    cout << "Puntaje de la tirada: " << puntajeTirada << endl;
    cout << endl;

    return puntajeTirada; // Devolvemos el puntaje de la tirada
}

bool nuevaTirada()
{
    int opcion;
    while (true) // Este bucle se va a finalizar cuando aparece un return
    {
        cout << endl;
        cout << "---------------------" << endl;
        cout << "Queres una tirada mas?" << endl;
        cout << "0. No" << endl;
        cout << "1. Si" << endl;
        cout << endl;
        cin >> opcion;

        // Acá verificamos si el usuario no ingresó un número, así el programa no se rompe o hace algo inesperado
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignoramos la entrada incorrecta
            cout << "Opcion incorrecta! Ingresa un numero valido." << endl;
            continue; // Volvemos al inicio del bucle
        }

        // Si llegamos acá, es porque la opción fue un número (entrada válida)
        switch (opcion)
        {
        case 0:
            system("cls");
            return false;
        case 1:
            return true;
        default:
            system("cls");
            cout << "Opcion incorrecta!" << endl;
            system("pause");
            // Acá no usamos continue, ya que el programa va a volver a pedir la opcion de nuevo
            break;
        }
    }
}