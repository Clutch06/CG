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
	// 윈도우 초기화 및 생성
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("openGL");

	// 필요한 콜백함수 설정
	glutDisplayFunc(DrawScene);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(Mouse);

	// 이벤트 루프 실행
	glutMainLoop();
}

GLvoid DrawScene()
{
	// 윈도우, 깊이 버퍼 클리어
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// x, y 좌표계
	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(0.0, 300.0);
		glVertex2f(800.0, 300.0);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(400.0, 0.0);
		glVertex2f(400.0, 600.0);
	glEnd();

	// 제어점


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

	//gluPerspective(60.0f, w / h, 1.0, 1000.0);	// 원근 투영
	//glTranslatef(0.0, 0.0, -300.0);     // 투영 공간을 화면 안쪽으로 이동하여 시야를 확보한다.
	glOrtho(0.0, 800.0, 0.0, 600.0, -1.0, 1.0);

	// 모델 뷰 행렬 스택 재설정 
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// 관측 변환: 카메라의 위치 설정 (필요한 경우, 다른 곳에 설정 가능) 
	gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0);
}

void Keyboard(unsigned char key, int x, int y)
{
	if (key == 'r') {
		
	}

	// 화면 재출력을 위하여 디스플레이 콜백 함수 호출
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