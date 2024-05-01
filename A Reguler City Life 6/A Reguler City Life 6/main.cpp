///ABRAR FAIYAZ
///RIFAT TASNIA ISLAM
///SADIA ISLAM
///DURJOY BARDHAN


#include<cstdio>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<math.h>

bool night = false;
bool rainday = false;


GLfloat positionSun = 0.0f;
GLfloat speedSun = 0.003f;
GLfloat positionMoon = 0.0f;
GLfloat speedMoon = 0.003f;
GLfloat positionCloud1 = 0.0f;
GLfloat speedCloud1 = 0.005f;
GLfloat positionCloud2 = 0.0f;
GLfloat speedCloud2 = 0.004f;
GLfloat positionRain = 0.0f;
GLfloat speedRain = 0.03f;
GLfloat positionGreenBus = 0.0f;
GLfloat speedGreenBus = 0.01f;
GLfloat positionBlueBus = 0.0f;
GLfloat speedBlueBus = 0.016f;
GLfloat positionCyanCar = 0.0f;
GLfloat speedCyanCar = 0.02f;
GLfloat positionTrain = 0.0f;
GLfloat speedTrain = 0.01f;
GLfloat positionOrangeCar = 0.0f;
GLfloat speedOrangeCar = 0.03f;
GLfloat positionOliveCar = 0.0f;
GLfloat speedOliveCar = 0.02f;

void Quad(GLfloat ax,GLfloat ay,GLfloat bx,GLfloat by,GLfloat cx,GLfloat cy,GLfloat dx,GLfloat dy,GLfloat cr,GLfloat cg,GLfloat cb,GLfloat ca=1.0f)
{
   glBegin(GL_QUADS);
    glColor4f(cr,cg,cb,ca);
   glVertex2f(ax,ay);
   glVertex2f(bx,by);
   glVertex2f(cx, cy);
   glVertex2f(dx, dy);
   glEnd();
}

void Triangle(GLfloat ax,GLfloat ay,GLfloat bx,GLfloat by,GLfloat cx,GLfloat cy,GLfloat cr,GLfloat cg,GLfloat cb,GLfloat ca=1.0)
{
    glBegin(GL_TRIANGLES);
   glColor4f(cr,cg,cb,ca);
   glVertex2f(ax,ay);
   glVertex2f(bx,by);
   glVertex2f(cx, cy);
   glEnd();
}

void Circle(float x, float y, float radius, int triangleAmount)
{
    float twicePi=2.0f*3.1415926f;
   glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(int i = 0; i <= triangleAmount;i++)
            {
                glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
                    y + (radius * sin(i * twicePi / triangleAmount))
                );
		}
	glEnd();

}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speedTrain += 0.01f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}
	else if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			speedTrain -= 0.01f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}

void updateMoon(int x)
{
    if(positionMoon >= .85)
    {
         positionMoon = positionMoon;
    }
    else
    {
    positionMoon+= speedMoon;
    }

 glutPostRedisplay();
 glutTimerFunc(100, updateMoon, 0);

}

void updateSun(int x)
{
    if(positionSun >= .75)
    {
         positionSun = positionSun;
    }
    else
    {
    positionSun+= speedSun;
    }

 glutPostRedisplay();
 glutTimerFunc(100, updateSun, 0);

}

void updateCloud1(int value)
{

    if(positionCloud1 > 1.6)
    {
        positionCloud1 = -1.2f;
    }
    else
    {
        positionCloud1 += speedCloud1;
    }

	glutPostRedisplay();
	glutTimerFunc(100, updateCloud1, 0);
}


void updateCloud2(int value)
{

    if(positionCloud2 > 1.6)
    {
        positionCloud2 = -1.2f;
    }
    else
    {
        positionCloud2 += speedCloud2;
    }
	glutPostRedisplay();
	glutTimerFunc(100, updateCloud2, 0);
}

void updateGreenBus(int value)
{

    if(positionGreenBus > 1.9)
    {
        positionGreenBus = -1.2f;
    }
    else
    {
        positionGreenBus+= speedGreenBus;
    }
	glutPostRedisplay();
	glutTimerFunc(100, updateGreenBus, 0);
}

void updateBlueBus(int value)
{

    if(positionBlueBus > 1.4)
    {
        positionBlueBus = -1.9f;
    }
    else
    {
        positionBlueBus+= speedBlueBus;
    }
	glutPostRedisplay();
	glutTimerFunc(100, updateBlueBus, 0);
}

void updateCyanCar(int value)
{

    if(positionCyanCar > 1.6)
    {
        positionCyanCar = -1.6f;
    }
    else
    {
        positionCyanCar+= speedCyanCar;
    }
	glutPostRedisplay();
	glutTimerFunc(100, updateCyanCar, 0);
}
void updateOliveCar(int value)
{

    if(positionOliveCar < -1.6)
    {
        positionOliveCar = 2.2f;
    }
    else
    {
        positionOliveCar -= speedOliveCar;
    }
	glutPostRedisplay();
	glutTimerFunc(100, updateOliveCar, 0);
}
void updateOrangeCar(int value)
{

    if(positionOrangeCar < -1.5)
    {
        positionOrangeCar = 2.2f;
    }
    else
    {
        positionOrangeCar -= speedOrangeCar;
    }
	glutPostRedisplay();
	glutTimerFunc(100, updateOrangeCar, 0);
}
void updateRain(int value)
{

	if(positionRain < -0.5)
    {
        positionRain = 0.03f;
    }
    else
    {
        positionRain -= speedRain;
    }

	glutPostRedisplay();
	glutTimerFunc(100, updateRain, 0);
}

void updateTrain(int value)
{
    if(positionTrain < -1.5)
    {
        positionTrain = 2.2f;
    }
    else
    {
        positionTrain -= speedTrain;
    }

	glutPostRedisplay();
	glutTimerFunc(30, updateTrain, 0);
}

void drawSky()
{
    glBegin(GL_POLYGON);
    glColor3f(0.2f, 1.0f, .8f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
	glEnd();
}

void drawskynight()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.15f, 0.15f, 0.15f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
	glEnd();
	glPopMatrix();
}

void drawskyrain()
{
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.7f, 0.9f);
	glVertex2f(-1.0f, 0.0f);
	glVertex2f(1.0f, 0.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
	glEnd();
	glPopMatrix();
}

void drawsun()
{
    //Sun
    glPushMatrix();
    glTranslated(.0f,positionSun,.0f);
    glColor3f(1.0f,0.6f,0.0f);
    Circle(0.60,0.0,.08,200);
    glPopMatrix();
}

void drawmoon()
{
    //Moon
    glPushMatrix();
    glTranslated(.0f,positionMoon,.0f);
    glColor3f(1.0f,1.0f,1.0f);
    Circle(0.60,0.0,.06,200);
    glPopMatrix();
}

