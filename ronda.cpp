#include <iostream>
#include <limits>

using namespace std;

bool nuevaRonda()
{
    int opcion;
    while (true) // Este bucle se va a finalizar cuando aparece un return
    {
        cout << "-----------------------------" << endl;
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