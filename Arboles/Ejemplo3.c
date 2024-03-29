#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Nodo
{
  char Letra;
  struct Nodo *Izq, *Der;
};

void Inserta (struct Nodo **Raiz, char Insertador)
{
  struct Nodo *Avanza, *Nuevo;
  Avanza = *Raiz;
  if ((Nuevo = (struct Nodo *) malloc (sizeof (struct Nodo))) == NULL)
    {
      printf ("No hay memoria\n");
      exit (1);
    }
  Nuevo -> Letra = Insertador;
  Nuevo -> Izq = NULL;
  Nuevo -> Der = NULL;
  while (Avanza != NULL)
    {
      if (Insertador > Avanza -> Letra) //Muevete a la derecha
	{
	  if (Avanza -> Der != NULL)
	    {
	      Avanza = Avanza -> Der;
	    }
	  else
	  {
	    Avanza -> Der = Nuevo;
	    return;
	  }
	}
      if (Insertador <= Avanza -> Letra) //Muevete a la izquierda
	{
	  if (Avanza -> Izq != NULL)
	    {
	      Avanza = Avanza -> Izq;
	    }
	  else
	    {
	      Avanza -> Izq = Nuevo;
	      return;
	    }
	}
    }
  *Raiz = Nuevo;
  //Avanza = Nuevo;
  //*Raiz = Avanza;
}

void Imprime (struct Nodo *Impresor)
{
  if (Impresor != NULL)
    {
      Imprime (Impresor -> Izq);
      printf ("%c\n", Impresor -> Letra);
      Imprime (Impresor -> Der);
    }
}

void Borra (struct Nodo *Borrador)
{
  if (Borrador != NULL)
    {
      Borra (Borrador -> Izq);
      Borra (Borrador -> Der);
      free (Borrador);
    }
}

int main (void)
{
  char Insertador;
  struct Nodo *Raiz;
  Raiz = NULL;
  system ("clear");
  printf ("\n");
  printf ("Teclea letras, seguido por un cáracter alfabético para terminar (solo se considera una letra a la vez):\n\n");
  do
  {
    __fpurge (stdin);
    scanf ("%c", &Insertador);
    if ((Insertador >= 'a' && Insertador <= 'z') || (Insertador >= 'A' && Insertador <= 'Z'))
    {
      Inserta (&Raiz, Insertador);
    }
    system ("clear");
    printf ("\n");
    printf ("Letras impresas en orden:\n\n");
    Imprime (Raiz);
    printf ("\n");
    if ((Insertador >= 'a' && Insertador <= 'z') || (Insertador >= 'A' && Insertador <= 'Z'))
    {
      printf ("Continúe tecleando:\n\n");
    }
  }
  while ((Insertador >= 'a' && Insertador <= 'z') || (Insertador >= 'A' && Insertador <= 'Z'));
  Borra (Raiz);
}
