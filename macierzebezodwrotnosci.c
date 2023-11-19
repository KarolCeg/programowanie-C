#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>
#include <math.h>
typedef struct macierz
{
    int wiersze , kolumny;
    float* elementy;
}macierz;


macierz utworz_macierz(int wiersze , int kolumny )
{
    return (macierz) { .wiersze = wiersze , .kolumny = kolumny , .elementy = calloc(wiersze * kolumny , sizeof(float) )  }; //tworzy miejsce na macierz
}


void wypisz_macierz(macierz M)
{
    for(int i = 0; i < M.wiersze ; i++)
    {
        for( int j = 0 ; j < M.kolumny ; j++)
        printf ("%.2f \t" , M.elementy[i * M.kolumny + j] );
        printf ("\n");
    }
}


void wpisz(macierz M)
{
for(int i = 0 ; i < M.wiersze ; i++)
    for(int j = 0 ; j < M.kolumny ; j++)
    {
        M.elementy[i * M.kolumny + j] = ( rand() % 10 ) + 0; // wpisuje losowe liczby
    }
}


void wpisz_samemu(macierz M, float *dane)
{
for(int i = 0 ; i < M.wiersze ; i++)
    for(int j = 0 ; j < M.kolumny ; j++)
    {
        M.elementy[i * M.kolumny + j] = dane[i * M.kolumny + j];
    }
}


macierz iloczyn( macierz M1 , macierz M2)
{
macierz M3 = utworz_macierz(M1.wiersze , M2. kolumny);
if(M1.kolumny != M2.wiersze)
{
    printf ("nie można utworzyć macierzy");
     M3.wiersze = 0;
     M3.kolumny = 0;
     return M3;
}
for(int i = 0 ; i < M3.wiersze ; i++)
    {
        for(int j = 0 ; j < M3.kolumny ; j++)
         {
             float pom = 0;
                for( int k = 0 ; k < M1.kolumny ; k++ )
                  pom += M1.elementy[i * M1.kolumny + k] * M2.elementy[k * M2.kolumny + j];
            M3.elementy[i * M3.kolumny + j] = pom;
         }
    }
    return M3;
}   


float wyznacznik (macierz M)
{
    float det = 0;
    if(M.wiersze != M.kolumny) //macierz nie kwadratowa
    {
        printf("nie mozna wyznaczyc wyznacznika\n");
        return det = 0;
    }
    if (M.wiersze == 1 && M.kolumny==1) //macierz 1x1
    {
        det = M.elementy[0];
        return det;
    }
    
    if(M.wiersze == 2 && M.kolumny == 2)//macierz 2x2
    {
        det = (M.elementy[0] * M.elementy[3]) -(M.elementy[1]*M.elementy[2]);
        return det;
    }
    for (int i = 0 ;  i < M.kolumny ; i++)
    {
       int pozycja = 0 ;
    macierz podM = utworz_macierz(M.wiersze -1 , M.kolumny -1);//podmacierz
    podM.wiersze = M.wiersze - 1;
    podM.kolumny = M.kolumny - 1;
    for( int w = 1 ; w < M.wiersze  ; w++)
        {
            for( int k = 0 ; k < M.kolumny; k++) 
            {
                if(k != i) 
                {
                    podM.elementy[pozycja++] = M.elementy[w * M.kolumny + k];
                }
            }
        }
    float znak = pow(-1,1+i+1);
    det += znak * M.elementy[i] * wyznacznik(podM);
    free(podM.elementy);
    }
    return det;
}


macierz odwrotna(macierz M)
{

}

void main()
{
// srand( time( NULL ) ); // pozwala na zmienianie "losowych" liczb
macierz M1 = utworz_macierz(3,3);
macierz M2 = utworz_macierz(3,3);
macierz M3 = utworz_macierz(3,3);

wpisz(M1);
wypisz_macierz(M1);
printf("\n");
wpisz(M2);
wypisz_macierz(M2);
printf("\n");
printf("iloczyn Macierzy M1 * M2\n");
M3 = iloczyn(M1 , M2);
wypisz_macierz(M3);
printf("\n");
free(M1.elementy);
free(M2.elementy);
free(M3.elementy);
printf("\n");

 // wpisywanie wlasnych wartosci
macierz M4 = utworz_macierz(3,3);
float dane1[] = {1 ,2, 2, 1 };
//wpisz_samemu(M4, dane1);
wpisz(M4);
wypisz_macierz(M4);
printf("\n");
printf("%.2f" , wyznacznik(M4));
}
