#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <vector>
class Character {
private:
    int health;
    int attack;
    int defense;
    int speed;
    int weapon;
    int level;
    int exp;
    std::vector<int> backpack;

public:
    // 构造函数
    Character(int initialHealth) : health(initialHealth) {}

    // 获取当前血量
    int getHealth() const {
        return health;
    }

    // 设置新的血量
    void setHealth(int newHealth) {
        health = newHealth;
    }

    // 受到伤害，减少血量
    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) {
            health = 0; // 确保血量不会低于0
        }
    }

    // 恢复血量
    void heal(int amount) {
        health += amount;
    }

        // 获取攻击力
    int getAttackPower() const {
        return attack;
    }

    // 设置攻击力
    void setAttackPower(int newAttackPower) {
        attack = newAttackPower;
    }

    // 获取防御力
    int getDefense() const {
        return defense;
    }

    // 设置防御力
    void setDefense(int newDefense) {
        defense = newDefense;
    }

    // 获取速度
    int getSpeed() const {
        return speed;
    }

    // 设置速度
    void setSpeed(int newSpeed) {
        speed = newSpeed;
    }

    // 获取武器
    int getWeapon() const {
        return speed;
    }

    // 设置武器
    void setWeapon(int newSpeed) {
        speed = newSpeed;
    }

    // 获取等级
    int getLevel() const {
        return level;
    }

    // 设置等级
    void setLevel(int newLevel) {
        level = newLevel;
    }

    // 获取经验值
    int getExp() const {
        return exp;
    }

    // 设置经验值
    void setExp(int newExp) {
        exp = newExp;
    }

    // 获取背包
    std::vector<int> getBackpack() const {
        return backpack;
    }

    // 添加物品到背包
    void addToBackpack(int item) {
        backpack.push_back(item);
    }

    // 从背包中移除物品
    void removeFromBackpack(int item) {
        for (int i = 0; i < backpack.size(); i++) {
            if (backpack[i] == item) {
                backpack.erase(backpack.begin() + i);
                break;
            }
        }
    }
};

#endif // CHARACTER_HPP