//Resta Um

#include <GL/glut.h>
#include <stdio.h>
#include <stdbool.h>

GLint pecasRestantes;
GLfloat angle, fAspect, inclinacao = 0;
//Definição de cores RGBA para usar com MaterialFV
GLfloat Black[] = {0.0, 0.0, 0.0, 1.0};
GLfloat DarkRed[] = {0.2, 0.0, 0.0, 1.0};
GLfloat Red[] = {0.4, 0.0, 0.0, 1.0};
GLfloat White[] = {1, 1, 1, 1.0};
GLfloat LightGray[] = {0.80, 0.80, 0.80};
GLfloat Gray[] = {0.45, 0.45, 0.45};

///-1 = NAOPODEJOGAR 0 = VAZIO 1 = COM PEÇA
int tabuleiro[7][7] = {{-1, -1, 1, 1, 1, -1, -1},
                       {-1, -1, 1, 1, 1, -1, -1},
                         {1, 1, 1, 1, 1, 1, 1},
                         {1, 1, 1, 0, 1, 1, 1},
                         {1, 1, 1, 1, 1, 1, 1},
                       {-1,-1, 1, 1, 1, -1,-1},
                       {-1,-1, 1, 1, 1, -1,-1}};

/*------------------------- LOGICA DO JOGO --------------------------*/

//Verifica se o jogo ja acabou
void verificaFim() {
    if (pecasRestantes == 1) {
        printf("PARABENS!!!! VOCE VENCEU!!!\n");
        inclinacao = 0;
    }
}

//Retorna a quantidade de peças que faltam para acabar o jogo
int quantasFaltam() {
    pecasRestantes = 0; //Zera a quantidade para fazer a contagem

    for (int i=0;i<7;i++) {
        for (int j=0;j<7;j++) {
            if (tabuleiro[i][j] == 1)
                pecasRestantes++;
        }
    }

    return pecasRestantes;
}

void imprimeTab() {
    printf("\n");
    for (int i=0;i<7;i++) {
        printf("\n");
        for (int j=0;j<7;j++) {
            if ((i == 2 && j == 0) || (i == 3 && j == 0) || (i == 4 && j == 0)) {
                printf("  %d ", tabuleiro[i][j]);
            } else {
                printf("%d ", tabuleiro[i][j]);
            }
        }
    }
}

//Move a peça para um campo disponivel, "comendo" a peça vizinha
void movePeca(int i, int j, int direcao) { ///DIREÇÃO: CIMA=0, BAIXO=1, ESQ=2, DIR=3
    switch(direcao){
    case 0: ///CIMA

        tabuleiro[i][j] = 0;//Remover espaço que peça estava
        tabuleiro[i-1][j] = 0;//Remover vizinho
        tabuleiro[i-2][j] = 1;//Mover para próxima casa

        //
        break;

    case 1: ///BAIXO

        tabuleiro[i][j] = 0;//Remover espaço que peça estava
        tabuleiro[i+1][j] = 0;//Remover vizinho
        tabuleiro[i+2][j] = 1;//Mover para próxima casa

        break;

    case 2: ///ESQUERDA

        tabuleiro[i][j] = 0;//Remover espaço que peça estava
        tabuleiro[i][j-1] = 0;//Remover vizinho
        tabuleiro[i][j-2] = 1;//Mover para próxima casa

        break;

    case 3: ///DIREITA

        tabuleiro[i][j] = 0;//Remover espaço que peça estava
        tabuleiro[i][j+1] = 0;//Remover vizinho
        tabuleiro[i][j+2] = 1;//Mover para próxima casa

        break;

    }
}