void drawcloud()
{
    //cloud1
    glTranslatef(positionCloud1,0.0f, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(-0.1f, 0.8f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(0.025f, 0.65f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(0.075f, 0.75f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(0.0f, 0.825f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(-0.1f, 0.7f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(0.0f, 0.75f, 0.075f, 100);
    glLoadIdentity();

    //cloud2
    glTranslatef(positionCloud2,0.0, 0.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(-0.5f, 0.75f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(-0.625f, 0.75f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(-0.425f, 0.675f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(-0.4f, 0.8f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(-0.575f, 0.825f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(-0.475f, 0.875f, 0.075f, 100);
    glColor3f(1.0f, 1.0f, 1.0f);
    Circle(-0.55f, 0.675f, 0.075f, 100);
    glLoadIdentity();
}

void drawnightcloud()
{
    //cloud1
    glTranslatef(positionCloud1,0.0, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(-0.1f, 0.8f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(0.025f, 0.65f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(0.075f, 0.75f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(0.0f, 0.825f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(-0.1f, 0.7f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(0.0f, 0.75f, 0.075f, 100);
    glLoadIdentity();

    //cloud2
    glTranslatef(positionCloud2,0.0, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(-0.5f, 0.75f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(-0.625f, 0.75f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(-0.425f, 0.675f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(-0.4f, 0.8f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(-0.575f, 0.825f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(-0.475f, 0.875f, 0.075f, 100);
    glColor3f(0.7f, 0.7f, 0.7f);
    Circle(-0.55f, 0.675f, 0.075f, 100);
    glLoadIdentity();
}

void drawraincloud()
{
    //cloud1
    glTranslatef(positionCloud1,0.0f, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    Circle(-0.1f, 0.8f, 0.075f, 100);
    Circle(0.025f, 0.65f, 0.075f, 100);
    Circle(0.075f, 0.75f, 0.075f, 100);
    Circle(0.0f, 0.825f, 0.075f, 100);
    Circle(-0.1f, 0.7f, 0.075f, 100);
    Circle(0.0f, 0.75f, 0.075f, 100);
    glLoadIdentity();

    //cloud2
    glTranslatef(positionCloud2,0.0, 0.0f);
    glColor3f(0.1f, 0.1f, 0.1f);
    Circle(-0.5f, 0.75f, 0.075f, 100);
    Circle(-0.625f, 0.75f, 0.075f, 100);
    Circle(-0.425f, 0.675f, 0.075f, 100);
    Circle(-0.4f, 0.8f, 0.075f, 100);
    Circle(-0.575f, 0.825f, 0.075f, 100);
    Circle(-0.475f, 0.875f, 0.075f, 100);
    Circle(-0.55f, 0.675f, 0.075f, 100);
    glLoadIdentity();
}

void drawBuilding()
{

    glPushMatrix();
    ///Hospital
    glScalef(1.2f,1.2f,1.2f);
    glColor3f(0.75f, 0.59f, 0.34f);
    Circle(0.0f, 0.4f, .1f, 100);
    glColor3f(0.75f, 0.59f, 0.34f);
	glBegin(GL_QUADS);

	glVertex2f(-0.25f,0.0f);
	glVertex2f(-0.25f,0.4f);
	glVertex2f(0.25f,0.4f);
    glVertex2f(0.25f,0.0f);
	glEnd();

	glColor3f(0.75f, 0.59f, 0.34f);
	glBegin(GL_QUADS);

	glVertex2f(-0.25f,0.45f);
	glVertex2f(-0.175f,0.45f);
    glVertex2f(-0.175f,0.4f);
    glVertex2f(-0.25f,0.4f);
    glEnd();

    glColor3f(0.75f, 0.59f, 0.34f);
	glBegin(GL_QUADS);

	glVertex2f(0.25f,0.45f);
	glVertex2f(0.175f,0.45f);
    glVertex2f(0.175f,0.4f);
    glVertex2f(0.25f,0.4f);
    glEnd();

  ///////////////////////////////

  //Right big box
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

	glVertex2f(0.05f,0.0f);
	glVertex2f(0.05f,0.325f);
	glVertex2f(0.225f,0.325f);
	glVertex2f(0.225f,0.0f);
    glEnd();

    //1,1(right)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(0.075f,0.3f);
	glVertex2f(0.125f,0.3f);
	glVertex2f(0.125f,0.225f);
	glVertex2f(0.075f,0.225f);
    glEnd();

    //1,2(right)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(0.15f,0.3f);
	glVertex2f(0.2f,0.3f);
	glVertex2f(0.2f,0.225f);
	glVertex2f(0.15f,0.225f);
    glEnd();

    //2,1(right)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(0.075f,0.2f);
	glVertex2f(0.125f,0.2f);
	glVertex2f(0.125f,0.125f);
	glVertex2f(0.075f,0.125f);
    glEnd();

    //2,2(right)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(0.15f,0.2f);
	glVertex2f(0.2f,0.2f);
	glVertex2f(0.2f,0.125f);
	glVertex2f(0.15f,0.125f);
    glEnd();

    //3,1(right)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(0.075f,0.1f);
	glVertex2f(0.125f,0.1f);
	glVertex2f(0.125f,0.025f);
	glVertex2f(0.075f,0.025f);
    glEnd();

    //3,2(right)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(0.15f,0.1f);
	glVertex2f(0.2f,0.1f);
	glVertex2f(0.2f,0.025f);
	glVertex2f(0.15f,0.025f);
    glEnd();



    //Left big box
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

	glVertex2f(-0.05f,0.0f);
	glVertex2f(-0.05f,0.325f);
	glVertex2f(-0.225f,0.325f);
	glVertex2f(-0.225f,0.0f);
    glEnd();

     //1,1(left)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(-0.15f,0.3f);
	glVertex2f(-0.2f,0.3f);
	glVertex2f(-0.2f,0.225f);
	glVertex2f(-0.15f,0.225f);
    glEnd();

     //1,2(left)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(-0.075f,0.3f);
	glVertex2f(-0.125f,0.3f);
	glVertex2f(-0.125f,0.225f);
	glVertex2f(-0.075f,0.225f);
    glEnd();



     //2,1(left)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(-0.15f,0.2f);
	glVertex2f(-0.2f,0.2f);
	glVertex2f(-0.2f,0.125f);
	glVertex2f(-0.15f,0.125f);
    glEnd();

    //2,2(left)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(-0.075f,0.2f);
	glVertex2f(-0.125f,0.2f);
	glVertex2f(-0.125f,0.125f);
	glVertex2f(-0.075f,0.125f);
    glEnd();



    //3,1(left)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(-0.15f,0.1f);
	glVertex2f(-0.2f,0.1f);
	glVertex2f(-0.2f,0.025f);
	glVertex2f(-0.15f,0.025f);
    glEnd();

    //3,2(left)
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

	glVertex2f(-0.075f,0.1f);
	glVertex2f(-0.125f,0.1f);
	glVertex2f(-0.125f,0.025f);
	glVertex2f(-0.075f,0.025f);
    glEnd();





    //Middle box1
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.025f,0.375f);
    glVertex2f(0.025f,0.375f);
	glVertex2f(0.025f,0.3f);
	glVertex2f(-0.025f,0.3f);
    glEnd();

    //middle box2
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.025f,0.275f);
    glVertex2f(0.025f,0.275f);
	glVertex2f(0.025f,0.2f);
	glVertex2f(-0.025f,0.2f);
    glEnd();

    //middle box3
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.025f,0.1f);
    glVertex2f(0.025f,0.1f);
	glVertex2f(0.025f,0.175f);
	glVertex2f(-0.025f,0.175f);
    glEnd();

    //middle box4
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.035f,0.082f);
    glVertex2f(0.035f,0.082f);
	glVertex2f(0.035f,0.0f);
	glVertex2f(-0.035f,0.0f);
    glEnd();

    //middle door line
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);

    glVertex2f(0.0f,0.082f);
    glVertex2f(0.0f,0.0f);

    glEnd();


    //Plus Sign
    //updown
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.0125,0.48);
    glVertex2f(0.0125f,0.48f);
    glVertex2f(0.0125f,0.38f);
    glVertex2f(-0.0125f,0.38f);
    glEnd();

    //left-right
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.0375f,0.45f);
    glVertex2f(0.0375f,0.45f);
    glVertex2f(0.0375f,0.41f);
    glVertex2f(-0.0375f,0.41f);
    glEnd();

    glLoadIdentity();
///////////////////////////////////////////////////////////////////////////////////////////////ending of Hospital draw///////////////////////////////////////////////////////////////////////

    ///left building beside hospital
    glColor3ub(205, 163, 33);
    glBegin(GL_QUADS);

    glVertex2f(-0.35f,0.25f);
    glVertex2f(-0.35f,0.0f);
    glVertex2f(-0.65f,0.0f);
    glVertex2f(-0.65f,0.25f);
    glEnd();

    //left 1st floor shed
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.34f,0.27f);
    glVertex2f(-0.34f,0.25f);
    glVertex2f(-0.66f,0.25f);
    glVertex2f(-0.66f,0.27f);
    glEnd();

    //left window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.58f,0.24f);
    glVertex2f(-0.58f,0.01f);
    glVertex2f(-0.64f,0.01f);
    glVertex2f(-0.64f,0.24f);
    glEnd();

    //left up window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.59f,0.23f);
    glVertex2f(-0.59f,0.17f);
    glVertex2f(-0.63f,0.17f);
    glVertex2f(-0.63f,0.23f);
    glEnd();


    //left middle window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.59f,0.15f);
    glVertex2f(-0.59f,0.09f);
    glVertex2f(-0.63f,0.09f);
    glVertex2f(-0.63f,0.15f);
    glEnd();

    //left down window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.59f,0.07f);
    glVertex2f(-0.59f,0.01f);
    glVertex2f(-0.63f,0.01f);
    glVertex2f(-0.63f,0.07f);
    glEnd();


    //Right window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.36f,0.24f);
    glVertex2f(-0.36f,0.01f);
    glVertex2f(-0.42f,0.01f);
    glVertex2f(-0.42f,0.24f);
    glEnd();

    //Right up window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.37f,0.23f);
    glVertex2f(-0.37f,0.17f);
    glVertex2f(-0.41f,0.17f);
    glVertex2f(-0.41f,0.23f);
    glEnd();


    //Right middle window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.37f,0.15f);
    glVertex2f(-0.37f,0.09f);
    glVertex2f(-0.41f,0.09f);
    glVertex2f(-0.41f,0.15f);
    glEnd();

    //Right down window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.37f,0.07f);
    glVertex2f(-0.37f,0.01f);
    glVertex2f(-0.41f,0.01f);
    glVertex2f(-0.41f,0.07f);
    glEnd();

    //left middle window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.59f,0.15f);
    glVertex2f(-0.59f,0.09f);
    glVertex2f(-0.63f,0.09f);
    glVertex2f(-0.63f,0.15f);
    glEnd();

    //1st floor triangle
    glColor3ub(139, 69, 19);
    glBegin(GL_TRIANGLES);

    glVertex2f(-0.5f,0.23f);
    glVertex2f(-0.43f,0.15f);
    glVertex2f(-0.57f,0.15f);
    glEnd();

    //1st floor white door
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.44f,0.15f);
    glVertex2f(-0.44f,0.0f);
    glVertex2f(-0.56f,0.0f);
    glVertex2f(-0.56f,0.15f);
    glEnd();

    //1st floor main door
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.46f,0.11f);
    glVertex2f(-0.46f,0.0f);
    glVertex2f(-0.54f,0.0f);
    glVertex2f(-0.54f,0.11f);
    glEnd();

    //main door line
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);

    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.5f,0.11f);
    glEnd();

    //left building 2nd floor
    glColor3ub(205, 163, 33);
    glBegin(GL_QUADS);

    glVertex2f(-0.4f,0.35f);
    glVertex2f(-0.4f,0.27f);
    glVertex2f(-0.6f,0.27f);
    glVertex2f(-0.6f,0.35f);
    glEnd();


    //2nd floor triangle
    glColor3ub(139, 69, 19);
    glBegin(GL_TRIANGLES);

    glVertex2f(-0.5f,0.43f);
    glVertex2f(-0.38f,0.35f);
    glVertex2f(-0.62f,0.35f);
    glEnd();
/////////////////////////////////////////////////////////////////////////////////////////////

    ///left building 2
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);

    glVertex2f(-0.7f,0.24f);
    glVertex2f(-0.7f,0.0f);
    glVertex2f(-0.95f,0.0f);
    glVertex2f(-0.95f,0.24f);
    glEnd();

    //left building 2 1st floor door border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.86f,0.16f);
    glVertex2f(-0.86f,0.0f);
    glVertex2f(-0.93f,0.0f);
    glVertex2f(-0.93f,0.16f);
    glEnd();

    //left building 2 1st floor door
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.87f,0.15f);
    glVertex2f(-0.87f,0.0f);
    glVertex2f(-0.92f,0.0f);
    glVertex2f(-0.92f,0.15f);
    glEnd();

    //left building 2 1st floor window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.73f,0.17f);
    glVertex2f(-0.73f,0.04f);
    glVertex2f(-0.81f,0.04f);
    glVertex2f(-0.81f,0.17f);
    glEnd();

    //left building 2 1st floor window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.74f,0.16f);
    glVertex2f(-0.74f,0.05f);
    glVertex2f(-0.8f,0.05f);
    glVertex2f(-0.8f,0.16f);
    glEnd();


    //left building 2 1st floor shed
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.7f,0.25f);
    glVertex2f(-0.7f,0.24f);
    glVertex2f(-0.95f,0.24f);
    glVertex2f(-0.95f,0.25f);
    glEnd();

    //left building 2 2nd floor
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);

    glVertex2f(-0.71f,0.35f);
    glVertex2f(-0.71f,0.25f);
    glVertex2f(-0.85f,0.25f);
    glVertex2f(-0.85f,0.35f);
    glEnd();

    //left building 2 2nd floor shed
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.7f,0.37f);
    glVertex2f(-0.7f,0.35f);
    glVertex2f(-0.86f,0.35f);
    glVertex2f(-0.86f,0.37f);
    glEnd();

    //left building 2 2nd floor door
    glColor3f(0.0f, 0.5f, 0.6f);
    glBegin(GL_QUADS);

    glVertex2f(-0.79f,0.34f);
    glVertex2f(-0.79f,0.25f);
    glVertex2f(-0.84f,0.25f);
    glVertex2f(-0.84f,0.34f);
    glEnd();

    //left building 2 2nd floor window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.72f,0.34f);
    glVertex2f(-0.72f,0.27f);
    glVertex2f(-0.78f,0.27f);
    glVertex2f(-0.78f,0.34f);
    glEnd();


    //left building 2 2nd floor window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(-0.73f,0.33f);
    glVertex2f(-0.73f,0.28f);
    glVertex2f(-0.77f,0.28f);
    glVertex2f(-0.77f,0.33f);
    glEnd();

    //left building 2 roof oporer piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.7f,0.3f);
    glVertex2f(-0.7f,0.29f);
    glVertex2f(-0.95f,0.29f);
    glVertex2f(-0.95f,0.3f);
    glEnd();

    //left building 2 1st floor left 1 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.93f,0.29f);
    glVertex2f(-0.93f,0.25f);
    glVertex2f(-0.94f,0.25f);
    glVertex2f(-0.94f,0.29f);
    glEnd();

    //left building 2 1st floor left 2 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.90f,0.29f);
    glVertex2f(-0.90f,0.25f);
    glVertex2f(-0.91f,0.25f);
    glVertex2f(-0.91f,0.29f);
    glEnd();

    //left building 2 1st floor left 3 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.87f,0.29f);
    glVertex2f(-0.87f,0.25f);
    glVertex2f(-0.88f,0.25f);
    glVertex2f(-0.88f,0.29f);
    glEnd();

    //left building 2 1st floor left 4 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.84f,0.29f);
    glVertex2f(-0.84f,0.25f);
    glVertex2f(-0.85f,0.25f);
    glVertex2f(-0.85f,0.29f);
    glEnd();

    //left building 2 1st floor left 5 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.81f,0.29f);
    glVertex2f(-0.81f,0.25f);
    glVertex2f(-0.82f,0.25f);
    glVertex2f(-0.82f,0.29f);
    glEnd();

    //left building 2 1st floor left 6 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.78f,0.29f);
    glVertex2f(-0.78f,0.25f);
    glVertex2f(-0.79f,0.25f);
    glVertex2f(-0.79f,0.29f);
    glEnd();

    //left building 2 1st floor left 7 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.75f,0.29f);
    glVertex2f(-0.75f,0.25f);
    glVertex2f(-0.76f,0.25f);
    glVertex2f(-0.76f,0.29f);
    glEnd();

    //left building 2   1st floor left 7 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.72f,0.29f);
    glVertex2f(-0.72f,0.25f);
    glVertex2f(-0.73f,0.25f);
    glVertex2f(-0.73f,0.29f);
    glEnd();
//////////////////////////////////////////////////////////////////////////////////////////

///Right building beside Hospital
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);

    glVertex2f(0.58,0.45f);
    glVertex2f(0.58f,0.0f);
    glVertex2f(0.35f,0.0f);
    glVertex2f(0.35f,0.45f);
    glEnd();

    //Right building beside Hospital roof shed
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(0.59,0.48f);
    glVertex2f(0.59f,0.45f);
    glVertex2f(0.34f,0.45f);
    glVertex2f(0.34f,0.48f);
    glEnd();


    //Right building beside Hospital 3rd floor left window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.42,0.43f);
    glVertex2f(0.42f,0.31f);
    glVertex2f(0.36f,0.31f);
    glVertex2f(0.36f,0.43f);
    glEnd();

    //Right building beside Hospital 3rd floor left window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(0.41,0.42f);
    glVertex2f(0.41f,0.32f);
    glVertex2f(0.37f,0.32f);
    glVertex2f(0.37f,0.42f);
    glEnd();

//Right building beside Hospital 3rd floor middle window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.5,0.43f);
    glVertex2f(0.5f,0.31f);
    glVertex2f(0.43f,0.31f);
    glVertex2f(0.43f,0.43f);
    glEnd();

//Right building beside Hospital 3rd floor middle window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(0.49,0.42f);
    glVertex2f(0.49f,0.32f);
    glVertex2f(0.44f,0.32f);
    glVertex2f(0.44f,0.42f);
    glEnd();

    //Right building beside Hospital 3rd floor right window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.57,0.43f);
    glVertex2f(0.57f,0.31f);
    glVertex2f(0.51f,0.31f);
    glVertex2f(0.51f,0.43f);
    glEnd();
     //Right building beside Hospital 3rd floor right window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(0.56,0.42f);
    glVertex2f(0.56f,0.32f);
    glVertex2f(0.52f,0.32f);
    glVertex2f(0.52f,0.42f);
    glEnd();

    //Right building beside Hospital 2nd floor left window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.45,0.29f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.36f,0.29f);
    glEnd();

    //Right building beside Hospital 2nd floor left window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(0.44,0.28f);
    glVertex2f(0.44f,0.18f);
    glVertex2f(0.37f,0.18f);
    glVertex2f(0.37f,0.28f);
    glEnd();

    //Right building beside Hospital 2nd floor right window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.57,0.29f);
    glVertex2f(0.57f,0.17f);
    glVertex2f(0.48f,0.17f);
    glVertex2f(0.48f,0.29f);
    glEnd();

    //Right building beside Hospital 2nd floor right window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(0.56,0.28f);
    glVertex2f(0.56f,0.18f);
    glVertex2f(0.49f,0.18f);
    glVertex2f(0.49f,0.28f);
    glEnd();

    //Right building beside Hospital door border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.44,0.14f);
    glVertex2f(0.44f,0.0f);
    glVertex2f(0.37f,0.0f);
    glVertex2f(0.37f,0.14f);
    glEnd();
    //Right building beside Hospital door
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(0.43,0.13f);
    glVertex2f(0.43f,0.0f);
    glVertex2f(0.38f,0.0f);
    glVertex2f(0.38f,0.13f);
    glEnd();

    //Right building beside Hospital 1st floor window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.56,0.13f);
    glVertex2f(0.56f,0.04f);
    glVertex2f(0.47f,0.04f);
    glVertex2f(0.47f,0.13f);
    glEnd();

    //Right building beside Hospital 1st floor window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(0.55,0.12f);
    glVertex2f(0.55f,0.03f);
    glVertex2f(0.48f,0.03f);
    glVertex2f(0.48f,0.12f);
    glEnd();

    //Right building beside Hospital 1st floor  window r nich
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.57f,0.04f);
    glVertex2f(0.57f,0.02f);
    glVertex2f(0.46f,0.02f);
    glVertex2f(0.46f,0.04f);
    glEnd();

    //Right building beside Hospital 1st floor window left 1st red
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.49f,0.13f);
    glVertex2f(0.49f,0.08f);
    glVertex2f(0.47f,0.08f);
    glVertex2f(0.47f,0.13f);
    glEnd();

    //Right building beside Hospital 1st floor window left 1st white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.51f,0.13f);
    glVertex2f(0.51f,0.08f);
    glVertex2f(0.49f,0.08f);
    glVertex2f(0.49f,0.13f);
    glEnd();

    //Right building beside Hospital 1st floor window 2nd red
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.53f,0.13f);
    glVertex2f(0.53f,0.08f);
    glVertex2f(0.51f,0.08f);
    glVertex2f(0.51f,0.13f);
    glEnd();

    //Right building beside Hospital 1st floor window left 1st white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.55f,0.13f);
    glVertex2f(0.55f,0.08f);
    glVertex2f(0.53f,0.08f);
    glVertex2f(0.53f,0.13f);
    glEnd();
    //Right building beside Hospital 1st floor window left 1st red
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.56f,0.13f);
    glVertex2f(0.56f,0.08f);
    glVertex2f(0.55f,0.08f);
    glVertex2f(0.55f,0.13f);
    glEnd();

///////////////////////////////////////////////////////////////////////////////////

///Right 2nd building
glScalef(1.0f,1.1f,1.1f);
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);

    glVertex2f(0.64,0.3f);
    glVertex2f(0.64f,0.0f);
    glVertex2f(0.85f,0.0f);
    glVertex2f(0.85f,0.3f);
    glEnd();

    //Right 2nd building shed
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(0.63,0.33f);
    glVertex2f(0.63f,0.3f);
    glVertex2f(0.86f,0.3f);
    glVertex2f(0.86f,0.33f);
    glEnd();

    //Right 2nd building left window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.66,0.28f);
    glVertex2f(0.66f,0.19f);
    glVertex2f(0.73f,0.19f);
    glVertex2f(0.73f,0.28f);
    glEnd();

    //Right 2nd building left window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(0.67,0.27f);
    glVertex2f(0.67f,0.2f);
    glVertex2f(0.72f,0.2f);
    glVertex2f(0.72f,0.27f);
    glEnd();


    //Right 2nd building right window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.76,0.28f);
    glVertex2f(0.76f,0.19f);
    glVertex2f(0.83f,0.19f);
    glVertex2f(0.83f,0.28f);
    glEnd();

    //Right 2nd building right window
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(0.77,0.27f);
    glVertex2f(0.77f,0.2f);
    glVertex2f(0.82f,0.2f);
    glVertex2f(0.82f,0.27f);
    glEnd();

    //Right 2nd building triangle shed
    glColor3ub(139, 69, 19);
    glBegin(GL_TRIANGLES);

    glVertex2f(0.75,0.18f);
    glVertex2f(0.80f,0.11f);
    glVertex2f(0.69f,0.11f);
    glEnd();

    //Right 2nd building door border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.78,0.11f);
    glVertex2f(0.78f,0.0f);
    glVertex2f(0.71f,0.0f);
    glVertex2f(0.71f,0.11f);
    glEnd();

    //Right 2nd building door
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(0.77,0.09f);
    glVertex2f(0.77f,0.0f);
    glVertex2f(0.72f,0.0f);
    glVertex2f(0.72f,0.09f);
    glEnd();

    //Right 2nd building 2nd floor
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);

    glVertex2f(0.72,0.41f);
    glVertex2f(0.72f,0.33f);
    glVertex2f(0.84f,0.33f);
    glVertex2f(0.84f,0.41f);
    glEnd();

    //Right 2nd building 2nd floor shed
    glColor3ub(139, 63, 19);
    glBegin(GL_QUADS);

    glVertex2f(0.71,0.43f);
    glVertex2f(0.71f,0.41f);
    glVertex2f(0.85f,0.41f);
    glVertex2f(0.85f,0.43f);
    glEnd();

    //Right 2nd building 1st floor left window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.65,0.10f);
    glVertex2f(0.65f,0.02f);
    glVertex2f(0.70f,0.02f);
    glVertex2f(0.70f,0.10f);
    glEnd();

    //Right 2nd building 1st floor left window border
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(0.66,0.09f);
    glVertex2f(0.66f,0.03f);
    glVertex2f(0.69f,0.03f);
    glVertex2f(0.69f,0.09f);
    glEnd();


    //Right 2nd building 1st floor right window border
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.79,0.10f);
    glVertex2f(0.79f,0.02f);
    glVertex2f(0.84f,0.02f);
    glVertex2f(0.84f,0.10f);
    glEnd();

    //Right 2nd building 1st floor right window border
    glColor3f(0.0f, 0.7f, 0.8f);
    glBegin(GL_QUADS);

    glVertex2f(0.80,0.09f);
    glVertex2f(0.80f,0.03f);
    glVertex2f(0.83f,0.03f);
    glVertex2f(0.83f,0.09f);
    glEnd();
    glLoadIdentity();


    glPopMatrix();

	//glutSwapBuffers();
}

