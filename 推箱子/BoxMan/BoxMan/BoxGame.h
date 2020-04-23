#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<Windows.h>
#include<iostream>
#include <sstream>

using namespace sf;
using namespace std;

#define WINDOW_HEIGHT 720	//窗口高度
#define WINDOW_WIDTH 1280	//窗口宽度
#define STAGE_HEIGHT 600    //界面高度
#define STAGE_WIDTH 400  	//界面宽度
#define SCALE 1             //缩放比例
#define GRIDSIZE 50         //贴图大小


typedef enum GridState
{
	_Block,        //游戏空地0
	_Wall,         //游戏墙体1
	_Seed,         //种子，果实2
	_People,       //人物3
	_Box,          //箱子4
	_PeoSeed,      //人物+种子 5
    _RedBox,       //箱子+种子 6


};


class BoxGame
{
public:
	BoxGame();
	~BoxGame();

	bool  gameOver, gameQuit;

	int score;

	sf::RenderWindow window;

	VideoMode mode = VideoMode::getDesktopMode();   //
	Vector2i ViewPos;
	Vector2i Loadposition;	//记录鼠标坐标

	Texture tBackGround, tPeople, tWall, tBlock, tBox, tRedBox, tSeed;  //纹理
	Sprite  sBackGround, sPeople, sWall, sBlock, sBox, sRedBox, sSeed; //精灵对象


	void Run();

	void Initial();

	void Draw();

	void Input();
	
	void Logic();
};
