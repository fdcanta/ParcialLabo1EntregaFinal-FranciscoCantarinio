/*
 ============================================================================
 Name        : parcialLaboratorio1.c
 Author      : Francisco Cantari�o
 Version     :
 Copyright   :
 Description : Parcial de laboratorio
 ============================================================================
 */

#include "UTN.h"
#include "estructuraServicios.h"
#include "estructuraTrabajos.h"
#include "estructuraBicicletas.h"

float calcularPesos(float* pesos,eServicio* servicios,eTrabajo* trabajos,int largoServicios,int largoTrabajos);
int imprimirTrabajosPorBicicleta(eBicicleta* bicicletas,eTrabajo* trabajos,int tamanioTrabajos,int tamanioBicicletas);
int imprimirMayorServicios(eServicio* servicios,eTrabajo* trabajos,int tamanioServicios,int tamanioTrabajos);
int mostrarServiciosConBicicletas(eServicio* servicios, eBicicleta* bicicletas,eTrabajo* trabajos,int tamanioServicios,int tamanioBicicletas,int tamanioTrabajos);
int revisarServiciosBicicletas(int id, eBicicleta* bicicletas,eTrabajo* trabajos,int tamanioTrabajos, int tamanioBicicletas);

int main(void) {
	setbuf(stdout,NULL);
	int opcion;
	int i;
	int j;
	int auxId;
	int auxMarca;
	int auxPosicion;
	int auxDia;
	int auxMes;
	int auxAnio;
	float auxPesos;
	int auxEntero;
	int auxIdServicio;
	int auxIdTrabajo;
	auxIdTrabajo=1;
	auxId=20000;
	eServicio servicios[SERV];
	eTrabajo trabajos[TRAB];
	eBicicleta bicicletas[BICI];
	iniciarServicios(servicios,SERV);
	iniciarTrabajos(trabajos,TRAB);
	iniciarBicicletas(bicicletas, BICI);

	if(iniciarServicios(servicios,SERV)!=-1){
		for(i=0;i<SERV;i++){
			if(servicios[i].isEmpty==1&&servicios[i].id>=auxId){
				auxId=servicios[i].id+1;
			}
		}
		for(i=0;i<TRAB;i++){
			if(trabajos[i].isEmpty==1&&trabajos[i].id>=auxIdTrabajo){
				auxIdTrabajo=trabajos[i].id+1;
			}
		}
		do{
			conseguirEnteroConParametros(&opcion,"\nElija opcion:\n1  - Alta.\n2  - Modificar trabajo.\n3  - Baja de trabajo.\n4  - Listar trabajos.\n5  - Lista de servicios.\n6  - Total en pesos de servicios prestados.\n7  - Listado por marca de bicicleta.\n8  - Servicios mas realizados. -\n9  - Servicios, y bicicletas que se lo realizaron. \n10 - Bicicletas rojas que recibieron servicios.\n11 - salir.\n\n", "\nError, elija opcion valida.\n", 1, 11,5);
			switch(opcion){
			case 1:/**/
				if(buscarEspacioTrabajos(trabajos, TRAB)!=-1&&buscarServiciosDisponibles(servicios, SERV)!=-1){
					auxPosicion=buscarEspacioTrabajos(trabajos, TRAB);
					for(i=0;i<1;i++){
						do{}while(conseguirEnteroConParametros(&auxMarca,"\nElija marca de bicicleta:\n1 - Honda.\n2 - Mitsubishi.\n3 - Shimano.\n4 - Susuki.\n5 - Yamaha.\n", "Error, elija opcion disponible.", 1,5,1)==-1);
						do{
							do{}while(conseguirEnteroConParametros(&auxDia,"\nIngrese dia(formato dd): ", "Error, dia fuera de parametros",1, 31, 1)==-1);
							do{}while(conseguirEnteroConParametros(&auxMes,"\nIngrese mes(formato mm):  ", "Error, mes fuera de parametros",1, 12, 1)==-1);
							do{}while(conseguirEnteroConParametros(&auxAnio,"\nIngrese año(formato '20xx'): ", "Error, año fuera de parametros",1921, 2021, 1)==-1);
						}while(verificarFecha(auxDia,auxMes, auxAnio)!=0);
						do{
							printf("\nLos servicios disponibles son:");
							for(j=0;j<SERV;j++){
								if(servicios[j].isEmpty==1){
									printf("\n\nDescripcion: %s.\nId: %i", servicios[j].descripcion, servicios[j].id);
								}
							}
							conseguirEnteroConParametros(&auxIdServicio,"\nIngrese id del servicio: ", "\nError, id fuera de parametros.",20000, auxId, 1);
							if(verificarIdServicio(servicios,auxIdServicio, SERV)==-1){
								printf("\nServicio no disponible, elija otro.");
							}
						}while(verificarIdServicio(servicios,auxIdServicio, SERV)!=0);
					}
					if(cargarTrabajo(trabajos,auxMarca,auxDia,auxMes,auxAnio,auxIdServicio,auxPosicion,auxIdTrabajo)==0){
						auxIdTrabajo++;
						printf("\nTrabajo cargado.");
					}else{
						printf("\nEl trabajo no pudo ser cargado.");
					}
				}else{
					if(buscarEspacioTrabajos(trabajos, TRAB)==-1){
						printf("\nNo puede ingresarse otro trabajo.");
					}else {
						printf("\nNo hay servicios para elegir.");
					}
				}
				break;
			case 2:
				if(buscarTrabajosDisponibles(trabajos, TRAB)==-1){
					printf("\nNo hay trabajos a modificar.");
				}else{
					do{
						mostrarTrabajos(trabajos, TRAB);
					}while(conseguirEnteroConParametros(&auxEntero,"\nIngrese id del trabajo: ", "\nError, id fuera de parametros.",1, auxIdTrabajo, 1)!=0);
					if(buscarTrabajoPorId(auxEntero, trabajos, TRAB)!=-1){
						auxPosicion=buscarTrabajoPorId(auxEntero, trabajos, TRAB);
						do{}while(conseguirEnteroConParametros(&auxEntero,"\nElija que cambiar:\n1 - Marca.\n2 - Servicio.\n ", "\nError, fuera de parametros.",1, 2, 1)==-1);
						switch(auxEntero){
						case 1:
							do{}while(conseguirEnteroConParametros(&auxMarca,"\nElija marca de bicicleta:\n1 - Shimano.\n2 - Yamaha.\n3 - Honda.\n4 - Susuki.\n5 - Mitsubishi.\n", "Error, elija opcion disponible.", 1,5,1)==-1);
							switch(auxMarca){
								case 1:
									trabajos[auxPosicion].idBicicleta=25;
									break;
								case 2:
									trabajos[auxPosicion].idBicicleta=26;
									break;
								case 3:
									trabajos[auxPosicion].idBicicleta=27;
									break;
								case 4:
									trabajos[auxPosicion].idBicicleta=28;
									break;
								case 5:
									trabajos[auxPosicion].idBicicleta=29;
									break;
								}
							break;
						case 2:
							do{
								mostrarServicios(servicios,SERV);
							}while(conseguirEnteroConParametros(&auxEntero,"\nElija id del servicio: ", "Error, elija opcion disponible.", 1,auxId,1)==-1);
							if(verificarIdServicio(servicios,auxEntero,SERV)!=-1){
								trabajos[auxPosicion].idServicio=auxEntero;
							}else{
								printf("\nNo es un servicio valido.");
							}
							break;
						}
					}else{
						printf("\nNo hay trabajo con esa ID.");
					}
				}
				break;
			case 3:
				if(buscarTrabajosDisponibles(trabajos, TRAB)==-1){
					printf("\nNo hay trabajos a eliminar.");
				}else{
					do{
						mostrarTrabajos(trabajos, TRAB);
					}while(conseguirEnteroConParametros(&auxEntero,"\nIngrese id del trabajo: ", "\nError, id fuera de parametros.",1, auxIdTrabajo, 1)!=0);
					if(borrarTrabajo(trabajos, auxEntero, TRAB)!=-1){
						printf("\nTrabajo eliminado.");
					}else{
						printf("\nNo hay trabajo con esa ID.");
					}
				}
				break;
			case 4:
				if(buscarTrabajosDisponibles(trabajos, TRAB)==-1){
					printf("\nNo hay trabajos para mostrar.");
				}else{
					ordenarTrabajos(trabajos, TRAB);
					printf("\nLos trabajos ingresados son: ");
					mostrarTrabajos(trabajos, TRAB);
				}
				break;
			case 5:
				if(buscarServiciosDisponibles(servicios, SERV)==-1){
					printf("\nNo hay trabajos para mostrar.");
				}else{
					printf("\nLos servicios ingresados son: ");
					mostrarServicios(servicios, SERV);
				}
				break;
			case 6:
				if(calcularPesos(&auxPesos,servicios, trabajos, SERV, TRAB)>0){
					printf("\nEl total de ganancias por servicios es: %.2f.", auxPesos);
				}else{
					printf("\nNo se esta generando ninguna ganancia.");
				}
				break;
			case 7:
				if(buscarTrabajosDisponibles(trabajos, TRAB)==-1){
					printf("\nNo hay trabajos a listar.");
				}else{
					printf("\nLos trabajos realizados son:");
					imprimirTrabajosPorBicicleta(bicicletas, trabajos, TRAB, BICI);
				}
				break;
			case 8:
				if(buscarTrabajosDisponibles(trabajos, TRAB)==-1){
					printf("\nNo hay servicios realizados a listar.");
				}else{
					printf("Los servicios mas realizados son: ");
					imprimirMayorServicios(servicios, trabajos, SERV, TRAB);
				}
				break;
			case 9:
				if(buscarServiciosDisponibles(servicios, SERV)==-1){
					printf("\nNo hay trabajos para mostrar.");
				}else{
					printf("\nLos servicios ingresados son: \n");
					mostrarServiciosConBicicletas(servicios,bicicletas,trabajos,SERV,BICI,TRAB);
				}
				break;
			case 10:
				break;
			case 11:
				break;
			}
		}while(opcion!=11);
	}else{
		printf("\nNo pudo crearse lista de servicios.\n");
	}

	printf("\n========================================================================");
	printf("\n========================Gracias, vuelva pronto!=========================");
	printf("\n========================================================================");
	return 0;
}


