#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float p = 0;
float dc = 0;
float sun = 0;
float autosun = 0;
float m = 0;
float car1=0;
float car2=0;
float car3 =0;
float AutoMode =0;
//int l;
//int m =0;
int inc = 0.0;

int day = 6;

void init (void)
{

glClearColor (0,0,0, 0.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0,135,0,68, -1.0, 1.0);
}

void circle( GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy,GLint a,GLint b)
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=a;i<=b;i++)
    {

        float  angle = 2.0f *3.1416*i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));



    }
    glEnd();
}



void Rain1()
{

    if(p >= 0)
    {
        p -= 0.1;
    }

    else{
        p = 10;
    }

    glutPostRedisplay();

    for(int j=0;j<80;j=j+5)
    {
        for(int i=-100;i<=200;i=i+5)
        {
        glColor3f (1,1,1);
        circle(1,1,i+p,j+p,67,70);
        }
    }
}

void Rain2()
{

    if(p >= 0)
    {
        p -= 0.07;
    }

    else{
        p = 10;
    }

    glutPostRedisplay();

    for(int j=0;j<80;j=j+5)
    {
        for(int i=-100;i<=200;i=i+5)
        {
        glColor3f (1,1,1);
        circle(1,1,i+p,j+p,67,70);
        }
    }
}

void Rain3()
{

    if(p >= 0)
    {
        p -= 0.04;
    }

    else{
        p = 10;
    }

    glutPostRedisplay();

    for(int j=0;j<80;j=j+5)
    {
        for(int i=-100;i<=200;i=i+5)
        {
        glColor3f (1,1,1);
        circle(1,1,i+p,j+p,67,70);
        }
    }
}


void Rain4()
{

    if(p >= 0)
    {
        p -= 0.01;
    }

    else{
        p = 10;
    }

    glutPostRedisplay();

    for(int j=0;j<80;j=j+10)
    {
        for(int i=-100;i<=200;i=i+5)
        {
        glColor3f (1,1,1);
        circle(1,1,i+p,j+p,67,70);
        }
    }
}

void Cloud()
{
    glColor3ub(200,208,200);
    glBegin(GL_POLYGON);
    glVertex3f (0,60, 0.0);
    glVertex3f (135,60, 0.0);
    glVertex3f (135, 68, 0.0);
    glVertex3f (0, 68, 0.0);
    glEnd();



   for(int i=130;i>=0;i=i-20)
   {
    glColor3ub(200,208,200);
    circle(5,5,i-8,59,0,100);

    glColor3ub(200,208,200);
    circle(5,5,i-2,59,0,100);

    glColor3ub(119,128,143);
    circle(5,5,i-10,61,0,100);

    glColor3ub(119,128,143);
    circle(5,5,i-0,61,0,100);

    glColor3ub(119,128,143);
    circle(7,7,i-5,61,0,100);

   }
}

void Background0()
{

    if(m <= 150)
    {
        m += 0.09;

    }

    else{
        m =0;

    }

    glutPostRedisplay();

    int k=m*m;

    glColor3ub((k*1)%235, (k*1)%235, (k*1)%235);
    glBegin(GL_POLYGON);
    glVertex3f (0,0, 0.0);
    glVertex3f (135,0, 0.0);
    glVertex3f (135, 68, 0.0);
    glVertex3f (0, 68, 0.0);
    glEnd();
}

void Dayroad()
{
    glColor3f (.24, 1,.24);
    glBegin(GL_POLYGON);
    glVertex2f (0,0);
    glVertex2f (135,0);
    glVertex2f (135, 12);
    glVertex2f (0, 12);
    glEnd();

    glColor3ub(67, 64,75);
    glBegin(GL_POLYGON);
    glVertex2f (0,0);
    glVertex2f (135,0);
    glVertex2f (135, 11);
    glVertex2f (0, 11);
    glEnd();

    glColor3f (.24, 1,.24);
    glBegin(GL_POLYGON);
    glVertex2f (0,0);
    glVertex2f (135,0);
    glVertex2f (135, 1);
    glVertex2f (0, 1);
    glEnd();

    for(int i=0;i<135;i=i+5)
    {

    glColor3ub(238, 176,13);
    glBegin(GL_POLYGON);
    glVertex2f (i,6.5);
    glVertex2f (i+4,6.5);
    glVertex2f (i+4.3, 7);
    glVertex2f (i+.3, 7);
    glEnd();

    }


}



void Nightroad()
{
    glColor3f (.24, 1,.24);
    glBegin(GL_POLYGON);
    glVertex2f (0,0);
    glVertex2f (135,0);
    glVertex2f (135, 12);
    glVertex2f (0, 12);
    glEnd();

    glColor3f (.1, .1,.1);
    glBegin(GL_POLYGON);
    glVertex2f (0,0);
    glVertex2f (135,0);
    glVertex2f (135, 11);
    glVertex2f (0, 11);
    glEnd();

    glColor3f (.24, 1,.24);
    glBegin(GL_POLYGON);
    glVertex2f (0,0);
    glVertex2f (135,0);
    glVertex2f (135, 1);
    glVertex2f (0, 1);
    glEnd();

    for(int i=0;i<135;i=i+5)
    {

    glColor3ub(238, 176,13);
    glBegin(GL_POLYGON);
    glVertex2f (i,6.5);
    glVertex2f (i+4,6.5);
    glVertex2f (i+4.3, 7);
    glVertex2f (i+.3, 7);
    glEnd();

    }


}



void Background1()
{
    glColor3ub (2,20,35);
    glBegin(GL_POLYGON);
    glVertex3f (0,0, 0.0);
    glVertex3f (135,0, 0.0);
    glVertex3f (135, 68, 0.0);
    glVertex3f (0, 68, 0.0);
    glEnd();
}





void Background2()
{
    glColor3ub (19,62,98);
    glBegin(GL_POLYGON);
    glVertex3f (0,0, 0.0);
    glVertex3f (135,0, 0.0);
    glVertex3f (135, 68, 0.0);
    glVertex3f (0, 68, 0.0);
    glEnd();
}

void Background3()
{
    glColor3ub (57,114,163);
    glBegin(GL_POLYGON);
    glColor3ub (255,255,0);
    glVertex3f (0,0, 0.0);
    glColor3ub (0,250,0);
    glVertex3f (135,0, 0.0);


    glColor3ub (255,0,0);
    glVertex3f (135, 68, 0.0);
    glColor3ub (0,0,255);
    glVertex3f (0, 68, 0.0);
    glEnd();
}

