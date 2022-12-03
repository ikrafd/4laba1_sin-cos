#include <stdio.h>
#include <math.h>
int n, num;
float x1, x2, dx, e, r_x1, x, sin_x, cos_x, delta;
char er, symbol;
void check_number();
void sinus_x2();
void cosine_x2();
void cosine_x1();
void sinus_x1();
int main() {
    do
    {
        er = 0;
        printf("Enter number:\n"
               "1 - only sinus\n"
               "2 - only cosine\n"
               "3 - sinus and cosine \n");
        scanf("%i%c", &num, &symbol);
        check_number();
        if (num<1||num>3){
            er = 1;
            fflush(stdin);
            printf("Enter correct number\n");
        }
    } while (er != 0);
    symbol = 0;

    do
    {
        er = 0;
        printf("Enter x1:\n");
        scanf("%f%c", &x1, &symbol);
        check_number();
    } while (er != 0);
    symbol = 0;

    do
    {
        er = 0;
        printf("Enter x2:\n");
        scanf("%f%c", &x2, &symbol);
        check_number();
    } while (er != 0);
    symbol = 0;

    do
    {
        er = 0;
        printf("Enter step:\n");
        scanf("%f%c", &dx, &symbol);
        check_number();
        if(dx==0) {
            er = 1;
            while ((getchar()) != '\n');
            printf("Step can not be less than zero\n");
        } else if(((x1<x2)&(dx<0))||((x1>x2)&(dx>0))) {
            er = 1;
            while ((getchar()) != '\n');
            printf("Enter correct step\n");
        }
    } while (er != 0);
    symbol = 0;

    do
    {
        er = 0;
        printf("Enter epsilon:\n");
        scanf("%f%c", &e, &symbol);
        check_number();
        if((e<0)||(e>1)){
            er = 1;
            while ((getchar()) != '\n');
            printf("Enter correct epsilon\n");
        }
    } while (er != 0);

    if (num==1){
        if (dx>0) {
            sinus_x2();
        }else {
            sinus_x1();
        }
    } else if (num==2){
        if (dx>0) {
            cosine_x2();
        }else {
            cosine_x1();
        }
    } else {
        if (dx>0) {
            sinus_x2();
            cosine_x2();
        }else {
            sinus_x1();
            cosine_x1();
        }
    }

    return 0;
}

void check_number() {
    if (symbol != '\n') {
        er = 1;
        while ((getchar()) != '\n');
        printf("Enter number without symbol\n");
    }
}

void sinus_x2(){
    printf("\nX\t\tTaylor sin\t\tSin(x)\t\t\tTaylor-sin(x)\n");
    x=x1;
    while (x<=x2){
        r_x1=(x*M_PI)/180;
        delta=sin_x=r_x1;
        n=1;
        while (fabsf(delta)>=e) {
            delta *= (-r_x1*r_x1) / ((n + 1) * (n + 2));
            sin_x += delta;
            n += 2;
        }
        printf("%.2f\t\t%f%24f%24f\n", x, sin_x, sinf(r_x1), fabsf(sin_x-sinf(r_x1)));
        x+=dx;
    }
}

void cosine_x2() {
    printf("\nX\t\tTaylor cos\t\tCos(x)\t\t\tTaylor-cos(x)\n");
    x = x1;
    while(x<=x2){
        r_x1 = (x * M_PI) / 180;
        delta = cos_x = 1;
        n = 1;
        while (fabsf(delta)>= e) {
            delta *= (-r_x1 * r_x1) / (2 * n * (2 * n - 1));
            cos_x += delta;
            n += 1;
        }
        x += dx;
        printf("%.2f\t\t%f%24f%24f\n", (x-dx), cos_x, cosf(r_x1), fabsf(cos_x - cosf(r_x1)));
    }
}

void cosine_x1() {
    printf("\nX\t\tTaylor cos\t\tCos(x)\t\t\tTaylor-cos(x)\n");
    x = x1;
    while (x>=x2) {
    r_x1 = (x * M_PI) / 180;
    delta = cos_x = 1;
    n = 1;
    while (fabsf(delta) >= e) {
        delta *= (-r_x1 * r_x1) / (2 * n * (2 * n - 1));
        cos_x += delta;
        n += 1;
    }
    printf("%.2f\t\t%f%24f%24f\n", x, cos_x, cosf(r_x1), fabsf(cos_x-cosf(r_x1)));
    x+=dx;
    }
}

void sinus_x1(){
    printf("\nX\t\tTaylor sin\t\tSin(x)\t\t\tTaylor-sin(x)\n");
    x=x1;
    while (x>=x2){
        r_x1=(x*M_PI)/180;
        delta=sin_x=r_x1;
        n=1;
        while (fabsf(delta)>=e) {
            delta *= (-r_x1*r_x1) / ((n + 1) * (n + 2));
            sin_x += delta;
            n += 2;
        }
        printf("%.2f\t\t%f%24f%24f\n", x, sin_x, sinf(r_x1), fabsf(sin_x-sinf(r_x1)));
        x+=dx;
    }
}