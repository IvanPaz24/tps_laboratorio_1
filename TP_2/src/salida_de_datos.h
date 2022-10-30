/*
 * salida_de_datos.h
 *
 *  Created on: 28 oct. 2022
 *      Author: ivan_
 */

#ifndef SALIDA_DE_DATOS_H_
#define SALIDA_DE_DATOS_H_

void ListaDeJugadoresPorId(eJugador arrayJugador[],int TAMJUGADOR,eConfederacion arrayConfederacion[], int TAMCONFEDERACION);

void MenuInformes(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int totalJugadores);

void ListaOrdenadaPorConfederacionYNombre(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION);

void ImprimirListaDeJugador(eJugador arrayJugador[],int TAMJUGADOR, eConfederacion arrayConfederacion[],int TAMCONFEDERACION);

void MostrarConfederacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION);

void ListadoDeConfederacionesConSusJugadores(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION);

void ConfederacionesConJugadores(eJugador arrayJugador[], int TAMJUGADOR, int id);

int TotalPromedios(eJugador arrayJugador[], int TAMJUGADOR, int totalJugadores);

int ConfederacionConMasAniosDeContratos(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[]);

int PorcentajeDeJugadorPorConfederacion(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[],int totalJugadores);

int RegionConMasJugadores(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION);



#endif /* SALIDA_DE_DATOS_H_ */
