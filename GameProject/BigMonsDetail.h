#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include "item.h"

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
	bool &keychange;
	bool &firsttime;
public:
	BigMonsDetail();
	~BigMonsDetail();
	vector<float> *PositionX; //for regist unit x position
	vector<float> *PositionY; //for regist unit y position
	int attack(Unit &);
	int beAttack(int);
	bool isDead();
	void ChooseSkill(int);
	void Cooldown(int);
	void show();
	bool checktime(float, vector<float> &, bool &, bool &);
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
		type = "Bigmons4";
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

//pls random skill for him.
int BigMonsDetail::attack(class &U)
{
	int Atk = 0;
	if (chooseSkill == 3)
	{
		Atk = atk;
	}
	else if (chooseSkill == 0 || chooseSkill == 1 || chooseSkill == 2)
	{
		Atk += skillPassive[chooseSkill];
	}
	else
	{
		cout << "no data";
	}
	return U.beAttacked(Atk);
}
//calculate hp
int BigMonsDetail::beAttack(int ATK)
{
	int dmg;
	if (ATK > def)dmg = ATK - def;
	else dmg = 0;

	hp -= dmg;
	if (hp <= 0) hp = 0;

	return dmg;
}

void BigMonsDetail::ChooseSkill(int s)
{
	int a = 0;
	int b = s - 1;
	chooseSkill = b;
		if (b == 0 || b == 1 || b == 2)
		{
			if (skillCooldown[b] = skillCooldownMax[b])
			{
				cout << skill[b];
				a = skillMana[b];
				mana -= a;
				skillCooldown[b] = 0;
			}
			else
			{
				cout << "Can't use skill coz this skill is cooldown. \nPls choose skill again";
				cin >> chooseSkill;
			}
		}
		else
		{
			cout << "Null \nPls Choose skill again.";
			cin >> chooseSkill;
		}

	chooseSkill = 3;
	Cooldown(b);
}

bool BigMonsDetail::checktime(float start, vector<float> &skillCooldownMax, bool &keychange, bool &firsttime) {
	cout << (clock() - start) / (double)CLOCKS_PER_SEC << endl;
	if (firsttime) {
		keychange = false;
		firsttime = false;
		return true;
	}
	if ((clock() - start) / (double)CLOCKS_PER_SEC>skillCooldownMax) {
		keychange = true;
		return true;
	}
	else {
		keychange = false;
		return false;
	}
}

void BigMonsDetail::Cooldown(int d)
{
	char x;
	bool keychange = true, firsttime = true;
	int  start;
	srand(time(0));
	while (true) {
		x = _getch();
		if (x != '	')
		{
			if (keychange) start = clock();
			if (checktime(start, skillCooldownMax[d], keychange, firsttime)) skillCooldown[d] = skillCooldownMax[d];
		}
	}
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
	if (type == "Bigmons1")
	{
		int b = rand() % 6 +1;
		int c = rand() % 6 +1;
		if (hp == 0)
		{
			return true;
			Item A(b, c);
		}
		else return false;
	}
	else if (type == "Bigmons2")
	{
		int b = rand() % 10 + 3;
		int c = rand() % 10 + 3;
		if (hp == 0) 
		{
			Item A(d, e);
			return true;
		}
		else return false;
		
	}
	else if (type == "Bigmons3")
	{
		int b = rand() % 14 + 5;
		int c = rand() % 14 + 5;
		if (hp == 0)
		{
			return true;
			Item A(f, g);
		}
		else return false;
		
	}
	else if (type == "Bigmons4")
	{
		if (hp == 0)
		{
			return true;
			cout << "You win.\n";
		}
		else return false;
	}

}

BigMonsDetail::~BigMonsDetail()
{
	skill.clear();
	skillCooldown.clear();
	skillCooldownMax.clear();
	skillPassive.clear();
}
