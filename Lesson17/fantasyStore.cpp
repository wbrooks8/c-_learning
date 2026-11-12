//
// Created by kyle on 11/12/26.
//

#include "fantasyStore.h"

#include "../Random.h"
#include <array>
#include <iostream>
#include <ostream>
#include <string_view>
#include <vector>

namespace Potion {
enum Type {
  healing,
  mana,
  speed,
  invisibility,
  maxStoreItems,
};

static constexpr std::string_view potionToStringView(Potion::Type t) {
  switch (t) {
  case Potion::Type::healing:
    return "healing";
  case Potion::Type::mana:
    return "mana";
  case Potion::Type::speed:
    return "speed";
  case Potion::Type::invisibility:
    return "invisibility";
  default:
    return "";
  }
}

constexpr std::array cost{20, 30, 12, 50};

constexpr std::array<std::string_view, 4> types = {
    potionToStringView(Potion::Type::healing),
    potionToStringView(Potion::Type::mana),
    potionToStringView(Potion::Type::speed),
    potionToStringView(Potion::Type::invisibility),
};

static_assert(
    std::size(types) ==
    maxStoreItems); // ensure 'all' contains the correct number of enumerators

static_assert(std::size(cost) == maxStoreItems);

} // namespace Potion

class Player {
private:
  static constexpr int s_minStartingGold{80};
  static constexpr int s_maxStartingGold{120};

  std::string m_name;
  std::array<int, Potion::maxStoreItems> m_inventory{};
  int m_gold{};

public:
  explicit Player(std::string_view name)
      : m_name(name),
        m_gold(Random::get(s_minStartingGold, s_maxStartingGold)) {}
  [[nodiscard]] const std::string &getName() const { return m_name; }
  [[nodiscard]] int getGold() const { return m_gold; }
  void setGold(int gold) { m_gold = gold; }
  void addItemToInventory(int item) { m_inventory[item]++; }
  std::array<int, Potion::maxStoreItems>& getInventory() { return m_inventory; }
};

void shop(auto &costArr, auto &typesArr, auto &player) {

  while (true) {
    std::cout << "Here is our selection for today: " << std::endl;
    for (int i{0}; i < Potion::maxStoreItems; i++) {
      std::cout << i << ") " << typesArr[i] << " cost " << costArr[i]
                << std::endl;
    }
    std::cout
        << "Enter the number of the potion you'd like to buy, or 'q' to quit: "
        << std::endl;

    char choice{};
    std::cin >> choice;

    while (choice != 'q' && choice != 'Q' &&
           (choice < '0' || choice > '0' + (Potion::maxStoreItems - 1))) {
      std::cout << "That is an invalid input. Please try again." << std::endl;
      std::cin >> choice;
    }

    if (choice == 'q' || choice == 'Q') {
      break; // leave before touching any array
    }

    int index{choice - '0'};

    if (player.getGold() >= costArr[index]) {
      player.addItemToInventory(index);
      player.setGold(player.getGold() - costArr[index]);
      std::cout << "You purchased a potion of " << typesArr[index]
                << ".   You have " << player.getGold() << " left." << std::endl;
    } else {
      std::cout << "You can not afford that." << std::endl;
    }
  }

  std::cout << "Your inventory contains:" << std::endl;
  auto inventory = player.getInventory();
  for (int i {}; i < inventory.size(); i++) {
    if (inventory[i] > 0) {
      std::cout << inventory[i] << "x potion of " << typesArr[i] << std::endl;
    }
  }
  std::cout << "You escaped with " << player.getGold() << " gold remaining." << std::endl;

}

void runStore() {
  std::cout << "Welcome to Roscoe's potion emporium!" << std::endl;
  std::cout << "Enter your name: " << std::endl;
  std::string playerName;
  std::cin >> playerName;
  Player player1(playerName);
  std::cout << "Hello, " << player1.getName() << ", you have "
            << player1.getGold() << " gold." << std::endl;

  shop(Potion::cost, Potion::types, player1);

  std::cout << "\nThanks for shopping at Roscoe's potion emporium!\n";
}