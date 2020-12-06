//Trabalho
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

//Functions %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int checaPrimo(int a); //verifica se é primo
int recebePrimeNum(); //permite apenas números primos na entrada
int lelinha (char s[], int lim);
void fatora(char s[], int a); //fatora um número a em fatores primos
int primeFactors(int s[], int num); // coloca os fatores primos de num em s e retorna quantos eles são
void printInt(int s[], int size); // imprime cada elemento de um vetor de 0 a size
int escolhePubKey(int n1, int n2); //retorna 1 número, o outro será prime1*prime2
int mdc(int a, int b); //Algoritmo de Euclides iterativo
int mmc(int a, int b); //Algoritmo do MMC
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
int main(void) {
  
  int prime1, prime2;

  printf("\nAgora você precisará escolher dois números primos.\n");

  printf("\nEscolha o primeiro número primo: \n");
  prime1 = recebePrimeNum();
  printf("\nEscolha o segundo número primo: \n");
  prime2 = recebePrimeNum();

  int prodPrime;
  prodPrime = prime1 * prime2;

  int Y;
  Y = (prime1 - 1)*(prime2 - 1);

  // int firstPubKey;
  // firstPubKey = escolhePubKey();

  int numPrimeFactors; //Quantos são os fatores primos
  int fatoresPrimos[100];
  numPrimeFactors = primeFactors(fatoresPrimos, Y);
  
  int firstPubKey;
  
  firstPubKey = escolhePubKey(fatoresPrimos[0], fatoresPrimos[numPrimeFactors - 1]);
  

  printf("\nSuas chaves públicas serão: %d e %d", firstPubKey, prodPrime);


  printf("\nDigite uma fase para ser criptografada: \n");
  
//----------------------------------------------------  
  return 0;
}
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§


int checaPrimo(int a) {
  int c;
  int var = 1;
  
  for (c = 2; c <= (a -1); c+=1) {
    
    if (a % c == 0) {
      
      return 0;
    }
    
  }
  
  if (c == a) {
    
      return 1;
    }
}

int recebePrimeNum() {
  
  int n;
  scanf("%d", &n);
  
  int state = checaPrimo(n);
  
  if( state == 1) {
    
    return n;
  } else {
    
    printf("Digite apenas números primos:\n");
    recebePrimeNum();
  }
}


int escolhePubKey(int n1, int n2) {
    
    int num;
    num = mmc(n1, n2);
    
    return (num -1);
}

int lelinha (char s[], int lim) {
  
  int c, i;
  
  for(i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
  
    s[i] = c;
  }
  
  // if (c == '\n') {
  //   s[i] = c;
  //   ++i;
  // }
  
  s[i] = '\0';
  return i;
}

void fatora(char s[], int a) {
  
  int div = 2, n;
  n = a;
  
  while (n != 1) {
    
    if(checaPrimo(div) == 1) {
      
      while(n % div == 0){
        
        
      }
    }
  }
}

int primeFactors(int s[], int num) {

    int i, j, isPrime;
    int p = 0;

    for(i=2; i<=num; i++) {
        
        if(num%i==0) {
                
            isPrime = 1;
            for(j=2; j<=i/2; j++) {
                
                if(i%j==0) {
                    
                    isPrime = 0;
                    break;
                }
            }

            /* If 'i' is Prime number and factor of num */
            if(isPrime==1) {
                
                s[p] = i;
                p++;
            }
        }
    }
    return p;
}

void printInt(int s[], int size) {
  
      for( int i = 0; i < size; i++ ) {
        
        printf("%d ", s[i] ); 
    }
    printf("\n"); 
}


int mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int mmc(int a, int b){
    return a * (b / mdc(a, b));
}