#include <stdio.h>
int konwersja(char kolumna , char wiersz, int rozmiar)
{
int pozycja = 0;
printf("podaj pole na ktorym chcesz postawic pionek (kolumna , wiersz)(np A1)\n"); 
scanf("%c%d", &kolumna , &wiersz); 
pozycja = (wiersz - 1)*rozmiar + kolumna - 'A';
return pozycja;
}
void main()
{
    char wiersz  , kolumna ;   
    printf("%d", konwersja(kolumna,wiersz,13));
}
