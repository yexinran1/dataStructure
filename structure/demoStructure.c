#include <stdio.h>
#include<string.h>
#define BUFFER_SIZE 16
#define DEFAULT_SIZE 2
/* 结构体 */
/* 1、什么是结构体：将不同类型的属性封装成一个类型 */
/* 2、结构体怎么定义 */
typedef struct stuInfo
{
    int age;
    int height;
    int weight;
    char sex;
    char name[BUFFER_SIZE];
}stuInfo;

/* 取别名 typedef */

/* 结构体会默认进行字节对齐： 读取速度快（但是浪费空间） */
/* 什么叫变长结构体 */
int main()
{

#if 1
    /* 3、怎么使用结构体 */
    stuInfo stu;
    memset(&stu, 0, sizeof(stu));

    /* 4、结构体的大小 */
    int len = sizeof(stu);
    printf("len:%d\n", len);
#if 0
    stu.age = 10;
    stu.height = 170;
    stu.sex = 'm';
    stu.weight = 50;
    strncpy(stu.name, "zhangsan", sizeof(stu.name) - 1);
    
    printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%c\t,stu.weight:%d\t,stu.name%s\n", stu.age, stu.height, stu.sex, stu.weight, stu.name);
#endif

    /* 5、结构体数组 */
    /* 数组 ：
        1、一块连续的内存地址
        2、存放的是同一种类型
    */
    stuInfo buffer[DEFAULT_SIZE];
    buffer[0].age = 10;
    buffer[0].height = 50;
    buffer[0].sex = 'm';
    buffer[0].height = 180;
    strncpy(buffer[0].name, "zhangsan", sizeof(buffer[0].name) - 1);

    buffer[1].age = 20;
    buffer[1].height = 50;
    buffer[1].sex = 'f';
    buffer[1].height = 160;
    strncpy(buffer[1].name, "wangwu", sizeof(buffer[1].name) - 1);

    printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%c\t,stu.weight:%d\t,stu.name%s\n", 
        buffer[0].age, buffer[0].height, buffer[0].sex, buffer[0].weight, buffer[0].name);

    printf("stu.age:%d\t,stu.height:%d\t,stu.sex:%c\t,stu.weight:%d\t,stu.name%s\n", 
        buffer[1].age, buffer[1].height, buffer[1].sex, buffer[1].weight, buffer[1].name);
#endif
    return 0;
}