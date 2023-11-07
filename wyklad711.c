#include <stdio.h>
/*
pierwszy plik
void main(void)
{
    char bufor[1024];
    FILE *plik = fopen("test.c" , "r");
    while(!feof(plik))
    {
       // fscanf(plik, "%s" , bufor); //zczytuje ale bez enterow chyba
        fscanf(plik,"%[^\n]\n" , bufor); //zczytuje pli
        //fseek(plik, 0 , SEEK_SET); //wypisuje w nieskonczonosc
        printf("%s\n" , bufor); //wypisuje plik
    }
    fclose(plik);
}
*/
//-------------------------
/*

drugi plik
void main(void)
{
    float liczby []= {0,1,2,3,4,5,6,7,8,9};
    FILE *plik = fopen("liczby", "w+"); //otwiera plik
    fwrite(liczby , sizeof(float) , 10 , plik); //wpisuje do pliku
    fclose(plik); 
}
*/
//-------------------------------------
/*
r" Open a text file for reading.
"w" Open a text file for writing, truncating an an existing file to zero length, or creating the file if it does not exist.

"r+" Open a text file for update (that is, for both reading and writing).
"w+" Open a text file for update (reading and writing), first truncating the file to zero length if it exists or creating the file if it does not exist.
*/
//--------------------
void main (void)
{

    char znaczek;
    while(!feof(stdin))
    {
        fread(&znaczek, 1 , 1, stdin);
        fwrite(&znaczek , 1, 1, stdout);
    }
}