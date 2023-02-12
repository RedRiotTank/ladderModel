#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>		
#include "practicasIG.h"
#include "visual.h"


int estMouse = 0;

void clickRaton (int boton, int estado, int x, int y){
	if(boton == GLUT_LEFT_BUTTON){
		estMouse = 1;
	}
	else estMouse = 0;
		
	setC(x,y);
}

void RatonMovido (int x, int y){
	if(estMouse == 1)
		girarCamara(x,y);
	
}