/*Verifica se é possível realizar uma jogada
de acordo com o estado do tabuleiro, utilizando
a posição i e j para verificar os vizinhos */
int possoJogar(int i, int j){

    //Verificar cima
    if (tabuleiro[i-1][j] == 1 && i-1 > 0) { //Tem vizinho em cima?
        if (tabuleiro[i-2][j] == 0 && i-2 > 0) { //Depois do vizinho, tem espaço livre?
            printf("Posso mover para cima.");
            return 0;
        }
    }

    //Verificar baixo
    if (tabuleiro[i+1][j] == 1 && i+1 < 7) { //Tem vizinho embaixo?
        if (tabuleiro[i+2][j] == 0 && i+2 < 7) { //Depois do vizinho, tem espaço livre?
            printf("Posso mover para baixo.");
            return 1;
        }
    }

    //Verificar esq
    if (tabuleiro[i][j-1] == 1 && j-1 > 0) { //Tem vizinho na esquerda?
        if (tabuleiro[i][j-2] == 0 && j-2 > 0) { //Depois do vizinho, tem espaço livre?
            printf("Posso mover para esq.");
            return 2;
        }
    }

    //Verificar dir
    if (tabuleiro[i][j+1] == 1 && j+1 < 7) { //Tem vizinho na direita?
        if (tabuleiro[i][j+2] == 0 && j+2 < 7) { //Depois do vizinho, tem espaço livre?
            printf("Posso mover para dir.");
            return 3;
        }
    }

    return -1; //Se não achar condições de jogada, retorna -1.
}

//Realiza uma jogada, se for possível jogar
void fazJogada(int i, int j) {
    int dir = possoJogar(i, j);

    if (dir != -1) { //Verifica se pode jogar, se sim, faz a jogada
        movePeca(i, j, dir);
        verificaFim();
        imprimeTab();
    }
    else
        printf("Voce nao pode mover esta peca\n");
}

