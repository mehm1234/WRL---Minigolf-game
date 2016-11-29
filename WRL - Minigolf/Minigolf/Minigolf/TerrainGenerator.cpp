/*#include "TerrainGenerator.h"

void TerrainGenerator::GenerateTerrain(int seed) {
	for (int i = 0; i < width; i++) {
		//std::cout << "\n";
		for (int j = 0; j < lenght; j++) {
			terrainVerticies[i][j].x = j * 5;
			terrainVerticies[i][j].y = 0;
			terrainVerticies[i][j].z = j * 5;
			//std::cout << " - " << terrainVerticies[i][j].x << " - " << terrainVerticies[i][j].z << " - ";
		}
	}
}

void TerrainGenerator::CalculateIndicies() {
	//for (int i = 0; i < width; i++) {
	//	for (int j = 0; j < lenght; j++) {
	//		indicies[i][j].x = (i * width) + (j + 1);
	//		indicies[i][j].y = ((i + 1) * width) + (j + 1);
	//		indicies[i][j].z = (i * width) + j;


	//		
	//		//std::cout << " - " << terrainVerticies[i][j].x << " - " << terrainVerticies[i][j].z << " - ";
	//	}
	//}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < lenght; j++) {
			indicies[i][j].x = (i * width) + (j + 1);
			indicies[i][j].y = ((i + 1) * width) + (j + 1);
			indicies[i][j].z = (i * width) + j;

			indicies[i][j+1].x = ((i + 1) * width) + (j + 1);
			indicies[i][j+1].y = ((i + 1) * width) + (j);
			indicies[i][j+1].z = (i * width) + j;

			
		}
	}
	for (int z = 0; z < 1; z++) {
		for (int k = 0; k < 50; k++) {
			std::cout << indicies[z][k].x << "," << indicies[z][k].y << "," << indicies[z][k].z << "\n";
		}
	}
	
	
	}*/