//Resta Um

#include <GL/glut.h>

GLfloat angle, fAspect, inclinacao = 0; //INCLINAÇÃO: ÂNGULO DE ROTAÇÃO DO TABULEIRO
                                         //VALORES TESTADOS: {0~90}

//Representa a base do tabuleiro
void Base(){
    glutSolidCube(50);
}

//Representa uma esfera individual
void Esfera(){
    glColor3f(1, 1, 1);
    glutSolidSphere(15, 50, 50);
}

//Representa o tabuleiro do Resta Um
void Tabuleiro() {

    //BASE DO TABULEIRO
    glPushMatrix();
        glColor3f(0.4, 0, 0);
        glRotated(inclinacao, 1, 0, 0);
        glTranslated(0, -5, 0);
        glScaled(2.5, 0.5, 2.5);
        Base();
    glPopMatrix();

    //ESFERA 1 - COMEÇANDO DO TOPO-ESQUERDA
    glPushMatrix();
        glRotated(inclinacao - 90, 1, 0, 0);
        glScaled(0.45, 0.45, 0.45);
        glTranslated(-45, 125, 30);
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
        glTranslated(40, 0, 0);
        Esfera();

    //ESFERA 18
        glTranslated(40, 0, 0);
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

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    Tabuleiro();

    glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    angle=45;
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
    if (button == GLUT_LEFT_BUTTON)

    if (button == GLUT_RIGHT_BUTTON)

    EspecificaParametrosVisualizacao();
    glutPostRedisplay();
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
