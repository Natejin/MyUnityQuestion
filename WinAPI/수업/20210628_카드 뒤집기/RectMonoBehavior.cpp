#include "RectMonoBehavior.h"

RectMonoBehavior::RectMonoBehavior()
	:MonoBehavior(), rc(new Rect(0,0,0,0)),
	isGravity(false), onGround(false), isCollision(true),
	currentlySpeed(Vector2(0, 0)), previousMove(Vector2(0, 0))

{
	//init();
}

RectMonoBehavior::RectMonoBehavior(double x, double y, double width, double height)
: MonoBehavior(), rc(new Rect(x,y,width,height)), rgb(0,0,0),
currentlySpeed(Vector2(0,0)), previousMove(Vector2(0,0)),
isGravity(false), onGround(false), isCollision(true)
{
	isKinetic = true;
}

void RectMonoBehavior::update()
{
	previousMove = currentlySpeed;
	if (this->isGravity&& !this->onGround)
	{
		if (fallSpeedMax >= previousMove.y)
		{
			previousMove += Vector2(0, gravity);
		}
	}
	currentlySpeed = previousMove;
}

void RectMonoBehavior::release()
{
}

void RectMonoBehavior::init()
{
	rc = new Rect();
}

void RectMonoBehavior::init(double x, double y, double width, double height)
{
	rc = new Rect(x, y, width, height);
}

void RectMonoBehavior::render(HDC* hdc)
{
	rc->Render(hdc);
}


bool RectMonoBehavior::CheckIntersect(RectMonoBehavior* rect) {
	RECT thisRECT = { (LONG)rc->left, (LONG)rc->top, (LONG)rc->right, (LONG)rc->bottom };
	RECT anotherRECT = { rect->rc->left, rect->rc->top, rect->rc->right, rect->rc->bottom };
	return IntersectRect(&g_RECT, &thisRECT, &anotherRECT);
}

//�浹�� �˻��ϰ� �浹�ȸ�ŭ �о��.
bool RectMonoBehavior::CheckIntersectAndEdit(RectMonoBehavior* rect)
{
	checkCollision = rc->Collided(rect->rc);
	if (checkCollision.x && checkCollision.y)
	{
		Translate();
		Translate(rect->previousMove);
		checkCollision = rc->Collided(rect->rc);
		rc->SetUpLTRBFromXY();
		rect->rc->SetUpLTRBFromXY();
		auto temp = rect->rc;

		//signal = -1;
		double push = 0.1;
		collisionTarget = rect;
		if (rc->bottom > temp->top) {
			//�Ʒ��� �ִ°��
			if (rc->bottom >= temp->bottom)
			{
				signal = 11;
				//�Ʒ� �߾�
				if (rc->left > temp->left && rc->right < temp->right)
				{
					signal = 111;
					if (checkCollision.GetBool())
					{
						rc->y = temp->bottom + rc->height;
					}
				}
				//7�ù���
				else if (rc->left < temp->left && rc->right < temp->right) {
					//7�� ����
					if (abs(rc->right - temp->left) > abs(rc->top - temp->bottom))
					{
						signal = 1121;
						if (checkCollision.GetBool())
						{
							rc->y = temp->bottom + rc->height;
						}
					}
					//7�þƷ���
					else {
						signal = 1122;
						if (checkCollision.GetBool())
						{
							rc->x = rect->rc->left - rc->width;
						}
					}
				
				}
				//5�ù���
				else if (rc->right > temp->right && rc->left > temp->left) {
					//5�þƷ���
					if (abs(rc->left - temp->right) > abs(rc->top - temp->bottom))
					{
						signal = 1131;
						if (checkCollision.GetBool())
						{
							rc->y = temp->bottom + rc->height;
						}
					}
					//5�ÿ���
					else {
						signal = 1132;
						if (checkCollision.GetBool())
						{
							rc->x = rect->rc->right + rc->width;
						}
					}
				}else{
					signal = 114;
				}
				onGround = false;
				if (previousMove.y < 0)
				{
					currentlySpeed.y = 0;
				}
			}
			//���� �ִ� ���
			else if (rc->top > temp->top && rc->bottom < temp->bottom)
			{
				//����
				if (rc->right < temp->right)
				{
					signal = 121;
					if (checkCollision.GetBool())
					{
						rc->x = rect->rc->left - rc->width - push;
					}
					if (previousMove.x > 0)
					{
						currentlySpeed.x = 0;
					}

				}
				//������
				else if (rc->left > temp->left) {
					signal = 122;
					if (checkCollision.GetBool())
					{
						rc->x = rect->rc->right + rc->width + push;
					}
					if (previousMove.x < 0)
					{
						currentlySpeed.x = 0;
					}
				}
				else {
					signal = 123;
				}
				onGround = false;
			}
			//���� �ִ� ���
			else {
				//�� �߾ӿ� �ִ°��
				if (rc->left > temp->left && rc->right < temp->right)
				{
					signal = 131;
					if (checkCollision.GetBool())
					{
						rc->y = temp->top - rc->height;

					}
				}
				//�� �߾ӿ��� ���ʿ� ġ�ߵ�
				else if (rc->left < temp->left && rc->right < temp->right) {


					if (abs(rc->right - temp->left) > abs(rc->bottom - temp->top))
					{
						signal = 1322;
						if (checkCollision.GetBool())
						{
							rc->y = temp->top - rc->height;
						}
					}
					else {
						signal = 1323;
						if (checkCollision.GetBool())
						{
							rc->x = rect->rc->left - rc->width - push;
						}
					}

				}
				//�� �߾ӿ��� ���ʿ� ġ�ߵ�
				else if (rc->right > temp->right && rc->left > temp->left) {
					if (abs(rc->left - temp->right) > abs(rc->bottom - temp->top))
					{
						signal = 1331;
						if (checkCollision.GetBool())
						{
							rc->y = temp->top - rc->height;
						}
					}
					else {
						signal = 1332;
						if (checkCollision.GetBool())
						{
							rc->x = rect->rc->right + rc->width + push;
						}
					}
				}
				else {
					signal = 114;
				}
				onGround = true;
				if (previousMove.y > 0)
				{
					currentlySpeed.y = 0;
				}
			}
			return true;
		}
	}
	//signal = -5;
	collisionTarget = nullptr;
	return false;
}

void RectMonoBehavior::Translate(Vector2 move)
{
	rc->Translate(move);
}

void RectMonoBehavior::Translate(double x, double y)
{
	rc->Translate(x,y);
}

void RectMonoBehavior::Translate()
{
	rc->Translate(previousMove);
}

void RectMonoBehavior::SetPos(Vector2 newPos)
{
	rc->SetPos(newPos);
}


void RectMonoBehavior::SetPos(double x, double y)
{
	rc->SetPos(x,y);
}


void RectMonoBehavior::RedoTranslate()
{
	rc->Translate(-previousMove.x,-previousMove.y);
}




