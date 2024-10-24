#include <iostream>
#include <string>

using namespace std;

string nombreJugador()
{
    string nombre;

    cout << "Escribe tu nombre: " << endl;
    cin >> nombre;
    return nombre;
}