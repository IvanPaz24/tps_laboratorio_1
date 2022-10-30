/*
 * datos_de_jugador.c
 *
 *  Created on: 17 oct. 2022
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
 * \fn void InicializarEstadoJugador(eJugador[], int)
 * \brief inicializa el array en LIBRE
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAM tamaño del array
 */
void InicializarEstadoJugador(eJugador arrayJugador[], int TAM)
{
	int i;
	//recorre el array
	for (i = 0; i < TAM; i++)
	{
		arrayJugador[i].isEmpty = LIBRE;
	}

}

/**
 * \fn int BuscarLibreJugador(eJugador[], int)
 * \brief busca u indice o un id y verifica que sea este libre
 *
 * \param arrayJugador arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAM tamaño del array
 * \return devuelve el indice que encuentra
 */
int BuscarLibreJugador(eJugador arrayJugador[],int TAM)
{
	int indice;
	indice = -1;//Si no encuentra un usuario inactivo o si el array está lleno.

	//recorro el array
	for(int i=0; i<TAM; i++)
    {
		//si esta en LIBRE pone el id
	   if(arrayJugador[i].isEmpty == LIBRE && arrayJugador != NULL)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}


/**
 * \fn int AltaDeJugador(eJugador[], int, eConfederacion[], int, int)
 * \brief esta es la parte del menu de alta donde se cargan todos los datos
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR pertenece a eJugador y guarda sus datos
 * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
 * \param TAMCONFEDERACION tamaño del array eConfederacion
 * \param idAutoincremental id autoincremental que almacena cada dato de cada jugador
 * \return devulve 1 si se cargagon bien todos los datos y 0 en caso de error
 */
int AltaDeJugador(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int idAutoincremental)
{
	int retorno;
	int id;

	retorno = 0;

	id = BuscarLibreJugador(arrayJugador, TAMJUGADOR);

	if(id > -1)
	{
		if(AltaDelCampoNombre(arrayJugador, idAutoincremental) == 1 &&
		   AltaDelCampoPosicion(arrayJugador, idAutoincremental) == 1 &&
		   AltaDelCampoNumeroDeCamiseta(arrayJugador, idAutoincremental) == 1 &&
		   AltaDelCampoConfederacion(arrayJugador, arrayConfederacion, TAMCONFEDERACION, idAutoincremental) == 1 &&
		   AltaDelCampoSalario(arrayJugador, idAutoincremental) == 1 &&
		   AltaDelCampoAniosDeContrato(arrayJugador, idAutoincremental) == 1)
		{
			arrayJugador[id].id = idAutoincremental;
			arrayJugador[id].isEmpty = OCUPADO;
			retorno = 1;
		}
	}

	return retorno;
}

/**
 * \fn int BajaDeJugador(eJugador[], int)
 * \brief esta funcion recorre todo el array para encontrar el que el usuario quiera dar de baja
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAM tamaño del array
 * \return devuelve 1 si se dio de baja y 0 si no ocurrio un error
 */
int BajaDeJugador(eJugador arrayJugador[], int TAM)
{
	int auxJugador;
	int retorno;

	retorno = 0;

	if(utn_getNumero(&auxJugador, "\nIngrese el id del jugador desea dar de baja: ", "Error", 0, 3000, 3)== 0)
	{
		if(BuscarPorIDJugador(arrayJugador, TAM, auxJugador) >= 0)
		{
			arrayJugador[auxJugador].isEmpty = LIBRE;
			retorno = 1;
		}
	}

	return retorno;
}

/**
 * \fn int ModificacionDeJugador(eJugador[], int, eConfederacion[], int, int)
 * \brief esta es la parte del menu donde el usuario modifica los datos de los jugadores
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño del array eJugador
 * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
 * \param TAMCONFEDERACION tamaño del array eConfederacion
 * \param idAutoincremental id autoincremental que almacena cada dato de cada jugador
 * \return devulve 1 si se cargagon bien todos los datos y 0 en caso de error
 */
int ModificacionDeJugador(eJugador arrayJugador[], int TAMJUGADOR, eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int idAutoincremental)
{
	int retorno;
	int idIngresado;
	int opcion;

	do
	{
		//ListaDeJugadoresPorId(arrayJugador, TAMJUGADOR, arrayConfederacion, TAMCONFEDERACION);
		printf("1: Para ingresar modificar los datos de un jugador.\n"
			   "2: Para volver al menu principal\n");

		//ListaDeJugadoresPorId(arrayJugador, TAMJUGADOR, arrayConfederacion, TAMCONFEDERACION);

		if(utn_getNumero(&opcion, "\nIngrese su opcion: ", "\nError\n", 1, 2, 4 ) == 0)
		{
			switch(opcion)
			{
				case 1:
					ListaDeJugadoresPorId(arrayJugador, TAMJUGADOR, arrayConfederacion, TAMCONFEDERACION);
					ImprimirListaDeJugador(arrayJugador, TAMJUGADOR, arrayConfederacion, TAMCONFEDERACION);
					if(utn_getNumero(&idIngresado, "Ingrese el id del jugador que desea modificar", "\nError\n", 0, 3000, 3)== 0)
					{
						do
						{
							printf("\n\tMenu de modificacion\n"
									"1: Para modificar el nombre\n"
									"2: Para modificar la posicion\n"
									"3: Para modificar el numero de camiseta\n"
									"4: Para modificar la confederacion\n"
									"5: Para modificar el salario\n"
									"6: Para modificar los años de contrato\n"
									"7: Para salir.\n");

							if(utn_getNumero(&opcion, "\nIngrese su opcion: ", "\nError\n", 1, 7, 4)==0)
							{
								retorno = 1;
								switch(opcion)
								{
									case 1:

										if(ModificacionCampoNombre(arrayJugador, TAMJUGADOR, idIngresado)== 1)
										{
											printf("\nSe modifico correctamente el nombre\n");
											break;
										}
										else
										{
											printf("\nError\n");
										}

										break;

									case 2:

										if(ModificacionCampoPosicion(arrayJugador, TAMJUGADOR, idIngresado) == 1)
										{
											printf("\nSe modifico correctamente la posicion\n");
										}
										else
										{
											printf("\nError\n");
										}

										break;

									case 3:

										if(ModificacionCampoNumeroDeCamiseta(arrayJugador, TAMJUGADOR, idIngresado) == 1)
										{
											printf("\nSe modifico correctamente el numero de camiseta.\n");
										}
										else
										{
											printf("\nError\n");
										}

										break;

									case 4:

										if(ModificacionCampoConfederacion(arrayJugador, TAMJUGADOR, arrayConfederacion, TAMCONFEDERACION, idIngresado)== 1)
										{
											printf("\nSe modifico correctamente la confederacion.\n");
										}
										else
										{
											printf("\nError\n");
										}

										break;

									case 5:

										if(ModificacionCampoSalario(arrayJugador, TAMJUGADOR, idIngresado) == 1)
										{
											printf("\nSe modifico correctamente el salario.\n");
										}
										else
										{
											printf("\nError\n");
										}

										break;

									case 6:

										if(ModificacionCampoAniosDeContrato(arrayJugador, TAMJUGADOR, idIngresado)== 1)
										{
											printf("\nSe modifico correctamente los anios de contrato.\n");
										}

										break;

									break;
								}
							}

						}while(opcion != 7);
					}
			}
		}

	}while(opcion != 2);

	retorno = 0;

	return retorno;
}
/**
 * \fn int AltaDelCampoNombre(eJugador[], int)
 * \brief da de alta el nombre que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param idAutoincremental id autoincremental que almacena cada dato de cada jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int AltaDelCampoNombre(eJugador arrayJugador[], int idAutoincremental)
{
	int retorno;
	int id;

	id = idAutoincremental;

	retorno = 0;

	if(utn_getNombre(arrayJugador[id].nombre, 50, "\nIngrese el nombre del jugador: ", "Error", 3)== 0)
	{
		printf("\nSe cargo correctamente el nombre.");
		retorno = 1;
	}

	return retorno;
}

/**
 * \fn int AltaDelCampoPosicion(eJugador[], int)
 * \brief da de alta la posicion que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param idAutoincremental id autoincremental que almacena cada dato de cada jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int AltaDelCampoPosicion(eJugador arrayJugador[], int idAutoincremental)
{
	int retorno;
	int id;
	int auxPosicion;

	id = idAutoincremental;

	retorno = 0;

	if(utn_getNumero(&auxPosicion, "\nIngrese la posicion del jugador(1: delantero, 2: mediocampista, 3: defensor y 4: arquero): ", "Error", 1, 4, 3)== 0)
	{
		retorno = 1;
		switch (auxPosicion)
		{
			case 1:
				strcpy(arrayJugador[id].posicion,"delantero");
				break;

			case 2:
				strcpy(arrayJugador[id].posicion,"mediocampista");
				break;

			case 3:
				strcpy(arrayJugador[id].posicion,"defensor");
				break;

			case 4:
				strcpy(arrayJugador[id].posicion,"arquero");
				break;
		}
	}

	return retorno;
}

/**
 * \fn int AltaDelCampoNumeroDeCamiseta(eJugador[], int)
 * \brief da de alta el numero de camiseta que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param idAutoincremental id autoincremental que almacena cada dato de cada jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int AltaDelCampoNumeroDeCamiseta(eJugador arrayJugador[], int idAutoincremental)
{
	int retorno;
	int id;
	int auxNumeroCamiseta;

	id = idAutoincremental;

	retorno = 0;

	if(utn_getNumero(&auxNumeroCamiseta, "\nIngrese el numero de camiseta del jugador: ", "Error", 1, 99, 3)== 0)
	{
		printf("\nSe cargo correctamente el numero de camiseta.");
		arrayJugador[id].numeroCamiseta = auxNumeroCamiseta;
		retorno = 1;
	}

	return retorno;
}

/**
 * \fn int AltaDelCampoConfederacion(eJugador[], eConfederacion[], int, int)
 * \brief da de alta la confederacion que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
 * \param TAMCONFEDERACION tamaño de array de eConfederacion
 * \param idAutoincremental id autoincremental que indica los datos del jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int AltaDelCampoConfederacion(eJugador arrayJugador[], eConfederacion arrayConfederacion[], int TAMCONFEDERACION, int idAutoincremental)
{
	int retorno;
	int id;
	int auxConfederacion;

	id = idAutoincremental;

	retorno = 0;

	MostrarConfederacion(arrayConfederacion, TAMCONFEDERACION);

	if(utn_getNumero(&auxConfederacion, "\nIngrese el id de la confederacion elegida: ", "Error", 1, 6, 3)== 0)
	{
		if(BuscarPorIDConfederacion(arrayConfederacion, TAMCONFEDERACION, auxConfederacion)>= 0)
		{
			arrayJugador[id].idConfederacion = auxConfederacion;
			printf("\nSe cargo correctamente la confederacion.");
			retorno = 1;
		}
	}

	return retorno;
}

/**
 * \fn int AltaDelCampoSalario(eJugador[], int)
 * \brief da de alta el salario que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param idAutoincremental id autoincremental que indica los datos del jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int AltaDelCampoSalario(eJugador arrayJugador[], int idAutoincremental)
{
	int retorno;
	int id;

	id = idAutoincremental;

	retorno = 0;

	if(utn_getNumeroFlotante(&arrayJugador[id].salario, "\nIngrese el salario del jugador: " , "Error", 1, 1000000, 3)== 0)
	{
		printf("\nSe cargo correctamente el salario.");
		retorno = 1;
	}

	return retorno;
}

/**
 * \fn int AltaDelCampoAniosDeContrato(eJugador[], int)
 * \brief da de alta el salario que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param idAutoincremental id autoincremental que indica los datos del jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int AltaDelCampoAniosDeContrato(eJugador arrayJugador[], int idAutoincremental)
{
	int retorno;
	int id;
	int auxAniosDeContrato;

	id = idAutoincremental;

	retorno = 0;

	if(utn_getNumero(&auxAniosDeContrato, "\nIngrese los anios de contrato: ", "Error", 1, 8, 3)==0)
	{
		arrayJugador[id].aniosContrato = auxAniosDeContrato;
		printf("\nSe cargo correctamente los anios de contrato.");
		retorno = 1;
	}

	return retorno;
}

/**
 * \fn int ModificacionCampoNombre(eJugador[], int, int)
 * \brief modifica el nombre que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño de array eJugador
 * \param idIngresado id autoincremental que indica los datos del jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int ModificacionCampoNombre(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado)
{
	int retorno;
	char auxNombre[50];

	retorno = 0;

	if(BuscarPorIDJugador(arrayJugador, TAMJUGADOR, idIngresado)>= 0)
	{
		//si lo encuentra guarda el titulo a modificar en un auxiliar y se modifica en el array
		if(utn_getNombre(auxNombre, 50, "\nIngrese el nuevo nombre: ", "Error", 4)== 0)
		{
			strcpy(arrayJugador[idIngresado].nombre,auxNombre);
			retorno = 1;
			//break;
		}
	}

	return retorno;
}

/**
 * \fn int ModificacionCampoPosicion(eJugador[], int, int)
 * \brief  modifica la posicion que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño de array eJugador
 * \param idIngresado id autoincremental que indica los datos del jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int ModificacionCampoPosicion(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado)
{
	int retorno;
	int auxPosicion;

	retorno = 0;

	if(BuscarPorIDJugador(arrayJugador, TAMJUGADOR, idIngresado)>= 0)
	{
		if(utn_getNumero(&auxPosicion, "\nIngrese la posicion del jugador(1: delantero, 2: mediocampista, 3: defensor y 4: arquero): ", "Error", 1, 4, 3)== 0)
		{
			switch (auxPosicion)
			{
				case 1:
					strcpy(arrayJugador[idIngresado].posicion,"delantero");
					break;

				case 2:
					strcpy(arrayJugador[idIngresado].posicion,"mediocampista");
					break;

				case 3:
					strcpy(arrayJugador[idIngresado].posicion,"defensor");
					break;

				case 4:
					strcpy(arrayJugador[idIngresado].posicion,"arquero");
					break;
			}
			retorno = 1;
		}
	}

	return retorno;
}

/**
 * \fn int ModificacionCampoNumeroDeCamiseta(eJugador[], int, int)
 * \brief modifica el numero de camiseta que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño de array eJugador
 * \param idIngresado id autoincremental que indica los datos del jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int ModificacionCampoNumeroDeCamiseta(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado)
{
	int retorno;
	int auxNumeroCamiseta;

	retorno = 0;

	if(BuscarPorIDJugador(arrayJugador, TAMJUGADOR, idIngresado) >= 0)
	{
		if(utn_getNumero(&auxNumeroCamiseta, "\nIngrese el nuevo numero de camiseta del jugador: ", "Error", 1, 99, 3)== 0)
		{
			arrayJugador[idIngresado].numeroCamiseta = auxNumeroCamiseta;
			retorno = 1;
		}
	}

	return retorno;
}

/**
 * \fn int ModificacionCampoConfederacion(eJugador[], int, eConfederacion[], int, int)
 * \brief modifica la confederacion que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño de array eJugador
 * \param arrayConfederacion pertenece a eConfederacion y guarda sus datos
 * \param TAMCONFEDERACION tamaño de array eConfederacion
 * \param idIngresado id autoincremental que indica los datos del jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int ModificacionCampoConfederacion(eJugador arrayJugador[], int TAMJUGADOR,eConfederacion arrayConfederacion[],int TAMCONFEDERACION, int idIngresado)
{
	int retorno;
	int auxConfederacion;

	retorno = 0;

	MostrarConfederacion(arrayConfederacion, TAMCONFEDERACION);
	if(BuscarPorIDJugador(arrayJugador, TAMJUGADOR, idIngresado)>= 0)
	{
		if(utn_getNumero(&auxConfederacion, "\nIngrese el nuevo id de la confederacion elegida: ", "Error", 1, 6, 3)== 0)
		{
			if(BuscarPorIDConfederacion(arrayConfederacion, TAMCONFEDERACION, auxConfederacion) >= 0)
			{
				arrayJugador[idIngresado].idConfederacion = auxConfederacion;
				retorno = 1;
			}
		}
	}

	return retorno;
}

/**
 * \fn int ModificacionCampoSalario(eJugador[], int, int)
 * \brief modifica el salario que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño de array eJugador
 * \param idIngresado id autoincremental que indica los datos del jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int ModificacionCampoSalario(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado)
{
	int retorno;
	int auxSalario;

	retorno = 0;

	if(BuscarPorIDJugador(arrayJugador, TAMJUGADOR, idIngresado)>= 0)
	{
		if(utn_getNumero(&auxSalario, "\nIngrese el nuevo salario: ", "\nError\n", 1, 1000000, 3)== 0)
		{
			arrayJugador[idIngresado].salario = auxSalario;
			retorno = 1;
		}
	}

	return retorno;
}

/**
 * \fn int ModificacionCampoAniosDeContrato(eJugador[], int, int)
 * \brief modifica los anios de contrato que ingresa el usuario
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAMJUGADOR tamaño de array eJugador
 * \param idIngresado id autoincremental que indica los datos del jugador
 * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
 */
int ModificacionCampoAniosDeContrato(eJugador arrayJugador[], int TAMJUGADOR, int idIngresado)
{
	int retorno;
	int auxAnioContrato;

	retorno = 0;

	if(BuscarPorIDJugador(arrayJugador, TAMJUGADOR, idIngresado)>= 0)
	{
		if(utn_getNumero(&auxAnioContrato, "\nIngrese los nuevos anios de contrato: ", "\nError\n", 1, 8, 3)== 0)
		{
			for(int i = 0; i < TAMJUGADOR ; i++)
			{
				arrayJugador[idIngresado].aniosContrato = auxAnioContrato;
				retorno = 1;
			}
		}
	}


	return retorno;
}
 /**
   * \fn int ValidacionExitenciaJugadores(eJugador[], int)
  * \brief valida que array tenga datos cargados
  *
  * \param arrayJugador pertenece a eJugador y guarda sus datos
  * \param TAMJUGADORES tamaño de array eJugador
  * \return devuelve 1 si salio todo bien y 0 cuando salio hubo error
  */
int ValidacionExitenciaJugadores(eJugador arrayJugador[], int TAMJUGADORES)
{
	int retorno;

	retorno = 1;

	for(int i = 0; i < TAMJUGADORES; i++)
	{
		if(arrayJugador != NULL && arrayJugador[i].isEmpty == OCUPADO)
		{
			retorno = 1;
		}
	}
	return retorno;
}

/**
 * \fn int BuscarPorIDJugador(eJugador[], int, int)
 * \brief busca el id que este libre y verefica que este ocupado
 *
 * \param arrayJugador pertenece a eJugador y guarda sus datos
 * \param TAM tamaño de array eJugador
 * \param idIngresado id autoincremental que indica los datos del jugador
 * \return devuelve el id encontrado
 */
int BuscarPorIDJugador(eJugador arrayJugador[], int TAM, int idIngresado)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (arrayJugador != NULL && TAM > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < TAM; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (arrayJugador[i].id == idIngresado && arrayJugador[i].isEmpty == OCUPADO) {
				//SI ENCONTRE EL ID
				//DEVUELVO EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}
