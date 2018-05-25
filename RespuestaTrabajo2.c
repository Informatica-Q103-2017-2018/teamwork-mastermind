#include <stdio.h>
#include <string.h>
#define N 5
typedef struct
{
	char color[10];
}codigo;
int main()
{
	codigo respuesta[5];
	codigo solucion[5];
	codigo ordenador[5]={"negro","blanco","blanco","blanco","blanco"};
	int i,w,z;
	printf("Introduce tus colores:\n");
	do
	{
		z=0;
		for(i=0; i<N ;i++)
		{
			scanf("%s",respuesta[i].color);	
		}
		for(i=0; i<N ;i++)
		{
			if(strcmp(respuesta[i].color,ordenador[i].color)==0)
			{
				strcpy(solucion[i].color,"correcto\t");
				z++;
				printf("%i\t",z);
			}
			else 
				strcpy(solucion[i].color,"incorrecto\t");	
		}
		for(i=0 ; i<N ; i++)
		{
			printf("%s\t", solucion[i]);
		}
		w++;
	}while(z!=5 || w<5);
}
