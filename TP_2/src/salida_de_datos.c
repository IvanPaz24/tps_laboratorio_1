/*
 * salida_de_datos.c
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
/**
 * \fn void MenuInformes(eJugador[], int, eConfederacion[], int, int)
 * \brief sub menu de informes donde el usaurio navega
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño del array eJugador
 * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
 * \param TAMCONFEDERACION tamaño del array eConfederacion
 * \param totalJugadores cantidad de jugadores subidos
 */
void MenuInformes(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION,int totalJugadores)
{
	int opcion;

	do{
		printf("\n1: Lista ordena alfabeticamente por confederacion y nombre\n"
			   "\n2: Lista de confederaciones con sus jugadores\n"
			   "\n3: Total de salarios y promedios\n"
			   "\n4: Confederaciones con mas anios de contrato\n"
			   "\n5: Porcentaje de jugadores por confederacion\n"
			   "\n6: Regiones con mas jugadores\n"
			   "\n7: Salir\n");

		if(utn_getNumero(&opcion, "\nIngrese su opcion: ", "\nError\n", 1, 7, 3)== 0)
		{
			switch(opcion)
			{
				case 1:
					ListaOrdenadaPorConfederacionYNombre(arrayJugador, TAMJUGADOR, arrayConfederacion, TAMCONFEDERACION);
					ImprimirListaDeJugador(arrayJugador, TAMJUGADOR, arrayConfederacion, TAMCONFEDERACION);
					break;

				case 2:
					ListadoDeConfederacionesConSusJugadores(arrayJugador, TAMJUGADOR, arrayConfederacion, TAMCONFEDERACION);
					break;

				case 3:
					if(TotalPromedios(arrayJugador, TAMJUGADOR, totalJugadores)== 1)
					{
						printf("\nSe hizo la operacion de correctamente\n");
					}
					else
					{
						printf("\nError\n");
					}
					break;

				case 4:
					if(ConfederacionConMasAniosDeContratos(arrayJugador, TAMJUGADOR, arrayConfederacion)== 1)
					{
						printf("\nSe hizo la operacion de correctamente\n");
					}
					else
					{
						printf("\nError\n");
					}
					break;

				case 5:
					if(PorcentajeDeJugadorPorConfederacion(arrayJugador, TAMJUGADOR, arrayConfederacion, totalJugadores)== 1)
					{
						printf("\nSe hizo la operacion de correctamente\n");
					}
					else
					{
						printf("\nError\n");
					}
					break;

				case 6:
					if(RegionConMasJugadores(arrayJugador, TAMJUGADOR, arrayConfederacion, TAMCONFEDERACION)== 1)
					{
						printf("\nSe hizo la operacion de correctamente\n");
					}
					else
					{
						printf("\nError\n");
					}
					break;
			}
		}

	}while(opcion != 7);

}
 /**
   * \fn void ListaOrdenadaPorConfederacionYNombre(eJugador[], int, eConfederacion[], int)
  * \brief ordena la lista de jugadores por nombre de confederacion y nombre de jugador
  *
  * \param arrayJugador pertenece a eJugador y guarda sus datos
  * \param TAMJUGADOR tamaño del array eJugador
  * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
  * \param TAMCONFEDERACION tamaño del array eConfederacion
  */