void Background4()
{
    glColor3ub (107,173,230);
    glBegin(GL_POLYGON);

    glVertex3f (0,0, 0.0);

    glVertex3f (135,0, 0.0);


    glVertex3f (135, 68, 0.0);
    glColor3ub (247,240,140);

    glVertex3f (0, 68, 0.0);
    glEnd();







    glColor3ub(222,0,0);
    circle(40,40,70,10,0,100);

    glColor3ub(254,98,44);
    circle(38,38,70,10,0,100);

    glColor3ub(244,254,0);
    circle(36,36,70,10,0,100);

    glColor3ub(0,188,0);
    circle(34,34,70,10,0,100);

    glColor3ub(0,154,255);
    circle(32,32,70,10,0,100);

    glColor3ub(0,0,132);
    circle(30,30,70,10,0,100);

      glColor3ub(44,0,156);
    circle(28,28,70,10,0,100);

    glColor3ub (107,173,230);
    circle(26,26,70,10,0,100);


}




void Building1()
{
    glColor3ub(106,85,45);
    glBegin(GL_POLYGON);
    glVertex3f (10,12, 0.0);
    glVertex3f (20.5,12, 0.0);
    glVertex3f (20.5,21, 0.0);
    glVertex3f (10,21, 0.0);
    glEnd();

    for(int i=9;i<19;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,12.5, 0.0);
    glVertex3f (i+3,12.5, 0.0);
    glVertex3f (i+3,14, 0.0);
    glVertex3f (i+1.5,14, 0.0);
    glEnd();
    }

 for(int i=9;i<19;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,14.5, 0.0);
    glVertex3f (i+3,14.5, 0.0);
    glVertex3f (i+3,16, 0.0);
    glVertex3f (i+1.5,16, 0.0);
    glEnd();
    }

    for(int i=9;i<19;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,16.5, 0.0);
    glVertex3f (i+3,16.5, 0.0);
    glVertex3f (i+3,18, 0.0);
    glVertex3f (i+1.5,18, 0.0);
    glEnd();
    }

    for(int i=9;i<19;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,18.5, 0.0);
    glVertex3f (i+3,18.5, 0.0);
    glVertex3f (i+3,20, 0.0);
    glVertex3f (i+1.5,20, 0.0);
    glEnd();
    }

    glColor3ub(106,85,45);
    glBegin(GL_POLYGON);
    glVertex3f (11,20, 0.0);
    glVertex3f (19.5,20, 0.0);
    glVertex3f (19.5,31.5, 0.0);
    glVertex3f (11,31.5, 0.0);
    glEnd();

    for(int i=10;i<18;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,21, 0.0);
    glVertex3f (i+3,21, 0.0);
    glVertex3f (i+3,23, 0.0);
    glVertex3f (i+1.5,23, 0.0);
    glEnd();

    }

     for(int i=10;i<18;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,23.5, 0.0);
    glVertex3f (i+3,23.5, 0.0);
    glVertex3f (i+3,25.5, 0.0);
    glVertex3f (i+1.5,25.5, 0.0);
    glEnd();

    }

     for(int i=10;i<18;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,26, 0.0);
    glVertex3f (i+3,26, 0.0);
    glVertex3f (i+3,28, 0.0);
    glVertex3f (i+1.5,28, 0.0);
    glEnd();

    }

     for(int i=10;i<18;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,28.5, 0.0);
    glVertex3f (i+3,28.5, 0.0);
    glVertex3f (i+3,30.5, 0.0);
    glVertex3f (i+1.5,30.5, 0.0);
    glEnd();

    }

    glColor3ub(106,85,45);
    glBegin(GL_POLYGON);
    glVertex3f (12,31, 0.0);
    glVertex3f (18.5,31, 0.0);
    glVertex3f (18.5,40, 0.0);
    glVertex3f (12,40, 0.0);
    glEnd();

    for(int i=11;i<17;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,32, 0.0);
    glVertex3f (i+3,32, 0.0);
    glVertex3f (i+3,34, 0.0);
    glVertex3f (i+1.5,34, 0.0);
    glEnd();

    }

     for(int i=11;i<17;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,34.5, 0.0);
    glVertex3f (i+3,34.5, 0.0);
    glVertex3f (i+3,36.5, 0.0);
    glVertex3f (i+1.5,36.5, 0.0);
    glEnd();

    }


     for(int i=11;i<17;i=i+2)
    {
    glColor3ub(255,255,140);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.5,37, 0.0);
    glVertex3f (i+3,37, 0.0);
    glVertex3f (i+3,39, 0.0);
    glVertex3f (i+1.5,39, 0.0);
    glEnd();

    }

}


void Tree1()
{
   glColor3ub(66,34,11);
    glBegin(GL_POLYGON);
    glVertex3f (4,12, 0.0);
    glVertex3f (6,12, 0.0);
    glVertex3f (6,20, 0.0);
    glVertex3f (4,20, 0.0);
    glEnd();

    glColor3ub(104,150,43);
    circle(3,3,3,18,0,100);

    glColor3ub(104,150,43);
    circle(3,3,7,18,0,100);

    glColor3ub(104,150,43);
    circle(2.5,2.5,3.5,22,0,100);

    glColor3ub(104,150,43);
    circle(2.5,2.5,6.5,22,0,100);

    glColor3ub(104,150,43);
    circle(2.5,2.5,4.75,26,0,100);


}

void Tree3()
{
   glColor3ub(66,34,11);
    glBegin(GL_POLYGON);
    glVertex3f (20.5,12, 0.0);
    glVertex3f (22.5,12, 0.0);
    glVertex3f (22.5,20, 0.0);
    glVertex3f (20.5,20, 0.0);
    glEnd();

    glColor3ub(104,150,43);
    circle(3,3,18.5,19,0,100);

    glColor3ub(104,150,43);
    circle(3,3,24.5,19,0,100);

    glColor3ub(104,150,43);
    circle(3,3,19,21,0,100);

    glColor3ub(104,150,43);
    circle(3,3,24,21,0,100);

    glColor3ub(104,150,43);
    circle(3,3,19.5,23.5,0,100);

    glColor3ub(104,150,43);
    circle(3,3,23.5,25,0,100);

    glColor3ub(104,150,43);
    circle(3,3,22,27,0,100);


}


void Tree2()
{
   glColor3ub(66,34,11);
    glBegin(GL_POLYGON);
    glVertex3f (128,12, 0.0);
    glVertex3f (131,12, 0.0);
    glVertex3f (131,20, 0.0);
    glVertex3f (128,20, 0.0);
    glEnd();

    glColor3ub(104,150,43);
    circle(5,5,127,21,0,100);

    glColor3ub(104,150,43);
    circle(5,5,132,21,0,100);

    glColor3ub(104,150,43);
    circle(4,4,128,25,0,100);

    glColor3ub(104,150,43);
    circle(4,4,131,25,0,100);

    glColor3ub(104,150,43);
    circle(4,4,129,27,0,100);

    glColor3ub(104,150,43);
    circle(4,4,130,27,0,100);

    glColor3ub(104,150,43);
    circle(3,3,129.5,29,0,100);


}

