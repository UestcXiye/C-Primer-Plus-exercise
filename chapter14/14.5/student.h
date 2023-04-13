#ifndef STUDENT_H
#define STUDENT_H

#define LEN 15
#define CSIZE 4
#define SCORES 3

struct names
{
    char fname[LEN];
    char lname[LEN];
};

struct student
{
    struct names name;
    float grade[SCORES];
    float average;
};

extern struct student s[CSIZE];

#endif