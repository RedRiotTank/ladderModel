#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>		
#include "practicasIG.h"


int main (int argc, char *argv[]){

  glutInit (&argc, argv);
  glutInitWindowPosition (0, 0);
  glutInitWindowSize (800, 800);
  glutInitDisplayMode (GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
  glutCreateWindow ("IG. Curso 2022/23. Autor: Alberto Plaza");

  initModel ();

  glutDisplayFunc (Dibuja);
  glutReshapeFunc (inicializaVentana);


  glutKeyboardFunc (letra);
  glutSpecialFunc (especial);

  glutMouseFunc (clickRaton);
  glutMotionFunc (RatonMovido);

  glutTimerFunc (30, idle, 0);

  glEnable (GL_DEPTH_TEST);
  glEnable (GL_CULL_FACE);
  glEnable (GL_LIGHTING);
  glEnable (GL_LIGHT0);

  glutMainLoop ();
  return 0;
}
