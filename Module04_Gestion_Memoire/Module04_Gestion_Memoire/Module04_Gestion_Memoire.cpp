
#include <iostream>

int main()
{
	int j = 0;
	int& k = j;

	int* tableau = (int*)malloc(100*sizeof(int));
	//std::cout << i << std::endl;
	//*i = 8;
	//std::cout << i << std::endl;

	int valeurs[] = { 1, 2, 3, 4, 5 };
	int* ptr = valeurs;
	std::cout << *ptr << std::endl;
	std::cout << ptr << std::endl;
	ptr += 2;
	std::cout << *ptr << std::endl;
	std::cout << ptr << std::endl;
	*ptr = 42;
	std::cout << ptr << std::endl;
	std::cout << *ptr << std::endl;
	std::cout << valeurs[2] << std::endl;
}


 