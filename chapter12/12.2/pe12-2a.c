// pe12-2a.c
#include "pe12-2a.h"

void set_mode(int n)
{
    mode = n;
}

void get_info()
{
    printf("Enter distance traveled in kilometers:");
    scanf("%lf", &km);
    printf("Enter fuel consumed in liters:");
    scanf("%lf", &fc);
}

void show_info()
{
    if (mode)
    {
        printf("Fuel consumption is %.1lf miles per gallon.\n", km / fc);
    }
    else
    {
        printf("Fuel consumption is %.2lf liters per 100 km.\n", fc / km);
    }
}