#include <stdio.h>

void Seleccion (int m[], int n_elementos)
{
  int i, j, min, temp;
  for (i = 0; i < n_elementos; i ++)
    {
      min = i;
      for (j = i + 1; j < n_elementos; j ++)
	{
	  if (m[j] < m[min])
	    {
	      min = j;
	    }
	}
      temp = m [i];
      m [i] = m [min];
      m [min] = temp;
    }
}

int main ()
{
  int m[] = {25, 2, 7, 3, 67, 43, 1, 15, 9, 32};
  int i;

  printf ("Arreglo original\n");
  for (i = 0; i < 10; i ++)
    {
      printf ("%d ", m[i]);
    }
  printf ("\nArreglo ordenado\n");
  Seleccion (m, 10);
  for (i = 0; i < 10; i ++)
    {
      printf ("%d ", m[i]);
    }
  return (1);
}
