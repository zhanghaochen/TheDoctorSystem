//
//  MyDoctor.c
//  MyDoctor
//
//  Created by 张昊辰 on 15/12/22.
//  Copyright © 2015年 com.mingxing. All rights reserved.
//

#include "MyDoctor.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

FILE *fopen$UNIX2003( const char *filename, const char *mode )
{
    return fopen(filename, mode);
}

int fputs$UNIX2003(const char *res1, FILE *res2){
    return fputs(res1,res2);
}

int nanosleep$UNIX2003(int val){
    return usleep(val);
}

char* strerror$UNIX2003(int errornum){
    return strerror(errornum);
}

double strtod$UNIX2003(const char *nptr, char **endptr){
    return strtod(nptr, endptr);
}

size_t fwrite$UNIX2003( const void *a, size_t b, size_t c, FILE *d )
{
    return fwrite(a, b, c, d);
}