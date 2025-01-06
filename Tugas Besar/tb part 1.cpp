#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

void cylinder(float rbase, float rtop, float height);
void blok(float tebal, int ratiol, int ratiop);
void bilah (float r_inner, float r_outer, float tebal, int batang);
void kipas();

int screen_width=600; // inisialisasi lebar screen
int screen_height=400; // inisialisasi tinggi screen
int button_up=0, button_down=0;
int Turn=0;
float xPos = 1.0;
float yPos = 1.0;

double rotation_y=0, rotation_y_plus=-15, direction; // merubah rotasi
double Rhead=0, Rheadplus=0;
double Angguk=0, Anggukplus=0;
double press=0, pressplus, pressplus1=180, pressplus2=0, pressplus3=0, pressplus4=0, pressplus5=0;

bool Toleh = true, Tolehpress=true;
bool RightTurn=true;
bool speed1=true, speed2=false, speed3=false, speed4=false, speed5=false;

// Variabel untuk skala
float scaleFactor = 1.0; // Faktor skala

// Variabel untuk translasi
float translateX = 0.0f; // Posisi translasi di sumbu X
float translateY = 0.0f; // Posisi translasi di sumbu Y
float translateZ = 0.0f; // Posisi translasi di sumbu Z

// Variabel untuk rotasi
float rotateX = 0.0f;
float rotateY = 0.0f;

// setting pencahayaan kipas angin
GLfloat ambient_light[]={0.0,0.0,0.15,1.0};
GLfloat source_light[]={0.9,0.5,0.7,1.0};
GLfloat light_pos[]={3.0,0.0,6.0,1.0};

void cartesius() {
    glColor3f(0.1, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(10.0, 0.0, 0.0);
    glVertex3f(0.0, -10.0, 0.0);
    glVertex3f(0.0, 10.0, 0.0);
    glVertex3f(0.0, 0.0, -10.0);
    glVertex3f(0.0, 0.0, 10.0);
    glEnd();
}

// menggambar meja
void meja(){
	// mengatur transformasi
	glPushMatrix();
	glTranslatef(translateX, translateY, translateZ);
	glRotatef(rotateX, 1.0f, 0.0f, 0.0f); // rotasi di sumbu X
	glRotatef(rotateY, 0.0f, 1.0f, 0.0f); // rotasi di sumbu Y
	glScalef(scaleFactor, scaleFactor, scaleFactor); // skala
	
	// alas meja 
	
	glPushMatrix();
	glTranslated(0.0, 0.0, 0.0);
	glScaled(1.5, 0.2, 1.6);
	glutSolidCube(10);
	glPopMatrix();
	
	// kaki meja
	glColor3d(0.88, 0.72, 0.53);
	glPushMatrix();
	glTranslatef(-7.5, -7.0, -8.0); // kaki kiri depan
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(10);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(7.5, -7.0, -8.0); // kaki kanan depan
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(10);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-7.5, -7.0, 8.0); // kaki kiri belakang
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(10);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(7.5, -7.0, 8.0); // kaki kanan belakang
	glScalef(0.2, 1.5, 0.2);
	glutSolidCube(10);
	glPopMatrix();
	
	glPopMatrix();
}

void init(void)
{
    glShadeModel(GL_SMOOTH);
    glViewport(0,0,screen_width,screen_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(GLfloat)screen_width/(GLfloat)screen_height,1.0f,1000.0f);

    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
    glEnable(GL_LIGHTING);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, source_light);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    
}

// fungsi untuk membuat objek tetap proporsional sewaktu layar di maximaze
void resize(int width, int height)
{
    screen_width=width;
    screen_height=height;

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glViewport(0,0,screen_width,screen_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(55.0f,(GLfloat)screen_width/(GLfloat)screen_height,1.0f,1000.0f);

    glutPostRedisplay();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); // MEMBERSIHKAN LAYAR LATAR BELAKANG
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Terapkan translasi berdasarkan posisi yang diperbarui
    glTranslatef(translateX, translateY, -70);
    
    cartesius();
    meja();
	glPushMatrix();
    glScalef(scaleFactor, scaleFactor, scaleFactor); // Terapkan skala
    
    glRotatef(270,1.0,0.0,0.0);
    kipas();
    glPopMatrix();
   
    
    glutSwapBuffers();
}

