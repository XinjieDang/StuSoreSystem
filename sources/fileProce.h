#pragma once
#include"student.h"
#include"select.h"
#include"user.h"
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#define max_student 100
using namespace std;

class UsertF {                       //ѧ���ɼ���Ϣ������Դ�ļ�����
public:
	void setUserIn();               //�����û���Ϣ
	void setStuIn();                //����ѧ����Ϣ
	void lookDate();                //��ѯ�ļ�������ѧ����Ϣ
	void delStuInfo();              //ɾ���ļ���ѧ���ɼ���Ϣ
	void modStuInfo();              //�޸��ļ���ѧ���ɼ���Ϣ
	void buildStuInfo();            //����ѧ���ɼ����ı��ļ�     

	void buildSubInfo();            //���ɿγ̳ɼ������ı��ļ�
	int login();                    //�û���¼
	friend User;                    //���ļ�����ѧ����Ϣ
	void showTime();                //��ʾ����

private:
	fstream userFile;               //�ļ�����
};
typedef UsertF userFile;

void UsertF::setUserIn()
{

	User user;
	userFile.open("userInfo_date.txt", ios::app);
	cout << "���û�ע�᣺(����end����ע��)" << endl;
	while (user.registers()) {      //�����û���Ϣ�������txt�ļ�
		userFile << endl << user.userName << " " << user.passWord << " " << user.uRoot;
		cout << "�û�ע��ɹ���" << endl;

	}
	userFile.close();
}
void UsertF::setStuIn()
{

	Student student;
	userFile.open("stuInfo_date.txt", ios::app);
	cout << "����ѧ����Ϣ---����end����" << endl;
	while (student.inserStu()) {    //����ѧ����Ϣ�������txt�ļ�
		userFile << endl << student.stuName << " " << student.stuID;
		userFile << " " << student.subName << " " << student.subID;
		userFile << " " << student.subScore << " " << student.score;
		cout << "����ѧ����Ϣ�ɹ���" << endl;

	}
	userFile.close();
}

