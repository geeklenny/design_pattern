//SingletonA.h
#pragma once
#include "Singleton.h"
class SingletonA: public Singleton
{
	friend class Singleton; //����Ϊ��Ԫ�࣬�������޷���������Ĺ��캯��
public:
	void Show() { cout<<"SingletonA"<<endl; }
private:   //Ϊ�������ԣ���������޷�ͨ�����캯������ʵ����
	SingletonA() {} 
};