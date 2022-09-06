// g++ -c -o main.o main.cpp -I\"C:\mingw64\x86_64-w64-mingw32\include"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <windows.h>
#include <time.h>

using namespace std;

int w=1200, h=800;
float xc, yc, r;
double ortho_w= double (w/2);
double ortho_h= double (h/2);

void init();
void display();
void draw_cartesian();


int main(int argc, char**argv)
{

    cout<<"Enter Center [CENTER X Y MUST BE SAME; X==Y]: ";
    cin>>xc>>yc;

    cout<<"Enter radius : ";
    cin>>r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Midpoint Cirlce");

    glutDisplayFunc(display);
    init();
    glutMainLoop();
    
}

void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-ortho_w,ortho_w,-ortho_h,ortho_h);
    glLineWidth(2.0);
}

void display()
{
    draw_cartesian();
    
    float x=0;
    float y=r;
    float pk= 5/4-r;

    glPointSize(10.0);
    glBegin(GL_POINTS);
    glColor3f(0.0,0.0,1.0); 
    glVertex2f(xc,yc);
    glEnd();
    glFlush();

    glPointSize(2.0);
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0); 
    while (x<=y)
    {
        if (pk<0)
        {
            x++;
            pk = pk + 2*x + 3;
        }
        else
        {
            x++;
            y--;
            pk = pk + 2*x - 2*y + 5;
        }
        
        glVertex2f(x+xc,y+yc);
        glVertex2f(y+yc,x+xc);
        glVertex2f(x+xc,-y+yc);
        glVertex2f(y+yc,-x+xc);
        glVertex2f(-y+yc,-x+xc);
        glVertex2f(-x+xc,-y+yc);
        glVertex2f(-x+xc,y+yc);
        glVertex2f(-y+yc,x+xc);
        
        /*
        float x_n = x + xc;
        float y_n = y + yc;
        glVertex2f(x_n,y_n);
        glVertex2f(y_n,x_n);
        glVertex2f(x_n,-y_n);
        glVertex2f(y_n,-x_n);
        glVertex2f(-y_n,-x_n);
        glVertex2f(-x_n,-y_n);
        glVertex2f(-x_n,y_n);
        glVertex2f(-y_n,x_n);
        */

    }
    glEnd();
    glFlush();
    
}

void draw_cartesian()
{
    //For Y axis
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f(0,(h/2-10));
    glVertex2f(0,-(h/2-10));
    glEnd();
    glFlush();

    //For X axis
    glBegin(GL_LINES);
    glColor3f(0.0,0.0,0.0);
    glVertex2f((w/2-20),0);
    glVertex2f(-(w/2-20),0);
    glEnd();
    glFlush();
}