float calcularPesos(float* pesos,eServicio* servicios,eTrabajo* trabajos,int largoServicios,int largoTrabajos){
	int j;
	int i;
	int auxIdServicio;
	float retorno;
	retorno=0;
	for(i=0;i<largoTrabajos;i++){
		if(trabajos[i].isEmpty==1){
			auxIdServicio=trabajos[i].idServicio;
			for(j=0;j<largoServicios;j++){
				if(servicios[j].id==auxIdServicio){
					retorno=retorno+servicios[j].precio;
				}
			}
		}
	}
	*pesos=retorno;
	return retorno;
}

int imprimirTrabajosPorBicicleta(eBicicleta* bicicletas,eTrabajo* trabajos,int tamanioTrabajos,int tamanioBicicletas){
	int i;
	int j;
	int retorno;
	retorno=-1;
	eTrabajo auxTrabajo;
	char auxMarca[25];
	for(i=0;i<tamanioTrabajos;i++){
		for(j=0;j<tamanioTrabajos;j++){
			if(trabajos[i].isEmpty==1&&trabajos[j].isEmpty==1&&trabajos[i].idBicicleta>trabajos[j].idBicicleta){
				auxTrabajo=trabajos[i];
				trabajos[i]=trabajos[j];
				trabajos[j]=auxTrabajo;
			}
		}
	}
	for(i=0;i<tamanioTrabajos;i++){
		if(trabajos[i].isEmpty==1){
			retorno=0;
			for(j=0;j<tamanioBicicletas;j++){
				if(bicicletas[j].id==trabajos[i].idBicicleta){
					strcpy(auxMarca, bicicletas[j].marca);
				}
			}
			printf("\n\nid del trabajo: %i\nId del servicio: %i\nFecha %i-%i-%i.\nMarca de la bicicleta: %s\n", trabajos[i].id,trabajos[i].idServicio, trabajos[i].fecha[0],trabajos[i].fecha[1],trabajos[i].fecha[2], auxMarca);
		}
	}
	return retorno;
}

