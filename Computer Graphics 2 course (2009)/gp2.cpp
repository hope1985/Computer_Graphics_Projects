//*************************
// Wrriten by Hossein Pejman
// June 2009
//**************************

#include "windows.h"
#include "GL\glut.h"    		
#include "stdio.h"


static float Lookx = 160;      //Place that we stand
static float Looky = 180;
static float Lookz = 100;

static float ei = 0;           //Place that we see
static float ej = 70;
static float ek = 0;

static int mainw = -1;          //For managing windows

float changeCutoff = 0;
float changeSpotExponent = 0;
float changeConstant = 0.5;
float changeGlobalAmbient = 0.8;

int wwin = 1024;                  //For size windows
int hwin = 768;

static int f = 0;                 //For select object

static int Selectfloor = 0;       //For  select floor
static int Selectwall = 0;        //For  select wall
static int Selectchair = 0;
static int Selecttable = 0;
static int SelectLight = 0;
static int SelectCamera = 0;
static int DirectionLight = 0;

GLfloat  light_position0[] = { -399, 160.5, -150, 1.0 };
GLfloat  light_position1[] = { -399, 160.5, 100.0, 1.0 };
GLfloat  light_position2[] = { -150, 160.5, -399, 1.0 };
GLfloat  light_position3[] = { 100.0, 160.5, -399, 1.0 };
GLfloat  spot_direction[] = { 0.0, -1, 0 };

GLubyte texarray[400][328][3];
GLubyte texarray2[320][240][3];
GLubyte texarray3[400][199][3];
GLubyte texarray4[320][200][3];
GLubyte texarray5[380][527][3];
GLubyte texarray6[400][370][3];
GLubyte texarray7[400][271][3];
GLubyte texarray8[400][271][3];
GLubyte texarray9[320][240][3];
GLubyte texarray10[320][240][3];
GLubyte texarray11[400][286][3];
GLubyte texarray12[400][278][3];
GLubyte texarray13[400][512][3];
GLubyte texarray14[320][424][3];
GLubyte texarray15[340][237][3];
GLubyte texarray16[320][240][3];
GLubyte texarray17[100][100][3];

float L4positionx = 50;
float L4positiony = 100;
float L4positionz = 0;


float bi = 0;
float bj = 0;


void font()
{
	glRasterPos2i(10, 10);
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'h');
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, 'p');
}


