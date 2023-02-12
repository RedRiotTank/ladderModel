#include <GL/glut.h>    
#include "practicasIG.h"
#include <math.h>

float Y=-0.8, rotE = 0;
int mode = GL_FILL;
bool ilumination = true;
bool normals = false;

void updateLadder(float y,float rot){

  Y = y;
  rotE = rot;

}

void setMode(int M) {
  mode = M;
}
/**
 * @brief Sets auxiliar normals state.
 * @param il true if auxiliar normals is active, false if not.
 * @author RedRiotTank
 */
void setNormals(bool n) {
  normals = n;
}

/**
 * @brief Returns axulirial normals state.
 * @return true if axuliar normals are activated.
 * @author RedRiotTank
 */
bool getNormals() {
  return normals;
}

/**
 * @brief Returns ilumination mode.
 * @return true if ilumination is active, false if not.
 * @author RedRiotTank
 */
bool getIlumination() {
  return ilumination;
}

/**
 * @brief Sets ilumination mode.
 * @param il true if ilumination is active, false if not.
 * @author RedRiotTank
 */
void setIlumination(bool il) {
  ilumination = il;
}

/**
 * @brief Calculates the normal of two vectors.
 * @param p normal 1.
 * @param n normal 2.
 * @author RedRiotTank
 */
vector3D calNormal(vector3D p, vector3D q){
  vector3D n;

  n.x = p.y * q.z - p.z * q.y;
  n.y = p.z * q.x - p.x * q.z;
  n.z = p.x * q.y - p.y * q.x;

  

  if (sqrt(pow(n.x, 2) + pow(n.y, 2) + pow(n.z, 2) != 1)) {
    float module = sqrt(pow(n.x, 2) + pow(n.y, 2) + pow(n.z, 2));
    n.x = (n.x) / module;
    n.y = (n.y) / module;
    n.z = (n.z) / module;
  }

  return n;
}

/**
 * @brief If normal is true, draw the line whose vector is vector3D and passes through the point p.
 * @param p the point.
 * @param n the vector (the normal).
 * @author RedRiotTank
 */
void setNormal(point p, vector3D n){
    if(normals){
      glBegin(GL_LINES);
      glVertex3f(p.x, p.y, p.z);
      glVertex3f(p.x + n.x , p.y+ n.y, p.z + n.z);
      glEnd();
    }
}

/**
 * @brief Given the points, obtain the director vectors p and q (reference).
 * @author RedRiotTank
 */
void dirVec(point pFijo, point pv1, point pv2, vector3D &p, vector3D &q){
  p.x = pv1.x - pFijo.x;
  p.y = pv1.y - pFijo.y;
  p.z = pv1.z - pFijo.z;

  q.x = pv2.x - pFijo.x;
  q.y = pv2.y - pFijo.y;
  q.z = pv2.z - pFijo.z;
}


/**
 * @brief Cube default constructor, default side = 1.
 * @author RedRiotTank
 */
Cube::Cube() {
    side = 1;
  }

/**
 * @brief Cube constructor whre you can set the side.
 * @param side length of the side
 * @note The ladder doesn't adapt to different cube sizes.
 * @author RedRiotTank
 */
Cube::Cube(float side) {
    this->side = side;
  }

/**
 * @brief Draws the cube on the xz plane with the center of the lower base at position [0,0,0].
 * @author RedRiotTank
 */
void Cube::draw() {
    point p1, p2, p3, p4, p5, p6, p7, p8; //Points.
    vector3D frontFace, leftFace, backFace, rightFace, supBase, infBase;  //normals for shadows.
    vector3D p,q; //Auxiliary vectors.

    p1 = {side/2, -side/2, side/2};
    p2 = {side/2, side/2, side/2};
    p3 = {-side/2, -side/2, side/2};
    p4 = {-side/2, side/2, side/2};
    p5 = {-side/2, -side/2, -side/2};
    p6 = {-side/2, side/2, -side/2};
    p7 = {side/2, -side/2, -side/2};
    p8 = {side/2, side/2, -side/2};

    glPolygonMode(GL_FRONT_AND_BACK, mode);
    glBegin(GL_QUAD_STRIP);
    {
      //frontFace
      dirVec(p1,p2,p4,p,q);
      frontFace = calNormal(p,q);
      glNormal3f(frontFace.x, frontFace.y, frontFace.z);
      glVertex3f(p1.x, p1.y, p1.z);
      glVertex3f(p2.x, p2.y, p2.z);
      glVertex3f(p3.x, p3.y, p3.z);
      glVertex3f(p4.x, p4.y, p4.z);

      //leftFace
      dirVec(p3,p4,p6,p,q);
      leftFace = calNormal(p,q);
      glNormal3f(leftFace.x, leftFace.y, leftFace.z);
      glVertex3f(p5.x, p5.y, p5.z);
      glVertex3f(p6.x, p6.y, p6.z);

      //backFace
      dirVec(p5,p6,p8,p,q);
      backFace = calNormal(p,q);
      glNormal3f(backFace.x, backFace.y, backFace.z);
      glVertex3f(p7.x, p7.y, p7.z);
      glVertex3f(p8.x, p8.y, p8.z);

      //rightFace
      dirVec(p7,p8,p2,p,q);
      rightFace = calNormal(p,q);
      glNormal3f(rightFace.x, rightFace.y, rightFace.z);
      glVertex3f(p1.x, p1.y, p1.z);
      glVertex3f(p2.x, p2.y, p2.z);
    }
    
    glEnd();

    glBegin(GL_QUADS);
    {
      //infBase
      dirVec(p7,p1,p3,p,q);
      infBase = calNormal(p,q);
      glNormal3f(infBase.x, infBase.y, infBase.z);
      glVertex3f(p1.x, p1.y, p1.z);
      glVertex3f(p3.x, p3.y, p3.z);
      glVertex3f(p5.x, p5.y, p5.z);
      glVertex3f(p7.x, p7.y, p7.z);
      
      //supBase
      dirVec(p2,p8,p6,p,q);
      supBase = calNormal(p,q);
      glNormal3f(supBase.x, supBase.y, supBase.z);
      glVertex3f(p2.x, p2.y, p2.z);
      glVertex3f(p8.x, p8.y, p8.z);
      glVertex3f(p6.x, p6.y, p6.z);
      glVertex3f(p4.x, p4.y, p4.z);
    }
    glEnd();
   
    setNormal( (p1+p2+p3+p4)/4.0,frontFace);
    setNormal( (p3+p4+p5+p6)/4.0,leftFace);
    setNormal( (p5+p6+p7+p8)/4.0,backFace);
    setNormal( (p7+p8+p1+p2)/4.0,rightFace);
    setNormal( (p2+p8+p6+p4)/4.0,supBase);
    setNormal( (p1+p7+p3+p5)/4.0,infBase);
    
  }

