#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void seive(int n, int prime[], int allPrimes[]);


int main() {
  
  int prime[20];
  int allPrimes[20];
  
  seive(192, prime, allPrimes);
  

} 

void seive(int n, int prime[], int allPrimes[]) {
  
  //int prime[20];
  int p = 2;
  
  while (p * p <= n) {
    
    if(prime[p] == 0) {
      
      for(int i = 2*p; i < (n+1); i += p) {
        
        prime[i] = 1;
      }
    }
    p += 1;
  }
    
  //int allPrimes[20];
  
  for( int i = 2; i < n; i++) {
    
    if(prime[i] == 0) {
      
      allPrimes[i];
    }
  }
}

