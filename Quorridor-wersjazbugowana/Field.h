#pragma once
class Field
{
private:
	int kogo;//1- g1 2- g2 0- wolne
	bool gora;
	bool lewo;
	bool dol;
	bool prawo;
public:
	Field(int numer);
	void setKogo(int nkogo);
	int getKogo();
	bool getGora();
	void setGora(bool ngora);
	bool getLewo();
	void setLewo(bool nlewo);
	bool getDol();
	void setDol(bool ndol);
	bool getPrawo();
	void setPrawo(bool nprawo);
};

