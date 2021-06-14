enum class PLAYERSKILL {
	NONE, POSTION, SKILL

};

class Player
{
public:
	Player(const int hp);
	~Player();
	int GetHP()const { return hp; }
	int GetAtk()const { return playerAtk; }
	void SetHP(const int hp) { this->hp = hp; }

private:
	int hp;
	int playerAtk;
};