void Tree4()
{

    glColor3ub(104,150,43);
    circle(5,5,104,25,0,100);

    glColor3ub(104,150,43);
    circle(5,5,110,25,0,100);

    glColor3ub(104,150,43);
    circle(4,4,105,28,0,100);

    glColor3ub(104,150,43);
    circle(4,4,109,28,0,100);

    glColor3ub(104,150,43);
    circle(5,6,107,30,0,100);




}

void Tree5()
{
   glColor3ub(66,34,11);
    glBegin(GL_POLYGON);
    glVertex3f (40,12, 0.0);
    glVertex3f (43,12, 0.0);
    glVertex3f (43,20, 0.0);
    glVertex3f (40,20, 0.0);
    glEnd();

    glColor3ub(104,150,43);
    circle(5,5,39,21,0,100);

    glColor3ub(104,150,43);
    circle(5,5,44,21,0,100);

    glColor3ub(104,150,43);
    circle(4,4,40,25,0,100);

    glColor3ub(104,150,43);
    circle(4,4,43,25,0,100);

    glColor3ub(104,150,43);
    circle(4,4,41,27,0,100);

    glColor3ub(104,150,43);
    circle(4,4,42,27,0,100);

    glColor3ub(104,150,43);
    circle(3,3,41.5,29,0,100);


}

void Building2()
{

    glColor3ub(90,90,92);
    glBegin(GL_POLYGON);
    glVertex3f (52,12, 0.0);
    glVertex3f (72,12, 0.0);
    glVertex3f (72,45, 0.0);
    glVertex3f (52,45, 0.0);
    glEnd();

    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (52.5,12, 0.0);
    glVertex3f (71.5,12, 0.0);
    glVertex3f (71.5,44.5, 0.0);
    glVertex3f (52.5,44.5, 0.0);
    glEnd();




    for(int i=52;i<72;i=i+3)
    {
    glColor3ub(172,143,48);
    glBegin(GL_POLYGON);
    glVertex3f (i+1,12, 0.0);
    glVertex3f (i+1.5,12, 0.0);
    glVertex3f (i+1.5,44.5, 0.0);
    glVertex3f (i+1,44.5, 0.0);
    glEnd();
    }

    for(float i=12;i<43;i=i+1.5)
    {
    glColor3ub(144,136,136);
    glBegin(GL_POLYGON);
    glVertex3f (52,i+2.2, 0.0);
    glVertex3f (72,i+2.2, 0.0);
    glVertex3f (72,i+2.3, 0.0);
    glVertex3f (52,i+2.3, 0.0);
    glEnd();;
    }
}

void Building3()

{
    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (110,12, 0.0);
    glVertex3f (125.3,12, 0.0);
    glVertex3f (125.3,24.5, 0.0);
    glVertex3f (110,24.5, 0.0);
    glEnd();

    for(int i=109;i<124;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,12.5, 0.0);
    glVertex3f (i+2,12.5, 0.0);
    glVertex3f (i+2,13.2, 0.0);
    glVertex3f (i+1.3,13.2, 0.0);
    glEnd();
    }

 for(int i=109;i<124;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,14, 0.0);
    glVertex3f (i+2,14, 0.0);
    glVertex3f (i+2,14.7, 0.0);
    glVertex3f (i+1.3,14.7, 0.0);
    glEnd();
    }

    for(int i=109;i<124;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,15.5, 0.0);
    glVertex3f (i+2,15.5, 0.0);
    glVertex3f (i+2,16.2, 0.0);
    glVertex3f (i+1.3,16.2, 0.0);
    glEnd();
    }

     for(int i=109;i<124;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,17, 0.0);
    glVertex3f (i+2,17, 0.0);
    glVertex3f (i+2,17.7, 0.0);
    glVertex3f (i+1.3,17.7, 0.0);
    glEnd();
    }

     for(int i=109;i<124;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,18.5, 0.0);
    glVertex3f (i+2,18.5, 0.0);
    glVertex3f (i+2,19.2, 0.0);
    glVertex3f (i+1.3,19.2, 0.0);
    glEnd();
    }


     for(int i=109;i<124;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,20, 0.0);
    glVertex3f (i+2,20, 0.0);
    glVertex3f (i+2,20.7, 0.0);
    glVertex3f (i+1.3,20.7, 0.0);
    glEnd();
    }

     for(int i=109;i<124;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,21.5, 0.0);
    glVertex3f (i+2,21.5, 0.0);
    glVertex3f (i+2,22.2, 0.0);
    glVertex3f (i+1.3,22.2, 0.0);
    glEnd();
    }

     for(int i=109;i<124;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,23, 0.0);
    glVertex3f (i+2,23, 0.0);
    glVertex3f (i+2,23.7, 0.0);
    glVertex3f (i+1.3,23.7, 0.0);
    glEnd();
    }

    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (111,24.5, 0.0);
    glVertex3f (124.3,24.5, 0.0);
    glVertex3f (124.3,34.5, 0.0);
    glVertex3f (111,34.5, 0.0);
    glEnd();

    for(int i=110;i<123;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,24.5, 0.0);
    glVertex3f (i+2,24.5, 0.0);
    glVertex3f (i+2,25.2, 0.0);
    glVertex3f (i+1.3,25.2, 0.0);
    glEnd();

    }

    for(int i=110;i<123;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,26, 0.0);
    glVertex3f (i+2,26, 0.0);
    glVertex3f (i+2,26.7, 0.0);
    glVertex3f (i+1.3,26.7, 0.0);
    glEnd();

    }

    for(int i=110;i<123;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,27.3, 0.0);
    glVertex3f (i+2,27.3, 0.0);
    glVertex3f (i+2,28.1, 0.0);
    glVertex3f (i+1.3,28.1, 0.0);
    glEnd();

    }

    for(int i=110;i<123;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,28.9, 0.0);
    glVertex3f (i+2,28.9, 0.0);
    glVertex3f (i+2,29.6, 0.0);
    glVertex3f (i+1.3,29.6, 0.0);
    glEnd();

    }

    for(int i=110;i<123;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,30.3, 0.0);
    glVertex3f (i+2,30.3, 0.0);
    glVertex3f (i+2,31, 0.0);
    glVertex3f (i+1.3,31, 0.0);
    glEnd();



    }

    for(int i=110;i<123;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,31.7, 0.0);
    glVertex3f (i+2,31.7, 0.0);
    glVertex3f (i+2,32.4, 0.0);
    glVertex3f (i+1.3,32.4, 0.0);
    glEnd();


    }
     for(int i=110;i<123;i=i+1)
    {
    glColor3ub(200,187,84);
    glBegin(GL_POLYGON);
    glVertex3f (i+1.3,33.1, 0.0);
    glVertex3f (i+2,33.1, 0.0);
    glVertex3f (i+2,33.8, 0.0);
    glVertex3f (i+1.3,33.8, 0.0);
    glEnd();
    }

    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (112,34.5, 0.0);
    glVertex3f (123.3,34.5, 0.0);
    glVertex3f (123.3,40, 0.0);
    glVertex3f (112,40, 0.0);
    glEnd();

    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (113,40, 0.0);
    glVertex3f (122.3,40, 0.0);
    glVertex3f (122.3,45, 0.0);
    glVertex3f (113,45, 0.0);
    glEnd();

    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (115,45, 0.0);
    glVertex3f (120.3,45, 0.0);
    glVertex3f (120.3,48, 0.0);
    glVertex3f (115,48, 0.0);
    glEnd();





}

