//*************************
// Wrriten by Hossein Pejman
// June 2006
//**************************


#include "GL\glut.h"
#include "conio.h"
#include "stdio.h"


static float Lookx = 40;      //Place that we stand
static float Looky = 40;
static float Lookz = 100;

static float ei = 0;          //Place that we see
static float ej = 0;
static float ek = 0;

static float j = 65;          //For transfer object
static float i = 0;
static float k = 0;

static float i2 = 0;          //For rotate object
static float k2 = 0;
static float j2 = 0;
static float ag = 0;

static float color1 = 0;      //For color of Object
static float color2 = 1;
static float color3 = 0;

static int mainw = -1;        //For managing windows
static int sw1 = -1;
static int sw2 = -1;
static int sw3 = -1;

int flag1 = 0;                //For sub windows
int flag2 = 0;
int flag3 = 0;

int wwin = 600;               //For size windows
int hwin = 500;

static float out = 6;         //For sub window left
static float in = 3;
static int flaga1 = 0;
static float agsw1 = 0;
static float xb = 1;
static float yb = 1;
static float zb = 0;

static int flaga2 = 0;        //For sub window right
static float agsw = 0;
static float xa = 1;
static float ya = 1;
static float za = 0;
static float r = 5;
static float h = 8;
static int   fl = 0;

static float spw1 = 0.05;     //Control speed for left sub windows 

static float spw2 = 0.005;    //Control speed for right sub windows 

static float spw3 = 0.05;     //Control size for down sub window  

static int first = 0;         //For first animation

static int f = 0;             //For select object

static int f1 = 0;			//For object animation

static float u = 65;          //For Sphere animation
static float sp = 0.3;
static int f2 = 0;

static int floorff = 0;       //For  select floor 

static float floorss = 100;   //For  floor model2 

static float co1 = 0.05;      //For  size floor  
static float co2 = 20;


GLbyte HP[14] = { 'H', 'o', 's', 's', 'e', 'i', 'n', ' ', 'P', 'e', 'j', 'm', 'a', 'n' };


//=====================================Animation Function===========================

void AnimateSubW1()
{

	if (out < 10 && flaga1 == 0)
	{
		in = in + 0.01;
		out = out + 0.01;
	}
	else
	{
		flaga1 = 1;
	}
	if (out > 6 && flaga1 == 1)
	{
		in = in - 0.01;
		out = out - 0.01;
	}
	else
	{
		flaga1 = 0;
	}
	agsw1 = agsw1 + spw1;
	glutPostRedisplay();

}
//***********************************
void AnimateSubW2()
{
	if (agsw < 720 && flaga2 == 0)
	{
		agsw = agsw + spw2;
	}
	else
	{
		flaga2 = 1;
	}


	if (agsw > 0 && flaga2 == 1)
	{
		agsw = agsw - spw2;
	}
	else
	{
		flaga2 = 0;
	}


	if (fl == 0 && h < 10)
	{
		h = h + 0.002;
		r = r + 0.001;
	}
	else
	{
		fl = 1;
	}


	if (fl == 1 && h > 4)
	{
		r = r - 0.001;
		h = h - 0.002;
	}
	else
	{
		fl = 0;
	}


	glutPostRedisplay();

}

//==============================sub window Function==========================
void DisplaySubW1()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glOrtho(-20, 20, -20, 20, 20, -20);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 5, 0);

	glColor3f(0, 0, 1);
	glRotatef(agsw1, xb, yb, zb);
	glutWireTorus(in, out, 20, 20);
	glutSwapBuffers();

}

//****************************************

void DisplaySubW2()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glOrtho(-10, 10, -10, 10, -10, 10);
	gluLookAt(2, -1, 2, 0, 0, 0, 0, 5, 0);

	glColor3f(1, 0, 0);
	glRotatef(agsw, xa, ya, za);
	glutWireCone(r, h, 20, 20);

	glutSwapBuffers();

}


//****************************************

