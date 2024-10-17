#ifndef _play_h
#define _play_h
#include <iostream>
#include "character.hpp"
#include "archive.hpp"
using namespace std;
void play(Character* ID)
{
    char enemy_name[16] = "Enemy";
    Character Enemy(50, 15, 7, 0, 1, 0,enemy_name);
    Character *p=ID;
    int attack_option=0;
    bool attack_finish=false;
    while(1){
        attack_finish=false;
        cout<<"请选择你的攻击方式"<<endl;
        cout<<"按1进行普通攻击，按2进行特殊攻击"<<endl;
        cout<<"特殊攻击CD还有"<<(*p).skillCD<<"秒"<<endl;
        do{
            cin>>attack_option;
            switch(attack_option){
            case 1:
                (*p).attack(&Enemy);
                if((*p).skillCD>0) (*p).skillCD--;
                attack_finish=true;
                break;
            case 2:
                if((*p).skillCD==0){
                    (*p).skill(&Enemy);
                    attack_finish=true;
                }
                else cout<<"技能还在冷却中"<<endl;
                break;
            default:
                cout<<"无效输入！"<<endl;
            }
        }while(!attack_finish);
        cout<<"敌人还有"<<Enemy.HP<<"点血！"<<endl;
        if(Enemy.HP<=0){
        	cout<<"敌人死了！"<<endl;
            (*p).EXP+=1;
            (*p).LevelUp();
            Enemy.~Character();
            break;
        }
        Enemy.attack(ID);
        cout<<"你还有"<<(*p).HP<<"点血！"<<endl;
        if((*p).HP<=0){
            cout<<"你死了!"<<endl;
            (*p).HP=(*p).HPMAX;
            break;
        }
    }
    save(*p);
}
#endif
