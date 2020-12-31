#ifdef WIN32
#include<Windows.h>
#include<gl/GL.h>
#include<gl/GLU.h>
#include "GL/glut.h"

#endif

void RenderScene(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(-25.0f, 25.0f, 25.0f, -25.0f);
	glFlush();
}
//setup rendering state
void SetupRC(void) 
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

}
//void changesize
void ChangeSize(GLsizei w, GLsizei h) 
{
	GLfloat aspectRatio;
	//prevent divide by 0
	if (h == 0)
		h = 1;
	//set viewport to window dimensions
	glViewport(0, 0, w, h);
	//Reset coordinate systems
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Establish clipping volume
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w<=h)
		glOrtho(-100.0, 100, -100.0 / aspectRatio, 100.0 / aspectRatio, 1.0, -1.0);
	else 
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 1.0, -1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//main program 
int main(int argc, char*argv[]) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutCreateWindow("Change Size!");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);

	SetupRC();
	glutMainLoop();
	return 0;
}


