#include <iostream>

class MyClass
{
public:
	int* data; // Указатель на массив данных

	// Конструктор класса, выделяет память и заполняет массив данными от 0 до size-1
	MyClass(int size)
	{
		this->Size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		std::cout << " MyClass(cons) " << this << std::endl;
	}

	// Конструктор копирования, создает копию объекта other
	MyClass(const MyClass& other)
	{
		this->Size = other.Size;

		this->data = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->data[i] = other.data[i];
		}
		std::cout << " MyClass(cons) " << this << std::endl;
	}

	// Деструктор, освобождает выделенную память для массива данных
	~MyClass()
	{
		std::cout << " ~MyClass(des) " << this << std::endl;
		delete[] data;
	}

private:
	int Size; // Размер массива данных
};

void Foo(MyClass value)
{
	std::cout << "Foo(MyClass value)" << std::endl;
}

MyClass Foo2()
{
	std::cout << "Foo2()" << std::endl;
	MyClass temp(2);

	return temp;
}

int main()
{
	MyClass a(10); // Создание объекта a с размером 10
	MyClass b(a);  // Создание объекта b как копии объекта a

	/*Foo(a);     // Вызов функции Foo с объектом a как параметром (приводит к вызову конструктора копирования)
	Foo2();      // Вызов функции Foo2, создание временного объекта и его возврат (приводит к вызову конструктора и деструктора)*/
	std::cout << "\nWassup bruh..=)";
	return 0;	
}
