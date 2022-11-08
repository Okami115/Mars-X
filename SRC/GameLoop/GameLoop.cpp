#include "GameLoop.h"
#include "raylib.h"
#include "../Explorer/Explorer.h"
#include "../Obstacles/Obstacles.h"


namespace OkamiIndustries
{

	extern int SetScene;
	extern Texture2D BackgroundGame;
	extern Texture2D Parallax1Game;
	extern Texture2D Parallax2Game;
	extern Texture2D Parallax3Game;
	extern Texture2D FloorGame;
	Vector2 BackgroundPos = { 0,0 };
	Vector2 Parallax1pos = { 0,0 };
	Vector2 Parallax1pos2 = { 1920,0 };
	Vector2 Parallax2pos = { 0,0 };
	Vector2 Parallax2pos2 = { 1920,0 };
	Vector2 Parallax3pos = { 0,0 };
	Vector2 Parallax3pos2 = { 1920,0 };
	Vector2 Floorpos = { 0,0 };
	Vector2 Floorpos2 = { 1920,0 };

	void GameLoop()
	{
		if (IsKeyPressed(KEY_ESCAPE))
		{
			SetScene = 0;
		}
		updateBackground();
		MoveExplorer();
		MoveObstacles();
	}

	void DrawGame()
	{
		DrawTextureEx(BackgroundGame, BackgroundPos, 0, 1, WHITE);
		DrawTextureEx(Parallax1Game, Parallax1pos, 0, 1, WHITE);
		DrawTextureEx(Parallax1Game, Parallax1pos2, 0, 1, WHITE);
		DrawTextureEx(Parallax2Game, Parallax2pos, 0, 1, WHITE);
		DrawTextureEx(Parallax2Game, Parallax2pos, 0, 1, WHITE);
		DrawTextureEx(Parallax3Game, Parallax3pos, 0, 1, WHITE);
		DrawTextureEx(Parallax3Game, Parallax3pos2, 0, 1, WHITE);
		DrawTextureEx(FloorGame, Floorpos, 0, 1, WHITE);
		DrawTextureEx(FloorGame, Floorpos2, 0, 1, WHITE);
		DrawExplorer();
		DrawObstacles();
	}

	void InitGame()
	{
		BackgroundGame = LoadTexture("C:/Users/tomas/Desktop/Mars X/Mars X/assets/Background.png");
		Parallax1Game = LoadTexture("C:/Users/tomas/Desktop/Mars X/Mars X/assets/parallax 1.png");
		Parallax2Game = LoadTexture("C:/Users/tomas/Desktop/Mars X/Mars X/assets/parallax 2.png");
		Parallax3Game = LoadTexture("C:/Users/tomas/Desktop/Mars X/Mars X/assets/parallax 3.png");
		FloorGame = LoadTexture("C:/Users/tomas/Desktop/Mars X/Mars X/assets/Floor.png");
		
	}

	static void updateBackground()
	{
		Parallax1pos.x -= 200* GetFrameTime();
		Parallax1pos2.x -= 200* GetFrameTime();
		Parallax2pos.x -= 400* GetFrameTime();
		Parallax2pos2.x -= 400* GetFrameTime();
		Parallax3pos.x -= 600* GetFrameTime();
		Parallax3pos2.x -= 600* GetFrameTime();
		Floorpos.x -= 800* GetFrameTime();
		Floorpos2.x -= 800* GetFrameTime();
		if (Parallax1pos.x < -1920)
		{
			Parallax1pos.x = 1920;
		}
		if (Parallax1pos2.x < -1920)
		{
			Parallax1pos2.x = 1920;
		}
		if (Parallax2pos.x < -1920)
		{
			Parallax2pos.x = 1920;
		}
		if (Parallax2pos2.x < -1920)
		{
			Parallax2pos2.x = 1920;
		}
		if (Parallax3pos.x < -1920)
		{
			Parallax3pos.x = 1920;
		}
		if (Parallax3pos2.x < -1920)
		{
			Parallax3pos2.x = 1920;
		}
		if (Floorpos.x < -1920)
		{
			Floorpos.x = 1920;
		}
		if (Floorpos2.x < -1920)
		{
			Floorpos2.x = 1920;
		}

	}
}