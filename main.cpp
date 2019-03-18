#include<GL/glut.h>
#include<cmath>


int screenWidth = 800;
int screenHeight = 800;
int screenDepth = 600;


double PI = 3.14;

float ANGLE = 0.0f;
void init(void)
{
    GLfloat lgt1_diffuse[] = { 0.05f, 0.05f, 0.6f, 1.0f };
    GLfloat lgt2_diffuse[] = { 0.6f, 0.05f, 0.05f, 1.0f };
    GLfloat light_pos1[] = { 5.0f, 5.0f, 0.0f, 1.0f };
    GLfloat light_pos2[] = { -5.0f, 5.0f, 0.0f, 1.0f };

    GLfloat ambientLight[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat diffuseLight[] = {1.0f, 1.f, 1.f, 1.0f};
    GLfloat specularLight[] = {0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat position[] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat shininess[] = {50.0f};
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light[] = { 0.0, 0.9, 0.2 };
    GLfloat lmodel_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight );
//    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight );

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    ANGLE += 0.2;
}

void circle(int radius, int width)
{
    double PI = 3.14;
    int numPoints = 360;
    glColor3ub(253, 165, 15);
    glBegin(GL_POLYGON);
    for(int i = 0; i < numPoints; i++) {
        float angle = i * (2 * PI/numPoints);
        int x = (int) (cos(angle) * radius);
        int y = (int) (sin(angle) * radius);
        glVertex3i(width, x, y);
    }

    glEnd();

}
void circles(int depth, int width, int height)
{
    glPushMatrix();
    glTranslatef(0,0,50);
    circle((int)(height * .7), width);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,0,-50);
    circle((int)(height * .7), width);
    glPopMatrix();

}
void wheel(int radius)
{
    glColor3ub(121,61,55);
    glutSolidTorus(radius * .45, radius, 360, 360);

    glColor3ub(90,103,51);

    for(int i = 0; i<=5; i++)
    {
        float angle = i * (2 * PI/5) - ANGLE;
        int x = (int) (cos(angle) * radius);
        int y = (int) (sin(angle) * radius);
        glPushMatrix();
        glRotatef(90,x,y,0);
        glTranslatef(0,0,-30);
        glutSolidCone(radius * .2, radius/1.2, 360, 10);
        glPopMatrix();
    }
}

void wheels(int depth, int width, int height)
{
    depth = depth + 19;
    width = .6 * width;

    glPushMatrix();
    glTranslatef(width,-height,-depth);
    wheel((int)(height * .7));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-width,-height,-depth);
    wheel((int)(height * .7));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-width,-height,depth);
    wheel((int)(height * .7));
    glPopMatrix();

    glPushMatrix();
    glTranslatef(width,-height,depth);
    wheel((int)(height * .7));
    glPopMatrix();
}
void up()
{
    int depth = 100;
    int width = 100;
    int height = 30;

    glPushMatrix();
    glTranslated(-100, 3*height, 0);
    glBegin(GL_POLYGON);
    glVertex3i(width,-height,-depth);
    glVertex3i(-width,-height,-depth);
    glVertex3i(-width,height,-depth);
    glVertex3i(width,height,-depth);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(width,-height,depth);
    glVertex3i(-width,-height,depth);
    glVertex3i(-width,height,depth);
    glVertex3i(width,height,depth);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(-width,-height,depth);
    glVertex3i(-width,-height,-depth);
    glVertex3i(-width,height,-depth);
    glVertex3i(-width,height,depth);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(width,-height,depth);
    glVertex3i(width,-height,-depth);
    glVertex3i(width,height,-depth);
    glVertex3i(width,height,depth);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(width,-height,depth);
    glVertex3i(width,-height,-depth);
    glVertex3i(-width,-height,-depth);
    glVertex3i(-width,-height,depth);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(width,height,depth);
    glVertex3i(width,height,-depth);
    glVertex3i(-width,height,-depth);
    glVertex3i(-width,height,depth);
    glEnd();
    glPopMatrix();
}

void body(int depth, int width, int height)
{
    glColor3ub(0,61,55);
    glBegin(GL_POLYGON);
    glVertex3i(width,-height,-depth);
    glVertex3i(-width,-height,-depth);
    glVertex3i(-width,height,-depth);
    glVertex3i(width,height,-depth);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex3i(width,-height,depth);
    glVertex3i(-width,-height,depth);
    glVertex3i(-width,height,depth);
    glVertex3i(width,height,depth);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(-width,-height,depth);
    glVertex3i(-width,-height,-depth);
    glVertex3i(-width,height,-depth);
    glVertex3i(-width,height,depth);
    glEnd();


    glBegin(GL_POLYGON);
    glVertex3i(width,-height,depth);
    glVertex3i(width,-height,-depth);
    glVertex3i(-width,-height,-depth);
    glVertex3i(-width,-height,depth);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3i(width,height,depth);
    glVertex3i(width,height,-depth);
    glVertex3i(-width,height,-depth);
    glVertex3i(-width,height,depth);
    glEnd();
}

void car()
{
    int depth = 120;
    int width = 250;
    int height = 60;

    body(depth, width, height);
    up();
    wheels(depth, width, height);
    circles(depth, width, height);

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    init ();

//    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
//    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
//    glLightfv(GL_LIGHT0, GL_POSITION, position);
//    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);

    gluLookAt(1,-3,-6,0,0,0,0,1,0);
//    gluLookAt(1,1,-6,0,0,0,0,1,0);
//    gluLookAt(1,1,-1,0,0,0,0,1,0); // isometric
//    gluLookAt(1,0,0,0,0,0,0,1,0); // FRONT see lights
//    gluLookAt(1,1,0,0,0,0,0,1,0); // TOP see car up
//    gluLookAt(0,0,-1,0,0,0,0,1,0); // SIDE see wheel

    car();

    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(screenWidth,screenHeight);
    glutCreateWindow("car");

    glutInitDisplayMode(GLUT_RGB | GL_DEPTH | GL_DOUBLE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
    glClearColor(0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho( -screenWidth/2.0f, screenWidth/2.0f, -screenHeight/2.0f, screenHeight/2.0f , -screenDepth/2.0f , screenDepth/2.0f );    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutMainLoop();
    return 0;
}