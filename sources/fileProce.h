#pragma once
#include"student.h"
#include"select.h"
#include"user.h"
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define max_student 100
using namespace std;

class UsertF {                       //学生成绩信息本地资源文件操作
public:
	void setUserIn();               //新增用户信息
	void setStuIn();                //新增学生信息
	void lookDate();                //查询文件中所有学生信息
	void delStuInfo();              //删除文件中学生成绩信息
	void modStuInfo();              //修改文件中学生成绩信息
	void buildStuInfo();            //生成学生成绩单文本文件     

	void buildSubInfo();            //生成课程成绩排名文本文件
	int login();                    //用户登录
	friend User;                    //向文件输入学生信息
	void showTime();                //显示日期

private:
	fstream userFile;               //文件操作
};
typedef UsertF userFile;

void UsertF::setUserIn()
{

	User user;
	userFile.open("userInfo_date.txt", ios::app);
	cout << "新用户注册：(输入end结束注册)" << endl;
	while (user.registers()) {      //输入用户信息并输出到txt文件
		userFile << endl << user.userName << " " << user.passWord << " " << user.uRoot;
		cout << "用户注册成功！" << endl;

	}
	userFile.close();
}
void UsertF::setStuIn()
{

	Student student;
	userFile.open("stuInfo_date.txt", ios::app);
	cout << "新增学生信息---输入end结束" << endl;
	while (student.inserStu()) {    //输入学生信息并输出到txt文件
		userFile << endl << student.stuName << " " << student.stuID;
		userFile << " " << student.subName << " " << student.subID;
		userFile << " " << student.subScore << " " << student.score;
		cout << "新增学生信息成功！" << endl;

	}
	userFile.close();
}

int UsertF::login()
{
	int u_root = 0;
	userFile.open("userInfo_date.txt", ios::in);
	if (userFile.fail())
		cout << "没有找到用户的信息.....请确认是否已注册!" << endl;
	else
	{
		string userName, pwd;
		cout << "|请输入用户姓名:|" << endl;
		cin >> userName;
		cout << "|请输入用户密码:|" << endl;
		char ch;
		bool flg = false;                       //输入*号隐藏和密码退格处理
		 while (true)
		 {
			 while (ch = _getch())
			 {
				 if (ch == '\r')
				 {
					 flg = true;
					 break;
				 }

				 if (ch != 8)                  //回撤是\b,ASCII码是8
				 {                             //不是回撤就录入 
					 pwd += ch;                //string对象重载了+=
					 putchar('*');             //输出星号 
					
				 }
				 else
				 {
					 putchar('\b');           //回撤一个字符
					 putchar(' ');            //显示空格掩盖
					 putchar('\b');           //再回撤一格等待录入 
				 }
			 }

			 if (flg)
				 break;
		 }
		User user;
		while (!userFile.eof())   
		{
			userFile >> user.userName >> user.passWord >> user.uRoot;
			if (user.userName == userName && user.passWord == pwd)
			{
				cout << "登录成功!正在进入主界面......" << endl;
				cout << endl;
				u_root = user.uRoot;
				return u_root;

			}

		}
	}
	userFile.close();
}
void UsertF::showTime()
{
	string week = " ";
	std::right;
	SYSTEMTIME systemTime;//时间系统函数
	GetLocalTime(&systemTime);
	cout << "欢迎使用本系统！"<< endl;
	cout << "今天是：" << setw(22) << systemTime.wYear << "年" << systemTime.wMonth << "月" << systemTime.wDay << "日";
	cout << systemTime.wHour << "时" << systemTime.wMinute << "分";
	switch (systemTime.wDayOfWeek)
	{
	case 0:
		week = "日";
		break;
	case 1:
		week = "一";
		break;
	case 2:
		week = "二";
		break;
	case 3:
		week = "三";
		break;
	case 4:
		week = "四";
		break;
	case 5:
		week = "五";
		break;
	case 6:
		week = "六";
		break;
	}
	cout << "   星期";
	cout << week << setw(8) << endl;

}

