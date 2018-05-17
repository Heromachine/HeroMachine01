#ifndef DISPLAY_H

#define DISPLAY_H

#include<iostream>

#include <string>

#include<GL\glew.h>

#include<GLFW\glfw3.h>

#include "cMouse.h";


using namespace std;



class Display

{

private:

	Mouse mouse;

	Display(const Display& other) {}

	Display & operator=(const Display& other) {}



	GLFWwindow* window;



	bool LMD;



public:

	Display(int width, int height, const std::string& title, Mouse &dmouse);

	virtual ~Display();



	void SwapBuffers();

	void Update();

	void UpdateMouse(double &x, double &y, int & b);



	//bool IsClosed();

	const GLint WIDTH = 800, HEIGHT = 600;



	bool IsClosed()

	{

		return glfwWindowShouldClose(window);

	}





};



#endif //DISPLAY_H