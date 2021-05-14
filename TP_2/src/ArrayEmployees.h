/*
 * Pantalla.h
 *
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define NOMBRE_LEN 51
#define APELLIDO_LEN 51

#define SECTOR_ADM 0
#define SECTOR_TEC 1
#define SECTOR_MAE 2

typedef struct
{
	char name [NOMBRE_LEN];
	char lastName [APELLIDO_LEN];
	float salary;
	int sector;
	int isEmpty;
	int idEmployee;
}Employee;

void emp_cargarEmployee(Employee* array, int limite, int indice, int* id);
int emp_initEmployees (Employee* array, int limite);
int emp_imprimir (Employee* pElemento);
int emp_inicializarArray (Employee* array, int limite);
int emp_addEmployees(Employee* array, int limite, int indice, int* id);
int emp_getEmptyIndex (Employee* array, int limite);
int emp_imprimirArray (Employee* array, int limite);
int emp_findEmployeeById (Employee* array, int limite, int valorBuscado);
int emp_modificarArray (Employee* array, int limite, int indice);
int emp_cargarModificarArray (Employee* array, int limite, int indice);
int emp_removeEmployee (Employee* array, int limite, int indice);
int emp_darDeBajaArray (Employee* array, int limite, int indice);
int emp_ordenarPorSector (Employee* array, int limite);
int emp_buscarIdIngresado (Employee* array, int limite, int indice);
int emp_sortEmployeesByLastNameSector(Employee* array, int limite);
int emp_printArraySort (Employee* array, int limite);
int emp_printLastName(Employee* pElemento);

void emp_printSort (Employee* array, int limite);
int emp_printSalario(Employee* array, int limite, int indice);



int emp_altaArrayForzada (Employee* array, int limite, int indice, int* id, char* nombre, char* apellido, float salario, int sector);

int emp_cargarAuxIndice (Employee* array, int limite, int indice, int* id);

#endif /* ARRAYEMPLOYEES_H_ */
