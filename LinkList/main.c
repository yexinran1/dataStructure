#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include"LinkList.h"
#define BUFFER_SIZE 5

typedef struct stuInfo
{
    int age;
    char sex;
}stuInfo;

/* 自定义打印 */
int printStruct(void *arg)
{
    stuInfo *info = (stuInfo *)arg;
    printf("age:%d\t sex:%c\n", info->age, info->sex);
}

int printBaiscData(void *arg)
{
    int data = *(int*)arg;
    printf("data:%d\t", data);
}

int main()
{
    
    LinkList * list = NULL;
    /* 初始化 链表*/
    LinkListInit(&list);
#if 1
    int buffer[BUFFER_SIZE] = {1, 2, 3, 4, 5};
    /* 插入数据 */
    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        LinkListTailInsert(list, (void*)&buffer[idx]);
    }
    
    printf("测试插入\n");
    /* 获取链表的长度 */
    int size = 0;
    LinkListGetLength(list, &size);
    printf("size:%d\n", size);

    LinkListForeach(list, printBaiscData);
    printf("\n");
{
    printf("测试指定位置插入\n");
    int val = 9;
    LinkListAppointPosInsert(list, 2, &val);
    int size = 0;
    LinkListGetLength(list, &size);
    printf("size:%d\n", size);
    LinkListForeach(list, printBaiscData);
    printf("\n");
}

{
    printf("测试指定位置删除\n");
    LinkListDelAppointPos(list, 3);
    int size = 0;
    LinkListGetLength(list, &size);
    printf("size:%d\n", size);
    LinkListForeach(list, printBaiscData);
    printf("\n");
}

{
    printf("删除指定数据\n");
    int val = 2;
    //LinkListDelAppointData(list, &val, );
    int size = 0;
    LinkListGetLength(list, &size);
    printf("size:%d\n", size);
    LinkListForeach(list, printBaiscData);
    printf("\n");
}
#else

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

    stuInfo buffer[BUFFER_SIZE] = {stu1, stu2, stu3};

    for(int idx = 0; idx < BUFFER_SIZE; idx++)
    {
        LinkListHeadInsert(list, (void*)&buffer[idx]);
    }
    int size = 0;
    LinkListGetLength(list, &size);
    printf("size:%d\n", size);

    /* 遍历 */
    LinkListForeach(list, printStruct);
#endif 

    return 0;
}