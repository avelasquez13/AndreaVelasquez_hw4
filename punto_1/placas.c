#include <stdio.h>
#include <stdlib.h>

int main(){

  float L = 5, l = 2, d = 1, h = 0.02, V0 = 100;
  int N = 100;

  //inicializa la matriz
  int i, j, k;
  
  double **matriz;
  matriz = (double**) malloc((int)(L/h)*sizeof(double*));

  for (i=0; i<=(int)(L/h); i++){
    matriz[i] = (double*) malloc((int)(L/h)*sizeof(double));
  }

  for(i=0; i<(int)(L/h); i++){
    for(j=0; j<(int)(L/h); j++){
      matriz[i][j]=1;
    }
  }

  for(i=(int)((L/2-l/2)/h); i<(int)((L/2+l/2)/h); i++){
    matriz[i][(int)((L/2-d/2)/h)] = -V0/2;
    matriz[i][(int)((L/2+d/2)/h)] = V0/2;
  }
  
  for(i=0; i<(int)(L/h); i++){
    matriz[i][0] = 0;
    matriz[i][(int)(L/h)] = 0;
  }
  
  for(j=0; j<(int)(L/h); j++){
    matriz[0][j] = 0;
    matriz[(int)(L/h)][j] = 0;
  }
  

  //metodo de relajacion
  for(k=0; k<N; k++){
    for(i=1; i<(int)(L/h)-1; i++){
      for(j=1; j<(int)(L/h)-1; j++){
	if(j!=(int)((L/2-d/2)/h) && j!=(int)((L/2+d/2)/h)){
	  matriz[i][j]=0.25*(matriz[i+1][j]+matriz[i][j+1]+matriz[i-1][j]+matriz[i][j-1]);
	}
      }
    }
  }


  //calcula el campo electrico
  double **Ex;
  Ex = (double**) malloc((int)(L/h)*sizeof(double*));
  double **Ey;
  Ey = (double**) malloc((int)(L/h)*sizeof(double*));

  for (i=0; i<=(int)(L/h); i++){
    Ex[i] = (double*) malloc((int)(L/h)*sizeof(double));
    Ey[i] = (double*) malloc((int)(L/h)*sizeof(double));
  }

  for(i=0; i<(int)(L/h); i++){
    for(j=0; j<(int)(L/h); j++){
      Ex[i][j]=(matriz[i][j]-matriz[i+1][j]);
      Ey[i][j]=(matriz[i][j]-matriz[i][j+1]);
    }
  }


  //imprime los valores del potencial y del campo
  for(i=0; i<(int)(L/h); i++){
    for(j=0; j<(int)(L/h); j++){
      printf("%f\n", matriz[i][j]);
    }
  }

  for(i=0; i<(int)(L/h); i++){
    for(j=0; j<(int)(L/h); j++){
      printf("%f\n", Ex[i][j]);
    }
  }

  for(i=0; i<(int)(L/h); i++){
    for(j=0; j<(int)(L/h); j++){
      printf("%f\n", Ey[i][j]);
    }
  }


  /*
  printf("%f %f\n", matriz[(int)((L/2)/h)][(int)(L/h)], matriz[(int)(L/h)][(int)((L/2+d/2)/h)]);
  printf("%f %f\n", matriz[(int)((L/2)/h)][0], matriz[0][(int)((L/2+d/2)/h)]);
  printf("%f %f\n", matriz[(int)((L/2)/h)][(int)((L/2-d/2)/h)], matriz[(int)(L/(2*h))][(int)((L/2+d/2)/h)]);
  
  for(i=0; i<(int)(L/h); i++){
    for(j=0; j<(int)(L/h); j++){
      printf("%f\t", matriz[i][j]);
    }printf("\n");
  }
  */


  return 0;

}
