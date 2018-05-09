#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 3
typedef struct{
	char color[10];
}tipo;
int main()
{
	tipo solucion[N];
	int  i, aux;
	srand(time(NULL));
	for(i=0; i<N ; i++)
	{
		aux=40 + (rand()%6);
		switch(aux){
			case 40:
				solucion[i]=(const tipo) {"negro"};
				break;
			case 41:
				solucion[i]=(const tipo) {"blanco"};
				break;
			case 42:
				solucion[i]=(const tipo) {"rojo"};
				break;
			case 43:
				solucion[i]=(const tipo) {"azul"};
				break;
			case 44:
				solucion[i]=(const tipo) {"amarillo"};
				break;
			case 45:
				solucion[i]=(const tipo) {"verde"};
				break;
		}
	}
	for(i=0; i<N ; i++)
	{
		printf("%s\t", solucion[i].color);
	}
}
