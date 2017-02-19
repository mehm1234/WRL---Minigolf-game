// Std. Includes
#include <string>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// GL includes
#include "Shader.h"
#include "Camera.h"
#include "Model.h"
#include "TerrainGenerator.h"
#include "Player.h"

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other Libs
#include <SOIL/SOIL.h>
//TEST VARIABLES

bool loop = true;
int i = 0;

bool moving = true;
bool shoot = true;




// Properties
GLuint screenWidth = 800, screenHeight = 600;

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void Do_Movement();

// Camera
Camera camera(true ,glm::vec3(0.0f, 0.0f, 3.0f));
bool keys[1024];
GLfloat lastX = 400, lastY = 300;
bool firstMouse = true;

int xloop = 0, zloop = 0;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

Player player(-25.19f, 0.0f, -82.23f);
int main()
{

	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "Minigolf", nullptr, nullptr); // Windowed
	glfwMakeContextCurrent(window);

	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// Options
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// Initialize GLEW to setup the OpenGL Function pointers
	glewExperimental = GL_TRUE;
	glewInit();

	// Define the viewport dimensions
	glViewport(0, 0, screenWidth, screenHeight);

	// Setup some OpenGL options
	glEnable(GL_DEPTH_TEST);

	// Setup and compile our shaders
	Shader shader("ModelLoading.vs", "ModelLoading.frag");

	// Load models
	Model ourModel("resources/models/Ball/ball.obj");
	Model VillageModel("resources/models/First Level/Platform/Platform_levelone2.obj");
	Model LeftWall_L1("resources/models/First Level/Walls/LeftWallPlane_Triangulate.obj");
	Model RightWall_L1("resources/models/First Level/Walls/rightWall2.obj");
	Face LeftWallFaces[32 /*For some reason cannot use models member variables*/];
	Face RightWallFaces_L1[32];
	// Draw in wireframe
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		//TESTING AREA
		
		/*std::cout << "Number of Verticies: " << ourModel.NumberOfVerticies << "\n";
		std::cout << "Number of Faces: " << LeftWall_L1.NumberOfFaces << "\n";
		std::cout << "Number of Meshes: " << ourModel.NumberOfMeshes << "\n";
		std::cout << "Size of vector: " << ourModel.TEST_Indi.size() << "\n\n\n";*/
		//ourModel.TEST_Indi;
		//std::cout << ourModel.TEST_Indi[1].x << "\n";
		
		//std::cout << player.getPosition().x << "\t" << player.getPosition().z << "\n";

		for (xloop; xloop < LeftWall_L1.NumberOfFaces; xloop++) {
			LeftWallFaces[xloop].vertex1 = LeftWall_L1.TEST_Indi[xloop * 3];
			LeftWallFaces[xloop].vertex2 = LeftWall_L1.TEST_Indi[(xloop * 3) + 1];
			LeftWallFaces[xloop].vertex3 = LeftWall_L1.TEST_Indi[(xloop * 3) + 2];

		}

		for (zloop; zloop < RightWall_L1.NumberOfFaces; zloop++) {
			RightWallFaces_L1[zloop].vertex1 = RightWall_L1.TEST_Indi[zloop * 3];
			RightWallFaces_L1[zloop].vertex2 = RightWall_L1.TEST_Indi[(zloop * 3) + 1];
			RightWallFaces_L1[zloop].vertex3 = RightWall_L1.TEST_Indi[(zloop * 3) + 2];

		}

		for (int z = 0; z < LeftWall_L1.NumberOfFaces; z++) {
			player.CollisionWithWalls(LeftWallFaces[z], true);
		}
		
		for (int y = 0; y < RightWall_L1.NumberOfFaces; y++) {
			player.CollisionWithWalls(RightWallFaces_L1[y], false);
		}
		//if (loop == true) {
		//	for (i; i < LeftWall_L1.TEST_Indi.size(); i++) {
		//		if (i == 0) {
		//			std::cout << "Number of Verticies: " << ourModel.NumberOfVerticies << "\n";
		//			std::cout << "Number of Faces: " << ourModel.NumberOfFaces << "\n";
		//			std::cout << "Number of Meshes: " << ourModel.NumberOfMeshes << "\n";
		//			std::cout << "Size of vector: " << ourModel.TEST_Indi.size() << "\n";
		//		}
		//		//if(player.getPosition().x < LeftWall_L1.TEST_Indi[i].x)
		//		std::cout << "Vertex " << i << " = \t" << LeftWall_L1.TEST_Indi[i].x << "\t" << LeftWall_L1.TEST_Indi[i].y << "\t" << LeftWall_L1.TEST_Indi[i].z << "\n";
		//		if (i == LeftWall_L1.TEST_Indi.size()) {
		//			loop = false;
		//		}
		//	}
		//}
	
		//^^^^^^^^^^^^^^^^^^^^^^^^^^^^

		// Set frame time
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// Check and call events
		glfwPollEvents();
		Do_Movement();
		player.setDeltaTime(deltaTime);
		player.CollisionWithGround((VillageModel.max_position.y - 9.2f), ourModel.min_position.y);
		player.Update(deltaTime);
		// Clear the colorbuffer
		glClearColor(1.0f, 0.00f, 0.00f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.Use();   // <-- Don't forget this one!
						// Transformation matrices
		glm::mat4 projection = glm::perspective(camera.Zoom, (float)screenWidth / (float)screenHeight, 0.1f, 10000.0f);
		GLfloat radius = 50.0f;
		GLfloat camX = -sin(-player.getRotationInRads()) * radius;
		GLfloat camZ = -cos(-player.getRotationInRads()) * radius;
		glm::mat4 view = glm::lookAt(glm::vec3(player.getPosition().x + camX, 20.0f, player.getPosition().z + camZ), glm::vec3(player.getPosition().x, player.getPosition().y, player.getPosition().z), glm::vec3(0.0f, 1.0f, 0.0f));
		//glm::mat4 view = camera.GetViewMatrix();
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "view"), 1, GL_FALSE, glm::value_ptr(view));

		// Draw the loaded model
		glm::mat4 model;
		
		model = glm::translate(model, glm::vec3(player.getPosition().x, player.getPosition().y, player.getPosition().z)); // Translate it down a bit so it's at the center of the scene
		model = glm::rotate(model, -player.getRotation(), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::scale(model, glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(model));
		ourModel.Draw(shader);

		glm::mat4 VillageTransform;
		VillageTransform = glm::translate(VillageTransform, glm::vec3(0.0f, -9.2f, 0.0f));
		//VillageTransform = glm::scale(VillageTransform, glm::vec3(1.0f, 1.0f, 1.0f));
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(VillageTransform));
		VillageModel.Draw(shader);
		

		glm::mat4 LeftWallTransform;
		LeftWallTransform = glm::translate(LeftWallTransform, glm::vec3(0.0f, -9.0f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(LeftWallTransform));
		LeftWall_L1.Draw(shader);

		glm::mat4 RightWallTransform;
		RightWallTransform = glm::translate(RightWallTransform, glm::vec3(0.0f, -9.2f, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(RightWallTransform));
		RightWall_L1.Draw(shader);

		
		

		// Swap the buffers
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

#pragma region "User input"

// Moves/alters the camera positions based on user input
void Do_Movement()
{
	if (player.getSpeed() <= 0.03) {
		if (keys[GLFW_KEY_UP])
		{
			player.setSpeed(40);
			player.setDirX(cos((player.getRotation() + 90) * PI / 180));
			player.setDirZ(sin((player.getRotation() + 90) * PI / 180));

		}
		if (keys[GLFW_KEY_DOWN])
		{
			player.setSpeed(-14);
		}
		if (keys[GLFW_KEY_LEFT])
		{
			player.setRotation(-0.08);
		}
		if (keys[GLFW_KEY_RIGHT])
		{
			player.setRotation(0.08);
		}
		if (keys[GLFW_KEY_P])
		{
			player.setPosition(player.getPosition().x, 15.0f, player.getPosition().z);
		}
		//Shooting
		if (keys[GLFW_KEY_SPACE] == GLFW_PRESS)
		{
			if (shoot = true)
			{
				player.force += 1.0f;
				if (player.force == 100)
				{
					player.force = 0;
				}
			}
			else if (shoot = false)
			{
				player.force == 0;
			}
		}

		if (keys[GLFW_KEY_SPACE] == GLFW_RELEASE)
		{
			//player.setSpeed(player.force);

			if (moving = true)
			{
				if (player.force > 0)
				{
					player.force -= 1.0f;
					if (player.force >= 0)
					{
						player.setDirX(cos((player.getRotation() + 90) * PI / 180));
						player.setDirZ(sin((player.getRotation() + 90) * PI / 180));
						player.setSpeed(player.force);
					}
				}
			}
		}

		while (1)
		{
			cout << player.force << "\n";
			break;
		}
		//////Shootig



	}
	// Camera controls
	/*
	if (keys[GLFW_KEY_W])

		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (keys[GLFW_KEY_S])
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (keys[GLFW_KEY_A])
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (keys[GLFW_KEY_D])
		camera.ProcessKeyboard(RIGHT, deltaTime);
	*/
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if (action == GLFW_PRESS)
		keys[key] = true;
	else if (action == GLFW_RELEASE)
		keys[key] = false;
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

		player.setRotation(xoffset);

	camera.ProcessMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}

#pragma endregion