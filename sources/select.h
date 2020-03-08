#pragma once
#include"student.h"
#include<string>
using namespace std;

class Select {//��ѯ�ļ��е���Ϣ��
public:
	void searchStuID();           //ͨ��ѧ��ѧ�Ų�ѯ
	void searchSubID();           //ͨ���γ̱�Ų�ѯ
	void searchSubSore();         //ͨ���γ�ѧ�ֲ�ѯ
	void searchScore();           //���ݳɼ������ѯ
	void vagueSearch();           //�ؼ���ģ����ѯ
	void select();                //��ѯ��ӿ�
	fstream stuFile;              //�ļ�����
};
string showId;

void Select::searchStuID() {
	string ID;
    showId = "0";
	cout << "��������Ҫ���ҵ�ѧ��ѧ��!:";
	cin >> ID;
	while (!stuFile.eof())
	{
		Student temp;
		stuFile >> temp.stuName >> temp.stuID >> temp.subName >> temp.subID >> temp.subScore >> temp.score;
		if (temp.stuID == ID)
		{
			showId = "1";
			temp.showInfo();                      //�ҵ��������Ļ
		}
			
	}
	if (showId != "1")
	{
		cout << "�Ҳ�����ص���Ϣ!�����˳�......" << endl;
	}
}

void Select::searchSubID() {
	string ID;
    showId = "0";
	cout << "��������Ҫ���ҿγ̵Ŀγ̱��!:";
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
		cout << "�Ҳ�����ص���Ϣ!�����˳�......" << endl;
	}
}

void Select::searchSubSore() {
	int subScore;
	showId = "0";
	cout << "��������Ҫ���ҿγ̵�ѧ��!:";
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
		cout << "�Ҳ�����ص���Ϣ!�����˳�......" << endl;
	}
}

void Select::vagueSearch() {
	string Select; 	           //��ѯ�ؼ���
	int flaga = 1, flagb = 1;  //��ѯ�ж�����Ƿ�ɹ���Ϣ
	cout << "�����������ؼ���!";
	cin >> Select;
	while (!stuFile.eof()) {
		Student temp;
		stuFile >> temp.stuName >> temp.stuID >> temp.subName >> temp.subID >> temp.subScore >> temp.score;
		bool judgeStuName = 1, judgeSubName = 1;  //ѧ�������γ����������
		int length = Select.size();
		for (int i = 0; i < length; i++) {        //��ѯģ�����е��ַ��Ƿ���ѧ�����г���
			if (temp.stuName.find(Select.substr(i, 1)) == -1) { //�ж�ģ�����е��ַ��Ƿ����±�λ�ã�������ڣ�
				//substr����ַ���selct�дӵ�iλ��ʼ�ĳ���Ϊ1���ַ���
				judgeStuName = 0;
				flaga = 0;
				break;
			}
		}
		for (int i = 0; i < length; i++) {       //��ѯģ�����е��ַ��Ƿ��ڿγ����г���
			if (temp.subName.find(Select.substr(i, 1)) == -1) {
				judgeSubName = 0;
				flagb = 0;
				break;
			}
		}
		if (judgeStuName || judgeSubName)      //�γ�����ѧ��������һ���ҵĵ�����ʾ����Ļ��
			temp.showInfo();
	}
	
	if (flaga==0 && flagb==0)
	{
		cout << "�Ҳ��������Ϣ!�����˳�..." << endl;
	}

}

void Select::searchScore() {
	string subject;
	double lowerLimit, upperLimit;                  //����ɼ��������޺�����
	cout << "������������Χ�Ŀγ̱��(�����Ҫ�����пγ̣�������all):";
	cin >> subject;
	cout << "��ֱ�����Ҫ�����ĳɼ�����(���������ޣ�����������):";
	cin >> lowerLimit >> upperLimit;                 
	while (!stuFile.eof()) {
		Student temp;
		stuFile >> temp.stuName >> temp.stuID >> temp.subName >> temp.subID >> temp.subScore >> temp.score;
		if (subject == "all") {
			if (temp.score >= lowerLimit && temp.score <= upperLimit) //ȫ���Ŀγ�
				temp.showInfo();
		}
		else {
			if (temp.score >= lowerLimit && temp.score <= upperLimit && subject == temp.subID)//ָ���Ŀγ̱��
				temp.showInfo();
		}
	}
}

void Select::select()//��ѯ�˵�
{
	stuFile.open("stuInfo_date.txt", ios::in);
	if (stuFile.fail())                              //��Ȿ���Ƿ����ѧ����Ϣ�ļ�
		cout << "��⵽��û��ѧ����Ϣ��" << endl;
	else {
		std::right;
		cout << "\t\t���������������������������������������� " << endl;
		cout << "\t\t* \t\t     ��ѯ�˵� " << setw(26) << " * " << endl;
		cout << "\t\t*������������������������������������---* " << endl;
		cout << "\t\t* \t\t1.ͨ��ѧ��ѧ�Ų�ѯ                * " << endl;
		cout << "\t\t* \t\t2.ͨ���γ̱�Ų�ѯ                * " << endl;
		cout << "\t\t* \t\t3.ͨ���γ�ѧ�ֲ�ѯ                * " << endl;
		cout << "\t\t* \t\t4.���ݳɼ������ѯ" << setw(18)<<"* " << endl;
		cout << "\t\t* \t\t5.ͨ���ؼ��ֲ�ѯ  " << setw(19) <<"* " << endl;
		cout << "\t\t* \t\t6.�˳���ѯ                            * " << endl;
		cout << "\t\t*_________________________________________________________*" << endl;
		cout << "��Ҫ��β�ѯ��(�밴�����):";
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

		else if (key == "6")//ֱ���˳�
			exit(1);
	}
	stuFile.close();
}