void UsertF::lookDate() {
	userFile.open("stuInfo_date.txt", ios::in);
	if (userFile.fail())                              //检测本地是否存在学生信息文件
		cout << "没有检测到学生信息！" << endl;

	else {
		Student temp;
		cout << "所有学生信息如下！"<<endl;
		while (!userFile.eof()) {                      //检测是否到达文件末尾
			userFile >> temp.stuName>> temp.stuID >> temp.subName >> temp.subID >> temp.subScore>> temp.score;
			temp.showInfo();                           //向屏幕显示学生信息
			cout << endl;
		}
		
	}
	userFile.close();
}

void UsertF::delStuInfo() {

	userFile.open("stuInfo_date.txt", ios::in);
	if (userFile.fail())                              //检测本地是否存在学生信息文件
		cout << "该学生不存在！" << endl;
	else {
		string stuID;
		cout << "请输入要删除的学生学号:";
		cin >> stuID;
		cout << "你确认要删除吗？(输入‘1’确认操作，输入其他则取消此操作):";
		char c;
		cin >> c;
		if (c == '1') {                              
			Student student;
			fstream temp("tempInfo_date.txt", ios::out); //建立立中间文件暂存

			while (!userFile.eof()) {                   //通过跳过向中间文件输入以此删除相关学生信息
				userFile >> student.stuName >> student.stuID >> student.subName >> student.subID >> student.subScore >> student.score;
				if (student.stuID == stuID)
					cout << "删除成功!" << endl;

				else {                                 //除了要删除那条不存，其他全部再存入中间文件
					temp << endl << student.stuName << " " << student.stuID;
					temp << " " << student.subName << " " << student.subID;
					temp << " " << student.subScore << " " << student.score;
				}
			}

			temp.close();

		}
	}
	userFile.close();
	remove("stuInfo_date.txt");                          //删除原文件
	rename("tempInfo_date.txt", "stuInfo_date.txt");     //中间文件名替换原来文件
}

void UsertF::modStuInfo() {
	userFile.open("stuInfo_date.txt", ios::in);
	if (userFile.fail())
		cout << "检测到还没有学生信息！" << endl;
	else {
		string stuID, subID;
		cout << "请输入要修改学生的学生学号！:";
		cin >> stuID;
		cout << "你确认要修改该学生的信息吗(输入‘1’确认操作，输入其他则取消此操作):";
		char c;
		cin >> c;
		if (c == '1') {                             
			Student student;
			fstream temp("tempInfo_date.txt", ios::out);          //建立立中间文件暂存
			while (!userFile.eof()) {
				userFile >> student.stuName >> student.stuID >> student.subName >> student.subID >> student.subScore >> student.score;
				if (student.stuID == stuID) {
					cout << "请输入该学生新的课程名称:" << endl;
					cin >> student.subName;
					cout << "请输入该学生新的课程编号:" << endl;
					cin >> student.subID;
					cout << "请输入该学生新的课程学分:" << endl;
					cin >> student.subScore;
					cout << "请输入该学生新的课程成绩:" << endl;
					cin >> student.score;
					cout << "修改信息成功!" << endl;
				}
				//写入中间文件
				temp << endl << student.stuName << " " << student.stuID;
				temp << " " << student.subName << " " << student.subID;
				temp << " " << student.subScore << " " << student.score;
			}
			temp.close();

		}
	}
	userFile.close();
	remove("stuInfo_date.txt");                      //删除原文件
	rename("tempInfo_date.txt", "stuInfo_date.txt"); //中间文件替换原来文件

}

