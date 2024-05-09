#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *sig;
}nodo;


void crear(nodo *p);
void mostrar(nodo *p);
nodo* eliminarCabeza(nodo *p, int cont,int num1,int num2);
int eliminarIntermedio(nodo *p, int cont, int num1, int num2);
nodo * insertarCabeza(nodo *p, int num1);
void insertarIntermedio(nodo *p, int cont, int num1);



int main(){
    
    int cont=1;
    int num1;
    int num2;
    nodo *prin;
    prin=(nodo*)malloc(sizeof(nodo));
    
    crear(prin);
    printf("\nLa lista es: \n");
    mostrar(prin);
    
    printf("\nIngrese un número positivo: ");
    scanf("%d",&num1);
    
    printf("\nIngrese otro número positivo mayor al anterior: ");
    scanf("%d",&num2);
    
    prin=eliminarCabeza(prin, cont, num1,num2);
    
    if(num1==1){    
        printf("\nLa lista sin los nodos entre los números ingresados es: \n");
        mostrar(prin);   
    }else if(num1>1){    
        cont=eliminarIntermedio(prin, cont, num1, num2);
        if(num1<=cont){
            printf("\nLa lista sin los nodos entre los números ingresados es: \n");
            mostrar(prin);        
        }
    }
    
    printf("\nIngrese un número mayor a cero, el cual se agregará en la posicón del valor de ese número ingresado y se agregarán sus números descendientes de forma consecuetiva: \n");
    scanf("%d",&num1);
    while(num1<=0){
        printf("\nDebe ingresar un número mayor a cero: \n");
        scanf("%d",&num1);
    }
    
    if(num1==1){ 
        prin=insertarCabeza(prin, num1);
        printf("\nLa lista con la nueva cabeza es: \n");
        mostrar(prin);
        
        insertarIntermedio(prin, cont, num1);
        
        printf("\nLa lista con la nueva cabeza y sus números descendientes es: \n");
        mostrar(prin);
            
    }
    else{
        insertarIntermedio(prin, cont, num1);
        printf("\nLa lista con numero intermedio y sus números descendientes es: \n");
        mostrar(prin);
    }
    
    return 0;
}

void crear(nodo *p){
    printf("Ingrese un número. Termine con 1000: ");
    scanf("%d",&p->num);
    if(p->num==1000){
        p->sig=NULL;
    }else{
        p->sig=(nodo*)malloc(sizeof(nodo));
        crear(p->sig);
    }
    return;
}

void mostrar(nodo *p){
    while(p->sig!=NULL){
        printf("%d ",p->num);
        p=p->sig;
    }
    
}


nodo* eliminarCabeza(nodo *p, int cont,int num1,int num2){
    nodo *aux;
    
    while(p->sig!=NULL){
        if(num1==1&&cont<=num2){
            aux=p->sig;
            free(p);
            p=aux;
            cont++;
        }
        else {
            return p;
        }
    }
    return p;
}


int eliminarIntermedio(nodo *p, int cont, int num1, int num2){
    nodo *aux;
    cont++;
    
    while(p->sig!=NULL&&p->sig->sig!=NULL){
        if(cont>=num1&&cont<=num2){
            aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
            cont++;
            
        }else{
            cont++;
            p=p->sig;
        }
        
    }
    if(num1>cont){
        printf("\nNo se pudieron eliminar los nodos puesto que el primer número ingresado es mayor a la cnatidad de números ingresados en la lista.\n");
    } else{
        
    }
    return cont;
}


nodo * insertarCabeza(nodo *p, int num1){
    nodo* aux;

    if(num1==1&&p->sig!=NULL){
        aux=(nodo*)malloc(sizeof(nodo));
        aux->num=1;
        aux->sig=p;
        p=aux;
    }else{
        return p;   
    }
        
    return p;
    
}

void insertarIntermedio(nodo *p, int cont, int num1){
    nodo *aux;
    cont=1;
    if(p->sig!=NULL){ 
        if(num1==1){
            aux=(nodo*)malloc(sizeof(nodo));    
            aux->num=0;
            aux->sig=p->sig;
            p->sig=aux;
        }else if(num1>1){
                    while(cont<num1&&p->sig!=NULL){ 
                        cont++;
                        p=p->sig;
                    } 
                    while(num1>=0){ 
                        aux=(nodo *)malloc(sizeof(nodo));
                        aux->num=num1;
                        aux->sig=p->sig;
                        p->sig=aux;
                        num1=num1-1;
                        p=p->sig;
                    }
                }else{}
        
                
    }else{}
}
