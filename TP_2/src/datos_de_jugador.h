/*
 * datos_de_jugador.h
 *
 *  Created on: 17 oct. 2022
 *      Author: ivan_
 */

#ifndef DATOS_DE_JUGADOR_H_
#define DATOS_DE_JUGADOR_H_

#define OCUPADO 1
#define LIBRE 0

typedef struct{

	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;

}eConfederacion;

typedef struct{

	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;

}eJugador;

void InicializarEstado(eJugador arrayJugador[], int TAM);
int BuscarLibre(eJugador arrayJugador[],int TAM);
void MostrarConfederacion(eConfederacion arrayConfederacion[], int TAM);
int AltaDeJugador(eJugador arrayJugador[], int TAM ,eConfederacion arrayConfederacion[],int idAutoincremental);
int BajaDeJugador(eJugador arrayJugador[], int TAM);

#endif /* DATOS_DE_JUGADOR_H_ */
