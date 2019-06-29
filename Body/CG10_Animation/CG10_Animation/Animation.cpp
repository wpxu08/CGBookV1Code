#include <gl/glut.h>

float fEarth = 2.0f; //������̫������ת�Ƕ�

float fMoon = 24.0f; //�����Ƶ������ת�Ƕ�

void Init()

{

	glEnable(GL_DEPTH_TEST); //������Ȳ���

	glClearColor(0.0f, 0.0f, 0.0f, 0.8f); //����Ϊ��ɫ

}

void Reshape(int w, int h)

{

	if (0 == h)

		h = 1;

	glViewport(0, 0, w, h); //���������ߴ�

	glMatrixMode(GL_PROJECTION); //ָ����ǰ����ͶӰ�����ջ

	glLoadIdentity(); //����ͶӰ����

	//ָ��͸��ͶӰ�Ĺ۲�ռ�

	gluPerspective(45.0f, (float)w / (float)h, 1.0f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();

}

void Display(void)

{

	//�����ɫ����Ȼ�����

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //ָ����ǰ����ģ����ͼ�����ջ

	glLoadIdentity(); //����ģ����ͼ����

	glTranslatef(0.0f, 0.0f, -500.0f); //��ͼ����z�Ḻ���ƶ�

	glColor3f(1.0f, 0.0f, 0.0f); //��̫��

	glutSolidSphere(50.0f, 20, 20);

	glColor3f(0.0f, 0.0f, 1.0f);

	glRotatef(23.27,0.0,0.0,1.0); //������̫���ĻƳཻ��

	glRotatef(fEarth, 0.0f, 1.0f, 0.0f);

	glTranslatef(200.0f, 0.0f, 0.0f);

	glutSolidSphere(20.0f, 20, 20); //������

	glPopMatrix();

	glPopMatrix();

	glRotatef(6.0f, 1.0f, 1.0f, 1.0f);

	glRotatef(fMoon, 0.0f, 1.0f, 0.0f);

	glColor3f(1.0f, 1.0f, 0.0f);

	glTranslatef(30.0f, 0.0f, 0.0f);

	glutSolidSphere(5.0f, 20, 20); //������

	glLoadIdentity();

	glFlush();

	glutSwapBuffers();

}

void myIdle(void) //�ڿ���ʱ���ã��ﵽ����Ч��

{

	fEarth += 0.03f; //������ת��������������Ч��

	if (fEarth > 360.0f)

		fEarth = 2.0f;

	fMoon += 0.24f;

	if (fMoon > 360.0f)

		fMoon = 24.0f;

	Display();

}

int main(int argc, char *argv[])

{

	glutInit(&argc, argv);

	//����ʹ��RGB��ɫ��˫�������Ȼ���

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100,100);

	glutInitWindowSize(600, 400);

	glutCreateWindow("̫��ϵ����");

	glutReshapeFunc(Reshape);

	glutDisplayFunc(Display);

	glutIdleFunc(&myIdle);

	Init();

	glutMainLoop();

	return 0;

}