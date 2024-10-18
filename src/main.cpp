#include <iostream>
#include <vector>
#include "headers/character.hpp"
#include "headers/item.hpp"

int main() {
    // 创建一个角色
    Character player("Player", 100, 10, 5, 5, 0, 1, 0);

    // 创建一个物品
    Item sword(1, "Sword", true, 5, 0, 0, Item::NONE, 0, -1);

    // 输出角色信息
    std::cout << "Player: " << player.getName() << std::endl;
    std::cout << "HP: " << player.getHealth() << std::endl;
    std::cout << "Attack: " << player.getAttack() << std::endl;
    std::cout << "Defense: " << player.getDefense() << std::endl;
    std::cout << "Speed: " << player.getSpeed() << std::endl;
    std::cout << "Level: " << player.getLevel() << std::endl;
    std::cout << "Exp: " << player.getExp() << std::endl;

    // 输出物品信息
    std::cout << "Item: " << sword.getName() << std::endl;
    std::cout << "Attack Bonus: " << sword.getAttackBonus() << std::endl;
    std::cout << "Defense Bonus: " << sword.getDefenseBonus() << std::endl;
    std::cout << "Speed Bonus: " << sword.getSpeedBonus() << std::endl;

    return 0;
}
