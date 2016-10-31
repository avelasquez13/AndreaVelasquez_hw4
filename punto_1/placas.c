#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

  float L = 5, l = 2, d = 1, h = 0.02, V0 = 100;
  float N = 2*pow((L/h), 2);
  int n = (int)(L/h);

  //inicializa la matriz
  int i, j, k;
  
  double **matriz;
  matriz = (double**) malloc(n*sizeof(double*));

  for (i=0; i<=n; i++){
    matriz[i] = (double*) malloc(n*sizeof(double));
  }

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      matriz[i][j] = 10;
    }
  }

  for(i=(int)((L/2-l/2)/h); i<(int)((L/2+l/2)/h); i++){
    matriz[i][(int)((L/2-d/2)/h)] = -V0/2;
    matriz[i][(int)((L/2+d/2)/h)] = V0/2;
  }
  
  for(i=0; i<n; i++){
    matriz[i][0] = 0;
    matriz[i][n-1] = 0;
  }
  
  for(j=0; j<=n; j++){
    matriz[0][j] = 0;
    matriz[n-1][j] = 0;
  }


  //metodo de relajacion
  for(k=0; k<N; k++){
    for(i=1; i<n-1; i++){
      for(j=1; j<n-1; j++){
	if(j!=(int)((L/2-d/2)/h) && j!=(int)((L/2+d/2)/h)){
	  matriz[i][j]=0.25*(matriz[i+1][j]+matriz[i][j+1]+matriz[i-1][j]+matriz[i][j-1]);
	}
      }
    }
  }


  //calcula el campo electrico
  double **Ex;
  Ex = (double**) malloc(n*sizeof(double*));
  double **Ey;
  Ey = (double**) malloc(n*sizeof(double*));

  for (i=0; i<=n; i++){
    Ex[i] = (double*) malloc(n*sizeof(double));
    Ey[i] = (double*) malloc(n*sizeof(double));
  }

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      Ex[i][j]=(matriz[i][j]-matriz[i+1][j]);
      Ey[i][j]=(matriz[i][j]-matriz[i][j+1]);
    }
  }


  //imprime los valores del potencial y del campo
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      printf("%f\n", matriz[i][j]);
    }
  }
  
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      printf("%f\n", Ex[i][j]);
    }
  }

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      printf("%f\n", Ey[i][j]);
    }
  }


  return 0;

}