void ListaOrdenadaPorConfederacionYNombre(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION)
{
	// retorno;
	int primerId;
	int segundoid;
	eJugador aux;

	for(int i = 0; i < TAMJUGADOR -1 ;i++)
	{
		for(int j = i+1; j < TAMJUGADOR ;j++)
		{
			if(arrayJugador[i].isEmpty == OCUPADO && arrayJugador[j].isEmpty == OCUPADO && arrayJugador != NULL)
			{
				primerId = BuscarPorIDConfederacion(arrayConfederacion, TAMCONFEDERACION, arrayJugador[i].idConfederacion);
				segundoid = BuscarPorIDConfederacion(arrayConfederacion, TAMCONFEDERACION, arrayJugador[j].idConfederacion);
				if(segundoid >= 0 && primerId >= 0)
				{
					if(stricmp(arrayConfederacion[primerId].nombre,arrayConfederacion[segundoid].nombre)>0)
					{
						aux = arrayJugador[i];
						arrayJugador[i] = arrayJugador[j];
						arrayJugador[j] = aux;
					}
					else
					{
						if(stricmp(arrayConfederacion[primerId].nombre,arrayConfederacion[segundoid].nombre)==0)
						{
							if(stricmp(arrayJugador[i].nombre, arrayJugador[j].nombre) > 0)
							{
								aux = arrayJugador[i];
								arrayJugador[i] = arrayJugador[j];
								arrayJugador[j] = aux;
							}
						}
					}
				}
			}
		}
	}

}
 /**
   * \fn void ImprimirListaDeJugador(eJugador[], int, eConfederacion[], int)
  * \brief imprime la lista de jugadores cargados
  *
  * \param arrayJugador pertenece a eJugador y guarda sus datos
  * \param TAMJUGADOR tamaño del array eJugador
  * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
  * \param TAMCONFEDERACION tamaño del array eConfederacion
  */
void ImprimirListaDeJugador(eJugador arrayJugador[],int TAMJUGADOR, eConfederacion arrayConfederacion[],int TAMCONFEDERACION)
{
	printf("______________________________________________________________________________________________________________________\n"
		   "|%-5s|%-35s|%-15s|%-15s|%-15s|%-10s|%-15s |\n"
		   "|=====|===================================|===============|===============|===============|==========|===============|\n",
			 "Id", "Nombre del jugador",                "Posicion",   "Numero camiseta","Confederacion","Salario","Años contrato" );
	for(int i = 0; i < TAMJUGADOR ; i++)
	{
		for(int j = 0; j < TAMCONFEDERACION ; j++)
		{
			if(arrayJugador[i].idConfederacion == arrayConfederacion[j].id)
			{
				printf("|%-5d|%-35s|%-15s|%-15d|%-15s|%-10.2f|%-15d|\n",arrayJugador[i].id,arrayJugador[i].nombre,
					arrayJugador[i].posicion,arrayJugador[i].numeroCamiseta,arrayConfederacion[j].nombre, arrayJugador[i].salario,
					arrayJugador[i].aniosContrato);
			}
		}
	}

	printf("|_____|___________________________________|_______________|_______________|_______________|__________|_______________|\n");
}

/**
 * \fn void MostrarConfederacion(eConfederacion[], int)
 * \brief muestra las confederaciones
 *
 * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
 * \param TAMCONFEDERACION tamaño del array eConfederacion
 */
void MostrarConfederacion(eConfederacion arrayConfederacion[], int TAMCONFEDERACION)
{
	printf("Id de confedarcion  \tNombre  \tRegion  \tAnio de creacion\n");
	//recorro el array y muestro el id para el usario
	for(int i = 0; i < TAMCONFEDERACION; i++)
	{
		printf("\t%d\t%s\t\t%s\t%d\n",arrayConfederacion[i].id, arrayConfederacion[i].nombre, arrayConfederacion[i].region, arrayConfederacion[i].anioCreacion);
	}
}
 /**
   * \fn void ListaDeJugadoresPorId(eJugador[], int, eConfederacion[], int)
  * \brief ordena la lista de jugadores por id
  *
  * \param arrayJugador pertenece a eJugador y guarda sus datos
  * \param TAMJUGADOR tamaño del array eJugador
  * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
  * \param TAMCONFEDERACION tamaño del array eConfederacion
  */
void ListaDeJugadoresPorId(eJugador arrayJugador[],int TAMJUGADOR,eConfederacion arrayConfederacion[], int TAMCONFEDERACION)
{
	eJugador aux;

	//recorro el array y muestro el id para el usario
	for(int i = 0; i < TAMJUGADOR; i++)
	{
		for(int j = 0; j < TAMCONFEDERACION; j++)
		{
			if(arrayConfederacion[j].id == arrayJugador[i].idConfederacion && arrayJugador[i].isEmpty == OCUPADO)
			{
				for(int k = 0 ; k < TAMJUGADOR - 1; k++)
				{
					for(int z = k + 1; z < TAMJUGADOR; z++)
					{
						if(arrayJugador[k].id > arrayJugador[z].id)
						{
							aux = arrayJugador[k];
							arrayJugador[k] = arrayJugador[z];
							arrayJugador[z] = aux;
						}
					}
				}
			}
		}
	}
}

