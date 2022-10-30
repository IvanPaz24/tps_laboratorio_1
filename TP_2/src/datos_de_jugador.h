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
#define SIZEJUGADOR 3000
#define SIZECONFEDERACION 6
#include "datos_de_confederaciones.h"
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

//menus
int AltaDeJugador(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int idAutoincremental);
int BajaDeJugador(eJugador arrayJugador[], int TAMJUGADOR);
int ModificacionDeJugador(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int idAutoincremental);
//funciones de alta
int AltaDelCampoNombre(eJugador arrayJugador[], int idAutoincremental);
int AltaDelCampoPosicion(eJugador arrayJugador[], int idAutoincremental);
int AltaDelCampoNumeroDeCamiseta(eJugador arrayJugador[], int idAutoincremental);
int AltaDelCampoConfederacion(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int idAutoincremental);
int AltaDelCampoSalario(eJugador arrayJugador[], int idAutoincremental);
int AltaDelCampoAniosDeContrato(eJugador arrayJugador[], int idAutoincremental);
//funciones de modifcar
int ModificacionCampoNombre(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado);
int ModificacionCampoPosicion(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado);
int ModificacionCampoNumeroDeCamiseta(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado);
int ModificacionCampoConfederacion(eJugador arrayJugador[], int TAMJUGADOR,eConfederacion arrayConfederacion[],int TAMCONFEDERACION, int idIngresado);
int ModificacionCampoSalario(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado);
int ModificacionCampoAniosDeContrato(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado);
//validaciones e inicializaciones
int ValidacionExitenciaJugadores(eJugador arrayJugador[], int TAMJUGADORES);
int BuscarPorIDJugador(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado);
void InicializarEstadoJugador(eJugador arrayJugador[], int TAM);
int BuscarLibreJugador(eJugador arrayJugador[],int TAM);

#endif /* DATOS_DE_JUGADOR_H_ */
