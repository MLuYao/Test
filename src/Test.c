#include <stdio.h>
#pragma pack(2) // 值只能填1 2 4 8 16  这里最好是看结构里边最小的成员 这里是char 所以最好是填1    //但是当#pragma pack指定的值等于或者超过所有数据成员长度的时候，这个指定值的大小将不产生任何效果
typedef struct _A
{

    double x; // 8
    int y;    // 4
    char p;   // 1

} NODE;

// 8+4+1+1=14按n为2
#pragma pack(4)
typedef struct _A4
{

    double x; // 8
    int y;    // 4
    char p;   // 1

} NODE1;
// 8+4+1+3=16按n为4以上或者使用系统自动对齐

#pragma pack(1) // 设定为8字节对齐
typedef struct test
{
    char m1;   // 1+7
    double m4; // 8
    int m3;    // 4+4

} NODE2;

// 1+1+4+8=14//按n为2
// 1+7+8+4=20 不满足8的倍数  加4等于24满足  总：1+7+8+4+4=24

int main(void)
{
    struct
    {
        int c;
        struct
        {
            int a;
            struct
            {
                int b;
            };
        };
    } ma;
}
