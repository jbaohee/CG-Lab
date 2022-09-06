// g++ -c -o main.o main.cpp -I\"C:\mingw64\x86_64-w64-mingw32\include"
#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

float x,y,len,alpha,n,a,b;

void line(float x,float y,float a,float b)
{   
    glBegin(GL_LINES);
    glColor3f(1,0,0);
    glVertex2d(x,y);
    glVertex2d(a,b);
    glEnd();
}

void koch_curve(float x,float y,float len,float alpha, float n)
{
    if(n>0){

        len=len/3;
        koch_curve(x,y,len,alpha,n-1);
        x=x+len*cos(alpha);
        y=y+len*sin(alpha);
        koch_curve(x,y,len,alpha-120,n-1);
        x=x+len*cos(alpha-120);
        y=y+len*sin(alpha-120);
        koch_curve(x,y,len,alpha+120,n-1);
        x=x+len*cos(alpha+120);
        y=y+len*sin(alpha+120);
        koch_curve(x,y,len,alpha,n-1); 
    }
    else{
        a=x+len*cos(alpha);
        b=y+len*sin(alpha);
        line(x,y,a,b);
    }
}

void Display(void)
{
    koch_curve (x,y,len,alpha,n);
    glFlush();
}

void init(void)
{
    glPointSize(5);
    glClearColor(1.0,1.0,1.0,0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLineWidth(3.0);
    glPointSize(2.0);
    gluOrtho2D(-600,600,-400,400);

}

int main(int ac,char** av)

{   
    cout <<"Enter n: ";
    cin >> n;
    cout <<"Enter x y: ";
    cin >> x >> y;
    cout <<"Enter length :";
    cin >> len;
    cout <<"Enter alpha :";
    cin >> alpha;

    glutInit(&ac, av);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(200,100);
    glutCreateWindow("koch_curve ");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}       
