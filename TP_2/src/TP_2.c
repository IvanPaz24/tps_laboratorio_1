/*
 Ivan Ramiro Paz Agüero 1k

*/

#include <stdio.h>
#include <stdlib.h>
#include "datos_de_jugador.h"
#include "utn.h"

int main(void) {

	setbuf(stdout, NULL);

	eConfederacion confederacion[]= {{1, "CONMEBOL", "SUDAMERICA",1916},
									{2, "UEFA", "EUROPA", 1954},
									{3, "AFC", "ASIA", 1954},
									{4, "CAF", "AFRICA", 1957},
									{5, "CONCAF", "NORTE Y CENTRO AMERICA", 1961},
									{6, "OFC", "OCEANIA", 1966}};

	eJugador jugador[3000];

	int respuesta;
	int idAutoincremental;

	idAutoincremental = 0;

	InicializarEstado(jugador, 3000);
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
					if((AltaDeJugador(jugador, 3000, confederacion, idAutoincremental)) == 1)
					{
						idAutoincremental++;
						printf("Se cargo correctamente los datos del jugador");
					}
					break;
				case 2:
					//baja
					if(BajaDeJugador(jugador, 3000)== 1)
					{
						printf("Se dio de baja al jugador correctamente");
					}
					else
					{
						printf("Error no se dio de baja correctamente");
					}
					break;
				case 3:
					//modificacion
					break;
				case 4:
					//informes
					break;
			}
		}


	}while(respuesta != 5);

	printf("Fin del programa");
}
