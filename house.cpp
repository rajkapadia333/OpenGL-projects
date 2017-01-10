#define _USE_MATH_DEFINES
#include <cmath>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float red=1.0f, blue=1.0f, green=1.0f;
float rings = 1000;
float sectors = 1000;
float R = 1/(float)(rings-1);
float S = 1/(float)(sectors-1);

float a=0.0f, b=0.0f, z=0.0f; // angle for rotating triangle
float angle = 0.0f;
void changeSize(int w, int h) {
    if (h == 0)   // (you cant make a window of zero width).
        h = 1;
    float ratio =  w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);      // Use the Projection Matrix
    glLoadIdentity();// Reset Matrix
    glViewport(0, 0, w, h);    // Set the viewport to be the entire window
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);  // Set the correct perspective.
    glMatrixMode(GL_MODELVIEW);    // Get Back to the Modelview
}
void renderScene(void) {
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();   // Reset transformations
    gluLookAt(0.0f, 0.0f, 50.0f,      // Set the camera
              0.0f, 0.0f,  0.0f,
              0.0f, 1.0f,  0.0f);
    
    // ____________________________________*******_____________________________________*********___________________________//

    //Sun

for(int r = 0; r < rings; r++)
    {
        glBegin(GL_POLYGON);
        glPushMatrix();
        glColor3ub(30, 151, 24);
        glTranslatef(a, b, z);
        glScalef(15, 15, 15);
        
        for(int s = 0; s < sectors; s++)
        {
            float X = sin(r * ((2 * M_PI)/(rings - 1)))*cos(s * ((2 * M_PI)/(sectors - 1)));
            float Y = sin(r * ((2 * M_PI)/(rings - 1)))*sin(s * ((2 * M_PI)/(sectors - 1)));
            float Z = cos(r * ((2 * M_PI)/(rings - 1)));
            glVertex3f( (4*X)-15, (4*Y)+27, 4*Z);
            
        }
        glEnd();
    }
    
    //base of the hut
    glColor3ub(169, 142, 142);
    glTranslatef(a,b-1,z);
    glutSolidCube(2.0);
    
    //roofhut
    glBegin( GL_TRIANGLES );
    
    glColor3ub(232, 214, 214);

    glVertex3f( 0.0f, 3.0f, 0.0f);
    glVertex3f( -1.0f, 1.0f, 1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    
    glVertex3f( 0.0f, 3.0f, 0.0f);
    glVertex3f( -1.0f, 1.0f, 1.0f);
    glVertex3f( 0.0f, 1.0f, -1.0f);
    
    glVertex3f( 0.0f, 3.0f, 0.0f);
    glVertex3f( 0.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    
    
    glVertex3f( -1.0f, 1.0f, 1.0f);
    glVertex3f( 0.0f, 1.0f, -1.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);
    
    glEnd();
    
    //top windowhut
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(-0.5, 0, 1.1);
    glVertex3f(-0.5, 0.5, 1.1);
    glVertex3f(0.5, 0.5, 1.1);
    glVertex3f(0.5, 0.0, 1.1);
    glEnd();
    
    //doorhut
    glPushMatrix();
    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 0, 0);
    glVertex3f(-0.2, -0.5, 1.1);
    glVertex3f(-0.2, -1.0, 1.1);
    glVertex3f(0.2, -0.5, 1.1);
    glVertex3f(0.2, -1.0, 1.1);
    glPopMatrix();
    glEnd();
    
    //lawn
    glPushMatrix();
    glBegin(GL_QUAD_STRIP);
    glColor3ub(0, 255, 0);
    glVertex3f(-7000, 0, -10);
    glVertex3f(-7000, -100, 15);
    glVertex3f(200, 0, -10);
    glVertex3f(300, -100, 15); 

 //   glColor3ub(0, 0, 255);
   // glVertex3f(-301, -101, -10);
   // glVertex3f(-301, 0, 15);
    //glVertex3f(-5000, -101, -10);
   // glVertex3f(-5000, 0, 15);
    glPopMatrix();
    glEnd();
    
    //Sky
    glPushMatrix();
    glBegin(GL_QUAD_STRIP);
    glColor3ub(0, 0, 255);
    glVertex3f(-7000, -650, 100);
    glVertex3f(-7000, 100, -100);
    glVertex3f(7000, -650, -100);
    glVertex3f(7000, 100, 100);
    glPopMatrix();
    glEnd();
    
    //fencing
    glPushMatrix();
    glColor3ub(100, 100, 0);
    glBegin(GL_QUAD_STRIP);
    glVertex3f(-100, 0, -8);
    glVertex3f(100, 0, -8);
    glVertex3f(-100, -1, -8);
    glVertex3f(100, -1, -8);
    glPopMatrix();
    glEnd();
    
    
    //Mansion
    
    //back wall
    glPushMatrix();
    glColor3ub(141, 176, 128);
    glBegin(GL_QUAD_STRIP);
    glVertex3f(-3,- 2, -5);
    glVertex3f(-20, -2, -5);
    glVertex3f(-3, 15, -5);
    glVertex3f(-20, 15, -5);
    
    //front facade
    glVertex3f(-3, -2,5);
    glVertex3f(-20, -2, 5);
    glVertex3f(-3, 15, 5);
    glVertex3f(-20, 15, 5);
    
    //side walls
    glColor3ub(141, 176, 128);
    glVertex3f(-20, -2, 5);
    glVertex3f(-20, 15, 5);
    glVertex3f(-30, -2, 2);
    glVertex3f(-30, 15, 2);
    glPopMatrix();
    
    //far side wall
    glColor3ub(178, 176 , 128);
    glVertex3f(-34, -2, 2);
    glVertex3f(-34, 15, 2);
    glVertex3f(-30, -2, 2);
    glVertex3f(-30, 15, 2);
    
    //definite side wall left
    glVertex3f(-34, -2, 2);
    glVertex3f(-34, 15, 2);
    glVertex3f(-37, -2, -5);
    glVertex3f(-37, 15, -5);
    
    glVertex3f(-20, -2, -5);
    glVertex3f(-37, -2, -5);
    glVertex3f(-20, 15, -5);
    glVertex3f(-37, 15, -5);
    
    //definite side wall right
    glColor3ub(178, 176, 128);
    glVertex3f(-3, -2, 5);
    glVertex3f(-3, 15, -5);
    glVertex3f(-3, -2, -5);
    glVertex3f(-3, 15, 5);
    glEnd();
    
    //small piece of wall beside the garage(right)
    glBegin(GL_QUAD_STRIP);
    glColor3ub(141, 136, 128);
    glVertex3f(-4,-2, 15);
    glVertex3f(-4, 7, 15);
    glVertex3f(-3, -2, 5);
    glVertex3f(-3, 7, 5);
    glEnd();
    
    //roof of garage
    glBegin(GL_QUAD_STRIP);
    glColor3ub(178,176, 128);
    glVertex3f(-4, 7, 15);
    glVertex3f(-4, 7, 5);
    glVertex3f(-15, 7, 15);
    glVertex3f(-15, 7, 5);
    glEnd();

    //left side of garage
    glBegin(GL_QUAD_STRIP);
    glColor3ub(141, 136, 128);
    glVertex3f(-15,-2, 15);
    glVertex3f(-15, 7, 15);
    glVertex3f(-15, -2, 5);
    glVertex3f(-15, 7, 5);
    glEnd();

    
    //garage
    glPushMatrix();
    glBegin(GL_QUAD_STRIP);
    glColor3ub(141, 136, 128);
    glVertex3f(-4, -2, 15);
    glVertex3f(-15, -2, 15);
    glVertex3f(-4, 7, 15);
    glVertex3f(-15, 7,15);
    glPopMatrix();
    glEnd();
    
    //garage door
    glPushMatrix();
    glBegin(GL_QUAD_STRIP);
    glColor3ub(255, 200, 200);
    glVertex3f(-14.7, -2, 15.01);
    glVertex3f(-14.7, 6.3, 15.01);
    glVertex3f(-4.3, -2, 15.01);
    glVertex3f(-4.3, 6.3, 15.01);
    glPopMatrix();
    glEnd();
    
    //Main door on the side
    
    //door frame
    glBegin(GL_QUAD_STRIP);
    glColor3ub(193, 167, 125);
    glVertex3f(-16, -2, 5.02);
    glVertex3f(-16, 5, 5.02);
    glVertex3f(-21, -2, 5.02);
    glVertex3f(-21, 5, 5.02);
    glEnd();
    
    //door window
    glBegin(GL_QUAD_STRIP);
    glColor3ub(167, 215,220);
    glVertex3f(-17, 4, 5.03);
    glVertex3f(-17, 2, 5.03);
    glVertex3f(-20, 4, 5.03);
    glVertex3f(-20, 2, 5.03);
    glEnd();
    
    //door knob
    glColor3ub(255, 255, 255);
    glTranslatef(-16.7, 0.7, 5.03);
    glutSolidSphere(0.15, 100, 100);
    
    //window above garage
    glBegin(GL_QUAD_STRIP);
    glColor3ub(167, 215,220);
    glVertex3f(12, 7, 5.03);
    glVertex3f(2, 7, 5.03);
    glVertex3f(12, 12, 5.03);
    glVertex3f(2, 12, 5.03);
    glEnd();



   //trees begin
   glBegin(GL_POLYGON);
   glColor3ub(175,151,32);
   glVertex3f(-41,7,0);
   glVertex3f(-41,-5,0);
   glVertex3f(-38,-5,0);
   glVertex3f(-38,7,0);
   glEnd();

for(int r = 0; r < rings; r++)
    {
        glBegin(GL_POLYGON);
        glPushMatrix();
        glColor3ub(30, 151, 24);
        glTranslatef(a, b, z);
        glScalef(15, 15, 15);
        
        for(int s = 0; s < sectors; s++)
        {
            float X = sin(r * ((2 * M_PI)/(rings - 1)))*cos(s * ((2 * M_PI)/(sectors - 1)));
            float Y = sin(r * ((2 * M_PI)/(rings - 1)))*sin(s * ((2 * M_PI)/(sectors - 1)));
            float Z = cos(r * ((2 * M_PI)/(rings - 1)));
            glVertex3f( (4*X)-39.5, (4*Y)+7, 4*Z);
            
        }
        glEnd();
    }

glBegin(GL_POLYGON);
   glColor3ub(175,151,32);
   glVertex3f(-45,7,0);
   glVertex3f(-45,-5,0);
   glVertex3f(-42,-5,0);
   glVertex3f(-42,7,0);
   glEnd();

for(int r = 0; r < rings; r++)
    {
        glBegin(GL_POLYGON);
        glPushMatrix();
        glColor3ub(30, 151, 24);
        glTranslatef(a, b, z);
        glScalef(15, 15, 15);
        
        for(int s = 0; s < sectors; s++)
        {
            float X = sin(r * ((2 * M_PI)/(rings - 1)))*cos(s * ((2 * M_PI)/(sectors - 1)));
            float Y = sin(r * ((2 * M_PI)/(rings - 1)))*sin(s * ((2 * M_PI)/(sectors - 1)));
            float Z = cos(r * ((2 * M_PI)/(rings - 1)));
            glVertex3f( (4*X)-43.5, (4*Y)+7, 4*Z);
            
        }
        glEnd();
    }
   //trees end

    angle+=0.51f;
    glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int x, int y) {
    switch(key) {
        case  27 :	exit(0);
            
        case 'w' : z++;break;
        case 's' : z--;break;
        case 'a' : a++;break;
        case 'd' : a--;break;
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
    }
}

int main(int argc, char **argv) {
    
    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Earth");
    
    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    
    // here are the new entries
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);
    
    // enter GLUT event processing cycle
    glutMainLoop();
    
    return 1;
}
