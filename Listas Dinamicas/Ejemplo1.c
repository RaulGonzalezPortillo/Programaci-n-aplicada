#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Def_Dato
{
  int Dato;
  struct Def_Dato *Sig;
} TipoDato;

void InsertaInicio (int Numero, TipoDato **Inicio);
void InsertaFin (int Numero, TipoDato **Inicio);
void InsertaEnOrden (int Numero, TipoDato **Inicio);
void ImprimirLista (TipoDato *Inicio);
void BorrarLista (TipoDato *Inicio);
  
int main (void)
{
  int Eleccion = 0, Numero;
  char Enter;
  TipoDato *Inicio = NULL;
  do
    {
      system ("clear");
      printf ("\n");
      printf ("Bienvenido, escoja una opción:\n\n\n");
      printf ("1.- Insertar numero al inicio\n\n");
      printf ("2.- Insertar numero al final\n\n");
      printf ("3.- Insertar numero en orden\n\n");
      printf ("4.- Mostrar numeros\n\n");
      printf ("5.- Salir del programa y borrar la lista de la memoria\n\n");
      scanf ("%d", &Eleccion);
      printf ("\n");
      switch (Eleccion)
	{
	case 1:
	  printf ("Inserte un numero:\n\n");
	  scanf ("%d", &Numero);
	  InsertaInicio (Numero, &Inicio);
	  break;
	case 2:
	  printf("Inserte un numero:\n\n");
	  scanf ("%d", &Numero);
	  InsertaFin (Numero, &Inicio);
	  break;
	case 3:
	  printf ("Inserte un numero: (Función pensada para utilizarse en lugar de Insertar al inicio / fin, de haberlas usado antes, puede esta que no funcione)\n\n");
	  scanf ("%d", &Numero);
	  InsertaEnOrden (Numero, &Inicio);
	  break;
	case 4:
	  ImprimirLista (Inicio);
	  printf ("\n");
	  printf ("Presione enter para continuar...\n\n");
	  __fpurge (stdin);
	  scanf ("%c", &Enter);
	  break;
	case 5:
	  BorrarLista (Inicio);
	  break;
	default:
	  printf ("Ha elegido una opción que no existe\n\n");
	  printf ("Presione enter para continuar....\n\n");
	  __fpurge (stdin);
	  scanf ("%c", &Enter);
	  break;
	}
    }
  while (Eleccion != 5);
}

void InsertaInicio (int Numero, TipoDato **Inicio)
{
  TipoDato *Temp;
  Temp = (TipoDato*) malloc (sizeof (TipoDato));
  Temp -> Dato = Numero;
  Temp -> Sig = *Inicio;
  *Inicio = Temp;
}

void InsertaEnOrden (int Numero, TipoDato **Inicio)
{
  TipoDato *Temp, *Temp2, *Temp3, *Nuevo;
  Nuevo = (TipoDato*) malloc (sizeof (TipoDato));
  Nuevo -> Dato = Numero;
  Temp = *Inicio;
  while ((Temp != NULL) && (Numero > Temp -> Dato))
    {
      Temp = Temp -> Sig;
    }
  if (Temp != NULL)
    {
      if (Temp != *Inicio)
	{
	  Temp2 = *Inicio;
	  while (Temp2 -> Sig != Temp)
	    {
	      Temp2 = Temp2 -> Sig;
	    }
	  Nuevo -> Sig = Temp;
	  Temp2 -> Sig = Nuevo;
	}
      else
	{
	  Nuevo -> Sig = *Inicio;
	  *Inicio = Nuevo;
	}
    }
  else
    {
      Nuevo -> Sig = NULL;
      if (*Inicio != NULL)
	{
	  Temp3 = *Inicio;
	  while (Temp3 -> Sig != NULL)
	    Temp3 = Temp3 -> Sig;
	  Temp3 -> Sig = Nuevo;
	}
      else
	*Inicio = Nuevo;
    }
}

void InsertaFin (int Numero, TipoDato **Inicio)
{
  TipoDato *Temp, *Temp2;
  Temp = (TipoDato *) malloc (sizeof (TipoDato));
  Temp -> Dato = Numero;
  Temp -> Sig = NULL;
  if (*Inicio != NULL)
    {
      Temp2 = *Inicio;
      while (Temp2 -> Sig != NULL)
	Temp2 = Temp2 -> Sig;
      Temp2 -> Sig = Temp;
    }
  else
    *Inicio = Temp;
}

void ImprimirLista (TipoDato *Inicio)
{
  TipoDato *Temp;
  Temp = Inicio;
  while (Temp != NULL)
    {
      printf ("%d\n", Temp -> Dato);
      Temp = Temp -> Sig;
    }
}

void BorrarLista (TipoDato *Inicio)
{
  TipoDato *Temp;
  while (Inicio != NULL)
  {
    Temp = Inicio;
    Inicio = Inicio -> Sig;
    free (Temp);
  }
}