void drawbuildingnight()
{

    glPushMatrix();
    ///Hospital
    glScalef(1.2f,1.2f,1.2f);
   glColor3f(0.55f, 0.49f, 0.24f);
Circle(0.0f, 0.4f, .1f, 100);
glColor3f(0.55f, 0.49f, 0.24f);
	glBegin(GL_QUADS);

	glVertex2f(-0.25f,0.0f);
	glVertex2f(-0.25f,0.4f);
	glVertex2f(0.25f,0.4f);
    glVertex2f(0.25f,0.0f);
	glEnd();

	glColor3f(0.55f, 0.49f, 0.24f);
	glBegin(GL_QUADS);

	glVertex2f(-0.25f,0.45f);
	glVertex2f(-0.175f,0.45f);
    glVertex2f(-0.175f,0.4f);
    glVertex2f(-0.25f,0.4f);
    glEnd();

    glColor3f(0.55f, 0.49f, 0.24f);
	glBegin(GL_QUADS);

	glVertex2f(0.25f,0.45f);
	glVertex2f(0.175f,0.45f);
    glVertex2f(0.175f,0.4f);
    glVertex2f(0.25f,0.4f);
    glEnd();

  ///////////////////////////////

  //Rigt big box
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

	glVertex2f(0.05f,0.0f);
	glVertex2f(0.05f,0.325f);
	glVertex2f(0.225f,0.325f);
	glVertex2f(0.225f,0.0f);
    glEnd();

    //1,1(right)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(0.075f,0.3f);
	glVertex2f(0.125f,0.3f);
	glVertex2f(0.125f,0.225f);
	glVertex2f(0.075f,0.225f);
    glEnd();

    //1,2(right)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(0.15f,0.3f);
	glVertex2f(0.2f,0.3f);
	glVertex2f(0.2f,0.225f);
	glVertex2f(0.15f,0.225f);
    glEnd();

    //2,1(right)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(0.075f,0.2f);
	glVertex2f(0.125f,0.2f);
	glVertex2f(0.125f,0.125f);
	glVertex2f(0.075f,0.125f);
    glEnd();

    //2,2(right)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(0.15f,0.2f);
	glVertex2f(0.2f,0.2f);
	glVertex2f(0.2f,0.125f);
	glVertex2f(0.15f,0.125f);
    glEnd();

    //3,1(right)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(0.075f,0.1f);
	glVertex2f(0.125f,0.1f);
	glVertex2f(0.125f,0.025f);
	glVertex2f(0.075f,0.025f);
    glEnd();

    //3,2(right)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(0.15f,0.1f);
	glVertex2f(0.2f,0.1f);
	glVertex2f(0.2f,0.025f);
	glVertex2f(0.15f,0.025f);
    glEnd();



    //Left big box
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);

	glVertex2f(-0.05f,0.0f);
	glVertex2f(-0.05f,0.325f);
	glVertex2f(-0.225f,0.325f);
	glVertex2f(-0.225f,0.0f);
    glEnd();

     //1,1(left)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(-0.15f,0.3f);
	glVertex2f(-0.2f,0.3f);
	glVertex2f(-0.2f,0.225f);
	glVertex2f(-0.15f,0.225f);
    glEnd();

     //1,2(left)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(-0.075f,0.3f);
	glVertex2f(-0.125f,0.3f);
	glVertex2f(-0.125f,0.225f);
	glVertex2f(-0.075f,0.225f);
    glEnd();



     //2,1(left)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(-0.15f,0.2f);
	glVertex2f(-0.2f,0.2f);
	glVertex2f(-0.2f,0.125f);
	glVertex2f(-0.15f,0.125f);
    glEnd();

    //2,2(left)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(-0.075f,0.2f);
	glVertex2f(-0.125f,0.2f);
	glVertex2f(-0.125f,0.125f);
	glVertex2f(-0.075f,0.125f);
    glEnd();



    //3,1(left)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(-0.15f,0.1f);
	glVertex2f(-0.2f,0.1f);
	glVertex2f(-0.2f,0.025f);
	glVertex2f(-0.15f,0.025f);
    glEnd();

    //3,2(left)
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

	glVertex2f(-0.075f,0.1f);
	glVertex2f(-0.125f,0.1f);
	glVertex2f(-0.125f,0.025f);
	glVertex2f(-0.075f,0.025f);
    glEnd();





    //Middle box1
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.025f,0.375f);
    glVertex2f(0.025f,0.375f);
	glVertex2f(0.025f,0.3f);
	glVertex2f(-0.025f,0.3f);
    glEnd();

    //middle box2
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.025f,0.275f);
    glVertex2f(0.025f,0.275f);
	glVertex2f(0.025f,0.2f);
	glVertex2f(-0.025f,0.2f);
    glEnd();

    //middle box3
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.025f,0.1f);
    glVertex2f(0.025f,0.1f);
	glVertex2f(0.025f,0.175f);
	glVertex2f(-0.025f,0.175f);
    glEnd();

    //middle box4
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.035f,0.082f);
    glVertex2f(0.035f,0.082f);
	glVertex2f(0.035f,0.0f);
	glVertex2f(-0.035f,0.0f);
    glEnd();

    //middle door line
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);

    glVertex2f(0.0f,0.082f);
    glVertex2f(0.0f,0.0f);

    glEnd();


    //Plus Sign
    //updown
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.0125,0.48);
    glVertex2f(0.0125f,0.48f);
    glVertex2f(0.0125f,0.38f);
    glVertex2f(-0.0125f,0.38f);
    glEnd();

    //left-right
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.0375f,0.45f);
    glVertex2f(0.0375f,0.45f);
    glVertex2f(0.0375f,0.41f);
    glVertex2f(-0.0375f,0.41f);
    glEnd();
    glLoadIdentity();
///////////////////////////////////////////////////////////////////////////////////////////////ending of Hospital draw///////////////////////////////////////////////////////////////////////

     ///left building beside hospital
    glColor3ub(205, 163, 33);
    glBegin(GL_QUADS);

    glVertex2f(-0.35f,0.25f);
    glVertex2f(-0.35f,0.0f);
    glVertex2f(-0.65f,0.0f);
    glVertex2f(-0.65f,0.25f);
    glEnd();

    //l1st floor shed
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.34f,0.27f);
    glVertex2f(-0.34f,0.25f);
    glVertex2f(-0.66f,0.25f);
    glVertex2f(-0.66f,0.27f);
    glEnd();

    //left window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(-0.58f,0.24f);
    glVertex2f(-0.58f,0.01f);
    glVertex2f(-0.64f,0.01f);
    glVertex2f(-0.64f,0.24f);
    glEnd();

    //left up window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.59f,0.23f);
    glVertex2f(-0.59f,0.17f);
    glVertex2f(-0.63f,0.17f);
    glVertex2f(-0.63f,0.23f);
    glEnd();

    //left middle window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.59f,0.15f);
    glVertex2f(-0.59f,0.09f);
    glVertex2f(-0.63f,0.09f);
    glVertex2f(-0.63f,0.15f);
    glEnd();

    //left down window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.59f,0.07f);
    glVertex2f(-0.59f,0.01f);
    glVertex2f(-0.63f,0.01f);
    glVertex2f(-0.63f,0.07f);
    glEnd();

    //Right window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(-0.36f,0.24f);
    glVertex2f(-0.36f,0.01f);
    glVertex2f(-0.42f,0.01f);
    glVertex2f(-0.42f,0.24f);
    glEnd();

    //Right up window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.37f,0.23f);
    glVertex2f(-0.37f,0.17f);
    glVertex2f(-0.41f,0.17f);
    glVertex2f(-0.41f,0.23f);
    glEnd();


    //Right middle window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.37f,0.15f);
    glVertex2f(-0.37f,0.09f);
    glVertex2f(-0.41f,0.09f);
    glVertex2f(-0.41f,0.15f);
    glEnd();

    //Right down window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.37f,0.07f);
    glVertex2f(-0.37f,0.01f);
    glVertex2f(-0.41f,0.01f);
    glVertex2f(-0.41f,0.07f);
    glEnd();

    //1st floor triangle
    glColor3ub(139, 69, 19);
    glBegin(GL_TRIANGLES);

    glVertex2f(-0.5f,0.23f);
    glVertex2f(-0.43f,0.15f);
    glVertex2f(-0.57f,0.15f);
    glEnd();

    //1st floor grey door
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(-0.44f,0.15f);
    glVertex2f(-0.44f,0.0f);
    glVertex2f(-0.56f,0.0f);
    glVertex2f(-0.56f,0.15f);
    glEnd();

    //1st floor main door
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.46f,0.11f);
    glVertex2f(-0.46f,0.0f);
    glVertex2f(-0.54f,0.0f);
    glVertex2f(-0.54f,0.11f);
    glEnd();

    //main door line
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);

    glVertex2f(-0.5f,0.0f);
    glVertex2f(-0.5f,0.11f);
    glEnd();


    //left building 2nd floor
   glColor3ub(205, 163, 33);
    glBegin(GL_QUADS);

    glVertex2f(-0.4f,0.35f);
    glVertex2f(-0.4f,0.27f);
    glVertex2f(-0.6f,0.27f);
    glVertex2f(-0.6f,0.35f);
    glEnd();


    //2nd floor triangle
    glColor3ub(139, 69, 19);
    glBegin(GL_TRIANGLES);

    glVertex2f(-0.5f,0.43f);
    glVertex2f(-0.38f,0.35f);
    glVertex2f(-0.62f,0.35f);
    glEnd();
/////////////////////////////////////////////////////////////////////////////////////////////

    ///left building 2
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);

    glVertex2f(-0.7f,0.24f);
    glVertex2f(-0.7f,0.0f);
    glVertex2f(-0.95f,0.0f);
    glVertex2f(-0.95f,0.24f);
    glEnd();


     //left building 2 1st floor door border
   glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(-0.86f,0.16f);
    glVertex2f(-0.86f,0.0f);
    glVertex2f(-0.93f,0.0f);
    glVertex2f(-0.93f,0.16f);
    glEnd();

    //left building 2 1st floor door
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.87f,0.15f);
    glVertex2f(-0.87f,0.0f);
    glVertex2f(-0.92f,0.0f);
    glVertex2f(-0.92f,0.15f);
    glEnd();

    //left building 2 1st floor window border
     glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(-0.73f,0.17f);
    glVertex2f(-0.73f,0.04f);
    glVertex2f(-0.81f,0.04f);
    glVertex2f(-0.81f,0.17f);
    glEnd();

    //left building 2 1st floor window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.74f,0.16f);
    glVertex2f(-0.74f,0.05f);
    glVertex2f(-0.8f,0.05f);
    glVertex2f(-0.8f,0.16f);
    glEnd();


    //left building 2 1st floor shed
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.7f,0.25f);
    glVertex2f(-0.7f,0.24f);
    glVertex2f(-0.95f,0.24f);
    glVertex2f(-0.95f,0.25f);
    glEnd();

    //left building 2 2nd floor
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);

    glVertex2f(-0.71f,0.35f);
    glVertex2f(-0.71f,0.25f);
    glVertex2f(-0.85f,0.25f);
    glVertex2f(-0.85f,0.35f);
    glEnd();

    //left building 2 2nd floor shed
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.7f,0.37f);
    glVertex2f(-0.7f,0.35f);
    glVertex2f(-0.86f,0.35f);
    glVertex2f(-0.86f,0.37f);
    glEnd();

    //left building 2 2nd floor door
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.79f,0.34f);
    glVertex2f(-0.79f,0.25f);
    glVertex2f(-0.84f,0.25f);
    glVertex2f(-0.84f,0.34f);
    glEnd();

    //left building 2 2nd floor window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(-0.72f,0.34f);
    glVertex2f(-0.72f,0.27f);
    glVertex2f(-0.78f,0.27f);
    glVertex2f(-0.78f,0.34f);
    glEnd();


    //left building 2 2nd floor window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.73f,0.33f);
    glVertex2f(-0.73f,0.28f);
    glVertex2f(-0.77f,0.28f);
    glVertex2f(-0.77f,0.33f);
    glEnd();

    //left building roof oporer piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.7f,0.3f);
    glVertex2f(-0.7f,0.29f);
    glVertex2f(-0.95f,0.29f);
    glVertex2f(-0.95f,0.3f);
    glEnd();

    //left building 1st floor left 1 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.93f,0.29f);
    glVertex2f(-0.93f,0.25f);
    glVertex2f(-0.94f,0.25f);
    glVertex2f(-0.94f,0.29f);
    glEnd();

    //left building 2 1st floor left 2 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.90f,0.29f);
    glVertex2f(-0.90f,0.25f);
    glVertex2f(-0.91f,0.25f);
    glVertex2f(-0.91f,0.29f);
    glEnd();

    //left building 2 1st floor left 3 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.87f,0.29f);
    glVertex2f(-0.87f,0.25f);
    glVertex2f(-0.88f,0.25f);
    glVertex2f(-0.88f,0.29f);
    glEnd();

    //left building 2 1st floor left 4 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.84f,0.29f);
    glVertex2f(-0.84f,0.25f);
    glVertex2f(-0.85f,0.25f);
    glVertex2f(-0.85f,0.29f);
    glEnd();

    //left building 1st floor left 5 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.81f,0.29f);
    glVertex2f(-0.81f,0.25f);
    glVertex2f(-0.82f,0.25f);
    glVertex2f(-0.82f,0.29f);
    glEnd();

    //left building 2 1st floor left 6 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.78f,0.29f);
    glVertex2f(-0.78f,0.25f);
    glVertex2f(-0.79f,0.25f);
    glVertex2f(-0.79f,0.29f);
    glEnd();

    //left building 2 1st floor left 7 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.75f,0.29f);
    glVertex2f(-0.75f,0.25f);
    glVertex2f(-0.76f,0.25f);
    glVertex2f(-0.76f,0.29f);
    glEnd();

    //left building 2 1st floor left 7 piller
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(-0.72f,0.29f);
    glVertex2f(-0.72f,0.25f);
    glVertex2f(-0.73f,0.25f);
    glVertex2f(-0.73f,0.29f);
    glEnd();