void DisplaySubW3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(-20, 20, -20, 20);


	float a1x, a1y, b1x, b1y, c1x, c1y, d1x, d1y;
	a1x = -20;
	a1y = -20;
	b1x = -20;
	b1y = 20; 
	c1x = 20;
	c1y = 20;
	d1x = 20;
	d1y = -20;
	float color3 = 0;
	for (int nn = 0; nn < 25; nn++)
	{
		glColor3f(color3, color3, color3);
		glBegin(GL_LINE_LOOP);
		glVertex2f(b1x, b1y);
		glVertex2f(a1x, a1y);
		glVertex2f(d1x, d1y);
		glVertex2f(c1x, c1y);
		glVertex2f(b1x, b1y);
		glEnd();

		a1x = a1x + spw3*(b1x - a1x);
		a1y = a1y + spw3*(b1y - a1y);
		b1x = b1x + spw3*(c1x - b1x);
		b1y = b1y + spw3*(c1y - b1y);
		c1x = c1x + spw3*(d1x - c1x);
		c1y = c1y + spw3*(d1y - c1y);
		d1x = d1x + spw3*(a1x - d1x);
		d1y = d1y + spw3*(a1y - d1y);

		color3 = color3 + 0.04;
	}


	glutSwapBuffers();

}

//==============================Table Function==========================

void Table()
{

	glColor3f(0.7, 0.4, 0.1);
	glTranslatef(50, 0, 50);
	glRotatef(-90, 1, 0, 0);

	GLUquadricObj* obj;

	obj = gluNewQuadric();

	gluCylinder(obj, 3, 3, 50, 10, 10);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-50, 0, -50);

	glColor3f(0.7, 0.4, 0.1);
	glTranslatef(-50, 0, -50);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(obj, 3, 3, 50, 10, 10);
	glRotatef(90, 1, 0, 0);
	glTranslatef(50, 0, 50);

	glColor3f(0.7, 0.4, 0.1);
	glTranslatef(-50, 0, 50);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(obj, 3, 3, 50, 10, 10);
	glRotatef(90, 1, 0, 0);
	glTranslatef(50, 0, -50);

	glColor3f(0.7, 0.4, 0.1);
	glTranslatef(50, 0, -50);
	glRotatef(-90, 1, 0, 0);
	gluCylinder(obj, 3, 3, 50, 10, 10);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-50, 0, 50);

	glColor3f(0.6, 0.4, 0.1);
	glBegin(GL_POLYGON);	   //Down
	glVertex3f(60, 50, -60);
	glVertex3f(60, 50, 60);
	glVertex3f(-60, 50, 60);
	glVertex3f(-60, 50, -60);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.6, 0.1);
	glVertex3f(-60, 50, -60);
	glVertex3f(-60, 60, -60);
	glVertex3f(-60, 60, 60);
	glVertex3f(-60, 50, 60);
	glEnd();

	glColor3f(0.8, 0.7, 0.2);
	glBegin(GL_POLYGON);
	glVertex3f(60, 50, -60);
	glVertex3f(60, 60, -60);
	glVertex3f(-60, 60, -60);
	glVertex3f(-60, 50, -60);
	glEnd();

	glColor3f(0.7, 0.4, 0.1);
	glBegin(GL_POLYGON);      //up
	glVertex3f(60, 60, -60);
	glVertex3f(60, 60, 60);
	glVertex3f(-60, 60, 60);
	glVertex3f(-60, 60, -60);
	glEnd();

	glColor3f(0.8, 0.7, 0.2);
	glBegin(GL_POLYGON);
	glVertex3f(60, 50, -60);
	glVertex3f(60, 60, -60);
	glVertex3f(60, 60, 60);
	glVertex3f(60, 50, 60);
	glEnd();

	glColor3f(0.8, 0.6, 0.1);
	glBegin(GL_POLYGON);
	glVertex3f(60, 50, 60);
	glVertex3f(60, 60, 60);
	glVertex3f(-60, 60, 60);
	glVertex3f(-60, 50, 60);
	glEnd();

}

//==============================Room Function==========================

