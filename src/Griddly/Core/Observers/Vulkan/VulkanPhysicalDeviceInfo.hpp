#include <vulkan/vulkan.h>
#include <string>
#include "VulkanQueueFamilyIndices.hpp"

namespace vk {
struct VulkanPhysicalDeviceInfo {
    VkPhysicalDevice& physicalDevice;
    std::string deviceName;
    bool isGpu;
    bool isSupported;
    VulkanQueueFamilyIndices queueFamilyIndices;
};
}  // namespace vk