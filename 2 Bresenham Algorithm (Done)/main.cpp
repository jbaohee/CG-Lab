// g++ -c -o main.o main.cpp -I\"C:\mingw64\x86_64-w64-mingw32\include"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;
int w=1200, h=800;

double ortho_w = (double) w/2;
double ortho_h = (double) h/2;

float xstart, ystart, xend, yend;

void init();
void draw_cartesian();
void display();
void plot_case_1();
void plot_case_2();
void plot_case_3();

int main(int argc, char**argv)
{
    cout<<"Enter starting X Y coordinate: ";
    cin>>xstart>>ystart;

    cout<<"Enter Ending X Y coordinate: ";
    cin>>xend>>yend;
    cout<<endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(200,100);
    glutInitWindowSize(w,h);
    glutCreateWindow("Bresenham line");

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
    glPointSize(2.0);
    glLineWidth(1.0);
}

void draw_cartesian()
{
    //X axis
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f((w/2-10),0);
    glVertex2f(-(w/2-10),0);
    glEnd();
    glFlush();

    //Y axis
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex2f(0,(h/2-10));
    glVertex2f(0,-(h/2-10));
    glEnd();
    glFlush();
}

void display()
{
    draw_cartesian();

    float m = (yend-ystart)/(xend-xstart);
    cout<<"Slope = "<<m<<endl;

    if (m>=0 && m<=1) //FOR 0<M<1
    {
        cout<<"Case 1 initialized"<<endl;
        plot_case_1();
    }
    else if(m>=-1 && m<0) //FOR -1<M<0
    {
        cout<<"Case 2 initialized"<<endl;
        plot_case_2();
    }
    else if(m>1 || m<1) //FOR M>1 AND M<1
    {
        cout<<"Case 3 initialized"<<endl;
        plot_case_3();
    }
    
}


//FOR 0<M<1
void plot_case_1()
{
    float dx = xend-xstart;
    float dy = yend-ystart;
    float p = 2*dy - dx;
    float x,y;
    x = xstart;
    y = ystart;

    float step_x = dx;
    float step_y = dy;

    for (int i=0; i<step_x; i++)
    {
        glBegin(GL_POINTS);
        glColor3f(1,0,0);
        glVertex2f(x,y);
        glEnd();
        glFlush();

        x++;
        if (p>0)
        {
            y = y+1;
            p = p-2*dx;
        }
        p = p + 2*dy;
    }
}


//FOR -1<M<0
void plot_case_2()
{
    if (abs(yend-ystart) < abs(xend-xstart))
    {
        if(xend<xstart)
        {
            swap(xend, xstart);
            swap(yend, ystart);
        }
    }

    float dx = xend-xstart;
    float dy = yend-ystart;
    float yi = 1;

    if (dy<0)
    {
        yi = -1;
        dy = -dy;
    }

    float p = 2*dy - dx;

    float x,y;
    x = xstart;
    y = ystart;

    float step_x = dx;
    float step_y = dy;

    for (int i=0; i<step_x; i++)
    {
        glBegin(GL_POINTS);
        glColor3f(1,0,0);
        glVertex2f(x,y);
        glEnd();
        glFlush();

        x++;
        if (p>0)
        {
            y = y+yi;
            p = p+ 2*dy - 2*dx;
        }
        else
        {
            p = p + 2*dy;
        }
        
    }
}

//FOR M>1 AND M<1
void plot_case_3()
{
    if (abs(yend-ystart) >= abs(xend-xstart))
    {
        if(yend<ystart)
        {
            swap(xend, xstart);
            swap(yend, ystart);
        }
    }

    float dx = xend-xstart;
    float dy = yend-ystart;
    float xi = 1;

    if (dx<0)
    {
        xi = -1;
        dx = -dx;
    }

    float p = 2*dx - dy;

    float x,y;
    x = xstart;
    y = ystart;

    float step_x = dx;
    float step_y = dy;

    for (int i=0; i<step_y; i++)
    {
        glBegin(GL_POINTS);
        glColor3f(1,0,0);
        glVertex2f(x,y);
        glEnd();
        glFlush();

        y++;
        if (p>0)
        {
            x = x+xi;
            p = p+ 2*dx - 2*dy;
        }
        else
        {
            p = p + 2*dx;
        }
        
    }
}

