#include<iostream>
#include<vector>
 #include "Project1.h"

using namespace std;

int main()
{
		vector<string> skill;
		for (int i = 0 ; i < 3 ; i++)
		{
			string A;
			cout << "Pls input your skillname.\n";
			getline(cin,A);
			skill.push_back(A);
		}
		for(int j = 0 ; j < 3 ; j++)
		{
			cout << "skill name " << skill[j] << "\n";
		}
		skill.clear();
	return 0;
}
