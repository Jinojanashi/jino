#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>

using namespace std;


class Unit
{
	string name;
	string type;
	vector<string> skill; //for regist name of skill
	vector<int> skillCooldownMax;
	vector<int> skillCooldown;
	vector<int> skillMana;
	vector<int> skillPassive;
	int manaMax; // max mana = 100
	int mana;
	int atk;
	int def;
	int hpMax;
	int hp;
	int speed;
	int chooseSkill;
public:
		Unit(int);
		vector<float> *PositionX; //for regist unit x position
		vector<float> *PositionY; //for regist unit y position
		int attack(Unit &);
		int beAttack(int);
		int heal();
		int plusmana();
		bool isDead();
		int ChooseSkill(int);
		void Cooldown(int);
		void show();
		void ClearUnit(bool);
};

/* int type = 00 is players
   int type = 01 is mons1
   int type = 02 is mons2
   int type = 03 is mons3
   int type = 04 is mons4
   int type = 11 is Bigmons1
   int type = 12 is Bigmons2
   int type = 13 is Bigmons3
   int type = 14 is Bigmons4*/

//create uni
Unit::Unit(int a)
{
	if (a == 0)
	{
		type = "Players";
		cout << "Plese input your name.";
		getline(cin, name);
		hpMax = 300;
		atk = 10;
		def = 5;
		speed = 15;
		chooseSkill = 3;
		manaMax = 100;
		skillCooldownMax.push_back(10);
		skillCooldownMax.push_back(20);
		skillCooldownMax.push_back(30);
		skillMana.push_back(10);
		skillMana.push_back(20);
		skillMana.push_back(50);
		skillPassive.push_back(30);
		skillPassive.push_back(50);
		skillPassive.push_back(150);
		skillPassive[3] = 0;
		for (int i = 0 ; i < 3 ; i++)
		{
			string A;
			cout << "Pls input your skillname.\n";
			getline(cin,A);
			skill.push_back(A);
		}
	}
	else if (a == 1)
	{
		type = "mons1";
		name = "smallmons";
		hpMax = 20;
		atk = 1;
		def = 0;
		manaMax = 0;
		chooseSkill = 3;
		for (int i = 0; i < 4; i++)
		{
			string A = "NULL";
			skill.push_back(A);
			skillCooldownMax.push_back(0);
			skillMana.push_back(0);
			skillPassive.push_back(0);
		}
	}
	else if (a == 2)
	{
		type = "mons2";
		name = "smallmons";
		hpMax = 30;
		atk = 1;
		def = 0;
		manaMax = 0;
		chooseSkill = 3;
		for (int i = 0; i < 4; i++)
		{
			string A = "NULL";
			skill.push_back(A);
			skillCooldownMax.push_back(0);
			skillMana.push_back(0);
			skillPassive.push_back(0);
		}
	}
	else if (a == 3)
	{
		type = "mons3";
		name = "smallmons";
		hpMax = 50;
		atk = 2;
		def = 1;
		manaMax = 0;
		chooseSkill = 3;
		for (int i = 0; i < 4; i++)
		{
			string A = "NULL";
			skill.push_back(A);
			skillCooldownMax.push_back(0);
			skillMana.push_back(0);
			skillPassive.push_back(0);
		}
	}
	else if (a == 4)
	{
		type = "mons2";
		name = "smallmons";
		hpMax = 60;
		atk = 3;
		def = 2;
		manaMax = 0;
		chooseSkill = 3;
		for (int i = 0; i < 4; i++)
		{
			sstring A = "NULL";
			skill.push_back(A);
			skillCooldownMax.push_back(0);
			skillMana.push_back(0); 
			skillPassive.push_back(0);
		}
	}
	else if (a == 11)
	{
		type = "Bigmons1";
		name = "Bigmons";
		hpMax = 200;
		atk = 20;
		def = 0;
		manaMax = 0;
		chooseSkill = 3;
		string A = "Jumping";
		skill.push_back(A);
		skillCooldownMax.pushback(20);
		skillMana.push_back(0);
		skillPassive.push_back(20);
		for (int i = 1; i < 4; i++)
		{
			A = "NULL";
			skill.push_back(A);
			skillCooldownMax.push_back(0);
			skillMana.push_back(0);
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
		skillMana.push_back(0);
		skillPassive.push_back(50);
		for (int i = 1; i < 4; i++)
		{
			A = "NULL";
			skill.push_back(A);	
			skillCooldownMax.push_back(0);
			skillMana.push_back(0);
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
			skillMana.push_back(0);
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
		manaMax = 0;
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
			skillMana.push_back(0);
			skillPassive.push_back(110);
		}
		skillPassive.push_back(0);
	}
	else
	{
		cout << "no data.";
	}

	mana = manaMax;
	hp = hpMax;

	for (int i = 0; i < 3; i++)
	{
		skillCooldown.push_back(skillCooldownMax[i]);
	}

}
//calculate of hp
int Unit::attack(Unit &U)
{
	int Atk = 0;
	if (chooseSkill == 3)
	{
		Atk = atk;
	}
	else if (chooseSkill == 0 || chooseSkill == 1 || chooseSkill == 2 )
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
int Unit::beAttack(int ATK)
{

}
//use for choose skill drop mana and assign to cooldown skill.
int Unit::ChooseSkill(int s)
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
	
	chooseSkill = 4;
	Cooldown(s);
	return mana;
}
 //use for cooldown skill.
void Unit::Cooldown(int d)
{
	int *c = new int[1000000000];
	while (skillCooldown[d] == skillCooldownMax[d])
	{
		clock_t start, stop;
		while((stop - start) / CLOCKS_PER_SEC == skillCooldownMax[d])
		{
			start = clock();
				for (int i = 0; i < 1000000000; i++) c[i] = i;
			stop = clock();
		}
		
	}
	delete [] c;
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
bool Unit::isDead()
{
	
}

void Unit::ClearUnit(bool A)
{
	if (A == true)
	{
		delete[] skill;
	}
}