void makeTexture()
{
	FILE *fd;
	GLubyte ch;
	int iii, jjj, kkk;

	//============================

	fd = fopen("texture/400328floor.raw", "rb");
	for (iii = 0; iii < 400; iii++)
	{
		for (jjj = 0; jjj < 328; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);

	//============================
	fd = fopen("texture/320240motor.raw", "rb");
	for (iii = 0; iii < 320; iii++)
	{
		for (jjj = 0; jjj < 240; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray2[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);

	//============================
	fd = fopen("texture/400199wood.raw", "rb");
	for (iii = 0; iii < 400; iii++)
	{
		for (jjj = 0; jjj < 199; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray3[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);

	//============================
	fd = fopen("texture/320200wood.raw", "rb");
	for (iii = 0; iii < 320; iii++)
	{
		for (jjj = 0; jjj < 200; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray4[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);
	//============================
	fd = fopen("texture/380527floorWall.raw", "rb");
	for (iii = 0; iii < 380; iii++)
	{
		for (jjj = 0; jjj < 527; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray5[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);
	//=========================================
	fd = fopen("texture/400370wood.raw", "rb");
	for (iii = 0; iii < 400; iii++)
	{
		for (jjj = 0; jjj < 370; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray6[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);
	//============================
	fd = fopen("texture/400271wood.raw", "rb");
	for (iii = 0; iii < 400; iii++)
	{
		for (jjj = 0; jjj < 271; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray7[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);

	//============================
	fd = fopen("texture/400271wall.raw", "rb");
	for (iii = 0; iii < 400; iii++)
	{
		for (jjj = 0; jjj < 271; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray8[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);

	//============================
	fd = fopen("texture/320240car.raw", "rb");///*****
	for (iii = 0; iii < 320; iii++)
	{
		for (jjj = 0; jjj < 240; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray9[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);

	//============================
	fd = fopen("texture/320240tree.raw", "rb");
	for (iii = 0; iii < 320; iii++)
	{
		for (jjj = 0; jjj < 240; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray10[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);

	//============================
	fd = fopen("texture/400286wall.raw", "rb");
	for (iii = 0; iii < 400; iii++)
	{
		for (jjj = 0; jjj < 286; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray11[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);

	//============================
	fd = fopen("texture/400278wall.raw", "rb");
	for (iii = 0; iii < 400; iii++)
	{
		for (jjj = 0; jjj < 278; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray12[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);
	//============================
	fd = fopen("texture/400512floor.raw", "rb");
	for (iii = 0; iii < 400; iii++)
	{
		for (jjj = 0; jjj < 512; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray13[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);
	//============================
	fd = fopen("texture/320424floor.raw", "rb");
	for (iii = 0; iii < 320; iii++)
	{
		for (jjj = 0; jjj < 424; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray14[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);

	//============================
	fd = fopen("texture/340237floor.raw", "rb");
	for (iii = 0; iii < 340; iii++)
	{
		for (jjj = 0; jjj < 237; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray15[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);
	//=================================
	fd = fopen("texture/320240flower.raw", "rb");
	for (iii = 0; iii < 320; iii++)
	{
		for (jjj = 0; jjj < 240; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray16[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);
	//=================================
	fd = fopen("texture/100100pave.raw", "rb");
	for (iii = 0; iii < 100; iii++)
	{
		for (jjj = 0; jjj < 100; jjj++)
		{
			for (kkk = 0; kkk < 3; kkk++)
			{
				fread(&ch, 1, 1, fd);
				texarray17[iii][jjj][kkk] = (GLubyte)ch;
			}
		}
	}
	fclose(fd);


}


//=======================================================================
void print()
{
	printf("Lookx=%f	Looky=%f	 Lookz=%f\n", Lookx, Looky, Lookz);
	//printf("ei=%f		ej=%f		 ek=%f\n\n",ei,ej,ek);	

}
//==============================Floor Function============================
void Floor()
{
	glEnable(GL_TEXTURE_2D);
	if (Selectfloor == 0)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 328, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray);
	}
	else  if (Selectfloor == 1)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 512, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray13);
	}
	else  if (Selectfloor == 2)
	{

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 424, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray14);
	}
	else  if (Selectfloor == 3)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 340, 237, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray15);
	}
	glNormal3f(0, 1, 0);
	bi = 0;
	bj = 0;
	for (float pi = -400.0; pi<400.0; pi = pi + 8.0)
	{
		for (float pj = 400.0; pj>-400.0; pj = pj - 8.0)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(bi, bj);
			glVertex3f(pi, 0, pj);

			glTexCoord2f(bi, bj + 8.0 / 100.0);
			glVertex3f(pi + 8.0, 0, pj);

			glTexCoord2f(bi + 8.0 / 100.0, bj + 8.0 / 100.0);
			glVertex3f(pi + 8.0, 0, pj - 8.0);

			glTexCoord2f(bi + 8.0 / 100.0, bj);
			glVertex3f(pi, 0, pj - 8.0);

			glEnd();
			bi = bi + 8.0 / 100.0;
		}
		bj = bj + 8.0 / 100.0;
	}
	glDisable(GL_TEXTURE_2D);
}



//==============================Picture Function==========================
void pic()
{
	//================================================================================
	glNormal3f(1, 0, 0);
	glTranslated(-399, 100, 100);
	glEnable(GL_TEXTURE_2D);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 200, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray4);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 52, 42);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0, 52, 0);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0, -2, 0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, -2, 42);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0, 52, 0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 52, -42);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0, -2, -42);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0, -2, 0);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 240, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray2);
	bi = 0;
	bj = 0;

	for (float pi = 40; pi > -40; pi = pi - 2)
	{
		for (float pj = 50; pj > 0; pj = pj - 2)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(bi, bj);
			glVertex3f(1, pj, pi);
			glTexCoord2f(bi, bj + 1.0 / 25.0);
			glVertex3f(1, pj - 2, pi);
			glTexCoord2f(bi + 1.0 / 40.0, bj + 1.0 / 25.0);
			glVertex3f(1, pj - 2, pi - 2);
			glTexCoord2f(bi + 1.0 / 40.0, bj);
			glVertex3f(1, pj, pi - 2);
			glEnd();
			bj = bj + 1.0 / 25.0;
		}
		bi = bi + 1.0 / 40.0;
	}

	glTranslated(399, -100, -100);
	//================================================================================


	glTranslated(-399, 100, -150);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 200, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray4);

	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 52, 42);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0, 52, 0);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0, -2, 0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, -2, 42);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0, 52, 0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 52, -42);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0, -2, -42);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0, -2, 0);
	glEnd();
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 240, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray9);
	bi = 0;
	bj = 0;

	for (float pi = 40; pi > -40; pi = pi - 2)
	{
		for (float pj = 50; pj > 0; pj = pj - 2)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(bi, bj);
			glVertex3f(1, pj, pi);
			glTexCoord2f(bi, bj + 1.0 / 25.0);
			glVertex3f(1, pj - 2, pi);
			glTexCoord2f(bi + 1.0 / 40.0, bj + 1.0 / 25.0);
			glVertex3f(1, pj - 2, pi - 2);
			glTexCoord2f(bi + 1.0 / 40.0, bj);
			glVertex3f(1, pj, pi - 2);
			glEnd();
			bj = bj + 1.0 / 25.0;
		}
		bi = bi + 1.0 / 40.0;
	}

	glTranslated(399, -100, 150);
	//================================================================================

	glTranslated(-150, 100, -399);
	glRotatef(-90, 0, 1, 0);

	glNormal3b(0, 0, -1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 200, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray4);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 52, 42);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0, 52, 0);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0, -2, 0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, -2, 42);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0, 52, 0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 52, -42);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0, -2, -42);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0, -2, 0);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 240, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray10);
	bi = 0;
	bj = 0;
	for (float pi = 40; pi > -40; pi = pi - 2)
	{
		for (float pj = 50; pj > 0; pj = pj - 2)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(bi, bj);
			glVertex3f(1, pj, pi);
			glTexCoord2f(bi, bj + 1.0 / 25.0);
			glVertex3f(1, pj - 2, pi);
			glTexCoord2f(bi + 1.0 / 40.0, bj + 1.0 / 25.0);
			glVertex3f(1, pj - 2, pi - 2);
			glTexCoord2f(bi + 1.0 / 40.0, bj);
			glVertex3f(1, pj, pi - 2);
			glEnd();
			bj = bj + 1.0 / 25.0;
		}
		bi = bi + 1.0 / 40.0;
	}
	glRotatef(90, 0, 1, 0);
	glTranslated(150, -100, 399);
	//================================================================================

	glTranslated(100, 100, -399);
	glRotatef(-90, 0, 1, 0);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 200, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray4);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0, 52, 42);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0, 52, 0);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0, -2, 0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0, -2, 42);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.5, 0.0);
	glVertex3f(0, 52, 0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(0, 52, -42);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(0, -2, -42);
	glTexCoord2f(0.5, 1.0);
	glVertex3f(0, -2, 0);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 240, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray16);
	bi = 0;
	bj = 0;
	for (float pi = 40; pi > -40; pi = pi - 2)
	{
		for (float pj = 50; pj > 0; pj = pj - 2)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(bi, bj);
			glVertex3f(1, pj, pi);
			glTexCoord2f(bi, bj + 1.0 / 25.0);
			glVertex3f(1, pj - 2, pi);
			glTexCoord2f(bi + 1.0 / 40.0, bj + 1.0 / 25.0);
			glVertex3f(1, pj - 2, pi - 2);
			glTexCoord2f(bi + 1.0 / 40.0, bj);
			glVertex3f(1, pj, pi - 2);
			glEnd();
			bj = bj + 1.0 / 25.0;
		}
		bi = bi + 1.0 / 40.0;
	}
	glRotatef(90, 0, 1, 0);
	glTranslated(-100, -100, 399);
	//================================================================================

	glDisable(GL_TEXTURE_2D);

}


