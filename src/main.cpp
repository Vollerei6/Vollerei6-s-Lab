#include <iostream>
#include <string>
#include "character.hpp"
#include "play.hpp"
#include "color.hpp"

using namespace std;

//主程序部分 
int main()
{
    #ifdef _DEBUG
    cout << "目前处于debug模式" << endl;
    #endif // _DEBUG

    rgb_init();
    string playername;
    cout <<white()<< "Enter your name\n";
    cin >> playername;
    Character Player(playername);
    int status=0;
    Player.Load();
    while(true)
    {
        cout<<"欢迎来到绿神话-吗喽\n";
		cout<<"请选择你要进入的页面\n";
		cout<<"输入1：进入游戏\n";
		//cout<<"输入2：查看说明"<<endl;
        cout<<"输入2：查看角色\n";
        cout<<"输入3：存档退出\n";
        cout << "输入4：获得武器\n";
		cin>>status;
        switch(status){
        case 1:play(Player); break;
        case 2:Player.getInfo(); break;
        case 3:exitGame(Player);break;
        case 4:getWeapon(Player); break;
        default:cout<<"输入无效！"<<endl;
        }
        if(status==3) break;
    }
    Player.~Character();
    return 0;
}