void Building4()
{


    glColor3ub(157,119,56);
    glBegin(GL_POLYGON);
    glVertex3f (23,12, 0.0);
    glVertex3f (37,12, 0.0);
    glVertex3f (37,19, 0.0);
    glVertex3f (23,19, 0.0);
    glEnd();

    for(int i=12;i<18;i=i+1)
    {
    glColor3ub(246,231,50);
    glBegin(GL_POLYGON);
    glVertex3f (23.5,i+.4, 0.0);
    glVertex3f (36.5,i+.4, 0.0);
    glVertex3f (36.5,i+.8, 0.0);
    glVertex3f (23.5,i+.8, 0.0);
    glEnd();
    }


     for(int i=24;i<37;i=i+3)
    {
    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (i+0,12, 0.0);
    glVertex3f (i+.2,12, 0.0);
    glVertex3f (i+.2,19, 0.0);
    glVertex3f (i+0,19, 0.0);
    glEnd();
    }

    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (23,19, 0.0);
    glVertex3f (37,19, 0.0);
    glVertex3f (36,21, 0.0);
    glVertex3f (24,21, 0.0);
    glEnd();




    glColor3ub(157,119,56);
    glBegin(GL_POLYGON);
    glVertex3f (24,21, 0.0);
    glVertex3f (36,21, 0.0);
    glVertex3f (36,27, 0.0);
    glVertex3f (24,27, 0.0);
    glEnd();

    for(int i=21;i<26;i=i+1)
    {
    glColor3ub(246,231,50);
    glBegin(GL_POLYGON);
    glVertex3f (24.5,i+.4, 0.0);
    glVertex3f (35.5,i+.4, 0.0);
    glVertex3f (35.5,i+.8, 0.0);
    glVertex3f (24.5,i+.8, 0.0);
    glEnd();
    }


     for(int i=25;i<36;i=i+3)
    {
    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (i+0,21, 0.0);
    glVertex3f (i+.2,21, 0.0);
    glVertex3f (i+.2,27, 0.0);
    glVertex3f (i+0,27, 0.0);
    glEnd();
    }

    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (24,27, 0.0);
    glVertex3f (36,27, 0.0);
    glVertex3f (35,29, 0.0);
    glVertex3f (25,29, 0.0);
    glEnd();





    glColor3ub(157,119,56);
    glBegin(GL_POLYGON);
    glVertex3f (25,29, 0.0);
    glVertex3f (35,29, 0.0);
    glVertex3f (35,35, 0.0);
    glVertex3f (25,35, 0.0);
    glEnd();


    for(int i=29;i<35;i=i+1)
    {
    glColor3ub(246,231,50);
    glBegin(GL_POLYGON);
    glVertex3f (25.5,i+.4, 0.0);
    glVertex3f (34.5,i+.4, 0.0);
    glVertex3f (34.5,i+.8, 0.0);
    glVertex3f (25.5,i+.8, 0.0);
    glEnd();
    }


     for(int i=27;i<35;i=i+3)
    {
    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (i+0,29, 0.0);
    glVertex3f (i+.2,29, 0.0);
    glVertex3f (i+.2,36, 0.0);
    glVertex3f (i+0,36, 0.0);
    glEnd();
    }

    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (25,35, 0.0);
    glVertex3f (35,35, 0.0);
    glVertex3f (34,37, 0.0);
    glVertex3f (26,37, 0.0);
    glEnd();

    glColor3ub(157,119,56);
    glBegin(GL_POLYGON);
    glVertex3f (26,37, 0.0);
    glVertex3f (34,37, 0.0);
    glVertex3f (34,42, 0.0);
    glVertex3f (26,42, 0.0);
    glEnd();

    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (26,42, 0.0);
    glVertex3f (34,42, 0.0);
    glVertex3f (33,44, 0.0);
    glVertex3f (27,44, 0.0);
    glEnd();

    glColor3ub(157,119,56);
    glBegin(GL_POLYGON);
    glVertex3f (27,44, 0.0);
    glVertex3f (33,44, 0.0);
    glVertex3f (33,48, 0.0);
    glVertex3f (27,48, 0.0);
    glEnd();

     glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (27,48, 0.0);
    glVertex3f (33,48, 0.0);
    glVertex3f (32,49, 0.0);
    glVertex3f (28,49, 0.0);
    glEnd();

    glColor3ub(157,119,56);
    glBegin(GL_POLYGON);
    glVertex3f (28,49, 0.0);
    glVertex3f (32,49, 0.0);
    glVertex3f (32,50, 0.0);
    glVertex3f (28,50, 0.0);
    glEnd();

     glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (28,50, 0.0);
    glVertex3f (32,50, 0.0);
    glVertex3f (31,50.6, 0.0);
    glVertex3f (29,50.6, 0.0);
    glEnd();

    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (29,50, 0.0);
    glVertex3f (31,50, 0.0);
    glVertex3f (30,55, 0.0);
    glEnd();


}

void Building5()
{

    glColor3ub(116,51,48);
    glBegin(GL_POLYGON);
    glVertex3f (0,12, 0.0);
    glVertex3f (12,12, 0.0);
    glVertex3f (12,30, 0.0);
    glVertex3f (0,30, 0.0);
    glEnd();




    for(int i=0;i<35;i=i+1)
    {
    glColor3ub(144,136,136);
    glBegin(GL_POLYGON);
    glVertex3f (i+1,12, 0.0);
    glVertex3f (i+1.1,12, 0.0);
    glVertex3f (i+1.1,30, 0.0);
    glVertex3f (i+1,30, 0.0);
    glEnd();
    }

    for(float i=12;i<28;i=i+1.5)
    {
    glColor3ub(144,136,136);
    glBegin(GL_POLYGON);
    glVertex3f (0,i+2.2, 0.0);
    glVertex3f (35,i+2.2, 0.0);
    glVertex3f (35,i+2.3, 0.0);
    glVertex3f (0,i+2.3, 0.0);
    glEnd();;
    }
}

