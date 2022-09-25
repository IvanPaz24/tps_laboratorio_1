/*
 * utn.h
 *
 *  Created on: 18 sep. 2022
 *      Author: ivan_
 */

#ifndef UTN_H_
#define UTN_H_


int utn_getNumeroInt(int*pResultado, char*pMensaje, char*pMensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFloat(float*pResultado, char*pMensaje, char*pMensajeError, float minimo, float maximo, int reintentos);
int utn_getCarater(char*pResultado, char*pMensaje, char*pMensajeError, char minimo, char maximo, int reintentos);

#endif /* UTN_H_ */
