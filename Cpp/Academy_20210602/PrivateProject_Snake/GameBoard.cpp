#include "GameBoard.h"


GameBoard::GameBoard()
{
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 20; j++)
		{
			if (i == 0 || i == 19 ||j == 0 || j == 19)
			{
				map[i][j] = MAPDATA::WALL;
			}
			else {
				map[i][j] = MAPDATA::EMPTY;
			}
		}
	}
	vector<Position> temp(3);
	snake = temp;
	vector<Position>::iterator it;
	it = snake.begin();
	snake[0] = Position(10, 10);
	snake[1] = Position(10, 11);
	snake[2] = Position(10, 12);
	map[10][10] = MAPDATA::SNAKE;
	map[10][11] = MAPDATA::SNAKE;
	map[10][12] = MAPDATA::SNAKE;
	currentSize = 3;
	currentLevel = 0;
}

State GameBoard::NextBehavior(int newPosX, int newPosY) {
	vector<Position>::iterator it;
	it = snake.begin();
	switch (map[newPosX][newPosY])
	{
	case MAPDATA::EMPTY:
		snake.insert(it, Position(newPosX, newPosY));
		map[newPosX][newPosY] = MAPDATA::SNAKE;
		map[snake.back().x][snake.back().y] = MAPDATA::EMPTY;
		snake.pop_back();
		text = "로 이동합니다.";
		return State::Moveable;
	case MAPDATA::SNAKE:
		text = "내몸에 부디쳤습니다 게임을 종료합니다.";
		return State::MeetSelf;
	case MAPDATA::WALL:
		text = "벽에 부디쳤습니다 게임을 종료합니다.";
		return State::MeetWall;
	case MAPDATA::FOOD:
		snake.insert(it, Position(newPosX, newPosY));
		map[newPosX][newPosY] = MAPDATA::SNAKE;
		text = "음식을 먹었습니다 길이가 한칸 늘어납니다.";
		hasFood = false;
		currentSize++;
		if (nextSize[currentLevel] < currentSize)
		{
			currentLevel++;
		}
		return State::MeetFood;
	default:
		text = "에러 1";
		return State::Error;
	}
	text = "에러 2";
	return State::Error;
}

void GameBoard::SetFood() {
	while (true)
	{
		int x = rand() % 18 + 1;
		int y = rand() % 18 + 1;

		if (map[x][y] == MAPDATA::EMPTY)
		{
			map[x][y] = MAPDATA::FOOD;
			hasFood = true;
			return;
		}

		
	}
}

State GameBoard::GetInput(eAsciiKey i)
{
	switch (i)
	{
	case eAsciiKey::EXTENDED_0x00:
		break;
	case eAsciiKey::ESC:
		break;
	case eAsciiKey::SPACE_BAR:
		break;
	case eAsciiKey::UP:
		return NextBehavior(snake.front().x - 1, snake.front().y);
	case eAsciiKey::LEFT:
		return NextBehavior(snake.front().x, snake.front().y - 1);
	case eAsciiKey::RIGHT:
		return NextBehavior(snake.front().x, snake.front().y + 1);
	case eAsciiKey::DOWN:
		return NextBehavior(snake.front().x + 1, snake.front().y);
	case eAsciiKey::EXTENDED_0xE0:
		break;
	default:
		return State::Error;
		break;
	}
	return State::Error;
}


//OnGUI();
void GameBoard::OnGUI()
{
	for (size_t i = 0; i < 20; i++)
	{
		for (size_t j = 0; j < 20; j++)
		{
			MAPDATA a = map[i][j];
			switch (a)
			{
			case MAPDATA::EMPTY:
				cout << "  ";
				break;
			case MAPDATA::SNAKE:
				cout << "◎";
				break;
			case MAPDATA::WALL:
				cout << "■";
				break;
			case MAPDATA::FOOD:
				cout << "★";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
	

	string s = "xmplr";
	string f = "ww";
	s.insert(0, f);

	cout << "======================================" << endl;
	cout << text << endl;
}
