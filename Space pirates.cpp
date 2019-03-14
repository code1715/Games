// Space pirates
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using std::cin;
using std::cout;
/* 
Gun damage:
1.Bad gun - 10
2.Blaster - 20
3.Laser gun - 40
4.Energetic gun - 60
5.EMI gun - 80
6.Gauss gun - 100
*/

class Space_Ship
{
protected:
	int police_hp;
  const int POLICE_DAMAGE = 20;
public:
	int coord_x, coord_y, coord_z;
};

class Space_Pirate : Space_Ship
{
private:
	double fill_price;
	int repair_price;
	bool pursuit = true;
	int fuel;
	int money;
  int hp;
	int gun_damage;
public:
	Space_Pirate()
	{
		coord_x = 0;
		coord_y = 0;
		coord_z = 0;
		gun_damage = 10;
		money = 150;
		hp = 100;
		fuel = 100;
	}
	
	void teleport()
	{
		srand(time(NULL));
		if (pursuit == true) 
    {
    cout << "Cops pursuit you, let's fight with them!\n";
    return;
    }
    int coord_x0 = coord_x;  // coord_x0 - coord_x before teleportation
		int coord_y0 = coord_y;  // coord_y0 - coord_y before teleportation
		int coord_z0 = coord_z;  // coord_z0 - coord_z before teleportation
		coord_x = rand() % 20;
		coord_y = rand() % 20;
		coord_z = rand() % 20;
		int fuel0 = fuel;        // fuel0 - fuel before teleportation
		fuel = fuel0 - (abs(coord_x - coord_x0) + abs(coord_y - coord_y0) + abs(coord_z - coord_z0));
		cout << "You have been teleported to: " << coord_x << ", " << coord_y << ", " << coord_z << ".\n";
		cout << "Fuel: " << fuel << ".\n";
	}
	
	double calculate_fill()
	{
		fill_price = (100.0 - fuel) * 0.3;
		return fill_price;
	}

	void set_fuel()
	{
		if (money >= fill_price)
		{
			money -= fill_price;
			fuel = 100;
			cout << "Your money: " << money << ".\n";
		}
		if (money < fill_price) cout << "You don't have enough money(\n";
	}

	bool gun_shop()
	{
		char shop;
		cout << "There are 5 guns in the sale:\n";
		cout << "1.Blaster - 50.\n";
		cout << "2.Laser gun - 70.\n";
		cout << "3.Energetic gun - 100.\n";
		cout << "4.Emi gun - 130.\n";
		cout << "5.Gauss gun - 160.\n";
		cout << "Your money - " << money << ".\n";
		cout << "Do you want to buy any gun? Enter + or -.\n";
		do cin >> shop; while (shop != '+' && shop != '-');
		if (shop == '+') return true;
		if (shop == '-') return false;
	}

	void buy_gun()
	{
		int number;
		cout << "Enter the number of gun, what you want to buy: ";
		do cin >> number; while (number != 1 && number != 2 && number != 3 && number != 4 && number != 5);
		if (number == 1)
		{
			if (money >= 50)
			{
				cout << "Your new gun is Blaster!\n";
				money -= 50;
				gun_damage = 20;
			}
			else if (money < 50) cout << "You don't have enough money(\n";
		}
		if (number == 2)
		{
			if (money >= 70)
			{
				cout << "Your new gun is Laser gun!\n";
				money -= 70;
				gun_damage = 40;
			}
			else if (money < 70) cout << "You don't have enough money(\n";
		}
		if (number == 3)
		{
			if (money >= 100)
			{
				cout << "Your new gun is Energetic gun!\n";
				money -= 100;
				gun_damage = 60;
			}
			else if (money < 100) cout << "You don't have enough money(\n";
		}
		if (number == 4)
		{
			if (money >= 130)
			{
				cout << "Your new gun is EMI gun!\n";
				money -= 130;
				gun_damage = 80;
			}
			else if (money < 130) cout << "You don't have enough money(\n";
		}
		if (number == 5)
		{
			if (money >= 160)
			{
				cout << "Your new gun is Gauss gun!\n";
				money -= 160;
				gun_damage = 100;
			}
			else if (money < 160) cout << "You don't have enough money(\n";
		}
	}

	void get_stats()
	{
		cout << "Fuel: " << fuel << ".\n";
		cout << "HP: " << hp << ".\n";
		cout << "Money: " << money << ".\n";
	}

  bool fight()
  {
    while (police_hp >0 && hp > 0)
    {
    police_hp -= gun_damage;
    hp -= POLICE_DAMAGE;
    }
    if (police_hp <= 0) 
    {
      cout << "Congratulations! You win the battle!\n";
      money += 30;
      return true;
    }
    else if (hp <= 0)
    {
      cout << "You lose(\n";
      cout << "Game over.\n";
      return false;
    }
  }

};

int main()
{
	Space_Pirate pirate;
	pirate.teleport();
	pirate.calculate_fill();
	if (pirate.gun_shop()) pirate.buy_gun();
	pirate.get_stats();
	return 0;
}
