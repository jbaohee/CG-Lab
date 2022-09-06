//g++ -c -o main.o main.cpp -I\"C:\mingw64\x86_64-w64-mingw32\include"

#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

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

void BoundaryFill(int x, int y, Color fillColor, Color boundaryColor) {
	Color currentColor = getPixelColor(x, y);

	if(currentColor.r != boundaryColor.r && currentColor.g != boundaryColor.g && currentColor.b != boundaryColor.b) {
		setPixelColor(x, y, fillColor);
		BoundaryFill(x+1, y, fillColor, boundaryColor);
		BoundaryFill(x-1, y, fillColor, boundaryColor);
		BoundaryFill(x, y+1, fillColor, boundaryColor);
		BoundaryFill(x, y-1, fillColor, boundaryColor);
	}
}

void onMouseClick(int button, int state, int x, int y)
{
	Color fillColor = {1.0f, 0.0f, 0.0f};		// red color will be filled
	Color boundaryColor = {0.0f, 0.0f, 0.0f};   // black- boundary

    int xc = (int) w/2;
	int yc = (int) h/2;
	Point p = {xc, yc}; // a point inside the circle

	BoundaryFill(p.x, p.y, fillColor, boundaryColor);
}

void draw_circle(Point pC, float radius) {
	float step = 1/radius; ///???
	float x, y;

	for(float theta = 0; theta <= 360; theta += step) {
		x = pC.x + (radius * cos(theta));
		y = pC.y + (radius * sin(theta));
        glColor3f(0,0,0);
		glVertex2i(x, y);
	}
}

void display(void) {
    int xc = (int) w/2;
	int yc = (int) h/2;

	Point pt = {xc, yc};
	float radius = 100;

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
	glutCreateWindow("Boundary Fill Algorithm");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}
