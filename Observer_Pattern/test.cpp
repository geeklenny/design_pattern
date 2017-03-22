
//�۲���ģʽ


#include <iostream>

#include <string>

#include <list>

using namespace std;

//�۲���
class Observer  
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void Update() {} 
};
//����
class Blog  
{
public:
	Blog() {}
	virtual ~Blog() {}
	void Attach(Observer *observer) { m_observers.push_back(observer); }	 //���ӹ۲���
	void Remove(Observer *observer) { m_observers.remove(observer); }        //�Ƴ��۲���
	void Notify() //֪ͨ�۲���
	{
		list<Observer*>::iterator iter = m_observers.begin();
		for(; iter != m_observers.end(); iter++)
			(*iter)->Update();
	}
	virtual void SetStatus(string s) { m_status = s; } //����״̬
	virtual string GetStatus() { return m_status; }    //���״̬
private:
	list<Observer* > m_observers; //�۲�������
protected:
	string m_status; //״̬
};

//���岩����
class BlogCSDN : public Blog
{
private:
	string m_name; //��������
public:
	BlogCSDN(string name): m_name(name) {}
	~BlogCSDN() {}
	void SetStatus(string s) { m_status = "CSDN֪ͨ : " + m_name + s; } //��������״̬��Ϣ
	string GetStatus() { return m_status; }
};
//����۲���
class ObserverBlog : public Observer   
{
private:
	string m_name;  //�۲�������
	Blog *m_blog;   //�۲�Ĳ��ͣ���Ȼ��������ʽ���ã��Ϳ��Թ۲�������
public: 
	ObserverBlog(string name,Blog *blog): m_name(name), m_blog(blog) {}
	~ObserverBlog() {}
	void Update()  //��ø���״̬
	{ 
		string status = m_blog->GetStatus();
		cout<<m_name<<"-------"<<status<<endl;
	}
};

//���԰���
int main()
{
	Blog *blog = new BlogCSDN("wuzhekai1985");
	Observer *observer1 = new ObserverBlog("tutupig", blog);
	blog->Attach(observer1);
	blog->SetStatus("�������ģʽC++ʵ�֣�15�������۲���ģʽ");
	blog->Notify();
	delete blog; delete observer1;

	cin.get();

	return 0;
}