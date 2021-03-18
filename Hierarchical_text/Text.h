#pragma once
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<algorithm>
#include<stack>
#include<set>

const int MAX_SIZE = 80;

struct TTextLink {
	TTextLink* pNext;
	TTextLink* pDown;
	char str[MAX_SIZE];
	TTextLink(const char* s = NULL, TTextLink* next = NULL, TTextLink* down = NULL);
};
class TText {
	TTextLink* pFirst;
	TTextLink* pCurr;
	std::stack<TTextLink*>st;
	//����������� ������. ���������� ������� 
	void PrintRec(TTextLink* t, int level);
	//����������� ����� � ����. ���������� �������
	void SaveRec(TTextLink* t, std::ofstream& ofs);
	//����������� ������ �� �����. ���������� �������
	TTextLink* ReadRec(std::ifstream& ifs);
public:
	//����������� �� ���������
	TText();
	//����������� �����������
	TText(const TText& t);
	//����������� ��������� �� ������� �� ������ ������� � �������� ����
	void GoFirstLink();
	//������� � ���������� �������� �� �������� ����� ��������
	void GoNextLink();
	//������� � ������� (����������) �������� �� �������� ����� ��������
	void GoDownLink();
	//��������� � ����������� ��������
	void GoPrevLink();
	//�������� ��������� �� �������� ������� � ������������ � ���� pNext �������� ��� pNext
	void InsNextLine(const char* s);
	//�������� ��������� �� �������� ������� � ������������ � ���� pNext �������� ��� pDown
	void InsNextSections(const char* s);
	//�������� ��������� �� �������� ������� � ������������ � ���� pDown �������� ��� pNext
	void InsDownLine(const char* s);
	//�������� ��������� �� �������� ������� � ������������ � ���� pDown �������� ��� pDown 
	void InsDownSections(const char* s);
	//������� � �������� ��������� �� �������� ������
	void DelNextLine();
	//������� � �������� ��������� �� �������� ������
	void DelDownLine();
	//������ �� ����� (����� ����� ����������� ������). ������� �������
	void Print();
	//����� � ���� (����� ����� ������������ ������). ������� ������� 
	void Save(const char* file_name);
	//������ �� ����� (����� ����� ������������� ������). ������� ������� 
	void Read(const char* file_name);
	//������ �� ����� � ������ �����
	void PrintS();
	//���������� � ���� � ������� �����
	void SaveS(const char* file_name);
	//������ �� ����� � ������� �����
	void ReadS(const char* file_name);
};