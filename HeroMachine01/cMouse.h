#ifndef MOUSE_H
#define MOUSE_H
#include <GLFW\glfw3.h>
#include <glm\glm.hpp>


#include <vector>

class Mouse
{
private: 
	double xpos;
	double ypose;
	bool leftButtonDown;
	bool rightButtonDown;



public:
	static void cursorPositionCallback(GLFWwindow *window, double x, double y);
	static void cursorEnterCallback(GLFWwindow * window, int entered);
	static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
	static void scrollCallback(GLFWwindow *window, double xOffset, double yOffset);
	
	void setLeftButtonTown(bool b)
	{
	
		leftButtonDown = b;
	
	}
	bool isLeftButtonDown()
	{
		return leftButtonDown;
	
	}

	void setRightButtonTown(bool b)
	{

		rightButtonDown = b;

	}
	bool isRightButtonDown()
	{
		return rightButtonDown;

	}
	GLFWimage CreateMouseImage(int w, int h);


};





#endif