#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int decToBin(int n);
int decodifica(int num, int privKey, int size); //
int returnLastNum(int num);


int main() {
    
    int n;
    n = decodifica(84, 77, 9);
    
    printf("\n%d\n", n);

    return 0;
}

int decodifica(int num, int privKey, int size) {
    
    //Retorna o número de expoentes
    
    int i = size;
    int binPrivKey = decToBin(privKey);
    int temp;
    int expoentes[size];
    int exp = 0; // é um contador para os expoentes da aritimética modular
    int quantExpoentes;
    
    while (i >= 0) {
        
        temp = returnLastNum(binPrivKey);
        
        if(temp == 1) {
            
            expoentes[-i] = pow(2, exp);
            quantExpoentes++;
        }
        
        binPrivKey = returnLastNum(binPrivKey);
        temp = returnLastNum(binPrivKey);
        i--;
        exp++;
    }
    
    temp = quantExpoentes;
    // int prod;
    
    // while (temp >= 0) {
        
        
    // }
    
    //----------
    return quantExpoentes;
}

int returnLastNum(int num) {
    
    return num % 10;
    
}

int decToBin(int n) {
    
    long long bin = 0;
    int rem, i = 1;
    while (n != 0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }
    return bin;
}