//Se clicou em uma posicao e tiver uma peca nela verifica se pode mover e move.
void clicouPos(int x, int y) {
    //Se clicou na posicao 1
    if (x > 301 && x < 355 && y > 94 && y < 147)
    {
        if (tabuleiro[0][2] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(0, 2);
    }

    //Se clicou na posicao 2
    if (x > 373 && x < 426 && y > 94 && y < 147)
    {
        if (tabuleiro[0][3] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(0, 3);
    }

    //Se clicou na posicao 3
    if (x > 445 && x < 498 && y > 94 && y < 147)
    {
        if (tabuleiro[0][4] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(0, 4);
    }

    //Se clicou na posicao 4
    if (x > 301 && x < 355 && y > 164 && y < 217)
    {
        if (tabuleiro[1][2] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(1, 2);
    }

    //Se clicou na posicao 5
    if (x > 373 && x < 426 && y > 164 && y < 217)
    {
        if (tabuleiro[1][3] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(1, 3);
    }

    //Se clicou na posicao 6
    if (x > 445 && x < 498 && y > 164 && y < 217)
    {
        if (tabuleiro[1][4] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(1, 4);
    }

    //Se clicou na posicao 7
    if (x > 175 && x < 226 && y > 234 && y < 281)
    {
        if (tabuleiro[2][0] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(2, 0);
    }

    //Se clicou na posicao 8
    if (x > 247 && x < 298 && y > 234 && y < 281)
    {
        if (tabuleiro[2][1] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(2, 1);
    }

    //Se clicou na posicao 9
    if (x > 319 && x < 370 && y > 234 && y < 281)
    {
        if (tabuleiro[2][2] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(2, 2);
    }

    //Se clicou na posicao 10
    if (x > 375 && x < 425 && y > 234 && y < 281)
    {
        if (tabuleiro[2][3] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(2, 3);
    }

    //Se clicou na posicao 11
    if (x > 442 && x < 492 && y > 234 && y < 281)
    {
        if (tabuleiro[2][4] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(2, 4);
    }

    //Se clicou na posicao 12
    if (x > 508 && x < 558 && y > 234 && y < 281)
    {
        if (tabuleiro[2][5] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(2, 5);
    }

    //Se clicou na posicao 13
    if (x > 573 && x < 625 && y > 234 && y < 281)
    {
        if (tabuleiro[2][6] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(2, 6);
    }

    //Se clicou na posicao 14
    if (x > 175 && x < 226 && y > 293 && y < 342)
    {
        if (tabuleiro[3][0] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(3, 0);
    }

    //Se clicou na posicao 15
    if (x > 247 && x < 298 && y > 293 && y < 342)
    {
        if (tabuleiro[3][1] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(3, 1);
    }

    //Se clicou na posicao 16
    if (x > 319 && x < 370 && y > 293 && y < 342)
    {
        if (tabuleiro[3][2] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(3, 2);
    }

    //Se clicou na posicao 17
    if (x > 375 && x < 425 && y > 293 && y < 342)
    {
        if (tabuleiro[3][3] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(3, 3);
    }

    //Se clicou na posicao 18
    if (x > 442 && x < 492 && y > 293 && y < 342)
    {
        if (tabuleiro[3][4] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(3, 4);
    }

    //Se clicou na posicao 19
    if (x > 508 && x < 558 && y > 293 && y < 342)
    {
        if (tabuleiro[3][5] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(3, 5);
    }

    //Se clicou na posicao 20
    if (x > 573 && x < 625 && y > 293 && y < 342)
    {
        if (tabuleiro[3][6] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(3, 6);
    }

    //Se clicou na posicao 21
    if (x > 175 && x < 226 && y > 352 && y < 398)
    {
        if (tabuleiro[4][0] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(4, 0);
    }

    //Se clicou na posicao 22
    if (x > 247 && x < 298 && y > 352 && y < 398)
    {
        if (tabuleiro[4][1] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(4, 1);
    }

    //Se clicou na posicao 23
    if (x > 319 && x < 370 && y > 352 && y < 398)
    {
        if (tabuleiro[4][2] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(4, 2);
    }

    //Se clicou na posicao 24
    if (x > 375 && x < 425 && y > 352 && y < 398)
    {
        if (tabuleiro[4][3] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(4, 3);
    }

    //Se clicou na posicao 25
    if (x > 442 && x < 492 && y > 352 && y < 398)
    {
        if (tabuleiro[4][4] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(4, 4);
    }

    //Se clicou na posicao 26
    if (x > 508 && x < 558 && y > 352 && y < 398)
    {
        if (tabuleiro[4][5] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(4, 5);
    }

    //Se clicou na posicao 27
    if (x > 573 && x < 625 && y > 352 && y < 398)
    {
        if (tabuleiro[4][6] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(4, 6);
    }

    //Se clicou na posicao 28
    if (x > 319 && x < 363 && y > 405 && y < 451)
    {
        if (tabuleiro[5][2] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(5, 2);
    }

    //Se clicou na posicao 29
    if (x > 378 && x < 422 && y > 405 && y < 451)
    {
        if (tabuleiro[5][3] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(5, 3);
    }

    //Se clicou na posicao 30
    if (x > 437 && x < 483 && y > 405 && y < 451)
    {
        if (tabuleiro[5][4] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(5, 4);
    }

    //Se clicou na posicao 31
    if (x > 320 && x < 363 && y > 457 && y < 501)
    {
        if (tabuleiro[6][2] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(6, 2);
    }

    //Se clicou na posicao 32
    if (x > 377 && x < 422 && y > 457 && y < 501)
    {
        if (tabuleiro[6][3] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(6, 3);
    }

    //Se clicou na posicao 33
    if (x > 436 && x < 480 && y > 457 && y < 501)
    {
        if (tabuleiro[6][4] != 1) {
            printf("\nnao tem peca onde voce clicou.\n");
        }
        else
            fazJogada(6, 4);
    }
}

/*------------------------ APARENCIA DO JOGO -------------------------*/

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

void MenuJogo(int op) {
    switch(op) {
    case 0:
        printf("Jogo iniciado!");

        inclinacao = 90; //Deixa o tabuleiro em pe

        EspecificaParametrosVisualizacao();
        glutPostRedisplay();

        break;
    case 1:
        exit(1);
        break;
    }

}

// Gerenciamento do menu principal
void MenuPrincipal(int op)
{
}

// Criacao do Menu
void CriaMenu()
{
    int menu,submenu1;

    submenu1 = glutCreateMenu(MenuJogo);
    glutAddMenuEntry("Iniciar jogo", 0);
    glutAddMenuEntry("Sair", 1);

    menu = glutCreateMenu(MenuJogo);
    glutAddSubMenu("Menu principal",submenu1);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Função callback chamada para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
    if (button == GLUT_RIGHT_BUTTON)
         if (state == GLUT_DOWN)
            CriaMenu();
    if (button == GLUT_LEFT_BUTTON)
        if (state == GLUT_DOWN) {
            clicouPos(x, y);
        }

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
