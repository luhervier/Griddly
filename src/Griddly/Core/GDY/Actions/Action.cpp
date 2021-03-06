#include "Action.hpp"

#define SPDLOG_HEADER_ONLY
#include <spdlog/fmt/fmt.h>

namespace griddly {

Action::Action(std::shared_ptr<Grid> grid, std::string actionName, uint32_t delay)
    : actionName_(actionName),
      delay_(delay),
      grid_(grid) {
}

Action::~Action() {}

std::string Action::getDescription() const {
  auto sourceLocation = getSourceLocation();
  auto destinationLocation = getDestinationLocation();
  return fmt::format("Action: {0} [{1}, {2}]->[{3}, {4}] [{5}, {6}] Delay: [{7}]",
                     actionName_,
                     sourceLocation.x, sourceLocation.y,
                     destinationLocation.x, destinationLocation.y,
                     vectorToDest_.x, vectorToDest_.y,
                     delay_);
}

void Action::init(glm::ivec2 sourceLocation, glm::ivec2 destinationLocation) {
  sourceLocation_ = sourceLocation;
  destinationLocation_ = destinationLocation;

  actionMode_ = ActionMode::SRC_LOC_DST_LOC;
}

void Action::init(std::shared_ptr<Object> sourceObject, glm::ivec2 vectorToDest, glm::ivec2 orientationVector, bool relativeToSource) {
  sourceObject_ = sourceObject;

  auto rotationMatrix = sourceObject_->getObjectOrientation().getRotationMatrix();

  vectorToDest_ = relativeToSource ? vectorToDest * rotationMatrix : vectorToDest;
  orientationVector_ = relativeToSource ? orientationVector * rotationMatrix : orientationVector;

  actionMode_ = ActionMode::SRC_OBJ_DST_VEC;
}

std::shared_ptr<Object> Action::getSourceObject() const {
  if (sourceObject_ != nullptr) {
    return sourceObject_;
  } else {
    return grid_->getObject(sourceLocation_);
  }
}

std::shared_ptr<Object> Action::getDestinationObject() const {
  switch (actionMode_) {
    case ActionMode::SRC_LOC_DST_LOC:
    case ActionMode::SRC_OBJ_DST_LOC:
      return grid_->getObject(destinationLocation_);
    case ActionMode::SRC_OBJ_DST_OBJ:
      return destinationObject_;
    case ActionMode::SRC_OBJ_DST_VEC:
      auto destinationLocation = (getSourceLocation() + vectorToDest_);
      return grid_->getObject(destinationLocation);
  }
}

glm::ivec2 Action::getSourceLocation() const {
  switch (actionMode_) {
    case ActionMode::SRC_LOC_DST_LOC:
      return sourceLocation_;
    case ActionMode::SRC_OBJ_DST_LOC:
    case ActionMode::SRC_OBJ_DST_OBJ:
    case ActionMode::SRC_OBJ_DST_VEC:
      return sourceObject_->getLocation();
  }
}

glm::ivec2 Action::getDestinationLocation() const {
  switch (actionMode_) {
    case ActionMode::SRC_LOC_DST_LOC:
    case ActionMode::SRC_OBJ_DST_LOC:
      return destinationLocation_;
    case ActionMode::SRC_OBJ_DST_OBJ:
      return destinationObject_->getLocation();
    case ActionMode::SRC_OBJ_DST_VEC:
      return sourceObject_->getLocation() + vectorToDest_;
  }
}

glm::ivec2 Action::getVectorToDest() const {
  return vectorToDest_;
}

glm::ivec2 Action::getOrientationVector() const {
  return orientationVector_;
}

std::string Action::getActionName() const { return actionName_; }

uint32_t Action::getDelay() const {
  return delay_;
}

}  // namespace griddly