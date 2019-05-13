
//#define _MAIN_

#ifdef _MAIN_

// alice header
#include "main.h"

// zSpace v002
// zSpace header
#include <headers/app/include/zObjects.h>
#include <headers/app/include/zFnSets.h>
#include <headers/app/include/zViewer.h>

// include toolset header
#include <headers/app/include/Tools/zTsGeometry.h>

using namespace zSpace;
using namespace std;


////////////////////////////////////////////////////////////////////////// GLOBAL VARIABLES ----------------------------------------------------
////// --- MODEL OBJECTS ----------------------------------------------------
zModel model;
zObjMesh operateMesh;
zFnMesh fnOperateMesh;


string path = "C:/Users/Leo.b/Desktop/test.obj";

// tool set
zTsRemesh myRemesh;

////// --- GUI OBJECTS ----------------------------------------------------


////////////////////////////////////////////////////////////////////////// MAIN PROGRAM : MVC DESIGN PATTERN  ----------------------------------------------------
////// ---------------------------------------------------- MODEL  ----------------------------------------------------
void setup()
{
	model = zModel(10000);
	fnOperateMesh = zFnMesh(operateMesh);
	fnOperateMesh.from(path, zOBJ);

	myRemesh = zTsRemesh(operateMesh);

	// append to model for displaying the object
	model.addObject(operateMesh);

	
}

void update(int value)
{

}

////// ---------------------------------------------------- VIEW  ----------------------------------------------------
void draw()
{
	//drawGrid(20);
	backGround(0.75);
	model.draw();
}

////// ---------------------------------------------------- CONTROLLER  ----------------------------------------------------
void keyPress(unsigned char k, int xm, int ym)
{
	if (k == 'q')
		myRemesh.tangentialRelaxation();
}

void mousePress(int b, int state, int x, int y)
{
}

void mouseMotion(int x, int y)
{
}

#endif // _MAIN_