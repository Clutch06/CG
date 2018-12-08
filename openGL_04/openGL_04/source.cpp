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
	// 윈도우 초기화 및 생성
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1680, 1020);
	glutCreateWindow("openGL");

	// 필요한 콜백함수 설정
	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);

	// 이벤트 루프 실행
	glutMainLoop();
}

GLvoid DrawScene()
{
	// 윈도우, 깊이 버퍼 클리어
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRotatef(30.0, 1.0, 0.0, 0.0);
	glRotatef(45.0, 0.0, 1.0, 0.0);

	floor();	// 바닥 그리기

	glRotatef(rotateX, 1.0, 0.0, 0.0);	// X축 회전
	glRotatef(rotateY, 0.0, 1.0, 0.0);	// Y축 회전

	glTranslatef(translateX, 0.0, 0.0);	// X축 이동
	glTranslatef(0.0, 0.0, translateZ); // Y축 이동

	cube();	// 직육면체 그리기

	// 결과 출력
	glutSwapBuffers();
}

GLvoid Reshape(int w, int h)
{
	//--- 뷰포트 변환 설정
	glViewport(0, 0, w, h);

	// 투영 행렬 스택 재설정 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(60.0f, w / h, 1.0, 1200.0);	// 원근 투영
	glTranslatef(0.0, 0.0, -700.0);     // 투영 공간을 화면 안쪽으로 이동하여 시야를 확보한다.
	//glOrtho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);

	// 모델 뷰 행렬 스택 재설정 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// 관측 변환: 카메라의 위치 설정 (필요한 경우, 다른 곳에 설정 가능) 
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

	// 화면 재출력을 위하여 디스플레이 콜백 함수 호출
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

	// 바닥
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

	// 뚜껑
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