#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 4

typedef struct{   
	char name[10];
	int anio;
	char mes [15];
	int dia;
	int age;
	int points;
}puntos;

typedef struct{
	char color[10];
	int puntos;
}codigo;

void genptos(int *p);
void genera(char *p);
char menu(void);
void datos(int puntuacion, FILE *pg);

int main()
{
	srand(time(NULL));
	FILE *pf,*pg;
	int i,j=0, m=0, intento=0, *q, puntuacion=0;;
	codigo ordenador[N], respuesta[N], solucion[N];
	long int fsize;
	char *texto, *texto1, *p,  opcion , dificultad;
	
	do{
		opcion=menu();
		switch(opcion)
		{
			case 'I':
			case 'i':
					for(i= 0; i<N ; i++)
					{
						p = ordenador[i].color;
						genera(p);
						q = &ordenador[i].puntos;
						genptos(q);
						//printf("%s\t", p);
					}
				do{
				m=0;
				printf("\nIntroduce tus colores: entre los posibles: Negro, Blanco, Amarillo, Rojo, Azul, Verde \n");
				printf("Intento numero %i\n", intento+1 );
				for(i=0; i<N ;i++)
				{
					scanf("%s",respuesta[i].color);	
				}
				for(i=0; i<N ;i++)
				{
					if(strcmp(respuesta[i].color,ordenador[i].color)==0){
						strcpy(solucion[i].color,"correcto\t");
						m++;
					}
					else 
						strcpy(solucion[i].color,"incorrecto\t");	
				}
				for(i=0 ; i<N ; i++)
				{
					printf("%s\t", solucion[i].color);
				}
				printf("\n Has introducido \n");
				for(i=0 ; i<N ; i++)
				{
					printf("%s\t", respuesta[i].color);
				}
				if(m<N)
					printf("\n Pruebe otra vez\n");
				intento++;
				}while( (m<N) && (intento <5) );
				break;
			case 'C':
			case 'c':
				if( m== N)
				{
					for(i=0; i<N; i++)
					{
						puntuacion += ordenador[i].puntos;
					}
					puntuacion/=4;
					puntuacion += intento;
					datos(puntuacion,pg);
				}
				pg = fopen("puntuacion.txt", "r");
				if (pg == NULL)
				{
				printf("Error al abrir el fichero.\n");	
				return -1;
				}
				else
				{
					printf("Fichero abierto correctamente.\n");
					fseek(pg, 0, SEEK_END);
	   				fsize = ftell(pf);
	    			fseek(pg, 0, SEEK_SET);
	    			texto= malloc(sizeof(char) * fsize);
					while(fscanf(pg, "%c", &texto[j]) != EOF)
					{
		   				j++;
					}
					printf("%s\n", texto);
				}
				fclose(pg);
				break;
			case 'M':
			case 'm':
				pf = fopen("instrucciones.txt", "r");
				if (pf == NULL)
				{
				printf("Error al abrir el fichero.\n");	
				return -1;
				}
				else
				{
					printf("Fichero abierto correctamente.\n");
					fseek(pf, 0, SEEK_END);
	   				fsize = ftell(pf);
	    			fseek(pf, 0, SEEK_SET);
	    			texto1= malloc(sizeof(char) * fsize);
					while(fscanf(pf, "%[^\n]\n", texto1) != EOF)
					{
		   				i++;
					}
					printf("%s\n", texto1);
				}
				fclose(pf);
				break;
		}
	
	}while( ( opcion != 'S') && ( opcion != 's') );
	
}
char menu(void)
{
	char opcion;
	printf ("\n Seleccione una de estas opciones:\n");
	printf ("I - Iniciar partida \n");
	printf ("C - Consultar Resultados \n");
	printf ("M - Mostrar instrucciones \n");
	printf ("S - Abandonar Aplicacion \n");
	printf ("Opcion: ");
	scanf (" %c",&opcion);
	return opcion;
}
void genera(char *p)
{
	int   aux;
	aux=40 + (rand()%6);
	//printf("%i", aux);
	switch(aux){
		case 40:
			strcpy( p,"negro");
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
void genptos(int *q)
{
	int   aux;
	aux=40 + (rand()%6);
	//printf("%i", aux);
	switch(aux){
		case 40:
			*q=1;
			break;
		case 41:
			*q=2;
			break;
		case 42:
			*q=3;
			break;
		case 43:
			*q=4;
			break;
		case 44:
			*q=5;
			break;
		case 45:
			*q=6;
			break;
	}	
}
void datos(int puntuacion, FILE *pg)
{
	puntos player;
	printf("Introduce tu nombre y tu edad \n");
	scanf("%s %d", player.name, &player.age);
	printf("\n %s: \n", player.name);
	printf("Introduce la fecha en la que juegas ejem: 10 enero 2018 \n ");
	scanf("%d %s %d", &player.dia, player.mes, &player.anio);
	pg=fopen("puntuacion.txt","a");
	player.points=puntuacion;
	fprintf(pg, "%s %d %d %d %s %d \n", player.name, player.age, player.points, player.dia, player.mes, player.anio);
	fclose(pg);
}
