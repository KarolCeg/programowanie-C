#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>

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
        printf ("%f " , M.elementy[i * M.kolumny + j] );
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
    //wywoływanie funckji przez samą siebie
}

macierz odwrotna(macierz M)
{

}

void main()
{
   // srand( time( NULL ) ); // pozwala na zmienianie "randomowych" liczb
macierz M1 = utworz_macierz(3,3);
macierz M2 = utworz_macierz(3,3);
macierz M3 = utworz_macierz(3,3);
wpisz(M1);
wypisz_macierz(M1);
printf("\n");
wpisz(M2);
wypisz_macierz(M2);
printf("\n");
M3 = iloczyn(M1 , M2);
wypisz_macierz(M3);
printf("\n");
free(M1.elementy);
free(M2.elementy);
free(M3.elementy);
}
//randomowe liczby rand