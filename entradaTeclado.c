
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>	
#include "practicasIG.h"
#include "visual.h"


float rotxCamara = 30, rotyCamara = 45;
float dCamara = 10;

float Yentrada = -0.8, rotentrada = 0;

void letra (unsigned char k, int x, int y)
{
  
  switch (k){
    case '+':			
      dCamara -= 1;
    break;
    case '-':			
      dCamara += 1;
    break;

    case 'p':
    case'P':
      setMode(GL_POINT);
    break;

    case 'l':
    case'L':
      setMode(GL_LINE);
    break;

    case 'f':
    case'F':
      setMode(GL_FILL);
    break;

    case 'i':
    case'I':
      if(getIlumination())
        setIlumination(false);
      else
        setIlumination(true);
    break;

    case 'o':
    case 'O':
      if(getNormals())
        setNormals(false);
      else
        setNormals(true);
    break;

    case 'n':
      if(rotentrada <= 40)
        rotentrada += 2;
    break;
    case 'N':
    if(rotentrada >= -70)
      rotentrada-=2;
    break;

    case 'm':
      if(Yentrada<= 0)
        Yentrada+=0.1;
    break;
    case 'M':
      if(Yentrada>= -0.8)
        Yentrada-=0.1; 
    break;
    
  

    //Práctica 5

    case 'w':
      moveCameraW();
    break;

    case 's':
      moveCameraS();
    break;

    case 'a':
      moveCameraA();
    break;

    case 'd':
      moveCameraD();
    break;

    case 'r':
      reiniciar();
    break;



    case 27:			// Escape  Terminar
      exit (0);
    default:
      return;
    }

  updateLadder(Yentrada,rotentrada);
  setCamara (rotxCamara, rotyCamara, dCamara);
  
  glutPostRedisplay ();		
}				

void especial (int k, int x, int y)
{

  switch (k)
    {
    case GLUT_KEY_UP:
      rotxCamara += 5.0;	
      if (rotxCamara > 360)
	      rotxCamara -= 360;
    break;

    case GLUT_KEY_DOWN:
      rotxCamara -= 5.0;
      if (rotxCamara < 0)
	      rotxCamara += 360;
    break;

    case GLUT_KEY_LEFT:
      rotyCamara += 5.0;
      if (rotyCamara > 360)
	      rotyCamara -= 360;
    break;

    case GLUT_KEY_RIGHT:
      rotyCamara -= 5.0;
      if (rotyCamara < 0)
	      rotyCamara += 360;
    break;

    case GLUT_KEY_PAGE_DOWN:	
      dCamara -= 5.0;
    break;

    case GLUT_KEY_PAGE_UP:	
      dCamara += 5.0;
    break;

    case GLUT_KEY_F1:
      setFrustum(false);
      rotxCamara = 90;
      rotyCamara = 0;
      dCamara = 5;
    break;

    case GLUT_KEY_F2:
      setFrustum(true);
      rotxCamara = 0;
      rotyCamara = -90;
      dCamara = 5;
    break;

    case GLUT_KEY_F3:
      setFrustum(true);
      rotxCamara = 0;
      rotyCamara = 0;
      dCamara = 5;
    break;

    default:
      return;
    }
  setCamara (rotxCamara, rotyCamara, dCamara);
  glutPostRedisplay ();		
}
