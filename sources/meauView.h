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
	int loginMeau();          //��¼�˵�
	int loginCheck();         //��¼���������
	int mainMeau();           //���˵�
private:
	int root;                 //�û�Ȩ��

};

userFile usf;
Select sech;
User userR;
string key;                  //����ȫ�ְ���

int  meauView::loginMeau()
{

	while (1)
	{
		std::right;
		Sleep(20);
		cout << "\t\t������������������������������������"  << setw(2) << "������---" << endl;
		Sleep(180);
		cout << "\t\t|             ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ"          <<setw(10)<< "|"<<endl;
		Sleep(150);
		Sleep(20);
		cout << "\t\t������������������������������������"  << setw(4) << "��������" << endl;
		cout << "\t\t| \t\t����ע���ֱ�ӵ�¼  ��              "<< setw(4) << "|" << endl;
		Sleep(200);
		cout << "\t\t| \t\t1.ע��                           " <<  setw(15) << "|" << endl;
		Sleep(150);
		cout << "\t\t| \t\t2.��¼                           " <<  setw(15) << "|" << endl;
		Sleep(200);
		cout << "\t\t| \t\t3.�˳�ϵͳ                          " <<  setw(10) << "|" << endl;
		Sleep(150);
		cout << "\t\t|________________________________________________________________" << setw(1)<<"|"<<endl;
		Sleep(200);
		cout << "��Ҫ��ʲô��(�밴�����):";
		cin >> key;
		if (key == "1")
		{
			usf.setUserIn();
		}
		else if (key == "2")
		{
			root = loginCheck();      //��¼У������ȡ���û�Ȩ��ֵ��1��2���������Ȩ��ֵ��ʾ��Ӧ�Ĳ˵�
			if (root != 0)
			{
				mainMeau();           //��ʾϵͳ���˵�

			}

		}

		else if (key == "3")
			break;
	}

	system("pause");
	return -1;
}

int  meauView::mainMeau()               //ϵͳ���˵�
{

	if (root == 1)                     //Ȩ��Ϊ1 ��ʾ����Ա�Ĳ˵�
	{
		while (1)
		{
			std::right;

			Sleep(20);
			cout << "\t\t������������������������������������" <<  setw(2) << "����������" << endl;
			Sleep(180);
			cout << "\t\t|             ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ" <<  setw(13) << "|" << endl;
			Sleep(20);
			cout << "\t\t������������������������������������" <<  setw(9) << "����������" << endl;
			Sleep(150);
			cout << "\t\t* \t\t--���ǹ���Ա�û���--                   " <<  setw(6) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t1.����ѧ����Ϣ                            " <<  setw(5) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t2.�޸�ѧ����Ϣ                           " << setw(6) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t3.ɾ��ѧ����Ϣ                           " <<  setw(6) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t4.���ݲ�ͬ������ѯ                     " <<  setw(6) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t5.�鿴����ѧ����Ϣ                     " <<setw(6) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t6.����ѧ���ɼ�txt�ļ�            " << setw(12) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t7.�����γ̳ɼ�����txt�ļ�         " <<  setw(9) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t8.�˳���¼                       " <<  setw(16) << "*" << endl;
			Sleep(150);
			cout << "\t\t*___________________________________________________________________" <<  setw(1) << "*" << endl;
			Sleep(200);
			usf.showTime();
			cout << "��Ҫ��ʲô��(�밴�����):";
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

	if (root == 2)                   //Ȩ��Ϊ2 ��ʾѧ���û��Ĳ˵�
	{
		while (1)
		{
			std::right;
			Sleep(20);
			cout << "\t\t������������������������������������" <<  setw(2) << "����������" << endl;
			Sleep(180);
			cout << "\t\t|             ��ӭʹ��ѧ���ɼ���Ϣ����ϵͳ" <<  setw(13) << "|" << endl;
			Sleep(20);
			cout << "\t\t������������������������������������" <<  setw(9) << "����������" << endl;
			Sleep(150);
			cout << "\t\t* \t\          ---����ѧ���û���--                   " << setw(6) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t1.���ݲ�ͬ������ѯ                     " <<  setw(6) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t2.�鿴����ѧ����Ϣ                     " <<  setw(6) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t3.����ѧ���ɼ�txt�ļ�            " << setw(12) << "*" << endl;
			Sleep(200);
			cout << "\t\t* \t\t4.�����γ̳ɼ�����txt�ļ�         " << setw(9) << "*" << endl;
			Sleep(150);
			cout << "\t\t* \t\t5.�˳���¼                       " << setw(16) << "*" << endl;
			Sleep(150);
			cout << "\t\t*___________________________________________________________________" <<setw(1) << "*" << endl;
			Sleep(200);
			usf.showTime();              //��ʾ��������
			cout << "��Ҫ��ʲô��(�밴�����):";
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

int meauView::loginCheck()             //�û���¼У��
{
	userFile usfAll;
	int chock = 0;
	for (int i = 4; i >= 0; i--)
	{
		chock = usfAll.login();      //����ȡ���û���¼��Ȩ�޵�ֵ���������¼�ɹ�
		cout << endl;
		if (chock == 1)
		{
			return 1;
		}
		else if (chock == 2)
		{
			return 2;

		}
		else                          //��¼ʧ��
		{

			cout << "�û������������,�㻹��" << i << "�λ����¼" << endl;
		}
	}
	return -1;

}






