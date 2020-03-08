#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class User
{
public:
	bool registers();          //用户注册
	friend class UsertF;       //学生文件操作友员类
	friend class meauView;     //菜单友元类
private:
	string  userName;          //用户名
	string passWord;           //密码
	int uRoot;                 //用户类型权限

};

bool User::registers() //注册
{
	cout << "请输入--用户姓名:  |  密码:  |  用户类型:(1为管理员，2为学生）  " << endl;
	cin >> userName;
	if (userName == "end")
	{
		cout << "已退出注册" << endl;
		return 0;

	}

	cin >> passWord >> uRoot;
	fstream userFile1("userInfo_date.txt", ios::in);//检测本地用户信息
	User temp;
	while (!userFile1.eof()) {                        //查找是否有相同的用户重复注册
		userFile1 >> temp.userName >> temp.passWord >> temp.uRoot;//提取
		if (temp.userName == userName&&temp.passWord!=passWord) {
			cout << "该用户已存在，请重新注册" << endl;
			userFile1.close();
			return false;
		}
	}
	userFile1.close();
	return true;
}
