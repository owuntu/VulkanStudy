#pragma once
#ifdef _WIN32
#define VK_USE_PLATFORM_WIN32_KHR
#endif // _WIN32

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#ifdef _WIN32
#define GFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3native.h>
#endif //_WIN32

#include <cstring>
#include <optional>
#include <vector>

const uint32_t g_WINDOW_WIDTH = 800;
const uint32_t g_WINDOW_HEIGHT = 600;

const std::vector<const char*> validationLayers = {
	"VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif


struct QueueFamilyIndices
{
	std::optional<uint32_t> graphicsFamily;
	std::optional<uint32_t> presentFamily;

	bool isComplete()
	{
		return graphicsFamily.has_value() && presentFamily.has_value();
	}
};

class HelloTriangleApplication
{
public:
	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData
	);

	void run();

private:
	void initWindow();
	void initVulkan();

	void createLogicalDevice();
	void createInstance();
	void createSurface();

	void pickPhysicalDevice();
	bool isDeviceSuitable(VkPhysicalDevice device);

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

	void mainLoop();
	void cleanup();
	bool checkValidationLayerSupport();
	std::vector<const char*> getRequiredExtensions();

	void setupDebugMessenger();
	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

private:
	GLFWwindow* m_pWindow;

	VkInstance m_instance;
	VkDebugUtilsMessengerEXT m_debugMessenger;

	VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
	VkDevice m_device = VK_NULL_HANDLE;
	
	VkQueue m_graphicsQueue;
	VkQueue m_presentQueue;

	VkSurfaceKHR m_surface;
};
