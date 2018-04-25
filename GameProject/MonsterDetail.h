#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

class MonsterDetail
{
	string name;
	string type;
	int atk;
	int def;
	int hpMax;
	int hp;
public:
	MonsterDetail(int);
	~MonsterDetail();
	vector<float> *PositionX; //for regist unit x position
	vector<float> *PositionY; //for regist unit y position
	int attack(class &);
	int beAttack(int);
	void show();
};

MonsterDetail::MonsterDetail(int a)
{
	else if (a == 1)
	{
		type = "mons1";
		name = "smallmons";
		hpMax = 20;
		atk = 1;
		def = 0;
	}
	else if (a == 2)
	{
		type = "mons2";
		name = "smallmons";
		hpMax = 30;
		atk = 1;
		def = 0;
	}
	else if (a == 3)
	{
		type = "mons3";
		name = "smallmons";
		hpMax = 50;
		atk = 2;
		def = 1;
	}
	else if (a == 4)
	{
		type = "mons4";
		name = "smallmons";
		hpMax = 60;
		atk = 3;
		def = 2;
	}
	hp = hpMax;

}

//calculate of hp
int MonsterDetail::attack(class &U)
{
	return U.beAttacked(atk);
}
//calculate hp
int MonsterDetail::beAttack(int ATK)
{

}

void Unit::show()
{
	cout << hpMax;
	cout << mana;
	cout << type;
	cout << name;
	cout << atk;
	cout << def;
	for (int i = 0; i < 3; i++)
	{
		cout << skill[i];
		cout << skillCooldown[i];
	}
}
bool MonsterDetail::isDead()
{

}

MonsterDetail::~MonsterDetail()
{
	if (A == true)
	{
		delete[] skill;
	}
}
