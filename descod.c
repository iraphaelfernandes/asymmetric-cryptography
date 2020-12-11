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
void codifica(unsigned long int vet[], char s[], int n1, int n2); //Converte com (s[i]^p)%div

int calculaModulo( int n, int firstKey,int Y); //geral o tal 77
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
int main(void) {
  
  int privKey;
  int n = 0; 
  int Y = 192;
  
  ///////////////////////////////////////////////////////
  //A chave de decodificação cujo produto pelo primeiro número publicado
  // while (n != 1){
  
  //   privKey++;
  //   n = calculaModulo( privKey, 5, Y);  
  // }
    
  // printf("\n%d\n", privKey);
  ///////////////////////////////////////////////////////
  
  FILE *fp;
  char str[MAX];
  char* filename = "./numcripto.txt";
  int j = 0;
  
  fp = fopen(filename, "r");
  
  if (fp == NULL){
      printf("Could not open file %s",filename);
      return 1;
    }
  
  char * num;
  int numbers[MAX];
    while ( (num = fgets(fp)) != EOF ) {
      
      str[j] = num;
      j++;
    // numbers[j] = num;
    // j++;
  }
    
  printf("\n%d", numbers[0]);
  
  // while (fgets(str, MAX, fp) != NULL){
    
  //   for(j = 0; str[j]; j++) {
      
  //     fputc(str[j], fp);
  //   }
  // }


  fclose(fp);
    
    
      
  // pubKeys[0] = fgets(pubKeys, sizeof pubKeys, "numcripto.txt");
  
  // printf("\n\n%s", pubKeys);
  
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

void codifica(unsigned long int vet[], char s[], int n1, int n2) {

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

    // for(int j = 0; j != i; j++) {

    //     temp = pow(vet[j], pot);
    //     vet[j] = temp % n2;
    // }
}


int calculaModulo( int n, int firstKey,int Y) {
  
  int num;
  
  num = (n * firstKey) % Y;
  return num;  
}