Cube cube;

void initModel() {
  cube = Cube();  //Initialize the cube.
}

/**
 * @brief Axes class.
 * @author RedRiotTank
 */
class Axes: Objeto3D {
  public: float longitud = 30;
  void draw() {
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES); {
      glColor3f(0, 1, 0);
      glVertex3f(0, 0, 0);
      glVertex3f(0, longitud, 0);

      glColor3f(1, 0, 0);
      glVertex3f(0, 0, 0);
      glVertex3f(longitud, 0, 0);

      glColor3f(0, 0, 1);
      glVertex3f(0, 0, 0);
      glVertex3f(0, 0, longitud);
    }
    glEnd();
    glEnable(GL_LIGHTING);

  }
};

/**
 * @brief Creates the bar (sides of the ladder).
 * @author RedRiotTank
 */
void Ladder::bar(){
  glPushMatrix();
      glScalef(0.02,0.8,0.02);
      glTranslatef(0,0.5,0);
      cube.draw();
  glPopMatrix();

}

/**
 * @brief Creates the step form.
 * @author RedRiotTank
 */
void Ladder::step(){
  glPushMatrix();
      glScalef(0.02,0.02,0.5);
     glTranslatef(0,0.5,0);
      cube.draw();
    glPopMatrix();
}

/**
 * @brief Creates and translate multiple instances of step to make steps.
 * @author RedRiotTank
 */
void Ladder::steps(){
  glPushMatrix();
    glTranslatef(0,0.1,0);
    step();

    glTranslatef(0,0.2,0);
    step();

    glTranslatef(0,0.2,0);
    step();

    glTranslatef(0,0.2,0);
    step();

  glPopMatrix();
}

/**
 * @brief Create a single ladder structure.
 * @author RedRiotTank
 */
void Ladder::sladder(){
  glPushMatrix();
    glTranslatef(0,0,-0.25);
    this->bar();

    glTranslatef(0,0,0.5);
    bar();
  glPopMatrix();

  glPushMatrix();
    steps();
  glPopMatrix();
}

/**
 * @brief Creates full ladder structure (movable).
 * @author RedRiotTank
 */
void Ladder::structure(){
  
  glPushMatrix();
    glTranslatef(0,Y,0);
    sladder();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.02,0,0);
    sladder();
  glPopMatrix();

}

/**
 * @brief Creates the full ladder structure (normal and inverse of the structure).
 * @author RedRiotTank
 */
Ladder::Ladder(){}
void Ladder::draw(){

glScalef(2,2,2);
  glTranslatef(-1.14,1.1,-0.24);
  
    glPushMatrix();
      glRotatef(45,0,0,1);
      glTranslatef(0,-0.8,0);
      structure();
    glPopMatrix();

    glPushMatrix();
      glRotatef(rotE,0,0,1);
      glTranslatef(0,-0.8,0);
      glRotatef(180,0,1,0);
      structure();
    glPopMatrix();
}

Ladder ladder;

Axes axes;

void Dibuja(void) {
  //Light position:
  static GLfloat pos[4] = {5.0, 5.0, 10.0, 0.0}; 
  static GLfloat p1[4] = {0.0, 0.0, -3.0, 0.0};
  static GLfloat p2[4] = {-3.0, 0, -3.0, 0};
  static GLfloat p3[4] = {-2.0, 2.0, 0.0, 0};


  glPushMatrix(); // Stacks the current geometric transformation
  glClearColor(0.0, 0.0, 0.0, 1.0); // Set the background color to black
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Initialize the color buffer and the Z-Buffer
  transformacionVisualizacion(); // Load display transformation
  glLightfv(GL_LIGHT0, GL_POSITION, pos); // Light declaration. Placed here is fixed on the scene

  axes.draw(); // Draw axes.

  if (mode == GL_FILL) 
    if (ilumination) 
      glEnable(GL_LIGHTING);
     else 
      glDisable(GL_LIGHTING);

      ladder.draw();
  

  glPopMatrix(); // Unstack the geometric transformation
  glutSwapBuffers(); // Swap the draw and display buffers
}

//Idle is the background procedure. It is called by glut when there are no pending events.
void idle(int v) {
    
  glutPostRedisplay(); // Redibuja
  glutTimerFunc(30, idle, 0); // Vuelve a activarse dentro de 30 ms
  
}