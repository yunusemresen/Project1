//
//  main.c
//  ScanText
//
//  Created by Yunus Emre Şen on 4.08.2016.
//  Copyright © 2016 Yunus Emre Şen. All rights reserved.
//

#include "fn.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i, j;
    float temp, x;
    struct complex a, b, c, d;
    const char s[2] = " ";
    char *token = NULL;
    
    printf("argc = %d\n",argc);
    for(i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    FILE* filepointer = fopen (argv[1], "r");
    char output[256];
    FILE* filepointer2 = fopen (argv[2], "r");
    char output2[256];
    while (fgets(output, sizeof(output), filepointer) != NULL)
    {
        token = strtok(output, s);
        
        if (strcmp(token, "add") == 0)
        {
            for (j = 0; j < 2; ++j)
            {
                token = strtok(NULL, s);
                if (j == 0 && token != NULL)
                {
                    sscanf(token, "%f%fj", &a.real, &a.img);
                }
                else if (j == 1 && token != NULL)
                {
                    sscanf(token, "%f%fj", &b.real, &b.img);
                }
            }
            c = add(&a, &b);
            if (fgets(output2, sizeof(output), filepointer2) != NULL)
            {
                sscanf(output2, "%f%fj", &d.real, &d.img);
                
                if (compare(&c, &d))
                {
                    puts("PASS");
                }
                else
                {
                    printf("%f+%fj != %f+%fj\n",c.real,c.img,d.real,d.img);
                    puts("FAIL!");
                    break;
                }
            }
            
            //if ( c.img >= 0 )
            //printf("Sum of two complex numbers = %.2f+%.2fj\n",c.real,c.img);
            //else
            //printf("Sum of two complex numbers = %.2f%.2fj\n",c.real,c.img);
        }
        if (strcmp(token, "sub") == 0)
        {
            for (j = 0; j < 2; ++j)
            {
                token = strtok(NULL, s);
                if (j == 0 && token != NULL)
                {
                    sscanf(token, "%f%fj", &a.real, &a.img);
                }
                else if (j == 1 && token != NULL)
                {
                    sscanf(token, "%f%fj", &b.real, &b.img);
                }
            }
            c = sub(&a, &b);
            if (fgets(output2, sizeof(output), filepointer2) != NULL)
            {
                sscanf(output2, "%f%fj", &d.real, &d.img);
                if (compare(&c, &d))
                {
                    puts("PASS");
                }
                else
                {
                    printf("%.10f%+.10fj != %.10f%+.10fj\n", c.real, c.img, d.real, d.img);
                    puts("FAIL!");
                    break;
                }
            }
            //if ( c.img >= 0 )
            //printf("Substract of two complex numbers = %.2f+%.2fj\n",c.real,c.img);
            //else
            //printf("Substract of two complex numbers = %.2f%.2fj\n",c.real,c.img);
        }
        if (strcmp(token, "multi") == 0)
        {
            for (j = 0; j < 2; ++j)
            {
                token = strtok(NULL, s);
                if (j == 0 && token != NULL)
                {
                    sscanf(token, "%f%fj", &a.real, &a.img);
                }
                else if (j == 1 && token != NULL)
                {
                    sscanf(token, "%f%fj", &b.real, &b.img);
                }
            }
            c = multi(&a, &b);
            if (fgets(output2, sizeof(output2), filepointer2) != NULL)
            {
                sscanf(output2, "%f%fj", &d.real, &d.img);
                
                if (compare(&c, &d))
                {
                    puts("PASS");
                }
                else
                {
                    printf("%f+%fj != %f+%fj\n",c.real,c.img,d.real,d.img);
                    puts("FAIL!");
                    break;
                }
            }
            //if ( c.img >= 0 )
            //printf("Multiplication of two complex numbers = %.2f+%.2fj\n",c.real,c.img);
            //else
            //printf("Multiplication of two complex numbers = %.2f%.2fj\n",c.real,c.img);
        }
        if (strcmp(token, "division") == 0)
        {
            for (j = 0; j < 2; ++j)
            {
                token = strtok(NULL, s);
                if (j == 0 && token != NULL)
                {
                    sscanf(token, "%f%fj", &a.real, &a.img);
                }
                else if (j == 1 && token != NULL)
                {
                    sscanf(token, "%f%fj", &b.real, &b.img);
                }
            }
            c = division(&a, &b);
            if (fgets(output2, sizeof(output2), filepointer2) != NULL)
            {
                sscanf(output2, "%f%fj", &d.real, &d.img);
                
                if (compare(&c, &d))
                {
                    puts("PASS");
                }
                else
                {
                    printf("%f%+f\n",fabs(c.real - d.real), fabs(c.img-d.img));
                    puts("FAIL!");
                    break;
                }
            }
            
            //if ( c.img >= 0 )
            //printf("Division of two complex numbers = %.2f+%.2fj\n",c.real,c.img);
            //else
            //printf("Division of two complex numbers = %.2f%.2fj\n",c.real,c.img);
        }
        if (strcmp(token, "length") == 0)
        {
            token = strtok(NULL, s);
            if (token != NULL)
            {
                sscanf(token, "%f%fj", &a.real, &a.img);
            }
            temp = length(&a);
            if (fgets(output2, sizeof(output2), filepointer2) != NULL)
            {
                sscanf(output2, "%f", &x);
                
                if (fcompare(x, temp))
                {
                    puts("PASS");
                }
                else
                {
                    printf("%f+%fj != %f+%fj\n",c.real,c.img,d.real,d.img);
                    puts("FAIL!");
                    break;
                }
            }
            
            //printf ("Lenght of the complex number = %.2f\n",temp);
        }
        if (strcmp(token, "real") == 0)
        {
            token = strtok(NULL, s);
            if (token != NULL)
            {
                sscanf(token, "%f%fj", &a.real, &a.img);
            }
            temp = real(&a);
            if (fgets(output2, sizeof(output), filepointer2) != NULL)
            {
                sscanf(output2, "%f", &x);
                
                if (fcompare(temp, x))
                {
                    puts("PASS");
                }
                else
                {
                    printf("%f%+fj != %f%+fj\n",c.real,c.img,d.real,d.img);
                    puts("FAIL!");
                    break;
                }
            }
            
            //printf("Real part of the complex number = %.2f\n", temp);
        }
        if (strcmp(token, "img") == 0)
        {
            token = strtok(NULL, s);
            if (token != NULL)
            {
                sscanf(token, "%f%fj", &a.real, &a.img);
            }
            temp = imaginary(&a);
            if (fgets(output2,sizeof(output2),filepointer2) != NULL)
            {
                sscanf(output2, "%f", &x);
                if (fcompare(x, temp))
                {
                    puts("PASS");
                }
                else
                {
                    printf("%f%+fj != %f%+fj\n",c.real,c.img,d.real,d.img);
                    puts("FAIL!");
                    break;
                }
            }
            //printf("Imagine part of the complex number = %.2f\n", temp);
        }
    }
    fclose (filepointer);
    return 0;
}