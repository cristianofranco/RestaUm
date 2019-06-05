//Resta Um

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat angle, fAspect, inclinacao = 0;
//Definição de cores RGBA para usar com MaterialFV
GLfloat Black[] = {0.0, 0.0, 0.0, 1.0};
GLfloat DarkRed[] = {0.2, 0.0, 0.0, 1.0};
GLfloat Red[] = {0.4, 0.0, 0.0, 1.0};
GLfloat White[] = {1, 1, 1, 1.0};
GLfloat LightGray[] = {0.80, 0.80, 0.80};
GLfloat Gray[] = {0.45, 0.45, 0.45};

void BaseCubo()
/*Especifica o lado de um cubo*/
{
	glBegin(GL_POLYGON);
		glTexCoord2f(0.0,0.0);
		glVertex3d(-0.5,-0.5,0.0);

		glTexCoord2f(0.0,1.0);
		glVertex3d(-0.5,0.5,0.0);

		glTexCoord2f(1.0,1.0);
		glVertex3d(0.5,0.5,0.0);

		glTexCoord2f(1.0,0.0);
		glVertex3d(0.5,-0.5,0.0);
	glEnd();
}

void Cubo()
{
	glPushMatrix();

	BaseCubo();

	glPushMatrix();
	//Eixo +x
	glTranslated(0.5,0.0,0.5);
	glRotated(90.0,0.0,1.0,0.0);
	BaseCubo();

	glPopMatrix();

	//Eixo -x
	glPushMatrix();
	glTranslated(-0.5,0.0,0.5);
	glRotated(-90.0,0.0,1.0,0.0);
	BaseCubo();
	glPopMatrix();

	//Eixo +y
	glPushMatrix();
	glTranslated(0.0,0.5,0.5);
	glRotated(-90.0,1.0,0.0,0.0);
	BaseCubo();
	glPopMatrix();

	//Eixo -y
	glPushMatrix();
	glTranslated(0.0,-0.5,0.5);
	glRotated(90.0,1.0,0.0,0.0);
	BaseCubo();
	glPopMatrix();

	//Montando a parte de cima

	glBegin(GL_POLYGON);
		glTexCoord2f(0.0,0.0);
		glVertex3d(-0.5,-0.5,1.0);

		glTexCoord2f(1.0,0.0);
		glVertex3d(0.5,-0.5,1.0);

		glTexCoord2f(1.0,1.0);
		glVertex3d(0.5,0.5,1.0);

		glTexCoord2f(0.0,1.0);
		glVertex3d(-0.5,0.5,1.0);
	glEnd();


	glPopMatrix();
}

//Representa uma esfera individual
void Esfera(){
    glColor3f(1, 1, 1);

    glutSolidSphere(15, 50, 50);
}

void DesenhaEsferas(){
    //DEFINE A COR AMBIENTE, DIFUSA, ESPECULAR E A QUANTIDADE DE BRILHO
    glMaterialfv(GL_FRONT, GL_AMBIENT, Gray);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, LightGray);
    glMaterialfv(GL_FRONT, GL_SPECULAR, White);
    glMaterialf(GL_FRONT, GL_SHININESS, 30.0);

    //ESFERA 1 - COMEÇANDO DO TOPO-ESQUERDA
    glPushMatrix();
        glRotated(inclinacao - 90, 1, 0, 0);
        glScaled(0.45, 0.45, 0.45);
        glTranslated(-40, 120, 30);
        Esfera();

    //ESFERA 2
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 3
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 4
        glTranslated(-80, -40, 0);
        Esfera();

    //ESFERA 5
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 6
        glTranslated(40, 0, 0);
        Esfera();

   //ESFERA 7
        glTranslated(-160, -40, 0);
        Esfera();

    //ESFERA 8
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 9
        glTranslated(40, 0, 0);
        Esfera();


    //ESFERA 10
        glTranslated(40, 0, 0);
        Esfera();


    //ESFERA 11
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 12
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 13
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 14
        glTranslated(-240, -40, 0);
        Esfera();

    //ESFERA 15
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 16
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 17
        glTranslated(80, 0, 0);
        Esfera();

    //ESFERA 19
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 20
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 21
        glTranslated(-240, -40, 0);
        Esfera();

    //ESFERA 22
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 23
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 24
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 25
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 26
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 27
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 28
        glTranslated(-160, -40, 0);
        Esfera();

    //ESFERA 29
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 30
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 31
        glTranslated(-80, -40, 0);
        Esfera();

    //ESFERA 32
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 33
        glTranslated(40, 0, 0);
        Esfera();

    glPopMatrix();
}

