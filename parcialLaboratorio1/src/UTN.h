/*
 * UTN.h
 *
 *  Created on: 12 may. 2021
 *      Author: Legion
 */

#ifndef UTN_H_
#define UTN_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SERV 100
#define TRAB 1000
#define BICI 100

/* \brief permite intentar ingresar un numero entero dentro de ciertos parametros, una cantidad de veces definida
*  \param pValor int* puntero a entero para ser modificado por referencia
*  \param mensaje char* instrucciones para ingresar datos
*  \param mensajeError char* mensaje de error si los datos ingresados no pueden ser verificados
*  \param minimo int numero entero minimo a ingresar
*  \param maximo int numero entero maximo a ingresar
*  \param intentos int numero de intentos para ingresar un numero valido
*  \return Retorna -1 si no pudo ingresarse un numero, 0 si se pudo
*/
int conseguirEnteroConParametros(int* pValor,char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);

/* \brief permite intentar ingresar un numero con decimales dentro de ciertos parametros, una cantidad de veces definida
*  \param pValor float* puntero a numero con decimales para ser modificado por referencia
*  \param mensaje char* instrucciones para ingresar datos
*  \param mensajeError char* mensaje de error si los datos ingresados no pueden ser verificados
*  \param minimo float numero con decimales minimo a ingresar
*  \param maximo float numero con decimales maximo a ingresar
*  \param intentos int numero de intentos para ingresar un numero valido
*  \return Retorna -1 si no pudo ingresarse un numero, 0 si se pudo
*/
int conseguirNumeroDecimalConParametros(float* pValor,char* mensaje, char* mensajeError, int minimo, int maximo, int intentos);

/* \brief permite intentar ingresar una cadena de caracteres de cierto largo
*  \param auxiliar char* puntero a cadena de caracteres a ser modificada por referencia
*  \param mensaje char* instrucciones para ingresar datos
*  \param mensajeError char* mensaje de error si los datos ingresados no pueden ser verificados
*  \param minimo int numero entero, minimo de letras a ingresar
*  \param maximo int numero entero, maximo de letras a ingresar
*  \param intentos int numero de intentos para ingresar una cadena verificable
*  \return Retorna -1 si no pudo ingresarse una cadena de caracteres, 0 si se pudo
*/
int conseguirCadenaCaracteres(char auxiliar[], char* mensaje, char* mensajeError,int minimo, int maximo, int intentos);

/* \brief permite intentar ingresar un numero entero
*  \param numero int* puntero a entero para ser modificado por referencia
*  \param mensaje char* instrucciones para ingresar datos
*  \param mensajeError char* mensaje de error si los datos ingresados no pueden ser verificados
*  \return Retorna -1 si no pudo ingresarse un numero, 0 si se pudo
*/
int conseguirEntero(int* numero, char* mensaje, char* mensajeError);

/* \brief permite intentar ingresar un numero con decimales
*  \param numero float* puntero a entero para ser modificado por referencia
*  \param mensaje char* instrucciones para ingresar datos
*  \param mensajeError char* mensaje de error si los datos ingresados no pueden ser verificados
*  \return Retorna -1 si no pudo ingresarse un numero, 0 si se pudo
*/
int conseguirNumeroDecimal(float* numero, char* mensaje, char* mensajeError);

/* \brief verifica que una cadena de caracteres sea solo numeros enteros
*  \param numeros char* cadena de carcateres a verificar
*  \return Retorna -1 si no se pudo verificar los datos, 0 si se pudo
*/
int validarSoloEntero(char* numeros);

/* \brief verifica que una cadena de caracteres sea solo un numero con decimales
*  \param numeros char* cadena de carcateres a verificar
*  \return Retorna -1 si no se pudo verificar los datos, 0 si se pudo
*/
int validarSoloDecimales(char* numeros);

/* \brief verifica que una cadena de caracteres sea solo letras
*  \param cadena char* cadena de carcateres a verificar
*  \return Retorna -1 si no se pudo verificar los datos, 0 si se pudo
*/
int verificarCadenaSoloAlfabeto(char* cadena);

/* \brief alimenta el buffer a una variable nunca invocada para vaciarlo
*  \param nada
*  \return nada
*/
void limpiarBuffer();

/* \brief ordena una cadena de enteros
*  \param lista int* cadena de enteros a ordenar
*  \param orden int criterio de orden
*  \return Retorna -1 si no pudo ordenar la cadena, 0 si pudo
*/
int ordenarEnteros(int* lista, int orden);

/* \brief ordena una cadena de numeros con decimal
*  \param lista float* cadena de enteros a ordenar
*  \param orden int criterio de orden
*  \return Retorna -1 si no pudo ordenar la cadena, 0 si pudo
*/
int ordenarDecimales(float* lista, int orden);
//1 menor a mayor, 2 mayor a menor

int verificarFecha(int dia, int mes, int anio);

#endif /* UTN_H_ */