///////////////////////////////////////////////////////////////////////////////////////////////////////
///Right building beside Hospital
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);

    glVertex2f(0.58,0.45f);
    glVertex2f(0.58f,0.0f);
    glVertex2f(0.35f,0.0f);
    glVertex2f(0.35f,0.45f);
    glEnd();

    //Right building beside Hospital roof shed
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(0.59,0.48f);
    glVertex2f(0.59f,0.45f);
    glVertex2f(0.34f,0.45f);
    glVertex2f(0.34f,0.48f);
    glEnd();


    //Right building beside Hospital 3rd floor left window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.42,0.43f);
    glVertex2f(0.42f,0.31f);
    glVertex2f(0.36f,0.31f);
    glVertex2f(0.36f,0.43f);
    glEnd();

    //Right building beside Hospital 3rd floor left window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(0.41,0.42f);
    glVertex2f(0.41f,0.32f);
    glVertex2f(0.37f,0.32f);
    glVertex2f(0.37f,0.42f);
    glEnd();

//Right building beside Hospital 3rd floor middle window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.5,0.43f);
    glVertex2f(0.5f,0.31f);
    glVertex2f(0.43f,0.31f);
    glVertex2f(0.43f,0.43f);
    glEnd();

//Right building beside Hospital 3rd floor middle window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(0.49,0.42f);
    glVertex2f(0.49f,0.32f);
    glVertex2f(0.44f,0.32f);
    glVertex2f(0.44f,0.42f);
    glEnd();

    //Right building beside Hospital 3rd floor right window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.57,0.43f);
    glVertex2f(0.57f,0.31f);
    glVertex2f(0.51f,0.31f);
    glVertex2f(0.51f,0.43f);
    glEnd();
     //Right building beside Hospital 3rd floor right window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(0.56,0.42f);
    glVertex2f(0.56f,0.32f);
    glVertex2f(0.52f,0.32f);
    glVertex2f(0.52f,0.42f);
    glEnd();

    //Right building beside Hospital 2nd floor left window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.45,0.29f);
    glVertex2f(0.45f,0.17f);
    glVertex2f(0.36f,0.17f);
    glVertex2f(0.36f,0.29f);
    glEnd();

    //Right building beside Hospital 2nd floor left window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(0.44,0.28f);
    glVertex2f(0.44f,0.18f);
    glVertex2f(0.37f,0.18f);
    glVertex2f(0.37f,0.28f);
    glEnd();

    //Right building beside Hospital 2nd floor right window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.57,0.29f);
    glVertex2f(0.57f,0.17f);
    glVertex2f(0.48f,0.17f);
    glVertex2f(0.48f,0.29f);
    glEnd();

    //Right building beside Hospital 2nd floor right window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(0.56,0.28f);
    glVertex2f(0.56f,0.18f);
    glVertex2f(0.49f,0.18f);
    glVertex2f(0.49f,0.28f);
    glEnd();

    //Right building beside Hospital door border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.44,0.14f);
    glVertex2f(0.44f,0.0f);
    glVertex2f(0.37f,0.0f);
    glVertex2f(0.37f,0.14f);
    glEnd();
    //Right building beside Hospital door
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(0.43,0.13f);
    glVertex2f(0.43f,0.0f);
    glVertex2f(0.38f,0.0f);
    glVertex2f(0.38f,0.13f);
    glEnd();

    //Right building beside Hospital 1st floor window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.56,0.13f);
    glVertex2f(0.56f,0.04f);
    glVertex2f(0.47f,0.04f);
    glVertex2f(0.47f,0.13f);
    glEnd();

    //Right building beside Hospital 1st floor window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(0.55,0.12f);
    glVertex2f(0.55f,0.03f);
    glVertex2f(0.48f,0.03f);
    glVertex2f(0.48f,0.12f);
    glEnd();

    //Right building beside Hospital 1st floor  window r nich
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.57f,0.04f);
    glVertex2f(0.57f,0.02f);
    glVertex2f(0.46f,0.02f);
    glVertex2f(0.46f,0.04f);
    glEnd();

    //Right building beside Hospital 1st floor window left 1st red
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.49f,0.13f);
    glVertex2f(0.49f,0.08f);
    glVertex2f(0.47f,0.08f);
    glVertex2f(0.47f,0.13f);
    glEnd();

    //Right building beside Hospital 1st floor window left 1st white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.51f,0.13f);
    glVertex2f(0.51f,0.08f);
    glVertex2f(0.49f,0.08f);
    glVertex2f(0.49f,0.13f);
    glEnd();

    //Right building beside Hospital 1st floor window 2nd red
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.53f,0.13f);
    glVertex2f(0.53f,0.08f);
    glVertex2f(0.51f,0.08f);
    glVertex2f(0.51f,0.13f);
    glEnd();

    //Right building beside Hospital 1st floor window left 1st white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.55f,0.13f);
    glVertex2f(0.55f,0.08f);
    glVertex2f(0.53f,0.08f);
    glVertex2f(0.53f,0.13f);
    glEnd();
    //Right building beside Hospital 1st floor window left 1st red
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(0.56f,0.13f);
    glVertex2f(0.56f,0.08f);
    glVertex2f(0.55f,0.08f);
    glVertex2f(0.55f,0.13f);
    glEnd();
/////////////////////////////////////////////////////////////////////////////////////////////////////

///Right 2nd building
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);

    glVertex2f(0.64,0.3f);
    glVertex2f(0.64f,0.0f);
    glVertex2f(0.85f,0.0f);
    glVertex2f(0.85f,0.3f);
    glEnd();

    //Right 2nd building shed
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(0.63,0.33f);
    glVertex2f(0.63f,0.3f);
    glVertex2f(0.86f,0.3f);
    glVertex2f(0.86f,0.33f);
    glEnd();

    //Right 2nd building left window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.66,0.28f);
    glVertex2f(0.66f,0.19f);
    glVertex2f(0.73f,0.19f);
    glVertex2f(0.73f,0.28f);
    glEnd();

    //Right 2nd building left window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(0.67,0.27f);
    glVertex2f(0.67f,0.2f);
    glVertex2f(0.72f,0.2f);
    glVertex2f(0.72f,0.27f);
    glEnd();


    //Right 2nd building right window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.76,0.28f);
    glVertex2f(0.76f,0.19f);
    glVertex2f(0.83f,0.19f);
    glVertex2f(0.83f,0.28f);
    glEnd();

    //Right 2nd building right window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(0.77,0.27f);
    glVertex2f(0.77f,0.2f);
    glVertex2f(0.82f,0.2f);
    glVertex2f(0.82f,0.27f);
    glEnd();

    //Right 2nd building triangle shed
    glColor3ub(139, 69, 19);
    glBegin(GL_TRIANGLES);

    glVertex2f(0.75,0.18f);
    glVertex2f(0.80f,0.11f);
    glVertex2f(0.69f,0.11f);
    glEnd();

    //Right 2nd building door border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.78,0.11f);
    glVertex2f(0.78f,0.0f);
    glVertex2f(0.71f,0.0f);
    glVertex2f(0.71f,0.11f);
    glEnd();

    //Right 2nd building door
    glColor3ub(139, 69, 19);
    glBegin(GL_QUADS);

    glVertex2f(0.77,0.09f);
    glVertex2f(0.77f,0.0f);
    glVertex2f(0.72f,0.0f);
    glVertex2f(0.72f,0.09f);
    glEnd();

    //Right 2nd building 2nd floor
    glColor3ub(205, 133, 63);
    glBegin(GL_QUADS);

    glVertex2f(0.72,0.41f);
    glVertex2f(0.72f,0.33f);
    glVertex2f(0.84f,0.33f);
    glVertex2f(0.84f,0.41f);
    glEnd();

    //Right 2nd building 2nd floor shed
    glColor3ub(139, 63, 19);
    glBegin(GL_QUADS);

    glVertex2f(0.71,0.43f);
    glVertex2f(0.71f,0.41f);
    glVertex2f(0.85f,0.41f);
    glVertex2f(0.85f,0.43f);
    glEnd();

    //Right 2nd building 1st floor left window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.65,0.10f);
    glVertex2f(0.65f,0.02f);
    glVertex2f(0.70f,0.02f);
    glVertex2f(0.70f,0.10f);
    glEnd();

    //Right 2nd building 1st floor left window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(0.66,0.09f);
    glVertex2f(0.66f,0.03f);
    glVertex2f(0.69f,0.03f);
    glVertex2f(0.69f,0.09f);
    glEnd();


    //Right 2nd building 1st floor right window border
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);

    glVertex2f(0.79,0.10f);
    glVertex2f(0.79f,0.02f);
    glVertex2f(0.84f,0.02f);
    glVertex2f(0.84f,0.10f);
    glEnd();

    //Right 2nd building 1st floor right window
    glColor3f(0.9f, 1.0f, 0.1f);
    glBegin(GL_QUADS);

    glVertex2f(0.80,0.09f);
    glVertex2f(0.80f,0.03f);
    glVertex2f(0.83f,0.03f);
    glVertex2f(0.83f,0.09f);
    glEnd();

    glPopMatrix();

}

void drawtree()
{
    //Wood
    Quad(-0.2f, 0.1f, -0.175f, 0.1f, -0.175f, 0.0f, -0.2f, 0.0f, 0.53f, 0.37f, 0.26f);

    //lower leaves
    Triangle(-0.25f, 0.1f,  -0.125f, 0.1f, -0.1875f,  0.25, 0.0f, 0.5f, 0.0f);
    Triangle(-0.25f, 0.15f, -0.125f, 0.15f,  -0.1875f,  0.3f, 0.0f, 0.5f, 0.0f);
}

void drawnighttree()
{
    //Wood
    Quad(-0.2f, 0.1f, -0.175f, 0.1f, -0.175f, 0.0f, -0.2f, 0.0f, 0.43f, 0.27f, 0.16f);

    //lower leaves
    Triangle(-0.25f, 0.1f,  -0.125f, 0.1f, -0.1875f,  0.25, 0.0f, 0.4f, 0.0f);
    Triangle(-0.25f, 0.15f, -0.125f, 0.15f,  -0.1875f,  0.3f, 0.0f, 0.4f, 0.0f);
}

