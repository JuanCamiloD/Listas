#include <stdlib.h>
#include <stdio.h>


struct nodo{
	int dato;
	nodo* seguiente;
};


void insertarLista(nodo *&,int);
void mostrarLista(nodo *);
void eliminarNodo(nodo *&,int);
void buscarLista(nodo *,int);

int main(){
	system("color f4");
	nodo *lista=NULL;
	int dato,dato3;
	 int opcion;
do{
        system("cls");
      
        printf("\n\tMenu Clientes                         \n");
        printf("\n\t1. INGRESAR UN DATO                   \n");
        printf("\n\t2. MOTRAR DATOS                       \n");
        printf("\n\t3. ELIMINAR DATO                      \n");
        printf("\n\t4. BUSCAR DATO                        \n");
        printf("\n\t0. Menu Principal                     \n");
        printf("\n\tIngrese una opcion:                   \n");
       scanf("%d",&opcion);
        system("cls");
        switch(opcion){
            case 1: system("cls");
					printf("digite un dato \n");
					scanf("%d",&dato);
					insertarLista(lista,dato);
           			 break;
            case 2: system("cls");
					mostrarLista(lista);
           			 break;
            case 3:	system("cls");
					scanf("%d",&dato3);
	 				eliminarNodo(lista,dato3);
            break;
            case 4:	system("cls");
            		printf("ingrese un numero a buscar: \n");
					scanf("%d",&dato);
					buscarLista(lista,dato);
            		break;
            case 0:
            	break;
            default: printf("Opcion invalidad\n");
        }
    }while(opcion != 0);
	
	return 0;
}


void insertarLista(nodo *&lista,int n){
	nodo *nuevo_nodo = new nodo();
	nuevo_nodo->dato = n;
	nodo * aux1 = lista;
	nodo *aux2;
	while((aux1 != NULL)&&(aux1->dato<n)){
		aux2=aux1;
		aux1 = aux1->seguiente;
	}
	if(lista==aux1){
		lista = nuevo_nodo;
	}else{
		aux2->seguiente = nuevo_nodo;
	}
	nuevo_nodo->seguiente = aux1;
	printf("dato %d insertado con exito\n",n);
	printf("\n");
	system("pause");
	
}

void mostrarLista(nodo *lista){
	nodo *actual = new nodo();
	actual = lista;
	while(actual != NULL){
		printf("%d\n",actual->dato);
		actual = actual->seguiente;
	}
	system("pause");
}

void eliminarNodo(nodo *&lista, int n){
	if(lista != NULL){
		nodo *aux_borrar;
		nodo *anterior = NULL;
		aux_borrar = lista;
		
		while ((aux_borrar != NULL )&&(aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->seguiente;	
		}
		if(aux_borrar == NULL){
			printf("El elemento no existe\n");
		}else if(anterior == NULL){
			lista = lista->seguiente;
			printf("elemento %d eliminado \n",n);
			delete aux_borrar;
		}else{
			anterior->seguiente = aux_borrar->seguiente;
			printf("elemento %d eliminado \n",n);
			delete aux_borrar;
		}
	}
	system("pause");
}

void buscarLista(nodo *lista,int n){
	bool band = false;
	nodo *futuro = new nodo();
	futuro = lista;
	
	while((futuro != NULL) && (futuro->dato <= n)){
		if(futuro->dato == n){
			band = true;
		}
		futuro = futuro->seguiente;
	}
	
	if(band == true){
		printf("El elemento %d se encontro \n",n);
	}else{
		printf("El elemento %d No se encontro \n",n);
	}
	system("pause");
	system("pause");
}


