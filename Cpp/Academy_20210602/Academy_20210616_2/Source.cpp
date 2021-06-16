#include <iostream>
using namespace std;
class AbstractClass {
public:
	virtual void PureVirtualFunction() = 0;
	void What() { std::cout << "����?" << std::endl; };
};

class TestClass : public AbstractClass
{
public:
	virtual void PureVirtualFunction() {
		std::cout << "�ȳ�" << std::endl;
	}
};

class AbstractObject
{
public:
	AbstractObject() :line1(0), line2(0) {}
	AbstractObject(const double line1, const double line2) :line1(line1), line2(line2) {}

	void SetLine1(const double line1) { this->line1 = line1; }
	void SetLine2(const double line2) { this->line2 = line2; }
	double GetLine1() { return line1; }
	double GetLine2() { return line2; }

	virtual double AreaCalculation() = 0;
	virtual double Compute() = 0;


protected:
	double line1, line2;
};

class Isoscale : public AbstractObject
{
public:
	Isoscale() : AbstractObject() { side = 0; area = 0; }
	Isoscale(const double base, const double height) :AbstractObject(base, height) { side = 0; area = 0; };
	virtual double AreaCalculation() { 
		area = line1 * line2 * 0.5;
		return area;
	};
	virtual double Compute() {
		side = sqrt((line1 * line1) + (line2 * line2));
		return side;
	};
private:
	double side;
	double area;
};

class Square : public AbstractObject
{
public:
	Square() : AbstractObject() { side = 0; area = 0; }
	Square(const double base, const double height) :AbstractObject(base, height) { side = 0; area = 0; };
	virtual double AreaCalculation() {
		area = line1 * line2;
		return area;
	};
	virtual double Compute() {
		side = (line1 + line2) * 2;
		return side;
	};
private:
	double side;
	double area;
};





int main() {
	TestClass* t = new TestClass();
	t->PureVirtualFunction();
	t->What();
	delete t;

	Isoscale is(3, 4);
	cout << "�ﰢ���� �غ� : " << is.GetLine1() << endl;
	cout << "�ﰢ���� ���� : " << is.GetLine2() << endl;
	cout << "�ﰢ���� ���� : " << is.AreaCalculation() << endl;
	cout << "�ﰢ���� �غ� : " << is.Compute() << endl;

	Square sq(3, 4);
	cout << "�簢���� �غ� : " << sq.GetLine1() << endl;
	cout << "�簢���� ���� : " << sq.GetLine2() << endl;
	cout << "�簢���� ���� : " << sq.AreaCalculation() << endl;
	cout << "�簢���� �غ� : " << sq.Compute() << endl;
}

