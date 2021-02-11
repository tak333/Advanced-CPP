// Casts.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class A {
public:
	A(int x) {
		A::x = x;
		std:: cout << "const!";
	}

	static void* operator new(size_t size) {
		std::cout << "here!";
		std::cout << size << endl;
		return malloc(size);
	}

	int x;
};

int main()
{
	A* ptr = new A(3);
	cout << "VALUE" << ptr->x << endl;
	return 0;
}
