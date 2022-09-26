/*
 Debemos conformar un equipo para competir en el próximo mundial.
La formación del equipo titular será 1-4-4-2 (arquero, defensores, mediocampistas y
delanteros).
Hay que tener presente que no podemos superar la cantidad máxima de 22 jugadores y
no más de dos por posición, es decir, en total deberíamos tener 2 arqueros, 8 defensores,
8 mediocampistas y 4 delanteros (teniendo en cuenta titulares y suplentes).
Dicho plantel contara con un costo de mantenimiento, que va a estar compuesto por:
Gastos de Transporte, Hospedaje y Comida. El usuario deberá cargar todos los gastos.
Nota: de estos 3 valores surge el gasto de mantenimiento.
Los jugadores pueden desarrollar sus actividades en cualquiera de las 6 confederaciones:
AFC en Asia; CAF en África; CONCACAF en zona del Norte; CONMEBOL en Sudamérica;
UEFA en Europa; OFC en Oceanía;

Nota: en esta sección solo se calcularan los valores de los datos solicitados, NO se deberán
imprimir, solo informar que se realizaron correctamente los siguientes caculos:
a. Calcular el promedio de jugadores de cada mercado.
b. Calcular el costo de mantenimiento.
c. Si la mayoría del plantel está compuesta por jugadores de la confederación europea el costo
de mantenimiento recibe un aumento del 35%.

*/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ingreso_de_datos.h"
#include "realizacion_de_calculos.h"
//#define	OCUPADO  1
//#define LIBRE  0

