#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>		
#include "practicasIG.h"


float view_rotx = 30, view_roty = 45;

float D = 10;

bool frustum = 2;

float anchoVentana, altoVentana;

float x_camara = 0, y_camara = 0, z_camara = 0;

void setFrustum(bool frust){
  frustum = frust;
}

void reiniciar(){
  x_camara = 0;
  y_camara = 0;
  z_camara = 0;
  view_rotx = 30;
  view_roty = 45;

}

void moveCameraW(){
  double x = cos(view_rotx*M_PI/180) * sin(view_roty*M_PI/180);
  double y = sin(view_rotx*M_PI/180);
  double z = cos(view_rotx*M_PI/180) * cos(view_roty*M_PI/180);

  x_camara-=x;
  y_camara+=y;
  z_camara+=z;

}

void moveCameraS(){
  double x = cos(view_rotx*M_PI/180) * sin(view_roty*M_PI/180);
  double y = sin(view_rotx*M_PI/180);
  double z = cos(view_rotx*M_PI/180) * cos(view_roty*M_PI/180);

  x_camara+=x;
  y_camara-=y;
  z_camara-=z;
}
void moveCameraD(){
  double x = cos(view_rotx*M_PI/180) * cos(view_roty*M_PI/180);
  double y = sin(view_rotx*M_PI/180);
  double z = cos(view_rotx*M_PI/180) * sin(view_roty*M_PI/180);

  x_camara-=x;
  z_camara-=z;
}
void moveCameraA(){
   double x = cos(view_rotx*M_PI/180) * cos(-view_roty*M_PI/180);
   double z = cos(view_rotx*M_PI/180) * sin(view_roty*M_PI/180);
   
  x_camara+=x;
  z_camara+=z;
}

int rotX,rotY;

void setC(int x, int y){
  rotX = x;
	rotY = y;
}

void girarCamara(int x, int y){
  view_roty=view_roty-(x-rotX);
  view_rotx=view_rotx+(y-rotY);
  setC(x,y);
  
}

void setCamara (float ax, float ay, float d){
  view_rotx = ax;
  view_roty = ay;

  D = d;
}

void transformacionVisualizacion (){
  glTranslatef (0, 0, -D);
    
  glRotatef (view_rotx, 1.0, 0.0, 0.0);
  glRotatef (view_roty, 0.0, 1.0, 0.0);

  glTranslatef(x_camara,y_camara,z_camara);
}

void fijaProyeccion (){
  float calto;			

  if (anchoVentana > 0)
    calto = altoVentana / anchoVentana;
  else
    calto = 1;

  if(frustum)
    glFrustum (-1, 1, -calto, calto, 1.5, 1500);
  else
    glOrtho(-1,1,-calto,calto,1.5,1500);

  

  glMatrixMode (GL_MODELVIEW);   
  glLoadIdentity ();

}

void inicializaVentana (GLsizei ancho, GLsizei alto){
  altoVentana = alto;
  anchoVentana = ancho;

  glViewport (0, 0, ancho, alto);	

  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();

  fijaProyeccion ();

}
