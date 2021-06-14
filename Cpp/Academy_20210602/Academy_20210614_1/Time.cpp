#include "Time.h"

Time::Time():hour(0), minute(0)
{
	cout << "생성자!!" << endl;
}

Time::Time(const int h, const int m)
	:hour(h),minute(m)
{

	cout << "생성자 오버로딩!!!" << endl;
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