int UsertF::login()
{
	int u_root = 0;
	userFile.open("userInfo_date.txt", ios::in);
	if (userFile.fail())
		cout << "û���ҵ��û�����Ϣ.....��ȷ���Ƿ���ע��!" << endl;
	else
	{
		string userName, pwd;
		cout << "|�������û�����:|" << endl;
		cin >> userName;
		cout << "|�������û�����:|" << endl;
		char ch;
		bool flg = false;                       //����*�����غ������˸���
		 while (true)
		 {
			 while (ch = _getch())
			 {
				 if (ch == '\r')
				 {
					 flg = true;
					 break;
				 }

				 if (ch != 8)                  //�س���\b,ASCII����8
				 {                             //���ǻس���¼�� 
					 pwd += ch;                //string����������+=
					 putchar('*');             //����Ǻ� 
					
				 }
				 else
				 {
					 putchar('\b');           //�س�һ���ַ�
					 putchar(' ');            //��ʾ�ո��ڸ�
					 putchar('\b');           //�ٻس�һ��ȴ�¼�� 
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
				cout << "��¼�ɹ�!���ڽ���������......" << endl;
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
	SYSTEMTIME systemTime;//ʱ��ϵͳ����
	GetLocalTime(&systemTime);
	cout << "��ӭʹ�ñ�ϵͳ��"<< endl;
	cout << "�����ǣ�" << setw(22) << systemTime.wYear << "��" << systemTime.wMonth << "��" << systemTime.wDay << "��";
	cout << systemTime.wHour << "ʱ" << systemTime.wMinute << "��";
	switch (systemTime.wDayOfWeek)
	{
	case 0:
		week = "��";
		break;
	case 1:
		week = "һ";
		break;
	case 2:
		week = "��";
		break;
	case 3:
		week = "��";
		break;
	case 4:
		week = "��";
		break;
	case 5:
		week = "��";
		break;
	case 6:
		week = "��";
		break;
	}
	cout << "   ����";
	cout << week << setw(8) << endl;

}

void UsertF::lookDate() {
	userFile.open("stuInfo_date.txt", ios::in);
	if (userFile.fail())                              //��Ȿ���Ƿ����ѧ����Ϣ�ļ�
		cout << "û�м�⵽ѧ����Ϣ��" << endl;

	else {
		Student temp;
		cout << "����ѧ����Ϣ���£�"<<endl;
		while (!userFile.eof()) {                      //����Ƿ񵽴��ļ�ĩβ
			userFile >> temp.stuName>> temp.stuID >> temp.subName >> temp.subID >> temp.subScore>> temp.score;
			temp.showInfo();                           //����Ļ��ʾѧ����Ϣ
			cout << endl;
		}
		
	}
	userFile.close();
}

void UsertF::delStuInfo() {

	userFile.open("stuInfo_date.txt", ios::in);
	if (userFile.fail())                              //��Ȿ���Ƿ����ѧ����Ϣ�ļ�
		cout << "��ѧ�������ڣ�" << endl;
	else {
		string stuID;
		cout << "������Ҫɾ����ѧ��ѧ��:";
		cin >> stuID;
		cout << "��ȷ��Ҫɾ����(���롮1��ȷ�ϲ���������������ȡ���˲���):";
		char c;
		cin >> c;
		if (c == '1') {                              
			Student student;
			fstream temp("tempInfo_date.txt", ios::out); //�������м��ļ��ݴ�

			while (!userFile.eof()) {                   //ͨ���������м��ļ������Դ�ɾ�����ѧ����Ϣ
				userFile >> student.stuName >> student.stuID >> student.subName >> student.subID >> student.subScore >> student.score;
				if (student.stuID == stuID)
					cout << "ɾ���ɹ�!" << endl;

				else {                                 //����Ҫɾ���������棬����ȫ���ٴ����м��ļ�
					temp << endl << student.stuName << " " << student.stuID;
					temp << " " << student.subName << " " << student.subID;
					temp << " " << student.subScore << " " << student.score;
				}
			}

			temp.close();

		}
	}
	userFile.close();
	remove("stuInfo_date.txt");                          //ɾ��ԭ�ļ�
	rename("tempInfo_date.txt", "stuInfo_date.txt");     //�м��ļ����滻ԭ���ļ�
}

void UsertF::modStuInfo() {
	userFile.open("stuInfo_date.txt", ios::in);
	if (userFile.fail())
		cout << "��⵽��û��ѧ����Ϣ��" << endl;
	else {
		string stuID, subID;
		cout << "������Ҫ�޸�ѧ����ѧ��ѧ�ţ�:";
		cin >> stuID;
		cout << "��ȷ��Ҫ�޸ĸ�ѧ������Ϣ��(���롮1��ȷ�ϲ���������������ȡ���˲���):";
		char c;
		cin >> c;
		if (c == '1') {                             
			Student student;
			fstream temp("tempInfo_date.txt", ios::out);          //�������м��ļ��ݴ�
			while (!userFile.eof()) {
				userFile >> student.stuName >> student.stuID >> student.subName >> student.subID >> student.subScore >> student.score;
				if (student.stuID == stuID) {
					cout << "�������ѧ���µĿγ�����:" << endl;
					cin >> student.subName;
					cout << "�������ѧ���µĿγ̱��:" << endl;
					cin >> student.subID;
					cout << "�������ѧ���µĿγ�ѧ��:" << endl;
					cin >> student.subScore;
					cout << "�������ѧ���µĿγ̳ɼ�:" << endl;
					cin >> student.score;
					cout << "�޸���Ϣ�ɹ�!" << endl;
				}
				//д���м��ļ�
				temp << endl << student.stuName << " " << student.stuID;
				temp << " " << student.subName << " " << student.subID;
				temp << " " << student.subScore << " " << student.score;
			}
			temp.close();

		}
	}
	userFile.close();
	remove("stuInfo_date.txt");                      //ɾ��ԭ�ļ�
	rename("tempInfo_date.txt", "stuInfo_date.txt"); //�м��ļ��滻ԭ���ļ�

}

void UsertF::buildStuInfo()                          //����ѧ��ѧ�Ƴɼ���Ϣtxt
{
	userFile.open("stuInfo_date.txt", ios::in);
	if (userFile.fail())
		cout << "��⵽��û��ѧ����Ϣ��" << endl;
	else {
		string stuID;
		cout << "������Ҫ����ѧ�Ƴɼ���ѧ��ѧ�ţ�:";
		cin >> stuID; 
		if (stuID == "end")
		{
			cout << "���˳�����������" << endl;
			exit(1);

		}
		Student student;
		string fileName;                              //���������µ��ļ���
		fstream temp(stuID.c_str(), ios::out);//д,c_str()��������һ��ָ������C�ַ�����ָ��, �����뱾string����ͬ.
		while (!userFile.eof()) {
			userFile >> student.stuName >> student.stuID >> student.subName >> student.subID >> student.subScore >> student.score;
			if (student.stuID == stuID) {            //�����ļ��������ѯѧ����ID��ͬ��ѧ����Ϣ
				fileName = student.stuName;          //��ȡ��ѧ������
				temp << "�γ�����:   " << setw(8) << setiosflags(ios::right) << student.subName <<"   �γ̱��:"<< setw(8) << setiosflags(ios::right)<< student.subID;
				temp << "�γ�ѧ��:" << setw(3) << setiosflags(ios::right) << student.subScore << "   �ɼ�:" << setw(3) << setiosflags(ios::right)<< student.score << endl;
			}
		}

		temp.close();
		cout << "����txt�ļ��ɹ�!�����˳�......." << endl;
		fileName = fileName + ' ' + stuID + ".txt";  //�µ��ļ�������Ϊ��ѧ������ѧ��ID.txt��
		remove(fileName.c_str());                    //��ֹ����ͬ���ļ�����Ҫɾ��ͬ�����ļ�
		rename(stuID.c_str(), fileName.c_str());     //�����µ��ļ���Ϊѧ������+ѧ��ID
	}
	userFile.close();
}
int falg = 0;//�����ļ��ж�
void UsertF::buildSubInfo()//���ɵ����γ����е�ѧ���ɼ���Ϣtxt
{
	userFile.open("stuInfo_date.txt", ios::in);
	if (userFile.fail())
		cout << "��⵽��û��ѧ����Ϣ��" << endl;
	else {
		string stuSubID;
		cout << "������Ҫ�����Ŀγ̵ı�ţ�:";
		cin >> stuSubID;
		if (stuSubID == "end")
		{
			cout << "���˳�����������" << endl;
			exit(1);

		}
		Student student;
		string fileName;
		fstream temp(stuSubID.c_str(), ios::out);//,c_str()��������һ��ָ��γ̱�ź��ַ�����ָ��  ֻҪ�����ļ�¼��Ϣ����Ҫȫ������ָ��
		Student Student[max_student];                //����һ��ѧ���������飬����ѧ���ɼ�����
		int num = 0;

		while (!userFile.eof()) {                    //ѭ����������ѧ���ſε�ѧ����Ϣ
			userFile >> student.stuName >> student.stuID >> student.subName >> student.subID >> student.subScore >> student.score;
			if (student.subID == stuSubID) {
				fileName = student.subName;          //��ȡ�γ�����
				Student[num] = student;              //ÿ��ѧ�������������
				num++;//��¼��++
			}
		}

		for (int i = 0; i < num - 1; i++)            //ѧ���ɼ�������ð��
		{
			int k = i;
			for (int j = i + 1; j < num; j++) {
				if (Student[k].score < Student[j].score)
					k = j;
			}
			Students temp;
			temp = Student[i]; Student[i] = Student[k]; Student[k] = temp; //���� �Ӵ�С
		}
		for (int i = 0; i < num; i++) {
			temp << "����:" << setw(8) << setiosflags(ios::right) << Student[i].stuName << " ѧ��:" << setw(8) << setiosflags(ios::right) << Student[i].stuID;
			temp << " �γ�ѧ��:" << setw(3) << setiosflags(ios::right) << Student[i].subScore << " ѧ���ɼ�:" << setw(3) << setiosflags(ios::right) << Student[i].score << endl;
		}
		temp.close();
		cout << "����txt�ļ��ɹ�!���˳�......." << endl;
		fileName = fileName + ' ' + stuSubID + ".txt";//���ļ�������Ϊ���γ����ƿγ�ID.txt��
		remove(fileName.c_str());                     //��ֹ����ͬ���ļ�
		rename(stuSubID.c_str(), fileName.c_str());  //�����µ��ļ���Ϊ�γ�����+�γ̱��
	}
	userFile.close();
}