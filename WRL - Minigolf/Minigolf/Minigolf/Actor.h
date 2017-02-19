#pragma once
#include <glm\glm.hpp>

#define GRAVITY 19.81f

/* 
This class is a base for any objects in the game that would have properties such as scale, 
rotation, position etc. so pretty much anything, do not set any values directly in here. 

*/

struct Face { // A struct that contains 3 verticies that together makes a single mesh face
	glm::vec3 vertex1;
	glm::vec3 vertex2;
	glm::vec3 vertex3;
};

class Actor
{
public:
	

	glm::vec3 getPosition();
	void setPosition(float x, float y, float z);
	void UpdatePosition(float x, float y, float z);
	float getRotation();
	float getRotationInRads();
	void setRotation(float y, float x = 0, float z = 0);
	void SetVelocity(float x, float z, float y = 0);
	glm::vec3 getVelocity();


	void CollisionCheck();
	void ApplyGravity();
	void setDeltaTime(float x);


	void SetCollisionSphereSize(float x);//This function might be used to set the radius of the collision sphere. Depends on what collision system we will be using this function can stay or we can delete it. 
	void SetTypeOfCollision(int x);//1 = box collision 2 = Sphere collision
	void SetHP(int x);
	void AddHP(int x);
	void Update();
private:
	float dt;
	glm::vec3 Velocity;
	int HP;
	glm::vec3 Position;
	float Rotation;
	float EXP;
};