void drawroad()
{
     ///road end1
    Quad(-1.0f,0.0f,-0.75f,0.0f,-0.75f,-0.03f,-1.0f,-0.03f,1.0f,1.0f,0.0f);
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-1.0f,0.0f,-0.75f,0.0f,-0.75f,-0.03f,-1.0f,-0.03f,1.0f,1.0f,0.0f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-1.0f,0.0f,-0.75f,0.0f,-0.75f,-0.03f,-1.0f,-0.03f,1.0f,1.0f,0.0f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-1.0f,0.0f,-0.75f,0.0f,-0.75f,-0.03f,-1.0f,-0.03f,1.0f,1.0f,0.0f);
    glLoadIdentity();

    Quad(-0.75f,0.0f,-0.5f,0.0f,-0.5f,-0.03f,-0.75f,-0.03f,1.0f,1.0f,1.0f);
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-0.75f,0.0f,-0.5f,0.0f,-0.5f,-0.03f,-0.75f,-0.03f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-0.75f,0.0f,-0.5f,0.0f,-0.5f,-0.03f,-0.75f,-0.03f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-0.75f,0.0f,-0.5f,0.0f,-0.5f,-0.03f,-0.75f,-0.03f,1.0f,1.0f,1.0f);
    glLoadIdentity();

    ///road1
    Quad(-1.0f,-0.03f,1.0f,-0.03f,1.0f,-0.375f,-1.0f,-0.375,0.169f,0.169f,0.169f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,1.0f,1.0f,1.0f);

    glTranslatef(-0.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(0.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(0.75f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.75f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,1.0f,1.0f,1.0f);
    glLoadIdentity();



    ///road2
    Quad(-1.0f,-0.625f,1.0f,-0.625f,1.0f,-1.0f,-1.0f,-1.0,0.169f,0.169f,0.169f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,1.0f,1.0f,1.0f);

    glTranslatef(-0.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(0.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(0.75f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.75f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,1.0f,1.0f,1.0f);
    glLoadIdentity();

    ///road end2
    Quad(-1.0f,-0.97f,-0.75f,-0.97f,-0.75f,-1.0f,-1.0f,-1.0,1.0f,1.0f,0.0f);
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-1.0f,-0.97f,-0.75f,-0.97f,-0.75f,-1.0f,-1.0f,-1.0,1.0f,1.0f,0.0f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-1.0f,-0.97f,-0.75f,-0.97f,-0.75f,-1.0f,-1.0f,-1.0,1.0f,1.0f,0.0f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-1.0f,-0.97f,-0.75f,-0.97f,-0.75f,-1.0f,-1.0f,-1.0,1.0f,1.0f,0.0f);
    glLoadIdentity();

    Quad(-0.75f,-0.97f,-0.5f,-0.97f,-0.5f,-1.0f,-0.75f,-1.0f,1.0f,1.0f,1.0f);
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-0.75f,-0.97f,-0.5f,-0.97f,-0.5f,-1.0f,-0.75f,-1.0f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-0.75f,-0.97f,-0.5f,-0.97f,-0.5f,-1.0f,-0.75f,-1.0f,1.0f,1.0f,1.0f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-0.75f,-0.97f,-0.5f,-0.97f,-0.5f,-1.0f,-0.75f,-1.0f,1.0f,1.0f,1.0f);
    glLoadIdentity();

}

void drawroadnight()
{
     ///road end1
    Quad(-1.0f,0.0f,-0.75f,0.0f,-0.75f,-0.03f,-1.0f,-0.03,0.8f,0.8f,0.0f);
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-1.0f,0.0f,-0.75f,0.0f,-0.75f,-0.03f,-1.0f,-0.03,0.8f,0.8f,0.0f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-1.0f,0.0f,-0.75f,0.0f,-0.75f,-0.03f,-1.0f,-0.03,0.8f,0.8f,0.0f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-1.0f,0.0f,-0.75f,0.0f,-0.75f,-0.03f,-1.0f,-0.03,0.8f,0.8f,0.0f);
    glLoadIdentity();

    Quad(-0.75f,0.0f,-0.5f,0.0f,-0.5f,-0.03f,-0.75f,-0.03,0.8f,0.8f,0.8f);
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-0.75f,0.0f,-0.5f,0.0f,-0.5f,-0.03f,-0.75f,-0.03,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-0.75f,0.0f,-0.5f,0.0f,-0.5f,-0.03f,-0.75f,-0.03,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-0.75f,0.0f,-0.5f,0.0f,-0.5f,-0.03f,-0.75f,-0.03,0.8f,0.8f,0.8f);
    glLoadIdentity();


    ///road1
    Quad(-1.0f,-0.03f,1.0f,-0.03f,1.0f,-0.375f,-1.0f,-0.375,0.1f,0.1f,0.1f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,0.8f,0.8f,0.8f);

    glTranslatef(-0.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(0.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(0.75f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.75f,0.0f, 0.0f);
    Quad(-0.825f,-0.175f,-0.675f,-0.175f,-0.675f,-0.2f,-0.825f,-0.2,0.8f,0.8f,0.8f);
    glLoadIdentity();

     ///road2
    Quad(-1.0f,-0.625f,1.0f,-0.625f,1.0f,-1.0f,-1.0f,-1.0,0.1f,0.1f,0.1f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,0.8f,0.8f,0.8f);

    glTranslatef(-0.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(0.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(0.75f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.25f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.75f,0.0f, 0.0f);
    Quad(-0.825f,-0.8f,-0.675f,-0.8f,-0.675f,-0.825f,-0.825f,-0.825f,0.8f,0.8f,0.8f);
    glLoadIdentity();

    ///road end2
    Quad(-1.0f,-0.97f,-0.75f,-0.97f,-0.75f,-1.0f,-1.0f,-1.0,0.8f,0.8f,0.0f);
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-1.0f,-0.97f,-0.75f,-0.97f,-0.75f,-1.0f,-1.0f,-1.0,0.8f,0.8f,0.0f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-1.0f,-0.97f,-0.75f,-0.97f,-0.75f,-1.0f,-1.0f,-1.0,0.8f,0.8f,0.0f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-1.0f,-0.97f,-0.75f,-0.97f,-0.75f,-1.0f,-1.0f,-1.0,0.8f,0.8f,0.0f);
    glLoadIdentity();

    Quad(-0.75f,-0.97f,-0.5f,-0.97f,-0.5f,-1.0f,-0.75f,-1.0f,0.8f,0.8f,0.8f);
    glTranslatef(0.5f,0.0f, 0.0f);
    Quad(-0.75f,-0.97f,-0.5f,-0.97f,-0.5f,-1.0f,-0.75f,-1.0f,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.0f,0.0f, 0.0f);
    Quad(-0.75f,-0.97f,-0.5f,-0.97f,-0.5f,-1.0f,-0.75f,-1.0f,0.8f,0.8f,0.8f);
    glLoadIdentity();
    glTranslatef(1.5f,0.0f, 0.0f);
    Quad(-0.75f,-0.97f,-0.5f,-0.97f,-0.5f,-1.0f,-0.75f,-1.0f,0.8f,0.8f,0.8f);
    glLoadIdentity();

}

void drawrailway()
{
    //back
    Quad(-1.0f, -0.375f, 1.0f, -0.375f, 1.0f, -1.0f, -1.0f, -1.0f, 0.529412f, 0.529412f, 0.529412f);
    //boxes
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);

    glTranslatef(0.118f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(0.236f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(0.354f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(0.472f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(0.59f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(0.708f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(0.826f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(0.944f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(1.062f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(1.18f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(1.298f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(1.416f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(1.534f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(1.652f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(1.77f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
    glTranslatef(1.888f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.169f,0.169f,0.169f);
    glLoadIdentity();
}

void drawrailwaynight()
{
    //back
    Quad(-1.0f, -0.375f, 1.0f, -0.375f, 1.0f, -1.0f, -1.0f, -1.0f, 0.329412f, 0.329412f, 0.329412f);
    //boxes
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);

    glTranslatef(0.118f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(0.236f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(0.354f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(0.472f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(0.59f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(0.708f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(0.826f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(0.944f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(1.062f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(1.18f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(1.298f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(1.416f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(1.534f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(1.652f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(1.77f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
    glTranslatef(1.888f,0.0f, 0.0f);
    Quad(-1.0f, -0.4f, -0.9f, -0.4f, -0.9f, -0.6f, -1.0f, -0.6f, 0.1f,0.1f,0.1f);
    glLoadIdentity();
}

void drawrain()
{
        glTranslatef(0.0f,positionRain,0.0f);

                ///Column counted from left side
                //column1
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, 1.5f);
                glVertex2f(-0.915f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, 1.325f);
                glVertex2f(-0.915f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, 1.15f);
                glVertex2f(-0.915f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, 0.975f);
                glVertex2f(-0.915f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, 0.800f);
                glVertex2f(-0.915f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, 0.625f);
                glVertex2f(-0.915f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, 0.400f);
                glVertex2f(-0.915f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, 0.225f);
                glVertex2f(-0.915f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, 0.050f);
                glVertex2f(-0.915f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, -0.125f);
                glVertex2f(-0.915f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, -0.3f);
                glVertex2f(-0.915f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, -0.475f);
                glVertex2f(-0.915f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, -0.650f);
                glVertex2f(-0.915f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.915f, -0.825f);
                glVertex2f(-0.915f, -0.90f);
                glEnd();
/////////////////////////////////////////////////////////////////////////////////////////

                //column2
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, 1.5f);
                glVertex2f(-0.815f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, 1.325f);
                glVertex2f(-0.815f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, 1.15f);
                glVertex2f(-0.815f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, 0.975f);
                glVertex2f(-0.815f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, 0.800f);
                glVertex2f(-0.815f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, 0.625f);
                glVertex2f(-0.815f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, 0.400f);
                glVertex2f(-0.815f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, 0.225f);
                glVertex2f(-0.815f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, 0.050f);
                glVertex2f(-0.815f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, -0.125f);
                glVertex2f(-0.815f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, -0.3f);
                glVertex2f(-0.815f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, -0.475f);
                glVertex2f(-0.815f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, -0.650f);
                glVertex2f(-0.815f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.815f, -0.825f);
                glVertex2f(-0.815f, -0.90f);
                glEnd();
//////////////////////////////////////////////////////////////////////////////

                 //column3
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, 1.5f);
                glVertex2f(-0.715f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, 1.325f);
                glVertex2f(-0.715f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, 1.15f);
                glVertex2f(-0.715f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, 0.975f);
                glVertex2f(-0.715f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, 0.800f);
                glVertex2f(-0.715f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, 0.625f);
                glVertex2f(-0.715f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, 0.400f);
                glVertex2f(-0.715f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, 0.225f);
                glVertex2f(-0.715f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, 0.050f);
                glVertex2f(-0.715f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, -0.125f);
                glVertex2f(-0.715f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, -0.3f);
                glVertex2f(-0.715f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, -0.475f);
                glVertex2f(-0.715f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, -0.650f);
                glVertex2f(-0.715f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.715f, -0.825f);
                glVertex2f(-0.715f, -0.90f);
                glEnd();

////////////////////////////////////////////////////////////////////////////////////////

                 //column4
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, 1.5f);
                glVertex2f(-0.615f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, 1.325f);
                glVertex2f(-0.615f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, 1.15f);
                glVertex2f(-0.615f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, 0.975f);
                glVertex2f(-0.615f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, 0.800f);
                glVertex2f(-0.615f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, 0.625f);
                glVertex2f(-0.615f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, 0.400f);
                glVertex2f(-0.615f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, 0.225f);
                glVertex2f(-0.615f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, 0.050f);
                glVertex2f(-0.615f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, -0.125f);
                glVertex2f(-0.615f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, -0.3f);
                glVertex2f(-0.615f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, -0.475f);
                glVertex2f(-0.615f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, -0.650f);
                glVertex2f(-0.615f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.615f, -0.825f);
                glVertex2f(-0.615f, -0.90f);
                glEnd();

////////////////////////////////////////////////////////////////////////////////////////////

                 //column5
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, 1.5f);
                glVertex2f(-0.515f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, 1.325f);
                glVertex2f(-0.515f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, 1.15f);
                glVertex2f(-0.515f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, 0.975f);
                glVertex2f(-0.515f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, 0.800f);
                glVertex2f(-0.515f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, 0.625f);
                glVertex2f(-0.515f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, 0.400f);
                glVertex2f(-0.515f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, 0.225f);
                glVertex2f(-0.515f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, 0.050f);
                glVertex2f(-0.515f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, -0.125f);
                glVertex2f(-0.515f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, -0.3f);
                glVertex2f(-0.515f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, -0.475f);
                glVertex2f(-0.515f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, -0.650f);
                glVertex2f(-0.515f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.515f, -0.825f);
                glVertex2f(-0.515f, -0.90f);
                glEnd();

/////////////////////////////////////////////////////////////////////////////////

                 //column6
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, 1.5f);
                glVertex2f(-0.415f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, 1.325f);
                glVertex2f(-0.415f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, 1.15f);
                glVertex2f(-0.415f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, 0.975f);
                glVertex2f(-0.415f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, 0.800f);
                glVertex2f(-0.415f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, 0.625f);
                glVertex2f(-0.415f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, 0.400f);
                glVertex2f(-0.415f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, 0.225f);
                glVertex2f(-0.415f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, 0.050f);
                glVertex2f(-0.415f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, -0.125f);
                glVertex2f(-0.415f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, -0.3f);
                glVertex2f(-0.415f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, -0.475f);
                glVertex2f(-0.415f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, -0.650f);
                glVertex2f(-0.415f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.415f, -0.825f);
                glVertex2f(-0.415f, -0.90f);
                glEnd();

///////////////////////////////////////////////////////////////////////////////////////

                 //column7
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, 1.5f);
                glVertex2f(-0.315f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, 1.325f);
                glVertex2f(-0.315f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, 1.15f);
                glVertex2f(-0.315f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, 0.975f);
                glVertex2f(-0.315f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, 0.800f);
                glVertex2f(-0.315f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, 0.625f);
                glVertex2f(-0.315f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, 0.400f);
                glVertex2f(-0.315f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, 0.225f);
                glVertex2f(-0.315f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, 0.050f);
                glVertex2f(-0.315f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, -0.125f);
                glVertex2f(-0.315f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, -0.3f);
                glVertex2f(-0.315f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, -0.475f);
                glVertex2f(-0.315f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, -0.650f);
                glVertex2f(-0.315f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.315f, -0.825f);
                glVertex2f(-0.315f, -0.90f);
                glEnd();

/////////////////////////////////////////////////////////////////////////////////////

                 //column8
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, 1.5f);
                glVertex2f(-0.215f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, 1.325f);
                glVertex2f(-0.215f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, 1.15f);
                glVertex2f(-0.215f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, 0.975f);
                glVertex2f(-0.215f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, 0.800f);
                glVertex2f(-0.215f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, 0.625f);
                glVertex2f(-0.215f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, 0.400f);
                glVertex2f(-0.215f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, 0.225f);
                glVertex2f(-0.215f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, 0.050f);
                glVertex2f(-0.215f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, -0.125f);
                glVertex2f(-0.215f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, -0.3f);
                glVertex2f(-0.215f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, -0.475f);
                glVertex2f(-0.215f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, -0.650f);
                glVertex2f(-0.215f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.215f, -0.825f);
                glVertex2f(-0.215f, -0.90f);
                glEnd();

/////////////////////////////////////////////////////////////////////////////////////

                //column9
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, 1.5f);
                glVertex2f(-0.115f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, 1.325f);
                glVertex2f(-0.115f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, 1.15f);
                glVertex2f(-0.115f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, 0.975f);
                glVertex2f(-0.115f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, 0.800f);
                glVertex2f(-0.115f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, 0.625f);
                glVertex2f(-0.115f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, 0.400f);
                glVertex2f(-0.115f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, 0.225f);
                glVertex2f(-0.115f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, 0.050f);
                glVertex2f(-0.115f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, -0.125f);
                glVertex2f(-0.115f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, -0.3f);
                glVertex2f(-0.115f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, -0.475f);
                glVertex2f(-0.115f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, -0.650f);
                glVertex2f(-0.115f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.115f, -0.825f);
                glVertex2f(-0.115f, -0.90f);
                glEnd();

///////////////////////////////////////////////////////////////////////////////////////////////

                 //column10
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, 1.5f);
                glVertex2f(-0.015f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, 1.325f);
                glVertex2f(-0.015f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, 1.15f);
                glVertex2f(-0.015f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, 0.975f);
                glVertex2f(-0.015f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, 0.800f);
                glVertex2f(-0.015f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, 0.625f);
                glVertex2f(-0.015f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, 0.400f);
                glVertex2f(-0.015f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, 0.225f);
                glVertex2f(-0.015f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, 0.050f);
                glVertex2f(-0.015f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, -0.125f);
                glVertex2f(-0.015f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, -0.3f);
                glVertex2f(-0.015f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, -0.475f);
                glVertex2f(-0.015f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, -0.650f);
                glVertex2f(-0.015f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(-0.015f, -0.825f);
                glVertex2f(-0.015f, -0.90f);
                glEnd();

///////////////////////////////////////////////////////////////////////////////////////////////////////

                 //column12
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, 1.5f);
                glVertex2f(0.085f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, 1.325f);
                glVertex2f(0.085f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, 1.15f);
                glVertex2f(0.085f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, 0.975f);
                glVertex2f(0.085f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, 0.800f);
                glVertex2f(0.085f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, 0.625f);
                glVertex2f(0.085f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, 0.400f);
                glVertex2f(0.085f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, 0.225f);
                glVertex2f(0.085f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, 0.050f);
                glVertex2f(0.085f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, -0.125f);
                glVertex2f(0.085f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, -0.3f);
                glVertex2f(0.085f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, -0.475f);
                glVertex2f(0.085f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, -0.650f);
                glVertex2f(0.085f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.085f, -0.825f);
                glVertex2f(0.085f, -0.90f);
                glEnd();

////////////////////////////////////////////////////////////////////////////////////////////////////////

                //column13
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, 1.5f);
                glVertex2f(0.185f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, 1.325f);
                glVertex2f(0.185f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, 1.15f);
                glVertex2f(0.185f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, 0.975f);
                glVertex2f(0.185f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, 0.800f);
                glVertex2f(0.185f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, 0.625f);
                glVertex2f(0.185f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, 0.400f);
                glVertex2f(0.185f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, 0.225f);
                glVertex2f(0.185f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, 0.050f);
                glVertex2f(0.185f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, -0.125f);
                glVertex2f(0.185f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, -0.3f);
                glVertex2f(0.185f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, -0.475f);
                glVertex2f(0.185f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, -0.650f);
                glVertex2f(0.185f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.185f, -0.825f);
                glVertex2f(0.185f, -0.90f);
                glEnd();

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                //column14
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, 1.5f);
                glVertex2f(0.285f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, 1.325f);
                glVertex2f(0.285f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, 1.15f);
                glVertex2f(0.285f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, 0.975f);
                glVertex2f(0.285f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, 0.800f);
                glVertex2f(0.285f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, 0.625f);
                glVertex2f(0.285f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, 0.400f);
                glVertex2f(0.285f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, 0.225f);
                glVertex2f(0.285f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, 0.050f);
                glVertex2f(0.285f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, -0.125f);
                glVertex2f(0.285f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, -0.3f);
                glVertex2f(0.285f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, -0.475f);
                glVertex2f(0.285f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, -0.650f);
                glVertex2f(0.285f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.285f, -0.825f);
                glVertex2f(0.285f, -0.90f);
                glEnd();

 ////////////////////////////////////////////////////////////////////////////////////////////////////////

            //column15
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, 1.5f);
                glVertex2f(0.385f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, 1.325f);
                glVertex2f(0.385f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, 1.15f);
                glVertex2f(0.385f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, 0.975f);
                glVertex2f(0.385f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, 0.800f);
                glVertex2f(0.385f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, 0.625f);
                glVertex2f(0.385f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, 0.400f);
                glVertex2f(0.385f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, 0.225f);
                glVertex2f(0.385f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, 0.050f);
                glVertex2f(0.385f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, -0.125f);
                glVertex2f(0.385f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, -0.3f);
                glVertex2f(0.385f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, -0.475f);
                glVertex2f(0.385f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, -0.650f);
                glVertex2f(0.385f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.385f, -0.825f);
                glVertex2f(0.385f, -0.90f);
                glEnd();

//////////////////////////////////////////////////////////////////////////////////////////////////////////

                //column16
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, 1.5f);
                glVertex2f(0.485f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, 1.325f);
                glVertex2f(0.485f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, 1.15f);
                glVertex2f(0.485f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, 0.975f);
                glVertex2f(0.485f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, 0.800f);
                glVertex2f(0.485f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, 0.625f);
                glVertex2f(0.485f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, 0.400f);
                glVertex2f(0.485f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, 0.225f);
                glVertex2f(0.485f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, 0.050f);
                glVertex2f(0.485f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, -0.125f);
                glVertex2f(0.485f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, -0.3f);
                glVertex2f(0.485f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, -0.475f);
                glVertex2f(0.485f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, -0.650f);
                glVertex2f(0.485f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.485f, -0.825f);
                glVertex2f(0.485f, -0.90f);
                glEnd();

//////////////////////////////////////////////////////////////////////////////////////////////////////////

                //column17
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, 1.5f);
                glVertex2f(0.585f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, 1.325f);
                glVertex2f(0.585f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, 1.15f);
                glVertex2f(0.585f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, 0.975f);
                glVertex2f(0.585f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, 0.800f);
                glVertex2f(0.585f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, 0.625f);
                glVertex2f(0.585f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, 0.400f);
                glVertex2f(0.585f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, 0.225f);
                glVertex2f(0.585f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, 0.050f);
                glVertex2f(0.585f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, -0.125f);
                glVertex2f(0.585f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, -0.3f);
                glVertex2f(0.585f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, -0.475f);
                glVertex2f(0.585f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, -0.650f);
                glVertex2f(0.585f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.585f, -0.825f);
                glVertex2f(0.585f, -0.90f);
                glEnd();

 //////////////////////////////////////////////////////////////////////////////////////////////////////////

                //column18
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, 1.5f);
                glVertex2f(0.685f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, 1.325f);
                glVertex2f(0.685f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, 1.15f);
                glVertex2f(0.685f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, 0.975f);
                glVertex2f(0.685f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, 0.800f);
                glVertex2f(0.685f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, 0.625f);
                glVertex2f(0.685f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, 0.400f);
                glVertex2f(0.685f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, 0.225f);
                glVertex2f(0.685f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, 0.050f);
                glVertex2f(0.685f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, -0.125f);
                glVertex2f(0.685f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, -0.3f);
                glVertex2f(0.685f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, -0.475f);
                glVertex2f(0.685f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, -0.650f);
                glVertex2f(0.685f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.685f, -0.825f);
                glVertex2f(0.685f, -0.90f);
                glEnd();

//////////////////////////////////////////////////////////////////////////////////////////////////////////

                //column19
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, 1.5f);
                glVertex2f(0.785f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, 1.325f);
                glVertex2f(0.785f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, 1.15f);
                glVertex2f(0.785f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, 0.975f);
                glVertex2f(0.785f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, 0.800f);
                glVertex2f(0.785f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, 0.625f);
                glVertex2f(0.785f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, 0.400f);
                glVertex2f(0.785f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, 0.225f);
                glVertex2f(0.785f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, 0.050f);
                glVertex2f(0.785f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, -0.125f);
                glVertex2f(0.785f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, -0.3f);
                glVertex2f(0.785f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, -0.475f);
                glVertex2f(0.785f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, -0.650f);
                glVertex2f(0.785f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.785f, -0.825f);
                glVertex2f(0.785f, -0.90f);
                glEnd();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

                //column20
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, 1.5f);
                glVertex2f(0.885f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, 1.325f);
                glVertex2f(0.885f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, 1.15f);
                glVertex2f(0.885f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, 0.975f);
                glVertex2f(0.885f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, 0.800f);
                glVertex2f(0.885f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, 0.625f);
                glVertex2f(0.885f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, 0.400f);
                glVertex2f(0.885f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, 0.225f);
                glVertex2f(0.885f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, 0.050f);
                glVertex2f(0.885f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, -0.125f);
                glVertex2f(0.885f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, -0.3f);
                glVertex2f(0.885f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, -0.475f);
                glVertex2f(0.885f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, -0.650f);
                glVertex2f(0.885f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.885f, -0.825f);
                glVertex2f(0.885f, -0.90f);
                glEnd();

//////////////////////////////////////////////////////////////////////////////////////////////////////////

                //column21
                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, 1.5f);
                glVertex2f(0.985f, 1.425f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, 1.325f);
                glVertex2f(0.985f, 1.25f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, 1.15f);
                glVertex2f(0.985f, 1.075f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, 0.975f);
                glVertex2f(0.985f, 0.900f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, 0.800f);
                glVertex2f(0.985f, 0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, 0.625f);
                glVertex2f(0.985f, 0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, 0.400f);
                glVertex2f(0.985f, 0.325f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, 0.225f);
                glVertex2f(0.985f, 0.150f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, 0.050f);
                glVertex2f(0.985f, -0.025f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, -0.125f);
                glVertex2f(0.985f, -0.20f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, -0.3f);
                glVertex2f(0.985f, -0.375f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, -0.475f);
                glVertex2f(0.985f, -0.550f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, -0.650f);
                glVertex2f(0.985f, -0.725f);
                glEnd();

                glBegin(GL_LINES);
                glColor3f(1.0f,1.0f,1.0f);
                glVertex2f(0.985f, -0.825f);
                glVertex2f(0.985f, -0.90f);
                glEnd();

        glLoadIdentity();
}

void drawtrain()
{

        ///Train

    glTranslatef(positionTrain, 0.10f,0.0f);
    glScalef(1.2f, 1.2f, 0.9f);



    // 1st front body
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.8f,-0.45f);
    glVertex2f(-0.8f,-0.55f);
    glVertex2f(-0.88f,-0.55f);
    glVertex2f(-0.88f,-0.45f);
    glEnd();

    //1st body under line
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.69f,-0.55f);
    glVertex2f(-0.69f,-0.57f);
    glVertex2f(-0.88f,-0.57f);
    glVertex2f(-0.88f,-0.55f);
    glEnd();

    // 1st body

    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.7f,-0.35f);
    glVertex2f(-0.7f,-0.55f);
    glVertex2f(-0.8f,-0.55f);
    glVertex2f(-0.8f,-0.35f);
    glEnd();

    // 1st body window

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.72f,-0.37f);
    glVertex2f(-0.72f,-0.45f);
    glVertex2f(-0.78f,-0.45f);
    glVertex2f(-0.78f,-0.37f);
    glEnd();

    //1st shed

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.69f,-0.33f);
    glVertex2f(-0.69f,-0.35f);
    glVertex2f(-0.81f,-0.35f);
    glVertex2f(-0.81f,-0.33f);
    glEnd();


    //1st linker

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.65f,-0.52f);
    glVertex2f(-0.65f,-0.53f);
    glVertex2f(-0.7f,-0.53f);
    glVertex2f(-0.7f,-0.52f);
    glEnd();

    //2nd body
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.5f,-0.35f);
    glVertex2f(-0.5f,-0.55f);
    glVertex2f(-0.65f,-0.55f);
    glVertex2f(-0.65f,-0.35f);
    glEnd();

    // 2nd body left window
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.58f,-0.37f);
    glVertex2f(-0.58f,-0.48f);
    glVertex2f(-0.63f,-0.48f);
    glVertex2f(-0.63f,-0.37f);
    glEnd();

    //2nd body right window
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.52f,-0.37f);
    glVertex2f(-0.52f,-0.48f);
    glVertex2f(-0.57f,-0.48f);
    glVertex2f(-0.57f,-0.37f);
    glEnd();

    //2nd body under line
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.49f,-0.55f);
    glVertex2f(-0.49f,-0.57f);
    glVertex2f(-0.66f,-0.57f);
    glVertex2f(-0.66f,-0.55f);
    glEnd();


    //2nd body shed

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.49f,-0.33f);
    glVertex2f(-0.49f,-0.35f);
    glVertex2f(-0.66f,-0.35f);
    glVertex2f(-0.66f,-0.33f);
    glEnd();

    //2nd linker

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.45f,-0.52f);
    glVertex2f(-0.45f,-0.53f);
    glVertex2f(-0.5f,-0.53f);
    glVertex2f(-0.5f,-0.52f);
    glEnd();


    //3rd body

    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.3f,-0.35f);
    glVertex2f(-0.3f,-0.55f);
    glVertex2f(-0.45f,-0.55f);
    glVertex2f(-0.45f,-0.35f);
    glEnd();

    // 3rd body left window

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.32f,-0.37f);
    glVertex2f(-0.32f,-0.48f);
    glVertex2f(-0.37f,-0.48f);
    glVertex2f(-0.37f,-0.37f);
    glEnd();

    // 3rd body right window

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.38f,-0.37f);
    glVertex2f(-0.38f,-0.48f);
    glVertex2f(-0.43f,-0.48f);
    glVertex2f(-0.43f,-0.37f);
    glEnd();

    //3rd body under line
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.29f,-0.55f);
    glVertex2f(-0.29f,-0.57f);
    glVertex2f(-0.46f,-0.57f);
    glVertex2f(-0.46f,-0.55f);
    glEnd();

    //3rd body shed

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.29f,-0.33f);
    glVertex2f(-0.29f,-0.35f);
    glVertex2f(-0.46f,-0.35f);
    glVertex2f(-0.46f,-0.33f);
    glEnd();

    //3rd linker

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.25f,-0.52f);
    glVertex2f(-0.25f,-0.53f);
    glVertex2f(-0.3f,-0.53f);
    glVertex2f(-0.3f,-0.52f);
    glEnd();


    //4th body

    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.1f,-0.35f);
    glVertex2f(-0.1f,-0.55f);
    glVertex2f(-0.25f,-0.55f);
    glVertex2f(-0.25f,-0.35f);
    glEnd();


    //4th body left window

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.18f,-0.37f);
    glVertex2f(-0.18f,-0.48f);
    glVertex2f(-0.23f,-0.48f);
    glVertex2f(-0.23f,-0.37f);
    glEnd();

    //4th body right window

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.12f,-0.37f);
    glVertex2f(-0.12f,-0.48f);
    glVertex2f(-0.17f,-0.48f);
    glVertex2f(-0.17f,-0.37f);
    glEnd();

    //4th body under line
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.09f,-0.55f);
    glVertex2f(-0.09f,-0.57f);
    glVertex2f(-0.26f,-0.57f);
    glVertex2f(-0.26f,-0.55f);
    glEnd();


    //4th body shed
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.09f,-0.33f);
    glVertex2f(-0.09f,-0.35f);
    glVertex2f(-0.26f,-0.35f);
    glVertex2f(-0.26f,-0.33f);
    glEnd();

    ///Train wheel

    glColor3f(0.0f,0.0f,0.0f);
    Circle(-0.840,-0.58,0.025,100);
    Circle(-0.782,-0.58,0.025,100);
    Circle(-0.72,-0.58,0.025,100);
    Circle(-0.615,-0.58,0.025,100);
    Circle(-0.535,-0.58,0.025,100);
    Circle(-0.415,-0.58,0.025,100);
    Circle(-0.335,-0.58,0.025,100);
    Circle(-0.215,-0.58,0.025,100);
    Circle(-0.135,-0.58,0.025,100);


    glColor3f(1.0f,0.0f,0.0f);
    Circle(-0.840,-0.58,0.005,100);
    Circle(-0.782,-0.58,0.005,100);
    Circle(-0.72,-0.58,0.005,100);
    Circle(-0.615,-0.58,0.005,100);
    Circle(-0.535,-0.58,0.005,100);
    Circle(-0.415,-0.58,0.005,100);
    Circle(-0.335,-0.58,0.005,100);
    Circle(-0.215,-0.58,0.005,100);
    Circle(-0.135,-0.58,0.005,100);

    ///Front white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.88f,-0.54f);
    glVertex2f(-0.88f,-0.58f);
    glVertex2f(-0.9f,-0.58f);
    glVertex2f(-0.89f,-0.54f);
    glEnd();
    glLoadIdentity();
    glLoadIdentity();

}

