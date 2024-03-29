/*
 * relizacion_de_calculos.c
 *
 *  Created on: 24 sep. 2022
 *      Author: ivan_
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * \fn float Promedio(int, int)
 * \brief funcion que realiza los promedios de la conferaciones
 *
 * \param confedaricion recibe el tipo de conferacion y la cantidad de jugadores pertenecientes a esa
 * \param cantidadJugador recibe la cantidad total de los jugadores
 * \return devuelve el resultado de la opracion, osea el promedio por conferacion
 */

float Promedio(int confedaricion, int cantidadJugador)
{
	float promedio;

	promedio = (float) confedaricion / cantidadJugador;

	return promedio;
}

/**
 * \fn float AumentoParaCostoFinal(float*, float)
 * \brief esta fundion se utiliza para realizar el aumento en caso de que la cantidad de jugadores
 * que pertenecen a la UEFA sea mayor en comparacion que las otras confederaciones
 *
 * \param aumento varalible donde se realiza el aumento a aplicar
 * \param costoMantenimineto los costos totales de mantenimiento
 * \return devuelve el valor final de los costos de mantenimiento con el aumento agregado
 */

float AumentoParaCostoFinal(float* aumento, float costoMantenimineto)
{
	float costoConAumento;

	costoConAumento = 0;

	*aumento = costoMantenimineto * 0.35;

	costoConAumento = *aumento + costoMantenimineto;

	return costoConAumento;
}

