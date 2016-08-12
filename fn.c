//
//  fn.c
//  ScanText
//
//  Created by Yunus Emre Şen on 8.08.2016.
//  Copyright © 2016 Yunus Emre Şen. All rights reserved.
//

#include "fn.h"
#include <math.h>
#include <stdio.h>

#define EPSILON (0.05f)

struct complex add(struct complex *c1, struct complex *c2)
{
    struct complex sum;
    sum.real = c1->real + c2->real;
    sum.img = c1->img + c2->img;
    return sum;
}

struct complex sub(struct complex *c1, struct complex *c2)
{
    struct complex sub;
    sub.real = c1->real - c2->real;
    sub.img = c1->img - c2->img;
    return sub;
}

struct complex multi(struct complex *c1, struct complex *c2)
{
    struct complex multi;
    multi.real = c1->real * c2->real - c1->img * c2->img;
    multi.img = c1->real * c2->img + c1->img + c2->real;
    return multi;
}

struct complex division(struct complex *c1, struct complex *c2)
{
    struct complex division;
    division.real = (c1->real * c2->real + c1->img * c2->img) / (c2->real * c2->real + c2->img * c2->img);
    division.img = (c1->img * c2->real - c1->real * c2->img) / (c2->real * c2->real + c2->img * c2->img);
    return division;
}

float length(struct complex *c)
{
    return sqrt(c->real * c->real + c->img * c->img);
}

float real(struct complex *c)
{
    return c->real;
}

float imaginary(struct complex *c)
{
    return c->img;
}

int fcompare(float x, float y)
{
    return (fabs(x - y) <= EPSILON);
}

int compare(struct complex *c1, struct complex *c2)
{
    return fcompare(c1->img, c2->img) && fcompare(c1->real, c2->real);
    //return c1->img == c2->img && c1->real == c2->real;
}