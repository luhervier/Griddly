#include <functional>
#include <iostream>
#include <memory>

#include "Griddly/Core/GDY/TerminationHandler.hpp"
#include "Mocks/Griddly/Core/MockGrid.cpp"
#include "Mocks/Griddly/Core/Players/MockPlayer.cpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::Eq;
using ::testing::Mock;
using ::testing::Pair;
using ::testing::Return;
using ::testing::UnorderedElementsAre;

namespace griddly {

TEST(TerminationHandlerTest, terminateOnPlayerScore) {
  auto mockGridPtr = std::shared_ptr<MockGrid>(new MockGrid());
  auto mockPlayer1Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());
  auto mockPlayer2Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());

  auto player1Score = std::make_shared<int32_t>(10);
  auto player2Score = std::make_shared<int32_t>(5);

  auto players = std::vector<std::shared_ptr<Player>>{mockPlayer1Ptr, mockPlayer2Ptr};

  EXPECT_CALL(*mockPlayer1Ptr, getId())
      .WillRepeatedly(Return(1));

  EXPECT_CALL(*mockPlayer2Ptr, getId())
      .WillRepeatedly(Return(2));

  EXPECT_CALL(*mockPlayer1Ptr, getScore())
      .WillRepeatedly(Return(player1Score));

  EXPECT_CALL(*mockPlayer2Ptr, getScore())
      .WillRepeatedly(Return(player2Score));

  auto terminationHandlerPtr = std::shared_ptr<TerminationHandler>(new TerminationHandler(mockGridPtr, players));

  TerminationConditionDefinition tcd;
  tcd.commandName = "eq";
  tcd.commandArguments = {"_score", "10"};
  tcd.state = TerminationState::WIN;
  terminationHandlerPtr->addTerminationCondition(tcd);

  auto terminationResult = terminationHandlerPtr->isTerminated();

  ASSERT_TRUE(terminationResult.terminated);
  ASSERT_THAT(terminationResult.playerStates, UnorderedElementsAre(Pair(1, TerminationState::WIN), Pair(2, TerminationState::LOSE)));
}

TEST(TerminationHandlerTest, terminateOnPlayerObjects0) {
  auto mockGridPtr = std::shared_ptr<MockGrid>(new MockGrid());
  auto mockPlayer1Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());
  auto mockPlayer2Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());

  auto player1Score = std::make_shared<int32_t>(0);
  auto player2Score = std::make_shared<int32_t>(0);

  auto players = std::vector<std::shared_ptr<Player>>{mockPlayer1Ptr, mockPlayer2Ptr};
  auto mockBaseCounter = std::unordered_map<uint32_t, std::shared_ptr<int32_t>>{{1, std::make_shared<int32_t>(3)}, {2, std::make_shared<int32_t>(0)}};

  EXPECT_CALL(*mockGridPtr, getObjectCounter(Eq("base")))
      .Times(1)
      .WillOnce(Return(mockBaseCounter));

  EXPECT_CALL(*mockPlayer1Ptr, getId())
      .WillRepeatedly(Return(1));

  EXPECT_CALL(*mockPlayer2Ptr, getId())
      .WillRepeatedly(Return(2));

  EXPECT_CALL(*mockPlayer1Ptr, getScore())
      .WillRepeatedly(Return(player1Score));

  EXPECT_CALL(*mockPlayer2Ptr, getScore())
      .WillRepeatedly(Return(player2Score));

  auto terminationHandlerPtr = std::shared_ptr<TerminationHandler>(new TerminationHandler(mockGridPtr, players));

  // Player with 0 bases will end the game and "lose"
  TerminationConditionDefinition tcd;
  tcd.commandName = "eq";
  tcd.commandArguments = {"base:count", "0"};
  tcd.state = TerminationState::LOSE;
  terminationHandlerPtr->addTerminationCondition(tcd);

  auto terminationResult = terminationHandlerPtr->isTerminated();

  ASSERT_TRUE(terminationResult.terminated);
  ASSERT_THAT(terminationResult.playerStates, UnorderedElementsAre(Pair(1, TerminationState::WIN), Pair(2, TerminationState::LOSE)));
}

