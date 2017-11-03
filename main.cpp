
#include <GL\freeglut.h>
#include <GL\glut.h>
#include <iostream>

///Nama     : Robert Setyawan
///Materi   : Algoritma DDA

using namespace std;

void initialize();
void tampil(void);
void dda(void);
int bulat(double c);

//ukuran window
int width = 500;
int height = 500;

// judul window
char *judul = "Algoritma DDA";

int x1, y1, x2, y2,k,xn,yn;
float x,y,dx, dy, steps, x_inc, y_inc;


int main(int argc, char **argv)
{
    cout <<"Masukkan nilai x , y awal : ";
    cin >>x1;
    cin >>y1;
    cout <<"Masukkan nilai x , y akhir : ";
    cin >>x2;
    cin >>y2;
	// inisialisasi GLUT (OpenGL Utility Toolkit)
	glutInit(&argc, argv);
	glutInitWindowSize(width, height);
	glutCreateWindow(judul);
	initialize();
	glutDisplayFunc(tampil); //pemanggilan fungsi tampil garis
	glutMainLoop(); // loop pemrosesan GLUT
}

void initialize()
{
	glClearColor(1.0, 1.0, 1.0, 0.0); //set warna background
	glColor3f(0.0, 0.0, 0.0); //set warna titik
	glPointSize(2.0); //set ukuran titik
	glMatrixMode(GL_PROJECTION); //set mode matriks yang digunakan
	gluOrtho2D(0.0, 600.0, 0.0, 600.0); // set ukuran viewing window
}
void tampil(void)
{
	glClear(GL_COLOR_BUFFER_BIT); //clear color
	dda(); //panggil fungsi dda
	glutSwapBuffers(); //swap buffer
}
int bulat(double c){
    int i;
    double x;
    i = c;
    x = c - i;
    if(x >= 0.5){
        return i+1;
    }else return i;
}
void dda(void) {

//	x1 = 50;//titik x awal
//	y1 = 300;//titik y awal
//	x2 = 300;//titik x akhir
//	y2 = 100;//titik y akhir

	x = x1;//set titik x awal pada x1
	y = y1;//set titik y awal pada y1


	dx = x2 - x1;
	dy = y2 - y1;

	if (dx > dy) {
		steps = dx;
	}
	else {
		steps = dy;
	}

	x_inc = dx / steps;
	y_inc = dy / steps;

	//gambar titik awal
	glBegin(GL_POINTS);
	glVertex2i(x, y);


	//perulangan untuk menggambar titik-titik
	//kelemahan DDA tidak bisa menggambar jika x2 > x1
	//berikut solusinya
	//Kondisi untuk x
    if(x1<x2){
        for(k=0;k<steps;k++){
        x = x + x_inc;
        y = y + y_inc;
        glVertex2i(bulat(x),bulat(y));
        }
    }
    else{///jika x1 lebih besar x2
        while(x2<x){
            x = x -  x_inc;
            y = y -  y_inc;
            glVertex2i(bulat(x),bulat(y));
        }
    }

    //kondisi untuk y
    if(y1<y2){
        for(k=0;k<steps;k++){
        x = x + x_inc;
        y = y + y_inc;
        glVertex2i(bulat(x),bulat(y));
        }
    }
    else{///jika y1 lebih besar y2
        while(y2<y){
            x = x -  x_inc;
            y = y -  y_inc;
            glVertex2i(bulat(x),bulat(y));
        }
    }

	glEnd();
	glFlush();
}

