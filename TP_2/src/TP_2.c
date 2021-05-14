/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "ArrayEmployees.h"
#include "utn.h"
#define EMP_LEN 1000

int main(void) {
	setbuf(stdout, NULL);

	Employee arrayEmpleados [EMP_LEN];
	int opcionMenu;
	int auxIndice = 0;
	int idEmp = 0;

	if (emp_initEmployees(arrayEmpleados, EMP_LEN) == 0)
	{
		printf ("Array inicializado correctamente.");
	}

	emp_altaArrayForzada(arrayEmpleados, EMP_LEN, 0, &idEmp, "David", "Yates", 45000, 2);
	emp_altaArrayForzada(arrayEmpleados, EMP_LEN, 1, &idEmp, "Alfonso", "Cuaron", 40000, 1);
	emp_altaArrayForzada(arrayEmpleados, EMP_LEN, 3, &idEmp, "Franco", "Torrent", 36000, 0);
	emp_altaArrayForzada(arrayEmpleados, EMP_LEN, 5, &idEmp, "Tim", "Burton", 40000, 0);
	emp_altaArrayForzada(arrayEmpleados, EMP_LEN, 2, &idEmp, "Lucia", "Ridman", 70000, 1);
	emp_altaArrayForzada(arrayEmpleados, EMP_LEN, 4, &idEmp, "Charo", "Almirante", 70000, 1);
	emp_altaArrayForzada(arrayEmpleados, EMP_LEN, 6, &idEmp, "Federico", "Fellini", 20000, 2);



	do {
		if (!utn_getNumeroInt(&opcionMenu, "\n\n\n"
											"\n\t*************************************************"
											"\n\t\t	***** MENU *****					\n"
											"\n\t*	1.  ALTAS	\t\t\t*"
											"\n\t*	2.  MODIFICAR	\t\t\t*"
											"\n\t*	3.  BAJAS	\t\t\t*"
											"\n\t*	4.  INFORMAR	\t\t\t*"
											"\n\t*	0.  SALIR	\t\t\t*"
											"\n\t*************************************************\n",
											"\nError opcion invalida", 0, 5, 2))
		{
			switch(opcionMenu)
			{
				case 1:
						emp_cargarEmployee(arrayEmpleados, EMP_LEN, auxIndice, &idEmp);
					break;
				case 2:
						emp_cargarModificarArray(arrayEmpleados, EMP_LEN, auxIndice);
					break;
				case 3:
						emp_removeEmployee(arrayEmpleados, EMP_LEN, idEmp);
					break;
				case 4:
						emp_printSort(arrayEmpleados, EMP_LEN);
						emp_printSalario(arrayEmpleados, EMP_LEN, auxIndice);
					break;
			}
		}
	} while (opcionMenu != 0);
	return EXIT_SUCCESS;
}
