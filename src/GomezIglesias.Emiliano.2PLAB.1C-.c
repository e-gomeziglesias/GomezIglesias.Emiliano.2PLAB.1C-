/*
 ============================================================================
 Name        : GomezIglesias.Emiliano.2PLAB.1C-.c
 Author      : Gomez Iglesias, Emiliano
 Version     :
 Copyright   : Your copyright notice
 Description :

Desarrollar en ANSI C:
Un programa que realice lo siguiente:
1. Leer un archivo con los datos de libros, guard?ndolos en un linkedList
de entidades eLibro.
ACLARACI?N: El nombre del archivo se debe pasar como par?metro por l?nea de comandos.
2. Leer un archivo con los datos de editoriales, guard?ndolos en un linkedList
de entidades eEditorial.
ACLARACI?N: El nombre del archivo se debe pasar como par?metro por l?nea de comandos.
3. Ordenar la lista generada en el ?tem anterior, con la funci?n ll_sort,
seg?n el criterio de ordenamiento ?Autor? de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACI?N: Se deber? imprimir la descripci?n de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deber? utilizar la funci?n ll_filter* del LinkedList. Guardar el listado en un archivo csv.
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
#define ARCHIVO_MAPEADO "mapeado.csv"


int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	int flagCargaLibros = 0;
	int flagCargaEditoriales = 0;
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
					if (retorno == 0)
					{
						flagCargaLibros = 1;
					}
					system("pause");
				break;
				case 2:
					retorno = controller_loadEditorialFromText(ARCHIVO_EDITORIALES, listaEditoriales);
					Menu_AnalizarRetorno(retorno, "Las editoriales se cargaron exitosamente desde el archivo de texto", "No se pudieron cargar las editoriales en la lista");
					if (retorno == 0)
					{
						flagCargaEditoriales = 1;
					}
					system("pause");
				break;
				case 3:
					if(flagCargaEditoriales == 1 && flagCargaLibros == 1)
					{
					retorno = controller_sortLibros(listaLibros);
					Menu_AnalizarRetorno(retorno, "Los libros se ordenaron segun el criterio elegido", "No se pudieron ordenar los libros");
					}
					else
					{
						printf("Debe cargar los archivos de libros y de editoriales primero\n");
					}
					system("pause");
				break;
				case 4:
					if(flagCargaEditoriales == 1 && flagCargaLibros == 1)
					{
						retorno = controller_ListLibros(listaLibros, listaEditoriales);
						Menu_AnalizarRetorno(retorno, "Se muestra el listado de libros", "No se pudieron mostrar los libros");
					}
					else
					{
						printf("Debe cargar los archivos de libros y de editoriales primero\n");
					}
					system("pause");
				break;
				case 5:

					if(flagCargaEditoriales == 1 && flagCargaLibros == 1)
					{
						retorno = controller_ListarLibrosDeMinotauro(listaLibros, ARCHIVO_FILTRO, listaEditoriales);
						Menu_AnalizarRetorno(retorno, "Se muestra el listado de libros de la editorial Minotauro. El listado se guardo en un archivo de texto.", "No se pudo crear la lista");
					}
					else
					{
						printf("Debe cargar los archivos de libros y de editoriales primero\n");
					}
					system("pause");
				break;
				case 6:
					if(flagCargaEditoriales == 1 && flagCargaLibros == 1)
					{
						retorno = controller_mapeo(listaLibros, listaEditoriales, ARCHIVO_MAPEADO);
						Menu_AnalizarRetorno(retorno, "Se muestra el listado de libros con descuentos aplicados. El listado se guardo en un archivo de texto.", "No se pudo crear la lista");
					}
					else
					{
						printf("Debe cargar los archivos de libros y de editoriales primero\n");
					}
					system("pause");
				break;
				case 0:
					printf("\nHa salido del programa\n");
					system("pause");
				break;
			}
		}while(opcion != 0);
	}

	ll_deleteLinkedList(listaEditoriales);
	ll_deleteLinkedList(listaLibros);

	return EXIT_SUCCESS;
}
