#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
 {
  // Generamos dos matrices aleatorias
  int arr1[30][30];
  int arr2[30][30];
  for (int i = 0; i < 30; i++)
   {
    for (int j = 0; j < 30; j++) 
	{
      arr1[i][j] = rand() % 10;
      arr2[i][j] = rand() % 10;
    }
  }

  // Imprimimos las matrices antes de la multiplicación
  printf("Matriz 1:\n");
  for (int i = 0; i < 30; i++) 
  {
    for (int j = 0; j < 30; j++)
	 {
      printf("%d ", arr1[i][j]);
    }
    printf("\n");
  }
  printf("Matriz 2:\n");
  for (int i = 0; i < 30; i++)
   {
    for (int j = 0; j < 30; j++) 
	{
      printf("%d ", arr2[i][j]);
    }
    printf("\n");
  }

  

  
  int result[30][30];
  for (int i = 0; i < 30; i++)
   {
    for (int j = 0; j < 30; j++)
	 {
      for (int k = 0; k < 30; k++) 
	  {
        result[i][j] += arr1[i][k] * arr2[k][j];
      }
    }
  }

  // Obtenemos el tiempo de finalización
  

  // Imprimimos los resultados
  printf("Resultados:\n");
  for (int i = 0; i < 30; i++) 
  {
    for (int j = 0; j < 30; j++) 
	{
      printf("%d ", result[i][j]);
    }
    printf("\n");
  }

  // Imprimimos el tiempo de ejecución
 

  return 0;
}
