#pragma once
class unit
{
protected:

	int m_att;
	int m_def;

public:
	unit();
	~unit();

	int getAtt() { return m_att; }
	void setAtt(int att) { m_att = att; }

	int getDef() { return m_def; }
	void setDef(int def) { m_def = def; }





};