void Room()
{
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.9, 0.7);
	glVertex3f(-500, 500, 500);
	glVertex3f(-500, 500, -500);
	glVertex3f(500, 500, -500);
	glVertex3f(500, 500, 500);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0.9);
	glVertex3f(-500, 0, 500);
	glVertex3f(-500, 0, -500);
	glVertex3f(-500, 500, -500);
	glVertex3f(-500, 500, 500);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.9, 0.8);
	glVertex3f(-500, 0, -500);
	glVertex3f(500, 0, -500);
	glVertex3f(500, 500, -500);
	glVertex3f(-500, 500, -500);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 0.9);
	glVertex3f(500, 0, -500);
	glVertex3f(500, 0, 500);
	glVertex3f(500, 500, 500);
	glVertex3f(500, 500, -500);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.9, 0.8);
	glVertex3f(500, 0, 500);
	glVertex3f(-500, 0, 500);
	glVertex3f(-500, 500, 500);
	glVertex3f(500, 500, 500);
	glEnd();

}
//==============================Floor Function==========================
void Floor()
{
	//************************* Model 1
	if (floorff == 0)
	{
		float ax, az, bx, bz, dx, a, b, c;
		float po[8];
		b = 1.0;
		ax = -500.0;
		az = 500.0;
		bx = -500.0;
		bz = -500.0;
		dx = 500.0;
		a = 0;
		c = 1;

		for (int p = 0; p < co2; p++)
		{
			po[0] = dx + b*(ax - dx);
			po[2] = dx + (b - co1)*(ax - dx);
			po[4] = po[2];
			po[6] = po[0];
			b = float(b - co1);
			for (int p1 = 0; p1 < co2; p1++)
			{
				po[1] = az + a*(bz - az);
				po[3] = po[1];
				po[5] = az + (a + co1)*(bz - az);
				po[7] = po[5];
				a = float(a + co1);
				if (c == 1) { glColor3f(0, 0, 0); }
				if (c == -1){ glColor3f(1, 1, 1); }
				c = c*(-1);
				glBegin(GL_POLYGON);
				glVertex3f(po[0], 0, po[1]);
				glVertex3f(po[2], 0, po[3]);
				glVertex3f(po[4], 0, po[5]);
				glVertex3f(po[6], 0, po[7]);
				glEnd();
			}
			a = 0;
			c = c*(-1);
		}
	}

	//************************* Model 2
	if (floorff == 1)
	{
		float m = 0.2;
		float a111x, a111z, b111x, b111z, c111x, c111z, d111x, d111z;
		float a11x, a11z, b11x, b11z, c11x, c11z, d11x, d11z;
		float a1x, a1z, b1x, b1z, c1x, c1z, d1x, d1z;

		for (int cf1 = 0; cf1 <= 2 * (500.0 / floorss); cf1++)
		{
			a111x = -500;
			a111z = -500 + floorss*cf1;
			b111x = -500;
			b111z = (-500 - floorss) + floorss*cf1;
			c111x = (-500 - floorss);
			c111z = (-500 - floorss) + floorss*cf1;
			d111x = (-500 - floorss);
			d111z = -500 + floorss*cf1;

			for (int cf2 = 0; cf2 <= 2 * (500.0 / floorss); cf2++)
			{
				a11x = a111x + floorss*cf2;
				a11z = a111z;
				b11x = b111x + floorss*cf2;
				b11z = b111z;
				c11x = c111x + floorss*cf2;
				c11z = c111z;
				d11x = d111x + floorss*cf2;
				d11z = d111z;
				float color = 0.25;

				for (int nn = 0; nn < 25; nn++)
				{
					glColor3f(color, color, color);

					glBegin(GL_LINE_LOOP);
					glVertex3f(a11x, 0, a11z);
					glVertex3f(b11x, 0, b11z);
					glVertex3f(c11x, 0, c11z);
					glVertex3f(d11x, 0, d11z);
					glEnd();

					a1x = a11x + m*(b11x - a11x);
					a1z = a11z + m*(b11z - a11z);
					b1x = b11x + m*(c11x - b11x);
					b1z = b11z + m*(c11z - b11z);
					c1x = c11x + m*(d11x - c11x);
					c1z = c11z + m*(d11z - c11z);
					d1x = d11x + m*(a11x - d11x);
					d1z = d11z + m*(a11z - d11z);

					a11x = a1x;
					a11z = a1z;
					b11x = b1x;
					b11z = b1z;
					c11x = c1x;
					c11z = c1z;
					d11x = d1x;
					d11z = d1z;

					color = color + 0.02;
				}

			}
		}
	}

}

//==============================Font Function===============================

void Font()
{



	glLoadIdentity();
	gluLookAt(Lookx, Looky, Lookz, ei, ej, ek, 0, 5, 0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glColor3f(0, 0, 1);

	glTranslatef(-250, 200, -490);
	glScalef(0.5, 0.5, 0.5);


	for (int i = 0; i <= 13; i++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, HP[i]);
	}
}

