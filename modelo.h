#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

/**
	Funcion de redibujado. Se ejecuta con los eventos postRedisplay
**/
void Dibuja (void);

/**
	Funcion de fondo
**/
void idle (int v);

/**
	Funcion de inicializacion del modelo y de las variables globales
**/
void initModel ();


void setMode(int M);
void setNormals(bool n);
bool getNormals();
void setIlumination(bool il);
bool getIlumination();

void updateLadder(float y, float rot);

struct point {
  float x;
  float y;
  float z;

	point operator+(point p){
		point sol;
		sol.x = x + p.x;
		sol.y = y + p.y;
		sol.z = z + p.z;

		return sol;
	}

	point operator-(point p){
		point sol;
		sol.x = x - p.x;
		sol.y = y - p.y;
		sol.z = z - p.z;

		return sol;
	}

	point operator/(float n){
		point sol;
		sol.x = x / n;
		sol.y = y / n;
		sol.z = z / n;

		return sol;
	}

};

struct vector3D {
  float x;
  float y;
  float z;

  vector3D operator+=(vector3D p){
		vector3D sol;
		sol.x = x + p.x;
		sol.y = y + p.y;
		sol.z = z + p.z;

		return sol;
	}
};

class Objeto3D{ 

	public: 

	virtual void draw( ) = 0; // Dibuja el objeto

	void inicializarPuntos();

}; 

/**
 * @brief This class defines and draw the initial cube.
 * @author RedRiotTank
 */
class Cube: public Objeto3D{
	public: 
	
	float side;
	
	Cube();
	Cube(float side);
	void draw();

};

/**
 * @brief This class defines and draw the ladder
 * @author RedRiotTank
 */
class Ladder: public Objeto3D{
	public:
	
	Ladder();
	void bar();
	void step();
	void steps();
	void sladder();
	void structure();
	void draw();

};

