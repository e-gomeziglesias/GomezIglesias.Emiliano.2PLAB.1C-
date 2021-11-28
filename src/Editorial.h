/*
 * Editorial.h
 *
 *  Created on: 28 nov. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

#define TAM_EDITORIAL 50
#define MIN_ID_EDITORIAL 1
#define MAX_ID_EDITORIAL 6

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

typedef struct
{
	int idEditorial;
	char nombre[TAM_EDITORIAL];
}eEditorial;

//1.
/// @fn eEditorial editorial_new*()
/// @brief Permite crear el espacio en memoria dinamica para una nueva editorial e inicializa todos los campos en cero
///
/// @return el puntero a la nueva editorial
eEditorial* editorial_new();

//2.
/// @fn eEditorial editorial_newParametros*(char*, char*)
/// @brief Permite crear una nueva editorial, recibiendo todos sus paramtetros como cadena
///
/// @param idStr id de la editorial a cargar
/// @param nombreStr nombre de la editorial a cargar
///
/// @return puntero a la editorial creado si ok, NULL si error
eEditorial* editorial_newParametros(char* idStr, char* nombreStr);

//3.
/// @fn void editorial_delete(eEditorial*)
/// @brief Permite borrar una editorial. Elimina el puntero al mismo
///
/// @param pEditorial puntero la editorial a eliminar
void editorial_delete(eEditorial* pEditorial);

//4.
/// @fn int editorial_setId(eEditorial*, int)
/// @brief Permite cargar el id de una editorial
///
/// @param this puntero a la editorial
/// @param id id de la editorial a cargar
/// @return 0 si ok, -1 si error
int editorial_setId(eEditorial* this, int id);

//5.
/// @fn int editorial_getId(eEditorial*, int*)
/// @brief Permite recuperar el id de una editorial cargada
///
/// @param this puntero a la editorial
/// @param id puntero a la variable donde se guardara el id
/// @return 0 si ok, -1 si error
int editorial_getId(eEditorial* this,int* id);

//6.
/// @fn int libro_setNombre(eEditorial*, char*)
/// @brief Permite cargar el nombre a una editorial
///
/// @param this puntero a la editorial
/// @param nombre nombre de la editorial a cargar
/// @return 0 si ok, -1 si error
int editorial_setNombre(eEditorial* this,char* nombre);

//7.
/// @fn int editorial_getNombre(eEditorial*, char*)
/// @brief Permite recuperar el nombre de una editorial guardada
///
/// @param this puntero a la editorial
/// @param nombre puntero a la cadena donde se guardara el nombre recuperado
/// @return 0 si ok, -1 si error
int editorial_getNombre(eEditorial* this,char* nombre);

/// @fn int editorial_isValidIdEditorial(char*)
/// @brief Permite validar el id de una editorial pasado como cadena
///
/// @param idStr id a validar
/// @return 0 si ok, -1 si error
int editorial_isValidIdEditorial(char* idStr);

/// @fn int editorial_isValidNombre(char*)
/// @brief Permite validar el nombre de la editorial
///
/// @param nombreStr nombre a validar
/// @return 0 si ok, -1 si error
int editorial_isValidNombre(char* nombreStr);






#endif /* EDITORIAL_H_ */

