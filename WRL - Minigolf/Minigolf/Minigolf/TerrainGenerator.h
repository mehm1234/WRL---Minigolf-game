/*#pragma once

#include <iostream>
#include <glm\glm.hpp>

const int lenght = 500;
const int width = 500;
class TerrainGenerator
{
public:
	glm::vec3 indicies[2 * (width - 1)][2 * (lenght - 1)];
	glm::vec3 terrainVerticies[width][lenght];
	void GenerateTerrain(int seed);
	void CalculateIndicies();
};*/