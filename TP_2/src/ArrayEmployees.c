/*
 * Pantalla.c
 */

#include "ArrayEmployees.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn.h"
#define EMP_LEN 1000
static const char TXT_SECTOR [3][15] ={"Administrativo","Tecnico", "Maestranza"};


/*
 * \brief Imprime los datos del empleado
 * \param pElemento Puntero al elemento que se busca imprimir
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int emp_print (Employee* pElemento)
{
	int retorno = -1;
	if (pElemento != NULL && pElemento->isEmpty == 0){
		retorno = 0;
		printf ("\n ID CLIENTE: %-15d - NOMBRE: %-15s - APELLIDO: %-15s - SALARIO: %-15.2f -SECTOR: %-15s\n",pElemento->idEmployee, pElemento->name, pElemento->lastName, pElemento->salary, TXT_SECTOR[pElemento->sector]);
	}
	return retorno;
}
/*
 * \brief Imprime el array de empleados
 * \param array Array de empleados a ser actualizado
 * \param limite Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int emp_printArray (Employee* array, int limite)
{
	int retorno = -1;
	int i;
	if (array != NULL && limite >0){
		retorno = 0;
		for (i=0; i<limite; i++)
		{
			emp_print(&array [i]);
		}
	}
	return retorno;
}


/** \brief To indicate that all position in the array are empty,
* 			this function put the flag (isEmpty) in TRUE in all
* 			position of the array
* \param array Employee* Pointer to array of employees
* \param limite int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int emp_initEmployees (Employee* array, int limite)
{
	int retorno = -1;
	int i;
	if(array != NULL && limite>0){
		retorno = 0;
		for (i=0; i<limite; i++){
			array [i].isEmpty = 1;
		}
	}
	return retorno;
}
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param array employee*
* \param limite int Array length
*  \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
				free space] - (0) if Ok
*/
int emp_addEmployees(Employee* array, int limite, int indice, int* id)
{
	int retorno = -1;
	Employee bufferEmp;
	if (array != NULL && limite>0 && indice<limite && indice >= 0 && id != NULL){
		if (utn_getNombre(bufferEmp.name,NOMBRE_LEN, "\nIngrese nombre\n", "\nError", 3)==0 &&
			utn_getNombre(bufferEmp.lastName, APELLIDO_LEN, "\nIngrese apellido?:\n", "\nError", 3) ==0 &&
			utn_getNumeroFlotante(&bufferEmp.salary, "\nIngrese su salario\n", "\nError\n", 0, 6000000, 3) == 0 &&
			utn_getNumeroInt(&bufferEmp.sector, "\nIngrese sector: \n 0: Administrativo\n 1: Tecnico\n 2: Maestranza", "Error", 0, 3, 3)==0)
		{
			bufferEmp.idEmployee =*id;
			bufferEmp.isEmpty = 0;
			array[indice] = bufferEmp;
			(*id)++;
			retorno = 0;
		}
	}
	return retorno;
}
/*
 * \brief Actualiza los datos del empleado en una posicion del array
 * \param array Array de empleados a ser actualizados
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */

