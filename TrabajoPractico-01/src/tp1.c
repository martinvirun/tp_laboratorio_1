/*
 * tp1.c
 *
 *  Created on: 16 abr. 2022
 *      Author: martin
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
void  get_descontar(float*pResultado,float valor,float porcentaje){
	float resultado = valor-(valor*porcentaje);
	*pResultado = resultado;


}
void  get_incrementar(float*pResultado,float valor,float porcentaje){
	float resultado = valor+(valor*porcentaje);
	*pResultado = resultado;

}
void get_cambiarABitcoin(float*pResultado,float valor,float valorBitcoin){
	float resultado = valor/valorBitcoin;
	*pResultado = resultado;
}
void get_cotizarPorKm(float*pResultado,float valor,float kms){
	float resultado = valor/ kms;
	*pResultado = resultado;

}
void get_sacarDiferencia(float*pResultado,float latam,float aerolineas){
	if (latam > aerolineas){
	*pResultado = latam - aerolineas;}
	else {*pResultado = aerolineas - latam;}

}
