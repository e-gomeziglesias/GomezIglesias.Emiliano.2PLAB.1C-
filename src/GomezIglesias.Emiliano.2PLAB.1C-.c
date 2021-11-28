/*
 ============================================================================
 Name        : GomezIglesias.Emiliano.2PLAB.1C-.c
 Author      : Gomez Iglesias, Emiliano
 Version     :
 Copyright   : Your copyright notice
 Description :

Desarrollar en ANSI C:
Un programa que realice lo siguiente:
1. Leer un archivo con los datos de libros, guardándolos en un linkedList
de entidades eLibro.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de comandos.
2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList
de entidades eEditorial.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de comandos.
3. Ordenar la lista generada en el ítem anterior, con la función ll_sort,
según el criterio de ordenamiento “Autor” de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Input.h"
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"
#include "Controller.h"
#include "Menu.h"


#define ARCHIVO_LIBROS "libros.csv"
#define ARCHIVO_EDITORIALES "editoriales.csv"
#define ARCHIVO_FILTRO "filtrado.csv"

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	LinkedList* listaLibros;
	LinkedList* listaEditoriales;
	int retorno;

	listaLibros = ll_newLinkedList();
	Menu_AnalizarRetornoPunteros(listaLibros, "NOTA: La lista de libros se creo con exito", "NOTA: Ocurrio un error al crear la lista dinamica de libros");

	listaEditoriales = ll_newLinkedList();
	Menu_AnalizarRetornoPunteros(listaEditoriales, "NOTA: La lista de editoriales se creo con exito", "NOTA: Ocurrio un error al crear la lista dinamica de editoriales");
	printf("\n\n");
	if(listaLibros != NULL && listaEditoriales != NULL)
	{
		do
		{
			opcion = Menu_MostrarMenuPrincipalOpciones();
			switch(opcion)
			{
				case 1:
					retorno = controller_loadLibroFromText(ARCHIVO_LIBROS, listaLibros);
					Menu_AnalizarRetorno(retorno, "Los libros se cargaron exitosamente desde el archivo de texto", "No se pudieron cargar los libros en la lista");
				system("pause");
				break;
				case 2:
					retorno = controller_loadEditorialFromText(ARCHIVO_EDITORIALES, listaEditoriales);
					Menu_AnalizarRetorno(retorno, "Las editoriales se cargaron exitosamente desde el archivo de texto", "No se pudieron cargar las editoriales en la lista");
					system("pause");
				break;
				case 3:
					retorno = controller_sortLibros(listaLibros);
					Menu_AnalizarRetorno(retorno, "Los libros se ordenaron segun el criterio elegido", "No se pudieron ordenar los libros");

					system("pause");
				break;
				case 4:
					retorno = controller_ListLibros(listaLibros, listaEditoriales);
					Menu_AnalizarRetorno(retorno, "Se muestra el listado de libros", "No se pudieron mostrar los libros");
					system("pause");
				break;

			}
		}while(opcion != 0);
	}

	return EXIT_SUCCESS;
}
