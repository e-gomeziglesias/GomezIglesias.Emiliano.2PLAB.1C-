/*
 * Menu.c
 *
 *  Created on: 10 oct. 2021
 *      Author: Gomez Iglesias, Emiliano
 */
#include "Menu.h"

//1.
int Menu_MostrarMenuPrincipalOpciones (void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE OPCIONES\n\n");
	printf("1-Cargar los datos de libros desde un archivo\n");
	printf("2-Cargar los datos de editoriales desde un archivo\n");
	printf("3-Ordenar la lista de libros\n");
	printf("4-Listado de los libros\n");
	printf("5-Listado de los libros de la editorial MINOTAURO\n");
	printf("6-Generar el archivo de salida �mapeado.csv� luego de aplicar la funci�n map.\n");
	printf("0-Salir\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 6, 2);
	return opcion;
}


//4.
void Menu_AnalizarRetorno(int retorno, char mensaje[], char mensajeError[])
{
	if(mensaje != NULL && mensajeError != NULL)
	{
		if(retorno == -1)
		{
			printf("\n%s\n", mensajeError);
		}
		else
		{
			printf("\n%s\n", mensaje);
		}
	}
}

//5.
void Menu_AnalizarRetornoPunteros(void* pRetorno, char mensaje[], char mensajeError[])
{
	if(mensaje != NULL && mensajeError != NULL)
	{
		if(pRetorno == NULL)
		{
			printf("\n%s\n", mensajeError);
		}
		else
		{
			printf("\n%s\n", mensaje);
		}
	}
}


//3.
int Menu_MostrarMenuOrdenamiento(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE ORDENAMIENTO\n\n");
	printf("1-Libros ordenados por autor\n");
	printf("2-Libros ordenados por id\n");
/*
		printf("3-\n");
		printf("4-\n");
		printf("5-\n");
		printf("6-\n");
		printf("7-\n");
*/
	printf("0-Volver\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 2, 2);
	return opcion;
}




//2.
/*
int Menu_MostrarMenuModificacionesEmpleados(void)
{
	int opcion=-1;
	//system("cls");
	printf("		MENU DE MODIFICACIONES EMPLEADOS\n\n");
	printf("1-Nombre\n");
	printf("2-Horas trabajadas\n");
	printf("3-Sueldo\n");

		printf("4-\n");
		printf("5-\n");
		printf("6-\n");
		printf("7-\n");

	printf("0-Volver\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 3, 2);
	return opcion;
}
*/

/*

*/


/*
//2.
int Menu_MostrarMenuAltas(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE ALTAS\n\n");
	printf("1-CLIENTES\n");

	 	printf("2-\n");
		printf("3-\n");
		printf("4-\n");
		printf("5-\n");

	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 1, 2);
	return opcion;
}
*/

/*
//3.
int Menu_MostrarMenuBajas(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE BAJAS\n\n");
	printf("1-CLIENTES\n");

	 	printf("2-\n");
		printf("3-\n");
		printf("4-\n");
		printf("5-\n");

	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 1, 2);
	return opcion;
}
*/

/*
//4.
int Menu_MostrarMenuModificaciones(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE MODIFICACIONES\n\n");
	printf("1-CLIENTES\n");

	 	printf("2-\n");
		printf("3-\n");
		printf("4-\n");
		printf("5-\n");

	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 1, 2);
	return opcion;
}
*/

//4.2
/*int Menu_MostrarMenuModificacionesTipo(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE MODIFICACIONES TIPO DE PRODUCTO\n\n");
	printf("1-ID\n");
	printf("2-DESCRIPCION\n");
	printf("3-FABRICANTE DE PANTALLA\n");
	printf("0-CANCELAR\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 3, 2);
	return opcion;
}


//4.3
int Menu_MostrarMenuModificacionesNacionalidad(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE MODIFICACIONES NACIONALIDAD\n\n");
	printf("1-ID\n");
	printf("2-DESCRIPCION\n");
	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 2, 2);
	return opcion;
}
*/

/*
//5.
int Menu_MostrarMenuListados(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE LISTADOS\n\n");
	printf("1-LISTADO DE CLIENTES\n");
	printf("2-LISTADO DE PEDIDOS PENDIENTES\n");
	printf("3-LISTADO DE PEDIDOS PROCESADOS\n");

		printf("4-\n");
		printf("5-\n");
		printf("6-\n");
		printf("7-\n");

	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 3, 2);
	return opcion;
}
*/

/*
//6.
int Menu_MostrarMenuInformes(void)
{
	int opcion=-1;
	system("cls");
	printf("		MENU DE INFORMES\n\n");
	printf("1-PEDIDOS PENDIENTES PARA UNA LOCALIDAD\n");
	printf("2-CANTIDAD DE KILOS DE POLIPROPILENO RECICLADO PROMEDIO POR CLIENTE\n");
	printf("3-Cliente con m�s pedidos pendientes.\n");
	printf("4-Cliente con m�s pedidos completados\n");
	printf("5-Cliente con m�s pedidos.\n");

		printf("6-\n");
		printf("7-\n");
		printf("8-\n");
		printf("9-\n");
		printf("10-\n");
		printf("11-\n");
		printf("12-\n");
		printf("13-\n");

	printf("0-VOLVER\n");
	CargarEntero(&opcion, "Ingrese opcion: ", "La opcion ingresada es invalida.", 0, 5, 2);
	return opcion;
}
*/
