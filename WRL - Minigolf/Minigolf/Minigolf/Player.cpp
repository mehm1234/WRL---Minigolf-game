#include "Player.h"
#include <iostream>
#define PI 3.14159265

Player::Player()
{
	setPosition(0.0f, 0.0f, 0.0f);
}


Player::~Player()
{
}

void Player::Movement(float dt, int state) {

}

void Player::setSpeed(float x) {
	speed = x;
}

void Player::Update(float dt) {

	

	ApplyGravity();

	dirX = cos((getRotation() + 90) * PI / 180);
	dirZ = sin((getRotation() + 90) * PI / 180);

	SetVelocity((dirX * speed) * dt, (dirZ * speed) * dt, getVelocity().y * dt);

	UpdatePosition(getVelocity().x, getVelocity().y, getVelocity().z);

	setSpeed(0);

	if (getRotation() > 360) setRotation(0.0f);
	if (getRotation() < 0) setRotation(360.0f);
}