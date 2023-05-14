// #include <iostream>
// using namespace std;

// void swap(char*& str1, char*& str2)
// {
// 	char* temp = str1;
// 	str1 = str2;
// 	str2 = temp;
// }

// int main()
// {
// 	char* str1 = "GEEKS";
// 	char* str2 = "FOR GEEKS";
// 	swap(str1, str2);
// 	cout << "str1 is " << str1 << '\n';
// 	cout << "str2 is " << str2 << '\n';
// 	return 0;
// }



#include <iostream>
using namespace std;

int& fun()
{
	static int x = 10;
	return x;
}

int main()
{
	fun() = 30;
	cout << fun();
	return 0;
}

