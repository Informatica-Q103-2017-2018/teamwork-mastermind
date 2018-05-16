#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 3
typedef struct{
	char color[10];
}codigo;
void genera(char *p);
int main()
{
	int i;
	codigo ordenador[N] ;
	char *p;
	for(i= 0; i<N ; i++)
	{
		p = ordenador[i].color;
		genera(p);
		printf("%s\t", p);
	}

}
void genera(char *p)
{
	
	int   aux;
	srand(time(NULL));
	aux=40 + (rand()%6);
	printf("%i", aux);
	switch(aux){
		case 40:
			strcpy( p ,"negro");
			break;
		case 41:
			strcpy( p ,"blanco");
			break;
		case 42:
			strcpy( p ,"rojo");
			break;
		case 43:
			strcpy( p ,"azul");
			break;
		case 44:
			strcpy( p ,"amarillo");
			break;
		case 45:
			strcpy( p ,"verde");
			break;

	}	

}
