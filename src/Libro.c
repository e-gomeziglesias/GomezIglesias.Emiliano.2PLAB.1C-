/*
 * Libro.c
 *
 *  Created on: 28 nov. 2021
 *      Author: Gomez Iglesias, Emiliano
 */

#include "Libro.h"
#define ID_MINOTAURO 4

//1.
eLibro* libro_new()
{
	eLibro* nuevoLibro;
	nuevoLibro = (eLibro*) calloc(1, sizeof(eLibro));
	return nuevoLibro;
}

//2.
eLibro* libro_newParametros(char* idStr, char* tituloStr, char* autorStr, char* precioStr, char* idEditorialStr)
{
	eLibro* pNuevoLibro = NULL;
	pNuevoLibro = libro_new();
	if(pNuevoLibro != NULL && idStr != NULL && tituloStr != NULL && autorStr != NULL && precioStr != NULL && idEditorialStr != NULL &&
		!libro_isValidIdLibro(idStr) && !libro_isValidTitulo(tituloStr) && !libro_isValidAutor(autorStr) && !libro_isValidPrecio(precioStr) && !libro_isValidIdEditorial(idEditorialStr))
	{
		if(libro_setId(pNuevoLibro, atoi(idStr)) ||
			libro_setTitulo(pNuevoLibro, tituloStr)||
			libro_setAutor(pNuevoLibro, autorStr) ||
			libro_setPrecio(pNuevoLibro, atof(precioStr)) ||
			libro_setIdEditorial(pNuevoLibro, atoi(idEditorialStr)))
		{
			libro_delete(pNuevoLibro); //si alguno de los campos no se pudo cargar, el libro no se carga y se libera la memoria reservada
		}
	}
	return pNuevoLibro;
}

//3.
void libro_delete(eLibro* pLibro)
{
	if(pLibro != NULL)
	{
		free(pLibro);
	}
}

//4.
int libro_setId(eLibro* this, int id)
{
	int retorno = -1;
	if(this!=NULL && id>=MIN_ID_LIBRO && id<=MAX_ID_LIBRO)
	{
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

//5.
int libro_getId(eLibro* this,int* id)
{
	int retorno = -1;

	if(this !=NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

//6.
int libro_setTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;
	if(this != NULL && titulo != NULL && strlen(titulo)<TAM_TITULO)
	{
		strcpy(this->titulo, titulo);
		retorno = 0;
	}
	return retorno;
}

//7.
int libro_getTitulo(eLibro* this,char* titulo)
{
	int retorno = -1;
	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo, this->titulo);
		retorno = 0;
	}
	return retorno;
}

//8.
int libro_setAutor(eLibro* this,char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL && strlen(autor)<TAM_AUTOR)
	{
		strcpy(this->autor, autor);
		retorno = 0;
	}
	return retorno;
}

//9.
int libro_getAutor(eLibro* this,char* autor)
{
	int retorno = -1;
	if(this != NULL && autor != NULL)
	{
		strcpy(autor, this->autor);
		retorno = 0;
	}
	return retorno;
}

//10.
int libro_setPrecio(eLibro* this, float precio)
{
	int retorno = -1;
	if(this!=NULL && (precio>=MIN_PRECIO && precio <=MAX_PRECIO))
	{
		this->precio = precio;
		retorno = 0;
	}
	return retorno;
}

//11.
int libro_getPrecio(eLibro* this, float* precio)
{
	int retorno = -1;
	if(this!=NULL && precio!=NULL)
	{
		*precio = this->precio;
		retorno = 0;
	}
	return retorno;
}

//12.
int libro_setIdEditorial(eLibro* this, int idEditorial)
{
	int retorno = -1;
	if(this!=NULL && idEditorial>=MIN_ID_EDITORIAL && idEditorial<=MAX_ID_EDITORIAL)
	{
		this->idEditorial = idEditorial;
		retorno = 0;
	}
	return retorno;
}

