/*
 * parser.h
 *
 *  Created on: 2 nov. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#ifndef PARSER_H_
#define PARSER_H_



#endif /* PARSER_H_ */

//1.
/// @brief Parsea libros desde un archivo (modo texto)
///
/// @param pFile puntero FILE al archivo
/// @param pArrayListLibro LinkedList donde se guardaran los libros
/// @return 0 si ok, -1 si error
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro);

//2.
/// @brief Parsea libros desde un archivo (modo binario)
///
/// @param pFile puntero FILE al archivo
/// @param pArrayListLibro LinkedList donde se guardaran los libros
/// @return 0 si ok, -1 si error
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListLibro);

//3.
/// @brief Parsea editoriales desde un archivo (modo texto)
///
/// @param pFile puntero FILE al archivo
/// @param pArrayListLibro LinkedList donde se guardaran las editoriales
/// @return 0 si ok, -1 si error
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListLibro);

//4.
/// @brief Parsea editoriales desde un archivo (modo binario)
///
/// @param pFile puntero FILE al archivo
/// @param pArrayListLibro LinkedList donde se guardaran las editoriales
/// @return 0 si ok, -1 si error
int parser_EditorialFromBinary(FILE* pFile , LinkedList* pArrayListLibro);

