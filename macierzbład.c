macierz dopelnienie(macierz M)
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
      printf("nie mozna odwrócić macierzy");
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
            podM.wiersze = M.wiersze -1 ;
            podM.kolumny = M.kolumny - 1;
            podM.elementy = dopelnienie(M);
            float  podMdet = wyznacznik(podM);
            float znak = pow(-1,1+i+1);
            odwrotnaM[j * M.kolumny + i] = znak * podMdet / wyznacznik(M);
        }
    }
return odwrotnaM;
}
