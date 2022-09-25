/*
 * ingreso_de_datos.c
 *
 *  Created on: 23 sep. 2022
 *      Author: ivan_
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
/**
 * \fn void IngresoDeCostos(float*, float*, float*)
 * \brief esta funcion esta dedicada a optimizar y minimizar las lineas de codigo realizando
 * el submenu de el ingreso de los costos usando un swich para que eñ usuario se libre de completar
 * el costo que desee
 *
 * \param valorIngresadoComida aqui se pide ela validacion y el monto de el costo de comida y guardandolo
 * \param valorIngresadoTransporte aqui se pide ela validacion y el monto de el costo de transporte y guardandolo
 * \param valorIngresadoHospedaje aqui se pide ela validacion y el monto de el costo de hospedaje y guardandolo
 */
void IngresoDeCostos(float* valorIngresadoHospedaje, float* valorIngresadoComida, float* valorIngresadoTransporte)
{
	int opcion;

	do
	{
		printf("\nElija el costo que desea ingresar:\n"
				"1: Para costos de hospedaje.\n"
				"2: Para costos de comida.\n"
				"3: Para costos de transporte.\n"
				"4: Para salir.\n");
		utn_getNumeroInt(&opcion, "Ingrese aqui la opcion de menu: ", "Error opcion no valida\n", 1, 4, 3);
		switch(opcion)
		{
			case 1:

				utn_getNumeroFloat(valorIngresadoHospedaje, "Ingrese los costos de hospedaje: ", "Error monto no valido", 1, 1000000000, 4);

				break;
			case 2:

				utn_getNumeroFloat(valorIngresadoComida, "Ingrese los costos de comida: ", "Error monto no valido", 1, 1000000000, 4);

				break;
			case 3:

				utn_getNumeroFloat(valorIngresadoTransporte, "Ingrese los costos de transporte: ", "Error monto no valido", 1, 1000000000, 4);

				break;
			case 4:
				break;
		}
	}while(opcion != 4);
}

/**
 * \fn void IngresoDePosicionDeJugador(int*, int*, int*, int*, int*)
 * \brief el fin de esta funcion es el de obtener la posicion el la que el jugador esta en el campo de futbol
 *
 * \param arquero cuenta la cantidad de arqueros que ingresan al equipo
 * \param defensor cuenta la cantidad de defesores que ingresan al equipo
 * \param mediocampista cuenta la cantidad de mediocampista que ingresan al equipo
 * \param delantero cuenta la cantidad de delateros que ingresan al equipo
 */
void IngresoDePosicionDeJugador(int* arquero, int* defensor, int* mediocampista, int* delantero)
{
	int posicion;

	printf("\nIngrese su posicion:\n"
		"1. Arquero.\n"
		"2. Defensores.\n"
		"3. Mediocampista.\n"
		"4. Delantero\n");

	utn_getNumeroInt(&posicion,"\nIngrese aqui la opcion de menu: ", "Error opcion no valida\n", 1, 4, 3);

	switch(posicion)
	{
		case 1:
			if(*arquero > 2)
			{
				arquero++;
				//IngresoDeConfedarcion(*AFC, *CAF, *CONCACAF, *CONMEBOL, *UEFA, *OFC);
			}
			else
			{
				printf("Numero de posiciones superada\n");
			}
			break;
		case 2:
			if(*defensor < 8)
			{
				defensor++;
			}
			else
			{
				printf("Numero de posiciones superada\n");
			}
			break;
		case 3:
			if(*mediocampista < 8)
			{
				mediocampista++;
			}
			else
			{
				printf("Numero de posiciones superada\n");
			}
			break;
		case 4:
			if(*delantero < 4)
			{
				delantero++;
			}
			else
			{
				printf("Numero de posiciones superada\n");
			}
			break;
	}
}

/**
 * \fn void IngresoDeConfedarcion(int*, int*, int*, int*, int*, int*, int*)
 * \brief esta funcion realiza la validacion y el ingreso de la confedaracion a la que pertenece el jugador
 *
 * \param AFC cuenta la cantidad de jugadores pertenecintes a la AFC
 * \param CAF cuenta la cantidad de jugadores pertenecintes a la CAF
 * \param CONCACAF cuenta la cantidad de jugadores pertenecintes a la CONCACAF
 * \param CONMEBOL cuenta la cantidad de jugadores pertenecintes a la CONMEBOL
 * \param UEFA cuenta la cantidad de jugadores pertenecintes a la UEFA
 * \param OFC cuenta la cantidad de jugadores pertenecintes a la OFC
 */
void IngresoDeConfedarcion(int* AFC, int* CAF, int* CONCACAF, int* CONMEBOL, int* UEFA, int* OFC)
{
	int confederacion;

	printf("\nIngrese a que conferacion pertenece:\n"
			"1. AFC.\n"
			"2. CAF.\n"
			"3. CONCACAF.\n"
			"4. CONMEBOL.\n"
			"5. UEFA.\n"
			"6. OFC.\n");
	utn_getNumeroInt(&confederacion, "Ingrese aqui la opcion de menu: ", "Error opcion no valida\n", 1, 6, 3);

	switch(confederacion)
	{
		case 1:
			*AFC = *AFC + 1;
			break;
		case 2:
			*CAF = *CAF + 1;
			break;
		case 3:
			*CONCACAF = *CONCACAF + 1;
			break;
		case 4:
			*CONMEBOL = *CONMEBOL + 1;
			break;
		case 5:
			*UEFA = *UEFA + 1;
			break;
		case 6:
			*OFC = *OFC + 1;
			break;
	}
}