/**
 * \fn void ListadoDeConfederacionesConSusJugadores(eJugador[], int, eConfederacion[], int)
 * \brief oredena la lista de confederaciones con su jugadores
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño del array eJugado
 * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
 * \param TAMCONFEDERACION tamaño del array eConfederacion
 */
void ListadoDeConfederacionesConSusJugadores(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION)
{
	for(int i = 0; i < TAMCONFEDERACION; i++)
	{
		printf("Lista de %s", arrayConfederacion[i].nombre);

		ConfederacionesConJugadores(arrayJugador, TAMJUGADOR, arrayConfederacion[i].id);

	}
}
 /**
   * \fn void ConfederacionesConJugadores(eJugador[], int, int)
  * \brief mustra la lista de confederaciones con sus jugadores
  *
  * \param arrayJugador pertenece a eJugador y guarda sus datos
  * \param TAMJUGADOR tamaño del array eJugador
  * \param id id de las confederaciones ingresadas
  */
void ConfederacionesConJugadores(eJugador arrayJugador[], int TAMJUGADOR, int id)
{
	printf("__________________________________________________________________________________________________________\n"
			   "|%-5s|%-35s|%-15s|%-15s|%-15s|%-7s |\n"
			   "|=====|===================================|===============|===============|==========|===============|\n",
				 "Id", "Nombre del jugador",                "Posicion",   "Numero camiseta","Salario","Años contrato" );
	for(int i = 0; i < TAMJUGADOR ; i++)
	{
		if(arrayJugador[i].idConfederacion == id && arrayJugador[i].isEmpty == OCUPADO)
		{
			printf("|%-5d|%-35s|%-15s|%-15d|%-10.2f|%-15d|\n",arrayJugador[i].id,arrayJugador[i].nombre,
				arrayJugador[i].posicion,arrayJugador[i].numeroCamiseta,arrayJugador[i].salario,
				arrayJugador[i].aniosContrato);
		}
	}

	printf("|_____|___________________________________|_______________|_______________|_______________|__________|\n");

}

/**
 * \fn int TotalPromedios(eJugador[], int, int)
 * \brief saca los promedios totales y muestra el total de los salarios
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño del array eJugador
 * \param totalJugadores la cantidad total de jugadores cargados
 * \return devulve 1 si se cargagon bien todos los datos y 0 en caso de error
 */
int TotalPromedios(eJugador arrayJugador[], int TAMJUGADOR, int totalJugadores)
{
	int retorno;
	float acumulador;
	float promedio;
	int jugadoresSalarioSuperior;

	//eJugador aux;
	jugadoresSalarioSuperior = 0;

	retorno = 0;
	acumulador = 0;

	for(int i = 0; i < TAMJUGADOR; i++)
	{
		acumulador = acumulador + arrayJugador[i].salario;

	}

	promedio = (float)acumulador / totalJugadores;

	printf("\nSalarios totales: %.2f", acumulador);

	printf("\nPromedio: %.2f", promedio);

	for(int i = 0; i < TAMJUGADOR;i++ )
	{
		if(promedio < arrayJugador[i].salario)
		{
			jugadoresSalarioSuperior++;
		}
	}

	printf("\nLos jugadores con mayor salario al promedio son: %d", jugadoresSalarioSuperior);
	return retorno;

}
 /**
   * \fn int ConfederacionConMasAniosDeContratos(eJugador[], int, eConfederacion[])
  * \brief filtra las confederaciones con mas anios de contrato
  *
  * \param arrayJugador pertenece a eJugador y guarda sus datos
  * \param TAMJUGADOR tamaño del array eJugador
  * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
  * \return devulve 1 si se cargagon bien todos los datos y 0 en caso de error
  */