int imprimirMayorServicios(eServicio* servicios,eTrabajo* trabajos,int tamanioServicios,int tamanioTrabajos){
	int i;
	int j;
	int k;
	int mayor;
	int auxMayor;
	int auxId;
	int retorno;
	mayor=0;
	retorno=-1;
	for(i=0;i<tamanioTrabajos;i++){
		if(trabajos[i].isEmpty==1){
			auxMayor=0;
			for(j=0;j<tamanioServicios;j++){
				if(servicios[j].isEmpty==1&&servicios[j].id==trabajos[i].idServicio){
					auxMayor++;
				}
			}
			if(auxMayor>mayor){
				mayor=auxMayor;
			}
		}
	}

	for(i=0;i<tamanioTrabajos;i++){
		if(trabajos[i].isEmpty==1){
			auxMayor=0;
			for(j=0;j<tamanioServicios;j++){
				if(servicios[j].isEmpty==1&&servicios[j].id==trabajos[i].idServicio){
					auxMayor++;
				}
			}
			if(auxMayor==mayor){
				auxId=trabajos[i].idServicio;
				for(k=0;k<tamanioServicios;k++){
					if(servicios[k].id==auxId){
						printf("\nDescripcion: %s", servicios[k].descripcion);
					}
				}

			}
		}
	}
	return retorno;
}

