#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW\glfw3.h>

#include "cDisplay.h"





//static void cursorPositionCallback(GLFWwindow *window, double x, double y);

//void cursorEnterCallback(GLFWwindow *window, int entered);

//void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);

//void scrollCallback(GLFWwindow *window, double xOffset, double yOffset);



Display::Display(int width, int height, const std::string & title, Mouse &dmouse)

{

	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);



	window = glfwCreateWindow(WIDTH, HEIGHT, "VACCUM", nullptr, nullptr);



	//MOUSE



	glfwSetCursorPosCallback(window, mouse.cursorPositionCallback);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	glfwSetCursorEnterCallback(window, mouse.cursorEnterCallback);

	glfwSetMouseButtonCallback(window, mouse.mouseButtonCallback);

	glfwSetScrollCallback(window, mouse.scrollCallback);

	glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, 1);



	//new mouse image

	GLFWimage image; //= mouse.CreateMouseImage(10, 10);

	unsigned char pixels[16 * 16 * 4];

	memset(pixels, 0xff, sizeof(pixels));

	image.width = 10;

	image.height = 10;

	image.pixels = pixels;



	GLFWcursor *cursor = glfwCreateCursor(&image, 0, 0);

	glfwSetCursor(window, cursor);



	//CHECK ERRORS

	int screenWidth = width;

	int screenHeight = height;



	if (nullptr == window)

	{

		std::cout << "FAILED\n";

		glfwTerminate();

	}

	else

	{

		cout << "\WINDOW CREATED";

	}



	glfwMakeContextCurrent(window);



	glewExperimental = GL_TRUE;



	if (GLEW_OK != glewInit())

	{

		std::cout << "\nFAILED TO GLEW\n";

	}



	glViewport(0, 0, screenWidth, screenHeight);



}



Display::~Display()

{

	glfwTerminate();

}



void Display::SwapBuffers()

{

	//cout << "SWAPING BUFFER";

	glfwSwapBuffers(window);

}



void Display::Update()

{

	//cout << "UPDATING";

	glfwPollEvents();

}



void Display::UpdateMouse(double & x, double & y, int &b)

{

	glfwGetCursorPos(window, &x, &y);

	glfwGetMouseButton(window, b);



}