int emp_modificarArray (Employee* array, int limite, int indice)
{
	int retorno = -1;
	Employee bufferEmp;
	if (array!=NULL && limite>0 && indice<limite && indice>=0 && array[indice].isEmpty ==0){
		if (utn_getNombre(bufferEmp.name,NOMBRE_LEN, "\nIngrese nombre", "\nError", 3)==0 &&
			utn_getNombre(bufferEmp.lastName, APELLIDO_LEN, "\nIngrese apellido?:", "\nError", 3) ==0 &&
			utn_getNumeroFlotante(&bufferEmp.salary, "\nIngrese su salario\n", "\nError\n", 0, 600000, 3) == 0 &&
			utn_getNumeroInt(&bufferEmp.sector, "\nIngrese sector: \n 0: Administrativo\n 1: Tecnico\n 2: Maestranza", "Error", 0, 3, 3)==0)
		{
			bufferEmp.idEmployee = array[indice].idEmployee;
			bufferEmp.isEmpty = 0;
			array[indice] = bufferEmp;
			retorno = 0;
		}
	}
	return retorno;
}
/*
 * \brief Actualiza los datos del empleado en una posicion del array
 * \param array Array de empleados a ser actualizados
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int emp_cargarModificarArray (Employee* array, int limite, int indice)
{
	int retorno = 0;
	int posicion;
	int modificoArray;
	int valorBuscado;
	if (array != NULL && limite >0 && indice < limite && indice >= 0)
	{
		emp_printArray(array, EMP_LEN);
		if (utn_getNumeroInt(&valorBuscado,"\n Indique el ID del cliente a modificar", "\n Id invalido", 0, EMP_LEN, 2)==0)
		{
			posicion = emp_findEmployeeById(array, EMP_LEN, valorBuscado);
		}
		if(posicion == -1)
		{
			printf("\nEl ID ingresado no existe\n");
		}
		else
		{
			modificoArray = emp_modificarArray(array, EMP_LEN, posicion);
			if (modificoArray == 0)
			{
				printf ("\n Modificacion realizada con exito \n");
				retorno = 1;
			}
		}
	}
	return retorno;
}

/*
 * \brief Actualiza una posicion del array
 * \param array Array de empleados a ser actualizados
 * \param limite Limite del array de empleados
 * \param indice Posicion a ser actualizado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int emp_removeEmployee (Employee* array, int limite, int indice)
{
	int retorno = -1;
	int respuesta;
	int auxiliarIndice;
	emp_printArray(array, limite);
	if (utn_getNumeroInt(&respuesta, "\nIndique el ID del empleado a eliminar\n", "\nError\n", 0, EMP_LEN, 3) == 0 &&
			emp_findEmployeeById(array, limite, respuesta) != -1)
	{
		auxiliarIndice = emp_findEmployeeById(array, limite, respuesta);
		printf("\nEsta seguro que desea eliminar al empleado: %s %s ?", array[auxiliarIndice].name, array[auxiliarIndice].lastName);
		if (utn_getNumeroInt(&respuesta, "\n[SI: 1 / NO: 0)\n", "Error", 0, 2, 3)==0)
		{
			if (respuesta == 1)
			{
				if (auxiliarIndice>= 0 && array != NULL && limite >0 && auxiliarIndice <limite && auxiliarIndice >= 0 && array[auxiliarIndice].isEmpty ==0)
				{
					array[auxiliarIndice].isEmpty = 1;
					retorno = 0;
					printf ("\nBaja realizada con exito\n");
				}
			}
		}
	}
	else
	{
		printf("\nEl ID ingresado no existe\n");
	}
	return retorno;
}
/** \brief find an Employee by Id en returns the index position in array.
*
* \param array Employee*
* \param limite int
* \param valorBuscado int
* \return Return employee index position or (-1) if [Invalid length or NULL
			pointer received or employee not found]
*/

