/*
 * estructuraServicios.c
 *
 *  Created on: 17 may. 2021
 *      Author: Legion
 */

#include "estructuraServicios.h"

int iniciarServicios(eServicio* servicios,int tamanio){
	int i;
	int retorno;
	int bandera;
	bandera=0;
	retorno=-1;
	eServicio auxServicios[4]={{20000,"limpieza",250,1},{20001,"Parche",300,1},{20002,"Centrado",400,1},{20003,"Cadena",350,1}};
	for(i=0;i<tamanio;i++){
		if(i<4){
			servicios[i]=auxServicios[i];
		}else{
			servicios[i].isEmpty=0;
		}
	}
	for(i=0;i<tamanio;i++){
		if(servicios[i].isEmpty==1||servicios[i].isEmpty==0){
			bandera++;
		}
	}
	if (bandera!=0){
		retorno++;
	}
	return retorno;
}

int buscarServiciosDisponibles(eServicio* servicios,int tamanio){
	int i;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanio;i++){
		if(servicios[i].isEmpty==1){
			retorno++;
			break;
		}
	}
	return retorno;
}

int verificarIdServicio(eServicio* lista,int id,int tamanio){
	int i;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanio;i++){
		if(lista[i].id==id){
			retorno++;
			break;
		}
	}
	return retorno;
}

int mostrarServicios(eServicio* servicios,int tamanio){
	int i;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanio;i++){
		if(servicios[i].isEmpty==1){
			retorno=0;
			printf("\nDescripcion: %s.\nPrecio: %.2f.\nId: %i", servicios[i].descripcion, servicios[i].precio, servicios[i].id);
		}
	}
	return retorno;
}