int ConfederacionConMasAniosDeContratos(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[])
{
	int retorno;
	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCAF = 0;
	int contadorOFC = 0;

	retorno = 0;

	for(int i = 0; i < TAMJUGADOR ; i++)
	{
		switch (arrayJugador[i].idConfederacion)
		{
			case 1:
				contadorCONMEBOL = contadorCONMEBOL + arrayJugador[i].aniosContrato;
				break;

			case 2:
				contadorUEFA = contadorUEFA + arrayJugador[i].aniosContrato;
				break;

			case 3:
				contadorAFC = contadorAFC + arrayJugador[i].aniosContrato;
				break;

			case 4:
				contadorCAF = contadorCAF + arrayJugador[i].aniosContrato;
				break;

			case 5:
				contadorCONCAF = contadorCONCAF + arrayJugador[i].aniosContrato;
				break;

			case 6:
				contadorOFC = contadorOFC + arrayJugador[i].aniosContrato;
				break;
		}
	}

	if(contadorCONMEBOL > contadorUEFA && contadorCONMEBOL > contadorCAF && contadorCONMEBOL > contadorAFC && contadorCONMEBOL > contadorOFC && contadorCONMEBOL > contadorCONCAF)
	{
		printf("\nLa confederacion con mas anios de contrato es CONMEBOL\n");
		retorno = 1;
	}
	else
	{
		if(contadorUEFA > contadorCONCAF && contadorUEFA > contadorOFC && contadorUEFA > contadorAFC && contadorUEFA > contadorCAF)
		{
			printf("\nLa confederacion con mas anios de contrato es UEFA\n");
			retorno = 1;
		}
		else
		{
			if(contadorCONCAF > contadorCAF && contadorCONCAF > contadorOFC && contadorCONCAF > contadorAFC)
			{
				printf("\nLa confederacion con mas anios de contrato es CONCAF\n");
				retorno = 1;
			}
			else
			{
				if(contadorCAF > contadorAFC && contadorCAF > contadorOFC)
				{
					printf("\nLa confederacion con mas anios de contrato es CAF\n");
					retorno = 1;
				}
				else
				{
					if(contadorAFC > contadorOFC)
					{
						printf("\nLa confederacion con mas anios de contrato es AFC\n");
						retorno = 1;
					}
					else
					{
						printf("\nLa confederacion con mas anios de contrato es OFC\n");
						retorno = 1;
					}
				}
			}
		}
	}
	return retorno;
}

/**
 * \fn int PorcentajeDeJugadorPorConfederacion(eJugador[], int, eConfederacion[], int)
 * \brief calcula el porcentaje de jugadores por cada confederacions
 *
 * \param arrayJugador arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño del array eJugador
 * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
 * \param totalJugadores la cantidad total de jugadores cargados
 * \return devulve 1 si se cargagon bien todos los datos y 0 en caso de error
 */
int PorcentajeDeJugadorPorConfederacion(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int totalJugadores)
{
	int retorno;
	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCAF = 0;
	int contadorOFC = 0;
	float porcentajeDeCONMEBOL;
	float porcentajeDeUEFA ;
	float porcentajeDeCAF;
	float porcentajeDeAFC ;
	float porcentajeDeCONCAF ;
	float porcentajeDeOFC ;

	retorno = 0;

	for(int i = 0; i < TAMJUGADOR; i ++)
	{
		switch (arrayJugador[i].idConfederacion)
		{
			case 1:
				contadorCONMEBOL++;
				break;

			case 2:
				contadorUEFA++;
				break;

			case 3:
				contadorAFC++;
				break;

			case 4:
				contadorCAF++;
				break;

			case 5:
				contadorCONCAF++;
				break;

			case 6:
				contadorOFC++;
				break;
		}
	}

	if(contadorCONMEBOL > 0)
	{
		porcentajeDeCONMEBOL = (float)contadorCONMEBOL*100/totalJugadores;
		printf("\nEl porcentaje de CONMEBOL es: %2.f", porcentajeDeCONMEBOL);
	}

	if(contadorUEFA > 0)
	{
		porcentajeDeUEFA = (float)contadorUEFA*100/totalJugadores;
		printf("\nEl porcentaje de UEFA es: %2.f", porcentajeDeUEFA);
	}

	if(contadorAFC > 0)
	{
		porcentajeDeAFC = (float)contadorAFC*100/totalJugadores;
		printf("\nEl porcentaje de AFC es: %2.f", porcentajeDeAFC);
	}

	if(contadorCAF > 0)
	{
		porcentajeDeCAF = (float)contadorCAF*100/totalJugadores;
		printf("\nEl porcentaje de CAF es: %2.f", porcentajeDeCAF);
	}

	if(contadorCONCAF > 0)
	{
		porcentajeDeCONCAF = (float)contadorCONCAF*100/totalJugadores;
		printf("\nEl porcentaje de CONCAF es: %2.f", porcentajeDeCONCAF);
	}

	if(contadorOFC > 0)
	{
		porcentajeDeOFC = (float)contadorOFC*100/totalJugadores;
		printf("\nEl porcentaje de OFC es: %2.f", porcentajeDeOFC);
	}


	return retorno;
}

