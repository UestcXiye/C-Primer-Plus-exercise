#ifndef MONTHS_H
#define MONTHS_H

struct month
{
    char name[20];
    char abbrev[4];a
    int days;
    int monumb;
};

extern struct month months[12];

#endif