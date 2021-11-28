#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Editorial.h"
#include "Libro.h"
#include "File.h"


//1.
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	eLibro* pAuxLibro;
	char idStr[50];
	char tituloStr[150];
	char autorStr[150];
	char precioStr[50];
	char idEditorialStr[50];
	if(pFile != NULL && pArrayListLibro != NULL)
	{
		//falsa lectura para no cargar en el archivo las cabeceras
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, tituloStr, autorStr, precioStr, idEditorialStr);
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, tituloStr, autorStr, precioStr, idEditorialStr)==5)
			{
				if(!libro_isValidIdLibro(idStr) && !libro_isValidTitulo(tituloStr) && !libro_isValidAutor(autorStr) && !libro_isValidPrecio(precioStr) && !libro_isValidIdEditorial(idEditorialStr))
				{
					pAuxLibro = libro_newParametros(idStr, tituloStr, autorStr, precioStr, idEditorialStr);

					if(pAuxLibro != NULL)
					{
						retorno = ll_add((pArrayListLibro), pAuxLibro); //agrego el elemento a la linkedlist
					}
				}
			}
			if(feof(pFile)) //parche del while(feof) para evitar la potencial doble lectura
			{
				File_WriteNextIdTXTFile("nextIdLibro.txt", atoi(idStr)+1);
				break;
			}
		}
	}
	return retorno;
}

//2.
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	int tamCabecera;
	int nextId;
	eLibro* pAuxLibro;
	if(pFile != NULL && pArrayListLibro != NULL)
	{
		tamCabecera = strlen("id,titulo,autor,precio,idEditorial\n");
		fseek(pFile,tamCabecera,SEEK_SET);//ubico el indicador despues de la cabecera para saltearla
		while(!feof(pFile))
		{
			pAuxLibro = libro_new();
			if(pAuxLibro != NULL)
			{
				if(fread(pAuxLibro, sizeof(eLibro), 1, pFile)==1)
				{
					retorno = ll_add(pArrayListLibro, pAuxLibro);
					libro_getId(pAuxLibro, &nextId);//necesario para conseguir luego el siguiente id y guardarlo en archivo
				}
			}
			if(feof(pFile)) //parche del while(feof) para evitar la potencial doble lectura
			{
				File_WriteNextIdTXTFile("nextIdLibro.txt", nextId+1);
				break;
			}
		}
	}
	return retorno;
}

//3.
int parser_EditorialFromText(FILE* pFile , LinkedList* pArrayListEditorial)
{
	int retorno = -1;
	eEditorial* pAuxEditorial;
	char idStr[50];
	char nombreStr[150];
	if(pFile != NULL && pArrayListEditorial != NULL)
	{
		//falsa lectura para no cargar en el archivo las cabeceras
		fscanf(pFile, "%[^,],%[^\n]\n", idStr, nombreStr);
		while(!feof(pFile))
		{
			if(fscanf(pFile, "%[^,],%[^\n]\n", idStr, nombreStr)==2)
			{
				if(!editorial_isValidIdEditorial(idStr) && !editorial_isValidNombre(nombreStr))
				{
					pAuxEditorial = editorial_newParametros(idStr, nombreStr);

					if(pAuxEditorial != NULL)
					{
						retorno = ll_add((pArrayListEditorial), pAuxEditorial); //agrego el elemento a la linkedlist
					}
				}
			}
			if(feof(pFile)) //parche del while(feof) para evitar la potencial doble lectura
			{
				File_WriteNextIdTXTFile("nextIdEditorial.txt", atoi(idStr)+1);
				break;
			}
		}
	}
	return retorno;
}

//4.
int parser_EditorialFromBinary(FILE* pFile , LinkedList* pArrayListEditorial)
{
	int retorno = -1;
	int tamCabecera;
	int nextId;
	eEditorial* pAuxEditorial;
	if(pFile != NULL && pArrayListEditorial != NULL)
	{
		tamCabecera = strlen("id,editorial\n");
		fseek(pFile,tamCabecera,SEEK_SET);//ubico el indicador despues de la cabecera para saltearla
		while(!feof(pFile))
		{
			pAuxEditorial = editorial_new();
			if(pAuxEditorial != NULL)
			{
				if(fread(pAuxEditorial, sizeof(eLibro), 1, pFile)==1)
				{
					retorno = ll_add(pArrayListEditorial, pAuxEditorial);
					editorial_getId(pAuxEditorial, &nextId);//necesario para conseguir luego el siguiente id y guardarlo en archivo
				}
			}
			if(feof(pFile)) //parche del while(feof) para evitar la potencial doble lectura
			{
				File_WriteNextIdTXTFile("nextIdEditorial.txt", nextId+1);
				break;
			}
		}
	}
	return retorno;
}


