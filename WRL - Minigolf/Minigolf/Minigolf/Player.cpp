#pragma once
#include "Player.h"
#include <iostream>
#include "mathCalc.h"


Player::Player(float x, float y, float z)
{
<<<<<<< HEAD
	setPosition(x, y, z);
	force = 0;
=======
	setPosition(0.0f, 0.0f, 0.0f);
	force = 0.0f;
>>>>>>> origin/master
}


Player::~Player()
{
}

void Player::Movement(float dt, int state)
{

}

void Player::setSpeed(float x)
{
	speed = x;
}

<<<<<<< HEAD
void Player::setDirX(float X) {
	dirX = X;
}

void Player::setDirZ(float Z) {
	dirZ = Z;
}

void Player::CollisionWithGround(float maxTerrainY, float minBallY) {
	if (maxTerrainY < getPosition().y - abs(minBallY)) {
		ApplyGravity();
	}
}
=======
void Player::Update(float dt) 
{
	ApplyGravity();
>>>>>>> origin/master

Face Player::CollisionWithWalls(Face Face, bool WallToTheRight) {
	highestZ = -923188371; // Set to enourmouse values because we dont know what coordinates the model verticies will be.
	lowestZ = 923188371;
	averageX = (Face.vertex1.x + Face.vertex2.x + Face.vertex3.x) / 3;
		if (Face.vertex1.z < lowestZ) lowestZ = Face.vertex1.z;
		if (Face.vertex2.z < lowestZ) lowestZ = Face.vertex2.z;
		if (Face.vertex3.z < lowestZ) lowestZ = Face.vertex3.z;

		if (Face.vertex1.z > highestZ) highestZ = Face.vertex1.z;
		if (Face.vertex2.z > highestZ) highestZ = Face.vertex2.z;
		if (Face.vertex3.z > highestZ) highestZ = Face.vertex3.z;

		if (getPosition().z > lowestZ && getPosition().z < highestZ) {
			if (WallToTheRight == true) {
				if (getPosition().x < averageX) {
					//std::cout << getPosition().z << "\t" << Face.vertex1.z << "\t" << Face.vertex2.z << "\t" << Face.vertex3.z << "\n";
					//std::cout << "normal: " << "\t" << CalculateFaceNormal(Face).x << "\t" << CalculateFaceNormal(Face).y << "\t" << CalculateFaceNormal(Face).z << "\n";
					glm::vec3 friction = { 0.03f, 0.03f, 0.03f };
					glm::vec3 restitution = { 0.03f, 0.03f, 0.03f };
					glm::vec3 u = restitution * (glm::dot(getVelocity(), CalculateFaceNormal(Face)) /*/ glm::dot(CalculateFaceNormal(Face), (CalculateFaceNormal(Face)))*/) * CalculateFaceNormal(Face);
					glm::vec3 w = friction * (getVelocity() - u);
					dirX = (w.x - u.x) / (abs(dirX) + abs(dirZ));
					dirZ = (w.z - u.z) / (abs(dirX) + abs(dirZ));
					//std::cout << "dirX " << getDirX() << "\tdirZ " << getDirZ() << "\n";
					std::cout << "W: " << w.x << "   " << w.z << "    U: " << u.x << "   " << u.z << "\n";
					//SetVelocity(w.x - u.x, w.z - u.z, 0.0f);
					return Face;
				}
			}
			else {
				if (getPosition().x > averageX) {
					//std::cout << getPosition().z << "\t" << Face.vertex1.z << "\t" << Face.vertex2.z << "\t" << Face.vertex3.z << "\n";
					//std::cout << "normal: " << "\t" << CalculateFaceNormal(Face).x << "\t" << CalculateFaceNormal(Face).y << "\t" << CalculateFaceNormal(Face).z << "\n";
					glm::vec3 friction = { 0.03f, 0.03f, 0.03f };
					glm::vec3 restitution = { 0.03f, 0.03f, 0.03f };
					glm::vec3 u = restitution * (glm::dot(getVelocity(), CalculateFaceNormal(Face)) /*/ glm::dot(CalculateFaceNormal(Face), (CalculateFaceNormal(Face)))*/) * CalculateFaceNormal(Face);
					glm::vec3 w = friction * (getVelocity() - u);
					dirX = (w.x - u.x) / (abs(dirX) + abs(dirZ));
					dirZ = (w.z - u.z) / (abs(dirX) + abs(dirZ));
					//std::cout << "dirX " << getDirX() << "\tdirZ " << getDirZ() << "\n";
					std::cout << "W: " << w.x << "   " << w.z << "    U: " << u.x << "   " << u.z << "\n";
					//SetVelocity(w.x - u.x, w.z - u.z, 0.0f);
					return Face;
				}
			}
			}
}

void Player::Update(float dt) {

	//dirX = cos((getRotation() + 90) * PI / 180);
	//dirZ = sin((getRotation() + 90) * PI / 180);

	SetVelocity((getDirX() * speed) * dt, (getDirZ() * speed) * dt, getVelocity().y * dt);

	setSpeed(getSpeed() * (0.9999));

	UpdatePosition(getVelocity().x, getVelocity().y, getVelocity().z);
	//setSpeed(0);
	//std::cout << "dirX " << getDirX() << "\tdirZ " << getDirZ() << "\n";
	if (getRotation() > 360) setRotation(0.0f);
	if (getRotation() < 0) setRotation(360.0f);
}