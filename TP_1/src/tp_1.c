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
int main(void) {

	setbuf(stdout, NULL);

	int costosHospedaje;
	int costosComida;
	int costosTranporte;
	int opcion;
	int i;
	int respuesta;
	int estado;
	int confederacionIngresada;
	int contadorAFC;
	int contadorCAF;
	int contadorCONCACAF;
	int contadorCONMEBOL;
	int contadorUEFA;
	int contadorOFC;
	int numeroDeCamiseta;
	int posicionIngresada;
	int cantidadDeArqueros;
	int cantidadDeDefensores;
	int cantidadDeMediocampistas;
	int cantidadDeDelanteros;

	contadorAFC = 0;
	contadorCAF = 0;
	contadorCONCACAF = 0;
	contadorCONMEBOL = 0;
	contadorUEFA = 0;
	contadorOFC = 0;
	cantidadDeArqueros = 0;
	cantidadDeDefensores = 0;
	cantidadDeDelanteros = 0;
	cantidadDeMediocampistas = 0;

	estado = 0;

	for(i = 0; i < 22; i++)
	{
		do{
			printf("Bienvenido al menu\n"
					"1: Ingrese costos de mantinimiento.\n"
					"2: Carga de jugadores.\n"
					"3: Realizar todos los calculos.\n"
					"4: Informar todos los resultados.\n"
					"5: Salir.\n");

			//printf("Ingrese su respusta: ");
			utn_getNumero(&opcion, "Ingrese aqui la opcion de menu: ", "Error\n", 1, 5, 3);
			//scanf("%d", &respuesta);
			switch(opcion)
			{
				case 1:
					for(i = 0; i < 22; i++)
					{
						//estado = 0;
						if(i > 0)
						{
							printf("Ingrese los costos de hospedaje: ");
							scanf("%d", &costosHospedaje);

							printf("Ingrese los costos de comida: ");
							scanf("%d", &costosComida);

							printf("Ingrese los costos de transporte: ");
							scanf("%d", &costosTranporte);

							estado = 1;
						}

						if(estado == 1)
						{
							break;
						}
					}

					break;

				case 2:
					for(i = 0; i < 22; i++)
					{
						if(i > 0)
						{
							printf("Ingrese a que conferacion pertenece:\n"
									"1. AFC.\n"
									"2. CAF.\n"
									"3. CONCACAF.\n"
									"4. CONMEBOL.\n"
									"5. UEFA.\n"
									"6. OFC.\n");

							printf("Ingrese su opcion: ");
							scanf("%d", &confederacionIngresada);

							switch(confederacionIngresada)
							{
								case 1:
									contadorAFC++;
									break;
								case 2:
									contadorCAF++;
									break;
								case 3:
									contadorCONCACAF++;
									break;
								case 4:
									contadorCONMEBOL++;
									break;
								case 5:
									contadorUEFA++;
								case 6:
									contadorOFC++;
								default:
									break;
							}

							printf("Ingrese su numero de camiseta: ");
							scanf("%d", &numeroDeCamiseta);
							while(numeroDeCamiseta < 1 || numeroDeCamiseta > 99)
							{
								printf("Error, reingrese su numero de camiseta: ");
								scanf("%d", &numeroDeCamiseta);
							}

							printf("Ingrese su posicion:\n"
									"1. Arquero.\n"
									"2. Defensores.\n"
									"3. Mediocampista.\n"
									"4. Delantero\n");

							printf("Ingrese su opcion: ");
							scanf("%d", &posicionIngresada);
							switch(posicionIngresada)
							{
								case 1:
									while(cantidadDeArqueros > 2)
									{
										cantidadDeArqueros++;
									}
									break;
								case 2:
									while(cantidadDeDefensores > 8)
									{
										cantidadDeDefensores++;
									}
									break;
								case 3:
									while(cantidadDeMediocampistas > 8)
									{
										cantidadDeMediocampistas++;
									}
									break;
								case 4:
									while(cantidadDeDelanteros > 4)
									{
										cantidadDeDelanteros++;
									}
									break;
							}

							printf("La cantidad de arqueros es: %d\n", cantidadDeArqueros);
							printf("La cantidad de defensores es: %d\n", cantidadDeDefensores);
							printf("La cantidad de mediocampistas es: %d\n", cantidadDeMediocampistas);
							printf("La cantidad de delanteros es: %d\n", cantidadDeDelanteros);

						}
					}
					break;
				case 3:
					break;
				case 4:
					break;

			}

		}while(opcion != 5);
	}
}
