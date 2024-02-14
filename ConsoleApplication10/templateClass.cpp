#include <iostream>
using namespace std;
/* Внимание!Программа завершается аварийно! Для этого
 примера это нормально.*/

template<typename T>
class DynArray {
	T* arr;
	int size;

public:
	DynArray(int sizeP)
		: arr{ new T[sizeP] {} }, size{ sizeP }
	{
		std::cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}

	//Конструктор для инициализации масива 
	DynArray(T* arrayPtr, int arraySize)
		: arr{ new T[arraySize] }, size{ arraySize }
	{
		for (int i = 0; i < size; ++i) {
			arr[i] = arrayPtr[i];
		}
		cout << "DynArr constructed for " << size
			<< " elements, for " << this << '\n';
	}

	DynArray() : DynArray(5) {}

	DynArray(const DynArray& object)
		: arr{ new T[object.size] }, size{ object.size }
	{
		for (int i = 0; i < size; ++i) {
			arr[i] = object.arr[i];
		}
		std::cout << "DynArr copy constructed for "
			<< size << " elements, for " << this
			<< '\n';
	}


	T getElem(int idx) { return arr[idx]; }
	void setElem(int idx, T val) { arr[idx] = val; }
	void print();
	void randomize();
	void sum();
	DynArray operator+(DynArray& obj);
	DynArray operator+=(DynArray& obj);

	~DynArray()
	{
			delete[] arr; std::cout << "DynArr destructed for"
				<< size << " elements, for"
				<< this << '\n';
	}
};

template<typename T>
void DynArray<T>::print()
	{
		for (int i{ 0 }; i < size; ++i)
		{
			std::cout << arr[i] << ' ';
		}
		std::cout << '\n';
	}

template<typename T>
void DynArray<T>::randomize()
	{
		for (int i{ 0 }; i < size; ++i)
		{
			arr[i] = rand() % 10;
		}
	}



template<typename T>
void DynArray<T>::sum()
{
	T total = 0;
	for (int i{ 0 }; i < size; ++i)
	{
		total += arr[i];
	}
	cout << "Sum of elements: " << total << endl;
}


template<typename T>
DynArray<T> DynArray<T>::operator+(DynArray& obj)
{
	DynArray<T> result(size);
	for (int i = 0; i < size; ++i) {
		result.arr[i] = arr[i] + obj.arr[i];
	}
	return result;
}




class Point {
	int x;
	int y;

public:
	Point() : x{ 0 }, y{ 0 } {}
	Point(int value){
	x = value;
	y = value;
	}
	int getX() { return x; }
	int getY() { return y; }

	Point& operator+=(const Point& obj) {
		x += obj.x;
		y += obj.y;
		return *this;
	}
};

ostream& operator<<(ostream& out, Point& obj) {
	out << "x: " << obj.getX() << "   y: " << obj.getY() << endl;
	return out;
}


int main()
{
	DynArray<int>ar1{10};
	ar1.randomize();
	std::cout << "ar1 elements: ";
	ar1.print();
	DynArray<int> ar2{ ar1 };
	std::cout << "ar2 elements: ";
	ar2.print();



	int arrInt[] = { 1, 2, 3, 4, 5 };
	DynArray<int> arr1(arrInt, 5);
	arr1.print();
	arr1.sum();

	double arrDouble[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };
	DynArray<double> arr2(arrDouble, 5);
	arr2.print();
	arr2.sum();


	char arrChar[] = { '1', '2', '3', '4', '5' };
	DynArray<char> arr3(arrChar, 5);
	arr3.print();
	arr3.sum();

	Point arrPoint[] = {1,2,3,4,5};
	DynArray<Point> dynArrPoint(arrPoint, 5); 
	dynArrPoint.sum();
	return 0;
}





