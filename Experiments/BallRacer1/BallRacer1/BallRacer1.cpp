//#define NDEBUG
//#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
double PI = 3.1415926;
GLfloat dist = 0.0;
static int rot1 = 0, rot2 = 0;
 void init(void)
 {
 	glClearColor (0.0, 0.0, 0.0, 0.0);
 	glShadeModel (GL_FLAT);

	cout << "Press key 'f' to go front" << endl;
	cout << "Press key 'b' to go back"   << endl;
 }

 void display(void)
 {
 	glClear (GL_COLOR_BUFFER_BIT);
 	glColor3f (1.0, 1.0, 1.0);
 	glPushMatrix(); 	
 	glTranslatef (dist, 0.0, 0.0);
 	glRotatef ((GLfloat)rot2, 0.0, 0.0, 1.0);
 	glutWireSphere(0.2, 10, 8); 
	//glutSolidSphere(0.2, 10, 8);
 	glPopMatrix();
 	glutSwapBuffers();
 }

 void reshape (int w, int h)
 {
 	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
 	glMatrixMode (GL_PROJECTION);
 	glLoadIdentity ();
 	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
 	glMatrixMode(GL_MODELVIEW);
 	glLoadIdentity();
 	gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
 }

 void keyboard (unsigned char key, int x, int y)
 {
 	switch (key) {
 case 'b':
	rot1 = rot1 + 10;
 	rot2 = rot1 % 360;
	dist = -(GLfloat)rot1 / 180 * PI * 0.2;
 	glutPostRedisplay();
 	break;
 case 'f':
	 rot1 = rot1 - 10;
	 rot2 = rot1 % 360;
	 dist = -(GLfloat)rot1 / 180 * PI * 0.2;
 	glutPostRedisplay();
 	break;
 case 27:
 	exit(0);
 	break;
 default:
 	break;
 	}
 }

 int main(int argc, char** argv)
 {
 	glutInit(&argc, argv);
 	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
 	glutInitWindowSize (500, 500);
 	glutInitWindowPosition (100, 100);
 	glutCreateWindow (argv[0]);
 	init ();
 	glutDisplayFunc(display);
 	glutReshapeFunc(reshape);
 	glutKeyboardFunc(keyboard);
 	glutMainLoop();
 	return 0;
 }