void Building6()
{
    glColor3ub(90,90,92);
    glBegin(GL_POLYGON);
    glVertex3f (88,12, 0.0);
    glVertex3f (98,12, 0.0);
    glVertex3f (98,50, 0.0);
    glVertex3f (88,50, 0.0);
    glEnd();

    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (88.5,12, 0.0);
    glVertex3f (97.5,12, 0.0);
    glVertex3f (97.5,49.5, 0.0);
    glVertex3f (88.5,49.5, 0.0);
    glEnd();

    for(int i=13;i<49;i=i+1)
    {
    glColor3ub(172,143,48);
    glBegin(GL_POLYGON);
    glVertex3f (89,i+0, 0.0);
    glVertex3f (97,i+0, 0.0);
    glVertex3f (97,i+.6, 0.0);
    glVertex3f (89,i+.6, 0.0);
    glEnd();
    }


     for(int i=89;i<97;i=i+1)
    {
    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (i+0,13, 0.0);
    glVertex3f (i+.2,13, 0.0);
    glVertex3f (i+.2,49, 0.0);
    glVertex3f (i+0,49, 0.0);
    glEnd();
    }

    glColor3ub(90,90,92);
    glBegin(GL_POLYGON);
    glVertex3f (86,12, 0.0);
    glVertex3f (100,12, 0.0);
    glVertex3f (100,41.8, 0.0);
    glVertex3f (86,41.8, 0.0);
    glEnd();

    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (86.5,12, 0.0);
    glVertex3f (99.5,12, 0.0);
    glVertex3f (99.5,41.3, 0.0);
    glVertex3f (86.5,41.3, 0.0);
    glEnd();

    for(int i=13;i<41;i=i+1)
    {
    glColor3ub(172,143,48);
    glBegin(GL_POLYGON);
    glVertex3f (87,i+0, 0.0);
    glVertex3f (99,i+0, 0.0);
    glVertex3f (99,i+.6, 0.0);
    glVertex3f (87,i+.6, 0.0);
    glEnd();
    }


     for(int i=87;i<99;i=i+1)
    {
    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (i+0,13, 0.0);
    glVertex3f (i+.2,13, 0.0);
    glVertex3f (i+.2,41.2, 0.0);
    glVertex3f (i+0,41.2, 0.0);
    glEnd();
    }

    glColor3ub(90,90,92);
    glBegin(GL_POLYGON);
    glVertex3f (92,12, 0.0);
    glVertex3f (104,12, 0.0);
    glVertex3f (104,38, 0.0);
    glVertex3f (92,38, 0.0);
    glEnd();

    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (92.5,12, 0.0);
    glVertex3f (103.5,12, 0.0);
    glVertex3f (103.5,37.5, 0.0);
    glVertex3f (92.5,37.5, 0.0);
    glEnd();


    for(int i=13;i<37;i=i+1)
    {
    glColor3ub(172,143,48);
    glBegin(GL_POLYGON);
    glVertex3f (93,i+0, 0.0);
    glVertex3f (103,i+0, 0.0);
    glVertex3f (103,i+.6, 0.0);
    glVertex3f (93,i+.6, 0.0);
    glEnd();
    }


     for(int i=93;i<103;i=i+1)
    {
    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (i+0,13, 0.0);
    glVertex3f (i+.2,13, 0.0);
    glVertex3f (i+.2,37, 0.0);
    glVertex3f (i+0,37, 0.0);
    glEnd();
    }


    glColor3ub(90,90,92);
    glBegin(GL_POLYGON);
    glVertex3f (80,12, 0.0);
    glVertex3f (96,12, 0.0);
    glVertex3f (96,32, 0.0);
    glVertex3f (80,32, 0.0);
    glEnd();


    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (80.5,12, 0.0);
    glVertex3f (95.5,12, 0.0);
    glVertex3f (95.5,31.5, 0.0);
    glVertex3f (80.5,31.5, 0.0);
    glEnd();


    for(int i=13;i<31;i=i+1)
    {
    glColor3ub(172,143,48);
    glBegin(GL_POLYGON);
    glVertex3f (81,i+0, 0.0);
    glVertex3f (95,i+0, 0.0);
    glVertex3f (95,i+.6, 0.0);
    glVertex3f (81,i+.6, 0.0);
    glEnd();
    }


     for(int i=81;i<95;i=i+1)
    {
    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (i+0,13, 0.0);
    glVertex3f (i+.2,13, 0.0);
    glVertex3f (i+.2,31, 0.0);
    glVertex3f (i+0,31, 0.0);
    glEnd();
    }


    glColor3ub(90,90,92);
    glBegin(GL_POLYGON);
    glVertex3f (86,12, 0.0);
    glVertex3f (109,12, 0.0);
    glVertex3f (109,26, 0.0);
    glVertex3f (86,26, 0.0);
    glEnd();


    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (86.5,12, 0.0);
    glVertex3f (108.5,12, 0.0);
    glVertex3f (108.5,25.5, 0.0);
    glVertex3f (86.5,25.5, 0.0);
    glEnd();


    for(int i=13;i<25;i=i+1)
    {
    glColor3ub(172,143,48);
    glBegin(GL_POLYGON);
    glVertex3f (87,i+0, 0.0);
    glVertex3f (108,i+0, 0.0);
    glVertex3f (108,i+.6, 0.0);
    glVertex3f (87,i+.6, 0.0);
    glEnd();
    }


     for(int i=87;i<108;i=i+1)
    {
    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (i+0,13, 0.0);
    glVertex3f (i+.2,13, 0.0);
    glVertex3f (i+.2,25, 0.0);
    glVertex3f (i+0,25, 0.0);
    glEnd();
    }




       glColor3ub(66,34,11);
    glBegin(GL_POLYGON);
    glVertex3f (77,16, 0.0);
    glVertex3f (80,16, 0.0);
    glVertex3f (80,22, 0.0);
    glVertex3f (77,22, 0.0);
    glEnd();

    glColor3ub(104,150,43);
    circle(5,5,77,23,0,100);

    glColor3ub(104,150,43);
    circle(5,5,82,23,0,100);

    glColor3ub(104,150,43);
    circle(4,4,78,27,0,100);

    glColor3ub(104,150,43);
    circle(4,4,81,27,0,100);

    glColor3ub(104,150,43);
    circle(4,4,79,29,0,100);

    glColor3ub(104,150,43);
    circle(4,4,80,29,0,100);

    glColor3ub(104,150,43);
    circle(3,3,79.5,31,0,100);


glColor3ub(90,90,92);
    glBegin(GL_POLYGON);
    glVertex3f (76,12, 0.0);
    glVertex3f (109,12, 0.0);
    glVertex3f (109,21, 0.0);
    glVertex3f (76,21, 0.0);
    glEnd();


    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (76.5,12, 0.0);
    glVertex3f (108.5,12, 0.0);
    glVertex3f (108.5,20.5, 0.0);
    glVertex3f (76.5,20.5, 0.0);
    glEnd();

    for(int i=13;i<20;i=i+1)
    {
    glColor3ub(172,143,48);
    glBegin(GL_POLYGON);
    glVertex3f (77,i+0, 0.0);
    glVertex3f (108,i+0, 0.0);
    glVertex3f (108,i+.6, 0.0);
    glVertex3f (77,i+.6, 0.0);
    glEnd();
    }


     for(int i=77;i<108;i=i+1)
    {
    glColor3ub(71,46,46);
    glBegin(GL_POLYGON);
    glVertex3f (i+0,13, 0.0);
    glVertex3f (i+.2,13, 0.0);
    glVertex3f (i+.2,20, 0.0);
    glVertex3f (i+0,20, 0.0);
    glEnd();
    }




}


