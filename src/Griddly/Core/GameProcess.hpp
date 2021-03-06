#pragma once

#include <memory>
#include <vector>

#include "GDY/GDYFactory.hpp"
#include "GDY/TerminationHandler.hpp"
#include "Grid.hpp"
#include "Observers/Observer.hpp"

namespace griddly {

class Player;

struct ActionResult {
  std::unordered_map<uint32_t, TerminationState> playerStates;
  bool terminated;
  std::vector<int> rewards;
};

class GameProcess : public std::enable_shared_from_this<GameProcess> {
 public:
  GameProcess(std::shared_ptr<Grid> grid, std::shared_ptr<Observer> observer, std::shared_ptr<GDYFactory> gdyFactory);

  virtual std::shared_ptr<uint8_t> observe(uint32_t playerId) const;

  virtual ActionResult performActions(uint32_t playerId, std::vector<std::shared_ptr<Action>> actions) = 0;

  virtual void addPlayer(std::shared_ptr<Player> player);

  virtual void init();
  virtual std::shared_ptr<uint8_t> reset();

  bool isStarted();

  virtual std::string getProcessName() const;

  std::shared_ptr<Grid> getGrid();
  std::shared_ptr<Observer> getObserver();

  virtual uint32_t getNumPlayers() const;

  void release();

  virtual ~GameProcess() = 0;

 protected:
  std::vector<std::shared_ptr<Player>> players_;
  std::shared_ptr<Grid> grid_;
  std::shared_ptr<GDYFactory> gdyFactory_;
  std::shared_ptr<TerminationHandler> terminationHandler_;

  // Game process can have its own observer so we can monitor the game regardless of the player
  std::shared_ptr<Observer> observer_;

  bool isStarted_ = false;
  bool isInitialized_ = false;
 private:

  ObserverConfig getObserverConfig(ObserverType observerType) const;
};
}  // namespace griddly