int main(void)
{

	setbuf(stdout, NULL);
	// la opcion que el usuario implementa en el menu
	int opcion;
	// variables para la opcion 1 del menu
	float costoHospedaje;
	float costoComida;
	float costoTranporte;
	// variables para la opcion 2 del menu
	int posicionIngresada;
	int contadorAFC;
	int contadorCAF;
	int contadorCONCACAF;
	int contadorCONMEBOL;
	int contadorUEFA;
	int contadorOFC;
	int numeroDeCamiseta;
	int cantidadDeArquero;
	int cantidadDeDefensor;
	int cantidadDeMediocampista;
	int cantidadDeDelantero;
	int contadorDeJugador;
	char respuesta;
	//vairialbles de la opcion 3 y 4
	float promedioAFC;
	float promedioCAF;
	float promedioCONCACAF;
	float promedioCONMEBOL;
	float promedioUEFA;
	float promedioOFC;
	float costoTotalDeMantenimiento;
	int estadoMenuCalculos;
	float porcentajeUEFA;
	float aumentoParaUEFA;
	float costoDeMantenimientoConAumento;

	contadorAFC = 0;
	contadorCAF = 0;
	contadorCONCACAF = 0;
	contadorCONMEBOL = 0;
	contadorUEFA = 0;
	contadorOFC = 0;
	cantidadDeArquero = 0;
	cantidadDeDefensor = 0;
	cantidadDeDelantero = 0;
	cantidadDeMediocampista = 0;
	costoComida = 0;
	costoHospedaje = 0;
	costoTranporte = 0;
	contadorDeJugador = 0;
	estadoMenuCalculos = 0;
	aumentoParaUEFA = 0;
	costoDeMantenimientoConAumento = 0;

	do{
		//inicio del programa
		printf("\n\tBienvenido al menu\n\n");
		printf("1: Ingrese costos de mantinimiento.\n");
		printf("El costo de hospedaje es: %.2f\n",costoHospedaje);
		printf("El costo de comida es: %.2f\n",costoComida);
		printf("El costo de transporte es: %.2f\n\n",costoTranporte);
		printf("2: Carga de jugadores.\n");
		printf("La cantidad de arqueros es: %d\n",cantidadDeArquero);
		printf("La cantidad de defensores es: %d\n",cantidadDeDefensor);
		printf("La cantidad de mediocampistas es: %d\n",cantidadDeMediocampista);
		printf("La cantidad de delanteros es: %d\n\n",cantidadDeDelantero);
		printf("3: Realizar todos los calculos.\n\n");
		printf("4: Informar todos los resultados.\n\n");
		printf("5: Salir.\n\n");

		utn_getNumeroInt(&opcion, "Ingrese aqui la opcion de menu: ", "Error opcion no valida\n", 1, 5, 3);

		//ingreso de la opcion del usuario navegando por el menu
		switch(opcion)
		{
			case 1:
				//en este caso y funcion se ingresan los costos de mantenimiento
				IngresoDeCostos(&costoHospedaje,&costoComida,&costoTranporte);
			break;

			case 2:
				do{
					//en esta parte es la opcion del menu 2 donde se valida el ingreso de datos de los jugadores

					//Ingreso del numero de camiseta con la funcion que valide el numero
					utn_getNumeroInt(&numeroDeCamiseta, "\nIngrese su numero de camiseta: ", "\nError, reingrese su numero de camiseta: \n", 1, 99, 4);
					//Ingreso de la poscion de los jugadores contando por cada caso por si supera el numero permitido y validando su confederacion en una funcion
					printf("\nIngrese su posicion:\n"
							"1. Arquero.\n"
							"2. Defensores.\n"
							"3. Mediocampista.\n"
							"4. Delantero\n");
					utn_getNumeroInt(&posicionIngresada,"\nIngrese aqui la opcion de menu:", "\nError opcion no valida\n", 1, 4, 3);
					switch(posicionIngresada)
					{
						case 1:
							if(cantidadDeArquero < 2)
							{
								cantidadDeArquero++;
								contadorDeJugador++;
								IngresoDeConfedarcion(&contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC);
							}
							else
							{
								printf("\nNumero de posiciones superada\n");
							}
							break;
						case 2:
							if(cantidadDeDefensor < 8)
							{
								cantidadDeDefensor++;
								contadorDeJugador++;
								IngresoDeConfedarcion(&contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC);
							}
							else
							{
								printf("\nNumero de posiciones superada\n");
							}
							break;
						case 3:
							if(cantidadDeMediocampista < 8)
							{
								cantidadDeMediocampista++;
								contadorDeJugador++;
								IngresoDeConfedarcion(&contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC);
							}
							else
							{
								printf("\nNumero de posiciones superada\n");
							}
							break;
						case 4:
							if(cantidadDeDelantero < 4)
							{
								cantidadDeDelantero++;
								contadorDeJugador++;
								IngresoDeConfedarcion(&contadorAFC, &contadorCAF, &contadorCONCACAF, &contadorCONMEBOL, &contadorUEFA, &contadorOFC);
							}
							else
							{
								printf("\nNumero de posiciones superada\n");
							}
							break;
					}

					printf("\nDesea continuar?(s/n):");
					scanf("%c", &respuesta);

				}while(respuesta != 'n');
					break;

				case 3:
					//validando de en el case 2 y 1 halla datos ingresados para realizar los calculos
					if(costoComida != 0 && costoHospedaje != 0 && costoTranporte != 0 && contadorDeJugador != 0)
					{
						promedioAFC = Promedio(contadorAFC, contadorDeJugador);
						promedioCAF = Promedio(contadorCAF, contadorDeJugador);
						promedioCONCACAF = Promedio(contadorCONCACAF, contadorDeJugador);
						promedioCONMEBOL = Promedio(contadorCONMEBOL, contadorDeJugador);
						promedioOFC = Promedio(contadorOFC, contadorDeJugador);
						promedioUEFA = Promedio(contadorUEFA, contadorDeJugador);

						costoTotalDeMantenimiento = costoComida + costoTranporte + costoHospedaje;

						estadoMenuCalculos = 1;

						porcentajeUEFA = contadorUEFA * 100 / contadorDeJugador;

						printf("\nSe hicieron correctamente los calculos\n");
					}
					else
					{
						printf("\nNo se hicieron correctamente los calculos\n");
					}
					break;
				case 4:
					//validacion que los datos y los calculos para mostras las operaciones realizadas
					if(estadoMenuCalculos == 1)
					{
						printf("Promedio AFC: %.2f\n"
								"Promedio CAF: %.2f\n"
								"Promedio CONCACAF: %.2f\n"
								"Promedio CONMEBOL: %.2f\n"
								"Promedio OFC: %.2f\n"
								"Promedio UEFA: %.2f\n",promedioAFC,promedioCAF,promedioCONCACAF,promedioCONMEBOL,promedioOFC,promedioUEFA);
						//en caso de que la UEFA tenga mayoria de jugadores se hace un aumeto del %35
						if(porcentajeUEFA > 50)
						{
							costoDeMantenimientoConAumento = AumentoParaCostoFinal(&aumentoParaUEFA, costoTotalDeMantenimiento);
							printf("\nEl costo era de %.2f y recibio un aumento de %.2f\n, el valor del monto ahora es %.2f\n",costoTotalDeMantenimiento, aumentoParaUEFA, costoDeMantenimientoConAumento);
						}
						else
						{
							printf("\nEl costo total de mantenimiento total es: %.2f\n\n", costoTotalDeMantenimiento);
						}

						printf("\nDesea volver al menu principal?(s/n): \n");
						scanf("%c",&respuesta);

						if(respuesta == 's')
						{
							break;
						}
					}
					else
					{
						printf("\nNo se realizo ningun calculo\n");
					}
					break;
		}
	}while(opcion != 5);

	printf("Acaba de salir del menu");

}