//==============================Chair Function============================

void chair()
{
	glEnable(GL_TEXTURE_2D);

	if (Selectchair == 0)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 370, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray6);

	}
	else  if (Selectchair == 1)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 199, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray3);
	}
	else  if (Selectchair == 2)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 200, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray4);
	}
	else  if (Selectchair == 3)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 271, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray7);
	}


	//glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,400,370,0,GL_RGB,GL_UNSIGNED_BYTE,texarray6);

	//surface chair
	glTranslatef(0, 30, 90);               //top
	glRotatef(-90, 1, 0, 0);
	GLUquadricObj* obj;
	obj = gluNewQuadric();
	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricNormals(obj, GLU_SMOOTH);
	gluCylinder(obj, 15, 15, 5, 30, 30);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -30, -90);


	glTranslatef(0, 35, 90);
	glRotatef(-90, 1, 0, 0);                   //side

	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricNormals(obj, GLU_SMOOTH);
	gluDisk(obj, 0, 15, 30, 30);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -35, -90);

	glTranslatef(0, 30, 90);                //down
	glRotatef(-90, 1, 0, 0);

	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricNormals(obj, GLU_SMOOTH);
	gluDisk(obj, 0, 15, 30, 30);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -30, -90);
	// end surface chair

	glTranslatef(0, 0, 100);
	glRotatef(-90, 1, 0, 0);

	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricNormals(obj, GLU_SMOOTH);
	gluCylinder(obj, 2, 2, 30, 30, 30);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -100);

	glTranslatef(-10, 0, 90);
	glRotatef(-90, 1, 0, 0);

	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricNormals(obj, GLU_SMOOTH);
	gluCylinder(obj, 2, 2, 30, 30, 30);
	glRotatef(90, 1, 0, 0);
	glTranslatef(10, 0, -90);

	glTranslatef(8, 0, 82);
	glRotatef(-90, 1, 0, 0);

	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricNormals(obj, GLU_SMOOTH);
	gluCylinder(obj, 2, 2, 30, 30, 30);
	glRotatef(90, 1, 0, 0);
	glTranslatef(-8, 0, -82);

	glDisable(GL_TEXTURE_2D);

}


