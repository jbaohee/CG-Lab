// g++ -c -o main.o main.cpp -I\"C:\mingw64\x86_64-w64-mingw32\include"

#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <bits/stdc++.h>

using namespace std;
float x,y,l,a,n;
 
void line(float x, float y,float l, float a)
{   
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2i(x,y);
    glVertex2i(l,a);
    glEnd();
}

void C_curve(float x,float y,float l,float a,float n)
  {
    if(n>0)
        {
            l=l/sqrt(2);
            C_curve(x,y,l, a+0.785,n-1);
            x=x+l*cos(a+0.785);
            y=y+l*sin(a+0.785);
            C_curve(x,y,l,a-0.785,n-1);
         }
        else 
        {
            line (x,y,x+l*cos(a),y+l*sin(a)); 
        }
    }

void Display(void)
{   
    C_curve(x,y,l,a,n); 
    glFlush();
}
void init(void)
{   
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLineWidth(3.0);
    glPointSize(2.0);
    gluOrtho2D(-600,600,-400,400);
}

int main(int argc,char** argv)

{   
    cout <<"Enter N value: ";
    cin >> n;
    cout <<"Enter x and y: ";
    cin >> x >> y;
    cout <<"Enter alpha: ";
    cin >> a;
    cout <<"Enter Length: ";
    cin >> l;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(200,100);
    glutCreateWindow("C Curve ");
    
    glutDisplayFunc(Display);
    init();
    glutMainLoop();
    return 0;
    
}
