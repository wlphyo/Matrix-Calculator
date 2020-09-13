//README
//Wai Lwi Phyo
//CRUZID: wlphyo
//pa2
#include<stdio.h>
#include<stdlib.h>
#include"List.h"

int main(int argc, char* argv[]){
   
   //int Y[]={1,2,3,5,12};
   List A = newList();
   List B = newList();
   List C = newList();
     //~ append(A, &Y[0]);
     //~ printf("hell1\n");
        //~ append(A, &Y[1]);
             //~ printf("hell2\n");

        //~ moveFront(A);
     //~ printf("hell3\n");

        //~ delete(A);
     //~ printf("hell4\n");

        //~ append(A, &Y[2]);
     //~ printf("hell5\n");

        //~ append(A, &Y[3]);
     //~ printf("hell6\n");

        //~ moveFront(A);
     //~ printf("hell7\n");

        //~ insertAfter(A, &Y[4]);
     //~ printf("hell8\n");

        //~ delete(A);
     //~ printf("hell9 %d \n",length(A));

        //~ if (length(A) != 3) return 1;
     //~ printf("hell 10\n");

        //~ deleteFront(A);
             //~ printf("hell %d \n",length(A));

   //~ if (length(A) != 3) return 1;
        //~ printf("hello12\n");

   int X[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
   int i, u=-1, v=-2, equal=0;

   // initialize Lists A and B
   for(i=1; i<=20; i++){
      append(A, &X[i]);
      prepend(B, &X[i]);
   }

   // print both lists of integers in forward direction
   for(moveFront(A); index(A)>=0; moveNext(A)){
      printf("%d ", *(int*)get(A));
   }
   printf("\n");
   for(moveFront(B); index(B)>=0; moveNext(B)){
      printf("%d ", *(int*)get(B));
   }
   printf("\n");

   // print both lists of integers in backward direction
   for(moveBack(A); index(A)>=0; movePrev(A)){
      printf("%d ", *(int*)get(A));
   }
   printf("\n");
   for(moveBack(B); index(B)>=0; movePrev(B)){
      printf("%d ", *(int*)get(B));
   }
   printf("\n");

   // make a shallow copy of A
   moveFront(A);
   while( index(A)>=0 ){
      append(C, get(A));
      moveNext(A);
   }
   // print the copy in forward direction
   for(moveFront(C); index(C)>=0; moveNext(C)){
      printf("%d ", *(int*)get(C));
   }
   printf("\n");

   // check shallow equality of A and C by comparing pointers
   equal = (length(A)==length(C));
   moveFront(A);
   moveFront(C);
   while( index(A)>=0 && equal){
      equal = ( get(A)==get(C) );
      moveNext(A);
      moveNext(C);
   }
   printf("A equals C is %s\n", (equal?"true":"false") );

   moveFront(A);
   for(i=0; i<5; i++) moveNext(A); // at index 5
   insertBefore(A, &u);            // now at index 6
   for(i=0; i<9; i++) moveNext(A); // at index 15
   insertAfter(A, &v);             // doesn't change index
   for(i=0; i<5; i++) movePrev(A); // at index 10
   delete(A);                      // index is now undefined

   // print A in forward and backward direction
   for(moveFront(A); index(A)>=0; moveNext(A)){
      printf("%d ", *(int*)get(A));
   }
   printf("\n");
   for(moveBack(A); index(A)>=0; movePrev(A)){
      printf("%d ", *(int*)get(A));
   }
   printf("\n");

   // check length of A, before and after clear()
   printf("%d\n", length(A));
   clear(A);
   printf("%d\n", length(A));

   freeList(&A);
   freeList(&B);
   freeList(&C);

   return(0);
}

