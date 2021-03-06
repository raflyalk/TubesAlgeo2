#if defined(_WIN32)
#include <iostream>
#include <stdio.h>
#include <GL\glut.h>
#include <GL\GL.h>
#include <GL\GLU.h>

#elif defined(__APPLE__)
#include <iostream>
#include <stdio.h>
#include <GLUT/glut.h>
#include <OpenGL/GL.h>
#include <OpenGL/GLU.h>

#endif

int N, x[100], y[100];

void keyboard(unsigned char c, int x, int y) {
	if (c == 27) {
		exit(0);
	}
}

void render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (GLfloat i = -1; i <= 1; i += 0.1) {
		glLineWidth(1);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
			glVertex2f(-1, i);
			glVertex2f(1, i);
		glEnd();
	
		glLineWidth(1);
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_LINES);
			glVertex2f(i, -1);
			glVertex2f(i, 1);
		glEnd();
	}
	
	

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
		for (int i = 1; i <= N; i++) {
			glVertex2f(x[i], y[i]);
		}
		
	glEnd();
	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON) {
		exit(0);
	}
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("My OpenGL-Window");
	
	
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf_s("%d %d", &x[i], &y[i]);
	}

	glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	glutMainLoop();

	return 0;
}