int revisarServiciosBicicletas(int id, eBicicleta* bicicletas,eTrabajo* trabajos,int tamanioTrabajos, int tamanioBicicletas){
	int i;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanioTrabajos;i++){
		if(trabajos[i].idServicio==id){
			retorno=0;
			break;
		}
	}
	return retorno;
}

int mostrarServiciosConBicicletas(eServicio* servicios, eBicicleta* bicicletas,eTrabajo* trabajos,int tamanioServicios,int tamanioBicicletas, int tamanioTrabajos){
	int i;
	int j;
	int k;
	int retorno;
	retorno=-1;
	for(i=0;i<tamanioServicios;i++){
		if(servicios[i].isEmpty==1){
			retorno=0;
			printf("\nDescripcion: %s.\nPrecio: %.2f.\nId: %i", servicios[i].descripcion, servicios[i].precio, servicios[i].id);
			if(revisarServiciosBicicletas(servicios[i].id, bicicletas, trabajos, TRAB, BICI)!=-1){
				printf("\nLas bicicletas que realizaron este servicio fueron: ");
				for(j=0;j<tamanioTrabajos;j++){
					if(trabajos[j].idServicio==servicios[i].id){
						for(k=0;k<tamanioBicicletas;k++){
							if(trabajos[j].idBicicleta==bicicletas[k].id&&bicicletas[k].isEmpty==1){
								printf("\nMarca: %s.\nRodado: %i.\nColor :%s.\n",bicicletas[k].marca, bicicletas[k].rodado, bicicletas[k].color);
							}
						}
					}
				}
			}else{
				printf("\nNinguna bicicleta realizo este servicio.\n");
			}
		}
	}
	return retorno;
}
