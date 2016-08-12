//
//  fn.h
//  ScanText
//
//  Created by Yunus Emre Şen on 8.08.2016.
//  Copyright © 2016 Yunus Emre Şen. All rights reserved.
//

#ifndef fn_h
#define fn_h
#include <stdio.h>

struct complex
{
    float real, img;
};

struct complex add(struct complex *c1, struct complex *c2);
struct complex sub(struct complex *c1, struct complex *c2);
struct complex multi(struct complex *c1, struct complex *c2);
struct complex division(struct complex *c1, struct complex *c2);
float length(struct complex *c);
float real(struct complex *c);
float imaginary(struct complex *c);
int compare(struct complex *c1, struct complex *c2);
int fcompare(float x, float y);

#endif /* fn_h */
