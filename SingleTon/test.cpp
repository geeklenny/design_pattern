
#include <iostream>
#include "Singleton.h"

int main()
{
	Singleton *stA = Singleton::GetInstance("SingletonA");
	stA->Show();
	Singleton *stB = Singleton::GetInstance("SingletonB");
	stB->Show();
	cin.get();
	return 0;
}