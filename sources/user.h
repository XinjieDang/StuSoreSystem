#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
class User
{
public:
	bool registers();          //�û�ע��
	friend class UsertF;       //ѧ���ļ�������Ա��
	friend class meauView;     //�˵���Ԫ��
private:
	string  userName;          //�û���
	string passWord;           //����
	int uRoot;                 //�û�����Ȩ��

};

bool User::registers() //ע��
{
	cout << "������--�û�����:  |  ����:  |  �û�����:(1Ϊ����Ա��2Ϊѧ����  " << endl;
	cin >> userName;
	if (userName == "end")
	{
		cout << "���˳�ע��" << endl;
		return 0;

	}

	cin >> passWord >> uRoot;
	fstream userFile1("userInfo_date.txt", ios::in);//��Ȿ���û���Ϣ
	User temp;
	while (!userFile1.eof()) {                        //�����Ƿ�����ͬ���û��ظ�ע��
		userFile1 >> temp.userName >> temp.passWord >> temp.uRoot;//��ȡ
		if (temp.userName == userName&&temp.passWord!=passWord) {
			cout << "���û��Ѵ��ڣ�������ע��" << endl;
			userFile1.close();
			return false;
		}
	}
	userFile1.close();
	return true;
}