void DaySun()
{

    if(sun <= 145)
    {
        //sun += 0.05;

    }

    else{
        sun =0;

    }

    glutPostRedisplay();


    glColor3ub (248,240,45);
    circle(5,5,sun+10,62,0,100);


}

void NightCar1()
{
    if(car1 >= 0)
    {
        car1 -= 0.09;

    }

    else{
        car1 =155;

    }
    //car1 =40;
    int k=car1*5;

    glutPostRedisplay();

    //headLight

    glColor3ub(248,224,100);
    glBegin(GL_POLYGON);

    glVertex3f (-25+car1,2-1.5, 0.0);
    glVertex3f (-15+car1,5.5-1.5, 0.0);
    glVertex3f (-15+car1,6-1.5, 0.0);
    glVertex3f (-25+car1,9-1.5, 0.0);
    glEnd();

    glColor3ub(248,224,100);
    circle(4,3.5,-25+car1,5.5-1.5,25,75);



    glColor3ub(6,54,103);
    glBegin(GL_POLYGON);
    glVertex3f (-15+car1,4-1.5, 0.0);
    glVertex3f (-3+car1,4-1.5, 0.0);
    glVertex3f (-3+car1,8-1.5, 0.0);
    glVertex3f (-8+car1,8-1.5, 0.0);
    glVertex3f (-8+car1,10-1.5, 0.0);
    glVertex3f (-11+car1,10-1.5, 0.0);
    glVertex3f (-13+car1,8-1.5, 0.0);

    glVertex3f (-15+car1,7.5-1.5, 0.0);
    glEnd();

    //glass

    glColor3ub(40,218,228);
    glBegin(GL_POLYGON);
    glVertex3f (-8.5+car1,8-1.5, 0.0);
    glVertex3f (-8.5+car1,9.5-1.5, 0.0);
    glVertex3f (-11+car1,9.5-1.5, 0.0);
    glVertex3f (-12.5+car1,8-1.5, 0.0);
    glEnd();


    //fortLight

    glColor3ub((k*100)%255, (k*100)%255, (k*100)%235);
    glBegin(GL_POLYGON);
    glVertex3f (-14.8+car1,5.5-1.5, 0.0);
    glVertex3f (-14.1+car1,5.5-1.5, 0.0);
    glVertex3f (-13.8+car1,6.5-1.5, 0.0);
    glVertex3f (-14.8+car1,6.5-1.5, 0.0);

    glEnd();



    //backLight

    glColor3ub((k*100)%255, (k*100)%255, (k*100)%235);
    glBegin(GL_POLYGON);
    glVertex3f (-4+car1,5.5-1.5, 0.0);
    glVertex3f (-3.2+car1,5.5-1.5, 0.0);
    glVertex3f (-3.2+car1,6.5-1.5, 0.0);
    glVertex3f (-4+car1,6.5-1.5, 0.0);

    glEnd();

    //BackWheel

    glColor3ub(13,13,15);
    circle(1,1,-12.5+car1,4.5-1.5,0,100);

    glColor3ub(90,90,90);
    circle(.8,.8,-12.5+car1,4.5-1.5,0,100);

    glColor3ub(13,13,15);
    circle(.4,.4,-12.5+car1,4.5-1.5,0,100);

    glColor3ub(230,230,230);
    circle(.3,.3,-12.5+car1,4.5-1.5,0,100);

    glColor3ub(13,13,15);
    circle(.1,.1,-12.5+car1,4.5-1.5,0,100);

    //fortWheel

     glColor3ub(13,13,15);
    circle(1,1,-5.5+car1,4.5-1.5,0,100);

    glColor3ub(90,90,90);
    circle(.8,.8,-5.5+car1,4.5-1.5,0,100);

    glColor3ub(13,13,15);
    circle(.4,.4,-5.5+car1,4.5-1.5,0,100);

    glColor3ub(230,230,230);
    circle(.3,.3,-5.5+car1,4.5-1.5,0,100);

    glColor3ub(13,13,15);
    circle(.1,.1,-5.5+car1,4.5-1.5,0,100);

}


void NightCar2()
{
    if(car2 >= 0)
    {
        car2 -= 0.1;

    }

    else{
        car2 =155;

    }


    int k=car2*5;

    glutPostRedisplay();

    //headLight

    glColor3ub(248,224,100);
    glBegin(GL_POLYGON);

    glVertex3f (-25+car2,2+2, 0.0);
    glVertex3f (-15+car2,5.5+2, 0.0);
    glVertex3f (-15+car2,6+2, 0.0);
    glVertex3f (-25+car2,9+2, 0.0);
    glEnd();

    glColor3ub(248,224,100);
    circle(4,3.5,-25+car2,5.5+2,25,75);



    glColor3ub(167,32,29);
    glBegin(GL_POLYGON);
    glVertex3f (-15+car2,4+2, 0.0);
    glVertex3f (-3+car2,4+2, 0.0);
    glVertex3f (-3+car2,10+2, 0.0);
    glVertex3f (-8+car2,10+2, 0.0);
    glVertex3f (-8+car2,10+2, 0.0);
    glVertex3f (-11+car2,10+2, 0.0);
    glVertex3f (-13+car2,8+2, 0.0);

    glVertex3f (-15+car2,7.5+2, 0.0);
    glEnd();

    //glass

 glColor3ub(40,218,228);
    glBegin(GL_POLYGON);
    glVertex3f (-8.5+car2,8+2, 0.0);
    glVertex3f (-8.5+car2,9.5+2, 0.0);
    glVertex3f (-11+car2,9.5+2, 0.0);
    glVertex3f (-12.5+car2,8+2, 0.0);
    glEnd();

    glColor3ub(40,218,228);
    glBegin(GL_POLYGON);
    glVertex3f (-3.5+car2,8+2, 0.0);
    glVertex3f (-3.5+car2,9.5+2, 0.0);
    glVertex3f (-8+car2,9.5+2, 0.0);
    glVertex3f (-8+car2,8+2, 0.0);
    glEnd();


    //fortLight

    glColor3ub((k*100)%255, (k*100)%255, (k*100)%235);
    glBegin(GL_POLYGON);
    glVertex3f (-14.8+car2,5.5+2, 0.0);
    glVertex3f (-14.1+car2,5.5+2, 0.0);
    glVertex3f (-13.8+car2,6.5+2, 0.0);
    glVertex3f (-14.8+car2,6.5+2, 0.0);

    glEnd();



    //backLight

    glColor3ub((k*100)%255, (k*100)%255, (k*100)%235);
    glBegin(GL_POLYGON);
    glVertex3f (-4+car2,5.5+2, 0.0);
    glVertex3f (-3.2+car2,5.5+2, 0.0);
    glVertex3f (-3.2+car2,6.5+2, 0.0);
    glVertex3f (-4+car2,6.5+2, 0.0);

    glEnd();

    //BackWheel

    glColor3ub(13,13,15);
    circle(1,1,-12.5+car2,4.5+2,0,100);

    glColor3ub(90,90,90);
    circle(.8,.8,-12.5+car2,4.5+2,0,100);

    glColor3ub(13,13,15);
    circle(.4,.4,-12.5+car2,4.5+2,0,100);

    glColor3ub(230,230,230);
    circle(.3,.3,-12.5+car2,4.5+2,0,100);

    glColor3ub(13,13,15);
    circle(.1,.1,-12.5+car2,4.5+2,0,100);

    //fortWheel

     glColor3ub(13,13,15);
    circle(1,1,-5.5+car2,4.5+2,0,100);

    glColor3ub(90,90,90);
    circle(.8,.8,-5.5+car2,4.5+2,0,100);

    glColor3ub(13,13,15);
    circle(.4,.4,-5.5+car2,4.5+2,0,100);

    glColor3ub(230,230,230);
    circle(.3,.3,-5.5+car2,4.5+2,0,100);

    glColor3ub(13,13,15);
    circle(.1,.1,-5.5+car2,4.5+2,0,100);

}


