#include <GL/glut.h>
#include <string>
#include <math.h>

void myInit()
{

    glClearColor(0.60,0.80,1.00,1); /// background color
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(0.0, 0.0,0.0); /// foreground color
    glPointSize(12.0); /// point size
    glLineWidth(7.0); /// line width
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-300, 300, -300, 300); /// 2D frame position
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
}

void circle(int theta,int h,int k) /// circle drawing
{
    GLfloat x, y, angle;
    glBegin(GL_QUADS);
    for (angle = 0; angle <= 360; angle += 1)
    {
        x = theta * sin(angle);
        y = theta * cos(angle);
        glVertex2i(x+h,y+k);
    }
    glEnd();
}

void Display()
{

    ///Bangladesh national flag

    glColor3f(1,0,0);
    circle(30,-185,300-128); /// circle

    glColor3f(0.00,0.60,0.20);  /// flag
    glBegin(GL_QUADS);
    glVertex2i(-250, 300-55);
    glVertex2i(-120,300-55);
    glVertex2i(-120,300-200);
    glVertex2i(-250,300-200);
    glEnd();

    glColor3f(0,0,0); /// stick or pillar
    glBegin(GL_QUADS);
    glVertex2i(-260, 300-465);
    glVertex2i(-260,300-50);
    glVertex2i(-250,300-50);
    glVertex2i(-250,300-465);
    glEnd();

    glRecti(-280, 300-465,-230, 300-480); /// corner wise rectangle and ground part
    glRecti(-290, 300-480,-220, 300-490);

    glFlush();
    glutSwapBuffers();

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800, 800);  /// output window size
    glutInitWindowPosition(100, 100); /// output window position
    glutCreateWindow("Car Drawing"); /// output window title
    myInit();
    glutDisplayFunc(Display); /// output window object showing function
    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glutMainLoop();
}
