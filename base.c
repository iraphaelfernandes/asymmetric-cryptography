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
void codifica(int vet[], char s[], int n1, int n2); //Converte com (s[i]^p)%div

int calculaModulo( int n, int firstKey, int Y); //uso para achar o tal 77


void decodifica(int vetor[], int privKey, int prodPrime, char frase[]);

char itoc(int a);
void str_reverse(char str1[], int index, int size);
void itob(int n, char s[], int b);

int decToBin(int n);
int returnLastNum(int num);
int eliminaLastDigt( int n);

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
int main(void) {
  

  char frase[MAX];
  //int tamFrase;
  printf("\nDigite uma fase para ser criptografada: \n");
  
  lelinha (frase, MAX);
  printf("A frase a ser criptografada é:\n%s\n", frase);
  
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
  
  //Essa parte é responsável por escolher as chaves públicas
  int numPrimeFactors; //Quantos são os fatores primos
  int fatoresPrimos[100];
  numPrimeFactors = primeFactors(fatoresPrimos, Y);
  int firstPubKey;
  firstPubKey = escolhePubKey(fatoresPrimos[0], fatoresPrimos[numPrimeFactors - 1]);
  
  printf("\nAs chaves públicas são %d e %d.\n", firstPubKey, prodPrime);
  
  int n;
  int privKey = 0;
  
  while (n != 1){
  
    privKey++;
    n = calculaModulo( privKey, 5, Y);
  }
  
  printf("\nA chave privada será: %d\n", privKey);
  
  
  //Aqui converterá a frase na mensagem transmitida
  int vet[MAX];
  
  codifica(vet, frase, firstPubKey, prodPrime);
  
  
  printf("\nA mensagem transmitida será: \n");
    
  for( int i = 0; frase[i] != '\0'; i++) {
    
    printf("%d  ", vet[i]);
  }
  printf("\n");
  
  //Decodificação*********************************
  
  // char strM[MAX];
  // int p = 0;
  // char caract;
  // int inteiro;
  
  // while(frase[p] != '\0') {
  
  //   inteiro = vet[p];
  //   caract = itoc(inteiro);
  //   strM[p] = caract;
  //   p++;
  // }
  // strM[p] = '\0';
  
  // printf("\nA frase transmitida: \n");
  // printf("%s\n", strM);
  
  
  
  
//----------------------------------------------------  
  return 0;
}
//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§


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

void decodifica(int vetor[], int privKey, int prodPrime, char frase[]) {
  
  unsigned long int resultPow;
  int resultDiv;
  
  for (int i = 0; frase[i] != '\0'; i++) {
    
    resultPow = pow(vetor[i], privKey);
    resultDiv = (resultPow % prodPrime);
    vetor[i] = resultDiv;
  }
  
}


int escolhePubKey(int n1, int n2) {
    
    int num;
    num = mmc(n1, n2);
    
    return (num -1);
}

int calculaModulo( int n, int firstKey, int Y) {
  
  int num;
  // int prod;
  
  num = (n * firstKey) % Y;
  return num;  
}

int checaPrimo(int a) {
  
     int c;
 
   for ( c = 2 ; c <= a - 1 ; c++ )
   { 
      if ( a%c == 0 )
     return 0;
   }
   return 1;
  // int c;
  // int var = 1;
  
  // for (c = 2; c <= (a -1); c+=1) {
    
  //   if (a % c == 0) {
      
  //     return 0;
  //   }
    
  // }
  
  // if (c == a) {
    
  //     return 1;
  //   }
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



//Função itob

char itoc(int a) {
  
  if (a <= 9)
  {
    return a + '0';
  }

  return a + 'a' - 10;
}

void itob(int n, char s[], int b) {
  int i = 0, sign = n;

  do {
    
    s[i++] = itoc(abs(n) % b);
    n /= b;
  } while (n /= b);

  switch (b) {
    
  case 2:
    s[i++] = 'b';
    s[i++] = '0';
    break;

  case 16:
    s[i++] = 'x';
    s[i++] = '0';
    break;
  }

  if (sign < 0)
  {
    s[i++] = '-';
  }

  s[i] = '\0';

  int s_len = strlen(s);
  str_reverse(s, 0, s_len - 1);
}

void str_reverse(char str1[], int index, int size) {
  
  char temp;

  temp = str1[index];
  str1[index] = str1[size - index];
  str1[size - index] = temp;

  if (index == size / 2) {
    
    return;
  }

  str_reverse(str1, index + 1, size);
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

int returnLastNum(int num) {
    
    return num % 10;
    
}

int eliminaLastDigt( int n) {
    
    return n / 10;
}