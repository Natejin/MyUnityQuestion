#include "Time.h"

Time::Time():hour(0), minute(0)
{
	cout << "������!!" << endl;
}

Time::Time(const int h, const int m)
	:hour(h),minute(m)
{

	cout << "������ �����ε�!!!" << endl;
	/*hour = h;
	minute = m;*/
}

Time::~Time()
{
}

void Time::Print()
{
	cout << hour << " : " << minute << endl;
}
