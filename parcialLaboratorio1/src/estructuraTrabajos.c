/*
 * estructuraTrabajos.c
 *
 *  Created on: 18 may. 2021
 *      Author: Legion
 */
#include "estructuraTrabajos.h"

int iniciarTrabajos(eTrabajo* trabajos,int tamanio){
	int i;
	int retorno;
	int bandera;
	bandera=0;
	retorno=-1;
	for(i=0;i<tamanio;i++){
		trabajos[i].isEmpty=0;
	}
	for(i=0;i<tamanio;i++){
		if(trabajos[i].isEmpty==0){
			bandera++;
		}
	}
	if (bandera==tamanio){
		retorno++;
	}
	return retorno;
}

int buscarEspacioTrabajos(eTrabajo* trabajos, int tamanio){
	int i;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanio;i++){
		if(trabajos[i].isEmpty==0){
			retorno=i;
			break;
		}
	}
	return retorno;
}


int cargarTrabajo(eTrabajo* trabajos,int marca,int dia, int mes,int  anio, int idServicio,int  posicion,int idTrabajo){
	int retorno;
	retorno=-1;
	//25:yamaha-26:shimano-27:Honda-28:Susuki-29:Mitsubishi
	switch(marca){
	case 1:
		trabajos[posicion].idBicicleta=25;
		break;
	case 2:
		trabajos[posicion].idBicicleta=26;
		break;
	case 3:
		trabajos[posicion].idBicicleta=27;
		break;
	case 4:
		trabajos[posicion].idBicicleta=28;
		break;
	case 5:
		trabajos[posicion].idBicicleta=29;
		break;
	}
	trabajos[posicion].fecha[0]=dia;
	trabajos[posicion].fecha[1]=mes;
	trabajos[posicion].fecha[2]=anio;
	trabajos[posicion].idServicio=idServicio;
	trabajos[posicion].id=idTrabajo;
	trabajos[posicion].isEmpty=1;
	retorno++;
	return retorno;
}

int buscarTrabajosDisponibles(eTrabajo* trabajos,int tamanio){
	int i;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanio;i++){
		if(trabajos[i].isEmpty==1){
			retorno++;
			break;
		}
	}
	return retorno;
}

int mostrarTrabajos(eTrabajo* trabajos,int tamanio){
	int i;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanio;i++){
		if(trabajos[i].isEmpty==1){
			retorno=0;
			printf("\n\nid del trabajo: %i\nId del servicio: %i\nFecha %i-%i-%i.\n", trabajos[i].id,trabajos[i].idServicio, trabajos[i].fecha[0],trabajos[i].fecha[1],trabajos[i].fecha[2]);
		}
	}
	return retorno;
}

int borrarTrabajo(eTrabajo* trabajos,int id, int tamanio){
	int i;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanio;i++){
		if(trabajos[i].id==id){
			trabajos[i].isEmpty=0;
			retorno++;
			break;
		}
	}
	return retorno;
}

int ordenarTrabajos(eTrabajo* trabajos,int tamanio){
	int i;
	int j;
	eTrabajo auxTrabajo;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanio;i++){
		for(j=0;j<tamanio;j++){
			if(trabajos[i].isEmpty==1&&trabajos[j].isEmpty==1&&trabajos[i].fecha[2]<trabajos[j].fecha[2]){
				auxTrabajo=trabajos[j];
				trabajos[j]=trabajos[i];
				trabajos[i]=auxTrabajo;
			}
			if(trabajos[i].isEmpty==1&&trabajos[j].isEmpty==1&&trabajos[i].fecha[2]==trabajos[j].fecha[2]){
				if(trabajos[i].isEmpty==1&&trabajos[j].isEmpty==1&&trabajos[i].idBicicleta<trabajos[j].idBicicleta){
					auxTrabajo=trabajos[j];
					trabajos[j]=trabajos[i];
					trabajos[i]=auxTrabajo;
				}
			}
		}
	}
	retorno=0;
	return retorno;
}

int buscarTrabajoPorId(int id, eTrabajo* trabajos,int tamanio){
	int i;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanio;i++){
		if(trabajos[i].isEmpty==1&&trabajos[i].id==id){
			retorno=i;
		}
	}
	return retorno;
}
