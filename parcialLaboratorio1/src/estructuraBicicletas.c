/*
 * estructuraBicicletas.c
 *
 *  Created on: 20 may. 2021
 *      Author: Legion
 */
#include "estructuraBicicletas.h"

int iniciarBicicletas(eBicicleta* bicicletas, int tamanio){
	int i;
	int retorno;
	retorno=-1;
	eBicicleta auxBicicletas[5]={{25,"Honda",14,"Negro",1},{26,"Mitsubishi",16,"Rojo",1},{27,"Shimano",18,"Azul",1},{28,"Susuki",15,"Gris",1},{29,"Yamaha",23,"Blanco",1}};
	for(i=0;i<tamanio;i++){
		if(i<5){
			bicicletas[i]=auxBicicletas[i];
		}else{
			bicicletas[i].isEmpty=0;
		}
	}
	return retorno;
}
