/**
    @disciplina Computacao Grafica
    @aluno Jonathan Douglas Diego Tavares
    @matricula 201622040228
    @data 26/08/2019
**/

/**
    Funcionalidade extra: Geracao de matriz com controle de linhas e colunas via teclado

    Pressionar letra l para aumentar o numero de lados
    Pressionar letra k para diminuir o numero de lados
    Pressionar letra r para aumentar o raio
    Pressionar letra e para diminuir o raio
**/

#include <GL/glew.h>      // glew.h deve vir antes
#include <GL/freeglut.h>  // do freeglut.h
#include <math.h>
#include<stdio.h>

//#define M_PI acos(-1.0)

float nLados = 100000;
float raio = 0.1;
double angulo;

void escreveTexto(void * font, char *s, float x, float y, float z) {
    int i;
    glRasterPos3f(x, y, z);

    for (i = 0; i < strlen(s); i++) {
        glutBitmapCharacter(font, s[i]);
    }
}

void desenhaFigura(float x, float y){
    glBegin(GL_LINE_STRIP);
        for (float i = 0; i < nLados; i = i + 0.05){
            glVertex3f(x+raio*cos(i),y+raio*sin(i), 0);
            raio = raio + 1;
        }
    glEnd();
}

void desenhaHUD(){
    char bufferRaio[20];
    char bufferLados[20];
    itoa(raio, bufferRaio, 10);
    itoa(nLados, bufferLados, 10);

    escreveTexto(GLUT_BITMAP_HELVETICA_12, "Raio:", 20, 580, 0);
    escreveTexto(GLUT_BITMAP_HELVETICA_12, "nLados:", 20, 560, 0);
    escreveTexto(GLUT_BITMAP_HELVETICA_12, bufferRaio, 50, 580, 0);
    escreveTexto(GLUT_BITMAP_HELVETICA_12, bufferLados, 65, 560, 0);
}

// callback de desenho (display)
void desenhaMinhaCena() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    desenhaFigura(0, 0);
    glFlush();
}

// NOVIDADE: uma função que vamos chamar dentro
//    do "main"
// Inicia algumas variáveis de estado do OpenGL
void inicializa() {
    glPointSize(2);
    // define qual é a cor do fundo
    glClearColor(1, 1, 1, 1); // branco
    // desenho preenchido vs. contorno
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

// NOVIDADE: callback para o evento "reshape"
void redimensionada(int width, int height) {
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-600, 600, -600, 600, -1, 1);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

// NOVIDADE: callback de "keyboard"
void teclaPressionada(unsigned char key, int x, int y) {
    // vê qual tecla foi pressionada
    switch(key) {
    case 27:      // Tecla "ESC"
        exit(0);  // Sai da aplicação
        break;
    case 'r':
        raio = raio + 1;
        glutPostRedisplay();
        break;
    case 'e':
        if (raio > 1){
            raio = raio - 1;
        } else {
            printf("Raio minimo atingido.\n");
        }
        glutPostRedisplay();
        break;
    case 'l':
        nLados = nLados + 1;
        glutPostRedisplay();
        break;
    case 'k':
        if (nLados > 2){
            nLados = nLados - 1;
        } else {
            printf("Minimo de lados atingido.\n");
        }
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

// função principal
int main(int argc, char** argv) {
   glutInit(&argc, argv);

   glutInitContextVersion(2, 1);
   glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
   glutInitWindowSize(800, 600);
   glutInitWindowPosition(300, 100);

   glutCreateWindow("Atividade 3 - Jonathan Douglas Diego Tavares - Matrícula: 201622040228");

   // registra callbacks para alguns eventos
   glutDisplayFunc(desenhaMinhaCena);
   glutReshapeFunc(redimensionada);
   glutKeyboardFunc(teclaPressionada);

   // configura valor inicial de algumas
   // variáveis de estado do OpenGL
   inicializa();

   glutMainLoop();
   return 0;
}
