/*
 * datos_de_confederaciones.h
 *
 *  Created on: 28 oct. 2022
 *      Author: ivan_
 */

#ifndef DATOS_DE_CONFEDERACIONES_H_
#define DATOS_DE_CONFEDERACIONES_H_

typedef struct{

	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
	short isEmpty;

}eConfederacion;

int BuscarPorIDConfederacion(eConfederacion arrayConfederacion[], int TAM, int idIngresado);

void MenuConfederaciones(eConfederacion arrayConfederacion[], int TAMCONFEDERACION);

int AltaConfederacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION);

int BajaDeConfederacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION);

void InicializarEstadoConfederacion(eConfederacion arrayConfederacion[], int TAM);

int ModificacionNombre(eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int id);

int ModificacionRegion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int id);

int ModificacionAnioDeCreacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int id);

int BuscarLibreConfederacion(eConfederacion arrayConfederacion[],int TAM);

int ModificacionConfederacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION);

int AltaCampoAnioDeCreacion(eConfederacion arrayConfederacion[], int idEncontrado);

int AltaCampoRegion(eConfederacion arrayConfederacion[], int idEncontrado);

int AltaNombreConfederacion(eConfederacion arrayConfederacion[], int idEncontrado);

int AltaConfederacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION);









#endif /* DATOS_DE_CONFEDERACIONES_H_ */
