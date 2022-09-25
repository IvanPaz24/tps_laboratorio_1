/*
 * utn.c
 *
 *  Created on: 18 sep. 2022
 *      Author: ivan_
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica(char* cadena, int limite);
static int getInt(int* pResultado);
static int esNumericaFloat(char* cadena, int limite);
static int getFloat(float* pResultado);
static int myGets(char* cadena, int longitud);

/**
 * \fn static int myGets(char*, int)
 *
 * \brief 			 lee de stdin(archivo) hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 					 un maximo de 'longitud - 1' caracteres.
 * 					 (se encarga de no desbordar el bufferString)
 *
 * \param cadena	 puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud	 define el tamaño de la cadena
 * \return			 retorna 0 (EXITO) si se obtine una cadena y -1 (ERROR) si no
 */
static int myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[4096];  //se puede mejorar

	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/**
 * \fn static int esNumerica(char*, int)
 *
 * \brief			verifica si la cadena ingresada es numerica
 *
 * \param cadena	cadena de caracteres a ser analizada
 * \param limite	limite de la cadena de caracteres
 * \return			retorna 1 (VERDADERO) si la cadena es numerica y 0 (FALSO) si no lo es
 */
static int esNumerica(char* cadena, int limite)
{
	int retorno = 1;

	for(int i=0; i<limite && cadena[i]!='\0'; i++)
	{
		if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
		{
			continue;
		}
		if(cadena[i]<'0' || cadena[i]>'9')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/**
 * \fn static int getInt(int*)
 *
 * \brief 				obtiene un numero entero
 *
 * \param pResultado	puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return				retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];
	if(pResultado != NULL &&
		myGets(bufferString, sizeof(bufferString)) == 0 &&
		esNumerica(bufferString, sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atoi(bufferString);
	}
	return retorno;
}

/**
 * \fn int utn_getNumeroInt(int*, char*, char*, int, int, int)
 *
 * \brief				 solicita un nº entero al usuario, lo verifica y lo devuelve
 *
 * \param pResultado     puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param pMensaje       mensaje de ingreso que se muestra
 * \param pMensajeError	 mensaje de error que se muestra
 * \param minimo 		 valor minimo aceptable(incluido)
 * \param maximo		 valor maximo aceptable(incluido)
 * \param reintentos 	 cant de veces que se el usuario puede equivocarse antes de retornar -1(incluye el intento 0)
 * \return 				 retorna 0 (EXITO) si obtuvo el numero y -1 (ERROR) si no lo obtuvo
 */
int utn_getNumeroInt(int*pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);

			if(getInt(&bufferInt) == 0 &&
				bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n", pMensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \fn static int esNumericaFloat(char*, int)
 *
 * \brief			verifica si la cadena ingresada es numerica y es float
 *
 * \param cadena	cadena de caracteres a ser analizada
 * \param limite	limite de la cadena de caracteres
 * \return			retorna 1 (VERDADERO) si la cadena es numerica y 0 (FALSO) si no lo es
 */
static int esNumericaFloat(char* cadena, int limite)
{
	int retorno = 1;
	int flagPrimerPunto = 0;

	for(int i=0; i<limite && cadena[i]!='\0'; i++)
	{
		if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
		{
			continue;
		}
		if(cadena[i] == '.' && flagPrimerPunto == 0)
		{
			flagPrimerPunto = 1;
			continue;
		}

		if(cadena[i]<'0' || cadena[i]>'9')
		{
			retorno = 0;
			break;
		}
	}
	return retorno;
}

/** ta joya
 * \fn static int getIFloat(int*)
 *
 * \brief 				obtiene un numero flotante (no contempla cantidad de decimales)
 *
 * \param pResultado	puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return				retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 */
static int getFloat(float* pResultado)
{
	int retorno = -1;
	char bufferString[50];
	if(pResultado != NULL &&
		myGets(bufferString, sizeof(bufferString)) == 0 &&
		esNumericaFloat(bufferString, sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atof(bufferString);
	}
	return retorno;
}

/**
 * \fn int utn_getNumeroFloat(float*, char*, char*, float, float, int)
 *
 * \brief				 solicita un nº float al usuario, lo verifica y lo devuelve(no contempla cantidad de decimales)
 *
 * \param pResultado     puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param pMensaje       mensaje de ingreso que se muestra
 * \param pMensajeError	 mensaje de error que se muestra
 * \param minimo 		 valor minimo aceptable(incluido)
 * \param maximo		 valor maximo aceptable(incluido)
 * \param reintentos 	 cant de veces que se el usuario puede equivocarse antes de retornar -1
 * \return 				 retorna 0 (EXITO) si obtuvo el numero y -1 (ERROR) si no lo obtuvo
 */
int utn_getNumeroFloat(float*pResultado, char*pMensaje, char*pMensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			if(getFloat(&bufferFloat) == 0 &&
				bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n", pMensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \fn int utn_getCarater(char*, char*, char*, char, char, int)
 *
 * \brief				 solicita un caracter al usuario, lo verifica y lo devuelve
 *
 * \param pResultado     puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param pMensaje       mensaje de ingreso que se muestra
 * \param pMensajeError	 mensaje de error que se muestra
 * \param minimo 		 valor minimo aceptable(incluido)
 * \param maximo		 valor maximo aceptable(incluido)
 * \param reintentos 	 cant de veces que se el usuario puede equivocarse antes de retornar -1
 * \return 				 retorna 0 (EXITO) si obtuvo el caracter y -1 (ERROR) si no lo obtuvo
 */
int utn_getCarater(char*pResultado, char*pMensaje, char*pMensajeError, char minimo, char maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			fflush(stdin);
			scanf("%c", &bufferChar);

			if(bufferChar >= minimo && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s\n", pMensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

