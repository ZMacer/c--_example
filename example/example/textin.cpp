#include <iostream>
int main()
{
	using namespace std;
	char ch;
	int count = 0;
	//cin.get(ch);
	//while(!cin.fail())
	//while(cin.fail()==false)//windows 7 �°���ctrl+zΪEOF,cin.fail() == true
	while(cin.get(ch))
	{
		cout << ch;
		++count;
		//cin.get(ch);
	}
	cout << endl << count << ch << endl;
	getchar();
	return 0;
}