#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int decToBin(int n);
int returnLastNum(int num);
int eliminaLastDigt( int n);
int decodifica(int numCod, int privKey, int div) ;

int	main(void) {
    
    int n = 0;
    n = decodifica(84, 77, 221);
    
    printf("\n%d\n", n);
    
    return 0;
}

int decodifica(int numCod, int privKey, int div) {

    numCod = numCod % div; 
    
    int temp = 1;

    if (numCod == 0) {
    
        return 0;
    }
    while (privKey > 0) {

        if (privKey % 2 == 1) 
            temp = (temp*numCod) % div; 
        privKey = privKey >> 1; 

        numCod = (numCod*numCod) % div;   
    } 
    return temp; 
} 