#include <stdio.h>
#include <stdlib.h>


int main () {

    int str1[1], str2[1];
    FILE * fp;

    fp = fopen ("program.txt", "w+");

    rewind(fp);
    fscanf(fp, "%d %d", str1, str2);

    printf("Read String1 %d\n", str1[0] );
    printf("Read String2 %d\n", str2[0] );


    fclose(fp);

    return(0);
}