void kipas(){
	glPushMatrix();

    cylinder(2.5, 1.5, 16); // silinder batang bawah 2
    
	cylinder(2.5, 2.5, 6); // silinder batang bawah 1
    glPushMatrix();
    glTranslatef(0.0, 0.0, 14);
    glRotatef(90, 0.0, 1.0, 0.0);
    glRotatef(Angguk, 0.0, 0.0, 1.0);
    Anggukplus = 0;
    
	glPushMatrix();
    glRotatef(270, 0.0, 1.0, 0.0);
    glTranslatef(0.0, 0.0, 1);
    cylinder(0.5, 1, 4); // silinder batang atas
    glPopMatrix();
    
	glutSolidTorus(1.5, 2, 6, 16);
    glTranslatef(0.0, 0.0, -2);
    cylinder(1, 1, 4.3); // silinder penghubung batang atas dan batang bawah
    glTranslatef(0.0, 0.0, 2);
    glRotatef(270, 0.0, 1.0, 0.0);
    
	glPushMatrix();
    glTranslatef(0.0, 0.0, 10);
    glRotatef(90, 1.0, 0.0, 0.0);
    
    // Turn left-right for fan head
    if (Toleh == true) {
        if (Turn >= 60) // max degrees right
            RightTurn = false;
        if (Turn <= -60) // max degrees left
            RightTurn = true;
        if (RightTurn == true) {
            Rheadplus++;
            Turn++;
        } else {
            Rheadplus--;
            Turn--;
        }
    }
    Rhead = Rhead + Rheadplus;
    glRotatef(Rhead, 0.0, 1.0, 0.0);
    Rheadplus = 0;
    // end turn left-right for fan head
	
	glTranslatef(0.0, 0.0, -3.0);
    cylinder(4, 4, 6); // silinder belakang kipas
    cylinder(1, 0.5, 15); // silinder tonjolan di depan kipas
    glRotatef(270, 1.0, 0.0, 0.0);
    
	if (Tolehpress == true) // press down turn left-right head button
        cylinder(0.3, 0.5, 6); // silinder tonjolan di belakang
    else // pull up turn left-right head button
        cylinder(0.3, 0.5, 7);
   
    glRotatef(90, 1.0, 0.0, 0.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 11);
    glutWireTorus(5, 7, 10, 64);
    glutSolidTorus(0.5, 12, 10, 64);
    rotation_y += rotation_y_plus;
    if (rotation_y > 359) rotation_y = 0;
    glRotatef(rotation_y, 0.0, 0.0, 1.0);
    bilah(3, 10, 3, 5); // bilah kipas(inner radius, outer radius, thickness, qty bilah)
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glRotatef(90, 1.0, 0.0, 0.0);
    glTranslatef(0.0, -1.0, -4);
    blok(2, 7, 10); // blok di bawah / papan kontrol

    // speed selection
    glTranslatef(-6, 1, 14);
    glRotatef(270, 1.0, 0.0, 0.0);
    glTranslatef(2.0, 0.0, 0.0);
    
	glPushMatrix();
    glRotatef(pressplus5, 1.0, 0.0,     0.0);
    blok(0.5, 2, 2); // blok tombol off
    glPopMatrix();
    glTranslatef(2.0, 0.0, 0.0);
    
	glPushMatrix();
    glRotatef(pressplus1, 1.0, 0.0, 0.0);
    blok(0.5, 2, 2); // blok tombol speed 1
    glPopMatrix();
    glTranslatef(2.0, 0.0, 0.0);
   
    glPushMatrix();
    glRotatef(pressplus2, 1.0, 0.0, 0.0);
    blok(0.5, 2, 2); // blok tombol speed 2
    glPopMatrix();
    glTranslatef(2.0, 0.0, 0.0);
   
    glPushMatrix();
    glRotatef(pressplus3, 1.0, 0.0, 0.0);
    blok(0.5, 2, 2); // blok tombol speed 3
    glPopMatrix();
    glTranslatef(2.0, 0.0, 0.0);
    
	glPushMatrix();
    glRotatef(pressplus4, 1.0, 0.0, 0.0);
    blok(0.5, 2, 2); // blok tombol speed 4
    glPopMatrix();
    pressplus5 = 0;

    // end of speed selection
  
}
// membuat silinder
void cylinder(float rbase, float rtop, float height)
{
    float i;
    glColor3d(1.0,1.0,1.0); //warna putih
    glPushMatrix();
    glTranslatef(0.0, 0.0, -rbase / 4);
    glutSolidCone(rbase, 0, 32, 4);
    for (i = 0; i <= height; i += rbase / 8)
    {
        glTranslatef(0.0, 0.0, rbase / 8);
        glutSolidTorus(rbase / 4, rbase - ((i * (rbase - rtop)) / height), 16, 16);
    }
    glTranslatef(0.0, 0.0, rbase / 4);
    glutSolidCone(rtop, 0, 32, 4);
    glPopMatrix();
    
}

//membuat bilah kipas
void bilah(float r_inner, float r_outer, float tebal, int batang)
{
    float i;
	glPushMatrix();
    glTranslatef(0.0, 0.0, -tebal / 4);
    cylinder(r_inner, r_inner, tebal);
    glTranslatef(0.0, 0.0, tebal / 2);
    glRotatef(90, 0.0, 1.0, 0.0);
    for (i = 0; i < batang; i++)
    {
        glTranslatef(0.0, 0.0, r_inner);
        glRotatef(315, 0.0, 0.0, 1.0);
        blok(0.5, r_inner * 4.5, (r_outer - r_inner + (r_inner / 4)) * 2);
        glRotatef(45, 0.0, 0.0, 1.0);
        glTranslatef(0.0, 0.0, -r_inner);
        glRotatef(360 / batang, 1.0, 0.0, 0.0);
    }
    glPopMatrix();
}

