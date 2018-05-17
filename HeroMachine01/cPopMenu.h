//#ifndef POP_MENU_H
//#define POP_MENU_H
//#include <FG\freeglut.h>
//#include <FG\glut.h>
//#include<math.h>
//#include<stdlib.h>
//
//
////#define RED 1
////#define GREEN 2
////#define BLUE 3
////#define ORANGE 4
////
////#define FILL 1
////#define LINE 2
////
////#define SHRINK 1
////#define NORMAL 2
////int fillMenu, shrinkMenu, mainMenu, colorMenu;
////int menuFlag = 0;
////static float red = 1.0f, blue = 0.5f, green = 0.5f;
////float scale = 1.0f;
////float lx = 0.0f, lz = -1.0f;
////
////float angle = 0.0f;
////float deltaAngle = 0.0f;
////float deltaMove = 0;
////int xOrigin = -1;
////float x = 0.0f, z = 5.0f;
//
//class PopMenu
//{
//
//public:
//
//	PopMenu() {};
//	static void processMenuStatus(int status, int x, int y) {
//
//		if (status == GLUT_MENU_IN_USE)
//			menuFlag = 1;
//		else
//			menuFlag = 0;
//	}
//	static void createPopupMenus() {
//
//
//		shrinkMenu = glutCreateMenu(processShrinkMenu);
//
//		glutAddMenuEntry("Shrink", SHRINK);
//		glutAddMenuEntry("NORMAL", NORMAL);
//
//		fillMenu = glutCreateMenu(processFillMenu);
//
//		glutAddMenuEntry("Fill", FILL);
//		glutAddMenuEntry("Line", LINE);
//
//		colorMenu = glutCreateMenu(processColorMenu);
//		glutAddMenuEntry("Red", RED);
//		glutAddMenuEntry("Blue", BLUE);
//		glutAddMenuEntry("Green", GREEN);
//		glutAddMenuEntry("Orange", ORANGE);
//
//		mainMenu = glutCreateMenu(processMainMenu);
//
//		glutAddSubMenu("Polygon Mode", fillMenu);
//		glutAddSubMenu("Color", colorMenu);
//		// attach the menu to the right button
//		glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//		// this will allow us to know if the menu is active
//		glutMenuStatusFunc(processMenuStatus);
//	}
//	static void processMainMenu(int option) {
//
//		// nothing to do in here
//		// all actions are for submenus
//	}
//	static void createGLUTMenus() 
//	{
//
//		int menu;
//		
//		// create the menu and
//		// tell glut that "processMenuEvents" will
//		// handle the events
//		menu = glutCreateMenu(processMenuEvents);
//
//		//add entries to our menu
//		glutAddMenuEntry("Red", RED);
//		glutAddMenuEntry("Blue", BLUE);
//		glutAddMenuEntry("Green", GREEN);
//		glutAddMenuEntry("Orange", ORANGE);
//
//		// attach the menu to the right button
//		glutAttachMenu(GLUT_RIGHT_BUTTON);
//	}
//	static void processShrinkMenu(int option) {
//
//		switch (option) {
//
//		case SHRINK: scale = 0.5f; break;
//		case NORMAL: scale = 1.0f; break;
//		}
//	}
//	static void processFillMenu(int option) {
//
//		switch (option) {
//
//		case FILL: glPolygonMode(GL_FRONT, GL_FILL); break;
//		case LINE: glPolygonMode(GL_FRONT, GL_LINE); break;
//		}
//	}
//
//	static void processColorMenu(int option) {
//
//		switch (option) {
//		case RED:
//			red = 1.0f;
//			green = 0.0f;
//			blue = 0.0f; break;
//		case GREEN:
//			red = 0.0f;
//			green = 1.0f;
//			blue = 0.0f; break;
//		case BLUE:
//			red = 0.0f;
//			green = 0.0f;
//			blue = 1.0f; break;
//		case ORANGE:
//			red = 1.0f;
//			green = 0.5f;
//			blue = 0.5f; break;
//		}
//	}
//	static void processMenuEvents(int option) {
//
//		switch (option) {
//		case RED:
//			red = 1.0f;
//			green = 0.0f;
//			blue = 0.0f; break;
//		case GREEN:
//			red = 0.0f;
//			green = 1.0f;
//			blue = 0.0f; break;
//		case BLUE:
//			red = 0.0f;
//			green = 0.0f;
//			blue = 1.0f; break;
//		case ORANGE:
//			red = 1.0f;
//			green = 0.5f;
//			blue = 0.5f; break;
//		}
//	}
//};
//#endif