int emp_findEmployeeById (Employee* array, int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite>0 && valorBuscado>=0){
		for (i=0; i<limite; i++){
			if (array[i].idEmployee == valorBuscado){
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/*
 * \brief Buscar la primera posicion que este vacia
 * \param array Array de empleados
 * \param limite Limite del array de empleados
 * \return Retorna -1 (ERROR) o el indice de la posicion vacia
 */

int emp_getEmptyIndex (Employee* array, int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite>0){
		respuesta = 0;
		for (i=0; i<limite; i++){
			if (array[i].isEmpty == 1){
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/*
 * \brief Ordenar el array de empleados por sector
 * \param array Array de ..
 * \param limite Limite del array de ..
 * \return Retorna
 */

int emp_ordenarPorSector (Employee* array, int limite)
{
	int respuesta = -1;
	int i;
	Employee buffer;
	int flagSwap;
	if(array != NULL && limite>0)
	{
		do
		{
			flagSwap = 0;
			for (i=0; i<limite-1; i++)
			{
				if(array [i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if (array[i].sector > array [i+1].sector)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1] = buffer;
					respuesta= 0;
				}
			}
			limite--;
		}while (flagSwap);
	}
	return respuesta;
}
/*
 	 \brief Sort the elements in the array of employees, the argument order
	indicate UP or DOWN order
*
* \param array Employee*
* \param limite int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int emp_sortEmployeesByLastName(Employee* array, int limite)
{
	int respuesta = -1;
		int i;
		Employee buffer;
		int flagSwap;
		if(array != NULL && limite>=0)
		{
			do
			{
				flagSwap = 0;
				for (i=0; i<limite-1; i++)
				{
					if(array [i].isEmpty == 0 && array[i+1].isEmpty== 0)
					{
						if (strncmp(array[i].lastName, array[i+1].lastName, APELLIDO_LEN) >0 ||
							strncmp(array[i].lastName, array[i+1].lastName, APELLIDO_LEN) ==0)
						{
							flagSwap = 1;
							buffer = array[i];
							array[i] = array[i+1];
							array[i+1] = buffer;
							respuesta = 0;
						}
					}
				}
				limite--;
			}while (flagSwap);
		}
		return respuesta;
}

void emp_printSort (Employee* array, int limite)
{
	if (emp_sortEmployeesByLastName(array, limite) == 0 &&
		emp_ordenarPorSector(array, limite) == 0)
	{
		emp_printArray(array, limite);
	}
}

int emp_printSalario (Employee* array, int limite, int indice)
{
	int respuesta = -1;
	int i;
	int j;
	float totalSalary;
	float promedio;
	int contador= 0;
	int contadorEmpleados=0;
	if(array != NULL && limite>=0)
	{
		for (i=0; i<limite; i++)
		{
			if(array [i].isEmpty == 0 && array[i].salary)
			{
				totalSalary= totalSalary+array[i].salary;
				contador++;
				respuesta = 0;
			}
		}
		promedio = totalSalary / contador;
	}
	for (j=0; j<limite; j++)
	{
		if (array [j].isEmpty == 0 && array[j].salary>=promedio)
		{
			contadorEmpleados++;
			respuesta = 0;
		}
	}
	printf ("\n\nTotal de los salarios: $%.2f\n", totalSalary);
	printf ("\nEl promedio de los salarios es: $%.2f\n", promedio);
	printf("\nCantidad de empleados que superan el salario promedio: %d", contadorEmpleados);
	return respuesta;
}



int emp_altaArrayForzada (Employee* array, int limite, int indice, int* id, char* nombre, char* apellido, float salario, int sector)
{
	int respuesta = -1;
	Employee bufferEmp;

	if (array != NULL && limite >0 && indice <limite && indice >= 0 && id != NULL)
	{
		strncpy(bufferEmp.lastName, apellido, APELLIDO_LEN);
		strncpy(bufferEmp.name, nombre, NOMBRE_LEN);
		bufferEmp.salary = salario;
		bufferEmp.sector = sector;
		respuesta = 0;
		bufferEmp.idEmployee = *id;
		bufferEmp.isEmpty=0;
		array[indice] = bufferEmp;
		(*id)++;
	}
	return respuesta;
}


int emp_cargarAuxIndice (Employee* array, int limite, int indice, int* id)
{
   int auxiliarIndice;
   auxiliarIndice= emp_getEmptyIndex(array, limite);
    return auxiliarIndice;
}

void emp_cargarEmployee(Employee* array, int limite, int indice, int* id)
{
	indice = emp_cargarAuxIndice(array, limite, indice, id);
    if (indice >= 0 )
    {
		emp_addEmployees(array, limite, indice, id);
		emp_printArray(array, limite);
	}
}