void drawtrainnight()
{

        ///Train

    glTranslatef(positionTrain, 0.10f,0.0f);
    glScalef(1.2f, 1.2f, 0.9f);



    // 1st front body
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.8f,-0.45f);
    glVertex2f(-0.8f,-0.55f);
    glVertex2f(-0.88f,-0.55f);
    glVertex2f(-0.88f,-0.45f);
    glEnd();

    //1st body under line
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.69f,-0.55f);
    glVertex2f(-0.69f,-0.57f);
    glVertex2f(-0.88f,-0.57f);
    glVertex2f(-0.88f,-0.55f);
    glEnd();

    // 1st body

    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.7f,-0.35f);
    glVertex2f(-0.7f,-0.55f);
    glVertex2f(-0.8f,-0.55f);
    glVertex2f(-0.8f,-0.35f);
    glEnd();

    // 1st body window

    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.72f,-0.37f);
    glVertex2f(-0.72f,-0.45f);
    glVertex2f(-0.78f,-0.45f);
    glVertex2f(-0.78f,-0.37f);
    glEnd();

    //1st shed

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.69f,-0.33f);
    glVertex2f(-0.69f,-0.35f);
    glVertex2f(-0.81f,-0.35f);
    glVertex2f(-0.81f,-0.33f);
    glEnd();


    //1st linker

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.65f,-0.52f);
    glVertex2f(-0.65f,-0.53f);
    glVertex2f(-0.7f,-0.53f);
    glVertex2f(-0.7f,-0.52f);
    glEnd();

    //2nd body
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.5f,-0.35f);
    glVertex2f(-0.5f,-0.55f);
    glVertex2f(-0.65f,-0.55f);
    glVertex2f(-0.65f,-0.35f);
    glEnd();

    // 2nd body left window
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.58f,-0.37f);
    glVertex2f(-0.58f,-0.48f);
    glVertex2f(-0.63f,-0.48f);
    glVertex2f(-0.63f,-0.37f);
    glEnd();

    //2nd body right window
    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.52f,-0.37f);
    glVertex2f(-0.52f,-0.48f);
    glVertex2f(-0.57f,-0.48f);
    glVertex2f(-0.57f,-0.37f);
    glEnd();

    //2nd body under line
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.49f,-0.55f);
    glVertex2f(-0.49f,-0.57f);
    glVertex2f(-0.66f,-0.57f);
    glVertex2f(-0.66f,-0.55f);
    glEnd();


    //2nd body shed

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.49f,-0.33f);
    glVertex2f(-0.49f,-0.35f);
    glVertex2f(-0.66f,-0.35f);
    glVertex2f(-0.66f,-0.33f);
    glEnd();

    //2nd linker

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.45f,-0.52f);
    glVertex2f(-0.45f,-0.53f);
    glVertex2f(-0.5f,-0.53f);
    glVertex2f(-0.5f,-0.52f);
    glEnd();


    //3rd body

    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.3f,-0.35f);
    glVertex2f(-0.3f,-0.55f);
    glVertex2f(-0.45f,-0.55f);
    glVertex2f(-0.45f,-0.35f);
    glEnd();

    // 3rd body left window

    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.32f,-0.37f);
    glVertex2f(-0.32f,-0.48f);
    glVertex2f(-0.37f,-0.48f);
    glVertex2f(-0.37f,-0.37f);
    glEnd();

    // 3rd body right window

    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.38f,-0.37f);
    glVertex2f(-0.38f,-0.48f);
    glVertex2f(-0.43f,-0.48f);
    glVertex2f(-0.43f,-0.37f);
    glEnd();

    //3rd body under line
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.29f,-0.55f);
    glVertex2f(-0.29f,-0.57f);
    glVertex2f(-0.46f,-0.57f);
    glVertex2f(-0.46f,-0.55f);
    glEnd();

    //3rd body shed

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.29f,-0.33f);
    glVertex2f(-0.29f,-0.35f);
    glVertex2f(-0.46f,-0.35f);
    glVertex2f(-0.46f,-0.33f);
    glEnd();

    //3rd linker

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.25f,-0.52f);
    glVertex2f(-0.25f,-0.53f);
    glVertex2f(-0.3f,-0.53f);
    glVertex2f(-0.3f,-0.52f);
    glEnd();


    //4th body

    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.1f,-0.35f);
    glVertex2f(-0.1f,-0.55f);
    glVertex2f(-0.25f,-0.55f);
    glVertex2f(-0.25f,-0.35f);
    glEnd();


    //4th body left window

    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.18f,-0.37f);
    glVertex2f(-0.18f,-0.48f);
    glVertex2f(-0.23f,-0.48f);
    glVertex2f(-0.23f,-0.37f);
    glEnd();

    //4th body right window

    glColor3f(0.9f, 1.0f, .1f);
    glBegin(GL_QUADS);

    glVertex2f(-0.12f,-0.37f);
    glVertex2f(-0.12f,-0.48f);
    glVertex2f(-0.17f,-0.48f);
    glVertex2f(-0.17f,-0.37f);
    glEnd();

    //4th body under line
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.09f,-0.55f);
    glVertex2f(-0.09f,-0.57f);
    glVertex2f(-0.26f,-0.57f);
    glVertex2f(-0.26f,-0.55f);
    glEnd();


    //4th body shed
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.09f,-0.33f);
    glVertex2f(-0.09f,-0.35f);
    glVertex2f(-0.26f,-0.35f);
    glVertex2f(-0.26f,-0.33f);
    glEnd();

    ///Train wheel

    glColor3f(0.0f,0.0f,0.0f);
    Circle(-0.840,-0.58,0.025,100);
    Circle(-0.782,-0.58,0.025,100);
    Circle(-0.72,-0.58,0.025,100);
    Circle(-0.615,-0.58,0.025,100);
    Circle(-0.535,-0.58,0.025,100);
    Circle(-0.415,-0.58,0.025,100);
    Circle(-0.335,-0.58,0.025,100);
    Circle(-0.215,-0.58,0.025,100);
    Circle(-0.135,-0.58,0.025,100);


    glColor3f(1.0f,0.0f,0.0f);
    Circle(-0.840,-0.58,0.005,100);
    Circle(-0.782,-0.58,0.005,100);
    Circle(-0.72,-0.58,0.005,100);
    Circle(-0.615,-0.58,0.005,100);
    Circle(-0.535,-0.58,0.005,100);
    Circle(-0.415,-0.58,0.005,100);
    Circle(-0.335,-0.58,0.005,100);
    Circle(-0.215,-0.58,0.005,100);
    Circle(-0.135,-0.58,0.005,100);

    ///Front white
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);

    glVertex2f(-0.88f,-0.54f);
    glVertex2f(-0.88f,-0.58f);
    glVertex2f(-0.9f,-0.58f);
    glVertex2f(-0.89f,-0.54f);
    glEnd();


    //Light
    Triangle(-0.88f, -0.50f, -0.98f, -0.60f, -0.93f, -0.60f, 1.0f, 1.0f, 0.0f);

    glLoadIdentity();
    glLoadIdentity();

}

