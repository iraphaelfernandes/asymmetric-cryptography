//Trabalho

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


#define MAX 1000

int lelinha (char s[], int lim);
int checa_primo(int a);
void coleta_chave_pub(int a);

//==================================================
int main(void) {
  
  char entrada[MAX];
  int pub1;
  int pub2;
  
  printf("\nEscolha dois números primos, os quais serão suas chaves públicas\n");
  printf("Digite o primeiro número: \n");
  coleta_chave_pub(pub1);
  printf("Digite o segundo número: \n");
  coleta_chave_pub(pub2);
  
  checa_primo(pub1 = getchar());
  
  printf("As chaves são: %d, %d\n", pub1, pub2);

//---------------------  
  return 0;
}
//==================================================
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

int checa_primo(int a) {
  int c;
  int var = 1;
  
  for (c = 3; c <= (a -1) && a%var == 0 ; c+=2) {
    
    if (a % c == 0) {
      
      return 0;
    }
    
  }
  
  if (c == a) {
    
    var = var * c;
    return 1;
  }
}   

void coleta_chave_pub(int a) {
  
  int n, v;
  
  n = scanf("%d", &n);
  v = checa_primo(n);
  
  if(v == 1) {
    
    n = a;
  }
  
  else if( v == 0) {
    
    printf("Por favor, digite um número primo: \n");
    coleta_chave_pub(a);
  }
}