//**************************************

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(Lookx, Looky, Lookz, ei, ej, ek, 0, 5, 0);

	Floor();
	Room();
	Table();

	if (first == 0)
	{
		if (Lookx < 160 && Looky < 160)
		{
			Lookx = Lookx + 0.25;
			Looky = Looky + 0.25;
			glutPostRedisplay();
		}
		else
		{
			first = 1;
		}
	}
	if (f1 == 0)
	{
		if (i>65 || i < -65 || k>65 || k < -65)
		{
			if (f == 1)
			{
				if (j > 5 && f2 == 0)
				{
					j = j - sp;
					i2 = 1;
					k2 = 1;
					if (ag >= 360)
					{
						ag = 0;
					}
					ag = ag + 5;
					glutPostRedisplay();
				}
				else
				{
					if (f2 == 0){ u = u / 2.0; }
					if (j < u)
					{
						f2 = 1;
						j = j + sp;
						i2 = 1;
						k2 = 1;
						if (ag >= 360)
						{
							ag = 0;
						}
						ag = ag + 5;
						glutPostRedisplay();
					}
					else
					{
						if (u > 5)
						{
							f2 = 0;
							sp = sp - 0.05;
							glutPostRedisplay();
						}
						else
						{
							f1 = 1;
							glutPostRedisplay();
						}
					}
				}
			}
			//********************
			else
			{
				if (j > 5)
				{
					j = j - 0.5;
					i2 = 1;
					k2 = 1;
					if (ag >= 360)
					{
						ag = 0;
					}
					ag = ag + 5;
					glutPostRedisplay();
				}
				else
				{
					f1 = 1;
					glutPostRedisplay();
				}
			}
		}
	}
	glColor3f(color1, color2, color3);
	glTranslatef(i, j, k);
	glRotatef(ag, i2, j2, k2);
	if (f == 0)	{ glutWireTeapot(7); }
	if (f == 1)	{ glutWireSphere(5, 20, 20); }
	if (f == 2)	{ glutWireCube(9); }



	Font();

	glutSwapBuffers();

}

//####################################### keyboard and mouse #################################

void mykey1(unsigned char key, int x, int y)
{

	if (key == 'q' || key == 'Q') { if (Lookx > -490) { Lookx = Lookx - 2;  ei = ei - 2; }  glutPostRedisplay(); }
	if (key == 'e' || key == 'E') { if (Lookx < 490)  { Lookx = Lookx + 2;  ei = ei + 2; }  glutPostRedisplay(); }
	if (key == 'a' || key == 'A') { if (Lookz < 490)  { Lookz = Lookz + 2;  ek = ek + 2; }  glutPostRedisplay(); }
	if (key == 'd' || key == 'D') { if (Lookz > -490) { Lookz = Lookz - 2;  ek = ek - 2; }  glutPostRedisplay(); }
	if (key == 's' || key == 'S') { if (Looky > 5)    { Looky = Looky - 2;  ej = ej - 2; }  glutPostRedisplay(); }
	if (key == 'w' || key == 'W') { if (Looky < 490)  { Looky = Looky + 2;  ej = ej + 2; }  glutPostRedisplay(); }
	if (key == 'y' || key == 'Y') { k = k - 1; glutPostRedisplay(); }
	if (key == 'h' || key == 'H') { k = k + 1; glutPostRedisplay(); }
	if (key == 'g' || key == 'G') { i = i - 1; glutPostRedisplay(); }
	if (key == 'j' || key == 'J') { i = i + 1; glutPostRedisplay(); }


}

void mykeysubw1(unsigned char key, int x, int y)     //sub window Left
{
	if (key == 'x' || key == 'X') { spw1 = spw1 + 0.01;  if (spw1 > 20) { spw1 = 20; }   glutPostRedisplay(); }
	if (key == 'z' || key == 'Z') { spw1 = spw1 - 0.01;  if (spw1 < 0.05) { spw1 = 0.05; }   glutPostRedisplay(); }
}

void mykeysubw2(unsigned char key, int x, int y)     //sub window Right
{
	if (key == 'x' || key == 'X') { spw2 = spw2 + 0.002;  if (spw2 > 0.5) { spw2 = 0.5; }  glutPostRedisplay(); }
	if (key == 'z' || key == 'Z') { spw2 = spw2 - 0.002;  if (spw2 < 0.005) { spw2 = 0.005; }  glutPostRedisplay(); }
}


void mykeysubw3(unsigned char key, int x, int y)     //sub window down
{
	if (key == 'x' || key == 'X') { spw3 = spw3 + 0.001; if (spw3 > 0.08){ spw3 = 0.08; }glutPostRedisplay(); }
	if (key == 'z' || key == 'Z') { spw3 = spw3 - 0.001; if (spw3 < 0.01){ spw3 = 0.01; }glutPostRedisplay(); }

}

