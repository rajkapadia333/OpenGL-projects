#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
float red=1.0f, blue=1.0f, green=1.0f;
float a=0.0f, b=0.0f, z=0.0f; 
float angle = 0.0f; 
float sceneroty = 0.0f;
float xrot = 0.0f;	
float yrot = 0.0f;
float deltaAngle = 0.0f;
float xOrigin = 0.0f;
float lx = 0.0f;
float lz = 0.0f;
float ly = 0.0f;


void changeSize(int w, int h) {
		if (h == 0)   // (you cant make a window of zero width).
		h = 1;
	float ratio =  w * 1.0 / h;      
	glMatrixMode(GL_PROJECTION);      // Use the Projection Matrix    
	glLoadIdentity();// Reset Matrix
	glViewport(0, 0, w, h);    // Set the viewport to be the entire window
	gluPerspective(45.0f, ratio, 0.1f, 500.0f);  // Set the correct perspective.
	glMatrixMode(GL_MODELVIEW);    // Get Back to the Modelview
}
void renderScene(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glLoadIdentity();   // Reset transformations
	gluLookAt(0.0f, 0.0f, 50.0f,      // Set the camera
			lx, ly,  lz,
			1.0f, 0.0f,  0.0f);
glRotatef(sceneroty, 0.0f, 1.0f, 0.0f);
glRotatef(ly,0.0f, 0.0f, 0.0f);
glTranslatef(a,b,z);
			
			//Hub
glPushMatrix();
glColor3f(0.75, 0.75, 1.0);
glutSolidSphere(5, 20, 20);
glPopMatrix();

glRotatef(angle, 0, 0, 1);

			//Rim Body
glPushMatrix();
glScalef(5, 5, 1);
glColor3f(0.1f, 0.1f, 0.2f);
glTranslatef(0.0f, 0.0f, 1.5f);
glutSolidSphere(3, 20, 20);
glPopMatrix();
			//Main Body
glPushMatrix();
glScalef(2, 2, 0.5);
glColor3f(0.1f, 0.1f, 0.2f);
glTranslatef(0.0f, 0.0f, 1.5f);
glutSolidTorus(3, 3, 20, 20);
glPopMatrix();
			//Hubward Lights
		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(10*cos(45), 10*sin(45), 0);
		glutSolidSphere(1, 20, 20);
		glPopMatrix();
	
		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(10*cos(135), 10*sin(135), 0);
		glutSolidSphere(1, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(10*cos(225), 10*sin(225), 0);
		glutSolidSphere(1, 20, 20);
		glPopMatrix();
			
		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(10*cos(90), 10*sin(90), 0);
		glutSolidSphere(1, 20, 20);
		glPopMatrix();
	
		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(10*cos(180), 10*sin(180), 0);
		glutSolidSphere(1, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(10*cos(270), 10*sin(270), 0);
		glutSolidSphere(1, 20, 20);
		glPopMatrix();
			
			//Landing Gear
		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(2*cos(45), 2*sin(45), 3);
		glutSolidCone(1, 3, 20, 20);
		glPopMatrix();
	
		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(2*cos(135), 2*sin(135), 3);
		glutSolidCone(1, 3, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glTranslatef(2*cos(225), 2*sin(225), 3);
		glutSolidCone(1, 3, 20, 20);
		glPopMatrix();

			//Rimward Lights
		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(13*cos(45), 13*sin(45), 0);
		glutSolidSphere(0.5, 20, 20);
		glPopMatrix();
	
		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(13*cos(135), 13*sin(135), 0);
		glutSolidSphere(0.5, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(13*cos(225), 13*sin(225), 0);
		glutSolidSphere(0.5, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(13*cos(90), 13*sin(90), 0);
		glutSolidSphere(0.5, 20, 20);
		glPopMatrix();
	
		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(13*cos(180), 13*sin(180), 0);
		glutSolidSphere(0.5, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.01-cos(red), 0.04+cos(green), 0.04+cos(blue));
		glTranslatef(13*cos(270), 13*sin(270), 0);
		glutSolidSphere(0.5, 20, 20);
		glPopMatrix();
			red+=0.05f;
			green-=0.05f;
			blue+=0.05f;
angle+=1.0f;
	
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {
	switch(key) 
{
case  27 :	exit(0);
case 'w' :	z+=0.3f;break;
case 's' :	z-=0.3f;break;
case 'd' :	a+=0.3f;break;
case 'a' :	a-=0.3f;break;

	}
}

void processSpecialKeys(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_F1 :
				red = 1.0;
				green = 0.0;
				blue = 0.0; break;
		case GLUT_KEY_F2 :
				red = 0.0;
				green = 1.0;
				blue = 0.0; break;
		case GLUT_KEY_F3 :
				red = 0.0;
				green = 0.0;
				blue = 1.0; break;
		case GLUT_KEY_F4 :
				red = 0.0;
				green = 0.0;
				blue = 0.0;; break;
		case GLUT_KEY_F5 :
				red = 1.0;
				green = 1.0;
				blue = 1.0;; break;
		case GLUT_KEY_F6 :
				red = 1.0;
				green = 1.0;
				blue = 0.0;; break;
		case GLUT_KEY_F7 :
				red = 1.0;
				green = 0.0;
				blue = 1.0;; break;
		case GLUT_KEY_F8 :
				red = 0.0;
				green = 1.0;
				blue = 1.0;; break;
		case GLUT_KEY_F9 :
				red = 2.0;
				green = 0.0;
				blue = 0.0;; break;
		case GLUT_KEY_F10 :
				red = 0.0;
				green = 2.0;
				blue = 0.0;; break;
		case GLUT_KEY_F11 :
				red = 0.0;
				green = 0.0;
				blue = 2.0;; break;
		case GLUT_KEY_F12 :
				red = 2.0;
				green = 2.0;
				blue = 2.0;; break;

case GLUT_KEY_LEFT : sceneroty  += 2.0f;break;
case GLUT_KEY_RIGHT : sceneroty -=2.0f;break;
case GLUT_KEY_UP: ly +=2.0f;break;
case GLUT_KEY_DOWN: ly -=2.0;break;

	}
}

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(1366,786);
	glutCreateWindow("ALIENS!!!");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	// here are the new entries
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

// here are the two new functions
	
	

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}

