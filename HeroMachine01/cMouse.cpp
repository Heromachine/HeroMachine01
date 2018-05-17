#include "cMouse.h"
#include <iostream>
using namespace std; 

void Mouse::cursorPositionCallback(GLFWwindow * window, double x, double y)
{
	cout << x << endl;
	cout << y << endl;
}


void Mouse::cursorEnterCallback(GLFWwindow * window, int entered)
{
	if (entered)
	{
		cout << " [MOUSE INSIDE WINDOW]\t";

	}
	else
	{
		cout << "[MOUSE OUTSIDE WINDOW]\t";
	}


}
void Mouse::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		cout << "[RIGHT BUTTON PRESSED]\t";
	}

	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
	{
		cout << "[RIGHT BUTTON REALEASED]\t";
	}

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{

		cout << "[LEFT BUTTON PRESSED]\t";
	}

	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
	{
		cout << "[LEFT BUTTON REALEASED]\t";
	}

}
void Mouse::scrollCallback(GLFWwindow *window, double xOffset, double yOffset)
{
	cout << "[" << xOffset << " : " << yOffset << "]" << endl;


}

GLFWimage Mouse::CreateMouseImage(int w, int h)
{
	unsigned char pixels[16 * 16 * 4];
	memset(pixels, 0xff, sizeof(pixels));
	GLFWimage image;
	image.width = w;
	image.height = h;
	image.pixels = pixels;

	return image;
}