//*********************Special Keys************************
void mykey(int key, int x, int y)
{
	if (key == GLUT_KEY_UP)  { if (ei < 400)  ei = ei + 2;  glutPostRedisplay(); }
	if (key == GLUT_KEY_DOWN)  { if (ei > -400)  ei = ei - 2;  glutPostRedisplay(); }
	if (key == GLUT_KEY_LEFT)  { if (ek < 400)  ek = ek + 2;  glutPostRedisplay(); }
	if (key == GLUT_KEY_RIGHT)  { if (ek > -400)  ek = ek - 2;  glutPostRedisplay(); }
	if (key == GLUT_KEY_PAGE_UP)  { if (ej < 400)  ej = ej + 2;  glutPostRedisplay(); }
	if (key == GLUT_KEY_PAGE_DOWN)  { if (ej > 1)  ej = ej - 2;  glutPostRedisplay(); }

	//subwindow left
	if (key == GLUT_KEY_F1)
	{
		if (flag1 == 0 && sw2 == -1 && sw3 == -1)
		{
			sw1 = glutCreateSubWindow(mainw, 0, 0, 150, 150);
			glutInitDisplayMode(GLUT_DOUBLE);
			glutIdleFunc(AnimateSubW1);
			glutDisplayFunc(DisplaySubW1);
			glutKeyboardFunc(mykeysubw1);
			flag1 = 1;
		}
		else
		{
			if (flag1 == 1)
			{
				glutDestroyWindow(sw1);
				flag1 = 0;
				sw1 = -1;
			}
		}
	}

	//subwindow Right
	if (key == GLUT_KEY_F2)
	{
		if (flag2 == 0 && sw1 == -1 && sw3 == -1)
		{
			sw2 = glutCreateSubWindow(mainw, wwin - 150, 0, 150, 150);
			glutInitDisplayMode(GLUT_DOUBLE);
			glutIdleFunc(AnimateSubW2);
			glutDisplayFunc(DisplaySubW2);
			glutKeyboardFunc(mykeysubw2);
			flag2 = 1;
		}
		else
		{
			if (flag2 == 1)
			{
				glutDestroyWindow(sw2);
				flag2 = 0;
				sw2 = -1;
			}
		}
	}

	//subwindow Down
	if (key == GLUT_KEY_F3)
	{
		if (flag3 == 0 && sw1 == -1 && sw2 == -1)
		{
			sw3 = glutCreateSubWindow(mainw, 0, hwin - 150, 150, 150);
			glutInitDisplayMode(GLUT_DOUBLE);
			glutDisplayFunc(DisplaySubW3);
			glutKeyboardFunc(mykeysubw3);
			flag3 = 1;
		}
		else
		{
			if (flag3 == 1)
			{
				glutDestroyWindow(sw3);
				flag3 = 0;
				sw3 = -1;
			}
		}
	}

}

//###################################### START  MENU  #########################################

void main_menu(int value)
{
	if (value == 1)
	{
		k = i = 0;
		j = 65;
		k2 = i2 = j2 = 0;
		ag = 0;
		Lookx = Looky = 40;
		Lookz = 100;
		ek = ei = ej = 0;
		sw1 = sw2 = sw3 = -1;
		flag1 = flag2 = flag3 = 0;
		out = 6;
		in = 3;
		flaga1 = flaga2 = 0;
		agsw = 0;
		xa = ya = 1;
		za = 0;
		xb = yb = 1;
		zb = 0;
		agsw1 = 0;
		r = 5;
		h = 8;
		fl = f = f1 = f2 = 0;
		first = 0;
		u = 65;
		sp = 0.3;
		spw1 = spw3 = 0.05;
		spw2 = 0.005;
		spw3 = 0.05;
		color1 = color3 = 0;;
		color2 = 1;
		co1 = 0.05;
		co2 = 20;
		floorff = 0;
		floorss = 100;
		glutPostRedisplay();
	}
	if (value == 17) exit(0);
}

//**************************************
void mid1_menu(int value)
{
	if (value == 14) { f = 0; f1 = i = k = i2 = j2 = k2 = ag = 0;     j = 65;                  glutPostRedisplay(); }
	if (value == 15) { f = 1; i = k = i2 = j2 = k2 = ag = f1 = f2 = 0;  j = 65;  sp = 0.3; u = 65;   glutPostRedisplay(); }
	if (value == 16) { f = 2; f1 = i = k = i2 = j2 = k2 = ag = 0;     j = 65;                  glutPostRedisplay(); }
}

