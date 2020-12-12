
#include <stdio.h>

int decToBin(int n);

int returnLastNum(int num);
int eliminaLastDigt(int n);


long int decodifica(long long x, unsigned long long y, long long p);

int main() {
    
    long int n;
    n = decodifica(216, 221, 77);
    
    printf("\n%ld\n", n);
    
    //----------------------
    return 0;
}



long int decodifica(long long x, unsigned long long y, long long p) {
    
    long long res = 1;
    
    x = x%p;
    
    if(x == 0) {
        
        return 0;
    }
    
    while (y > 0) {
        
        if(y & 1)     
            res = (res * x) % p;
            
        x = y >> 1;
        x = (x*x) % p;
    }
    return res;
    
}