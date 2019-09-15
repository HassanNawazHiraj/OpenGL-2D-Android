

#include <iostream>
#include <GL/freeglut.h>


void init(void);
void display(void);


int main(int argc, char** argv)
{
	//Step#1 Create and initialize glut windowing system
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Android/Robot");
	//Step#2 Do Open GL related initializations
	init();
	//Step#3 Register Call back methods or Event Handler methods
	glutDisplayFunc(display);
	//Step#4 Enter in  main loop (an infinite loop listening to registered events and then call their registered methods if any)
	glutMainLoop();
	return 0;
}

void init(void) {
	// select background color
	glClearColor(1.0, 1.0, 1.0, 0.0); // (red, green, blue, alpha), used by glClear

	// Define world coordinate frame
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // model in real word units 
		// (left, right, bottom, top, near, far)
}

void drawCircle(float cx, float cy, float r, int num_segments) {
	const float PI = 3.14159;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++) {
		float theta = i * (2.0f * PI / num_segments);
		float x = r * cos(theta);
		float y = r * sin(theta);
		glVertex2f(x + cx, y + cy);
	}
	glEnd();
}

void drawBox(float topLeftX, float topLeftY, float width, float height) {
	glBegin(GL_QUADS);
	glVertex3f(topLeftX, topLeftY, 0.0);
	glVertex3f(topLeftX + width, topLeftY, 0.0);
	glVertex3f(topLeftX + width, topLeftY + height, 0.0);
	glVertex3f(topLeftX, topLeftY + height, 0.0);
	glEnd();
}


void drawHeadSemiCircle() {
	glColor3ub(164,198,57);
	drawCircle(0.0, 0.4, 0.5, 60);
	glColor3ub(255, 255, 255);
	drawBox(-0.5, -0.1, 1.0, 0.5);
}

void drawEyes() {
	glColor3ub(255, 255, 255);
	drawCircle(-0.25, 0.65, 0.04, 30);
	drawCircle(0.25, 0.65, 0.04, 30);
}

void drawBody() {
	glColor3ub(164, 198, 57);
	drawBox(-0.5, -0.43, 1.0, 0.8);
	drawCircle(0.401, -0.41, 0.1, 30);
	drawCircle(-0.401, -0.41, 0.1, 30);
	drawBox(-0.425, -0.509, 0.85, 0.2);
}

void drawLegs() {
	drawBox(-0.3, -0.7, 0.25, 0.4);
	drawBox(0.05, -0.7, 0.25, 0.4);
	drawCircle(-0.175, -0.695, 0.124, 30);
	drawCircle(0.175, -0.695, 0.124, 30);
}

void drawHands() {
	drawBox(0.54, -0.1, 0.20, 0.4);
	drawBox(-0.74, -0.1, 0.20, 0.4);
	//left arm circles
	drawCircle(-0.639, -0.11, 0.099, 30);
	drawCircle(-0.639, 0.305, 0.099, 30);
	//right arm circles
	drawCircle(0.639, -0.11, 0.099, 30);
	drawCircle(0.639, 0.305, 0.099, 30);
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	drawHeadSemiCircle();
	drawEyes();
	drawBody();
	drawLegs();
	drawHands();
	//// door wall
	//glColor3f(0.0, 0.0, 1.0);
	//glBegin(GL_POLYGON);
	//glVertex3f(-0.9, -0.9, 0.0);
	//glVertex3f(-0.4, -0.9, 0.0);
	//glVertex3f(-0.4, 0.2, 0.0);
	//glVertex3f(-0.9, 0.2, 0.0);
	//glEnd();

	//// door
	//glColor3f(0.0, 1.0, 0.0);
	//glBegin(GL_POLYGON);
	//glVertex3f(-0.8, -0.9, 0.0);
	//glVertex3f(-0.5, -0.9, 0.0);
	//glVertex3f(-0.5, 0.0, 0.0);
	//glVertex3f(-0.8, 0.0, 0.0);
	//glEnd();

	//// wall
	//glColor3f(1.0, 0.0, 0.0);
	//glBegin(GL_POLYGON);
	//glVertex3f(-0.4, -0.9, 0.0);
	//glVertex3f(0.9, -0.9, 0.0);
	//glVertex3f(0.9, 0.2, 0.0);
	//glVertex3f(-0.4, 0.2, 0.0);
	//glEnd();

	//// door roof
	//glColor3f(0.3, 0.3, 0.0);
	//glBegin(GL_POLYGON);
	//glVertex3f(-0.9, 0.2, 0.0);
	//glVertex3f(-0.65, 0.9, 0.0);
	//glVertex3f(-0.4, 0.2, 0.0);
	//glVertex3f(-0.9, 0.2, 0.0);
	//glEnd();

	//// wall roof
	//glColor3f(0.5, 0.0, 0.5);
	//glBegin(GL_POLYGON);
	//glVertex3f(-0.65, 0.9, 0.0);
	//glVertex3f(0.65, 0.9, 0.0);
	//glVertex3f(0.9, 0.2, 0.0);
	//glVertex3f(-0.4, 0.2, 0.0);
	//glEnd();

	//glPointSize(10);		// Default size is 1 
	//glBegin(GL_POINTS); 	// Center is at the mid of main window due to glOrtho()
	//glVertex3f(0.0, 0.0, 0.0);
	//glEnd();

	//box(0.0, 0.0, 0.5, 0.2);
	glFlush();
}