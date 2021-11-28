/*
 * Libro.h
 *
 *  Created on: 28 nov. 2021
 *      Author: Gomez Iglesias, Emiliano
 */
#include <stdio.h>
#include <stdlib.h>
#include "Input.h"

#define TAM_TITULO 80
#define TAM_AUTOR 50
#define MAX_ID_LIBRO 1000
#define MIN_ID_LIBRO 1
#define MIN_ID_EDITORIAL 1
#define MAX_ID_EDITORIAL 6
#define MIN_PRECIO 100
#define MAX_PRECIO 2000

#ifndef LIBRO_H_
#define LIBRO_H_

typedef struct
{
	int id;
	char titulo[TAM_TITULO];
	char autor [TAM_AUTOR];
	float precio;
	int idEditorial;
}eLibro;

//1.
/// @fn eLibro libro_new*()
/// @brief Permite crear el espacio en memoria dinamica para un nuevo libro e inicializa todos los campos en cero
///
/// @return el puntero al nuevo libro
eLibro* libro_new();

//2.
/// @fn eLibro libro_newParametros*(char*, char*, char*, char*, char*)
/// @brief Permite crear un nuevo libro, recibiendo todos sus paramtetros como cadena
///
/// @param idStr id del libro
/// @param tituloStr titulo del libro
/// @param autorStr autor del libro
/// @param precioStr precio del libro
/// @param idEditorialStr id de la editorial
/// @return puntero al libro creado si ok, NULL si error
eLibro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr);

//3.
/// @fn void libro_delete(pLibro*)
/// @brief Permite borrar un libro. Elimina el puntero al mismo
///
/// @param pLibro puntero al libro a eliminar
void libro_delete(eLibro* pLibro);

//4.
/// @fn int libro_setId(eLibro*, int)
/// @brief Permite cargar el id de un libro
///
/// @param this puntero al libro
/// @param id id a cargar
/// @return 0 si ok, -1 si error
int libro_setId(eLibro* this, int id);

//5.
/// @fn int libro_getId(eLibro*, int*)
/// @brief permite recuperar el id de un libro cargado
///
/// @param this puntero al libro
/// @param id puntero a la variable donde se recuperará el id
/// @return 0 si ok, -1 si error
int libro_getId(eLibro* this,int* id);

//6.
/// @fn int libro_setTitulo(eLibro*, char*)
/// @brief Permite cargar el titulo de un libro
///
/// @param this puntero al libro
/// @param titulo titulo a cargar
/// @return 0 si ok, -1 si error
int libro_setTitulo(eLibro* this,char* titulo);

//7.
/// @fn int libro_getTitulo(eLibro*, char*)
/// @brief Permite recuperar el titulo de un libro cargado
///
/// @param this puntero al libro
/// @param titulo puntero a la cadena donde se recuperara el titulo
/// @return 0 si ok, -1 si error
int libro_getTitulo(eLibro* this,char* titulo);

//8.
/// @fn int libro_setAutor(eLibro*, char*)
/// @brief Permite cargar el autor de un libro
///
/// @param this puntero al libro
/// @param autor autor a cargar
/// @return 0 si ok, -1 si error
int libro_setAutor(eLibro* this,char* autor);

//9.
/// @fn int libro_getAutor(eLibro*, char*)
/// @brief Permite recuperar el autor de un libro cargado
///
/// @param this puntero al libro
/// @param titulo puntero a la cadena donde se recuperara el autor
/// @return 0 si ok, -1 si error
int libro_getAutor(eLibro* this,char* autor);

//10.
/// @fn int libro_setPrecio(eLibro*, int)
/// @brief Permite cargar el precio de un libro
///
/// @param this puntero al libro
/// @param precio precio a caregar
/// @return 0 si ok, -1 si error
int libro_setPrecio(eLibro* this, float precio);

//11.
/// @fn int libro_getPrecio(eLibro*, int*)
/// @brief Permite recuperar el precio de un libro cargado
///
/// @param this puntero al libro
/// @param precio puntero a la variable donde se recuperara el precio
/// @return 0 si ok, -1 si error
int libro_getPrecio(eLibro* this, float* precio);

//12.
/// @fn int libro_setIdEditorial(eLibro*, int)
/// @brief Permite cargar el id del editorial en un libro
///
/// @param this puntero al libro
/// @param idEditorial id a cargar
/// @return 0 si ok, -1 si error
int libro_setIdEditorial(eLibro* this, int idEditorial);

//13.
/// @fn int libro_getIdEditorial(eLibro*, int*)
/// @brief permite recuperar el id de la editorial de un libro
///
/// @param this puntero al libro
/// @param idEditorial puntero a la variable donde se recuperara el id de la editorial
/// @return 0 si ok, -1 si error
int libro_getIdEditorial(eLibro* this,int* idEditorial);

//14.
/// @fn int libro_CompararPorAutor(void*, void*)
/// @brief Permite comparar los campos autor de dos libros
///
/// @param l1 puntero a void del primer libro
/// @param l2 puntero a void del segundo libro
/// @return 0 si son iguales, -1 si el autor del segundo es menor que el primero, 1 si el autor del segundo es mayor que el primero.
int libro_CompararPorAutor(void* l1, void* l2);

/// @fn int libro_CompararPorId(void*, void*)
/// @brief Permite comparar los campos id de dos libros
///
/// @param l1 puntero a void del primer libro
/// @param l2 puntero a void del segundo libro
/// @return 0 si son iguales, -1 si el id del segundo es menor que el primero, 1 si el id del segundo es mayor que el primero.
int libro_CompararPorId(void* l1, void* l2);

/// @fn int libro_FiltrarMinotauro(void*)
/// @brief Permite determinar si un elemento void tiene como editorial a MINOTAURO
///
/// @param pElement puntero a un elemento
/// @return 0 si no pertenece, 1 si pertenece
int libro_FiltrarMinotauro(void* pElement);

/// @fn int libro_isValidIdLibro(char*)
/// @brief permite validar un Id de libro, recibido como cadena
///
/// @param idStr id a validar
/// @return 0 si es valido, -1 si no lo es
int libro_isValidIdLibro(char* idStr);

/// @fn int libro_isValidIdEditorial(char*)
/// @brief Permite validar el id de una editorial
///
/// @param idStr
/// @return0 si es valido, -1 si no lo es

int libro_isValidIdEditorial(char* idStr);

/// @fn int libro_isValidAutor(char*)
/// @brief Permite validar el nombre de un autor
///
/// @param autorStr nombre a validar
/// @return 0 si es valido, -1 si no lo es
int libro_isValidAutor(char* autorStr);

/// @fn int libro_isValidPrecio(char*)
/// @brief Permite validar el precio de un libro recibido como cadena
///
/// @param precioStr precio a validar
/// @return 0 si es valido, -1 si no lo es
int libro_isValidPrecio(char* precioStr);

/// @fn int libro_isValidTitulo(char*)
/// @brief Permite validar el nombre de un titulo
///
/// @param tituloStr nombre del titulo a validar
/// @return 0 si es valido, -1 si no lo es
int libro_isValidTitulo(char* tituloStr);

#endif /* LIBRO_H_ */


