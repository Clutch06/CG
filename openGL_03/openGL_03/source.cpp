#include <gl/freeglut.h>
#define MAX 19

GLvoid DrawScene(GLvoid);
GLvoid Reshape(int w, int h);

void Keyboard(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);

int vertex_coordinate[MAX][2];
int vertex_num = 0;

void main(int argc, char** argv)
{
	// ������ �ʱ�ȭ �� ����
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("openGL");

	// �ʿ��� �ݹ��Լ� ����
	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);

	// �̺�Ʈ ���� ����
	glutMainLoop();
}

GLvoid DrawScene()
{
	// ������, ���� ���� Ŭ����
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// x, y ��ǥ��
	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(0.0, 300.0);
		glVertex2f(800.0, 300.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(400.0, 0.0);
		glVertex2f(400.0, 600.0);
	glEnd();

	// ������


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

	//gluPerspective(60.0f, w / h, 1.0, 1000.0);	// ���� ����
	//glTranslatef(0.0, 0.0, -300.0);     // ���� ������ ȭ�� �������� �̵��Ͽ� �þ߸� Ȯ���Ѵ�.
	glOrtho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);

	// �� �� ��� ���� �缳�� 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// ���� ��ȯ: ī�޶��� ��ġ ���� (�ʿ��� ���, �ٸ� ���� ���� ����) 
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	if (key == 'r') {
		
	}

	// ȭ�� ������� ���Ͽ� ���÷��� �ݹ� �Լ� ȣ��
	glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		vertex_coordinate[vertex_num][0] = x;
		vertex_coordinate[vertex_num][1] = y;
		vertex_num = (vertex_num + 1) % 19;
	}
}