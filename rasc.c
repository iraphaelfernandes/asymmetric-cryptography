#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void converte(unsigned long int vet[], char s[], int n1, int n2);
void printInt(unsigned long int s[], int size);

int main() {
    
    char s[] = "Celacanto";
    unsigned long int vector[60];

    converte(vector, s, 5, 221);
    printInt(vector, 9);

    return 0;
}


void converte(unsigned long int vet[], char s[], int n1, int n2) {

    int i;
    int pot, div;
    unsigned long int temp;

    if(n1 < n2) {

        pot = n1;
        div = n2;
    } else {
        
        pot = n2;
        div = n1;
    }

    for( i  = 0; s[i] != '\0'; i++){

        vet[i] = s[i];
    }

    for(int j = 0; j != i; j++) {

        temp = pow(vet[j], pot);
        vet[j] = temp % n2;
    }
}


void printInt(unsigned long int s[], int size) {
  
      for( int i = 0; i < size; i++ ) {
        
        printf("%d ", s[i] ); 
    }
    printf("\n"); 
}