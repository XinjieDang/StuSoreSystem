#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

class Student {
public:
	bool inserStu();                //新增学生所有信息
	void showInfo()const;           //显示所有的信息
	friend class  UsertF;
	friend class  Select;

private:

	string stuName;              //学生姓名
	string stuID;                //学号
	string subName;              //课程名称
	string subID;                //课程编号
	int subScore;                //课程学分
	double score;                //学生成绩
};
typedef Student Students;

bool Student::inserStu() {
	cout << "请输入-- 学生姓名:  |  学号:  |  课程名称:  |  课程编号:  |  课程学分  :|  学生成绩:" << endl;
	cin >> stuName;
	if (stuName == "end")
	{
		cout << "已退出新增操作！" << endl;
		return 0;

	}
	cin >> stuID >> subName >> subID >> subScore >> score;

	fstream stuFile1("stuInfo_date.txt", ios::in);   //打开本地学生信息
	Student temp;
	while (!stuFile1.eof()) {                        //判断是否有重复添加的学生
		stuFile1 >> temp.stuName >> temp.stuID >> temp.subName >> temp.subID >> temp.subScore >> temp.score;
		if (temp.stuID == stuID) {                   //判断是否有相同的学号
			cout << "该学生信息已存在，请勿重复添加！" << endl;
			stuFile1.close();
			return false;
		}
	}
	stuFile1.close();
	return true;
}

void Student::showInfo()const {                 //以表格格式化显示学生的信息
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\t学生姓名:" << setw(1) << setiosflags(ios::right) << "  \t\t" << stuName << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\t学号:" << setw(1) << setiosflags(ios::right) << "  \t\t" << stuID << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\t课程名称:" << setw(1) << setiosflags(ios::right) << "  \t\t" << subName << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\t课程编号:" << setw(1) << setiosflags(ios::right) << "  \t\t" << subID << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\t课程学分:" << setw(1) << setiosflags(ios::right) << "  \t\t" << subScore << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\t学生成绩:" << setw(1) << setiosflags(ios::right) << "  \t\t" << score << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
}