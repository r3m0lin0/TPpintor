//////////////////pintor.h////////////////////
#pragma once
#include <iostream>
#include <ncurses.h>

class pintor{

public : 
void setup(); 
void setx(int x);
void sety(int y);
int getx();
int gety();
void draw();

private : 
int ax;
int ay;

};