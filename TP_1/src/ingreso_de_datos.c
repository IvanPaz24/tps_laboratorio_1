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

				utn_getNumeroFloat(valorIngresadoHospedaje, "\nIngrese los costos de hospedaje: ", "\nError monto no valido\n", 1, 1000000000, 4);

				break;
			case 2:

				utn_getNumeroFloat(valorIngresadoComida, "\nIngrese los costos de comida: ", "\nError monto no valido\n", 1, 1000000000, 4);

				break;
			case 3:

				utn_getNumeroFloat(valorIngresadoTransporte, "\nIngrese los costos de transporte: ", "\nError monto no valido\n", 1, 1000000000, 4);

				break;
			case 4:
				break;
		}
	}while(opcion != 4);
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

