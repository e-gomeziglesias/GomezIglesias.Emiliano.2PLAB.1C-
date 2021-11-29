#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Editorial.h"
#include "Libro.h"
#include "parser.h"
#include "File.h"
#include "Controller.h"
#include "Menu.h"


//1.
/** \brief Carga los datos de los libros desde un archivo (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* linkedlist donde se cargaran los libros
 * \return int 0 si ok, -1 si error
 *
 */
int controller_loadLibroFromText(char* path , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListLibro != NULL)
	{
		ll_clear(pArrayListLibro);//limpio la lista para que al abrir el texto se cargue desde la primer posicion
		pFile=File_OpenTXTFileForReading(path);//abro el archivo para lectura de texto
		if(pFile!=NULL)
		{
			retorno = parser_LibroFromText(pFile, pArrayListLibro);
		}
		File_CloseFile(pFile); //cierro el archivo
	}
	return retorno;
}

/** \brief Carga los datos de las editoriales desde un archivo (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* linkedlist donde se cargaran las editoriales
 * \return int 0 si ok, -1 si error
 *
 */
int controller_loadEditorialFromText(char* path , LinkedList* pArrayListEditorial)
{
	int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListEditorial != NULL)
	{
		ll_clear(pArrayListEditorial);//limpio la lista para que al abrir el texto se cargue desde la primer posicion
		pFile=File_OpenTXTFileForReading(path);//abro el archivo para lectura de texto
		if(pFile!=NULL)
		{
			retorno = parser_EditorialFromText(pFile, pArrayListEditorial);
		}
		File_CloseFile(pFile); //cierro el archivo
	}
	return retorno;
}

//2.
/** \brief Carga los datos de los libros desde un archivo (modo binario).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* linkedlist donde se guardara el listado de libros
 * \return int 0 si ok, -1 si error
 *
 */
int controller_loadLibroFromBinary(char* path , LinkedList* pArrayListLibro)
{
	int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListLibro != NULL)
	{
		ll_clear(pArrayListLibro);//limpio la lista para que al abrir el archivo se cargue desde la primer posicion
		pFile = File_OpenBINFileForReading(path);//abro el archivo para lectura binaria
		if(pFile != NULL)
		{
			retorno = parser_LibroFromBinary(pFile, pArrayListLibro);
		}
		File_CloseFile(pFile);//cierro el archivo
	}
	return retorno;
}

//2.
/** \brief Carga los datos de los libros desde un archivo (modo binario).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* linkedlist donde se guardara el listado de libros
 * \return int 0 si ok, -1 si error
 *
 */
int controller_loadEditorialFromBinary(char* path , LinkedList* pArrayListEditorial)
{
	int retorno = -1;
	FILE* pFile;
	if(path != NULL && pArrayListEditorial != NULL)
	{
		ll_clear(pArrayListEditorial);//limpio la lista para que al abrir el archivo se cargue desde la primer posicion
		pFile = File_OpenBINFileForReading(path);//abro el archivo para lectura binaria
		if(pFile != NULL)
		{
			retorno = parser_EditorialFromBinary(pFile, pArrayListEditorial);
		}
		File_CloseFile(pFile);//cierro el archivo
	}
	return retorno;
}

