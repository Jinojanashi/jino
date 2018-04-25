#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;

class BigMonsDetail
{
	string name;
	string type;
	vector<string> skill; //for regist name of skill
	vector<int> skillCooldownMax;
	vector<int> skillCooldown;
	vector<int> skillPassive;
	int atk;
	int def;
	int hpMax;
	int hp;
	int chooseSkill;
public:
	PlayerDetail();
	~PlayerDetail();
	vector<float> *PositionX; //for regist unit x position
	vector<float> *PositionY; //for regist unit y position
	int attack(Unit &);
	int beAttack(int);
	bool isDead();
	int ChooseSkill(int);
	void Cooldown(int);
	void show();
};

BigMonsDetail::BigMonsDetail(int a)
{
	else if (a == 11)
	{
		type = "Bigmons1";
		name = "Bigmons";
		hpMax = 200;
		atk = 20;
		def = 0;
		chooseSkill = 3;
		string A = "Jumping";
		skill.push_back(A);
		skillCooldownMax.pushback(20);
		skillPassive.push_back(20);
		for (int i = 1; i < 4; i++)
		{
			A = "NULL";
			skill.push_back(A);
			skillCooldownMax.push_back(0);
			skillPassive.push_back(0);
		}
	}
	else if (a == 12)
	{
		type = "Bigmons2";
		name = "Bigmons";
		hpMax = 300;
		atk = 30;
		def = 0;
		manaMax = 0;
		chooseSkill = 4;
		string A = "Hammer!!";
		skill.push_back(A);
		skillCooldownMax.push_back(20);
		skillPassive.push_back(50);
		for (int i = 1; i < 4; i++)
		{
			A = "NULL";
			skill.push_back(A);
			skillCooldownMax.push_back(0);
			skillPassive.push_back(0);
		}
	}
	else if (a == 13)
	{
		type = "Bigmons3";
		name = "Bigmons";
		hpMax = 400;
		atk = 35;
		def = 0;
		manaMax = 0;
		chooseSkill = 4;
		string A = "Shub! Shub!! Shub!!!";
		skill.push_back(A);
		skillCooldownMax.push_back(40);
		skillMana.push_back(0);
		skillPassive.push_back(80);
		for (int i = 1; i < 4; i++)
		{
			A = "NULL";
			skill.push_back(A);
			skillCooldownMax.push_back(0);
			skillPassive.push_back(0);
		}
	}
	else if (a == 14)
	{
		type = "mons4";
		name = "Bigmons";
		hpMax = 400;
		atk = 40;
		def = 0;
		chooseSkill = 4;
		string A = "Run Run Run!!!";
		skill.push_back(A);
		A = "Spinnigggg";
		skill.push_back(A);
		A = "Fire the hole";
		skill.push_back(A);
		for (int i = 0; i < 3; i++)
		{
			skillCooldownMax.push_back(40);
			skillPassive.push_back(110);
		}
		skillPassive.push_back(0);
	}
	hp = hpMax;
	for (int i = 0; i < 3; i++)
	{
		skillCooldown.push_back(skillCooldownMax[i]);
	}

}

//calculate of hp
int BigMonsDetail::attack(class &U)
{
	return U.beAttacked(atk);
}
//calculate hp
int BigMonsDetail::beAttack(int ATK)
{

}

void BigMonsDetail::show()
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
bool BigMonsDetail::isDead()
{

}

BigMonsDetail::~BigMonsDetail()
{
	if (A == true)
	{
		delete[] skill;
	}
}