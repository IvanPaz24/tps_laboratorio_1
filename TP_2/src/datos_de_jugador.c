/*
 * datos_de_jugador.c
 *
 *  Created on: 17 oct. 2022
 *      Author: ivan_
 */

#include <stdio.h>
#include <stdlib.h>
#include "datos_de_jugador.h"
#include "utn.h"

void InicializarEstado(eJugador arrayJugador[], int TAM)
{
	int i;
	//recorre el array
	for (i = 0; i < TAM; i++)
	{
		arrayJugador[i].isEmpty = LIBRE;
	}

}

int BuscarLibre(eJugador arrayJugador[],int TAM)
{
	int indice;
	indice = -1;//Si no encuentra un usuario inactivo o si el array está lleno.

	//recorro el array
	for(int i=0; i<TAM; i++)
    {
		//si esta en LIBRE pone el id
	   if(arrayJugador[i].isEmpty == LIBRE)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}

void MostrarConfederacion(eConfederacion arrayConfederacion[], int TAM)
{
	printf("Id de confedarcion  \tNombre  \tRegion  \tAnio de creacion\n");
	//recorro el array y muestro el id para el usario
	for(int i = 0; i < TAM; i++)
	{
		printf("\t%d\t%s\t\t%s\%d\n",arrayConfederacion[i].id, arrayConfederacion[i].nombre, arrayConfederacion[i].region, arrayConfederacion[i].anioCreacion);
	}
}

int AltaDeJugador(eJugador arrayJugador[],int TAM, eConfederacion arrayConfederacion[], int idAutoincremental)
{
	int retorno;
	int id;
	int auxConfederacion;

	retorno = 0;

	id = BuscarLibre(arrayJugador, TAM);

	if(id > -1)
	{
		arrayJugador[id].isEmpty = OCUPADO;
		arrayJugador[id].id = idAutoincremental;

		if(utn_getNombre(arrayJugador[id].nombre, 50, "\nIngrese el nombre del jugador: ", "Error", 3)== 0)
		{
			printf("\nSe cargo correctamente el nombre.");
		}

		if(utn_getDescripcion(arrayJugador[id].posicion, 50, "\nIngrese la posicion del jugador: ", "Error", 3)== 0)
		{
			printf("\nSe cargo correctamente la posicion.");
		}

		if(utn_getNumero(&arrayJugador[id].numeroCamiseta, "\nIngrese el numero de camiseta del jugador: ", "Error", 1, 99, 3)== 0)
		{
			printf("\nSe cargo correctamente el numero de camiseta.");
		}

		MostrarConfederacion(arrayConfederacion, 6);

		if(utn_getNumero(&auxConfederacion, "\nIngrese el id de la confederacion elegida: ", "Error", 1, 6, 3)== 0)
		{
			for(int i = 0; i < 6 ; i++)
			{
				if(auxConfederacion == arrayConfederacion[i].id)
				{
					arrayJugador[id].idConfederacion = auxConfederacion;
					printf("\nSe cargo correctamente la confederacion.");
				}
			}
		}

		if(utn_getNumeroFlotante(&arrayJugador[id].salario, "\nIngrese el salario del jugador: " , "Error", 1, 1000000, 3)== 0)
		{
			printf("\nSe cargo correctamente el salario.");
		}

		if(utn_getNumero(&arrayJugador[id].aniosContrato, "\nIngrese los anios de contrato: ", "Error", 1, 8, 0)==0)
		{
			printf("\nSe cargo correctamente los anios de contrato.");
		}

		retorno = 1;
	}
	return retorno;
}

int BajaDeJugador(eJugador arrayJugador[], int TAM)
{
	int auxJugador;
	int retorno;

	retorno = 0;

	if(utn_getNumero(auxJugador, "\nIngrese el id del jugador desea dar de baja: ", "Error", 0, 3000, 3)== 0)
	{
		for(int i; i < TAM; i++)
		{
			if(arrayJugador[i].id == auxJugador && arrayJugador[i].isEmpty == OCUPADO)
			{
				arrayJugador[i].isEmpty = LIBRE;
				retorno = 1;
				break;
			}
		}
	}

	return retorno;
}


