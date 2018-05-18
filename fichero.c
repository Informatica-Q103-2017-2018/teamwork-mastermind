#include <stdio.h>
#include<stdlib.h>
int main ()
{
	FILE *pf;
	int i;
	long int fsize;
	char *texto, c;
	pf = fopen("instruciones.txt", "r");
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
    texto= malloc(sizeof(char) * fsize);
	while(fscanf(pf, "%c", &texto[i]) != EOF)
	{
	   i++;
	}
	printf("%s\n", texto);
	}
	fclose(pf);
	return 0;
}
	
