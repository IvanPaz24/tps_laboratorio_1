/*
 * datos_de_confederaciones.c
 *
 *  Created on: 28 oct. 2022
 *      Author: ivan_
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos_de_jugador.h"
#include "utn.h"
#include "datos_de_confederaciones.h"
#include "salida_de_datos.h"

void InicializarEstadoConfederacion(eConfederacion arrayConfederacion[], int TAM)
{
	int i;
	//recorre el array
	for (i = 0; i < TAM; i++)
	{
		arrayConfederacion[i].isEmpty = LIBRE;
	}

}

int BuscarLibreConfederacion(eConfederacion arrayConfederacion[],int TAM)
{
	int indice;
	indice = -1;//Si no encuentra un usuario inactivo o si el array está lleno.

	//recorro el array
	for(int i=0; i<TAM; i++)
    {
		//si esta en LIBRE pone el id
	   if(arrayConfederacion[i].isEmpty == LIBRE)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}

int BuscarPorIDConfederacion(eConfederacion arrayConfederacion[], int TAM, int idIngresado)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (arrayConfederacion != NULL && TAM > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (arrayConfederacion[i].id == idIngresado)
			{
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


void MenuConfederaciones(eConfederacion arrayConfederacion[], int TAMCONFEDERACION)
{
	int opcion;

	printf("\n\tBienvenido al menu de confederaciones\n"
		   "1: Para dar de alta.\n"
		   "2: Para dar de baja.\n"
		   "3: Para modificar.\n"
		   "4: Para ver la confederaciones.\n"
		   "5: Para salir.\n");
	if(utn_getNumero(&opcion, "\nIngrese su opcion: ", "\nError\n", 1, 5, 3)== 0)
	{
		switch (opcion)
		{
			case 1:
				if(AltaConfederacion(arrayConfederacion, TAMCONFEDERACION) == 1)
				{
					printf("\nSe dio de alta correctamente\n");
				}
				else
				{
					printf("\nError\n");
				}
				break;
			case 2:
				if(BajaDeConfederacion(arrayConfederacion, TAMCONFEDERACION) == 1)
				{
					printf("\nSe dio de baja correctamente correctamente\n");
				}
				else
				{
					printf("\nError\n");
				}
				break;

			case 3:
				if(ModificacionConfederacion(arrayConfederacion, TAMCONFEDERACION)== 1)
				{
					printf("\nSe modificaron corretamentente los datos\n");
				}
				else
				{
					printf("\nError\n");
				}
				break;

			case 4:
				MostrarConfederacion(arrayConfederacion, TAMCONFEDERACION);
				break;
		}
	}
}


int AltaConfederacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION)
{
	int retorno;
	int id;

	retorno = 0;

	id = BuscarLibreConfederacion(arrayConfederacion, TAMCONFEDERACION);

	if(id> -1)
	{
		if(AltaNombreConfederacion(arrayConfederacion, id)== 1 &&
			AltaCampoRegion(arrayConfederacion, id)== 1 &&
			AltaCampoAnioDeCreacion(arrayConfederacion, id) == 1)
		{
			retorno = 1;
			arrayConfederacion[id].isEmpty = OCUPADO;
		}
	}

	return retorno;
}

int AltaNombreConfederacion(eConfederacion arrayConfederacion[], int idEncontrado)
{
	int retorno;
	int id;

	id = idEncontrado;
	if(utn_getNombre(arrayConfederacion[id].nombre, 50, "\nIngrese el nombre de la confederacion: ", "\nError\n", 3)== 0)
	{
		printf("\nSe cargo correctamente el nombre.");
		retorno = 1;
	}
	retorno = 0;

	return retorno;
}

int AltaCampoRegion(eConfederacion arrayConfederacion[], int idEncontrado)
{
	int retorno;
	int id;

	id = idEncontrado;
	if(utn_getDescripcion(arrayConfederacion[id].region, 50, "\nIngrese la region", "\nError\n", 3)== 0)
	{
		printf("\nSe cargo correctamente el nombre.");
		retorno = 1;
	}
	retorno = 0;

	return retorno;
}

int AltaCampoAnioDeCreacion(eConfederacion arrayConfederacion[], int idEncontrado)
{
	int retorno;
	int id;
	int auxAnio;

	retorno = 0;
	id = idEncontrado;

	if(utn_getNumero(&auxAnio, "\nIngrese el anio de creacion", "\nError\n", 1500, 2022, 3) == 0)
	{
		arrayConfederacion[id].anioCreacion = auxAnio;
		retorno = 1;
	}

	return retorno;
}
int BajaDeConfederacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION)
{
	int retorno;
	int opcion;
	int idAux;

	retorno = 0;
	do{
		printf("1: Para continuar.\n"
			   "2: Para dar de baja una confederacion.\n");
		if(utn_getNumero(&opcion, "\nIngrese su opcion: ", "\nError\n", 1, 2, 3 ) == 0)
		{
			switch (opcion)
			{
				case 1:
					if(utn_getNumero(&idAux, "\nIngrese el id de la confederacion que desea dar de baja: ", "\nError\n", 1, 6, 3)== 0)
					{
						if(BuscarPorIDConfederacion(arrayConfederacion, TAMCONFEDERACION,idAux)== 1)
						{
							arrayConfederacion[idAux].isEmpty = LIBRE;
							retorno = 1;
						}
					}
					break;
			}
		}
	}while(opcion != 2);


	return retorno;
}

int ModificacionConfederacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION)
{
	int retorno;
	int opcion;
	int idAux;

	retorno = 0;
	do
	{
		//ListaDeJugadoresPorId(arrayJugador, TAMJUGADOR, arrayConfederacion, TAMCONFEDERACION);
		printf("1: Para ingresar modificar los datos de un jugador.\n"
			   "2: Para volver al menu principal\n");

		if(utn_getNumero(&opcion, "\nIngrese su opcion: ", "\nError\n", 1, 2, 4 ) == 0)
		{
			switch (opcion)
			{
				case 1:
					if(utn_getNumero(&idAux, "\nIngrese el id de la confederacion que desea modificar: ", "\nError\n", 1, 2, 6)== 0)
					{
						do{
							printf("\t\nMenu Modificar.\n"
									"1: Para modificar el nombre.\n"
									"2: Para modificar la ragion.\n"
									"3: Para modificar el anio de creacion.\n"
									"4: Para salir.\n");
							if(utn_getNumero(&opcion, "\nIngrese su opcion: ", "\nError\n", 1, 4, 3) == 0)
							{
								retorno = 1;
								switch (opcion)
								{
									case 1:
										if(ModificacionNombre(arrayConfederacion, TAMCONFEDERACION, idAux)== 1)
										{
											printf("\nSe modifico correctamente el nombre\n");
										}
										break;
									case 2:
										if(ModificacionRegion(arrayConfederacion, TAMCONFEDERACION, idAux)== 1)
										{
											printf("\nSe modifico correctamente el nombre\n");
										}
										break;

									case 3:
										if(ModificacionAnioDeCreacion(arrayConfederacion, TAMCONFEDERACION, idAux)== 1)
										{
											printf("\nSe modifico correctamente el nombre\n");
										}
										break;

								}
							}

						}while(opcion != 1);
					}
					break;
				default:
					break;
			}
		}

	}while(opcion != 2);

	return retorno;
}

int ModificacionNombre(eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int id)
{
	int retorno;
	char auxNombre[50];

	retorno = 0;

	if(BuscarPorIDConfederacion(arrayConfederacion, TAMCONFEDERACION, id)>= 0)
	{
		//si lo encuentra guarda el titulo a modificar en un auxiliar y se modifica en el array
		if(utn_getNombre(auxNombre, 50, "\nIngrese el nuevo nombre: ", "\nError\n", 4)== 0)
		{
			strcpy(arrayConfederacion[id].nombre,auxNombre);
			retorno = 1;
			//break;
		}
	}

	return retorno;
}

int ModificacionRegion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int id)
{
	int retorno;
	char auxRegion[50];

	retorno = 0;

	if(BuscarPorIDConfederacion(arrayConfederacion, TAMCONFEDERACION, id)>= 0)
	{
		//si lo encuentra guarda el titulo a modificar en un auxiliar y se modifica en el array
		if(utn_getDescripcion(auxRegion, 50, "\nIngrese la nueva region: ","\nError\n" , 3)== 0)
		{
			strcpy(arrayConfederacion[id].region,auxRegion);
			retorno = 1;
			//break;
		}
	}

	return retorno;
}

int ModificacionAnioDeCreacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int id)
{
	int retorno;
	int auxAnio;

	retorno = 0;

	if(BuscarPorIDConfederacion(arrayConfederacion, TAMCONFEDERACION, id)>= 0)
	{
		if(utn_getNumero(&auxAnio, "\nIngrese el nuevo anio", "\nError\n", 1500, 2022, 3) == 0)
		{
			arrayConfederacion[id].anioCreacion = auxAnio;
			retorno = 1;
		}
	}

	return retorno;
}