TEST(TerminationHandlerTest, terminateOnGlobalVariable0) {
  auto mockGridPtr = std::shared_ptr<MockGrid>(new MockGrid());
  auto mockPlayer1Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());
  auto mockPlayer2Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());

  auto player1Score = std::make_shared<int32_t>(0);
  auto player2Score = std::make_shared<int32_t>(0);

  auto globalVariablePtr = std::make_shared<int32_t>(20);

  auto players = std::vector<std::shared_ptr<Player>>{mockPlayer1Ptr, mockPlayer2Ptr};

  std::unordered_map<std::string, std::shared_ptr<int32_t>> globalVariables;
  globalVariables["variable_name"] = globalVariablePtr;

  EXPECT_CALL(*mockGridPtr, getGlobalVariables())
      .Times(1)
      .WillOnce(Return(globalVariables));

  EXPECT_CALL(*mockPlayer1Ptr, getId())
      .WillRepeatedly(Return(1));

  EXPECT_CALL(*mockPlayer2Ptr, getId())
      .WillRepeatedly(Return(2));

  EXPECT_CALL(*mockPlayer1Ptr, getScore())
      .WillRepeatedly(Return(player1Score));

  EXPECT_CALL(*mockPlayer2Ptr, getScore())
      .WillRepeatedly(Return(player2Score));

  auto terminationHandlerPtr = std::shared_ptr<TerminationHandler>(new TerminationHandler(mockGridPtr, players));

  // Player with 0 bases will end the game and "lose"
  TerminationConditionDefinition tcd;
  tcd.commandName = "eq";
  tcd.commandArguments = {"variable_name", "20"};
  terminationHandlerPtr->addTerminationCondition(tcd);

  auto terminationResult = terminationHandlerPtr->isTerminated();

  ASSERT_TRUE(terminationResult.terminated);
  ASSERT_THAT(terminationResult.playerStates, UnorderedElementsAre(Pair(1, TerminationState::NONE), Pair(2, TerminationState::NONE)));
}

TEST(TerminationHandlerTest, terminateOnMaxTicks) {
  auto mockGridPtr = std::shared_ptr<MockGrid>(new MockGrid());
  auto mockPlayer1Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());
  auto mockPlayer2Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());

  auto player1Score = std::make_shared<int32_t>(0);
  auto player2Score = std::make_shared<int32_t>(0);

  auto tickCounter = std::make_shared<int32_t>(100);

  auto players = std::vector<std::shared_ptr<Player>>{mockPlayer1Ptr, mockPlayer2Ptr};

  EXPECT_CALL(*mockPlayer1Ptr, getId())
      .WillRepeatedly(Return(1));

  EXPECT_CALL(*mockPlayer2Ptr, getId())
      .WillRepeatedly(Return(2));

  EXPECT_CALL(*mockGridPtr, getTickCount())
      .Times(1)
      .WillOnce(Return(tickCounter));

  EXPECT_CALL(*mockPlayer1Ptr, getScore())
      .WillRepeatedly(Return(player1Score));

  EXPECT_CALL(*mockPlayer2Ptr, getScore())
      .WillRepeatedly(Return(player2Score));

  auto terminationHandlerPtr = std::shared_ptr<TerminationHandler>(new TerminationHandler(mockGridPtr, players));

  TerminationConditionDefinition tcd;
  tcd.commandName = "eq";
  tcd.commandArguments = {"_steps", "100"};
  tcd.state = TerminationState::NONE;
  terminationHandlerPtr->addTerminationCondition(tcd);

  auto terminationResult = terminationHandlerPtr->isTerminated();

  ASSERT_TRUE(terminationResult.terminated);
  ASSERT_THAT(terminationResult.playerStates, UnorderedElementsAre(Pair(1, TerminationState::NONE), Pair(2, TerminationState::NONE)));
}

TEST(TerminationHandlerTest, singlePlayer_differentId_win) {
  auto mockGridPtr = std::shared_ptr<MockGrid>(new MockGrid());
  auto mockPlayer1Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());

  auto players = std::vector<std::shared_ptr<Player>>{mockPlayer1Ptr};

  EXPECT_CALL(*mockPlayer1Ptr, getId())
      .WillRepeatedly(Return(1));

  auto playerObjectCounter = std::unordered_map<uint32_t, std::shared_ptr<int32_t>>{{0, std::make_shared<int32_t>(0)}};
  EXPECT_CALL(*mockGridPtr, getObjectCounter(Eq("environment_objects")))
      .Times(1)
      .WillOnce(Return(playerObjectCounter));

  auto terminationHandlerPtr = std::shared_ptr<TerminationHandler>(new TerminationHandler(mockGridPtr, players));

  TerminationConditionDefinition tcd;
  tcd.commandName = "eq";
  tcd.commandArguments = {"environment_objects:count", "0"};
  tcd.state = TerminationState::WIN;
  terminationHandlerPtr->addTerminationCondition(tcd);

  auto terminationResult = terminationHandlerPtr->isTerminated();

  ASSERT_TRUE(terminationResult.terminated);
  ASSERT_THAT(terminationResult.playerStates, UnorderedElementsAre(Pair(1, TerminationState::WIN)));
}

