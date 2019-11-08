#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int data;
	int longitud;
	struct nodo *sig;

}Nodo;
	
Nodo * ListaNodos(Nodo *lista){
	lista = NULL;
	return lista;
}


Nodo * agregarNodo(Nodo *lista, int data){
	
	Nodo *nuevo_elemento, *temp;
	nuevo_elemento = (Nodo *) malloc(sizeof(Nodo));
	nuevo_elemento->data = data;
	nuevo_elemento->sig = NULL;
	if(lista == NULL){
		lista = nuevo_elemento;
	}else{
		temp = lista;
		while(temp->sig !=NULL){
			temp = temp->sig;
	
		}
		temp->sig = nuevo_elemento;
	}
	return lista;

}



int Len(Nodo *lista){
	Nodo *temp  = lista;
	int count = 0;

	while(temp !=NULL){
		temp = temp->sig;
		count++;
	}
	return count;
}

void MoverNodo(Nodo *lista, Nodo *nuevo_elemento){
	
	nuevo_elemento->sig = lista->sig;
	lista->sig = nuevo_elemento;

	
}

void Push(Nodo **head, int data){
	
	Nodo * nuevo_elemento;
	nuevo_elemento = (Nodo *) malloc(sizeof(Nodo) );
	nuevo_elemento->data = data;
	nuevo_elemento->sig = *head;
	*head = nuevo_elemento;
}

int main(){
	
	Nodo *lista = ListaNodos(lista);

	Nodo *menores = ListaNodos(menores);
	Nodo *mayores = ListaNodos(mayores);
	
	Nodo *mover_nodos = ListaNodos(mover_nodos);


	mover_nodos = agregarNodo(mover_nodos, 10);
	mover_nodos = agregarNodo(mover_nodos, 8);
	mover_nodos = agregarNodo(mover_nodos, 5);
	
	int posiciones_mover = 2;

	int len = Len(mover_nodos);

	if(posiciones_mover > len){
		Push(&mover_nodos, 7);
		printf("movieron al frente %d\n", 7);
	}
	
	else{
		Nodo *movido = malloc(sizeof(Nodo) );
		movido->data = 7; //cualesquier valor
		movido->sig = NULL;
		
		int counter = 1;
		while(mover_nodos !=NULL){
			printf("mis nodos %d\n", mover_nodos->data);
			mover_nodos = mover_nodos->sig;
			if(counter == posiciones_mover){
				MoverNodo(mover_nodos, movido);
			}
			counter++;	
		}
	}
	
	int numero = 7;

	int *arreglo = (int *) malloc(sizeof(int)*2),c=0;
	lista = agregarNodo(lista, 5);
	lista = agregarNodo(lista, 10);
	lista = agregarNodo(lista, 4);
	lista = agregarNodo(lista , 8);

	while(lista !=NULL){
		int temp = lista->data;
		if(temp  > numero){
			mayores = agregarNodo(mayores, temp);
		} else{
			menores = agregarNodo(menores, temp);
		}
		arreglo[c] = lista->data;
		lista = lista->sig;
		c++;
	}
	Nodo * lista_reverse = ListaNodos(lista_reverse);
	c--;
	while( c >=0){
		lista_reverse = agregarNodo(lista_reverse,arreglo[c] );
		c--;
	}
	while(lista_reverse != NULL){
		printf("en reversa %d\n", lista_reverse->data);
		lista_reverse = lista_reverse->sig;
	}
	while(mayores != NULL){
		printf("mayores %d\n", mayores->data);
		mayores = mayores->sig;
	}
	while(menores != NULL){
		printf("menores %d\n", menores->data);
		menores = menores->sig;
	}
	free(lista);
	free(mover_nodos);	
}
	    	
	

