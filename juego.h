#pragma once

using namespace std;

void jugar(int &estadisticasGanador, int &estadisticasRondas);

int tirarDado();
void tiradaDeDados(int vDados[], int cantidad);
void mostrarDados(int vDados[], int cantidad);
int ejecutarRonda(int jugador, int bloqueador1, int bloqueador2);
int calcularPuntaje(int vDados[], int cantidad, int bloqueador1, int bloqueador2);

