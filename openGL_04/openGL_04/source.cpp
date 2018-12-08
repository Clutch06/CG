#include <gl/freeglut.h>
#define MAX 19

GLvoid DrawScene(GLvoid);
GLvoid Reshape(int w, int h);

void Keyboard(unsigned char key, int x, int y);

GLfloat rotateX = 0;
GLfloat rotateY = 0;
GLfloat rotateZ = 0;

GLfloat translateX = 0;
GLfloat translateZ = 0;

void floor();
void cube();

void main(int argc, char** argv)
{
	// ������ �ʱ�ȭ �� ����
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1680, 1020);
	glutCreateWindow("openGL");

	// �ʿ��� �ݹ��Լ� ����
	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);

	// �̺�Ʈ ���� ����
	glutMainLoop();
}

GLvoid DrawScene()
{
	// ������, ���� ���� Ŭ����
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(30.0, 1.0, 0.0, 0.0);
	glRotatef(45.0, 0.0, 1.0, 0.0);

	floor();	// �ٴ� �׸���

	glRotatef(rotateX, 1.0, 0.0, 0.0);	// X�� ȸ��
	glRotatef(rotateY, 0.0, 1.0, 0.0);	// Y�� ȸ��

	glTranslatef(translateX, 0.0, 0.0);	// X�� �̵�
	glTranslatef(0.0, 0.0, translateZ); // Y�� �̵�

	cube();	// ������ü �׸���

	// ��� ���
	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	//--- ����Ʈ ��ȯ ����
	glViewport(0, 0, w, h);

	// ���� ��� ���� �缳�� 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0f, w / h, 1.0, 1200.0);	// ���� ����
	glTranslatef(0.0, 0.0, -700.0);     // ���� ������ ȭ�� �������� �̵��Ͽ� �þ߸� Ȯ���Ѵ�.
	//glOrtho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);

	// �� �� ��� ���� �缳�� 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// ���� ��ȯ: ī�޶��� ��ġ ���� (�ʿ��� ���, �ٸ� ���� ���� ����) 
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd') 
	{
		rotateY += 10.0;
		if (rotateY == 360)
			rotateY = 0.0;
	}

	if (key == 'a')
	{
		rotateY -= 10.0;
		if (rotateY == -360.0)
			rotateY = 0.0;
	}

	if (key == 'w') 
	{
		rotateX -= 10.0;
		if (rotateX == -360.0) 
			rotateX = 0.0;
	}

	if (key == 's') 
	{
		rotateX += 10.0;
		if (rotateX == 360.0) 
			rotateX = 0.0;
	}

	if (key == 'x')
	{
		translateX -= 10.0;
	}

	if (key =='X')
	{
		translateX += 10.0;
	}

	if (key == 'z')
	{
		translateZ += 10.0;
	}

	if (key == 'Z')
	{
		translateZ -= 10.0;
	}

	// ȭ�� ������� ���Ͽ� ���÷��� �ݹ� �Լ� ȣ��
	glutPostRedisplay();
}

void floor()
{
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_QUADS);
		glVertex3f(-250.0, -50.0, -250.0);
		glVertex3f(250.0, -50.0, -250.0);
		glVertex3f(250.0, -50.0, 250.0);
		glVertex3f(-250.0, -50.0, 250.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
		glVertex3f(-250.0, -50.0, 0.0);
		glVertex3f(250.0, -50.0, 0.0);
		glVertex3f(0.0, -50.0, -250.0);
		glVertex3f(0.0, -50.0, 250.0);
	glEnd();
}

void cube()
{
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CW);
	glShadeModel(GL_SMOOTH);

	// �ٴ�
	glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0, 0.0f);		// Red
		glVertex3f(-50.0, -50.0, -50.0);
		glColor3f(0.0f, 0.0f, 0.0f);	// Black
		glVertex3f(50.0, -50.0, -50.0);
		glColor3f(0.0f, 0.0f, 1.0f);	// Blue
		glVertex3f(50.0, -50.0, 50.0);
		glColor3f(1.0f, 0.0f, 1.0f);	// Magenta
		glVertex3f(-50.0, -50.0, 50.0);
	glEnd();

	// �Ѳ�
	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);	// Yello
		glVertex3f(-50.0, 50.0, -50.0);
		glColor3f(0.0f, 1.0f, 0.0f);	// Green
		glVertex3f(50.0, 50.0, -50.0);
		glColor3f(0.0f, 1.0f, 1.0f);	// Cyan
		glVertex3f(50.0, 50.0, 50.0);
		glColor3f(1.0f, 1.0f, 1.0f);	// White
		glVertex3f(-50.0, 50.0, 50.0);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f);	// Yello
		glVertex3f(-50.0, 50.0, -50.0);
		glColor3f(1.0f, 1.0f, 1.0f);	// White
		glVertex3f(-50.0, 50.0, 50.0);
		glColor3f(1.0f, 0.0f, 1.0f);	// Magenta
		glVertex3f(-50.0, -50.0, 50.0);
		glColor3f(1.0f, 0.0, 0.0f);		// Red
		glVertex3f(-50.0, -50.0, -50.0);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 1.0f);	// White
		glVertex3f(-50.0, 50.0, 50.0);
		glColor3f(0.0f, 1.0f, 1.0f);	// Cyan
		glVertex3f(50.0, 50.0, 50.0);
		glColor3f(0.0f, 0.0f, 1.0f);	// Blue
		glVertex3f(50.0, -50.0, 50.0);
		glColor3f(1.0f, 0.0f, 1.0f);	// Magenta
		glVertex3f(-50.0, -50.0, 50.0);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 1.0f);	// Cyan
		glVertex3f(50.0, 50.0, 50.0);
		glColor3f(0.0f, 1.0f, 0.0f);	// Green
		glVertex3f(50.0, 50.0, -50.0);
		glColor3f(0.0f, 0.0f, 0.0f);	// Black
		glVertex3f(50.0, -50.0, -50.0);
		glColor3f(0.0f, 0.0f, 1.0f);	// Blue
		glVertex3f(50.0, -50.0, 50.0);
	glEnd();

	glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);	// Green
		glVertex3f(50.0, 50.0, -50.0);
		glColor3f(1.0f, 1.0f, 0.0f);	// Yello
		glVertex3f(-50.0, 50.0, -50.0);
		glColor3f(1.0f, 0.0, 0.0f);		// Red
		glVertex3f(-50.0, -50.0, -50.0);
		glColor3f(0.0f, 0.0f, 0.0f);	// Black
		glVertex3f(50.0, -50.0, -50.0);
	glEnd();

	glDisable(GL_CULL_FACE);
}