#include "VulkanObserver.hpp"

#include <spdlog/spdlog.h>

#include <fstream>

#include "VulkanConfiguration.hpp"
#include "VulkanDevice.hpp"
#include "VulkanInstance.hpp"

namespace griddy {

VulkanObserver::VulkanObserver(std::shared_ptr<Grid> grid, uint tileSize) : Observer(grid), tileSize_(tileSize) {
}

VulkanObserver::~VulkanObserver() {}

void VulkanObserver::init(uint gridWidth, uint gridHeight) {
  spdlog::debug("Initializing Vulkan Observer.");
  auto configuration = vk::VulkanConfiguration();
  std::unique_ptr<vk::VulkanInstance> vulkanInstance(new vk::VulkanInstance(configuration));

  auto width = gridWidth * tileSize_;
  auto height = gridHeight * tileSize_;

  observationShape_ = {3, width, height};
  observationStrides_ = {1, 3, 3*width};

  std::unique_ptr<vk::VulkanDevice> vulkanDevice(new vk::VulkanDevice(std::move(vulkanInstance), width, height, tileSize_));

  device_ = std::move(vulkanDevice);

  device_->initDevice(false);
}

std::vector<uint> VulkanObserver::getShape() const {
  return observationShape_;
}

std::vector<uint> VulkanObserver::getStrides() const {
  return observationStrides_;
}

void VulkanObserver::print(std::unique_ptr<uint8_t[]> observation) {
  std::string filename = fmt::format("{0}.ppm", grid_->getTickCount());
  std::ofstream file(filename, std::ios::out | std::ios::binary);

  auto width = grid_->getWidth() * tileSize_;
  auto height = grid_->getHeight() * tileSize_;

  // ppm header
  file << "P6\n"
       << width << "\n"
       << height << "\n"
       << 255 << "\n";

  file.write((char*)observation.get(), width * height * 3);
  file.close();
}

}  // namespace griddy