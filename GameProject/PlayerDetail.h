#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include "item.h"

using namespace std;

class PlayerDetail
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
	int chooseSkill;
	bool &keychange;
	bool &firsttime;
public:
	PlayerDetail();
	~PlayerDetail();
	vector<float> *PositionX; //for regist unit x position
	vector<float> *PositionY; //for regist unit y position
	int attack(class &);
	int beAttack(int);
	int useItem();
	bool isDead();
	int ChooseSkill(int);
	void Cooldown(int);
	void show();
	bool checktime(float, vector<float> &, bool &, bool &);
};

PlayerDetail::PlayerDetail()
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
	Item A(2,2);
	for (int i = 0; i < 3; i++)
	{
		string A;
		cout << "Pls input your skillname.\n";
		getline(cin, A);
		skill.push_back(A);
	}
	mana = manaMax;
	hp = hpMax;

	for (int i = 0; i < 3; i++)
	{
		skillCooldown.push_back(skillCooldownMax[i]);
	}

}

//calculate of hp
int PlayerDetail::attack(class &U)
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
int PlayerDetail::beAttack(int ATK)
{
	int dmg;
	if(ATK > def)dmg = ATK - def;
	else dmg = 0;

	hp -= dmg;
	if (hp <= 0) hp = 0;

	return dmg;
}
//plus hp or mana. 1 for hp and 2 for mana
int PlayerDetail:useItem()
{
	int r = 0;
	cout << "pls choose item.\n";
	cin >> r;
	if (r == 1)
	{
		if (num_hp_item > 0)
		{
			if(hp+hp_item <= hpMax)hp += hp_item;
			else hp = hpMax;

			num_hp_item -= 1;
		}
		else cout << "can't use";
	}
	else if (r == 2)
	{
		if (num_mp_item > 0)
		{
			if (mana + mp_item <= manaMax) mana += mp_item;
			else mana = manaMax;

			num_mp_item -= 1;
		}
		else cout << "can't use";
	}
	else cout << "no data.\n";
}
//use for choose skill drop mana and assign to cooldown skill.
int PlayerDetail::ChooseSkill(int s)
{
	int a = 0;
	int b = s - 1;
	chooseSkill = b;
	if (mana >= skillMana[b])
	{
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
	}
	else cout << "can't use coz you not have mana";
	chooseSkill = 4;
	Cooldown(b);
	return mana;
}
//use to cheak time to cooldown.
bool PlayerDetail::checktime(float start, vector<float> &skillCooldownMax, bool &keychange, bool &firsttime) {
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
//use for cooldown skill.
void PlayerDetail::Cooldown(int d)
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
			if (checktime(start,skillCooldownMax[d], keychange, firsttime)) skillCooldown[d] = skillCooldownMax[d];
		}
		else cout << "skill not declare pls try again later.\n";
	}
}

void PlayerDetail::show()
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
bool PlayerDetail::isDead()
{
	if(hp == 0) return true;
	else return false;
}

void PlayerDetail::~PlayerDetail()
{
	skill.clear();
	skillCooldown.clear();
	skillCooldownMax.clear();
	skillMana.clear();
	skillPassive.clear();
}