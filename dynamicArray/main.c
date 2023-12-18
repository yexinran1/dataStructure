#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"dynamicArray.h"
#define BUFFER_SIZE 20
#define DEFAULT_NUM 5

typedef struct stuInfo
{
    int age;
    char sex;
}stuInfo;

int main()
{
    /* 静态数组 
        1、不够灵活
        2、可能会有浪费的现象
    */
    dynamicArray array;
    /* 初始化 */
    dynamicArrayInit(&array, BUFFER_SIZE);
#if 0
    /* 插入数据 */
    dynamicArrayInsertData(&array, 3);
    for(int idx = 1; idx <= DEFAULT_NUM; idx++)
    {
        dynamicArrayInsertData(&array, 21);
    }
    

    // /* 删除指定*/
    // dynamicArrayDeleteData(&array);

    /* 获取动态数组的大小 */
    int size = 0;
    dynamicArrayGetSize(&array, &size);
    printf("size:%d\n", size);
    
    int val = 0;
    for(int idx = 0; idx < size; idx++)
    {
        dynamicArrayGetAppointPosVal(&array, idx, &val);
        printf("val:%d\t", val);
    }
    printf("\n");
#endif
    stuInfo stu1, stu2, stu3;
    memset(&stu1, 0, sizeof(stu1));
    memset(&stu2, 0, sizeof(stu2));
    memset(&stu3, 0, sizeof(stu3));


    stu1.age = 10;
    stu1.sex = 'm';

    stu2.age = 20;
    stu2.sex = 'f';

    stu3.age = 30;
    stu3.sex = 'm';

    // dynamicArrayInsertData(&array, stu1);
    // dynamicArrayInsertData(&array, stu2);
    // dynamicArrayInsertData(&array, stu3);
    return 0;
}