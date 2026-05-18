#include "TinyTimber.h"
#define BSize 8

typedef struct {

    Object super;
    int count;
    int I;
    int J;
    int A[BSize];
} Circular_Buffer;


int Put(Circular_Buffer *, int); //Inser New elemnt.
int Get(Circular_Buffer *, int); //Remove Old element.

// Define an instance of the buffer.

Circular_Buffer buf = {initObject(),0,0,0,{0}}; // Empty buffer 


int Put(Circular_Buffer * self, int data){

    if(self->count < BSize){
        self->A[self->J] = data;
        self->J = (self->J + 1) %BSize;
        self->count = self->count +1;
        return 0;
    }
    else {return -1;}
}

int Get(Circular_Buffer *self, int unused){
    if(self->count >0){
        int data = self->A[self->I];
        self->I = (self->I +1) % BSize;
        self->count = self->count -1;
        return data;
    }
    else {return -1;}
}