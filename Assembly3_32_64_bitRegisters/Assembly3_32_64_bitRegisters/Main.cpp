# include <iostream>

//extern "C" int Foo();
extern "C" int RegTest();

int main()
{
	std::cout << "calling assembly function: " << RegTest();

	return 0;
}