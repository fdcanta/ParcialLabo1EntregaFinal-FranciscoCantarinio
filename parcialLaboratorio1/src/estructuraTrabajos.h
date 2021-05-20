/*
 * estructuraTrabajos.h
 *
 *  Created on: 18 may. 2021
 *      Author: Legion
 */

#ifndef ESTRUCTURATRABAJOS_H_
#define ESTRUCTURATRABAJOS_H_
#include <string.h>
#include <stdio.h>

typedef struct{
	int id;
	int idBicicleta;
	int idServicio;
	int fecha[3];
	int isEmpty;
} eTrabajo;

int iniciarTrabajos(eTrabajo* trabajos,int tamanio);
int cargarTrabajo(eTrabajo* trabajos,int marca,int dia, int mes,int  anio, int idServicio,int  posicion,int idTrabajo);
int buscarEspacioTrabajos(eTrabajo* trabajos, int tamanio);
int buscarTrabajosDisponibles(eTrabajo* trabajos,int tamanio);
int mostrarTrabajos(eTrabajo* trabajos,int tamanio);
int borrarTrabajo(eTrabajo* trabajos,int id, int tamanio);
int ordenarTrabajos(eTrabajo* trabajos,int tamanio);
int buscarTrabajoPorId(int id, eTrabajo* trabajos,int tamanio);


#endif /* ESTRUCTURATRABAJOS_H_ */
