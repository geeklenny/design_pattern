//SingletonB.h
#pragma once
#include "Singleton.h"
class SingletonB: public Singleton
{
	friend class Singleton; //����Ϊ��Ԫ�࣬�������޷���������Ĺ��캯��
public:
	void Show(){ cout<<"SingletonB"<<endl; }
private:  //Ϊ�������ԣ���������޷�ͨ�����캯������ʵ����
	SingletonB() {}
};