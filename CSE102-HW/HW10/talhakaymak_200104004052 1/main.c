#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define stackblocksize 10
 
struct Stack
{
int *array;
int currentsize;
int maxsize;
};
 
// we are creating stacks in here
struct Stack* init(int maxsize){ 
    struct Stack* place = (struct Stack*) malloc(sizeof(stackblocksize));
    place -> maxsize = maxsize;
    place -> currentsize = -1;
    place -> array = (int*) malloc(place -> maxsize * sizeof(int));
    return place;
}
//when place empthy 
int idle(struct Stack* stack)
{
return (stack->currentsize == -1);
}
//when place full
int full(struct Stack* stack)
{
return (stack->currentsize == stack->maxsize - 1);
}
 
void push(struct Stack *stack, int d)
{
    if (full(stack))
        return ;
    stack -> array[++stack -> currentsize] = d;
}
int pop(struct Stack *s)
{
    if (idle(s))
        return -4;
    return s -> array[s -> currentsize--];
}
void algorithmofhanoi(int currentsize, struct Stack *l, struct Stack *m, struct Stack *r){
    int i, moves;
    char s = '1', d = '3', a = '2';
    if (currentsize % 2 == 0){
        char temp = d;
        d = a;
        a = temp;
    }
    moves = pow(2, currentsize) - 1;
    for (i = currentsize; i >= 1; i--)
    push(l, i);
    for (i = 1; i <= moves; i++){
    	//algorithm of hanoi tower
    if (i % 3 == 1){
    int smallest1 = pop(l);
    int smallest2 = pop(r);
    if (smallest1 == -4){
        push(l, smallest2);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest2,d,s);
    }
    else if (smallest2 == -4){
        push(r, smallest1);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest1,s,d);
    }
    else if (smallest1 > smallest2){
        push(l, smallest1);
        push(l, smallest2);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest2,d,s);
    }
    else{
        push(r, smallest2);
        push(r, smallest1);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest1,s,d);   
    }
		}
    else if (i % 3 == 2){
    int smallest1 = pop(l);
    int smallest2 = pop(m);
    if (smallest1 == -4)
    {
        push(l, smallest2);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest2,a,s);
    }
    else if (smallest2 == -4){
        push(m, smallest1);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest1,s,a);
    }
    else if (smallest1 > smallest2){
        push(l, smallest1);
        push(l, smallest2);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest2,a,s);
    }
    else{
        push(m, smallest2);
        push(m, smallest1);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest1,s,a);   
    }
		}
    else if (i % 3 == 0){
    int smallest1 = pop(m);
    int smallest2 = pop(r);
    if (smallest1 == -4){
        push(m, smallest2);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest2,d,a);
    }
    else if (smallest2 == -4){
        push(r, smallest1);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest1,a,d);
   }
    else if (smallest1 > smallest2){
        push(m, smallest1);
        push(m, smallest2);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest2,d,a);
        
    }
    else{
        push(r, smallest2);
        push(r, smallest1);
        printf("Move the disk %d from \'%c\' to \'%c\'\n",smallest1,a,d);   
    }
}
    }
}
 
int main(){
	int currentsize;
	printf("enter tower size: ");
	scanf("%d",&currentsize);
    struct Stack *left, *right, *mid; 
    left = init(currentsize);
    mid = init(currentsize);
    right = init(currentsize);
 
    algorithmofhanoi(currentsize, left, mid, right);
    
    
    return 0;
}
