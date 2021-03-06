#include "Griddly/Core/GDY/Objects/Object.hpp"
#include "Griddly/Core/Grid.hpp"
#include "Griddly/Core/Observers/VectorObserver.hpp"
#include "Mocks/Griddly/Core/GDY/Objects/MockObject.cpp"
#include "Mocks/Griddly/Core/MockGrid.cpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::AnyNumber;
using ::testing::ElementsAre;
using ::testing::ElementsAreArray;
using ::testing::Eq;
using ::testing::Mock;
using ::testing::Pair;
using ::testing::Return;

namespace griddly {

void vector_mockGridFunctions(std::shared_ptr<MockGrid>& mockGridPtr, std::shared_ptr<MockObject>& mockAvatarObjectPtr) {
  // make a 5 by 5 grid with an avatar in the center and some stuff around it, there are 4 types of object
  // "4" is the avatar type
  // 11111
  // 12031
  // 12431
  // 13021
  // 11111

  auto mockObject1Ptr = std::shared_ptr<MockObject>(new MockObject());
  EXPECT_CALL(*mockObject1Ptr, getObjectId()).WillRepeatedly(Return(0));
  auto mockObject2Ptr = std::shared_ptr<MockObject>(new MockObject());
  EXPECT_CALL(*mockObject2Ptr, getObjectId()).WillRepeatedly(Return(1));
  auto mockObject3Ptr = std::shared_ptr<MockObject>(new MockObject());
  EXPECT_CALL(*mockObject3Ptr, getObjectId()).WillRepeatedly(Return(2));

  EXPECT_CALL(*mockAvatarObjectPtr, getObjectId()).WillRepeatedly(Return(3));
  EXPECT_CALL(*mockAvatarObjectPtr, getLocation()).WillRepeatedly(Return(glm::ivec2{2, 2}));

  EXPECT_CALL(*mockGridPtr, getUniqueObjectCount).WillRepeatedly(Return(4));

  // A horrible way of making a mock grid but fuck it
  ON_CALL(*mockGridPtr, getObjectsAt).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{}));

  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{0, 0}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{1, 0}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{2, 0}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{3, 0}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{4, 0}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));

  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{0, 1}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{1, 1}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject2Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{2, 1}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{3, 1}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject3Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{4, 1}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));

  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{0, 2}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{1, 2}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject2Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{2, 2}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockAvatarObjectPtr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{3, 2}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject3Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{4, 2}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));

  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{0, 3}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{1, 3}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject3Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{2, 3}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{3, 3}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject2Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{4, 3}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));

  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{0, 4}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{1, 4}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{2, 4}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{3, 4}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
  ON_CALL(*mockGridPtr, getObjectsAt(Eq(glm::ivec2{4, 4}))).WillByDefault(Return(std::map<uint32_t, std::shared_ptr<Object>>{{0, mockObject1Ptr}}));
}

void runVectorObserverTest(ObserverConfig observerConfig,
                           Direction avatarDirection,
                           std::vector<uint32_t> expectedObservationShape,
                           std::vector<uint32_t> expectedObservationStride,
                           uint8_t* expectedData,
                           bool trackAvatar) {
  auto mockGridPtr = std::shared_ptr<MockGrid>(new MockGrid());
  std::shared_ptr<VectorObserver> blockObserver = std::shared_ptr<VectorObserver>(new VectorObserver(mockGridPtr));

  auto mockAvatarObjectPtr = std::shared_ptr<MockObject>(new MockObject());
  auto orientation = DiscreteOrientation(avatarDirection);
  EXPECT_CALL(*mockAvatarObjectPtr, getObjectOrientation).WillRepeatedly(Return(orientation));

  vector_mockGridFunctions(mockGridPtr, mockAvatarObjectPtr);

  blockObserver->init(observerConfig);

  
  if (trackAvatar) {
    blockObserver->setAvatar(mockAvatarObjectPtr);
  }
  auto resetObservation = blockObserver->reset();
  ASSERT_EQ(blockObserver->getShape(), expectedObservationShape);
  ASSERT_EQ(blockObserver->getStrides(), expectedObservationStride);
  auto updateObservation = blockObserver->update();

  size_t dataLength = blockObserver->getShape()[0] * blockObserver->getShape()[1] * blockObserver->getShape()[2];

  auto resetObservationPointer = std::vector<uint8_t>(resetObservation.get(), resetObservation.get() + dataLength);
  auto updateObservationPointer = std::vector<uint8_t>(updateObservation.get(), updateObservation.get() + dataLength);

  ASSERT_THAT(resetObservationPointer, ElementsAreArray(expectedData, dataLength));
  ASSERT_THAT(updateObservationPointer, ElementsAreArray(expectedData, dataLength));
}

TEST(VectorObserverTest, defaultObserverConfig) {
  ObserverConfig config = {
      5,
      5,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::NONE, {4, 5, 5}, {1, 4, 20}, expectedData[0][0], false);
}

TEST(VectorObserverTest, partialObserver) {
  ObserverConfig config = {
      3,
      5,
      0,
      0,
      false};

  uint8_t expectedData[5][3][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}},
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::NONE, {4, 3, 5}, {1, 4, 12}, expectedData[0][0], false);
}

