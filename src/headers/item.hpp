#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
public:
    enum SpecialEffectType {
        NONE,
        HEAL,
        TEMPORARY_ATTRIBUTE_BOOST,
        GAIN_EXP,
        OBTAIN_OTHER_ITEM
    };

private:
    int id;
    std::string name;
    bool weapon;
    int attackBonus;
    int defenseBonus;
    int speedBonus;
    SpecialEffectType specialEffectType;
    int specialEffectValue;
    int otherItemId;

public:
    // 构造函数
    Item(int itemId, const std::string& itemName, bool isWeapon, int attack = 0, int defense = 0, int speed = 0, SpecialEffectType effectType = NONE, int effectValue = 0, int otherItem = -1)
        : id(itemId), name(itemName), weapon(isWeapon), attackBonus(attack), defenseBonus(defense), speedBonus(speed), specialEffectType(effectType), specialEffectValue(effectValue), otherItemId(otherItem) {}

    // 获取物品ID
    int getId() const {
        return id;
    }

    // 设置物品ID
    void setId(int newId) {
        id = newId;
    }

    // 获取物品名称
    std::string getName() const {
        return name;
    }

    // 设置物品名称
    void setName(const std::string& newName) {
        name = newName;
    }

    // 判断物品是否为武器
    bool isWeapon() const {
        return weapon;
    }

    // 获取攻击力加成
    int getAttackBonus() const {
        return attackBonus;
    }

    // 获取防御力加成
    int getDefenseBonus() const {
        return defenseBonus;
    }

    // 获取速度加成
    int getSpeedBonus() const {
        return speedBonus;
    }

    // 获取特殊效果类型
    SpecialEffectType getSpecialEffectType() const {
        return specialEffectType;
    }

    // 获取特殊效果值
    int getSpecialEffectValue() const {
        return specialEffectValue;
    }

    // 获取其他物品ID
    int getOtherItemId() const {
        return otherItemId;
    }
};

#endif // ITEM_HPP