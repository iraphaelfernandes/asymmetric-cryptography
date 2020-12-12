//Raphael dos Santos de Oliveira Fernandes


#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 1000

//Functions %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
void codifica(int vet[], char s[], int n1, int n2); //Converte com (s[i]^p)%div

int lelinha (char s[], int lim);

int decodifica(int numCod, int privKey, int prodPrime);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§
int main( int argc, char *argv[ ]) {
  

  char frase[MAX];
    
  //Le a entrada
  printf("\nDigite o texto para ser criptografado e pressione ctrl+d para indicar o final dele. \n");
  
  lelinha (frase, MAX);
  printf("\nA frase a ser criptografada é:\n%s\n", frase);
  
    
  //Coloca o texto no arquivo
  FILE* saidaTexto = fopen("texto.txt", "w+");
  fprintf(saidaTexto, "%s ", frase);
  fclose(saidaTexto);
  
   //Pega as chaves publicas
  int firstPubKey, prodPrime;
  FILE * getPubKey = fopen("numcripto.txt", "r");
  fscanf(getPubKey, "%d %d", &firstPubKey, &prodPrime);
  fclose(getPubKey);
  
  //Pega a chave privada
  int privKey;
  FILE * getPrivKey = fopen("numdescripto.txt", "r");
  fscanf(getPrivKey, "%d", &privKey);
  fclose(getPrivKey);
  
  //Codifica a frase
  int vetCodificado[MAX];
  codifica(vetCodificado, frase, firstPubKey, prodPrime);
  
    //Coloca a mensagem criptografada em um arquivo
  FILE* mensCripto = fopen("menscripto.txt", "w+");
  for (int i = 0; frase[i] != '\0'; i++) {
    
    fprintf(mensCripto, "%d ", vetCodificado[i]);
  }
  fclose(mensCripto);
  
  printf("\nA mensagem criptografada e transmitida será: \n");
    
  for( int i = 0; frase[i] != '\0'; i++) {
    
    printf("%d  ", vetCodificado[i]);
  }
  printf("\n");
  
  //Decodificação*********************************
  
  int fraseDecod[MAX];
  int varTemp;
  for(int i = 0; frase[i] != '\0'; i++) {
    
    varTemp = decodifica(vetCodificado[i] , privKey, prodPrime);
    fraseDecod[i] = varTemp;
  }
  
  printf("\nA mensagem recuperada em código ASCII é: \n");
    
  for( int i = 0; frase[i] != '\0'; i++) {
    
    printf("%d  ", fraseDecod[i]);
  }
  printf("\n");
  
  char fraseRecuperada[MAX];
  int p;
  
  for (p = 0; frase[p] != '\0'; p++) {
  
    fraseRecuperada[p] = fraseDecod[p];
  }
  p++;
  fraseRecuperada[p] = '\0';
  
  printf("\nOu seja:");
  printf("\n%s\n", fraseRecuperada);
  
  
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