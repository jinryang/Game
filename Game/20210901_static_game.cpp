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
	cout << "현재 당신의 위치는 (" << posX << ", " << posY << ") 입니다.\n";
	cout << "어디로 이동하실건가요?\n1. 왼쪽\n2. 오른쪽\n3. 위\n4. 아래\n5. 제자리에 있는다.\n";
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
		cout << "당신은 제자리에서 빙그르르 돌았습니다. 참 쓸데없는 짓이군요.\n";
		break;
	}
	Sleep(2000);
	system("cls");
}

void Game::Die() {
	life--;
	cout << "**생명이 1 감소하여 " << life << "이 되었습니다." << endl << endl;

}
double Game::Damage() {
	double damaged = 0;

	if (energy > 0) {
		damaged += rand() % 100;
		energy -= damaged;
		cout << "에너지가 " << damaged << " 감소하여 " << energy << " 이 되었습니다.\n";
		if (energy < 0) {
			life--;
			energy = 100;
			cout << "생명이 1 감소하여 " << life << "이 되었습니다." << endl << endl;

		}
	}
	return energy;
}

Game::Game()
{
	cout << "에너지가 " << energy << " 이며, 생명이 " << life << "인 캐릭터가 만들어졌습니다.\n";
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