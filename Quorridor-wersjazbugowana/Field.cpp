#include "Field.h"
#include <math.h>


Field::Field(int numer)
{
	kogo = 0;
	if (numer < 9)
		gora = false;
	else
		gora = true;
	if (numer > 71 && numer < 81)
		dol = false;
	else
		dol = true;
	if (numer % 9 == 0)
		lewo = false;
	else
		lewo = true;
	if (numer % 9 == 8)
		prawo = false;
	else
		prawo = true;
}

void Field::setKogo(int nkogo) {
	kogo = nkogo;
}
int Field::getKogo() {
	return kogo;
}
bool Field::getGora() {
	return gora;
}
void Field::setGora(bool ngora) {
	gora = ngora;
}
bool Field::getLewo() {
	return lewo;
}
void Field::setLewo(bool nlewo) {
	lewo = nlewo;
}
bool Field::getDol() {
	return dol;
}
void Field::setDol(bool ndol) {
	dol = ndol;
}
bool Field::getPrawo() {
	return prawo;
}
void Field::setPrawo(bool nprawo) {
	prawo = nprawo;
}
