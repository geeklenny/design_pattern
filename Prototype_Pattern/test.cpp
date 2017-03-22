
#include <iostream>

using namespace std;


//����
class Resume
{
protected:
	char *name;
public:
	Resume() {}
	virtual ~Resume() {}
	virtual Resume* Clone() { return NULL; }
	virtual void Set(char *n) {}
	virtual void Show() {}
};


class ResumeA : public Resume
{
public:
	ResumeA(const char *str);  //���캯��
	ResumeA(const ResumeA &r); //�������캯��
	~ResumeA();                //��������
	ResumeA* Clone();          //��¡���ؼ�����
	void Show();               //��ʾ����
};
ResumeA::ResumeA(const char *str) 
{
	if(str == NULL) {
		name = new char[1]; 
		name[0] = '\0'; 
	}
	else {
		name = new char[strlen(str)+1];
		strcpy(name, str);
	}
}
ResumeA::~ResumeA() { delete [] name;}
ResumeA::ResumeA(const ResumeA &r) {
	name = new char[strlen(r.name)+1];
	strcpy(name, r.name);
}
ResumeA* ResumeA::Clone() {
	return new ResumeA(*this);
}
void ResumeA::Show() {
	cout<<"ResumeA name : "<<name<<endl; 
}


int main()
{
	Resume *r1 = new ResumeA("A");
	Resume *r3 = r1->Clone();
	r1->Show();
	//ɾ��r1,r2
	delete r1; 
	r1 = r2 = NULL;
	//������Զ�r3,r4��Ӱ��
	r3->Show(); 
	delete r3;
	r3 = NULL;
}