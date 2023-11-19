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
/*

macierz dopelnienie(macierz M , int i , int j )
{
macierz dopelnienie = utworz_macierz(M.wiersze -1 , M.kolumny -1 );//macierz dopelnien
   dopelnienie.wiersze = M.wiersze -1 ;
    dopelnienie.kolumny = M.kolumny -1 ;
  for (int i = 0 ;  i < M.wiersze ; i++)
    {
       int pozycja = 0 ;
    for( int w = 1 ; w < M.wiersze  ; w++)
        {
            for( int k = 0 ; k < M.kolumny; k++) 
            {
                if(k != i) 
                {
                   dopelnienie.elementy[pozycja++] = M.elementy[w * M.kolumny + k];
                }
            }
        }
    }
        return dopelnienie;
}
*/
macierz dopelnienie_macierzy(macierz M , int i , int j )
{
macierz dopelnienie = utworz_macierz(M.wiersze -1 , M.kolumny -1 );//macierz dopelnien
   dopelnienie.wiersze = M.wiersze -1 ;
    dopelnienie.kolumny = M.kolumny -1 ;
       int pozycja = 0 ;
    for( int w = 0 ; w < M.wiersze  ; w++)
        {
            for( int k = 0 ; k < M.kolumny; k++) 
            {
                if(w != i && k != j) 
                {
                   dopelnienie.elementy[pozycja++] = M.elementy[w * M.kolumny + k];
                }
            }
        }
        return dopelnienie;
}
macierz odwrotna(macierz M)
{
if(M.wiersze != M.kolumny)
{
    printf("nie mozna odwrócić macierzy");
    return M;
}
if(wyznacznik(M) == 0)
{
      printf("nie mozna odwrOciC macierzy\n");
    return M;
}
    macierz odwrotnaM = utworz_macierz(M.wiersze  , M.kolumny  );//macierz odwrotna
    odwrotnaM.wiersze = M.wiersze  ;
    odwrotnaM.kolumny = M.kolumny  ;
  for( int i = 0 ; i < M.wiersze ; i++)
    {
        for ( int j = 0 ; j < M.kolumny ; j++)
        {
            macierz podM = utworz_macierz(M.wiersze -1 , M.kolumny -1  );//macierz odwrotna
            podM = dopelnienie_macierzy(M , i , j);
            float  podMdet = wyznacznik(podM);
            float znak = pow(-1,1+i+j+1);
            odwrotnaM.elementy[j * M.kolumny + i] = znak * podMdet / wyznacznik(M);
            free(podM.elementy);
        }
    }
return odwrotnaM;
}

void main()
{
srand( time( NULL ) ); // pozwala na zmienianie "losowych" liczb
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


macierz M4 = utworz_macierz(3,3);
wpisz(M4);
printf("macierz M4\n");
wypisz_macierz(M4);
printf("wyznacznik macierzy M4 \n");
printf("%.2f" , wyznacznik(M4));
printf("\n");
macierz M5 = utworz_macierz(3,3);
M5 = odwrotna(M4);
printf("odwroc macierz M5\n");
wypisz_macierz(M5);
}