/**
 * \fn int RegionConMasJugadores(eJugador[], int, eConfederacion[], int)
 * \brief flitra la region con mas jugadores y las muestras
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR pertenece a eJugador y guarda sus datos
 * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
 * \param TAMCONFEDERACION tamaño del array eConfederacion
 * \return devulve 1 si se cargagon bien todos los datos y 0 en caso de error
 */
int RegionConMasJugadores(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION)
{
	int contadorCONMEBOL = 0;
	int contadorUEFA = 0;
	int contadorAFC = 0;
	int contadorCAF = 0;
	int contadorCONCAF = 0;
	int contadorOFC = 0;
	int retorno;

	retorno = 0;

	for(int i = 0; i < TAMJUGADOR; i++)
	{
		switch (arrayJugador[i].idConfederacion)
		{
			case 1:
				contadorCONMEBOL++;
				break;

			case 2:
				contadorUEFA++;
				break;

			case 3:
				contadorAFC++;
				break;

			case 4:
				contadorCAF++;
				break;

			case 5:
				contadorCONCAF++;
				break;

			case 6:
				contadorOFC++;
				break;
		}
	}

	if(contadorCONMEBOL > contadorUEFA && contadorCONMEBOL > contadorCAF && contadorCONMEBOL > contadorAFC && contadorCONMEBOL > contadorOFC && contadorCONMEBOL > contadorCONCAF)
	{
		printf("\n%s\n", arrayConfederacion[0].region);
		ConfederacionesConJugadores(arrayJugador, TAMJUGADOR, arrayConfederacion[0].id);
		retorno = 1;
	}
	else
	{
		if(contadorUEFA > contadorCONCAF && contadorUEFA > contadorOFC && contadorUEFA > contadorAFC && contadorUEFA > contadorCAF)
		{
			printf("\n%s\n", arrayConfederacion[1].region);
			ConfederacionesConJugadores(arrayJugador, TAMJUGADOR, arrayConfederacion[1].id);
			retorno = 1;
		}
		else
		{
			if(contadorCONCAF > contadorCAF && contadorCONCAF > contadorOFC && contadorCONCAF > contadorAFC)
			{
				printf("\n%s\n", arrayConfederacion[2].region);
				ConfederacionesConJugadores(arrayJugador, TAMJUGADOR, arrayConfederacion[2].id);
				retorno = 1;
			}
			else
			{
				if(contadorCAF > contadorAFC && contadorCAF > contadorOFC)
				{
					printf("\n%s\n", arrayConfederacion[3].region);
					ConfederacionesConJugadores(arrayJugador, TAMJUGADOR, arrayConfederacion[3].id);
					retorno = 1;
				}
				else
				{
					if(contadorAFC > contadorOFC)
					{
						printf("\n%s\n", arrayConfederacion[4].region);
						ConfederacionesConJugadores(arrayJugador, TAMJUGADOR, arrayConfederacion[4].id);
						retorno = 1;
					}
					else
					{
						printf("\n%s\n", arrayConfederacion[5].region);
						ConfederacionesConJugadores(arrayJugador, TAMJUGADOR, arrayConfederacion[5].id);
						retorno = 1;
					}
				}
			}
		}
	}

	return retorno;
}
