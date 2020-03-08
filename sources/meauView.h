#pragma once
#include <time.h>
//#include<windows.h>
#include<string>;
#include<iostream>
#include"fileProce.h"
#include "user.h"
#include "select.h"
using namespace std;
class meauView
{
public:
	int loginMeau();          //登录菜单
	int loginCheck();         //登录密码检测控制
	int mainMeau();           //主菜单
private:
	int root;                 //用户权限

};

userFile usf;
Select sech;
User userR;
string key;                  //定义全局按键

int  meauView::loginMeau()
{

	while (1)
	{
		std::right;
		Sleep(20);
		cout << "\t\t——————————————————"  << setw(2) << "———---" << endl;
		Sleep(180);
		cout << "\t\t|             欢迎使用学生成绩信息管理系统"          <<setw(10)<< "|"<<endl;
		Sleep(150);
		Sleep(20);
		cout << "\t\t——————————————————"  << setw(4) << "————" << endl;
		cout << "\t\t| \t\t请先注册或直接登录  ！              "<< setw(4) << "|" << endl;
		Sleep(200);
		cout << "\t\t| \t\t1.注册                           " <<  setw(15) << "|" << endl;
		Sleep(150);
		cout << "\t\t| \t\t2.登录                           " <<  setw(15) << "|" << endl;
		Sleep(200);
		cout << "\t\t| \t\t3.退出系统                          " <<  setw(10) << "|" << endl;
		Sleep(150);
		cout << "\t\t|________________________________________________________________" << setw(1)<<"|"<<endl;
		Sleep(200);
		cout << "您要做什么？(请按下序号):";
		cin >> key;
		if (key == "1")
		{
			usf.setUserIn();
		}
		else if (key == "2")
		{
			root = loginCheck();      //登录校验若获取到用户权限值（1或2），则根据权限值显示对应的菜单
			if (root != 0)
			{
				mainMeau();           //显示系统主菜单

			}

		}

		else if (key == "3")
			break;
	}

	system("pause");
	return -1;
}

int  meauView::mainMeau()               //系统主菜单
{

	if (root == 1)                     //权限为1 显示管理员的菜单
	{
		while (1)
		{
			std::right;

			Sleep(20);
			cout << "\t\t——————————————————" <<  setw(2) << "—————" << endl;
			Sleep(180);
			cout << "\t\t|             欢迎使用学生成绩信息管理系统" <<  setw(13) << "|" << endl;
			Sleep(20);
			cout << "\t\t——————————————————" <<  setw(9) << "—————" << endl;
			Sleep(150);
			cout << "\t\t* \t\t--您是管理员用户！--                   " <<  setw(6) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t1.新增学生信息                            " <<  setw(5) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t2.修改学生信息                           " << setw(6) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t3.删除学生信息                           " <<  setw(6) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t4.根据不同条件查询                     " <<  setw(6) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t5.查看所有学生信息                     " <<setw(6) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t6.导出学生成绩txt文件            " << setw(12) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t7.导出课程成绩排名txt文件         " <<  setw(9) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t8.退出登录                       " <<  setw(16) << "*" << endl;
			Sleep(150);
			cout << "\t\t*___________________________________________________________________" <<  setw(1) << "*" << endl;
			Sleep(200);
			usf.showTime();
			cout << "您要做什么？(请按下序号):";
			cin >> key;
			if (key == "1")
				usf.setStuIn();
			else if (key == "2")
				usf.modStuInfo();

			else if (key == "3")
				usf.delStuInfo();

			else if (key == "4")
				sech.select();

			else if (key == "5")
				usf.lookDate();

			else if (key== "6")
				usf.buildStuInfo();

			else if (key == "7")
				usf.buildSubInfo();
			else if (key == "8")
				break;
		}
	}

	if (root == 2)                   //权限为2 显示学生用户的菜单
	{
		while (1)
		{
			std::right;
			Sleep(20);
			cout << "\t\t——————————————————" <<  setw(2) << "—————" << endl;
			Sleep(180);
			cout << "\t\t|             欢迎使用学生成绩信息管理系统" <<  setw(13) << "|" << endl;
			Sleep(20);
			cout << "\t\t——————————————————" <<  setw(9) << "—————" << endl;
			Sleep(150);
			cout << "\t\t* \t\          ---您是学生用户！--                   " << setw(6) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t1.根据不同条件查询                     " <<  setw(6) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t2.查看所有学生信息                     " <<  setw(6) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t3.导出学生成绩txt文件            " << setw(12) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t4.导出课程成绩排名txt文件         " << setw(9) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t5.退出登录                       " << setw(16) << "*" << endl;
			Sleep(150);
			cout << "\t\t*___________________________________________________________________" <<setw(1) << "*" << endl;
			Sleep(200);
			usf.showTime();              //显示今天日期
			cout << "您要做什么？(请按下序号):";
			cin >> key;
	        if (key == "1")
		    sech.select();
	        else if (key == "2")
		    usf.lookDate();
	        else if (key == "3")
		    usf.buildStuInfo();
	        else if (key == "4")
		    usf.buildSubInfo();
			else if (key == "5")
				break;
		}
	}
	system("pause");
	return -1;
}

int meauView::loginCheck()             //用户登录校验
{
	userFile usfAll;
	int chock = 0;
	for (int i = 4; i >= 0; i--)
	{
		chock = usfAll.login();      //若获取到用户登录的权限的值，则表明登录成功
		cout << endl;
		if (chock == 1)
		{
			return 1;
		}
		else if (chock == 2)
		{
			return 2;

		}
		else                          //登录失败
		{

			cout << "用户名或密码错误,你还有" << i << "次机会登录" << endl;
		}
	}
	return -1;

}