//==============================Room Function=============================
void Room()
{
	if (Selectwall == 0)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 286, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray11);
	}
	else  if (Selectwall == 1)
	{

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 380, 527, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray5);
	}
	else  if (Selectwall == 2)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 271, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray8);
	}
	else  if (Selectwall == 3)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 278, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray12);
	}


	glEnable(GL_TEXTURE_2D);
	//================================================================
	//x=-400 fix
	glNormal3f(1, 0, 0);
	bi = 0;
	bj = 0;
	for (float pi = 400.0; pi > -400.0; pi = pi - 8.0)
	{
		for (float pj = 400.0; pj > 0.0; pj = pj - 4.0)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(bi, bj);
			glVertex3f(-400, pj, pi);

			glTexCoord2f(bi, bj + 5.0 / 100.0);
			glVertex3f(-400, pj - 4.0, pi);

			glTexCoord2f(bi + 5.0 / 100.0, bj + 5.0 / 100.0);
			glVertex3f(-400, pj - 4.0, pi - 8.0);

			glTexCoord2f(bi + 5.0 / 100.0, bj);
			glVertex3f(-400, pj, pi - 8.0);

			glEnd();
			bj = bj + 5.0 / 100.0;
		}
		bi = bi + 5.0 / 100.0;
	}

	//================================================================

	//z=-400 fix
	glNormal3f(0, 0, 1);
	bi = 0;
	bj = 0;
	for (float pi = -400.0; pi<400.0; pi = pi + 8.0)
	{
		for (float pj = 400.0; pj>0.0; pj = pj - 4.0)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(bi, bj);
			glVertex3f(pi, pj, -400);

			glTexCoord2f(bi, bj + 5.0 / 100.0);
			glVertex3f(pi, pj - 4.0, -400);

			glTexCoord2f(bi + 5.0 / 100.0, bj + 5.0 / 100.0);
			glVertex3f(pi + 8.0, pj - 4.0, -400);

			glTexCoord2f(bi + 5.0 / 100.0, bj);
			glVertex3f(pi + 8.0, pj, -400);

			glEnd();
			bj = bj + 5.0 / 100.0;
		}
		bi = bi + 5.0 / 100.0;
	}


	//============================================================

	glNormal3f(-1, 0, 0);
	//x=400 fix
	bi = 0;
	bj = 0;
	for (float pi = -400.0; pi<400.0; pi = pi + 8.0)
	{
		for (float pj = 400.0; pj>0.0; pj = pj - 4.0)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(bi, bj);
			glVertex3f(400, pj, pi);

			glTexCoord2f(bi, bj + 5.0 / 100.0);
			glVertex3f(400, pj - 4.0, pi);

			glTexCoord2f(bi + 5.0 / 100.0, bj + 5.0 / 100.0);
			glVertex3f(400, pj - 4.0, pi + 8.0);

			glTexCoord2f(bi + 5.0 / 100.0, bj);
			glVertex3f(400, pj, pi + 8.0);

			glEnd();
			bj = bj + 5.0 / 100.0;
		}
		bi = bi + 5.0 / 100.0;
	}

	//================================================================

	//z=400 fix
	glNormal3f(0, 0, -1);
	bi = 0;
	bj = 0;
	for (float pi = 400.0; pi > -400.0; pi = pi - 8.0)
	{
		for (float pj = 400.0; pj > 0.0; pj = pj - 4.0)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(bi, bj);
			glVertex3f(pi, pj, 400);

			glTexCoord2f(bi, bj + 5.0 / 100.0);
			glVertex3f(pi, pj - 4.0, 400);

			glTexCoord2f(bi + 5.0 / 100.0, bj + 5.0 / 100.0);
			glVertex3f(pi - 8.0, pj - 4.0, 400);

			glTexCoord2f(bi + 5.0 / 100.0, bj);
			glVertex3f(pi - 8.0, pj, 400);

			glEnd();
			bj = bj + 5.0 / 100.0;
		}
		bi = bi + 5.0 / 100.0;
	}


}
//==============================Table Function============================
void Table()
{

	if (Selecttable == 0)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 199, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray3);
	}
	else  if (Selecttable == 1)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 370, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray6);
	}
	else  if (Selecttable == 2)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 400, 271, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray7);
	}
	else  if (Selecttable == 3)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 320, 200, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray4);
	}
	glEnable(GL_TEXTURE_2D);
	//=========================================================================================
	bi = 0;										//top
	bj = 0;
	glNormal3f(0, 1, 0);
	for (float pi = -60; pi<60; pi = pi + 1)
	{
		for (float pj = 60; pj>-60; pj = pj - 1)
		{

			glBegin(GL_POLYGON);
			glTexCoord2f(bi, bj);
			glVertex3f(pi, 60, pj);

			glTexCoord2f(bi, bj + 2.0 / 120.0);
			glVertex3f(pi + 1, 60, pj);

			glTexCoord2f(bi + 2.0 / 120.0, bj + 2.0 / 120.0);
			glVertex3f(pi + 1, 60, pj - 1); 

			glTexCoord2f(bi + 2.0 / 120.0, bj);
			glVertex3f(pi, 60, pj - 1);
			glEnd();
			bi = bi + 2.0 / 120.0;
		}
		bj = bj + 2.0 / 120.0;
	}
	//=========================================================================================
	glTranslatef(0, -10, 0);					//down

	bi = 0;
	bj = 0;
	glNormal3f(0, -1, 0);
	for (float pi = -60; pi<60; pi = pi + 1)
	{
		for (float pj = 60; pj>-60; pj = pj - 1)
		{

			glBegin(GL_POLYGON);
			glTexCoord2f(bi, bj);
			glVertex3f(pi, 60, pj);

			glTexCoord2f(bi, bj + 2.0 / 120.0);
			glVertex3f(pi + 1, 60, pj);

			glTexCoord2f(bi + 2.0 / 120.0, bj + 2.0 / 120.0);
			glVertex3f(pi + 1, 60, pj - 1);

			glTexCoord2f(bi + 2.0 / 120.0, bj);
			glVertex3f(pi, 60, pj - 1);
			glEnd();
			bi = bi + 2.0 / 120.0;
		}
		bj = bj + 2.0 / 120.0;
	}

	glTranslatef(0, 10, 0);
	//=========================================================================================
	glTranslatef(50, 0, 50);							//PROP 
	glRotatef(-90, 1, 0, 0);
	GLUquadricObj* obj;
	obj = gluNewQuadric();
	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricNormals(obj, GLU_SMOOTH);

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
	//=========================================================================================
	glNormal3f(1, 0, 0);					//SIDE
	glBegin(GL_POLYGON);   //X=60 FIX
	glTexCoord2f(0.25, 0.0);
	glVertex3f(60, 50, -60);
	glTexCoord2f(0.5, 0.25);
	glVertex3f(60, 60, -60);
	glTexCoord2f(0.0, 0.25);
	glVertex3f(60, 60, 60);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(60, 50, 60);
	glEnd();

	glNormal3f(-1, 0, 0);
	glBegin(GL_POLYGON);   //X=-60 FIX
	glTexCoord2f(0.25, 0.0);
	glVertex3f(-60, 50, -60);
	glTexCoord2f(0.5, 0.25);
	glVertex3f(-60, 60, -60);
	glTexCoord2f(0.0, 0.25);
	glVertex3f(-60, 60, 60);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-60, 50, 60);
	glEnd();


	glNormal3f(0, 0, 1);
	glBegin(GL_POLYGON);   //Z=60 FIX
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-60, 50, 60);
	glTexCoord2f(0.0, 0.25);
	glVertex3f(-60, 60, 60);
	glTexCoord2f(0.25, 0.25);
	glVertex3f(60, 60, 60);
	glTexCoord2f(0.25, 0.0);
	glVertex3f(60, 50, 60);
	glEnd();

	glNormal3f(0, 0, -1);
	glBegin(GL_POLYGON);   //Z=-60 FIX
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-60, 50, -60);
	glTexCoord2f(0.0, 0.25);
	glVertex3f(-60, 60, -60);
	glTexCoord2f(0.25, 0.25);
	glVertex3f(60, 60, -60);
	glTexCoord2f(0.25, 0.0);
	glVertex3f(60, 50, -60);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}

