#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>

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
	int speed;
	int chooseSkill;
public:
	PlayerDetail();
	~PlayerDetail();
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
int PlayerDetail::attack(Unit &U)
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

}
//use for choose skill drop mana and assign to cooldown skill.
int PlayerDetail::ChooseSkill(int s)
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
void PlayerDetail::Cooldown(int d)
{
	int *c = new int[1000000000];
	while (skillCooldown[d] == skillCooldownMax[d])
	{
		clock_t start, stop;
		while ((stop - start) / CLOCKS_PER_SEC == skillCooldownMax[d])
		{
			start = clock();
			for (int i = 0; i < 1000000000; i++) c[i] = i;
			stop = clock();
		}

	}
	delete[] c;
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

}

void PlayerDetail::ClearUnit(bool A)
{
	if (A == true)
	{
		delete[] skill;
	}
}