//Representa o tabuleiro do Resta Um
void Tabuleiro() {
    glMaterialfv(GL_FRONT, GL_AMBIENT, DarkRed);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, Red);
    glMaterialfv(GL_FRONT, GL_SPECULAR, White);
    glMaterialf(GL_FRONT, GL_SHININESS, 60.0);

    //BASE DO TABULEIRO
    glPushMatrix();
        glColor3f(0.4, 0, 0);
        glRotated(inclinacao, 1, 0, 0);
        glTranslated(0, 3, -62.5);
        glScaled(125, 10, 125);
        Cubo();
    glPopMatrix();
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT); //Limpa o buffer de profundidade

    Tabuleiro();

    DesenhaEsferas();

    glutSwapBuffers();
}

void ConfiguraIluminacao() {
    //Setup de iluminação
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    //Setup de intensidade e cor da iluminação
    GLfloat luzAmbiente[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat luzDifusa[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat luzEspecular[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzDifusa);
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzEspecular);

    //Posicionando a luz
    GLfloat posicaoLuz[] = {0, 200, -200, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    //Setup iluminação
    ConfiguraIluminacao();

    glEnable(GL_DEPTH_TEST); //Habilita a profundidade (impede que faces sejam renderizadas na frente de outras faces quando na verdade estão atrás)

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    angle = 45;
}

// Função usada para especificar a posição do observador virtual
void PosicionaObservador(void)
{
    // Especifica sistema de coordenadas do modelo
    glMatrixMode(GL_MODELVIEW);
    // Inicializa sistema de coordenadas do modelo
    glLoadIdentity();
    // Especifica posição do observador e do alvo
    gluLookAt(0,80,200, 0,0,0, 0,1,0);
}

// Função usada para especificar o volume de visualização
void EspecificaParametrosVisualizacao(void)
{
    // Especifica sistema de coordenadas de projeção
    glMatrixMode(GL_PROJECTION);
    // Inicializa sistema de coordenadas de projeção
    glLoadIdentity();

    // Especifica a projeção perspectiva(angulo,aspecto,zMin,zMax)
    gluPerspective(angle,fAspect,0.5,500);

    PosicionaObservador();
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Para previnir uma divisão por zero
    if ( h == 0 )
        h = 1;

    // Especifica o tamanho da viewport
    glViewport(0, 0, w, h);

    if (w <= h)
        fAspect = (GLfloat)h/(GLfloat)w;
    else
        fAspect = (GLfloat)w/(GLfloat)h;

    EspecificaParametrosVisualizacao();
}

//Função callback para gerenciar eventos do teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    if (key == 'w') {
        if (inclinacao == 90) {
            inclinacao = 90;
        } else {
            inclinacao+= 5;
        }
    }
    if (key == 's') {
        if (inclinacao == 0) {
            inclinacao = 0;
        } else {
            inclinacao-= 5;
        }
    }

    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{

}

// Programa Principal
int main(void)
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(400, 150);
    glutCreateWindow("Resta Um");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    glutMouseFunc(GerenciaMouse);
    glutKeyboardFunc(GerenciaTeclado);
    Inicializa();
    glutMainLoop();

    return 0;
}
