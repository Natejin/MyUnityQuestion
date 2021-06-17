#include <iostream>

using namespace std;

template <typename T> 
T GetMax(T x, T y) {
	return x > y ? x : y;
}

template <typename T>
void OutPut(T data) {
	cout << "µ¥ÀÌÅÍ : " << data << endl;
}

template <typename T1, typename T2>
void OutPut1(T1 a, T2 b) {
	cout << a << "," << b  << endl;
}




template<typename T>
class Box {
	private:
		T data;
	public:
		void SetData(const T data) { this->data = data; }
		T GetData() { return data; }
		
};

int main() {
	cout << GetMax(1, 2) << endl;
	OutPut(1);
	OutPut1(1, 1.5);

	Box<int>* box = new Box<int>();
	box->SetData(100);

	Box<double>* box1 = new Box<double>();
	box->SetData(3.1415);

	cout << box->GetData() << endl;
	cout << box1->GetData() << endl;
}