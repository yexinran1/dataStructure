#include<stdlib.h>
#include<stdio.h>
#include"dynamicArrayStack.h"

#define BUFFER_SIZE 5
int main()
{
    dynamicArrayStACK stack;

    /* 怎么解决套壳问题 */
    dynamicArrayStackInit(&stack);
    int buffer[BUFFER_SIZE] = {5, 32, 21, 56, 87};
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        dynamicArrayStackPush(&stack, &idx);
    }
    int size = 0;
    dynamicArrayStackGetSize(&stack, &size);
    printf("size:%d\n", size);

    int *val = NULL;
    while(!dynamicArrayStackIsEmpty(&stack))
    {
        dynamicArrayStackTop(&stack, (void**)&val);
        printf("val:%d\n", *val);
        dynamicArrayStackPop(&stack);
    }
    
    return 0;
}