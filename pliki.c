#include <stdio.h>

int main( int argc , char *args[])// to w nawaisie chyba niepotrzebne -do sprawdzenia
{
    FILE *plik = fopen("pliki.c", "r");// args[0] nazwa pliku z ktorego rpopgram zostal uruchomiony
    char bufor[1024];
    while(!feof(plik))//feof jakas funckaj z czytania pliku
    {
        fscanf(plik, "%s" , bufor);// fscanf czyta do pierwszego bialego znaku w linijce
        printf("%s\n" , bufor);
    }
    fclose(plik);
}
//jakas sieczka ma byc
//powinna bcy awaria 
//fread fwrite