#include <stdio.h>
#include <windows.h>
void main(int argc, char *args[], char *env[])
{
    printf("命令行参数个数：%d\n", argc);
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", args[i]);
    }
    int i;
    system("color 02");
    system("ping 127.0.0.1");
    system("call run.exe");
    while (env[i] != 0)
    {
        printf("%s\n", env[i]);
        i++;
    }
}