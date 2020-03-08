#pragma once
#include"student.h"
#include<string>
using namespace std;

class Select {//查询文件中的信息类
public:
	void searchStuID();           //通过学生学号查询
	void searchSubID();           //通过课程编号查询
	void searchSubSore();         //通过课程学分查询
	void searchScore();           //根据成绩区间查询
	void vagueSearch();           //关键字模糊查询
	void select();                //查询类接口
	fstream stuFile;              //文件操作
};
string showId;

void Select::searchStuID() {
	string ID;
    showId = "0";
	cout << "请输入你要查找的学生学号!:";
	cin >> ID;
	while (!stuFile.eof())
	{
		Student temp;
		stuFile >> temp.stuName >> temp.stuID >> temp.subName >> temp.subID >> temp.subScore >> temp.score;
		if (temp.stuID == ID)
		{
			showId = "1";
			temp.showInfo();                      //找到输出到屏幕
		}
			
	}
	if (showId != "1")
	{
		cout << "找不到相关的信息!正在退出......" << endl;
	}
}

void Select::searchSubID() {
	string ID;
    showId = "0";
	cout << "请输入你要查找课程的课程编号!:";
	cin >> ID;
	while (!stuFile.eof())
	{
		Student temp;
		stuFile >> temp.stuName >> temp.stuID >> temp.subName >> temp.subID >> temp.subScore >> temp.score;
		if (temp.subID == ID)
		{
			showId = "1";
			temp.showInfo();
		}	
	}
	if (showId != "1")
	{
		cout << "找不到相关的信息!正在退出......" << endl;
	}
}

void Select::searchSubSore() {
	int subScore;
	showId = "0";
	cout << "请输入你要查找课程的学分!:";
	cin >> subScore;
	while (!stuFile.eof()) 
	{
		Student temp;
		stuFile >> temp.stuName >> temp.stuID >> temp.subName >> temp.subID >> temp.subScore >> temp.score;
		if (temp.subScore == subScore)
		{
			showId = "1";
			temp.showInfo();
		}
	}
	if (showId != "1")
	{
		cout << "找不到相关的信息!正在退出......" << endl;
	}
}

void Select::vagueSearch() {
	string Select; 	           //查询关键字
	int flaga = 1, flagb = 1;  //查询判定输出是否成功信息
	cout << "请输入搜索关键字!";
	cin >> Select;
	while (!stuFile.eof()) {
		Student temp;
		stuFile >> temp.stuName >> temp.stuID >> temp.subName >> temp.subID >> temp.subScore >> temp.score;
		bool judgeStuName = 1, judgeSubName = 1;  //学生名，课程名、做标记
		int length = Select.size();
		for (int i = 0; i < length; i++) {        //查询模糊词中的字符是否在学生名中出现
			if (temp.stuName.find(Select.substr(i, 1)) == -1) { //判断模糊词中的字符是否有下标位置，有则存在，
				//substr获得字符串selct中从第i位开始的长度为1的字符串
				judgeStuName = 0;
				flaga = 0;
				break;
			}
		}
		for (int i = 0; i < length; i++) {       //查询模糊词中的字符是否在课程名中出现
			if (temp.subName.find(Select.substr(i, 1)) == -1) {
				judgeSubName = 0;
				flagb = 0;
				break;
			}
		}
		if (judgeStuName || judgeSubName)      //课程名或学生名中有一个找的到则显示到屏幕上
			temp.showInfo();
	}
	
	if (flaga==0 && flagb==0)
	{
		cout << "找不到相关信息!正在退出..." << endl;
	}

}

void Select::searchScore() {
	string subject;
	double lowerLimit, upperLimit;                  //定义成绩区间上限和下限
	cout << "请输入搜索范围的课程编号(如果是要查所有课程，请输入all):";
	cin >> subject;
	cout << "请分别输入要搜索的成绩区间(先输入下限，再输入上限):";
	cin >> lowerLimit >> upperLimit;                 
	while (!stuFile.eof()) {
		Student temp;
		stuFile >> temp.stuName >> temp.stuID >> temp.subName >> temp.subID >> temp.subScore >> temp.score;
		if (subject == "all") {
			if (temp.score >= lowerLimit && temp.score <= upperLimit) //全部的课程
				temp.showInfo();
		}
		else {
			if (temp.score >= lowerLimit && temp.score <= upperLimit && subject == temp.subID)//指定的课程编号
				temp.showInfo();
		}
	}
}

void Select::select()//查询菜单
{
	stuFile.open("stuInfo_date.txt", ios::in);
	if (stuFile.fail())                              //检测本地是否存在学生信息文件
		cout << "检测到还没有学生信息！" << endl;
	else {
		std::right;
		cout << "\t\t———————————————————— " << endl;
		cout << "\t\t* \t\t     查询菜单 " << setw(26) << " * " << endl;
		cout << "\t\t*——————————————————---* " << endl;
		cout << "\t\t* \t\t1.通过学生学号查询                * " << endl;
		cout << "\t\t* \t\t2.通过课程编号查询                * " << endl;
		cout << "\t\t* \t\t3.通过课程学分查询                * " << endl;
		cout << "\t\t* \t\t4.根据成绩区间查询" << setw(18)<<"* " << endl;
		cout << "\t\t* \t\t5.通过关键字查询  " << setw(19) <<"* " << endl;
		cout << "\t\t* \t\t6.退出查询                            * " << endl;
		cout << "\t\t*_________________________________________________________*" << endl;
		cout << "您要如何查询？(请按下序号):";
		string key;
		cin >> key;
		if (key == "1")
			searchStuID();

		else if (key == "2")
			searchSubID();

		else if (key == "3")
			searchSubSore();

		else if (key == "4")
			searchScore();

		else if (key == "5")
			vagueSearch();

		else if (key == "6")//直接退出
			exit(1);
	}
	stuFile.close();
}
