class Enemy
{
public:
	Enemy();
	Enemy(const int hp);
	~Enemy();
	int GetHP()const { return hp; }
	//int GetAtk()const { return playerAtk; }
	void SetHP(const int hp) { this->hp = hp; }
private:
	int hp;
	//int playerAtk;
};