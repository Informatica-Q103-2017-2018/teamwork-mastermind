#include <stdio.h>
char menu(void);
int 
int main()
{
	char opcion, dific;
	opcion=menu();
	switch(opcion)
	{
		case 'I':
		case 'i':
			printf("Elija la dificultad:\n F-facil\n N-normal\n D-dificil\n");
			scanf("%c",&dific);
			switch(dific)
			{
				case 'F':
				case 'f':
					break;
					
					
				case 'N':
				case 'n':
					break;
				
				
				case 'D':
				case 'd':
					break;
			}
			break;
			
		case 'C':
		case 'c':
			
		case 'A':
		case 'a':
			
			
	}
}
char menu(void)
{
	char opcion;
	printf ("Seleccione una de estas opciones:\n");
	printf ("I - Iniciar partida \n");
	printf ("C - Consultar Resultados \n");
	printf ("A - Ajustes\n");
	printf ("S - Abandonar Aplicacion\n");
	printf ("Opcion: ");
	scanf ("%c",&opcion);
	return opcion;
}
