#include<stdio.h>
#include "lexer.h"

int main()
{
    FILE *fp;
    fp = fopen("input.c",  "r");
    
    if(fp == NULL)
    {
        printf("Error : Unable to open input file\n");
        return 1;
    }

    lexical_analyzer(fp);
    fclose(fp);
    return 0;
}