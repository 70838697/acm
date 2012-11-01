// range heap example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main ()
{
	int myints[] = {10,20,30,5,15};
	vector<int> v(myints,myints+5);
	vector<int>::iterator it;

	make_heap (v.begin(),v.end());
	cout << "initial max heap   : " << v.front() << endl; //30

	pop_heap (v.begin(),v.end());
	v.pop_back();
	cout << "max heap after pop : " << v.front() << endl;//20

	v.push_back(99);
	push_heap (v.begin(),v.end());
	cout << "max heap after push: " << v.front() << endl;//99

	sort_heap (v.begin(),v.end());

	cout << "final sorted range :";
	for (unsigned i=0; i<v.size(); i++) cout << " " << v[i]; //5 10 15 20 99

	cout << endl;

	return 0;
}