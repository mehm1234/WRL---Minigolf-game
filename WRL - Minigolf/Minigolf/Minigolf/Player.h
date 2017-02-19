#pragma once
#define PI 3.14159265
#include "Actor.h"
//this class should be called ball as it will contain all the propeties of ball. 
class Player : public Actor
{
public:
	void Movement(float dt, int state);
	void setSpeed(float x);
	float getSpeed() { return speed; }
	void setDirX(float X);
	void setDirZ(float Z);
	float getDirX() { return dirX; }
	float getDirZ() { return dirZ; }
	Player(float x, float y, float z);
	~Player();
	void Update(float dt);
	void CollisionWithGround(float maxTerrainY, float minBallY);
	Face CollisionWithWalls(Face x, bool WallToTheRight);
	float force;
private:
	float dirX;
	float dirZ;
	float speed;
	float highestZ;
	float lowestZ, averageX;
	
	
};

