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
	int i;
	printf("Introduce tus colores:\n");
	for(i=0; i<N ;i++)
	{
		scanf("%s",respuesta[i].color);	
	}
	for(i=0; i<N ;i++)
	{
		if(strcmp(respuesta[i].color,ordenador[i].color)==0)
			strcpy(solucion[i].color,"correcto\t");
		else 
			strcpy(solucion[i].color,"incorrecto\t");	
	}
	for(i=0 ; i<N ; i++)
	{
		printf("%s\t", solucion[i]);
	}
}
