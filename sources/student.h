#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

class Student {
public:
	bool inserStu();                //����ѧ��������Ϣ
	void showInfo()const;           //��ʾ���е���Ϣ
	friend class  UsertF;
	friend class  Select;

private:

	string stuName;              //ѧ������
	string stuID;                //ѧ��
	string subName;              //�γ�����
	string subID;                //�γ̱��
	int subScore;                //�γ�ѧ��
	double score;                //ѧ���ɼ�
};
typedef Student Students;

bool Student::inserStu() {
	cout << "������-- ѧ������:  |  ѧ��:  |  �γ�����:  |  �γ̱��:  |  �γ�ѧ��  :|  ѧ���ɼ�:" << endl;
	cin >> stuName;
	if (stuName == "end")
	{
		cout << "���˳�����������" << endl;
		return 0;

	}
	cin >> stuID >> subName >> subID >> subScore >> score;

	fstream stuFile1("stuInfo_date.txt", ios::in);   //�򿪱���ѧ����Ϣ
	Student temp;
	while (!stuFile1.eof()) {                        //�ж��Ƿ����ظ���ӵ�ѧ��
		stuFile1 >> temp.stuName >> temp.stuID >> temp.subName >> temp.subID >> temp.subScore >> temp.score;
		if (temp.stuID == stuID) {                   //�ж��Ƿ�����ͬ��ѧ��
			cout << "��ѧ����Ϣ�Ѵ��ڣ������ظ���ӣ�" << endl;
			stuFile1.close();
			return false;
		}
	}
	stuFile1.close();
	return true;
}

void Student::showInfo()const {                 //�Ա���ʽ����ʾѧ������Ϣ
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\tѧ������:" << setw(1) << setiosflags(ios::right) << "  \t\t" << stuName << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\tѧ��:" << setw(1) << setiosflags(ios::right) << "  \t\t" << stuID << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\t�γ�����:" << setw(1) << setiosflags(ios::right) << "  \t\t" << subName << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\t�γ̱��:" << setw(1) << setiosflags(ios::right) << "  \t\t" << subID << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\t�γ�ѧ��:" << setw(1) << setiosflags(ios::right) << "  \t\t" << subScore << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
	cout << "  \t\tѧ���ɼ�:" << setw(1) << setiosflags(ios::right) << "  \t\t" << score << endl;
	cout << "\t\t|________________________________________________________________" << setw(1) << "|" << endl;
}