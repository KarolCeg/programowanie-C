#include<stdio.h>
#include<malloc.h>

typedef struct zespolona
{
    float re , im;
} zespolona;
typedef struct element
{
    zespolona liczba;
    struct element* nastepny;
    struct element* poprzedni;
} element;

element* nowy_elem(element* glowa, zespolona liczba)
{
    element* nowy = malloc(sizeof(element));
    *nowy = (element) { .liczba = liczba, .nastepny = NULL , .poprzedni = NULL};
    if (glowa)
    {
        for(element* pom = glowa; pom->nastepny || !(pom->nastepny = nowy); pom = pom->nastepny);
        return glowa;
    }
    return nowy;
}
int ile(element*glowa)
{
 if (!glowa) //pusta lista
    return 0;
    int i = 1;
    while (glowa -> nastepny)//nie pusta lista
    {
        glowa=glowa -> nastepny;
        i++;
    }
    return i;
}
element* usun_ostatni(element* glowa)
{
    
    if(!glowa) return; //pusta lista
    if(!glowa -> nastepny) //jeden element
    {
        free(glowa);
        return;
    }
    //wiele elementow
    while(glowa -> nastepny && glowa -> nastepny->nastepny)
         glowa = glowa -> nastepny;
     free(glowa -> nastepny);
    glowa -> nastepny = NULL;
    
}
element* usun_ity(element* glowa, int index)
{
element* poprzedni = NULL;
for(int i = 1 ; glowa && glowa -> nastepny && i++ < index ; )
    {
        poprzedni = glowa;
       glowa = glowa -> nastepny;
    }
    poprzedni -> nastepny = glowa -> nastepny;
    free(glowa);
} 
element* nowy_po(element* glowa, int index, zespolona liczba)
{
    element *pom_glowa = glowa; //element dodawany

    if(glowa)
    {
        if (index >= ile(glowa))
            glowa = nowy_elem(glowa, (zespolona) { liczba.re , liczba.im }); // dodaje na koncu niezaleznie jak index wykracza poza obszar struktury
        else //nie pusta ||indeks < ile
        {
            element* nowy = malloc(sizeof(element)); //nowy element, rezerowanie pamieci
            *nowy = (element) { .liczba = liczba, .nastepny = NULL , .poprzedni = NULL }; // wzor nowego elementu
            if (index == 0) // Wstawienie poczatek listy
            {
                nowy -> nastepny = glowa; //nadpisywanie
                glowa -> poprzedni = nowy;
                pom_glowa = nowy; //wpisywanie
            }
            else
            {
                for (int i = 1; i < index && glowa; i++, glowa = glowa -> nastepny); //szukanie miejsca

                    nowy -> nastepny = glowa -> nastepny; //nadpisywanie
                    if (glowa -> nastepny)
                    {
                        glowa -> nastepny -> poprzedni = nowy; 
                    }
                        nowy -> poprzedni = glowa; //wpisywanie nowego elementu
                        glowa -> nastepny = nowy; 
            }
        }
    }
    return pom_glowa;
}
element* nowy_koniec(element* glowa, zespolona liczba) // dodaje element na koncu listy
{
    glowa = nowy_elem(glowa, (zespolona) { liczba.re ,liczba.im });
}
void wypisz(element* glowa) //rekurencja
{
   if(!glowa) //pusta lista
     return;
     printf(" liczba zespolona = %f + i%f\n", glowa -> liczba.re , glowa -> liczba.im); //wypisywanie
    if(glowa -> nastepny)
        wypisz(glowa -> nastepny);  
}
void main()
{
    element* glowa = NULL;
    glowa = nowy_elem(glowa, (zespolona) { 2 , 2 });
    glowa = nowy_elem(glowa, (zespolona) { 1 , 1 });
    glowa = nowy_elem(glowa, (zespolona) { 6 , 5 });
    wypisz(glowa);
    printf("dlugosc = %d\n" , ile(glowa));
    printf("dodajemy element na trzecim miejscu\n");
    nowy_po(glowa , 2 , (zespolona) { 5 , 4 }); 
    wypisz(glowa);
    printf("dlugosc = %d\n" , ile(glowa));
    printf("dodajemy element na koncu listy\n");
    nowy_koniec(glowa, (zespolona) { 12 , 3 });
    wypisz(glowa);
    printf("dlugosc = %d\n" , ile(glowa));
    printf("usuwamy element z konca listy\n");
    usun_ostatni(glowa);
    wypisz(glowa);
    printf("dlugosc = %d\n" , ile(glowa));
    printf("usuwamy trzeci element z konca listy\n");
    usun_ity(glowa , 3);
    wypisz(glowa);
    printf("dlugosc = %d\n" , ile(glowa));
}
//dodawanie na koncu w srodku/ usuwanie na koncu srodku / wyswietlanie / zliczanie 