void AutoSun()
{

    if(autosun <= 145)
    {
        autosun += 0.015;

    }

    else
    {
        Background0();


        Nightroad();
        Building5();

        Tree1();
        Tree4();

        Building2();

        Building3();

        Tree2();
        Tree3();
        Building1();
        Building4();
        Building6();
        Tree5();
        Rain1();
        Cloud();
        NightCar2();
        NightCar1();

    }

    glutPostRedisplay();


    glColor3ub (248,248,0);
    circle(5,5,autosun,62,0,100);


}

void DayCloudFixed()
{
     if(dc <= 135)
    {
        dc += 0.02;
    }

    else{
        dc = -20;
    }

    glutPostRedisplay();


   for(int i=-500;i<=500;i=i+40)
   {
    glColor3ub(250,250,250);
    circle(5,5,i-8+dc,59,0,100);

    glColor3ub(250,250,250);
    circle(5,5,i-2+dc,59,0,100);

    glColor3ub(250,250,250);
    circle(5,5,i-10+dc,61,0,100);

    glColor3ub(250,250,250);
    circle(5,5,i-0+dc,61,0,100);

    glColor3ub(250,250,250);
    circle(7,7,i-5+dc,61,0,100);

   }
}


void DayCloudAuto()
{
     if(dc <= 155)
    {
        dc += 0.02;
    }

    else{
        //dc = -20;
    }

    glutPostRedisplay();


   for(int i=0;i<=135;i=i+40)
   {
    glColor3ub(250,250,250);
    circle(5,5,i-8+dc,59,0,100);

    glColor3ub(250,250,250);
    circle(5,5,i-2+dc,59,0,100);

    glColor3ub(250,250,250);
    circle(5,5,i-10+dc,61,0,100);

    glColor3ub(250,250,250);
    circle(5,5,i-0+dc,61,0,100);

    glColor3ub(250,250,250);
    circle(7,7,i-5+dc,61,0,100);

   }
}




void DayCar1()
{
     if(car1 >= 0)
    {
        car1 -= 0.09;

    }

    else{
        car1 =155;

    }
    //car1 =40;
    int k=car1*5;

    glutPostRedisplay();

    //headLight





    glColor3ub(6,54,103);
    glBegin(GL_POLYGON);
    glVertex3f (-15+car1,4-1.5, 0.0);
    glVertex3f (-3+car1,4-1.5, 0.0);
    glVertex3f (-3+car1,8-1.5, 0.0);
    glVertex3f (-8+car1,8-1.5, 0.0);
    glVertex3f (-8+car1,10-1.5, 0.0);
    glVertex3f (-11+car1,10-1.5, 0.0);
    glVertex3f (-13+car1,8-1.5, 0.0);

    glVertex3f (-15+car1,7.5-1.5, 0.0);
    glEnd();

    //glass

    glColor3ub(40,218,228);
    glBegin(GL_POLYGON);
    glVertex3f (-8.5+car1,8-1.5, 0.0);
    glVertex3f (-8.5+car1,9.5-1.5, 0.0);
    glVertex3f (-11+car1,9.5-1.5, 0.0);
    glVertex3f (-12.5+car1,8-1.5, 0.0);
    glEnd();


    //fortLight

    glColor3ub((k*100)%255, (k*100)%255, (k*100)%235);
    glBegin(GL_POLYGON);
    glVertex3f (-14.8+car1,5.5-1.5, 0.0);
    glVertex3f (-14.1+car1,5.5-1.5, 0.0);
    glVertex3f (-13.8+car1,6.5-1.5, 0.0);
    glVertex3f (-14.8+car1,6.5-1.5, 0.0);

    glEnd();



    //backLight

    glColor3ub((k*100)%255, (k*100)%255, (k*100)%235);
    glBegin(GL_POLYGON);
    glVertex3f (-4+car1,5.5-1.5, 0.0);
    glVertex3f (-3.2+car1,5.5-1.5, 0.0);
    glVertex3f (-3.2+car1,6.5-1.5, 0.0);
    glVertex3f (-4+car1,6.5-1.5, 0.0);

    glEnd();

    //BackWheel

    glColor3ub(13,13,15);
    circle(1,1,-12.5+car1,4.5-1.5,0,100);

    glColor3ub(90,90,90);
    circle(.8,.8,-12.5+car1,4.5-1.5,0,100);

    glColor3ub(13,13,15);
    circle(.4,.4,-12.5+car1,4.5-1.5,0,100);

    glColor3ub(230,230,230);
    circle(.3,.3,-12.5+car1,4.5-1.5,0,100);

    glColor3ub(13,13,15);
    circle(.1,.1,-12.5+car1,4.5-1.5,0,100);

    //fortWheel

     glColor3ub(13,13,15);
    circle(1,1,-5.5+car1,4.5-1.5,0,100);

    glColor3ub(90,90,90);
    circle(.8,.8,-5.5+car1,4.5-1.5,0,100);

    glColor3ub(13,13,15);
    circle(.4,.4,-5.5+car1,4.5-1.5,0,100);

    glColor3ub(230,230,230);
    circle(.3,.3,-5.5+car1,4.5-1.5,0,100);

    glColor3ub(13,13,15);
    circle(.1,.1,-5.5+car1,4.5-1.5,0,100);

}



