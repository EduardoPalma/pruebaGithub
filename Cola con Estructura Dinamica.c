#include <stdio.h>
#include <stdlib.h>
#define MAX 7

//Los datos fondo y frente se tienen que crear como variable global, ya que al pasarlo  como parametros vas a crear errores en el programa


typedef struct Cola{
	int digito;
	struct Cola *sgte;
}cola;

int ingresar_datos(cola *aux);
int imprimir_cola(cola *aux);

cola *frente = NULL;
cola *ultimo = NULL;

int main(){
	cola *aux;
	
	ingresar_datos(aux);
	
	imprimir_cola(aux);
	
	return 0;
}

int ingresar_datos(cola *aux){
	int cont = 0;
	
	for(cont = 0; cont < MAX; cont++){
		
		aux = (struct Cola*)malloc(sizeof(struct Cola));
		
		printf("\nAgrege un digito a su cola: ");
		scanf("%i",&aux->digito);
		
		aux -> sgte = NULL;
		
		if(frente == NULL){
			frente = aux;
			ultimo = aux;
		}
		if(frente != NULL){
			ultimo -> sgte = aux;
			ultimo = aux;
		}
	
	}
	
	return 0;
}

int imprimir_cola(cola *aux){
	
	aux = (struct Cola*)malloc(sizeof(struct Cola));
	
	aux = frente;
	
	if(frente != NULL){
		if(frente == ultimo){
			printf("\n%i",aux->digito);
		}
		else{
			while(aux != NULL){
				printf("\n%i",aux->digito);
				aux = aux->sgte;
			}
		}
	}
	else{
		printf("\nLa cola esta vacia");
		return 1;
	}
	
}