//13.
int libro_getIdEditorial(eLibro* this,int* idEditorial)
{
	int retorno = -1;

	if(this !=NULL && idEditorial != NULL)
	{
		*idEditorial = this->idEditorial;
		retorno = 0;
	}
	return retorno;
}

//14.
int libro_CompararPorAutor(void* l1, void* l2)
{
	int retorno = -1;
	eLibro* pLibro1 = NULL;
	eLibro* pLibro2 = NULL;

	char autorLibro1[500];
	char autorLibro2[500];

	if(l1 != NULL && l2 != NULL)
	{
		//unboxing
		pLibro1 = (eLibro*)l1;
		pLibro2 = (eLibro*)l2;
		if(!libro_getAutor(pLibro1, autorLibro1) &&
		!libro_getAutor(pLibro2, autorLibro2))
		{
			if(stricmp(autorLibro1, autorLibro2)>0)
			{
				retorno = 1;
			}
			else
			{
				if(stricmp(autorLibro1, autorLibro2)<0)
				{
					retorno = -1;
				}
				else
				{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}


int libro_CompararPorId(void* l1, void* l2)
{
	int retorno = -1;
	eLibro* pLibro1 = NULL;
	eLibro* pLibro2 = NULL;

	int idLibro1;
	int idLibro2;

	if(l1 != NULL && l2 != NULL)
	{
		//unboxing
		pLibro1 = (eLibro*)l1;
		pLibro2 = (eLibro*)l2;
		if(!libro_getId(pLibro1, &idLibro1) &&
		!libro_getId(pLibro2, &idLibro2))
		{
			if(idLibro1 > idLibro2)
			{
				retorno = 1;
			}
			else
			{
				if(idLibro1 < idLibro2)
				{
					retorno = -1;
				}
				else
				{
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

int libro_FiltrarMinotauro(void* pElement)
{
	int retorno = 0;
	eLibro* auxLibro;
	int auxIdEditorial;

	if(pElement != NULL)
	{
		auxLibro = (eLibro*) pElement;
		libro_getIdEditorial(auxLibro, &auxIdEditorial);
		if(auxIdEditorial == ID_MINOTAURO)
		{
			retorno = 1;
		}

	}
	return retorno;
}


//.
int libro_isValidIdLibro(char* idStr)
{
	int retorno = -1;
	if(idStr!= NULL && atoi(idStr)>=MIN_ID_LIBRO && atoi(idStr)<MAX_ID_LIBRO && !EsNumerica(idStr, sizeof(idStr)))
	{
		retorno = 0;
	}
	return retorno;
}

//.
int libro_isValidIdEditorial(char* idStr)
{
	int retorno = -1;
	if(idStr!= NULL && atoi(idStr)>=MIN_ID_EDITORIAL && atoi(idStr)<=MAX_ID_EDITORIAL && !EsNumerica(idStr, sizeof(idStr)))
	{
		retorno = 0;
	}
	return retorno;
}

//.
int libro_isValidAutor(char* autorStr)
{
	int retorno = -1;
	if(autorStr != NULL && !EsAlfabetica(autorStr, sizeof(autorStr)) && (strlen(autorStr)<(TAM_AUTOR)))
	{
		retorno = 0;
	}
	return retorno;
}

//.
int libro_isValidPrecio(char* precioStr)
{
	int retorno = -1;
	if(precioStr!= NULL && atof(precioStr)>=MIN_PRECIO && atof(precioStr)<=MAX_PRECIO && !EsNumerica(precioStr, sizeof(precioStr)))
	{
		retorno = 0;
	}
	return retorno;
}

int libro_isValidTitulo(char* tituloStr)
{
	int retorno = -1;
	if(tituloStr != NULL && (!EsAlfabetica(tituloStr, sizeof(tituloStr)|| !EsNumerica(tituloStr,sizeof(tituloStr)))) && (strlen(tituloStr)<(TAM_AUTOR)))
	{
		retorno = 0;
	}
	return retorno;
}
