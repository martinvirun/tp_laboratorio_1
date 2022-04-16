/*
 ============================================================================
 Name        : TrabajoPractico-01.c
 Author      : martin
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tp1.h"
#define DESCUENTO 0.1
#define AUMENTO 0.25
#define BIT 4606954.55


/*“Latam:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
Aerolíneas:
a) Precio con tarjeta de débito: r
b) Precio con tarjeta de crédito: r
c) Precio pagando con bitcoin : r
d) Precio unitario: r
La diferencia de precio es*/

int main(void) {
	int opcion =0;
	float kilometros;
	float precio[3];
	float preciosLatam[5];
	float preciosAerolineas[5];
	float diferencia;
	int intentos =0;



	printf("¡¡¡Hola!!!, este es el sistema de informacion al viajero.\n");
			do{
				printf("\nSus opciones son : "
				"\n 1- Ingrese cantidad de kilomentros. "
			    "\n 2- Ingresar Precio de Vuelos."
				"\n 3- Calcular todos los costos."
				"\n 4- Informar resultados."
				"\n 5- Carga forzada."
				"\n 6- Salir."
			    "\n Ingrese una opcion :\n");
				scanf("%d",&opcion);

                if(opcion>0&&opcion<7){
				switch (opcion){
					case 1:
						intentos=0;
						printf("ingrese cantidad de kilometros de su vuelo: \n");
						scanf("%f",&kilometros);

					while (kilometros <=0){
						intentos ++;
						printf("por favor ingrese una cantidad valida.\n");
						scanf("%f",&kilometros);

						if (intentos >2){
							printf("Usted ingreso datos invalidos reiteradas veces ,vuelva a intentarlo desde el comiezo.\n"
									"Elija la opcion 1 cuando sepa la cantidad de kms.");
							break;
							}
						}
					break;
					case 2:
						printf("Ingrese precio del vuelo por Aetolineas:\n");
						scanf("%f",&precio[1]);

					while (precio[1]<=0){
						printf("Por favor ingrese una cantidad valida:");
			            scanf("%f",&precio[1]);}

						printf("Ingrese precio del vuelo por Latam:\n");
				        scanf("%f",&precio[0]);
				    while (precio[0] <=0){
				        printf("Por favor ingrese una cantidad valida:");
				        scanf("%f",&precio[0]);
				    }
					break;
					case 3:
						 get_descontar(&preciosLatam[0],precio[0],DESCUENTO);
						 get_incrementar(&preciosLatam[1],precio[0],AUMENTO);
						 get_cambiarABitcoin(&preciosLatam[2],precio[0],BIT);
						 get_cotizarPorKm(&preciosLatam[3],precio[0],kilometros);
						 //*********************************************************
						 get_descontar(&preciosAerolineas[0],precio[1],DESCUENTO);
						 get_incrementar(&preciosAerolineas[1],precio[1],AUMENTO);
						 get_cambiarABitcoin(&preciosAerolineas[2],precio[1],BIT);
						 get_cotizarPorKm(&preciosAerolineas[3],precio[1],kilometros);
						 //**********************************************************
						 get_sacarDiferencia(&diferencia,precio[1],precio[0]);

						printf("\nLos calculos se han realizado con exito.\nPuede elegir la opcion 4 a continuacion para mostrar los resultados.\n");
                    break;
					case 4:
						printf("-----Datos Latam-----\n");
					    printf("A)-Los costos se detallaran a continuacion : \n");
						printf("B)-Valor Latam con debito :$%.2f ",preciosLatam[0]);
						printf("\nC)-Valor Latam con tarjeta de credito es de  :$%.2f ",preciosLatam[1]);
						printf("\nD)-Valor Latam con Bitcoin es de : %f BTC",preciosLatam[2]);
						printf("\nE)-El precio por kilometro es de :$%.2f \n",preciosLatam[3]);
						//***************************************************************
						printf("\n-----Datos Aerolineas-----\n");
						printf("A)-Los costos se detallaran a continuacion : \n");
						printf("B)-Valor Aerolineas con debito :$%.2f ",preciosAerolineas[0]);
						printf("\nC)-Valor Aerolineas con tarjeta de credito es de  :$%.2f ",preciosAerolineas[1]);
						printf("\nD)-Valor Aerolineas con Bitcoin es de : %f BTC",preciosAerolineas[2]);
						printf("\nE)-El precio por kilometro es de :$%.2f \n\n",preciosAerolineas[3]);
						if (precio[0]>precio[1]){
						   printf("La diferencia es de %.2f a favor de Aerolineas.\n",diferencia);
						}else {
						printf("La diferencia es de %.2f a favor de Latam.\n",diferencia);
						}

						break;
					case 5:
						 kilometros =  7090;
						 precio[1]= 162965;
					     precio[0]= 159339;

					     get_descontar(&preciosLatam[0],precio[0],DESCUENTO);
					     //Pide por referencia donde se va guardar el resultado, precio ,y descuento para calcular el valor con descuento
					     get_incrementar(&preciosLatam[1],precio[0],AUMENTO);
					     //Pide por referencia donde se va guardar el resultado, precio ,y aumento para calcular el valor con aumento
					     get_cambiarABitcoin(&preciosLatam[2],precio[0],BIT);
					     //Pide por referencia donde se va guardar el resultado, precio ,y valor del bitcoin actual para calcular el valor con bitcon
					     get_cotizarPorKm(&preciosLatam[3],precio[0],kilometros);
					     //Pide por referencia donde se va guardar el resultado, precio ,y kilometros para calcular el valor por km
					     //*********************************************************
					     get_descontar(&preciosAerolineas[0],precio[1],DESCUENTO);
					     get_incrementar(&preciosAerolineas[1],precio[1],AUMENTO);
					     get_cambiarABitcoin(&preciosAerolineas[2],precio[1],BIT);
					     get_cotizarPorKm(&preciosAerolineas[3],precio[1],kilometros);
					     //***********************************************************
					     get_sacarDiferencia(&diferencia,precio[1],precio[0]);
					     /*Pide por referencia donde se va guardar el resultado, precio latam y precio aerolineas para luego
					      * decidir quien quien es el mayor y sacar la direfencia.
					      */
                        printf("Se ha realizado una carga forzada con los siguientes datos :\n");
                        printf("Cantidad de kms :%.2f\n",kilometros);
                        printf("Precio latam :%.2f\n",precio[0]);
                        printf("Precio Aerolineas :%.2f\n",precio[1]);
					     //*****************************************************
                        printf("Los calculos arrojan los siguientes resultados : \n");
                        //******************************************************
					    printf("-----Datos Latam-----\n");
					    printf("A)-Los costos se detallaran a continuacion : \n");
					    printf("B)-Valor Latam con debito :$%.2f ",preciosLatam[0]);
					    printf("\nC)-Valor Latam con tarjeta de credito es de  :$%.2f ",preciosLatam[1]);
					    printf("\nD)-Valor Latam con Bitcoin es de : %f BTC",preciosLatam[2]);
					    printf("\nE)-El precio por kilometro es de :$%.2f \n\n",preciosLatam[3]);
					    //***************************************************************
					    printf("\n-----Datos Aerolineas-----\n");
					    printf("A)-Los costos se detallaran a continuacion : \n");
					    printf("B)-Valor Aerolineas con debito :$%.2f ",preciosAerolineas[0]);
 						printf("\nC)-Valor Aerolineas con tarjeta de credito es de  :$%.2f ",preciosAerolineas[1]);
					    printf("\nD)-Valor Aerolineas con Bitcoin es de : %f BTC",preciosAerolineas[2]);
					    printf("\nE)-El precio por kilometro es de :$%.2f \n\n",preciosAerolineas[3]);
					    if (precio[0]>precio[1]){
					    	printf("La diferencia es de %.2f a favor de Aerolineas.\n",diferencia);
					    }else {
					    	printf("La diferencia es de %.2f a favor de Latam.\n",diferencia);
					    }
						break;
                        }}else{
                        	printf("Elija una opcion del 1 al 6 .");
                        }


             }while(opcion!=6);
			printf("Gracias por utilizar el programa de informacion al viajero. ¡¡¡BUEN VIAJE!!!");



	return EXIT_SUCCESS;
}

