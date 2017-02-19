#pragma once
#include <glm\glm.hpp>
#include "Actor.h"

glm::vec3 CalculateFaceNormal(Face triangle)
{
	glm::vec3 U = triangle.vertex2 - triangle.vertex1;
	glm::vec3 V = triangle.vertex3 - triangle.vertex1;

	glm::vec3 normal;
	normal.x = ((U.y * V.z) - (U.z * V.y));
	normal.y = ((U.z * V.x) - (U.x * V.z));
	normal.z = ((U.x * V.y) - (U.y * V.x));

	return normal;
}