void DayCar2()
{
    if(car2 >= 0)
    {
        car2 -= 0.1;

    }

    else{
        car2 =155;

    }


    int k=car2*5;

    glutPostRedisplay();

    //headLight





    glColor3ub(167,32,29);
    glBegin(GL_POLYGON);
    glVertex3f (-15+car2,4+2, 0.0);
    glVertex3f (-3+car2,4+2, 0.0);
    glVertex3f (-3+car2,10+2, 0.0);
    glVertex3f (-8+car2,10+2, 0.0);
    glVertex3f (-8+car2,10+2, 0.0);
    glVertex3f (-11+car2,10+2, 0.0);
    glVertex3f (-13+car2,8+2, 0.0);

    glVertex3f (-15+car2,7.5+2, 0.0);
    glEnd();

    //glass

 glColor3ub(40,218,228);
    glBegin(GL_POLYGON);
    glVertex3f (-8.5+car2,8+2, 0.0);
    glVertex3f (-8.5+car2,9.5+2, 0.0);
    glVertex3f (-11+car2,9.5+2, 0.0);
    glVertex3f (-12.5+car2,8+2, 0.0);
    glEnd();

    glColor3ub(40,218,228);
    glBegin(GL_POLYGON);
    glVertex3f (-3.5+car2,8+2, 0.0);
    glVertex3f (-3.5+car2,9.5+2, 0.0);
    glVertex3f (-8+car2,9.5+2, 0.0);
    glVertex3f (-8+car2,8+2, 0.0);
    glEnd();


    //fortLight

    glColor3ub((k*100)%255, (k*100)%255, (k*100)%235);
    glBegin(GL_POLYGON);
    glVertex3f (-14.8+car2,5.5+2, 0.0);
    glVertex3f (-14.1+car2,5.5+2, 0.0);
    glVertex3f (-13.8+car2,6.5+2, 0.0);
    glVertex3f (-14.8+car2,6.5+2, 0.0);

    glEnd();



    //backLight

    glColor3ub((k*100)%255, (k*100)%255, (k*100)%235);
    glBegin(GL_POLYGON);
    glVertex3f (-4+car2,5.5+2, 0.0);
    glVertex3f (-3.2+car2,5.5+2, 0.0);
    glVertex3f (-3.2+car2,6.5+2, 0.0);
    glVertex3f (-4+car2,6.5+2, 0.0);

    glEnd();

    //BackWheel

    glColor3ub(13,13,15);
    circle(1,1,-12.5+car2,4.5+2,0,100);

    glColor3ub(90,90,90);
    circle(.8,.8,-12.5+car2,4.5+2,0,100);

    glColor3ub(13,13,15);
    circle(.4,.4,-12.5+car2,4.5+2,0,100);

    glColor3ub(230,230,230);
    circle(.3,.3,-12.5+car2,4.5+2,0,100);

    glColor3ub(13,13,15);
    circle(.1,.1,-12.5+car2,4.5+2,0,100);

    //fortWheel

     glColor3ub(13,13,15);
    circle(1,1,-5.5+car2,4.5+2,0,100);

    glColor3ub(90,90,90);
    circle(.8,.8,-5.5+car2,4.5+2,0,100);

    glColor3ub(13,13,15);
    circle(.4,.4,-5.5+car2,4.5+2,0,100);

    glColor3ub(230,230,230);
    circle(.3,.3,-5.5+car2,4.5+2,0,100);

    glColor3ub(13,13,15);
    circle(.1,.1,-5.5+car2,4.5+2,0,100);

}





void keyboardFunc( unsigned char key,int x,int y)
{
switch( key )
    {
    case 'z':
	case 'Z':
		day=5;
		break;

	case 'x':
    case 'X':
		day=0;
		break;


    case 'c':
    case 'C':
		day=1;
		break;

    case 'v':
    case 'V':
		day=2;
		break;

    case 'a':
    case 'A':
		day=4;
		break;

    case 'n':
    case 'N':
		day=6;
		break;

    case 'd':
    case 'D':
		day=6;
		break;

    case 'b':
    case 'B':
		day=3;
		break;

    case 's':
    case 'S':
		car1 =40;
		car2 =80;
		break;

    };

}



void display(void)
{

    glClear (GL_COLOR_BUFFER_BIT);

    if(day==0)
    {
        Background1();


        Nightroad();
        Building5();

        Tree1();
        Tree4();

        Building2();

        Building3();

        Tree2();
        Tree3();
        Building1();
        Building4();
        Building6();
        Tree5();
        Rain1();
        Cloud();
        NightCar2();
        NightCar1();
        //PlaySound("banana.wav", NULL, SND_ASYNC|SND_FILENAME);
    }

    if(day==1)
    {
        Background2();

        Nightroad();
        Building5();

        Tree1();
        Tree4();

        Building2();

        Building3();

        Tree2();
        Tree3();
        Building1();
        Building4();
        Building6();
        Tree5();
        Rain2();
        Cloud();
        NightCar2();
        NightCar1();

    }

    if(day==2)
    {
        Background3();

        Nightroad();
        Building5();

        Tree1();
        Tree4();

        Building2();

        Building3();

        Tree2();
        Tree3();
        Building1();
        Building4();
        Building6();
        Tree5();
        Rain3();
        Cloud();
        NightCar2();
        NightCar1();

    }



    if(day==3)
    {
        Background4();

        Nightroad();
        Building5();

        Tree1();
        Tree4();

        Building2();

        Building3();

        Tree2();
        Tree3();
        Building1();
        Building4();
        Building6();
        Tree5();
        Rain4();
        Cloud();
        NightCar2();
        NightCar1();

    }

    if(day==4)
    {
        Background4();

        Dayroad();
        Building5();

        Tree1();
        Tree4();

        Building2();

        Building3();

        Tree2();
        Tree3();
        Building1();
        Building4();
        Building6();
        Tree5();
        AutoSun();
        DayCloudAuto();
        NightCar2();
        NightCar1();

    }

    if(day==5)
    {

        Background0();
        Nightroad();
        Building5();

        Tree1();
        Tree4();

        Building2();

        Building3();

        Tree2();
        Tree3();
        Building1();
        Building4();
        Building6();
        Tree5();
        Rain1();
        Cloud();
        NightCar2();
        NightCar1();
    }

    if(day==6)
    {
        Background4();

        Dayroad();
        Building5();

        Tree1();
        Tree4();

        Building2();

        Building3();

        Tree2();
        Tree3();
        Building1();
        Building4();
        Building6();
        Tree5();
        DaySun();
        DayCloudFixed();
        DayCar2();
        DayCar1();



    }



    glutSwapBuffers();
}





int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize (1350, 680);
glutInitWindowPosition (10, 10);
glutCreateWindow ("Final Project");
init ();


glutDisplayFunc(display);
glutKeyboardFunc(keyboardFunc);
glutMainLoop();


return 0;
}