//========================================================================
void Seleclight()
{
	if (SelectLight == 0)
	{
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, changeConstant);
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, changeCutoff);
	}
	else if (SelectLight == 1)
	{
		glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, changeConstant);
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, changeCutoff);
	}
	else if (SelectLight == 2)
	{
		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, changeConstant);
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, changeCutoff);
	}
	else if (SelectLight == 3)
	{
		glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, changeConstant);
		glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, changeCutoff);
	}

	else if (SelectLight == 4)
	{
		glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, changeConstant);
		glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, changeCutoff);
	}

	else if (SelectLight == 5)
	{
		glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, changeConstant);
		glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, changeCutoff);
		glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, changeConstant);
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, changeCutoff);
		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, changeConstant);
		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, changeCutoff);
		glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, changeConstant);
		glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, changeCutoff);
	}
}
//*****************************************************************************************
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(Lookx, Looky, Lookz, ei, ej, ek, 0, 5, 0);
	glEnable(GL_TEXTURE_2D);
	print();

	//#########################################################################################
	Seleclight();
	GLfloat  spot_direction4[4];
	GLfloat  light_position4[] = { L4positionx, L4positiony, L4positionz, 1.0 };
	if (DirectionLight == 0)
	{
		spot_direction4[0] = -L4positionx;
		spot_direction4[1] = -L4positiony + 60;
		spot_direction4[2] = -L4positionz;
		spot_direction4[3] = 1.0;

	}
	else if (DirectionLight == 1)
	{
		spot_direction4[0] = 1;
		spot_direction4[1] = 0;
		spot_direction4[2] = 0;
		spot_direction4[3] = 1.0;
	}
	else if (DirectionLight == 2)
	{
		spot_direction4[0] = -1;
		spot_direction4[1] = 0;
		spot_direction4[2] = 0;
		spot_direction4[3] = 1.0;
	}
	else if (DirectionLight == 3)
	{
		spot_direction4[0] = 0;
		spot_direction4[1] = 1;
		spot_direction4[2] = 0;
		spot_direction4[3] = 1.0;
	}
	else if (DirectionLight == 4)
	{

		spot_direction4[0] = 0;
		spot_direction4[1] = -1;
		spot_direction4[2] = 0;
		spot_direction4[3] = 1.0;
	}
	else if (DirectionLight == 5)
	{
		spot_direction4[0] = 0;
		spot_direction4[1] = 0;
		spot_direction4[2] = 1;
		spot_direction4[3] = 1.0;
	}
	else if (DirectionLight == 6)
	{
		spot_direction4[0] = 0;
		spot_direction4[1] = 0;
		spot_direction4[2] = -1.0;
		spot_direction4[3] = 1.0;;
	}

	glLightfv(GL_LIGHT4, GL_POSITION, light_position4);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_direction4);
	//************************************************************************  
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT3, GL_POSITION, light_position3);

	//************************************************************************
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction);
	//************************************************************************

	glTranslatef(-400, 160.5, -150);
	glutSolidSphere(5, 20, 20);
	glTranslatef(400, -160.5, 150);

	glTranslatef(-400, 160.5, 100);
	glutSolidSphere(5, 20, 20);
	glTranslatef(400, -160.5, -100);

	glTranslatef(-150, 160.5, -400);
	glutSolidSphere(5, 20, 20);
	glTranslatef(150, -160.5, 400);

	glTranslatef(100, 160.5, -400);
	glutSolidSphere(5, 20, 20);
	glTranslatef(-100, -160.5, 400);

	glTranslatef(L4positionx, L4positiony, L4positionz);
	glutSolidSphere(5, 20, 20);
	glTranslatef(-L4positionx, -L4positiony, -L4positionz);
	//************************************************************************

	GLfloat  global_ambient[] = { changeGlobalAmbient, changeGlobalAmbient, changeGlobalAmbient };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
	//************************************************************************
	print();

	Floor();
	Room();
	Table();
	chair();
	pic();
	glTranslated(90, 0, -90);
	chair();
	glTranslated(-90, 0, 90);

	glTranslatef(0, 65, 0);
	GLUquadricObj* obj;
	obj = gluNewQuadric();
	gluQuadricTexture(obj, GLU_TRUE);
	gluQuadricNormals(obj, GLU_SMOOTH);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 100, 100, 0, GL_RGB, GL_UNSIGNED_BYTE, texarray17);
	glEnable(GL_TEXTURE_2D);
	if (f == 0)	{ glutSolidTeapot(7); }
	if (f == 1)	{ gluSphere(obj, 7, 30, 30); }
	if (f == 2)	{ glTranslatef(0, 10, 0);  glRotatef(90, 1, 0, 0);    gluCylinder(obj, 6, 3, 10, 30, 30); glTranslatef(0, -10, 0);    glRotatef(-90, 1, 0, 0); }
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void Init()
{
	makeTexture();
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//===================================================================================

	GLfloat  mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat  mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat  mat_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat  mat_shininess = { 100.0 };

	GLfloat  light_position[] = { 100, 100, 100, 1.0 };
	GLfloat  light_ambient[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat  light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat  light_specular[] = { 1.0, 1.0, 1.0, 1.0 };

	GLfloat  global_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
	GLfloat  spot_direction[] = { 0, -1, 0 };

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	//===================================================================================
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.015);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 90.0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 4.0);

	glEnable(GL_LIGHT0);
	//===================================================================================
	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.015);
	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.0);

	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);

	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 90.0);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 4.0);

	glEnable(GL_LIGHT1);

	//===================================================================================
	glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.015);
	glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.0);


	glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);

	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 90.0);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 4.0);

	glEnable(GL_LIGHT2);

	//===================================================================================
	glLightf(GL_LIGHT3, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT3, GL_LINEAR_ATTENUATION, 0.015);
	glLightf(GL_LIGHT3, GL_QUADRATIC_ATTENUATION, 0.0);


	glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);

	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 90.0);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 4.0);


	glEnable(GL_LIGHT3);

	//===================================================================================
	glLightf(GL_LIGHT4, GL_CONSTANT_ATTENUATION, 1.0);
	glLightf(GL_LIGHT4, GL_LINEAR_ATTENUATION, 0.015);
	glLightf(GL_LIGHT4, GL_QUADRATIC_ATTENUATION, 0.0);

	glLightfv(GL_LIGHT4, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT4, GL_SPECULAR, light_specular);

	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 90.0);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_direction);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 3.0);
	glEnable(GL_LIGHT4);

	//===================================================================================
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(40, (4.0 / 3.0), 1, -1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);

}




