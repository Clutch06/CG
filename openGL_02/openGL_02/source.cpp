#include <gl/freeglut.h>

GLvoid DrawScene(GLvoid);
GLvoid Reshape(int w, int h);

void Keyboard(unsigned char key, int x, int y);

int status = 0;

void main(int argc, char** argv)
{
	// ������ �ʱ�ȭ �� ����
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1000, 1000);
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
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	if (status == 0) {
		glShadeModel(GL_SMOOTH);
	}

	if (status == 1) {
		glShadeModel(GL_FLAT);
	}

	glBegin(GL_QUADS);
		glColor3f(1.0f, 1.0f, 0.0f); // Yellow 
		glVertex3f(100.0, 100.0, 0.0);
		glColor3f(0.0f, 0.0f, 1.0f); // Blue 
		glVertex3f(100.0, -100.0, 0.0);
		glColor3f(0.0f, 1.0f, 1.0f); // Cyan 
		glVertex3f(-100.0, -100.0, 0.0);
		glColor3f(1.0f, 0.0, 1.0f); // Magenta 
		glVertex3f(-100.0, 100.0, 0.0);
	glEnd();

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

	gluPerspective(60.0f, w / h, 1.0, 1000.0);
	glTranslatef(0.0, 0.0, -300.0);     // ���� ������ ȭ�� �������� �̵��Ͽ� �þ߸� Ȯ���Ѵ�.

	// �� �� ��� ���� �缳�� 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// ���� ��ȯ: ī�޶��� ��ġ ���� (�ʿ��� ���, �ٸ� ���� ���� ����) 
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	if (key == 'a') {
		status = 0;
	}

	if (key == 's') {
		status = 1;
	}

	// ȭ�� ������� ���Ͽ� ���÷��� �ݹ� �Լ� ȣ��
	glutPostRedisplay();
}