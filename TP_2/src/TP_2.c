/*
 Ivan Ramiro Paz Agüero 1k

*/

#include <stdio.h>
#include <stdlib.h>
#include "datos_de_jugador.h"
#include "datos_de_confederaciones.h"
#include "utn.h"
#include "salida_de_datos.h"

int main(void) {

	setbuf(stdout, NULL);

	eConfederacion confederacion[]= {{1, "CONMEBOL", "SUDAMERICA",1916},
									{2, "UEFA", "EUROPA", 1954},
									{3, "AFC", "ASIA", 1954},
									{4, "CAF", "AFRICA", 1957},
									{5, "CONCAF", "NORTE Y CENTRO AMERICA", 1961},
									{6, "OFC", "OCEANIA", 1966}};

	eJugador jugador[SIZEJUGADOR];

	int respuesta;
	int idAutoincremental;
	char opcionSalir[10];
	//float acumulador;
	int contadorDeJugador;

	idAutoincremental = 0;

	contadorDeJugador = 0;

	InicializarEstadoJugador(jugador, SIZEJUGADOR);

	do{
		printf("\tMenu principal.\n"
				"1: Para dar de alta al jugador.\n"
				"2: Para dar de baja al jugador.\n"
				"3: Para modificar los datos del jugador.\n"
				"4: Para ver los informes.\n"
				"5: Para salir\n");
		if(utn_getNumero(&respuesta, "\nIngrese su respuesta: ", "Error respuesta no valida", 1, 5, 3)== 0)
		{
			switch (respuesta)
			{
				case 1:
					//alta
					if(AltaDeJugador(jugador, SIZEJUGADOR, confederacion, SIZECONFEDERACION, idAutoincremental) == 1)
					{
						idAutoincremental++;
						printf("\nSe cargo correctamente los datos del jugador.\n");
						contadorDeJugador++;
					}
					else
					{
						printf("\nError no se cargo correctamente los datos.\n");
					}
					break;
				case 2:
					//baja
					if(ValidacionExitenciaJugadores(jugador, SIZEJUGADOR)== 1)
					{
						if(BajaDeJugador(jugador, SIZEJUGADOR)== 1)
						{
							printf("\nSe dio de baja al jugador correctamente.\n");
							contadorDeJugador--;
						}
						else
						{
							printf("\nError no se dio de baja correctamente.\n");
						}
					}
					else
					{
						printf("\nNo se cargo ningun jugador.\n");
					}
					break;
				case 3:
					//modificacion

					if(ValidacionExitenciaJugadores(jugador, SIZEJUGADOR)== 1)
					{
						if(ModificacionDeJugador(jugador, SIZEJUGADOR,confederacion, SIZECONFEDERACION, idAutoincremental)==1)
						{
							printf("\nSe modifico correctamente los datos del jugador.\n");
						}
						else
						{
							printf("\nError no se dio de baja correctamente.\n");
						}
					}
					else
					{
						printf("\nNo se cargo ningun jugador.\n");
					}
					break;
				case 4:
					//informes
					if(ValidacionExitenciaJugadores(jugador, SIZEJUGADOR)== 1)
					{
						MenuInformes(jugador, SIZEJUGADOR, confederacion, SIZECONFEDERACION, contadorDeJugador);
					}
					else
					{
						printf("\nNo se cargo ningun jugador.\n");
					}
					break;
				case 5:
					//salida del programa
					if(utn_getDescripcion(opcionSalir, 10,"\nDesea salir(s/n): ", "\Error\n", 3) == 0)
					{
						switch (opcionSalir[10])
						{
							case 'n':
								printf("Volvio al menu principal.");
								break;

						}
					}
			}
		}


	}while(respuesta != 5);

	printf("Fin del programa.");
}
