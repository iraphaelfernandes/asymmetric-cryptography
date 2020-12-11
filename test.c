/*
 * File:   main.c
 * Author: zentut.com
 * Description: Read text file line by line and output it to
 *              the screen.
 */
 
#include <stdio.h>
 
#define MAXCHAR 1000
int main() {
    FILE *fp;
    char str[MAXCHAR];
    char* filename = "numcripto.txt";
 
    fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Could not open file %s",filename);
        return 1;
    }
    while (fgets(str, MAXCHAR, fp) != NULL)
        printf("%s", str);
    fclose(fp);
    return 0;
}