TEST(VectorObserverTest, defaultObserverConfig_trackAvatar) {
  ObserverConfig config = {
      5,
      5,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::NONE, {4, 5, 5}, {1, 4, 20}, expectedData[0][0], false);
}

TEST(VectorObserverTest, defaultObserverConfig_trackAvatar_rotateWithAvatar_NONE) {
  ObserverConfig config = {
      5,
      5,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::NONE, {4, 5, 5}, {1, 4, 20}, expectedData[0][0], false);
}

TEST(VectorObserverTest, defaultObserverConfig_trackAvatar_UP) {
  ObserverConfig config = {
      5,
      5,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::UP, {4, 5, 5}, {1, 4, 20}, expectedData[0][0], false);
}
TEST(VectorObserverTest, defaultObserverConfig_trackAvatar_RIGHT) {
  ObserverConfig config = {
      5,
      5,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::RIGHT, {4, 5, 5}, {1, 4, 20}, expectedData[0][0], false);
}
TEST(VectorObserverTest, defaultObserverConfig_trackAvatar_DOWN) {
  ObserverConfig config = {
      5,
      5,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::DOWN, {4, 5, 5}, {1, 4, 20}, expectedData[0][0], false);
}
TEST(VectorObserverTest, defaultObserverConfig_trackAvatar_LEFT) {
  ObserverConfig config = {
      5,
      5,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::LEFT, {4, 5, 5}, {1, 4, 20}, expectedData[0][0], false);
}

TEST(VectorObserverTest, partialObserver_trackAvatar_NONE) {
  ObserverConfig config = {
      5,
      3,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::NONE, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

TEST(VectorObserverTest, partialObserver_trackAvatar_UP) {
  ObserverConfig config = {
      5,
      3,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::UP, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

TEST(VectorObserverTest, partialObserver_trackAvatar_RIGHT) {
  ObserverConfig config = {
      5,
      3,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::RIGHT, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

TEST(VectorObserverTest, partialObserver_trackAvatar_DOWN) {
  ObserverConfig config = {
      5,
      3,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::DOWN, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}
TEST(VectorObserverTest, partialObserver_trackAvatar_LEFT) {
  ObserverConfig config = {
      5,
      3,
      0,
      0,
      false};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::LEFT, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

TEST(VectorObserverTest, partialObserver_withOffset_trackAvatar_NONE) {
  ObserverConfig config = {
      5,
      3,
      1,
      1,
      false};

  uint8_t expectedData[5][5][4] = {
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}},
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}}};

  runVectorObserverTest(config, Direction::NONE, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

TEST(VectorObserverTest, partialObserver_withOffset_trackAvatar_UP) {
  ObserverConfig config = {
      5,
      3,
      1,
      1,
      false};

  uint8_t expectedData[5][5][4] = {
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}},
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}}};

  runVectorObserverTest(config, Direction::UP, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

TEST(VectorObserverTest, partialObserver_withOffset_trackAvatar_RIGHT) {
  ObserverConfig config = {
      5,
      3,
      1,
      1,
      false};

  uint8_t expectedData[5][5][4] = {
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}},
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}}};

  runVectorObserverTest(config, Direction::RIGHT, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

TEST(VectorObserverTest, partialObserver_withOffset_trackAvatar_DOWN) {
  ObserverConfig config = {
      5,
      3,
      1,
      1,
      false};

  uint8_t expectedData[5][5][4] = {
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}},
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}}};

  runVectorObserverTest(config, Direction::DOWN, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}
TEST(VectorObserverTest, partialObserver_withOffset_trackAvatar_LEFT) {
  ObserverConfig config = {
      5,
      3,
      1,
      1,
      false};

  uint8_t expectedData[5][5][4] = {
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}},
      {{0, 0, 0, 0}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}}};

  runVectorObserverTest(config, Direction::LEFT, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

TEST(VectorObserverTest, partialObserver_withOffset_trackAvatar_rotateWithAvatar_NONE) {
  ObserverConfig config = {
      5,
      3,
      0,
      1,
      true};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::NONE, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}


TEST(VectorObserverTest, partialObserver_withOffset_trackAvatar_rotateWithAvatar_UP) {
  ObserverConfig config = {
      5,
      3,
      0,
      1,
      true};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::UP, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}


TEST(VectorObserverTest, partialObserver_withOffset_trackAvatar_rotateWithAvatar_RIGHT) {
  ObserverConfig config = {
      5,
      3,
      0,
      1,
      true};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::RIGHT, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

TEST(VectorObserverTest, partialObserver_withOffset_trackAvatar_rotateWithAvatar_DOWN) {
  ObserverConfig config = {
      5,
      3,
      0,
      1,
      true};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}, {0, 1, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::DOWN, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

TEST(VectorObserverTest, partialObserver_withOffset_trackAvatar_rotateWithAvatar_LEFT) {
  ObserverConfig config = {
      5,
      3,
      0,
      1,
      true};

  uint8_t expectedData[5][5][4] = {
      {{1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 1, 0}, {0, 1, 0, 0}, {0, 1, 0, 0}, {1, 0, 0, 0}},
      {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 0, 0}, {1, 0, 0, 0}}};

  runVectorObserverTest(config, Direction::LEFT, {4, 5, 3}, {1, 4, 20}, expectedData[0][0], true);
}

}  // namespace griddly