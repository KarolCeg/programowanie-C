#include <stdio.h>
int konwersja(char kolumna , char wiersz, int rozmiar)
{
int pozycja = 0;
printf("podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n"); 
kolumna = getchar();
getchar();
wiersz = getchar();
wiersz -='0';
kolumna -= 'A';  
printf("%d , %d\n", kolumna + 1 , wiersz);
wiersz--;
pozycja = wiersz*rozmiar +kolumna;
 return pozycja;
}
void main()
{
    char wiersz  , kolumna ;   
    printf("%d", konwersja(kolumna,wiersz,13));
}
dwucyfrowe cyfry w ascii
