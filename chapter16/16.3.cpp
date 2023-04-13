#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926

struct Rectangular translate(struct Polar p);
void show_polar(const struct Polar p);
void show_rectangular(const struct Rectangular r);

struct Polar // 极坐标
{
    float r;
    float A;
};

struct Rectangular // 直角坐标
{
    float x;
    float y;
};

int main()
{
    struct Polar polar;
    struct Rectangular rec;

    printf("please input the length and angle of the vector:\n");
    scanf("%f %f", &polar.r, &polar.A);
    show_polar(polar);
    rec = translate(polar);
    show_rectangular(rec);

    system("pause");
    return 0;
}

struct Rectangular translate(struct Polar p)
{
    struct Rectangular r;

    r.x = p.r * cos(p.A * PI / 180.0);
    r.y = p.r * sin(p.A * PI / 180.0);

    return r;
}

void show_polar(const struct Polar p)
{
    printf("length: %.2f, angle: %.2f°\n", p.r, p.A);
}

void show_rectangular(const struct Rectangular r)
{
    printf("x: %.2f, y: %.2f\n", r.x, r.y);
}