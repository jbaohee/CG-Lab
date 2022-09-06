// g++ -c -o main.o main.cpp -I\"C:\mingw64\x86_64-w64-mingw32\include"

#include<windows.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <GL/glut.h>

using namespace std;

int w=1200, h=800;

double ortho_w= double (w/2);
double ortho_h= double (h/2);

struct Point {
	int x;
	int y;
};

struct Color {
	float r;
	float g;
	float b;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	//gluOrtho2D(-ortho_w,ortho_w,-ortho_h,ortho_h);
}

Color getPixelColor(int x, int y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(int x, int y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void floodFill(int x, int y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b )
	{
		setPixelColor(x, y, newColor);

		//4 connect
		floodFill(x+1, y, oldColor, newColor);
		floodFill(x, y+1, oldColor, newColor);
		floodFill(x-1, y, oldColor, newColor);
		floodFill(x, y-1, oldColor, newColor);
	}
	return;
}

void onMouseClick(int button, int state, int x, int y)
{
	Color newColor = {1.0f, 0.0f, 0.0f};  //to fill with red color
	Color oldColor = getPixelColor(x,y);
	int xc = (int) w/2;
	int yc = (int) h/2;
	floodFill(xc,yc, oldColor, newColor); //seed, old color, new color
}

void draw_circle(Point pC, float radius) {
	float step = 1/radius;
	float x, y;

	for(float theta = 0; theta <= 6.3; theta += (step*.1) ) {
		x = pC.x + (radius * cos(theta));
		y = pC.y + (radius * sin(theta));
		glColor3f(0,0,0);
		glVertex2i(x, y);
	}
}

void display(void) {
	int xc = (int) w/2;
	int yc = (int) h/2;

	Point pt = {xc,yc}; 
	float radius = 60;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	draw_circle(pt, radius);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(w,h);
	glutInitWindowPosition(200, 100);
	glutCreateWindow("Flood Fill");
	glutDisplayFunc(display);
	init();
	glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}
