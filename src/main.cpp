﻿#include <iostream>
#include <string>
#include "character.hpp"
#include "play.hpp"
#include "archive.hpp"
using namespace std;
//void archive();
//void play();
//void data_search();
//void exit();

//主程序部分 
int main()
{
    string playername = "Player";
    Character Player(playername);
    Player.Load();
    int status=0;
    while(true)
    {
        cout<<"欢迎来到绿神话-吗喽"<<endl;
		cout<<"请选择你要进入的页面"<<endl;
		cout<<"输入1：进入游戏"<<endl;
		cout<<"输入2：查看说明"<<endl;
		cout<<"输入3：存档退出"<<endl;
        cout << "输入4：查看角色" << endl;
		cin>>status;
        switch(status){
        //case 1:play(&Player);break;
        //case 2:data_search(Player);break;
        //case 3:exit(Player);break;
        default:cout<<"输入无效！"<<endl;
        }
        if(status==3) break;
    }
    Player.~Character();
    return 0;
}