// method untuk membuat blok kipas angin
void blok(float tebal, int ratiol, int ratiop)
{
    float i, j;
    glPushMatrix();
    for (i = 0; i < ratiop; i++)
    {
        glTranslatef(-(ratiol + 1) * tebal / 2, 0.0, 0.0);
        for (j = 0; j < ratiol; j++)
        {
            glTranslatef(tebal, 0.0, 0.0);
            glutSolidCube(tebal);
        }
        glTranslatef(-(ratiol - 1) * tebal / 2, 0.0, tebal);
    }
    glPopMatrix();
}

// fungsi untuk interaksi user dengan objek melalui keyboard
void keyboard_s(unsigned char key, int x,     int y)
{
    if (rotation_y_plus != 0)
        direction = (rotation_y_plus / abs(rotation_y_plus));
    else
        direction = -1;

    switch (key)
    {
    case '1': // speed pertama
        if (!speed1)
        {
            rotation_y_plus = 15 * direction;
            speed1 = true;
            pressplus1 = 180;
            speed2 = false;
            pressplus2 = 0;
            speed3 = false;
            pressplus3 = 0;
            speed4 = false;
            pressplus4 = 0;
            if (Tolehpress == true)
                Toleh = true;
        }
        else
        {
            speed1 = false;
            pressplus1 = 0;
            rotation_y_plus = 0;
            Toleh = false;
        }
        break;

    case '2': // speed kedua
        if (!speed2)
        {
            rotation_y_plus = 30 * direction;
            speed1 = false;
            pressplus1 = 0;
            speed2 = true;
            pressplus2 = 180;
            speed3 = false;
            pressplus3 = 0;
            speed4 = false;
            pressplus4 = 0;
            if (Tolehpress == true)
                Toleh = true;
        }
        else
        {
            speed2 = false;
            pressplus2 = 0;
            rotation_y_plus = 0;
            Toleh = false;
        }
        break;

    case '3': // speed ketiga
        if (!speed3)
        {
            rotation_y_plus = 45 * direction;
            speed1 = false;
            pressplus1 = 0;
            speed2 = false;
            pressplus2 = 0;
            speed3 = true;
            pressplus3 = 180;
            speed4 = false;
            pressplus4 = 0;
            if (Tolehpress == true)
                Toleh = true;
        }
        else
        {
            speed3 = false;
            pressplus3 = 0;
            rotation_y_plus = 0;
            Toleh = false;
        }
        break;

    case '4': // speed keempat
        if (!speed4)
        {
            rotation_y_plus = 15 * direction;
            speed1 = false;
            pressplus1 = 0;
            speed2 = false;
            pressplus2 = 0;
            speed3 = false;
            pressplus3 = 0;
            speed4 = true;
            pressplus4 = 180;
            if (Tolehpress == true)
                Toleh = true;
        }
        else
        {
            speed4 = false;
            pressplus4 = 0;
            rotation_y_plus = 0;
            Toleh = false;
        }
        break;

    case '5': // menghentikan toleh kipas kiri dan kanan
        if (Tolehpress == false)
        {
            if (speed1 || speed2 || speed3 || speed4)
                Toleh = true;
            Tolehpress = true;
        }
        else
        {
            if (speed1 || speed2 || speed3 || speed4)
                Toleh = false;
            Tolehpress = false;
        }
        break;

    case 'i': // meningkatkan skala
        scaleFactor += 0.1f; // meningkatkan skala
        break;

    case 'x': // menurunkan skala (diganti dari 'd' ke 'x')
        if (scaleFactor > 0.1f) // pastikan skala tidak negatif
            scaleFactor -= 0.1f; // menurunkan skala
        break;

    case 'w': // bergerak ke atas
        translateY += 0.5f;
        break;

    case 's': // bergerak ke bawah
        translateY -= 0.5f;
        break;

    case 'a': // bergerak ke kiri
        translateX -= 0.5f;
        break;

    case 'd': // bergerak ke kanan
        translateX += 0.5f;
        break;
        
    case 'q': // rotasi ke kiri
    	rotateY -= 5.0f;
    	break;
    	
    case 'e': // rotasi ke kanan
    	rotateY += 5.0f;
    	break;
    	
    case 'r': // rotasi ke atas
    	rotateX -= 5.0f;
    	break;
    	
    case 'f': // rotasi ke bawah
    	rotateX += 5.0f;
    	break;

    case 27: // Escape key to exit
        exit(0);
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(    screen_width, screen_height);
    glutCreateWindow("Kipas Angin dan Meja 3D");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyboard_s);
    init();
    glutMainLoop();
    return 0;
}