//*************************************

void mid2_menu(int value)
{
	if (value == 4)  { Lookx = 400;  Looky = 400;  Lookz = 400; ei = ej = ek = 0; glutPostRedisplay(); }
	if (value == 5)  { Lookx = 10;   Looky = 300;  Lookz = 10;  ei = ej = ek = 0; glutPostRedisplay(); }
	if (value == 6)  { Lookx = 300;  Looky = 80;   Lookz = 0;   ei = ej = ek = 0; glutPostRedisplay(); }
	if (value == 7)  { Lookx = 0;    Looky = 80;   Lookz = 300; ei = ej = ek = 0; glutPostRedisplay(); }
	if (value == 8)  { Lookx = 160;  Looky = 160;  Lookz = 100; ei = ej = ek = 0; glutPostRedisplay(); }

}

//*************************************

void mid3_menu(int value)
{

	if (value == 10)
	{
		if (floorff == 0) { co1 = 0.01; co2 = 100; }
		if (floorff == 1) { floorss = 25; }
		glutPostRedisplay();
	}

	if (value == 11)
	{
		if (floorff == 0) { co1 = 0.02; co2 = 50; }
		if (floorff == 1) { floorss = 50; }
		glutPostRedisplay();
	}

	if (value == 12)
	{
		if (floorff == 0) { co1 = 0.05; co2 = 20; }
		if (floorff == 1) { floorss = 100; }
		glutPostRedisplay();
	}

	if (value == 17)
	{
		if (floorff == 0) { co1 = 0.1;  co2 = 10; }
		if (floorff == 1) { floorss = 250; }
		glutPostRedisplay();
	}
}

//*************************************

void mid4_menu(int value)
{
	if (value == 0)
	{
		color1 = 1;
		color2 = color3 = 0;
		glutPostRedisplay();
	}
	if (value == 2)
	{
		color1 = color3 = 0;
		color2 = 1;
		glutPostRedisplay();
	}
	if (value == 3)
	{
		color3 = 1;
		color1 = color2 = 0;
		glutPostRedisplay();
	}
}

//*************************************

void mid5_menu(int value)
{
	if (value == 18)
	{
		floorff = 0;
		glutPostRedisplay();
	}
	if (value == 19)
	{
		floorff = 1;
		glutPostRedisplay();
	}
}

//*************************************

void Init()
{
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(50, (6.0 / 5.0), 1, -100);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);

}

//###################################### END  MENU  ########################################

int main(int argc, char ** argv)
{

	glutInit(&argc, argv);
	int sub_m1, sub_m2, sub_m3, sub_m4, sub_m5;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(wwin, hwin);
	glutInitWindowPosition(0, 0);
	mainw = glutCreateWindow("Graphic Project");
	Init();
	glutDisplayFunc(Display);
	glutSpecialFunc(mykey);

	glutKeyboardFunc(mykey1);

	sub_m1 = glutCreateMenu(mid1_menu);
	glutAddMenuEntry("Teapot", 14);
	glutAddMenuEntry("Sphere", 15);
	glutAddMenuEntry("Cube", 16);

	sub_m2 = glutCreateMenu(mid2_menu);
	glutAddMenuEntry("Corner", 4);
	glutAddMenuEntry("Top", 5);
	glutAddMenuEntry("Z", 6);
	glutAddMenuEntry("X", 7);
	glutAddMenuEntry("Reset place", 8);


	sub_m3 = glutCreateMenu(mid3_menu);
	glutAddMenuEntry("1/4x", 10);
	glutAddMenuEntry("1/2x", 11);
	glutAddMenuEntry("1x", 12);
	glutAddMenuEntry("2x", 17);

	sub_m4 = glutCreateMenu(mid4_menu);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);

	sub_m5 = glutCreateMenu(mid5_menu);
	glutAddMenuEntry("Model 1", 18);
	glutAddMenuEntry("Model 2", 19);

	glutCreateMenu(main_menu);

	glutAddMenuEntry("Reset", 1);
	glutAddSubMenu("Change object", sub_m1);
	glutAddSubMenu("Change camera", sub_m2);
	glutAddSubMenu("Change floor", sub_m5);
	glutAddSubMenu("Floor Scale ", sub_m3);
	glutAddSubMenu("Change color", sub_m4);
	glutAddMenuEntry("Exit", 17);

	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();

	return 0;

}


