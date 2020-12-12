//Trabalho
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

//Functions %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void codifica(int vet[], char s[], int n1, int n2); //Converte com (s[i]^p)%div

int lelinha (char s[], int lim);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
int main(void) {
  

  char frase[MAX];
  //int tamFrase;
  printf("\nDigite o texto para ser criptografado e pressione ctrl+d para indicar o final dela. \n");
  
  lelinha (frase, MAX);
  printf("\nA frase a ser criptografada é:\n%s\n", frase);
  int vet[MAX];
  
  int firstPubKey, prodPrime;
  
  firstPubKey = 5;
  prodPrime = 221;
  
  
  codifica(vet, frase, firstPubKey, prodPrime);
  
  printf("\nA mensagem criptografada e transmitida será: \n");
    
  for( int i = 0; frase[i] != '\0'; i++) {
    
    printf("%d  ", vet[i]);
  }
  printf("\n");
  
//----------------------------------------------------  
  return 0;
}
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§

int lelinha (char s[], int lim) {
  
  int c, i;
  
  for(i = 0; i < lim - 1 && (c = getchar()) != EOF; ++i) {
  
    s[i] = c;
  }
  
  // if (c == '\n') {
  //   s[i] = c;
  //   ++i;
  // }
  
  s[i] = '\0';
  return i;
}

void codifica(int vet[], char s[], int n1, int n2) {

    int i;
    int pot, div;
    unsigned long int resultPow;
    int resultDiv;
    // unsigned long int temp[MAX];

    if(n1 < n2) {

        pot = n1;
        div = n2;
    } else {
        
        pot = n2;
        div = n1;
    }
  
  for( i = 0; s[i] != '\0'; i++) {
    
    resultPow = pow(s[i], pot);
    resultDiv = resultPow % div;
    vet[i] = resultDiv;
  }
}