//10.
/// @fn int controller_getLibro(LinkedList*, int, int*, char*, char*, float*, int*)
/// @brief Permite recuperar los datos de cada campo de un libro que se encuentra en una lista, pasando su indice por parametro
///
/// @param pArrayListLibro lista donde buscar el libro
/// @param index indice del libro a buscar
/// @param pId puntero a la variable donde se guardara el indice
/// @param titulo puntero a la cadena donde se guaradara el titulo
/// @param autor puntero a la cadena donde se guaradara el autor
/// @param pPrecio puntero a la variable donde se guardara el precio
/// @param pIdEditorial puntero a la variable donde se guardara el id de la editorial
/// @return 0 si ok, -1 si error
int controller_getLibro(LinkedList* pArrayListLibro, int index, int* pId, char* titulo, char* autor, float* pPrecio, int* pIdEditorial)
{
	int retorno = -1;
	eLibro* pAuxLibro;
	if(pArrayListLibro != NULL && pId != NULL && titulo!= NULL && autor != NULL && pPrecio != NULL && pIdEditorial != NULL)
	{
		//unboxing
		pAuxLibro = (eLibro*) ll_get(pArrayListLibro, index);
		if(pAuxLibro != NULL)
		{//asigno cada campo al auxiliar
			if(!libro_getId(pAuxLibro, pId) &&
					!libro_getTitulo(pAuxLibro, titulo) &&
					!libro_getAutor(pAuxLibro, autor) &&
					!libro_getPrecio(pAuxLibro, pPrecio) &&
					!libro_getIdEditorial(pAuxLibro, pIdEditorial))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

//10.
/// @fn int controller_getEditorial(LinkedList*, int, int*, char*)
/// @brief Permite recuperar los datos de todos los campos de una editorial almacenada en una lista, pasando su indice por parametro
///
/// @param pArrayListEditorial lista donde buscar la editorial
/// @param index indice de la editorial
/// @param pId puntero a la variable donde se guardara el id de la editorial
/// @param nombre puntero a la cadena donde se guardara el nombre
/// @return 0 si ok, -1 si error
int controller_getEditorial(LinkedList* pArrayListEditorial, int index, int* pId, char* nombre)
{
	int retorno = -1;
	eEditorial* pAuxEditorial;
	if(pArrayListEditorial != NULL && pId != NULL && nombre!= NULL)
	{
		//unboxing
		pAuxEditorial = (eEditorial*) ll_get(pArrayListEditorial, index);
		if(pAuxEditorial != NULL)
		{//asigno cada campo al auxiliar
			if(!editorial_getId(pAuxEditorial, pId) &&
				!editorial_getNombre(pAuxEditorial, nombre))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

//11.
/// @fn int controller_MostrarUnaEditorialCompleta(LinkedList*, int)
/// @brief Permite mostrar los datos de todos los campos de una editorial
///
/// @param pArrayListEditorial listado de editoriales
/// @param index indice de la editorial
/// @return 0 si ok, -1 si error
int controller_MostrarUnaEditorialCompleta(LinkedList* pArrayListEditorial, int index)
{
	int retorno=-1;
	int auxId;
	char auxNombre[128];
	if(pArrayListEditorial != NULL && index >=0)
	{
		if(!controller_getEditorial(pArrayListEditorial, index, &auxId, auxNombre))
		{
			printf("%4d	%-20s\n", auxId, auxNombre);
			retorno = 0;
		}
	}
	return retorno;
}

/// @fn int controller_MostrarDescripcionUnaEditorial(LinkedList*, int)
/// @brief Permite mostrar la descripcion de una editorial
///
/// @param pArrayListEditorial listado de editoriales
/// @param index indice de la editorial
/// @return 0 si ok, -1 si error
int controller_MostrarDescripcionUnaEditorial(LinkedList* pArrayListEditorial, int index)
{
	int retorno=-1;
	int auxId;
	char auxNombre[128];
	if(pArrayListEditorial != NULL && index >=0)
	{
		if(!controller_getEditorial(pArrayListEditorial, index, &auxId, auxNombre))
		{
			printf("%-20s", auxNombre);
			retorno = 0;
		}
	}
	return retorno;
}

int controller_MostrarUnLibroCompleto(LinkedList* pArrayListLibro, int indexLibro, LinkedList* pArrayListEditorial)
{
	int retorno=-1;
	int auxIdLibro;
	char auxTitulo[128];
	char auxAutor[128];
	float auxPrecio;
	int auxIdEditorial;
	//char auxNombreEditorial[128];
	int auxIndiceEditorial;
	if(pArrayListEditorial != NULL && indexLibro >=0)
	{
		if(!controller_getLibro(pArrayListLibro, indexLibro, &auxIdLibro, auxTitulo, auxAutor, &auxPrecio, &auxIdEditorial))
		{
			auxIndiceEditorial = controller_getIndexEditorialById(pArrayListEditorial, auxIdEditorial);
			if(auxIndiceEditorial != -1)
			{
				printf("%4d %-50s %-25s %.2f ",auxIdLibro, auxTitulo, auxAutor, auxPrecio);
				controller_MostrarDescripcionUnaEditorial(pArrayListEditorial, auxIndiceEditorial);
				printf("\n");
				retorno = 0;
			}
		}
	}
	return retorno;
}

/// @fn int controller_getIndexEditorialById(LinkedList*, int)
/// @brief Permite obtener el indice de una editorial a partir de su id
///
/// @param pArrayListEditorial listado de editoriales
/// @param id id a buscar
/// @return si lo encuentra devuelve el indice, sino devuelve -1
int controller_getIndexEditorialById(LinkedList* pArrayListEditorial, int id)
{
	int retorno = -1;
	int auxId;
	int tamLista;
	eEditorial* pEditorial;
	if(pArrayListEditorial!=NULL && id>0)
	{
		tamLista = ll_len(pArrayListEditorial);
		if(tamLista>0)
		{
			for(int i=0; i<tamLista; i++)
			{
				pEditorial = ll_get(pArrayListEditorial, i);
				if(pEditorial != NULL)
				{
					editorial_getId(pEditorial, &auxId);
					if(id == auxId)
					{
						retorno = i;
						break;
					}
				}
			}
		}
	}
	return retorno;
}

/// @fn int controller_getIndexLibroById(LinkedList*, int)
/// @brief Permite obtener el indice de un libro a partir de su id
///
/// @param pArrayListLibro listado de libros
/// @param id id a buscar
/// @return si lo encuentra devuelve el indice, sino devuelve -1
int controller_getIndexLibroById(LinkedList* pArrayListLibro, int id)
{
	int retorno = -1;
	int auxId;
	int tamLista;
	eLibro* pLibro;
	if(pArrayListLibro!=NULL && id>0)
	{
		tamLista = ll_len(pArrayListLibro);
		if(tamLista>0)
		{
			for(int i=0; i<tamLista; i++)
			{
				pLibro = ll_get(pArrayListLibro, i);
				if(pLibro != NULL)
				{
					libro_getId(pLibro, &auxId);
					if(auxId == id)
					{
						retorno = i;
						break;
					}
				}
			}
		}
	}
	return retorno;
}


/// @fn int controller_ListLibros(LinkedList*, LinkedList*)
/// @brief Muestra un listado completo de todos los libros con el nombre de la editorial
///
/// @param pArrayListLibro array de libros
/// @param pArrayListEditorial array de editoriales
/// @return 0 si ok, -1 si error
int controller_ListLibros(LinkedList* pArrayListLibro, LinkedList* pArrayListEditorial)
{
	int retorno = -1;
	int tamLista;
	if(pArrayListLibro != NULL && pArrayListEditorial != NULL)
	{
		tamLista = ll_len(pArrayListLibro);
		if(tamLista>0)
		{
			printf("  ID	TITULO		   				AUTOR 			  PRECIO EDITORIAL\n");
			for(int i=0; i<tamLista; i++)
			{
				controller_MostrarUnLibroCompleto(pArrayListLibro, i, pArrayListEditorial);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/// @fn int controller_ListEditoriales(LinkedList*, LinkedList*)
/// @brief Permite mostrar el listado completo de editoriales
///
/// @param pArrayListLibro l
/// @param pArrayListEditorial
/// @return
int controller_ListEditoriales(LinkedList* pArrayListEditorial)
{
	int retorno = -1;
	int tamLista;
	if(pArrayListEditorial != NULL)
	{
		tamLista = ll_len(pArrayListEditorial);
		if(tamLista>0)
		{
			printf("  ID	NOMBRE\n");
			for(int i=0; i<tamLista; i++)
			{
				controller_MostrarUnaEditorialCompleta(pArrayListEditorial, i);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Ordenar libros por autor o por id, indicando criterio ascendente o descendente
 *
 * \param pArrayListEmployee LinkedList* lista a ordenar
 * \return int 0 si ok, -1 si error
 *
 */
int controller_sortLibros(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	int criterio;
	if(pArrayListEmployee != NULL)
	{
		do
		{
			opcion = Menu_MostrarMenuOrdenamiento();

			switch(opcion)
			{
				case 1:
					if(CargarEntero(&criterio, "Indique el criterio de ordenamiento (0-descendente / 1-ascendente): ", "El criterio ingresado es invalido." , 0, 1, 2)==-1)
					{
						break;
					}
					retorno = ll_sort(pArrayListEmployee, libro_CompararPorAutor, criterio);
					opcion = 0;
				//system("pause");
				break;

				case 2:
					if(CargarEntero(&criterio, "Indique el criterio de ordenamiento (0-descendente / 1-ascendente): ", "El criterio ingresado es invalido." , 0, 1, 2)==-1)
					{
						break;
					}
					retorno = ll_sort(pArrayListEmployee, libro_CompararPorId, criterio);
					opcion = 0;
				//system("pause");
				break;

				case 0:
					printf("Volviendo al menu principal\n");
				system("pause");
				break;
			}
		}while(opcion != 0);
	}
	return retorno;
}


int controller_ListarLibrosDeMinotauro(LinkedList* pArrayListaLibro, char* pathArchivoMinotauro, LinkedList* pArrayListEditorial)
{
	int retorno = -1;
	LinkedList* listaMinotauro = NULL;

	if(pArrayListaLibro != NULL)
	{
		listaMinotauro = ll_filter(pArrayListaLibro, libro_FiltrarMinotauro);
		if(listaMinotauro != NULL)
		{
			if(!controller_saveLibroAsText(pathArchivoMinotauro, listaMinotauro) && !controller_ListLibros(listaMinotauro, pArrayListEditorial))
			{
				retorno = 0;
			}
		}
		ll_deleteLinkedList(listaMinotauro);
	}
	return retorno;
}

int controller_mapeo(LinkedList* pArrayListaLibro, LinkedList* pArrayListEditorial, char* pathArchivoMapeo)
{
	int retorno = -1;
	LinkedList* listaMapeada;
	if(pArrayListaLibro != NULL && pathArchivoMapeo != NULL)
	{
		listaMapeada = ll_map(pArrayListaLibro, libro_Mapear);
		if(!controller_ListLibros(listaMapeada, pArrayListEditorial))
		{
			retorno = controller_saveLibroAsText(pathArchivoMapeo, listaMapeada);
		}
	}
	return retorno;
}

/// @fn int controller_saveLibroAsText(char*, LinkedList*)
/// @brief Permite guardar un listado del libros en archivo (modo texto)
///
/// @param path ruta del archivo
/// @param pArrayListLibro listado de libros
/// @return 0 si ok, -1 si error
int controller_saveLibroAsText(char* path , LinkedList* pArrayListLibro)
{
    int retorno = -1;
    int tamLista;
    FILE* pFile;
    int id;
    char titulo[150];
    char autor[150];
    float precio;
    int idEditorial;

    if(path != NULL && pArrayListLibro != NULL)
    {
    	pFile = File_OpenTXTFileForWriting(path);
    	if(pFile != NULL)
    	{
        	tamLista = ll_len(pArrayListLibro);
        	{
        		fprintf(pFile, "id,titulo,autor,precio,idEditorial\n");//imprimo la cabecera en el archivo
            	for(int i=0; i<tamLista; i++)
            	{
            		retorno = controller_getLibro(pArrayListLibro, i, &id, titulo, autor, &precio, &idEditorial);
            		if(retorno)
            		{
            			break;
            		}
            		else
            		{
                		fprintf(pFile, "%d,%s,%s,%.2f,%d\n", id, titulo, autor, precio, idEditorial);
            		}
            	}
        	}
        	File_CloseFile(pFile);
    	}
    }
    return retorno;
}

/// @fn int controller_saveLibroAsText(char*, LinkedList*)
/// @brief Permite guardar un listado del libros en archivo (modo texto)
///
/// @param path ruta del archivo
/// @param pArrayListLibro listado de libros
/// @return 0 si ok, -1 si error
int controller_saveEditorialAsText(char* path , LinkedList* pArrayListEditorial)
{
    int retorno = -1;
    int tamLista;
    FILE* pFile;
    int id;
    char nombre[150];

    if(path != NULL && pArrayListEditorial != NULL)
    {
    	pFile = File_OpenTXTFileForWriting(path);
    	if(pFile != NULL)
    	{
        	tamLista = ll_len(pArrayListEditorial);
        	{
        		fprintf(pFile, "id,nombre\n");//imprimo la cabecera en el archivo
            	for(int i=0; i<tamLista; i++)
            	{
            		retorno = controller_getEditorial(pArrayListEditorial, i, &id, nombre);
            		if(retorno)
            		{
            			break;
            		}
            		else
            		{
                		fprintf(pFile, "%d,%s\n", id, nombre);
            		}
            	}
        	}
        	File_CloseFile(pFile);
    	}
    }
    return retorno;
}

//3.
/** \brief Permite dar de alta un empleado, cargando los datos por teclado
 *
 * \param pArrayListEmployee LinkedList* linkedlist donde se guardara el empleado
 * \return int 0 si ok, -1 si error
 *
 */
/*
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmpleado;
	int id;
	char nombre[TAM_NOMBRE];
	int horasTrabajadas;
	int sueldo;
	int index;

	if(pArrayListEmployee != NULL)
	{
		pEmpleado = (Employee*) employee_new();
		if(pEmpleado != NULL)
		{
			if(!employee_CargarNombre(nombre)&&
			   !employee_CargarHorasTrabajadas(&horasTrabajadas)&&
			   !employee_CargarSueldo(&sueldo))
			{
				if(!employee_CargarId(&id))//como crea un archivo de texto, lo verifico luego de que se hayan cargado correctamente las otras variables para no generar un id erroneo
				{
					if(!employee_setEmployee(pEmpleado, id, nombre, horasTrabajadas, sueldo))
					{
						retorno = ll_add(pArrayListEmployee, pEmpleado);
						if(retorno == 0)
						{
							index = controller_getIndexEmployeeById(pArrayListEmployee, id);
							printf("  ID	NOMBRE		   HORAS 	SUELDO\n");
							controller_PrintOneEmployee(pArrayListEmployee, index);
							printf("\n");
						}
					}
				}
			}
			if(retorno ==-1 && pEmpleado != NULL)
			{
				employee_delete(pEmpleado);//si ocurrio algun error y no se pudo agregar el empleado a la linkedlist, libera la memoria reservada
			}
		}
	}
	return retorno;
}
*/
//4.
/** \brief Permite modificar cada uno de los campos de un empleado
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si ok, -1 si error
 *
 */

/*
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* pEmpleado;
	int retorno = -1;
	int idEmpleadoAModificar;
	int opcion;
	int index;
	char nombre[TAM_NOMBRE];
	int horasTrabajadas;
	int sueldo;
	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		if(CargarEntero(&idEmpleadoAModificar, "Ingrese el id del empleado a modificar: ","El id ingresado es invalido." , 1, MAX_ID, 2)==0)
		{
			index = controller_getIndexEmployeeById(pArrayListEmployee, idEmpleadoAModificar);
			pEmpleado = (Employee*) ll_get(pArrayListEmployee, index);
			if(pEmpleado != NULL)
			{
				do
				{
					printf("  ID	NOMBRE		   HORAS 	SUELDO\n");
					controller_PrintOneEmployee(pArrayListEmployee, index);
					printf("\n");
					opcion = Menu_MostrarMenuModificacionesEmpleados();
					switch(opcion)
					{
						case 1:
							if(!employee_CargarNombre(nombre))
							{
								retorno = employee_setNombre(pEmpleado, nombre);
								Menu_AnalizarRetorno(retorno, "Se modifico con exito el nombre", "El nombre no se pudo modificar");
							}
							system("pause");
						break;

						case 2:
							if(!CargarEntero(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas: ", "La cantidad de horas ingresada es invalida.", 0, 1000, 2))
							{
								retorno = employee_setHorasTrabajadas(pEmpleado, horasTrabajadas);
								Menu_AnalizarRetorno(retorno, "Se modificaron con exito las horas trabajadas.", "Las horas trabajadas no se pudieron modificar.");
							}
							system("pause");
						break;

						case 3:
							if(!CargarEntero(&sueldo, "Ingrese el sueldo: ", "El sueldo ingresado es invalido.", 0, MAX_SUELDO, 2))
							{
								retorno = employee_setSueldo(pEmpleado, sueldo);
								Menu_AnalizarRetorno(retorno, "Se modifico con exito el sueldo.", "El sueldo del empleado no se pudo modificar.");
							}
							system("pause");
						break;

						case 0:
							printf("Volviendo al menu principal\n");
							system("pause");
						break;

					}
				}while(opcion!=0);
			}
		}

	}
	return retorno;
}

//5.
 //\brief Baja de empleado. Permite dar de baja un empleado, eliminandolo de la linkedlist y liberando la memoria que ocupaba
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si ok, -1 si error
 *
 */
/*
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmpleado;
	char opcion = 'n';
	int id;
	int index;
	if(pArrayListEmployee != NULL)
	{
			if(controller_ListEmployee(pArrayListEmployee)!=-1)
			{
				if(!CargarEntero(&id, "Ingrese el id del empleado a borrar: ", "El id ingresado es invalido.", 1, MAX_ID, 2))
				{
					index = controller_getIndexEmployeeById(pArrayListEmployee, id);
					if(index != -1)
					{
						controller_PrintOneEmployee(pArrayListEmployee, index); //muestro el empleado a borrar
						CargarChar(&opcion, "Desea borrar este empleado? (s/n): ","La respuesta ingresada es incorrecta." , 0, 2); //confirmo la eliminacion
						if(opcion == 's')
						{
							pEmpleado = (Employee*) ll_pop(pArrayListEmployee, index); //borro el empleado de la linkedlist
							employee_delete(pEmpleado); //libero la direccion de memoria del empleado
							retorno = 0;
						}
					}
					else
					{
						retorno = -2;
					}
				}
			}
	}
	return retorno;
}
*/
//6.


//7.


//8.
/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista de donde se recuperaran los datos a guardar
 * \return int 0 si ok, -1 si error
 *
 */
/*

//9.
// \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista de donde se recuperaran los datos que se guardaran en el archivo
 * \return int 0 si ok, -1 si error
 *
 */
/*
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    char cabeceraArchivo[]="id,nombre,horasTrabajadas,sueldo";
	int tamLista;
	Employee* pEmpleado;

    if(path != NULL && pArrayListEmployee != NULL)
	{
		pFile = File_OpenBINFileForWriting(path);//abro el archivo para escritura binaria
		tamLista = ll_len(pArrayListEmployee);
		if(pFile!=NULL)
		{
			if(fwrite(cabeceraArchivo, sizeof(cabeceraArchivo), 1, pFile)==1)//escribo en el archivo binario la cabecera con los titulos
			{
				for(int i=0; i<tamLista; i++)
				{
					//unboxing del empleado
					pEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
					if(pEmpleado != NULL)
					{
						fwrite(pEmpleado, sizeof(Employee), 1, pFile);//imprimo el empleado en el archivo
						retorno = 0;
					}
					else
					{
						retorno = -1;
						break;
					}
				}
			}
			File_CloseFile(pFile); //cierro el archivo
		}
	}
    return retorno;
}
*/



/*



*/