void UsertF::buildStuInfo()                          //生成学生学科成绩信息txt
{
	userFile.open("stuInfo_date.txt", ios::in);
	if (userFile.fail())
		cout << "检测到还没有学生信息！" << endl;
	else {
		string stuID;
		cout << "请输入要导出学科成绩的学生学号！:";
		cin >> stuID; 
		if (stuID == "end")
		{
			cout << "已退出导出操作！" << endl;
			exit(1);

		}
		Student student;
		string fileName;                              //用来设置新的文件名
		fstream temp(stuID.c_str(), ios::out);//写,c_str()函数返回一个指向正规C字符串的指针, 内容与本string串相同.
		while (!userFile.eof()) {
			userFile >> student.stuName >> student.stuID >> student.subName >> student.subID >> student.subScore >> student.score;
			if (student.stuID == stuID) {            //查找文件中与待查询学生的ID相同的学生信息
				fileName = student.stuName;          //获取该学生姓名
				temp << "课程名称:   " << setw(8) << setiosflags(ios::right) << student.subName <<"   课程编号:"<< setw(8) << setiosflags(ios::right)<< student.subID;
				temp << "课程学分:" << setw(3) << setiosflags(ios::right) << student.subScore << "   成绩:" << setw(3) << setiosflags(ios::right)<< student.score << endl;
			}
		}

		temp.close();
		cout << "生成txt文件成功!正在退出......." << endl;
		fileName = fileName + ' ' + stuID + ".txt";  //新的文件名设置为“学生姓名学生ID.txt”
		remove(fileName.c_str());                    //防止存在同名文件所以要删除同名的文件
		rename(stuID.c_str(), fileName.c_str());     //更改新的文件名为学生姓名+学生ID
	}
	userFile.close();
}
int falg = 0;//生成文件判断
void UsertF::buildSubInfo()//生成单个课程所有的学生成绩信息txt
{
	userFile.open("stuInfo_date.txt", ios::in);
	if (userFile.fail())
		cout << "检测到还没有学生信息！" << endl;
	else {
		string stuSubID;
		cout << "请输入要导出的课程的编号！:";
		cin >> stuSubID;
		if (stuSubID == "end")
		{
			cout << "已退出导出操作！" << endl;
			exit(1);

		}
		Student student;
		string fileName;
		fstream temp(stuSubID.c_str(), ios::out);//,c_str()函数返回一个指向课程编号号字符串的指针  只要包含的记录信息，不要全部，用指针
		Student Student[max_student];                //建立一个学生对象数组，便于学生成绩排序
		int num = 0;

		while (!userFile.eof()) {                    //循环遍历所有学这门课的学生信息
			userFile >> student.stuName >> student.stuID >> student.subName >> student.subID >> student.subScore >> student.score;
			if (student.subID == stuSubID) {
				fileName = student.subName;          //获取课程名称
				Student[num] = student;              //每个学生对象存入数组
				num++;//记录数++
			}
		}

		for (int i = 0; i < num - 1; i++)            //学生成绩排序降序冒泡
		{
			int k = i;
			for (int j = i + 1; j < num; j++) {
				if (Student[k].score < Student[j].score)
					k = j;
			}
			Students temp;
			temp = Student[i]; Student[i] = Student[k]; Student[k] = temp; //交换 从大到小
		}
		for (int i = 0; i < num; i++) {
			temp << "姓名:" << setw(8) << setiosflags(ios::right) << Student[i].stuName << " 学号:" << setw(8) << setiosflags(ios::right) << Student[i].stuID;
			temp << " 课程学分:" << setw(3) << setiosflags(ios::right) << Student[i].subScore << " 学生成绩:" << setw(3) << setiosflags(ios::right) << Student[i].score << endl;
		}
		temp.close();
		cout << "生成txt文件成功!已退出......." << endl;
		fileName = fileName + ' ' + stuSubID + ".txt";//将文件名设置为“课程名称课程ID.txt”
		remove(fileName.c_str());                     //防止存在同名文件
		rename(stuSubID.c_str(), fileName.c_str());  //更改新的文件名为课程名称+课程编号
	}
	userFile.close();
}