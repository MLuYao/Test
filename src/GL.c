#include <stdio.h>
typedef enum
{
    ATOM,
    LIST
} ElemTag;
typedef int ElemType;
struct GLNode
{
    ElemTag flag;
    union
    {
        ElemType elem;
        struct
        {
            struct GLNode *hp, *tp;
        } ptr;
    };
} *GList;
void main()
{
    struct GLNode ma0;
    struct GLNode ma1;
    struct GLNode ma2;
    struct GLNode ma3;
    ma0.flag = LIST;
    ma0.ptr.hp = &ma1;
    ma0.ptr.tp = &ma2;
    ma1.flag = ATOM;
    ma1.elem = 10;
    ma2.flag = LIST;
    ma2.ptr.hp = NULL;
    ma2.ptr.tp = NULL;
    union f_data
    {
        float f;
        struct
        {
            unsigned char byte[4];
        };
    } fa;
    fa.f = 2.0F;
    printf("%hhd\t%hhd\t%hhd\t%hhd\t", fa.byte[0], fa.byte[1], fa.byte[2], fa.byte[3]);
    struct
    {
        unsigned char byte1[4];
        struct
        {
            unsigned char byte2[4];
        };
    } h;
    struct stu
        {
            int n;
        };struct stu nnn={1};
        struct stu stu1={.n=45};
    printf("OK!");
}
