//该头文件用于存档
#ifndef _archive_h
#define _archive_h
#include <iostream>
#include <fstream>
#include "character.hpp"
using namespace std;

/*inline void data_search(Character ID)//数据查询
{
    cout<<"你的最大生命值是："<<ID.HPMAX<<endl;
    cout<<"你的攻击力是："<<ID.ATK<<endl;
    cout<<"你的防御力是："<<ID.DEF<<endl;
    cout<<"你的经验值是："<<ID.EXP<<endl;
    cout<<"你的等级是："<<ID.LV<<endl;
}
inline void archive(Character *ID)//作为Character类的一个成员函数存在，方便进行赋值
{
    Character *p=ID;
    (*p).Load();
        data_search(*ID);
        cout<<"欢迎回来，"<<(*p).name<<endl;
    }//存档已经存在就读档，然后把数据赋值给Player对象
    else{
        char data[16];
        infile.close();
        ofstream outfile("archive.dat");
        cout<<"欢迎到来，新玩家！你的名字是什么？"<<endl;
        cin.getline(data,16);
        if (outfile.is_open())
        {
            outfile << 100 << endl;//血量100
            outfile << 20 << endl;//攻击力20
            outfile << 10 << endl;//防御力10
            outfile << 0 << endl;//初始经验0
            outfile << 1 << endl;//初始等级1
            outfile << data << endl;//名字
            outfile << 10 << endl;//金钱初始为10
            strcpy((*p).name, data);
            outfile.close();
        }
    }//没有存档就新建一个 新角色数值赋值已经在主程序里搞定了
}

inline void save(Character ID)
//存档
{
    ofstream outfile("archive.dat");
    outfile<<ID.HPMAX<<endl;//最大血量100
    outfile<<ID.ATK<<endl;//攻击力20
    outfile<<ID.DEF<<endl;//防御力10
    outfile<<ID.EXP<<endl;//初始经验0
    outfile<<ID.LV<<endl;//初始等级1
    outfile<<ID.name<<endl;//名字
    outfile.close();
}
inline void exit(Character ID)
//退出并存档
{
    save(ID);
    cout<<"再见，"<<ID.name<<endl;
}

*/
#endif
