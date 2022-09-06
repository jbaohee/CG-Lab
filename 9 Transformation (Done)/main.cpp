//g++ -c -o main.o main.cpp -I\"C:\mingw64\x86_64-w64-mingw32\include"

#include<windows.h>
#include <iostream>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include <bits/stdc++.h>

using namespace std;

int w=1200, h=800;

double ortho_w= double (w/2);
double ortho_h= double (h/2);

void delay(float ms){
    clock_t goal = ms + clock();
    while(goal>clock());
}

void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,w,0,h);
    glLineWidth(3);
    glPointSize(2);
    glColor3f(1,0,0);
}

void tran(){
    for(int i=0;i<200;i=i+1)
        {
        int x1=200,y1=200;
        int x2=300,y2=200;
        int x3=250,y3=250; //initial points
        delay(10);
        x1+=i;x2+=i;x3+=i;
        y1+=i;y2+=i;y3+=i;

        glClear(GL_COLOR_BUFFER_BIT);   
        glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glVertex2i(x3,y3);
        glEnd();
        glFlush();
        }
}

void scale(){
    for(float i=1;i<1.5;i=i+0.001)
    {
        int x1=100,y1=100,x2=300,y2=100,x3=300,y3=200;
        x1*=i; y1*=i;
        x2*=i; y1*=i;
        x3*=i; y3*=i;

        delay(5);
       
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glVertex2i(x3,y3);
        glEnd();
        glFlush();
    }

}

void rote(){
    for(float i=0;i<0.524;i=i+0.001)
    {
        delay(2);
        int x1=400,y1=100;
        int x2=600,y2=100;
        int x3=500,y3=200;

        x1=x1*cos(i)-y1*sin(i);
        x2=x2*cos(i)-y2*sin(i);
        x3=x3*cos(i)-y3*sin(i);

        y1=x1*sin(i)+y1*cos(i);
        y2=x2*sin(i)+y2*cos(i);
        y3=x3*sin(i)+y3*cos(i);
 
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_LINE_LOOP);
        glVertex2i(x1,y1);
        glVertex2i(x2,y2);
        glVertex2i(x3,y3);
        glEnd();
        glFlush();
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(w,h);
    glutInitWindowPosition(200,100);

    int choice;
        cout<<"Welcome to Geometric Transformation!!"<<endl;
        cout<<"Press 1 for Translation"<<endl;
        cout<<"Press 2 for Rotation"<<endl;
        cout<<"Press 3 for Scaling"<<endl;
        cout<<"Press 0 to exit"<<endl<<endl;

    while (1)
    {
        cout<<"Enter Choice : " ;
        cin>>choice;
        if (choice == 1) //translation
        {
            glutCreateWindow("Geometric Transformation");
            glutDisplayFunc(tran);
            init();
        }

        else if (choice == 2) // Scaling
        {
            glutCreateWindow("Geometric Transformation");
            glutDisplayFunc(rote);
            init();
        }

        else if (choice == 3) // Rotation
        {
            glutCreateWindow("Geometric Transformation");
            glutDisplayFunc(scale);
            init();
        }
        glutMainLoop();
    }
    return 0;
}
