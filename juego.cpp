#include <iostream>
#include <limits>
#include "juego.h"

using namespace std;

int tirarDado()
{
    return rand() % 6 + 1;
}

void tiradaDeDados(int vDados[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        vDados[i] = tirarDado();
    }
}

void mostrarDados(int vDados[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << " " << vDados[i];
    }

    cout << endl;
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

bool nuevaRonda()
{
    int opcion;
    while (true) // Este bucle se va a finalizar cuando aparece un return
    {
        cout << endl;
        cout << "Queres jugar una ronda mas? " << endl;
        cout << "0. No" << endl;
        cout << "1. Si" << endl;
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
            cout << "Fin del juego." << endl;
            cout << endl;
            return false;
        case 1:
            system("cls");
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

int calcularPuntaje(int vDados[], int cantidad, int bloqueador1, int bloqueador2)
{
    int puntos = 0;

    for (int i = 0; i < cantidad; i++)
    {
        if (vDados[i] != bloqueador1 && vDados[i] != bloqueador2)
        {
            puntos += vDados[i]; // Suma los puntos de los dados que no sean igual a los bloqueadores
        }
    }

    return puntos;
}

int ejecutarTirada(int bloqueador1, int bloqueador2)
{
    int dados[5];
    int puntajeTirada;

    tiradaDeDados(dados, 5);                                             // Generar los dados
    puntajeTirada = calcularPuntaje(dados, 5, bloqueador1, bloqueador2); // Calcular el puntaje de la tirada

    // Mostrar los bloqueadores, dados y puntaje de tirada
    cout << "Bloqueadores: " << bloqueador1 << " " << bloqueador2 << endl;
    cout << "Dados: ";
    mostrarDados(dados, 5);
    cout << endl;
    cout << "Puntaje de la tirada: " << puntajeTirada << endl;

    return puntajeTirada; // Devuelve el puntaje de la tirada, para sumar en puntajeTotalRonda (en jugarModoSolitario)
}

void jugarModoSolitario(int jugador)
{
    int rondaActual = 0;
    int puntajeTotal = 0; // Total acumulado de todas las rondas
    bool continuarRonda = true;

    // Si la ronda se sigue jugando, se ejecuta el bucle
    while (continuarRonda)
    {
        rondaActual++;
        int puntajeTotalRonda = 0; // Puntaje acumulado en la ronda actual
        bool continuarTirada = true;
        int tiradaActual = 0;

        cout << "-----------------------------" << endl;
        cout << "Ronda #" << rondaActual << endl;

        // Se ejecuta una tirada de dados para la ronda, siempre que el jugador quiera o tenga dados disponibles
        while (continuarTirada)
        {
            tiradaActual++;

            // Mostramos el número de la tirada
            cout << "Tirada #" << tiradaActual << endl;
            cout << endl;

            // Generamos los bloqueadores para la nueva tirada
            int bloqueador1 = tirarDado();
            int bloqueador2 = tirarDado();

            // Ejecutar la tirada y obtener su puntaje y dados
            int puntajeTirada = ejecutarTirada(bloqueador1, bloqueador2);

            // Sumamos el puntaje de la tirada al puntaje total de la ronda
            puntajeTotalRonda += puntajeTirada;

            // Mostramos los puntos totales acumulados de la ronda
            cout << "Puntaje total de la ronda: " << puntajeTotalRonda << endl;

            continuarTirada = nuevaTirada(); // Le preguntamos al jugador si quiere una nueva tirada de dados en esta ronda
        }

        // Sumamos el puntaje de la ronda en el puntaje total de la partida
        puntajeTotal += puntajeTotalRonda;

        // Mostrar el puntaje total acumulado al final de la ronda
        cout << "Fin de la ronda #" << rondaActual << endl;
        cout << endl;
        cout << "Puntaje total de la ronda: " << puntajeTotalRonda << endl;
        cout << "Puntaje total de la partida: " << puntajeTotal << endl;

        // Le preguntamos al jugador si quiere jugar otra ronda
        continuarRonda = nuevaRonda();
    }

    cout << "Tu puntuacion en esta partida fue de: " << puntajeTotal << " puntos" << endl;
}