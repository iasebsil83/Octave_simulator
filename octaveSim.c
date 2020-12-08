//standard
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//graphics
#include "S2DE.h"












/*~~~~~~~~~~~~~~~~~~~~~~~ Octave Simulator [0.1.1] ~~~~~~~~~~~~~~~~~~~~~~~
	Developped using S2DE :

	14/02/2019 > [0.1.0] :
	 - Implemented simple function tracing (plot() function).

	08/12/2020 > [0.1.1] :
	 - Passed graphics from custom to S2DE.

	BUGS : Bugs
	NOTES : Notes

	Contact     : i.a.sebsil83@gmail.com
	Youtube     : https://www.youtube.com/user/IAsebsil83
	GitHub repo : https://github.com/iasebsil83

	Let's Code !                                  By I.A.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/












// ==================== DECLARATIONS ======================

// ---- S2DE variables ----
extern unsigned int S2DE_width;
extern unsigned int S2DE_height;

// ---- graph ----
const int thickness = 2;












// ====================== DISPLAY =========================

// ---- graphics ----
void axes(){
	S2DE_line(
		         0, S2DE_height/2, //x
		S2DE_width, S2DE_height/2
	);
	S2DE_line(
		S2DE_width/2,           0, //y
		S2DE_width/2, S2DE_height
	);
}

void plot(double (*function)(double), double xm,double xM, double ym,double yM){
	if(xm >= xM || ym >= yM){
		printf("MATH ERROR : Invalid interval for function calculations\n");
		return;
	}
	//calculation
	double coefX = (xM-xm)/S2DE_width;
	double coefY = S2DE_height/(yM-ym);
	double offsetY = -ym*coefY;
	//draw
	int pxl_y;
	for(int pxl_x=0; pxl_x <= S2DE_width; pxl_x++){
		pxl_y =
			coefY*function(
				coefX*pxl_x + xm
			)
			+ offsetY
		;
		S2DE_rectangle(
			            pxl_x,             pxl_y,
			pxl_x + thickness, pxl_y + thickness,
			1
		);
	}
}



// ---- functions ----
double AM(double x){
	return cos(x/10)*sin(x)/2.0;
}

double FM(double x){
	return sin( cos(x/25)*x );
}

double dirac(double x){
	return (x == 0);
}






// ====================== MAIN CODE ========================

// ---- events ----
void S2DE_event(int event){
	switch(event){

		case S2DE_DISPLAY:
			//prepare a clean graph
			S2DE_setColor(255,255,255);
			S2DE_rectangle(
				         0,           0,
				S2DE_width, S2DE_height,
				1
			);
			S2DE_setColor(  0,  0,  0);
			axes();

			//blue AM
			S2DE_setColor(  0,  0,255);
			plot(
				AM,
				-32*M_PI,32*M_PI,
				-2,2
			);

			//red FM
			S2DE_setColor(255,  0,  0);
			plot(
				FM,
				-32*M_PI,32*M_PI,
				-8,8
			);
		break;

		case S2DE_KEYBOARD:
		break;

		case S2DE_MOUSECLICK:
		break;

		case S2DE_MOUSEMOVE:
		break;

		case S2DE_TIMER:
			//S2DE_refresh();
		break;

		case S2DE_RESIZE:
		break;
	}
}



// ---- launch graph ----
int main(int argc, char **argv){

	//launch S2DE
	S2DE_init(argc,argv, "Octave Simulator [0.1.1]", 1080,640);
	S2DE_start();

	return EXIT_SUCCESS;
}

