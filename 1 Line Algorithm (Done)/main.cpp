//g++ -c -o main.o main.cpp -I\"C:\mingw64\x86_64-w64-mingw32\include"


#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<bits/stdc++.h>

using namespace std;

void init();
void display();
void draw_cartesian();

float xstart, ystart, xend, yend;

int main(int argc, char**argv)
{
    cout<<"Enter Starting X Y coordinate :";
    cin>>xstart>>ystart;
    cout<<"Enter Terminal X Y coordinate :";
    cin>>xend>>yend;

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200,100);
    glutInitWindowSize(1200,800);
    glutCreateWindow("DDA Line Algorithm");

    glutDisplayFunc(display);
    init();
    glutMainLoop();
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glPointSize(3.0);
    glLineWidth(2.0);
    gluOrtho2D(-600,600,-400,400);
}

void display()

{
    float dx = xend-xstart;
    float dy = yend-ystart;

    float m = dy/dx;

    float x = xstart;
    float y = ystart;

    draw_cartesian();

    if (m<=1)
    {
        while (x<=xend) {
            x = x+1;
            y = y+m;

            glBegin(GL_POINTS);
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(x,y);
            glEnd();
            glFlush();
        }
    }
    else if (m>1)
    {
        while (y<=yend) {
            x = x + 1/m;
            y = y+1;

            glBegin(GL_POINTS);
            glColor3f(1.0, 0.0, 0.0);
            glVertex2f(x,y);
            glEnd();
            glFlush();
        }
    }

}

void draw_cartesian()
{
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0); 
    glVertex2f(0,380);
    glVertex2f(0,-380);
    glEnd();
    glFlush();

    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(580,0);
    glVertex2f(-580,0);
    glEnd();
    glFlush();
}