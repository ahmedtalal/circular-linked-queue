#include "linkedQueue.h"
#include <stddef.h>

node *front ;
node *rear ;

void createNode(){
    front = NULL;
    rear = NULL ;
}

int isEmpty(){
    if((rear == NULL) && (front == NULL)){
        return 0 ;
    }
    return 1 ;
}

void enQueue(int value){
    node *ptr = (node *)malloc(sizeof(node)) ;
    ptr->data = value ;
    if(isEmpty() == 0){
        rear  = front = ptr ;
        rear->next = front ;
    }else {
        rear->next = ptr ;
        rear = ptr ;
        rear->next = front ;
    }
    printf("the item is inserted \n") ;
}

void deQueue() {
    node *temp = front ;
    if(isEmpty() == 0){
        printf("the circular linked queue is empty \n") ;
    }else if(front == rear){
        printf("the poped item is %d \n " , front->data) ;
        front = rear = NULL;
        free(temp);
    }else {
        printf("the poped item is %d \n " , front->data) ;
        front = front->next ;
        rear->next = front ;
        free(temp) ;
    }
}

void display(){
    node *temp ;
    if(isEmpty() == 0){
        printf("the circular linked queue is empty \n") ;
    }else {
        temp = front ;
        while(temp->next != front){
            printf("%d \t" , temp->data) ;
            temp = temp->next ;
        }
        printf("%d \t" , temp->data) ;
    }
}

