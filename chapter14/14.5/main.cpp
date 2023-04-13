#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

void set_students(struct student s[], int n);
void cal_averages(struct student s[], int n);
void show_students(const struct student s[], int n);
void show_averages(const struct student s[], int n);

int main()
{
    set_students(s, CSIZE);
    cal_averages(s, CSIZE);
    show_students(s, CSIZE);
    show_averages(s, CSIZE);

    system("pause");
    return 0;
}

void set_students(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Please enter three scores for %s %s:\n", s[i].name.fname, s[i].name.lname);
        for (int j = 0; j < SCORES; j++)
        {
            while (scanf("%f", &s[i].grade[j]) != 1)
            {
                while (getchar() != '\n')
                    continue;
                printf("Please enter a number: ");
            }
        }
    }
}

void cal_averages(struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        float sum = 0.0;
        for (int j = 0; j < SCORES; j++)
        {
            sum += s[i].grade[j];
        }
        s[i].average = sum / SCORES;
    }
}

void show_students(const struct student s[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%s %s's three scores: ", s[i].name.fname, s[i].name.lname);
        for (int j = 0; j < SCORES; j++)
        {
            printf("%f ", s[i].grade[j]);
        }
        printf("\nAverage grade: %f\n", s[i].average);
    }
}

void show_averages(const struct student s[], int n)
{
    float total = 0.0;

    for (int i = 0; i < n; i++)
    {
        total += s[i].average;
    }
    printf("\nClass average grade: %f\n", total / n);
}