void drawlampPost()
{
    glColor3f(0.737f, 0.565f, 0.565f);

    //stand
    glBegin(GL_QUADS);
    glVertex2f(-0.98f,0.0f);
    glVertex2f(-0.98f,0.15f);
    glVertex2f(-0.97f,0.15f);
    glVertex2f(-0.97f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.98f,0.15f);
    glVertex2f(-0.98f,0.17f);
    glVertex2f(-0.92f,0.17f);
    glVertex2f(-0.92f,0.15f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    Circle(-0.93f, 0.11f, 0.009f, 100);

    glColor3f(0.737f, 0.565f, 0.565f);
    Triangle(-0.93f, 0.16f, -0.95f, 0.11f, -0.91f, 0.11f, 0.737f, 0.565f, 0.565f);


}

void drawlampPostnight()
{
     glColor3f(0.737f, 0.565f, 0.565f);

    //stand
    glBegin(GL_QUADS);
    glVertex2f(-0.98f,0.0f);
    glVertex2f(-0.98f,0.15f);
    glVertex2f(-0.97f,0.15f);
    glVertex2f(-0.97f,0.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.98f,0.15f);
    glVertex2f(-0.98f,0.17f);
    glVertex2f(-0.92f,0.17f);
    glVertex2f(-0.92f,0.15f);
    glEnd();

    Triangle(-0.93f, 0.16f, -0.96f, -0.05f, -0.90f, -0.05f, 1.0f,1.0f,0.9f,0.5f);
    glColor3f(1.0f, 1.0f, 0.0f);
    Circle(-0.93f, 0.11f, 0.009f, 100);

    glColor3f(0.737f, 0.565f, 0.565f);
    Triangle(-0.93f, 0.16f, -0.95f, 0.11f, -0.91f, 0.11f, 0.737f, 0.565f, 0.565f);

}

void drawVehiclesDay1()
{
    ///Cyan Car

glTranslatef(positionCyanCar, 0.2f, 0.0f);
//body
glColor3f(0.0f, 1.0f, 1.0f);
glBegin(GL_QUADS);



glVertex2f(-0.05f,-0.19f);
glVertex2f(-0.05f,-0.28f);
glVertex2f(-0.3f,-0.28f);
glVertex2f(-0.3f,-0.19f);
glEnd();



//upper body
glColor3f(0.0f, 1.0f, 1.0f);
glBegin(GL_QUADS);



glVertex2f(-0.1f,-0.11f);
glVertex2f(-0.07f,-0.19f);
glVertex2f(-0.29f,-0.19f);
glVertex2f(-0.25f,-0.11f);
glEnd();



//Window border
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);



glVertex2f(-0.1055f,-0.12f);
glVertex2f(-0.08f,-0.19f);
glVertex2f(-0.28f,-0.19f);
glVertex2f(-0.24555f,-0.12f);
glEnd();



//Left window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.18f,-0.13f);
glVertex2f(-0.18f,-0.18f);
glVertex2f(-0.27f,-0.18f);
glVertex2f(-0.24f,-0.13f);
glEnd();



//Right window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.11f,-0.13f);
glVertex2f(-0.09f,-0.18f);
glVertex2f(-0.17f,-0.18f);
glVertex2f(-0.17f,-0.13f);
glEnd();



//Car wheel
glColor3f(0.0f,0.0f,0.0f);
Circle(-0.25,-0.28,0.035,100);
Circle(-0.1,-0.28,0.035,100);



glColor3f(1.0f,1.0f,1.0f);
Circle(-0.25,-0.28,0.01,100);
Circle(-0.1,-0.28,0.01,100);

glLoadIdentity();

    ///Green bus

    glTranslatef(positionGreenBus, 0.0f, 0.0f);
 //body
glColor3f(0.0f, 1.0f, 0.0f);
glBegin(GL_QUADS);



glVertex2f(-0.6f,-0.08f);
glVertex2f(-0.6f,-0.28f);
glVertex2f(-0.9f,-0.28f);
glVertex2f(-0.9f,-0.08f);
glEnd();



//Window border
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);



glVertex2f(-0.64f,-0.1f);
glVertex2f(-0.64f,-0.21f);
glVertex2f(-0.89f,-0.21f);
glVertex2f(-0.89f,-0.1f);
glEnd();




//left window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.83f,-0.11f);
glVertex2f(-0.83f,-0.2f);
glVertex2f(-0.88f,-0.2f);
glVertex2f(-0.88f,-0.11f);
glEnd();



//Middle 1 window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.77f,-0.11f);
glVertex2f(-0.77f,-0.2f);
glVertex2f(-0.82f,-0.2f);
glVertex2f(-0.82f,-0.11f);
glEnd();



//Middle 2 window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.71f,-0.11f);
glVertex2f(-0.71f,-0.2f);
glVertex2f(-0.76f,-0.2f);
glVertex2f(-0.76f,-0.11f);
glEnd();



//Right window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.65f,-0.11f);
glVertex2f(-0.65f,-0.2f);
glVertex2f(-0.7f,-0.2f);
glVertex2f(-0.7f,-0.11f);
glEnd();



//Front glass border
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);



glVertex2f(-0.6f,-0.1f);
glVertex2f(-0.6f,-0.24f);
glVertex2f(-0.62f,-0.22f);
glVertex2f(-0.62f,-0.1f);
glEnd();



//Front glass
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.6f,-0.11f);
glVertex2f(-0.6f,-0.23f);
glVertex2f(-0.61f,-0.22f);
glVertex2f(-0.61f,-0.11f);
glEnd();



//Bus wheel
glColor3f(0.0f,0.0f,0.0f);
Circle(-0.83,-0.28,0.035,100);
Circle(-0.67,-0.28,0.035,100);



glColor3f(1.0f,1.0f,1.0f);
Circle(-0.83,-0.28,0.01,100);
Circle(-0.67,-0.28,0.01,100);


glLoadIdentity();



///Blue Bus

glTranslatef(positionBlueBus, 0.0f, 0.0f);
//body
glColor3f(0.0f, 0.0f, 01.0f);
glBegin(GL_QUADS);
glVertex2f(0.9f,-0.08f);
glVertex2f(0.9f,-0.28f);
glVertex2f(0.6f,-0.28f);
glVertex2f(0.6f,-0.08f);
glEnd();



//Window border
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);



glVertex2f(0.86f,-0.1f);
glVertex2f(0.86f,-0.21f);
glVertex2f(0.61f,-0.21f);
glVertex2f(0.61f,-0.1f);
glEnd();




//left window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(0.67f,-0.11f);
glVertex2f(0.67f,-0.2f);
glVertex2f(0.62f,-0.2f);
glVertex2f(0.62f,-0.11f);
glEnd();



//Middle 1 window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(0.73f,-0.11f);
glVertex2f(0.73f,-0.2f);
glVertex2f(0.68f,-0.2f);
glVertex2f(0.68f,-0.11f);
glEnd();



//Middle 2 window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(0.79f,-0.11f);
glVertex2f(0.79f,-0.2f);
glVertex2f(0.74f,-0.2f);
glVertex2f(0.74f,-0.11f);
glEnd();



//Right window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(0.85f,-0.11f);
glVertex2f(0.85f,-0.2f);
glVertex2f(0.8f,-0.2f);
glVertex2f(0.8f,-0.11f);
glEnd();



//Front glass border
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);



glVertex2f(0.9f,-0.1f);
glVertex2f(0.9f,-0.24f);
glVertex2f(0.88f,-0.22f);
glVertex2f(0.88f,-0.1f);
glEnd();



//Front glass
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(0.9f,-0.11f);
glVertex2f(0.9f,-0.23f);
glVertex2f(0.89f,-0.22f);
glVertex2f(0.89f,-0.11f);
glEnd();



//Bus wheel
glColor3f(0.0f,0.0f,0.0f);
Circle(0.83,-0.28,0.035,100);
Circle(0.67,-0.28,0.035,100);



glColor3f(1.0f,1.0f,1.0f);
Circle(0.83,-0.28,0.01,100);
Circle(0.67,-0.28,0.01,100);

glLoadIdentity();

}
void drawVehiclesDay2()
{
    ///Orange car
    glTranslatef(positionOrangeCar, 0.02f, 0.0f);
//Body
glColor3ub(255, 140, 0);
glBegin(GL_QUADS);



glVertex2f(0.5f,-0.75f);
glVertex2f(0.5f,-0.84f);
glVertex2f(0.25f,-0.84f);
glVertex2f(0.25f,-0.75f);
glEnd();




//Upper body
glColor3ub(255, 140, 0);
glBegin(GL_QUADS);



glVertex2f(0.47f,-0.67f);
glVertex2f(0.49f,-0.75f);
glVertex2f(0.28f,-0.75f);
glVertex2f(0.31f,-0.67f);
glEnd();



//Window Border
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);



glVertex2f(0.465f,-0.68f);
glVertex2f(0.48f,-0.75f);
glVertex2f(0.29f,-0.75f);
glVertex2f(0.3155f,-0.68f);
glEnd();



//left Window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(0.38f,-0.69f);
glVertex2f(0.38f,-0.74f);
glVertex2f(0.3f,-0.74f);
glVertex2f(0.32f,-0.69f);
glEnd();



//Right Window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(0.46f,-0.69f);
glVertex2f(0.47f,-0.74f);
glVertex2f(0.39f,-0.74f);
glVertex2f(0.39f,-0.69f);
glEnd();




//Car wheel
glColor3f(0.0f,0.0f,0.0f);
Circle(0.45,-0.84,0.035,100);
Circle(0.3,-0.84,0.035,100);



glColor3f(1.0f,1.0f,1.0f);
Circle(0.45,-0.84,0.01,100);
Circle(0.3,-0.84,0.01,100);


glLoadIdentity();



///Olive car

glTranslatef(positionOliveCar, 0.0f, 0.0f);
//Body
glColor3ub(135, 140, 0);
glBegin(GL_QUADS);



glVertex2f(-0.5f,-0.75f);
glVertex2f(-0.5f,-0.84f);
glVertex2f(-0.25f,-0.84f);
glVertex2f(-0.25f,-0.75f);
glEnd();




//Upper body
glColor3ub(135, 140,0);
glBegin(GL_QUADS);



glVertex2f(-0.25f,-0.67f);
glVertex2f(-0.25f,-0.75f);
glVertex2f(-0.48f,-0.75f);
glVertex2f(-0.45f,-0.67f);
glEnd();



//Window Border
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);



glVertex2f(-0.26f,-0.68f);
glVertex2f(-0.26f,-0.76f);
glVertex2f(-0.47f,-0.76f);
glVertex2f(-0.44f,-0.68f);
glEnd();



//left Window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.41f,-0.69f);
glVertex2f(-0.41f,-0.75f);
glVertex2f(-0.46f,-0.75f);
glVertex2f(-0.4355f,-0.69f);
glEnd();




//Middle Window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.34f,-0.69f);
glVertex2f(-0.34f,-0.75f);
glVertex2f(-0.4f,-0.75f);
glVertex2f(-0.4f,-0.69f);
glEnd();




//Right Window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.27f,-0.69f);
glVertex2f(-0.27f,-0.75f);
glVertex2f(-0.33f,-0.75f);
glVertex2f(-0.33f,-0.69f);
glEnd();




//Car wheel
glColor3f(0.0f,0.0f,0.0f);
Circle(-0.45,-0.84,0.035,100);
Circle(-0.3,-0.84,0.035,100);



glColor3f(1.0f,1.0f,1.0f);
Circle(-0.45,-0.84,0.01,100);
Circle(-0.3,-0.84,0.01,100);

glLoadIdentity();
}


