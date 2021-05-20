/*
 * estructuraBicicletas.h
 *
 *  Created on: 20 may. 2021
 *      Author: Legion
 */

#ifndef ESTRUCTURABICICLETAS_H_
#define ESTRUCTURABICICLETAS_H_
#include <string.h>
#include <stdio.h>

typedef struct{
    int id;
    char marca[25];
    int rodado;
    char color[25];
    int isEmpty;
}eBicicleta;

int iniciarBicicletas(eBicicleta* bicicletas, int tamanio);


#endif /* ESTRUCTURABICICLETAS_H_ */
