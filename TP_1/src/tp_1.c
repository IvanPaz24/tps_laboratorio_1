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
int main(void)
{

	setbuf(stdout, NULL);

	float costosHospedaje;
	float costosComida;
	float costosTranporte;
	int opcion;
	//int i;
	int subMenu = 0;
	//int estadoSubmenu = 0;
	//int estado;
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
	int contadorDeJugadores;

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
	costosComida = 0;
	costosHospedaje = 0;
	costosTranporte = 0;
	contadorDeJugadores = 0;

	//estado = 0;

	//for(i = 0; i < 22; i++)
	//{
		do{
			printf("\tBienvenido al menu\n\n");
			printf("1: Ingrese costos de mantinimiento.\n");
			printf("El costo de hospedaje es: %.2f\n",costosHospedaje);
			printf("El costo de comida es: %.2f\n",costosComida);
			printf("El costo de transporte es: %.2f\n\n",costosTranporte);
			printf("2: Carga de jugadores.\n");
			printf("La cantidad de arqueros es: %d\n",cantidadDeArqueros);
			printf("La cantidad de defensores es: %d\n",cantidadDeDefensores);
			printf("La cantidad de mediocampistas es: %d\n",cantidadDeMediocampistas);
			printf("La cantidad de delanteros es: %d\n\n",cantidadDeDelanteros);
			printf("3: Realizar todos los calculos.\n\n");
			printf("4: Informar todos los resultados.\n\n");
			printf("5: Salir.\n\n");

				//printf("Ingrese su respusta: ");
			utn_getNumero(&opcion, "Ingrese aqui la opcion de menu: \n", "Error\n", 1, 5, 3);
				//scanf("%d", &respuesta);

			switch(opcion)
			{
				case 1:
					do
					{
						printf("Elija el costo que desea ingresar:\n"
								"1: Para costos de hospedaje.\n"
								"2: Para costos de comida.\n"
								"3: Para costos de transporte.\n"
								"4: Para salir.\n");
						printf("Ingrese aqui la opcion de menu: \n");
						scanf("%d", &subMenu);
						switch(subMenu)
						{
							case 1:
								printf("Ingrese los costos de hospedaje: ");
								scanf("%f", &costosHospedaje);
								break;
							case 2:
								printf("Ingrese los costos de comida: ");
								scanf("%f", &costosComida);
								break;
							case 3:
								printf("Ingrese los costos de transporte: ");
								scanf("%f", &costosTranporte);
								break;
							case 4:
								//estadoSubmenu = 1;
								break;
						}
					}while(subMenu != 4);

				break;

				case 2:
					do{

						contadorDeJugadores++;
						printf("Ingrese los datos de los jugadores\n"
								"1: Numero de camiseta.\n"
								"2: Posicion de jugador.\n"
								"3: Conferacion a la que pertenece.\n"
								"4: Salir.\n");
						printf("Ingrese aqui la opcion de menu:\n");
						scanf("%d", &subMenu);

						switch (subMenu)
						{
							case 1:
								printf("Ingrese su numero de camiseta: ");
								scanf("%d", &numeroDeCamiseta);
								while(numeroDeCamiseta < 1 || numeroDeCamiseta > 99)
								{
									printf("Error, reingrese su numero de camiseta: ");
									scanf("%d", &numeroDeCamiseta);
								}
								break;
							case 2:
								printf("Ingrese su posicion:\n"
									"1. Arquero.\n"
									"2. Defensores.\n"
									"3. Mediocampista.\n"
									"4. Delantero\n"
									"5. Salir\n");

								printf("Ingrese su opcion: \n");
								scanf("%d", &posicionIngresada);
								switch(posicionIngresada)
								{
									case 1:
										if(cantidadDeArqueros > 2)
										{
											cantidadDeArqueros++;
										}
										else
										{
											printf("Numero de posiciones superada");
										}
										break;
									case 2:
										if(cantidadDeDefensores > 8)
										{
											cantidadDeDefensores++;
										}
										else
										{
											printf("Numero de posiciones superada");
										}
										break;
									case 3:
										if(cantidadDeMediocampistas > 8)
										{
											cantidadDeMediocampistas++;
										}
										else
										{
											printf("Numero de posiciones superada");
										}
										break;
									case 4:
										if(cantidadDeDelanteros > 4)
										{
											cantidadDeDelanteros++;
										}
										else
										{
											printf("Numero de posiciones superada");
										}
										break;
									case 5:
										break;
								}
									break;
								case 3:
									printf("Ingrese a que conferacion pertenece:\n"
											"1. AFC.\n"
											"2. CAF.\n"
											"3. CONCACAF.\n"
											"4. CONMEBOL.\n"
											"5. UEFA.\n"
											"6. OFC.\n"
											"7. Salir");
									printf("Ingrese su opcion: \n");
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
											break;
										case 6:
											contadorOFC++;
											break;
										default:
											break;
									}
										break;
									case 4:
										break;
						}


						}while(subMenu != 4);
						break;
					case 3:

						break;
					case 4:
						break;


			}
					//estado = 1;
			//}
		}while(opcion != 5);

}