void drawVehiclesNight1()
{
     ///Cyan Car

    glTranslatef(positionCyanCar, 0.2f, 0.0f);

    Triangle(-0.05f, -0.24f, -0.01f, -0.29f, 0.01f, -0.29f, 1.0f, 1.0f, 0.0f);
    //body
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);



    glVertex2f(-0.05f,-0.19f);
    glVertex2f(-0.05f,-0.28f);
    glVertex2f(-0.3f,-0.28f);
    glVertex2f(-0.3f,-0.19f);
    glEnd();



    //upper body
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);



    glVertex2f(-0.1f,-0.11f);
    glVertex2f(-0.07f,-0.19f);
    glVertex2f(-0.29f,-0.19f);
    glVertex2f(-0.25f,-0.11f);
    glEnd();



    //Window border
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);



    glVertex2f(-0.1055f,-0.12f);
    glVertex2f(-0.08f,-0.19f);
    glVertex2f(-0.28f,-0.19f);
    glVertex2f(-0.24555f,-0.12f);
    glEnd();



    //Left window
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(-0.18f,-0.13f);
    glVertex2f(-0.18f,-0.18f);
    glVertex2f(-0.27f,-0.18f);
    glVertex2f(-0.24f,-0.13f);
    glEnd();



    //Right window
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(-0.11f,-0.13f);
    glVertex2f(-0.09f,-0.18f);
    glVertex2f(-0.17f,-0.18f);
    glVertex2f(-0.17f,-0.13f);
    glEnd();



    //Car wheel
    glColor3f(0.0f,0.0f,0.0f);
    Circle(-0.25,-0.28,0.035,100);
    Circle(-0.1,-0.28,0.035,100);



    glColor3f(1.0f,1.0f,1.0f);
    Circle(-0.25,-0.28,0.01,100);
    Circle(-0.1,-0.28,0.01,100);

    glLoadIdentity();


    ///Green bus

    glTranslatef(positionGreenBus, 0.0f, 0.0f);

    Triangle(-0.6f, -0.26f, -0.55f, -0.29f, -0.5f, -0.29f, 1.0f, 1.0f, 0.0f);
    //body
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);



    glVertex2f(-0.6f,-0.08f);
    glVertex2f(-0.6f,-0.28f);
    glVertex2f(-0.9f,-0.28f);
    glVertex2f(-0.9f,-0.08f);
    glEnd();



    //Window border
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);



    glVertex2f(-0.64f,-0.1f);
    glVertex2f(-0.64f,-0.21f);
    glVertex2f(-0.89f,-0.21f);
    glVertex2f(-0.89f,-0.1f);
    glEnd();




    //left window
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(-0.83f,-0.11f);
    glVertex2f(-0.83f,-0.2f);
    glVertex2f(-0.88f,-0.2f);
    glVertex2f(-0.88f,-0.11f);
    glEnd();



    //Middle 1 window
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(-0.77f,-0.11f);
    glVertex2f(-0.77f,-0.2f);
    glVertex2f(-0.82f,-0.2f);
    glVertex2f(-0.82f,-0.11f);
    glEnd();



    //Middle 2 window
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(-0.71f,-0.11f);
    glVertex2f(-0.71f,-0.2f);
    glVertex2f(-0.76f,-0.2f);
    glVertex2f(-0.76f,-0.11f);
    glEnd();



    //Right window
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(-0.65f,-0.11f);
    glVertex2f(-0.65f,-0.2f);
    glVertex2f(-0.7f,-0.2f);
    glVertex2f(-0.7f,-0.11f);
    glEnd();



    //Front glass border
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);



    glVertex2f(-0.6f,-0.1f);
    glVertex2f(-0.6f,-0.24f);
    glVertex2f(-0.62f,-0.22f);
    glVertex2f(-0.62f,-0.1f);
    glEnd();



    //Front glass
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(-0.6f,-0.11f);
    glVertex2f(-0.6f,-0.23f);
    glVertex2f(-0.61f,-0.22f);
    glVertex2f(-0.61f,-0.11f);
    glEnd();



    //Bus wheel
    glColor3f(0.0f,0.0f,0.0f);
    Circle(-0.83,-0.28,0.035,100);
    Circle(-0.67,-0.28,0.035,100);



    glColor3f(1.0f,1.0f,1.0f);
    Circle(-0.83,-0.28,0.01,100);
    Circle(-0.67,-0.28,0.01,100);


    glLoadIdentity();



    ///Blue Bus

    glTranslatef(positionBlueBus, 0.0f, 0.0f);

    Triangle(0.9f, -0.26f, 0.95f, -0.29f, 1.0f, -0.29f, 1.0f, 1.0f, 0.0f);
    //body
    glColor3f(0.0f, 0.0f, 01.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.9f,-0.08f);
    glVertex2f(0.9f,-0.28f);
    glVertex2f(0.6f,-0.28f);
    glVertex2f(0.6f,-0.08f);
    glEnd();



    //Window border
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);



    glVertex2f(0.86f,-0.1f);
    glVertex2f(0.86f,-0.21f);
    glVertex2f(0.61f,-0.21f);
    glVertex2f(0.61f,-0.1f);
    glEnd();




    //left window
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(0.67f,-0.11f);
    glVertex2f(0.67f,-0.2f);
    glVertex2f(0.62f,-0.2f);
    glVertex2f(0.62f,-0.11f);
    glEnd();



    //Middle 1 window
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(0.73f,-0.11f);
    glVertex2f(0.73f,-0.2f);
    glVertex2f(0.68f,-0.2f);
    glVertex2f(0.68f,-0.11f);
    glEnd();



    //Middle 2 window
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(0.79f,-0.11f);
    glVertex2f(0.79f,-0.2f);
    glVertex2f(0.74f,-0.2f);
    glVertex2f(0.74f,-0.11f);
    glEnd();



    //Right window
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(0.85f,-0.11f);
    glVertex2f(0.85f,-0.2f);
    glVertex2f(0.8f,-0.2f);
    glVertex2f(0.8f,-0.11f);
    glEnd();



    //Front glass border
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);



    glVertex2f(0.9f,-0.1f);
    glVertex2f(0.9f,-0.24f);
    glVertex2f(0.88f,-0.22f);
    glVertex2f(0.88f,-0.1f);
    glEnd();



    //Front glass
    glColor3ub(128, 128, 128);
    glBegin(GL_QUADS);



    glVertex2f(0.9f,-0.11f);
    glVertex2f(0.9f,-0.23f);
    glVertex2f(0.89f,-0.22f);
    glVertex2f(0.89f,-0.11f);
    glEnd();



    //Bus wheel
    glColor3f(0.0f,0.0f,0.0f);
    Circle(0.83,-0.28,0.035,100);
    Circle(0.67,-0.28,0.035,100);



    glColor3f(1.0f,1.0f,1.0f);
    Circle(0.83,-0.28,0.01,100);
    Circle(0.67,-0.28,0.01,100);


    glLoadIdentity();


}
void drawVehiclesNight2()
{
 ///Orange car
glTranslatef(positionOrangeCar, 0.0f, 0.0f);
Triangle(0.25f, -0.81f, 0.21f, -0.85f, 0.19f, -0.85f, 1.0f, 1.0f, 0.0f);
//Body
glColor3ub(255, 140, 0);
glBegin(GL_QUADS);

glVertex2f(0.5f,-0.75f);
glVertex2f(0.5f,-0.84f);
glVertex2f(0.25f,-0.84f);
glVertex2f(0.25f,-0.75f);
glEnd();




//Upper body
glColor3ub(255, 140, 0);
glBegin(GL_QUADS);



glVertex2f(0.47f,-0.67f);
glVertex2f(0.49f,-0.75f);
glVertex2f(0.28f,-0.75f);
glVertex2f(0.31f,-0.67f);
glEnd();



//Window Border
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);



glVertex2f(0.465f,-0.68f);
glVertex2f(0.48f,-0.75f);
glVertex2f(0.29f,-0.75f);
glVertex2f(0.3155f,-0.68f);
glEnd();



//left Window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(0.38f,-0.69f);
glVertex2f(0.38f,-0.74f);
glVertex2f(0.3f,-0.74f);
glVertex2f(0.32f,-0.69f);
glEnd();



//Right Window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(0.46f,-0.69f);
glVertex2f(0.47f,-0.74f);
glVertex2f(0.39f,-0.74f);
glVertex2f(0.39f,-0.69f);
glEnd();




//Car wheel
glColor3f(0.0f,0.0f,0.0f);
Circle(0.45,-0.84,0.035,100);
Circle(0.3,-0.84,0.035,100);



glColor3f(1.0f,1.0f,1.0f);
Circle(0.45,-0.84,0.01,100);
Circle(0.3,-0.84,0.01,100);


glLoadIdentity();



///Olive car

glTranslatef(positionOliveCar, 0.02f, 0.0f);
Triangle(-0.5f, -0.81f, -0.53f, -0.85f, -0.55f, -0.85f, 1.0f, 1.0f, 0.0f);
//Body
glColor3ub(135, 140, 0);
glBegin(GL_QUADS);



glVertex2f(-0.5f,-0.75f);
glVertex2f(-0.5f,-0.84f);
glVertex2f(-0.25f,-0.84f);
glVertex2f(-0.25f,-0.75f);
glEnd();




//Upper body
glColor3ub(135, 140,0);
glBegin(GL_QUADS);



glVertex2f(-0.25f,-0.67f);
glVertex2f(-0.25f,-0.75f);
glVertex2f(-0.48f,-0.75f);
glVertex2f(-0.45f,-0.67f);
glEnd();



//Window Border
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_QUADS);



glVertex2f(-0.26f,-0.68f);
glVertex2f(-0.26f,-0.76f);
glVertex2f(-0.47f,-0.76f);
glVertex2f(-0.44f,-0.68f);
glEnd();



//left Window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.41f,-0.69f);
glVertex2f(-0.41f,-0.75f);
glVertex2f(-0.46f,-0.75f);
glVertex2f(-0.4355f,-0.69f);
glEnd();




//Middle Window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.34f,-0.69f);
glVertex2f(-0.34f,-0.75f);
glVertex2f(-0.4f,-0.75f);
glVertex2f(-0.4f,-0.69f);
glEnd();




//Right Window
glColor3ub(128, 128, 128);
glBegin(GL_QUADS);



glVertex2f(-0.27f,-0.69f);
glVertex2f(-0.27f,-0.75f);
glVertex2f(-0.33f,-0.75f);
glVertex2f(-0.33f,-0.69f);
glEnd();




//Car wheel
glColor3f(0.0f,0.0f,0.0f);
Circle(-0.45,-0.84,0.035,100);
Circle(-0.3,-0.84,0.035,100);



glColor3f(1.0f,1.0f,1.0f);
Circle(-0.45,-0.84,0.01,100);
Circle(-0.3,-0.84,0.01,100);

glLoadIdentity();


}


void display() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
   glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();

glPushMatrix();

if(!rainday)
{
    if (!night)
    {
        drawSky();
        drawsun();
        drawcloud();
        drawBuilding();
        drawtree();

        glTranslatef(-0.13f, 0.0f, 0.0f);
        drawtree();
        glLoadIdentity();
        glTranslatef(1.12f, 0.0f, 0.0f);
        drawtree();
        glLoadIdentity();



        //Upper road lamp post
        drawlampPost();

        glTranslatef(0.3f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(0.6f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(0.9f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.2f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.5f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.8f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();

//////////////////////////////////////////////////////

        drawrailway();
        drawroad();
        drawVehiclesDay1();
        drawtrain();
        drawVehiclesDay2();

////////////////////////////////////////////////////////

        //lamposts of road2
        glTranslatef(0.0f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
         glTranslatef(0.3f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(0.6f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(0.9f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.2f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.5f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.8f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();

    }
    else
    {
        drawskynight();
        drawmoon();
        drawnightcloud();
        drawbuildingnight();
        drawnighttree();
        glTranslatef(-0.13f, 0.0f, 0.0f);
        drawnighttree();
        glLoadIdentity();
        glTranslatef(1.12f, 0.0f, 0.0f);
        drawnighttree();
        glLoadIdentity();


        //LampPosts of road 1t
        drawlampPostnight();
        glTranslatef(0.3f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(0.6f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(0.9f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.2f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.5f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.8f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();

//////////////////////////////////////////////////////////////

        drawrailwaynight();
        drawroadnight();
        drawVehiclesNight1();
        drawtrainnight();
        drawVehiclesNight2();

//////////////////////////////////////////////////////////////

         //lamposts of road2
        glTranslatef(0.0f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
         glTranslatef(0.3f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(0.6f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(0.9f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.2f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.5f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.8f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();

    }

    glPopMatrix();

}
else
{
    if (!night)
    {
        drawskyrain();
        drawraincloud();
        drawBuilding();
        drawtree();
        glTranslatef(-0.13f, 0.0f, 0.0f);
        drawtree();
        glLoadIdentity();
        glTranslatef(1.12f, 0.0f, 0.0f);
        drawtree();
        glLoadIdentity();


         //Upper road lamp post
        drawlampPost();

        glTranslatef(0.3f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(0.6f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(0.9f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.2f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.5f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.8f, 0.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
/////////////////////////////////////////////////////////////////////////////////
drawrailway();
        drawroad();
        drawVehiclesDay1();
        drawtrain();
        drawVehiclesDay2();

//////////////////////////////////////////////////////////////////////////////////
        //lamposts of road2
        glTranslatef(0.0f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
         glTranslatef(0.3f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(0.6f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(0.9f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.2f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.5f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();
        glTranslatef(1.8f, -1.0f, 0.0f);
        drawlampPost();
        glLoadIdentity();

        drawrain();



    }
    else
    {
        drawskynight();
        drawraincloud();
        drawbuildingnight();
        drawnighttree();
        glTranslatef(-0.13f, 0.0f, 0.0f);
        drawnighttree();
        glLoadIdentity();
        glTranslatef(1.12f, 0.0f, 0.0f);
        drawnighttree();
        glLoadIdentity();


        drawlampPostnight();
        glTranslatef(0.3f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(0.6f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(0.9f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.2f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.5f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.8f, 0.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();

/////////////////////////////////////////////////////////////////////////
        drawrailwaynight();
        drawroadnight();
        drawVehiclesNight1();
        drawtrainnight();
        drawVehiclesNight2();
/////////////////////////////////////////////////////////////////////////

         //lamposts of road2
        glTranslatef(0.0f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
         glTranslatef(0.3f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(0.6f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(0.9f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.2f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.5f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();
        glTranslatef(1.8f, -1.0f, 0.0f);
        drawlampPostnight();
        glLoadIdentity();

        drawrain();


    }

glPopMatrix();
}

   glFlush();
}
/*

void trafficsound()
{
    PlaySound("traffic.wav", NULL, SND_ASYNC|SND_FILENAME);
}

void trafficsoundOff()
{
    PlaySound("off.wav", NULL, SND_ASYNC|SND_FILENAME);
}

void rainsound()
{
PlaySound("rain.wav", NULL, SND_ASYNC|SND_FILENAME);
}
void rainsoundOff()
{
PlaySound("off.wav", NULL, SND_ASYNC|SND_FILENAME);
}

void trainsound()
{
    PlaySound("train-whistle-01.wav", NULL, SND_ASYNC|SND_FILENAME);

}
void trainsoundOff()
{
PlaySound("off.wav", NULL, SND_ASYNC|SND_FILENAME);
}

void handleKeypress(unsigned char key, int x, int y) {

    switch (key) {

    case 'n':
        night = true;
        updateMoon(0);
        positionSun=0;
        break;
    case 'd':
        night = false;
        updateSun(0);
        positionMoon=0;
        break;
    case 'r':
        rainday = true;
        rainsound();
        break;
    case 't':
        rainday = false;
        rainsoundOff();
        break;
    case 'h' :
        trainsound();
        break;
    case 'j' :
        trainsoundOff();
        break;
    case 'c' :
        trafficsound();
        break;
    case 'a' :
        trafficsoundOff();
        break;
glutPostRedisplay();


	}
}
*/

int main(int argc, char** argv) {
   glutInit(&argc, argv);
   glutInitWindowSize(1800, 720);
   glutInitWindowPosition(50, 50);
   glutCreateWindow(" A Regular City Life ");
   glutDisplayFunc(display);
   glutMouseFunc(handleMouse);
  // glutKeyboardFunc(handleKeypress);
   glutTimerFunc(100, updateCloud1, 0);
   glutTimerFunc(100, updateCloud2, 0);
   glutTimerFunc(100, updateSun, 0);
   glutTimerFunc(100, updateRain, 0);
   glutTimerFunc(100, updateGreenBus, 0);
   glutTimerFunc(100, updateBlueBus, 0);
   glutTimerFunc(100, updateCyanCar, 0);
   glutTimerFunc(100, updateOliveCar, 0);
   glutTimerFunc(100, updateOrangeCar, 0);
   glutTimerFunc(30,updateTrain,0);
   glutMainLoop();
   return 0;
}
