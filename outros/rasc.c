
#include <stdio.h>

int decToBin(int n);

int returnLastNum(int num);
int eliminaLastDigt(int n);


int decodifica(int numCod, int privKey, int prodPrime);

int main() {
    
    int n;
    n = decodifica(84, 77, 221);
    
    printf("\n%d\n", n);
    
    //----------------------
    return 0;
}


int decodifica(int numCod, int privKey, int prodPrime) { 
    
    numCod = numCod % prodPrime; 
    int temp = 1;
    if (numCod == 0) return 0;
    
    while (privKey > 0) {
    
        if (privKey % 2 == 1) 
            temp = (temp*numCod) % prodPrime; 
        privKey = privKey>>1; 

        numCod = (numCod*numCod) % prodPrime;   
    } 
    return temp; 
} 