//####################################### keyboard and mouse #################################

void mykey1(unsigned char key, int x, int y)
{

	if (key == 'q' || key == 'Q') { if (Lookx > -390) { Lookx = Lookx - 5;  if (SelectCamera == 0) { ei = ei - 5; } else ei = 0; } glutPostRedisplay(); }
	if (key == 'e' || key == 'E') { if (Lookx < 390)  { Lookx = Lookx + 5;  if (SelectCamera == 0) { ei = ei + 5; } else ei = 0; } glutPostRedisplay(); }
	if (key == 'a' || key == 'A') { if (Lookz < 390)  { Lookz = Lookz + 5;  if (SelectCamera == 0) { ek = ek + 5; } else ek = 0; } glutPostRedisplay(); }
	if (key == 'd' || key == 'D') { if (Lookz > -390) { Lookz = Lookz - 5;  if (SelectCamera == 0) { ek = ek - 5; } else ek = 0; } glutPostRedisplay(); }
	if (key == 's' || key == 'S') { if (Looky > 5)    { Looky = Looky - 5;  if (SelectCamera == 0) { ej = ej - 5; } else ej = 65; } glutPostRedisplay(); }
	if (key == 'w' || key == 'W') { if (Looky < 390)  { Looky = Looky + 5;  if (SelectCamera == 0) { ej = ej + 5; } else ej = 65; } glutPostRedisplay(); }

	if (key == 'y' || key == 'Y') { if (L4positiony > 390)    L4positiony = 390;     L4positiony = L4positiony + 4;    glutPostRedisplay(); }
	if (key == 'h' || key == 'H') { if (L4positiony < 5)     L4positiony = 5;       L4positiony = L4positiony - 4;    glutPostRedisplay(); }
	if (key == 'g' || key == 'G') { if (L4positionx < -390)  L4positionx = 5;       L4positionx = L4positionx - 4;    glutPostRedisplay(); }
	if (key == 'j' || key == 'J') { if (L4positionx > 390)   L4positionx = 390;     L4positionx = L4positionx + 4;    glutPostRedisplay(); }
	if (key == 'u' || key == 'U') { if (L4positionz < -390)  L4positionz = 5;       L4positionz = L4positionz - 4;    glutPostRedisplay(); }
	if (key == 't' || key == 'T') { if (L4positionz > 390)   L4positionz = 390;     L4positionz = L4positionz + 4;    glutPostRedisplay(); }
	if (key == 'm' || key == 'M') { if (changeCutoff >= 90)   changeCutoff = 90;	   changeCutoff = changeCutoff + 3;  glutPostRedisplay(); }
	if (key == 'n' || key == 'N') { if (changeCutoff <= 0)    changeCutoff = 0;      changeCutoff = changeCutoff - 3;  glutPostRedisplay(); }
	if (key == '{' || key == '[') { if (changeConstant >= 40) changeConstant = 40;   changeConstant = changeConstant + 1;     glutPostRedisplay(); }
	if (key == '}' || key == ']') { if (changeConstant <= 0)  changeConstant = 0;    changeConstant = changeConstant - 1;     glutPostRedisplay(); }
	if (key == '?' || key == '/') { if (changeGlobalAmbient >= 1)    changeGlobalAmbient = 1;   changeGlobalAmbient = changeGlobalAmbient + 0.05;  glutPostRedisplay(); }
	if (key == '.' || key == '>') { if (changeGlobalAmbient <= 0)    changeGlobalAmbient = 0;   changeGlobalAmbient = changeGlobalAmbient - 0.05;  glutPostRedisplay(); }
	if (key == 'r' || key == 'R') { Lookx = -Lookx;     Looky = Looky;  Lookz = -Lookz; ei = -ei; ej = ej; ek = -ek; glutPostRedisplay(); }

}

