/*
 * estructuraServicios.h
 *
 *  Created on: 17 may. 2021
 *      Author: Legion
 */

#ifndef ESTRUCTURASERVICIOS_H_
#define ESTRUCTURASERVICIOS_H_
#include <string.h>
#include <stdio.h>

typedef struct{
	int id;
	char descripcion[25];
	float precio;
	int isEmpty;
} eServicio;


/* \brief inicia los servicios con algunos datos hardcodeados y marcando el resto como vacios
*  \param servicios servicio* cadena del tipo servicio a ser inicializada
*  \param tamanio int entero que marca el largo de la cadena
*  \return Retorna -1 si no pudo completar los daros, 0 si pudo
*/
int iniciarServicios(eServicio* servicios,int tamanio);
int buscarServiciosDisponibles(eServicio* servicios,int tamanio);
int verificarIdServicio(eServicio* lista,int id,int tamanio);
int mostrarServicios(eServicio* servicios,int tamanio);


#endif /* ESTRUCTURASERVICIOS_H_ */
