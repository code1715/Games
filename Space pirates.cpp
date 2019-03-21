// Space pirates
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <vector>
using std::cin;
using std::cout;
/*
Gun damage:
1.Bad gun - 5
2.Blaster - 10
3.Laser gun - 15
4.Energetic gun - 20
5.EMI gun - 25
6.Gauss gun - 30
*/

class Space_Ship
{
protected:
	int police_hp = 120;
	int police_damage;
	int merchant_hp = 40;
public:
	int coord_x, coord_y, coord_z;
	int p_coord_x, p_coord_y, p_coord_z;
	int number;
	int kills = 0;
};

class Space_Pirate : Space_Ship
{
private:
	double fill_price;
	int repair_price;
	bool pursuit = false;
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
		gun_damage = 5;
		money = 200;
		hp = 100;
		fuel = 100;
	}

	void teleport()
	{
		srand(time(NULL));
		if (pursuit == true)
		{
			cout << "Cops are pursuiting you, let's fight with them!\n";
			fight();
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

	void calculate_fill()
	{
		fill_price = (100.0 - fuel) * 0.3;
	}
	void calculate_repair()
	{
		repair_price = (100.0 - hp) * 0.3;
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

	void set_hp()
	{
		if (money >= repair_price)
		{
			money -= repair_price;
			hp = 100;
			cout << "Your money: " << money << ".\n";
		}
		if (money < repair_price) cout << "You don't have enough money(\n";
	}

	void gun_shop()
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
		if (shop == '+') buy_gun();
		if (shop == '-') return;
	}

	void buy_gun()
	{
		cout << "Enter the number of gun, what you want to buy: ";
		do cin >> number; while (number != 1 && number != 2 && number != 3 && number != 4 && number != 5);
		if (number == 1)
		{
			if (money >= 50)
			{
				cout << "Your new gun is Blaster!\n";
				money -= 50;
				gun_damage = 10;
			}
			else if (money < 50) cout << "You don't have enough money(\n";
		}

		if (number == 2)
		{
			if (money >= 70)
			{
				cout << "Your new gun is Laser gun!\n";
				money -= 70;
				gun_damage = 15;
			}
			else if (money < 70) cout << "You don't have enough money(\n";
		}

		if (number == 3)
		{
			if (money >= 100)
			{
				cout << "Your new gun is Energetic gun!\n";
				money -= 100;
				gun_damage = 20;
			}
			else if (money < 100) cout << "You don't have enough money(\n";
		}

		if (number == 4)
		{
			if (money >= 130)
			{
				cout << "Your new gun is EMI gun!\n";
				money -= 130;
				gun_damage = 25;
			}
			else if (money < 130) cout << "You don't have enough money(\n";
		}

		if (number == 5)
		{
			if (money >= 160)
			{
				cout << "Your new gun is Gauss gun!\n";
				money -= 160;
				gun_damage = 30;
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
		srand(time(NULL));
    if (gun_damage == 5)
		{
			while (police_hp > 0 && hp > 0)
			{
				police_damage = rand() % 10 + 0;
				cout << "You caused " << gun_damage << " damage. ";
				police_hp -= gun_damage;
				if (police_hp <= 0) break;
				cout << "Police hp: " << police_hp << ".\n";
				cout << "Police caused " << police_damage << " damage. ";
				hp -= police_damage;
				if (hp <= 0) break;
				cout << "Your hp: " << hp << ".\n";
			}
		}

    if (gun_damage == 10)
		{
			while (police_hp > 0 && hp > 0)
			{
				police_damage = rand() % 20 + 10;
				cout << "You caused " << gun_damage << " damage. ";
				police_hp -= gun_damage;
				if (police_hp <= 0) break;
				cout << "Police hp: " << police_hp << ".\n";
				cout << "Police caused " << police_damage << " damage. ";
				hp -= police_damage;
				if (hp <= 0) break;
				cout << "Your hp: " << hp << ".\n";
			}
		}

		if (gun_damage == 15)
		{
			while (police_hp > 0 && hp > 0)
			{
				police_damage = rand() % 20 + 30;
				cout << "You caused " << gun_damage << " damage. ";
				police_hp -= gun_damage;
				if (police_hp <= 0) break;
				cout << "Police hp: " << police_hp << ".\n";
				cout << "Police caused " << police_damage << " damage. ";
				hp -= police_damage;
				if (hp <= 0) break;
				cout << "Your hp: " << hp << ".\n";
			}
		}

		if (gun_damage == 20)
		{
			while (police_hp > 0 && hp > 0)
			{
				police_damage = rand() % 20 + 50;
				cout << "You caused " << gun_damage << " damage. ";
				police_hp -= gun_damage;
				if (police_hp <= 0) break;
				cout << "Police hp: " << police_hp << ".\n";
				cout << "Police caused " << police_damage << " damage. ";
				hp -= police_damage;
				if (hp <= 0) break;
				cout << "Your hp: " << hp << ".\n";
			}
		}

		if (gun_damage == 25)
		{
			hp = 120;
			police_hp = 90;
			while (police_hp > 0 && hp > 0)
			{
				police_damage = rand() % 20 + 70;
				cout << "You caused " << gun_damage << " damage. ";
				police_hp -= gun_damage;
				if (police_hp <= 0) break;
				cout << "Police hp: " << police_hp << ".\n";
				cout << "Police caused " << police_damage << " damage. ";
				hp -= police_damage;
				if (hp <= 0) break;
				cout << "Your hp: " << hp << ".\n";
			}
		}

		if (gun_damage == 30)
		{
			hp = 130;
			police_hp = 80;
			while (police_hp > 0 && hp > 0)
			{
				police_damage = rand() % 20 + 90;
				cout << "You caused " << gun_damage << " damage. ";
				police_hp -= gun_damage;
				if (police_hp <= 0) break;
				cout << "Police hp: " << police_hp << ".\n";
				cout << "Police caused " << police_damage << " damage. ";
				hp -= police_damage;
				if (hp <= 0) break;
				cout << "Your hp: " << hp << ".\n";
			}
		}

		if (police_hp <= 0 && hp >0)
		{
			cout << "Congratulations! You win the battle!\n";
			money += 30;
			return true;
		}

		else if (hp <= 0)
		{
			cout << "Cops have arrested you!\n";
			cout << "Game over.\n";
			return false;
		}

	}
	
	void merchant_fight()
	{
		cout << "You attacked the merchant.\n";
		while (merchant_hp > 0)
		{
			merchant_hp -= gun_damage;
			if (merchant_hp > 0) cout << "Merchant's hp: " << merchant_hp << "\n";
			else
			{
				money += 25;
				cout << "You earned 25 coins.\n";
			}
		} 
		kills++;
		check();
	}
	
	void check()
	{
	    char check_p;
	    if (kills > 5) pursuit = true;
	    cout << "Do you want to teleport? Enter + or -.\n";
		do cin >> check_p; while (check_p != '+' && check_p != '-'); 
	    if (check_p == '+') teleport();
	    else if (check_p == '-') fight();
	}

};

int main()
{
	Space_Pirate pirate;
	pirate.gun_shop();
	pirate.merchant_fight();
}
