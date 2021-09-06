#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
private:
	double energy = 100;
	static int life;
	int speed = 1;
	static int posX;
	static int posY;
public:
	Game();
	double Damage();
	void Move();
	static void Die();
};
int Game::life = 10;
int Game::posX = 10;
int Game::posY = 10;

void Game::Move() {
	int n;
	cout << "���� ����� ��ġ�� (" << posX << ", " << posY << ") �Դϴ�.\n";
	cout << "���� �̵��Ͻǰǰ���?\n1. ����\n2. ������\n3. ��\n4. �Ʒ�\n5. ���ڸ��� �ִ´�.\n";
	cin >> n;
	switch (n)
	{
	case 1:
		posX--;
		break;
	case 2:
		posX++;
		break;
	case 3:
		posY--;
		break;
	case 4:
		posY++;
		break;
	case 5:
		cout << "����� ���ڸ����� ���׸��� ���ҽ��ϴ�. �� �������� ���̱���.\n";
		break;
	}
	Sleep(2000);
	system("cls");
}

void Game::Die() {
	life--;
	cout << "**������ 1 �����Ͽ� " << life << "�� �Ǿ����ϴ�." << endl << endl;

}
double Game::Damage() {
	double damaged = 0;

	if (energy > 0) {
		damaged += rand() % 100;
		energy -= damaged;
		cout << "�������� " << damaged << " �����Ͽ� " << energy << " �� �Ǿ����ϴ�.\n";
		if (energy < 0) {
			life--;
			energy = 100;
			cout << "������ 1 �����Ͽ� " << life << "�� �Ǿ����ϴ�." << endl << endl;

		}
	}
	return energy;
}

Game::Game()
{
	cout << "�������� " << energy << " �̸�, ������ " << life << "�� ĳ���Ͱ� ����������ϴ�.\n";
	while (life > 0)
	{
		Move();
		Damage();
	}
	cout << "\n\nGame Over";
	Sleep(2000);
	exit(0);
}

int main()
{
	Game c1;

	return 0;
}