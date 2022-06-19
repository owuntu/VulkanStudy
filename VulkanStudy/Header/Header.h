#pragma once
//#include <vulkan/vulkan.h>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

const uint32_t g_WINDOW_WIDTH = 800;
const uint32_t g_WINDOW_HEIGHT = 600;

class HelloTriangleApplication
{
public:
	void run()
	{
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}

private:
	void initWindow()
	{
		glfwInit();
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_pWindow = glfwCreateWindow(g_WINDOW_WIDTH, g_WINDOW_HEIGHT, "Vulkan Study", nullptr, nullptr);
	}

	void initVulkan()
	{

	}

	void mainLoop()
	{
		while (!glfwWindowShouldClose(m_pWindow))
		{
			glfwPollEvents();
		}

	}

	void cleanup()
	{
		glfwDestroyWindow(m_pWindow);
		glfwTerminate();
	}

private:
	GLFWwindow* m_pWindow;
};
