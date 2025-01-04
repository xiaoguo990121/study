#include <stdio.h>

void test2_1()
{
    printf("Guo Xiao\n");
    printf("Guo\n");
    printf("Xiao\n");
    printf("Guo ");
    printf("Xiao\n");
}

void test2_2()
{
    printf("Name: Guo Xiao\n");
    printf("Address: WU HAN\n");
}

void test2_3()
{
    printf("age 26 is %d\n", 26 * 365);
}

void jolly()
{
    for (int i = 0; i < 3; ++i)
    {
        printf("For he's a jolly good fellow!\n");
    }
}
void deny()
{
    printf("Which nobody can deny!\n");
}
void test2_4()
{
    jolly();
    deny();
}

void br()
{
    printf("Brazil, Russia");
}
void ic()
{
    printf("India, China");
}
void test2_5()
{
    br();
    printf(", ");
    ic();
    printf("\n");
    ic();
    printf(",\n");
    br();
    printf("\n");
}

void test2_6()
{
    int toes = 10;
    printf("%d, %d, %d\n", toes, toes * 2, toes * toes);
}

void smile()
{
    printf("Smile!");
}
void test2_7()
{
    smile();
    smile();
    smile();
    printf("\n");
    smile();
    smile();
    printf("\n");
    smile();
    printf("\n");
}

void two()
{
    printf("two\n");
}
void one_three()
{
    printf("one\n");
    two();
    printf("three\n");
}
void test2_8()
{
    printf("starting now:\n");
    one_three();
    printf("done\n");
}

int main()
{
    test2_1();
    test2_2();
    test2_3();
    test2_4();
    test2_5();
    test2_6();
    test2_7();
    test2_8();

    return 0;
}