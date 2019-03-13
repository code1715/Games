// Space pirates
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
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
public:
	int coord_x, coord_y, coord_z;
};

class Space_Pirate : Space_Ship
{
public:
	double fill_price;
	int repair_price;
	bool pursuit = 0;
	int fuel;
	int money;
	int gun_damage;
	int hp;
	
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
		int coord_x0 = coord_x;  // coord_x0 - coord_x before teleportation
		int coord_y0 = coord_y;  // coord_y0 - coord_y before teleportation
		int coord_z0 = coord_z;  // coord_z0 - coord_z before teleportation
		coord_x = rand() % 20;
		coord_y = rand() % 20;
		coord_z = rand() % 20;
		int fuel0 = fuel;        // fuel0 - fuel before teleportation
		fuel = fuel0 - (abs(coord_x - coord_x0) + abs(coord_y - coord_y0) + abs(coord_z - coord_z0));
		std::cout << "You have been teleported to: " << coord_x << ", " << coord_y << ", " << coord_z << "." << "\n";
		std::cout << "Fuel: " << fuel << "." << "\n";
	}
	
	double calculate_fill()
	{
		fill_price = (100.0 - fuel) * 0.3;
		return fill_price;
	}

	void fill()
	{
		if (money >= fill_price)
		{
			money -= fill_price;
			fuel = 100;
			std::cout << "Your money: " << money << "." <<"\n";
		}
		if (money < fill_price) std::cout << "You don't have enough money(" << "\n";
	}

	bool gun_shop()
	{
		char shop;
		std::cout << "There are 5 guns in the sale:" << "\n";
		std::cout << "1.Blaster - 50." << "\n";
		std::cout << "2.Laser gun - 70." << "\n";
		std::cout << "3.Energetic gun - 100." << "\n";
		std::cout << "4.Emi gun - 130." << "\n";
		std::cout << "5.Gauss gun - 160." << "\n";
		std::cout << "Your money - " << money << "." << "\n";
		std::cout << "Do you want to buy any gun? Enter + or -." << "\n";
		do std::cin >> shop; while (shop != '+' && shop != '-');
		if (shop == '+') return true;
		if (shop == '-') return false;
	}

	void buy_gun()
	{
		int number;
		std::cout << "Enter the number of gun, what you want to buy: ";
		std::cin >> number;
		while (number != 1 && number != 2 && number != 3 && number != 4 && number != 5)
		{
			std::cin >> number;
		}
		if (number == 1)
		{
			if (money >= 50)
			{
				std::cout << "Your new gun is Blaster!" << "\n";
				money -= 50;
				gun_damage = 20;
			}
			else if (money < 50) std::cout << "You don't have enough money(" << "\n";
		}
		if (number == 2)
		{
			if (money >= 70)
			{
				std::cout << "Your new gun is Laser gun!" << "\n";
				money -= 70;
				gun_damage = 40;
			}
			else if (money < 70) std::cout << "You don't have enough money(" << "\n";
		}
		if (number == 3)
		{
			if (money >= 100)
			{
				std::cout << "Your new gun is Energetic gun!" << "\n";
				money -= 100;
				gun_damage = 60;
			}
			else if (money < 100) std::cout << "You don't have enough money(" << "\n";
		}
		if (number == 4)
		{
			if (money >= 130)
			{
				std::cout << "Your new gun is EMI gun!" << "\n";
				money -= 130;
				gun_damage = 80;
			}
			else if (money < 130) std::cout << "You don't have enough money(" << "\n";
		}
		if (number == 5)
		{
			if (money >= 160)
			{
				std::cout << "Your new gun is Gauss gun!" << "\n";
				money -= 160;
				gun_damage = 100;
			}
			else if (money < 160) std::cout << "You don't have enough money(" << "\n";
		}
	}

	void get_stats()
	{
		std::cout << "Fuel: " << fuel << ".\n";
		std::cout << "HP: " << hp << ".\n";
		std::cout << "Money: " << money << ".\n";
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
