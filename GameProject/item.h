#include<iostream>
#include<string>
using namespace std;
class Item{
	public:
		int hp_item=10;
		int mp_item=10;
		int num_hp_item=0;
		int num_mp_item=0;
		void Item(int,int);	
};

Item::Item(int x,int y){
		num_hp_item += x;
		num_mp_item += y;		
}