#include <stdio.h>
#include <stdlib.h>

void PedirDatos (int Numeros [], int CantidadALeer);
void OrdenarDatos (int Numeros [], int CantidadALeer);
void ImprimirDatos (int Numeros [], int CantidadALeer);

int main (void)
{
  system ("clear");
  int Numeros [100], CantidadALeer;
  printf ("Introduzca la cantidad de números a leer: ");
  scanf ("%d", &CantidadALeer);
  if (CantidadALeer < 1 || CantidadALeer > 100)
    {
      printf ("Se ha producido un error: Saliendo\n");
      exit (0);
    }
  PedirDatos (Numeros, CantidadALeer);
  OrdenarDatos (Numeros, CantidadALeer);
  ImprimirDatos (Numeros, CantidadALeer);
}

void PedirDatos (int Numeros [], int CantidadALeer)
{
  int i;
  printf ("A continuación introducirá los %d valores\n", CantidadALeer);
  for (i = 0; i < CantidadALeer; i ++)
    {
      printf ("Introduzca el valor #%d: ", i + 1);
      scanf ("%d", &Numeros[i]);
    }
}

void OrdenarDatos (int Numeros [], int CantidadALeer)
{
  int i, i2, temp;
  for (i = 0; i < CantidadALeer; i++)
    {
      for (i2 = i + 1; i2 < CantidadALeer; i2 ++)
	{
	  if (Numeros [i2] < Numeros [i])
	    {
	      temp = Numeros [i];
	      Numeros [i] = Numeros [i2];
	      Numeros [i2] = temp;
	    }
	}
    }
}

void ImprimirDatos (int Numeros [], int CantidadALeer)
{
  int i;
  printf ("A continuación se imprimirán los %d valores de forma ascendente\n", CantidadALeer);
  for (i = 0; i < CantidadALeer; i ++)
    {
      printf ("Elemento #%d: %d\n", i + 1, Numeros [i]);
    }
}