//*********************Special Keys************************






//###################################### START  MENU  #########################################

void main_menu(int value)
{
	if (value == 1)
	{
		Lookx = 160;
		Looky = 180;
		Lookz = 100;
		ei = 0;
		ej = 70;
		ek = 0;
		changeCutoff = changeSpotExponent = changeConstant = 0;
		glutPostRedisplay();
	}
	if (value == 17) { exit(0); }
}
//**************************************
void mid1_menu(int value)
{
	if (value == 14) { f = 0;   glutPostRedisplay(); }
	if (value == 15) { f = 1;   glutPostRedisplay(); }
	if (value == 16) { f = 2;   glutPostRedisplay(); }
}

//*************************************

void mid2_menu(int value)
{
	if (value == 4)   { Lookx = 400;  Looky = 400;  Lookz = 400; ei = ej = ek = 0; glutPostRedisplay(); }
	if (value == 5)   { Lookx = 10;   Looky = 300;  Lookz = 10;  ei = ej = ek = 0; glutPostRedisplay(); }
	if (value == 6)   { Lookx = 300;  Looky = 80;   Lookz = 0;   ei = ej = ek = 0; glutPostRedisplay(); }
	if (value == 7)   { Lookx = 0;    Looky = 80;   Lookz = 300; ei = ej = ek = 0; glutPostRedisplay(); }
	if (value == 33)  { Lookx = -60;  Looky = 176;  Lookz = 100;  ei = -360;  ej = 96; ek = 100;   glutPostRedisplay(); }
	if (value == 34)  { Lookx = -60;  Looky = 176;  Lookz = -150; ei = -360;  ej = 96; ek = -150;  glutPostRedisplay(); }
	if (value == 35)  { Lookx = -150; Looky = 176;  Lookz = -60;  ei = 100;   ej = 96; ek = -360;  glutPostRedisplay(); }
	if (value == 36)  { Lookx = 100;  Looky = 176;  Lookz = -60;  ei = -150;  ej = 96; ek = -360;  glutPostRedisplay(); }

}

//*************************************
void mid3_menu(int value)
{

	if (value == 10)
	{
		Selectwall = 0;
		glutPostRedisplay();
	}
	if (value == 11)
	{
		Selectwall = 1;
		glutPostRedisplay();
	}
	if (value == 12)
	{
		Selectwall = 2;
		glutPostRedisplay();
	}
	if (value == 17)
	{
		Selectwall = 3;
		glutPostRedisplay();
	}
}
//*************************************
void mid4_menu(int value)
{
	if (value == 0)
	{
		Selecttable = 0;
		glutPostRedisplay();
	}

	if (value == 2)
	{

		Selecttable = 1;
		glutPostRedisplay();
	}

	if (value == 3)
	{

		Selecttable = 2;
		glutPostRedisplay();
	}

	if (value == 26)
	{
		Selecttable = 3;
		glutPostRedisplay();
	}
}

//*************************************
void mid5_menu(int value)
{
	if (value == 18)
	{
		Selectfloor = 0;
		glutPostRedisplay();
	}
	if (value == 19)
	{
		Selectfloor = 1;
		glutPostRedisplay();
	}
	if (value == 20)
	{
		Selectfloor = 2;
		glutPostRedisplay();
	}
	if (value == 21)
	{
		Selectfloor = 3;
		glutPostRedisplay();
	}
}

//*************************************
void mid6_menu(int value)
{
	if (value == 22)
	{
		Selectchair = 0;
		glutPostRedisplay();
	}

	if (value == 23)
	{

		Selectchair = 1;
		glutPostRedisplay();
	}

	if (value == 24)
	{

		Selectchair = 2;
		glutPostRedisplay();
	}

	if (value == 25)
	{
		Selectchair = 3;
		glutPostRedisplay();
	}
}



void mid7_menu(int value)
{
	if (value == 27)
	{
		SelectLight = 0;
		glutPostRedisplay();
	}

	if (value == 28)
	{

		SelectLight = 1;
		glutPostRedisplay();
	}

	if (value == 29)
	{

		SelectLight = 2;
		glutPostRedisplay();
	}

	if (value == 30)
	{
		SelectLight = 3;
		glutPostRedisplay();
	}
	if (value == 31)
	{
		SelectLight = 4;
		glutPostRedisplay();
	}
	if (value == 32)
	{
		SelectLight = 5;
		glutPostRedisplay();
	}
}