TEST(TerminationHandlerTest, singlePlayer_differentId_lose) {
  auto mockGridPtr = std::shared_ptr<MockGrid>(new MockGrid());
  auto mockPlayer1Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());

  auto players = std::vector<std::shared_ptr<Player>>{mockPlayer1Ptr};

  EXPECT_CALL(*mockPlayer1Ptr, getId())
      .WillRepeatedly(Return(1));

  auto playerObjectCounter = std::unordered_map<uint32_t, std::shared_ptr<int32_t>>{{0, std::make_shared<int32_t>(0)}};
  EXPECT_CALL(*mockGridPtr, getObjectCounter(Eq("environment_objects")))
      .Times(1)
      .WillOnce(Return(playerObjectCounter));

  auto terminationHandlerPtr = std::shared_ptr<TerminationHandler>(new TerminationHandler(mockGridPtr, players));

  TerminationConditionDefinition tcd;
  tcd.commandName = "eq";
  tcd.commandArguments = {"environment_objects:count", "0"};
  tcd.state = TerminationState::LOSE;
  terminationHandlerPtr->addTerminationCondition(tcd);

  auto terminationResult = terminationHandlerPtr->isTerminated();

  ASSERT_TRUE(terminationResult.terminated);
  ASSERT_THAT(terminationResult.playerStates, UnorderedElementsAre(Pair(1, TerminationState::LOSE)));
}

TEST(TerminationHandlerTest, singlePlayer_sameId_lose) {
  auto mockGridPtr = std::shared_ptr<MockGrid>(new MockGrid());
  auto mockPlayer1Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());

  auto players = std::vector<std::shared_ptr<Player>>{mockPlayer1Ptr};

  EXPECT_CALL(*mockPlayer1Ptr, getId())
      .WillRepeatedly(Return(1));

  auto playerObjectCounter = std::unordered_map<uint32_t, std::shared_ptr<int32_t>>{{1, std::make_shared<int32_t>(0)}};
  EXPECT_CALL(*mockGridPtr, getObjectCounter(Eq("player_objects")))
      .Times(1)
      .WillOnce(Return(playerObjectCounter));

  auto terminationHandlerPtr = std::shared_ptr<TerminationHandler>(new TerminationHandler(mockGridPtr, players));

  TerminationConditionDefinition tcd;
  tcd.commandName = "eq";
  tcd.commandArguments = {"player_objects:count", "0"};
  tcd.state = TerminationState::LOSE;
  terminationHandlerPtr->addTerminationCondition(tcd);

  auto terminationResult = terminationHandlerPtr->isTerminated();

  ASSERT_TRUE(terminationResult.terminated);
  ASSERT_THAT(terminationResult.playerStates, UnorderedElementsAre(Pair(1, TerminationState::LOSE)));
}

TEST(TerminationHandlerTest, singlePlayer_sameId_win) {
  auto mockGridPtr = std::shared_ptr<MockGrid>(new MockGrid());
  auto mockPlayer1Ptr = std::shared_ptr<MockPlayer>(new MockPlayer());

  auto players = std::vector<std::shared_ptr<Player>>{mockPlayer1Ptr};

  EXPECT_CALL(*mockPlayer1Ptr, getId())
      .WillRepeatedly(Return(1));

  auto playerObjectCounter = std::unordered_map<uint32_t, std::shared_ptr<int32_t>>{{1, std::make_shared<int32_t>(0)}};
  EXPECT_CALL(*mockGridPtr, getObjectCounter(Eq("player_objects")))
      .Times(1)
      .WillOnce(Return(playerObjectCounter));

  auto terminationHandlerPtr = std::shared_ptr<TerminationHandler>(new TerminationHandler(mockGridPtr, players));

  TerminationConditionDefinition tcd;
  tcd.commandName = "eq";
  tcd.commandArguments = {"player_objects:count", "0"};
  tcd.state = TerminationState::WIN;
  terminationHandlerPtr->addTerminationCondition(tcd);

  auto terminationResult = terminationHandlerPtr->isTerminated();

  ASSERT_TRUE(terminationResult.terminated);
  ASSERT_THAT(terminationResult.playerStates, UnorderedElementsAre(Pair(1, TerminationState::WIN)));
}

}  // namespace griddly