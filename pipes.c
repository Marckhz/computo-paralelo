#include <stdio.h>
#define LEER 0
#define ESCRIBIR 1


void main(int argc, char *argv[]){
	
	int estado;
	int valores[]={1,2,3,4,5,8,9,10,442,21};
	int sumapadre=0, sumahijo=0, i, tuberia[2];
	int sumaparcial;
	pipe(tuberia);
	int hijo=fork();
	if(hijo==0){
	for(i=0; i<5; i++)
		sumahijo+=valores[i];
	close(tuberia[LEER]); //cierra la lectura
	write(tuberia[ESCRIBIR], &sumahijo, sizeof(sumahijo));
	}	
	else {
	for(i=5; i<10; i++)
		sumapadre+=valores[i];

	wait(&estado);
	close(tuberia[ESCRIBIR]); //cierra la escritura
	read(tuberia[LEER], &sumaparcial, sizeof(sumaparcial));
	int suma_total = (sumapadre + sumaparcial);
	printf("La suma del padre es :  %d\n", sumapadre);
	printf("La suma del hijo es : %d\n", sumaparcial);
	printf("La suma total  es: %d\n", suma_total);
	}
}
