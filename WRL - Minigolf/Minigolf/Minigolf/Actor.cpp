#include "Actor.h"

glm::vec3 Actor::getPosition() {
	return Position;
}

void Actor::setPosition(float x, float y, float z) {
	Position.x = x;
	Position.y = y;
	Position.z = z;
}

void Actor::UpdatePosition(float x, float y, float z) {
	Position.x += x;
	Position.y += y;
	Position.z += z;
}

float Actor::getRotation() {
	return Rotation;
}

float Actor::getRotationInRads() {
	return Rotation * 3.14159265 / 180;
}

void Actor::setRotation(float y, float x, float z) {
	Rotation += y;
}

void Actor::SetVelocity(float x, float z, float y) {
	Velocity.x = x;
	Velocity.z = z;
	Velocity.y = y;
}

glm::vec3 Actor::getVelocity() {
	return Velocity;
}

void Actor::CollisionCheck() {
	if (Position.y <= 0.0f) Position.y = 0;
}

void Actor::ApplyGravity() {
	if (Position.y > 0.0f) {
		float gStrenght = Position.y - 0.0f; //calculate the distance from the ground 
		Velocity.y = -(GRAVITY * gStrenght);
	}
}

void Actor::setDeltaTime(float x) {
	dt = x;
}

void Actor::SetHP(int x) {
	HP = x;
}

void Actor::AddHP(int x) {
	HP += x;
}

void Actor::Update() {

}