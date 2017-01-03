#pragma once

#include "Actor.h"
//this class should be called ball as it will contain all the propeties of ball. 
class Player : public Actor
{
public:
	void Movement(float dt, int state);
	void setSpeed(float x);
	Player();
	~Player();
	void Update(float dt);


	float force;
	float ballX;
	float ballZ;

private:
	float dirX;
	float dirZ;
	float speed;
};

