#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define N 4

typedef struct{    // estructura que nos permite ordenar los distintos 
	char name[10]; //campos en las puntuaciones.
	int anio;
	char mes [15];
	int dia;
	int age;
	int points;
}puntos;

typedef struct{    // estructura para almacenar los distintos colores 
	char color[10];// dentro del vector de la solucion y de la respuesta.
	int puntos;
}codigo;

void genptos(int *p);  // prototipos de las funciones utilizadas en el codigo
void genera(char *p);  // explicadas mas abajo.
char menu(void);
void datos(int puntuacion, FILE *pg);

int main()
{
	srand(time(NULL));  // conseguimos los numeros aleatorios que nos van a dar 
	FILE *pf,*pg;       // los colores de la solucion a traves de la hora del ordenador (srand(time(NULL))).
	int i,j=0, m=0, intento=0, *q, puntuacion=0;;
	codigo ordenador[N], respuesta[N], solucion[N];
	long int fsize;
	char *texto, *texto1, *p,  opcion ;
	
	do{
		opcion=menu();
		switch(opcion)
		{
			case 'I': // en este caso iniciamos la partida.
			case 'i': 
					for(i= 0; i<N ; i++)
					{
						p = ordenador[i].color;  // puntero p apunta a la estructura ordenador para almacenar el vector de los colores.
						genera(p); // funcion que genera la solucion del juego.
						q = &ordenador[i].puntos; // puntero q apunta a la estructura ordenador para almacenar las puntuaciones.
						genptos(q); // funcion que nos da la puntuacion.
						//printf("%s\t", p);
					}
				do{
				m=0;//reiniciamos el contador m; que cuenta el numero de aciertos del intento correspondiente.
				printf("\nIntroduce tus colores: entre los posibles: Negro, Blanco, Amarillo, Rojo, Azul, Verde \n");
				printf("Intento numero %i\n", intento+1 );
				for(i=0; i<N ;i++)
				{
					scanf("%s",respuesta[i].color);	
				}
				for(i=0; i<N ;i++)
				{
					if(strcmp(respuesta[i].color,ordenador[i].color)==0){  // con el srcpy y el strcmp comprobamos si las respuestas
						strcpy(solucion[i].color,"correcto\t");            //son correctas o incorrectas.
						m++;
					}
					else 
						strcpy(solucion[i].color,"incorrecto\t");	
				}
				for(i=0 ; i<N ; i++)  
				{
					printf("%s\t", solucion[i].color);
				}                 // bucle con printf para recordarnos que colores hemos elegido.
				printf("\n Has introducido \n");
				for(i=0 ; i<N ; i++)
				{ 										//  diferentes if que nos dan las pasos que seguimos
					printf("%s\t", respuesta[i].color); 
				}
				if((m<N) && (intento < 5))
					printf("\n Pruebe otra vez\n");     //mas inentos
				intento++;
				if((m<N) && (intento == 5))
					printf("\nHas perdido...\n");       //se acaba el numero de intentos.
				if(m==N)
					printf("\nEnhorabuena! Has ganado :D\n");// ganas la partida
				}while( (m<N) && (intento <5) );  // do while que sirve para que entremos en el juego al menos 1 vez y que se termine
				break;							  // cuando hayan pasado 5 intentos.
			case 'C':
			case 'c': // caso que nos permite consultar las puntuaciones de otros jugadores
				if( m== N)
				{
					for(i=0; i<N; i++)   // junto con el bucle for y .puntos que apunta a la estructura consguimos sacarla puntuacion
					{
						puntuacion += ordenador[i].puntos;
					}
					puntuacion/=4;
					puntuacion += intento; // la puntacion depende del numero de intentos por eso += intento para que vaya aaumentando
					datos(puntuacion,pg);
				}
				pg = fopen("puntuacion.txt", "r");  // abrimos el fichero
				if (pg == NULL)
				{
				printf("Error al abrir el fichero.\n");	
				return -1;
				}
				else
				{
					printf("Fichero abierto correctamente.\n");	// con el fichero u abierto se pueden poner nuestros datos y las puntuaciones
					fseek(pg, 0, SEEK_END);
	   				fsize = ftell(pf);							
	    			fseek(pg, 0, SEEK_SET);
	    			texto= malloc(sizeof(char) * fsize);      // usamos la asignacion dinamica de memoria y el fscanf para poder escribir dentro
					while(fscanf(pg, "%[^\n]\n", texto) != EOF)  //del fichero.
					{
		   				printf("%s\n", texto);	
					}
				}
				fclose(pg);  // cerramos el fichero.
				break;
			case 'M':   // caso para mirar las instrucciones del juego.
			case 'm':
				pf = fopen("instrucciones.txt", "r"); // solo podnemos "r" ya que no necesitamos escribir  en el fichero solo leerlo.
				if (pf == NULL)
				{
				printf("Error al abrir el fichero.\n");	
				return -1;
				}
				else
				{
					printf("Fichero abierto correctamente.\n");// una vez abierto el fichero utilizamos la asigcion dinamica de memoria
					fseek(pf, 0, SEEK_END);					   // y el fscanf para poder imprimir el texto de las instrucciones en la pantalla. 
	   				fsize = ftell(pf);						   
	    			fseek(pf, 0, SEEK_SET);
	    			texto1= malloc(sizeof(char) * fsize);
					while(fscanf(pf, "%[^\n]\n", texto1) != EOF)
					{
		   				printf("%s\n", texto1);
					}
				}
				fclose(pf); // cerramos el fichero.
				break;
		}
	
	}while( ( opcion != 'S') && ( opcion != 's') ); // do while para que el menu se reopita hasta que se presione la tecla s.
	
}
char menu(void) // funcion menu.
{
	char opcion;// podemos ver las distintas posibilidades que se pueden hacer en el juego.
	printf ("\n Seleccione una de estas opciones:\n");
	printf ("I - Iniciar partida \n");
	printf ("C - Consultar Resultados \n");
	printf ("M - Mostrar instrucciones \n");
	printf ("S - Abandonar Aplicacion \n");
	printf ("Opcion: ");
	scanf (" %c",&opcion);
	return opcion;
}
void genera(char *p)  // funcion que nos genera la solucion de la partida.
{
	int   aux;
	aux=40 + (rand()%6);// con (rand()%6) nos consigue 4 numeros aleatorios del 40 al 45.
	//printf("%i", aux);
	switch(aux){    // con *p apuntando a la estructura codigo en el main
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
void genptos(int *q) // funcion que nos genera la puntuacion de segun el numero de intentos.
{
	int   aux;
	aux=40 + (rand()%6); // con *q apunta en el main a la estructura codigo.
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
void datos(int puntuacion, FILE *pg)  // funcion que nos permite apuntar nuestros datos en el fichero.
{
	puntos player;
	printf("Introduce tu nombre y tu edad \n");
	scanf("%s %d", player.name, &player.age);
	printf("\n %s: \n", player.name);
	printf("Introduce la fecha en la que juegas ejem: 10 enero 2018 \n ");
	scanf("%d %s %d", &player.dia, player.mes, &player.anio);
	pg=fopen("puntuacion.txt","a");  // abrimos el fichero para poder ampliar la informacion dentro de el.
	player.points=puntuacion;
	fprintf(pg, "%s %d %d %d %s %d \n", player.name, player.age, player.points, player.dia, player.mes, player.anio);
	fclose(pg);
}
