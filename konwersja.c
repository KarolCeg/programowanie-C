#include <stdio.h>
int konwersja(char wiersz , char kolumna, int rozmiar)
{
int pozycja = 0;
printf("podaj pole na ktorym chcesz postawic pionek (wiersz , kolumna)\n");
//scanf("%c %c", &wiersz , &kolumna); 
wiersz = 'C';
kolumna = 3;
wiersz = wiersz - 64;  //tablica od zera do 8
 pozycja = wiersz*(rozmiar-1) +kolumna;
 return pozycja;
}
void main()
{
    char wiersz = 0 , kolumna = 0;   
    printf("%d", konwersja(wiersz,kolumna,3));
}
//trzeba konwersję A,B C ... na wartosci 1,2,3,...
//65-(wartosc zera w ascii)