void mid8_menu(int value)
{
	if (value == 33)
	{
		SelectCamera = 0;
		Lookx = 160;      //Place that we stand
		Looky = 180;
		Lookz = 100;
		ei = 0;           //Place that we see
		ej = 70;
		ek = 0;
		glutPostRedisplay();
	}

	if (value == 38)
	{
		SelectCamera = 1;
		Lookx = 160;      //Place that we stand
		Looky = 180;
		Lookz = 100;
		ei = 0;           //Place that we see
		ej = 70;
		ek = 0;;
		glutPostRedisplay();
	}

}


void mid9_menu(int value)
{
	if (value == 39)
	{
		DirectionLight = 0;
		glutPostRedisplay();

	}

	if (value == 40)
	{
		DirectionLight = 1;
		glutPostRedisplay();

	}
	if (value == 41)
	{
		DirectionLight = 2;
		glutPostRedisplay();

	}

	if (value == 42)
	{
		DirectionLight = 3;
		glutPostRedisplay();

	}
	if (value == 43)
	{
		DirectionLight = 4;
		glutPostRedisplay();

	}

	if (value == 44)
	{
		DirectionLight = 5;
		glutPostRedisplay();

	}
	if (value == 45)
	{
		DirectionLight = 6;
		glutPostRedisplay();

	}

}




//###################################### END  MENU  ########################################


int main(int argc, char ** argv)
{

	glutInit(&argc, argv);
	int sub_m1, sub_m2, sub_m3, sub_m4, sub_m5, sub_m6, sub_m7, sub_m8, sub_m9;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(wwin, hwin);
	glutInitWindowPosition(0, 0);
	mainw = glutCreateWindow("Graphic Project");
	Init();
	glutDisplayFunc(Display);

	glutKeyboardFunc(mykey1);

	sub_m1 = glutCreateMenu(mid1_menu);
	glutAddMenuEntry("Teapot", 14);
	glutAddMenuEntry("Sphere", 15);
	glutAddMenuEntry("Cylinder", 16);


	sub_m2 = glutCreateMenu(mid2_menu);
	glutAddMenuEntry("Corner", 4);
	glutAddMenuEntry("Top", 5);
	glutAddMenuEntry("X", 6);
	glutAddMenuEntry("Z", 7);
	glutAddMenuEntry("Picture 1", 33);
	glutAddMenuEntry("Picture 2", 34);
	glutAddMenuEntry("Picture 3", 35);
	glutAddMenuEntry("Picture 4", 36);


	sub_m3 = glutCreateMenu(mid3_menu);
	glutAddMenuEntry("Model 1", 10);
	glutAddMenuEntry("Model 2", 11);
	glutAddMenuEntry("Model 3", 12);
	glutAddMenuEntry("Model 4", 17);

	sub_m4 = glutCreateMenu(mid4_menu);
	glutAddMenuEntry("Model 1", 0);
	glutAddMenuEntry("Model 2", 2);
	glutAddMenuEntry("Model 3", 3);
	glutAddMenuEntry("Model 4", 26);

	sub_m5 = glutCreateMenu(mid5_menu);
	glutAddMenuEntry("Model 1", 18);
	glutAddMenuEntry("Model 2", 19);
	glutAddMenuEntry("Model 3", 20);
	glutAddMenuEntry("Model 4", 21);


	sub_m6 = glutCreateMenu(mid6_menu);
	glutAddMenuEntry("Model 1", 22);
	glutAddMenuEntry("Model 2", 23);
	glutAddMenuEntry("Model 3", 24);
	glutAddMenuEntry("Model 4", 25);

	sub_m7 = glutCreateMenu(mid7_menu);
	glutAddMenuEntry("Light 0", 27);
	glutAddMenuEntry("Light 1", 28);
	glutAddMenuEntry("Light 2", 29);
	glutAddMenuEntry("Light 3", 30);
	glutAddMenuEntry("Light 4", 31);
	glutAddMenuEntry("All (0-1-2-3)", 32);

	sub_m8 = glutCreateMenu(mid8_menu);
	glutAddMenuEntry("Track", 37);
	glutAddMenuEntry("Orbit -> Center=object", 38);

	sub_m9 = glutCreateMenu(mid9_menu);
	glutAddMenuEntry("Object", 39);
	glutAddMenuEntry("( 1, 0, 0)", 40);
	glutAddMenuEntry("(-1, 0, 0)", 41);
	glutAddMenuEntry("( 0, 1, 0)", 42);
	glutAddMenuEntry("( 0,-1, 0)", 43);
	glutAddMenuEntry("( 0, 0, 1)", 44);
	glutAddMenuEntry("( 0, 0,-1)", 45);


	glutCreateMenu(main_menu);

	glutAddMenuEntry("Reset", 1);
	glutAddSubMenu("Camera", sub_m8);
	glutAddSubMenu("Change object", sub_m1);
	glutAddSubMenu("Change Position", sub_m2);
	glutAddSubMenu("Change floor", sub_m5);
	glutAddSubMenu("Change wall", sub_m3);
	glutAddSubMenu("Change Table", sub_m4);
	glutAddSubMenu("Change Chair", sub_m6);
	glutAddSubMenu("Change Light", sub_m7);
	glutAddSubMenu("Direction Light", sub_m9);
	glutAddMenuEntry("Exit", 17);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();

	return 0;

}



