// g++ -c -o main.o main.cpp -I\"C:\mingw64\x86_64-w64-mingw32\include"

#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<bits/stdc++.h>

using namespace std;

float x_1, y_1, x_2, y_2, x_3, y_3;
int w=1200, h=800;
int n;

double ortho_w= double (w/2);
double ortho_h= double (h/2);


void gasket (float x1, float y1, float x2, float y2, float x3, float y3, int n)
{
    float x12, y12, x13, y13, x23, y23;

    if(n > 0)
    {
        x12 = (x1 + x2)/2; 
        x13 = (x1 + x3)/2; 
        x23 = (x2 + x3)/2;

        y12 = (y1 + y2)/2; 
        y13 = (y1 + y3)/2; 
        y23 = (y2 + y3)/2;

        gasket(x1, y1, x12, y12, x13, y13, n-1);
        gasket(x12, y12, x2, y2, x23, y23, n-1);
        gasket(x13, y13, x23, y23, x3, y3, n-1);
    }
    else
    {
        glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
        glEnd();
        glFlush();
    }
}

void Display(void)
{
	gasket(x_1, y_1, x_2, y_2, x_3,y_3,n);
}

void init (void)
{   
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-ortho_w,ortho_w,-ortho_h,ortho_h);
	glPointSize(2);
}

int main(int argc, char** argv)
{
    cout<<"first co-ordinate: ";
    cin>>x_1>>y_1;
    cout<<"\nsecond co-ordinate: ";
    cin>>x_2>>y_2;
    cout<<"\nthird co-ordinate: ";
    cin>>x_3>>y_3;
    cout<<"\nvalue of n: ";
    cin>>n;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(200, 100);
    glutCreateWindow("S_GASKET");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();

    return 0;
}
