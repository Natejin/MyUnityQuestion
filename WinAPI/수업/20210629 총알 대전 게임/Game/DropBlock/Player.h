#pragma once
#include "../../RectMonoBehavior.h"

namespace DropPoop {
	class Player : public RectMonoBehavior
	{
	private:
		int hp;
		bool isAlive;

	public:
		double  jumpPower = 10;
		bool isJump;
		//bool isHighlight;
		double speed = 5;
		double acceclete = 1;
		//bool onGround;

		Vector2 groundCheckSize;
		Vector2 groundCheckPos;
		Vector2 input;
		Rect* groundChecker;


	public:
		Player();
		Player(double x, double y, double width, double height, double jumpPower = 10);
		~Player() {};

		bool CheckOnground(Rect* another);
		virtual void Init();
		virtual void Init(double x, double y, double width, double height, double jumpPower = 10);
		virtual void Update();
		virtual void Release();
		int GetHP() { return hp; }
		void SetHP(int hp) { this->hp = hp; }
		void SetHP() { hp--; }

		bool CheckAlive() { return isAlive; }
		void Resurrect() { isAlive = true; }
		void KillPlayer() { isAlive = false; }
		//virtual void render(HDC* hdc);
	};




}
