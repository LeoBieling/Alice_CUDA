
//#define _MAIN_

#ifdef _MAIN_

// alice header
#include "main.h"

// zSpace v003
// zSpace header
#include <headers/zApp/include/zObjects.h>
#include <headers/zApp/include/zFnSets.h>
#include <headers/zApp/include/zViewer.h>

// zSpace toolset header
//#include <headers/zApp/include/zTsGeometry.h>

using namespace zSpace;
using namespace std;

/*objects*/
zObjMesh operateMeshObj;

/*function sets*/
zFnMesh fnOperateMesh;

/*tool sets*/

/*model setup*/
zModel model;

/*general variables*/
double background = 0.2;
bool drawMesh = true;


////////////////////////////////////////////////////////////////////////// MAIN PROGRAM : MVC DESIGN PATTERN  ----------------------------------------------------
////// ---------------------------------------------------- MODEL  ----------------------------------------------------
void setup()
{
	model = zModel(10000);
	fnOperateMesh = zFnMesh(operateMeshObj);

	zPointArray tmpVerts;
	zItMeshFace f;

	tmpVerts.push_back(zVector(10, 10, 0));
	tmpVerts.push_back(zVector(-10, -10, 0));
	tmpVerts.push_back(zVector(-10, 10, 0));

	fnOperateMesh.addPolygon(tmpVerts, f);

	

	model.addObject(operateMeshObj);

	/*gui setup*/
	B = *new ButtonGroup(Alice::vec(50, 450, 0));

	B.addButton(&drawMesh, "drawMesh");
	B.buttons[0].attachToVariable(&drawMesh);
}

void update(int value)
{
	operateMeshObj.setShowObject(drawMesh);
}

////// ---------------------------------------------------- VIEW  ----------------------------------------------------
void draw()
{
	drawGrid(50);
	backGround(background);
	model.draw();
}

////// ---------------------------------------------------- CONTROLLER  ----------------------------------------------------
void keyPress(unsigned char k, int xm, int ym)
{
}

void mousePress(int b, int state, int x, int y)
{
}

void mouseMotion(int x, int y)
{
}

#endif // _MAIN_