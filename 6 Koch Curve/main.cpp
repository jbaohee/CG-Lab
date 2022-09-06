#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float x,y,len,alpha,n,a,b;

int w=1200, h=800;

double ortho_w= double (w/2);
double ortho_h= double (h/2);

void init(void);

void line(float x,float y,float a,float b)

{
    glBegin(GL_LINES);
    glLineWidth(3.0);
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

        x=x+len*cos(alpha-2.1);
        y=y+len*sin(alpha-2.1);

        koch_curve(x,y,len,alpha+2.1,n-1);

        x=x+len*cos(alpha+2.1);
        y=y+len*sin(alpha+2.1);

        koch_curve(x,y,len,alpha,n-1); }
    else
    {
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
    glColor3f(1,0,0);
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    //gluOrtho2D(-100,100,-100,100);
    gluOrtho2D(-ortho_w,ortho_w,-ortho_h,ortho_h);
    }
int main(int ac,char** av)
{   
    printf("n: ");
    scanf("%f",&n);
    printf("\nx, y: ");
    scanf("%f%f",&x,&y);
    printf("\nlength: ");
    scanf("%f",&len);
    printf("\nalpha: ");
    scanf("%f",&alpha);
    glutInit(&ac, av);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("koch_curve ");
    init();
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;}
