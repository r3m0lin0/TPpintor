#include <pintor.h>

void pintor::setx(int x) { ax = x; }
void pintor::sety(int y) { ay = y; }
int pintor::getx() { return ax; }
int pintor::gety() { return ay; }

void pintor::setup()
{ ax = 60; ay = 39;}

void pintor::draw()
{ mvaddch(ay, ax, '°\_(◔︣‿◔︣)_/°');}

