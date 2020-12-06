#include <stdlib.h>
#include <stdio.h>

int * eliminaRepeat(int entrada[], int tam);

int main( void )
{
    /* Vetor de entrada com elementos de valor duplicado */
    int vetor[14] = { 1, 2, 3, 4, 4, 5, 5, 6, 7, 8, 9, 9, 10, 10 };

    /* Vetor de saida */
   // int saida[14];

    int i, j, n = 0;
    int tam = sizeof(vetor) / sizeof(int);

    /* Exibe Vetor de Entrada */
    printf("Antes: ");
    for( i = 0; i < tam; i++ )
        printf("%d ", vetor[i] );
    printf("\n");
    

    int saida;
    saida = eliminaRepeat(vetor, 14);
    
    printf("Depois: ");
    for( int x = 0; x < sizeof(saida) / sizeof(int); x++ )
        printf("%d ", saida[x] );
    printf("\n");
    /* Remove elementos com valor duplicado */
    // for( i = 0; i < tam; i++) {
    //     for( j = 0; j < n; j++ )
    //     {
    //         if( vetor[i] == saida[j] )
    //             break;
    //     }

    //     if( j == n )
    //     {
    //         saida[n] = vetor[i];
    //         n++;
    //     }
    // }

    /* Exibe Vetor de Saida */


    return 0;
}


int * eliminaRepeat(int entrada[], int tam){
    
    int i, j, n = 0;
    int temp[tam];
    
    for( i = 0; i < tam; i++) {
        
        for( j = 0; j < n; j++ ) {
            
            if( entrada[i] == temp[j] )
                break;
        }

        if( j == n ) {
            
            temp[n] = entrada[i];
            n++;
        }
    }
    
    int saida[];
    
    for(int x = 0; x != n; x++ ) {
        
        saida[x] = temp[x];
    }    
    return saida;
}