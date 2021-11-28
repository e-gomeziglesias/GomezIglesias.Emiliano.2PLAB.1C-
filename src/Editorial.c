/*
 * Editorial.c
 *
 *  Created on: 28 nov. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include "Editorial.h"

//1.
eEditorial* editorial_new()
{
	eEditorial* pNuevaEditorial;
	pNuevaEditorial = (eEditorial*) calloc(1, sizeof(eEditorial));
	return pNuevaEditorial;
}

//2.
eEditorial* editorial_newParametros(char* idStr, char* nombreStr)
{
	eEditorial* pNuevaEditorial = NULL;
	pNuevaEditorial = editorial_new();
	if(pNuevaEditorial != NULL && idStr != NULL && nombreStr != NULL &&
		!editorial_isValidIdEditorial(idStr) && !editorial_isValidNombre(nombreStr))
	{
		if(editorial_setId(pNuevaEditorial, atoi(idStr)) ||
			editorial_setNombre(pNuevaEditorial, nombreStr))
		{
			editorial_delete(pNuevaEditorial); //si alguno de los campos no se pudo cargar, el libro no se carga y se libera la memoria reservada
		}
	}
	return pNuevaEditorial;
}

//3.
void editorial_delete(eEditorial* pEditorial)
{
	if(pEditorial != NULL)
	{
		free(pEditorial);
	}
}

//4.
int editorial_setId(eEditorial* this, int id)
{
	int retorno = -1;
	if(this!=NULL && id>=MIN_ID_EDITORIAL && id<=MAX_ID_EDITORIAL)
	{
		this->idEditorial = id;
		retorno = 0;
	}
	return retorno;
}

//5.
int editorial_getId(eEditorial* this,int* id)
{
	int retorno = -1;

	if(this !=NULL && id != NULL)
	{
		*id = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}

//6.
int editorial_setNombre(eEditorial* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL && strlen(nombre)<TAM_EDITORIAL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}
	return retorno;
}

//7.
int editorial_getNombre(eEditorial* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 0;
	}
	return retorno;
}

int editorial_isValidIdEditorial(char* idStr)
{
	int retorno = -1;
	if(idStr!= NULL && atoi(idStr)>=MIN_ID_EDITORIAL && atoi(idStr)<=MAX_ID_EDITORIAL && !EsNumerica(idStr, sizeof(idStr)))
	{
		retorno = 0;
	}
	return retorno;
}

int editorial_isValidNombre(char* nombreStr)
{
	int retorno = -1;
	if(nombreStr != NULL && (!EsAlfabetica(nombreStr, sizeof(nombreStr))))//|| !EsNumerica(nombreStr,sizeof(nombreStr)))) && (strlen(nombreStr)<(TAM_EDITORIAL)))
	{
		retorno = 0;
	}
	return retorno;
}

/*
int editorial_MostrarUnaEditorial(eEditorial unaEditorial)
{
	int retorno = -1;
	int auxId;
	char auxNombre[TAM_EDITORIAL];
	if(!editorial_getId(&unaEditorial, &auxId) && !editorial_getNombre(&unaEditorial, auxNombre))
	{
		printf("%d %-20s", auxId, auxNombre);
		retorno = 0;
	}
	return retorno;
}

int editorial_MostrarEditoriales(eEditorial* this)
{
	int retorno = -1;
	if(this != NULL)
	{

	}
	return retorno;
}
*/
