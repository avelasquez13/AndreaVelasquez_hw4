#include <stdio.h>
#include <math.h>

int main(){

  int puntos = 100, tf = 200;
  float dx = 1.0/puntos, dt = 0.005, T = 40.0, rho = 10.0, c = sqrt(T/rho), r = c*dt/dx;

  float u0[puntos+1];
  float upast[puntos+1];
  
  int i;
  for(i=0; i<80; i++){
    u0[i] = 1.25*i/100;
    upast[i] = u0[i];
  }
  for(i=80; i<=puntos; i++){
    u0[i] = 5-5*i/(float)puntos;
    upast[i] = u0[i];
  }
 
  u0[0] = 0.0;
  u0[puntos] = 0.0;

  for(i=0; i<=puntos; i++){
    printf("%f\n", u0[i]);
  }

  upast[0] = 0.0;
  upast[puntos] = 0.0;


  float u1[puntos+1];
  float upresent[puntos+1];

  for(i=1; i<=puntos-1; i++){
    u1[i] = u0[i] + (pow(r,2)/2.0) * (u0[i+1] - 2.0*u0[i] + u0[i-1]);
    upresent[i] = u1[i];
  }
  
  u1[0] = 0.0;
  u1[puntos] = 0.0;

  upresent[0] = 0.0;
  upresent[puntos] = 0.0;


  int j;
  for(j=0; j<tf; j++){
    for(i=1; i<=puntos-1; i++){
      u1[i] = (2.0*(1.0-pow(r,2)))*upresent[i] - upast[i] + (pow(r,2))*(upresent[i+1] + upresent[i-1]);
    }for(i=1; i<=puntos-1; i++){
      upast[i] = upresent[i];
      upresent[i] = u1[i];
    }for(i=0; i<=puntos; i++){
      printf("%f\n", upresent[i]);
    }
  }
  
  
  return 0;

}
