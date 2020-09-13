//standard
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//graphics
#include "GfxLib.h" //graphics






/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Octave Simulator ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	Developped using GfxLib :
	Project developped for ISEN Toulon, an Yncrea Mediterranee engineering school

	14/02/2019 > [0.1.0] :
		- Implemented simple function tracing (plot() function)
		BUGS : Bugs
		NOTES : Notes

	Contacts : sebastien.silvano@isen.yncrea.fr

	/!\ WARNING /!\ : Pay attention to GfxLib, features added !
	
	Special thanks to Ghislain Oudinet for GfxLib : ghislain.oudinet@isen.fr
	ISEN Toulon : www.isen.fr
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/






// ==================== DECLARATIONS ======================

// ---- game ----
const int maxl = 1080; const int maxl_2 = 540;
const int maxh = 640;  const int maxh_2 = 320;
const int thickness = 2;






// ====================== DISPLAY =========================

// ---- graphics ----
void axes(){
	ligne(0,maxh_2, maxl,maxh_2); //x
	ligne(maxl_2,0, maxl_2,maxh); //y
}

void plot(double (*function)(double), double xm,double xM, double ym,double yM){
	if(xm >= xM || ym >= yM){
		printf("MATH ERROR : Invalid interval for function calculations\n");
		return;
	}
	//calculation
	double coefX = (xM-xm)/maxl;
	double coefY = maxh/(yM-ym);
	double offsetY = -ym*coefY;
	//draw
	int pxl_y;
	for(int pxl_x=0; pxl_x <= maxl; pxl_x++){
		pxl_y =
			coefY*function(
				coefX*pxl_x + xm
			)
			+ offsetY
		;
		rectangle(
			pxl_x,pxl_y,
			pxl_x + thickness,
			pxl_y + thickness,1
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
void gestionEvenement(EvenementGfx evenement){
	switch(evenement){
		case Initialisation:
			demandeTemporisation(100);
		break;
		case Temporisation:
			//rafraichisFenetre();
		break;
		case Affichage:
			//prepare a clean graph
			effaceFenetre(255,255,255);
			couleurCourante(0,0,0);
			axes();
			
			//blue AM
			couleurCourante(0,0,255);
			plot(
				AM,
				-32*M_PI,32*M_PI,
				-2,2
			);
			
			//red FM
			couleurCourante(255,0,0);
			plot(
				FM,
				-32*M_PI,32*M_PI,
				-8,8
			);
		break;
		case Clavier:
		break;
		case ClavierSpecial:
		break;
		case BoutonSouris:
		break;
		case Souris:
		break;
		case Inactivite:
		break;
		case Redimensionnement:
		break;
	}
}



// ---- launch game ----
int main(int argc, char **argv){
	initialiseGfx(argc, argv);
	prepareFenetreGraphique("Octave Simulator [0.1.0]", maxl, maxh);
	lanceBoucleEvenements();
	return 0;
}

