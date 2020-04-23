#include "BoxGame.h"

int main()
{
	BoxGame Mine;
	while (Mine.window.isOpen())
	{
		Mine.Run();
	}

}




/*#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<Windows.h>
#include<iostream>
#include <sstream>

using namespace sf;
using namespace std;

#define WINDOW_HEIGHT 25	//窗口高度
#define WINDOW_WIDTH 80		//窗口宽度
#define STAGE_HEIGHT 600		//界面高度
#define STAGE_WIDTH 400  	//界面宽度
#define SCALE 1

const int width = STAGE_WIDTH;
const int height = STAGE_HEIGHT;
int sceneNumber;
bool  gameOver, gameQuit;

VideoMode mode = VideoMode::getDesktopMode();
sf::RenderWindow window(sf::VideoMode(width, height), ("by lancer"));  //设置窗口
Vector2i ViewPos;
Vector2i Loadposition;	//记录鼠标坐标

Texture tBackGround, T_people, T_wall, T_blank, T_end, T_box, T_redbox;  //纹理
Sprite S_mainBackground, S_people, S_wall, sBlock, S_end, S_box, S_redbox;   //精灵对象


////记录地图
//int map[7][9] = {
//		{0,0,1,1,1,1,0,0,0},  //0  空地
//		{1,1,1,0,0,1,1,0,0},  //1  墙
//		{1,0,3,3,0,0,1,1,1},  //3  目的地
//		{1,0,7,3,7,0,0,0,1},  //4  箱子
//		{1,5,4,4,3,4,4,0,1},  //5  人
//		{1,0,0,1,1,0,0,0,1},  //7  箱子+目的地 
//		{1,1,1,1,1,1,1,1,1} }; //8  人+目的地


void initial()
{

	window.setFramerateLimit(600);  //控制窗口更新频率，每秒设置目标帧数
	ViewPos.x = (mode.width - STAGE_WIDTH * SCALE) / 2;
	ViewPos.y = (mode.height - STAGE_HEIGHT * SCALE) / 2;
	window.setPosition(ViewPos);


	if (!tBackGround.loadFromFile("date/images/background2.png"))
	{
		cout << "没有找到主背景图" << endl;
	}
	S_mainBackground.setTexture(tBackGround);  //设置精灵对象纹理
	S_mainBackground.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!T_people.loadFromFile("date/images/people.jpg"))
	{
		cout << "没有找到主人公" << endl;
	}
	S_people.setTexture(T_people);  //设置精灵对象纹理
	S_people.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!T_wall.loadFromFile("date/images/wall.jpg"))
	{
		cout << "没有找到墙体" << endl;
	}
	S_wall.setTexture(T_wall);  //设置精灵对象纹理
	S_wall.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!T_blank.loadFromFile("date/images/blank.jpg"))
	{
		cout << "没有找到地板" << endl;
	}
	sBlock.setTexture(T_blank);  //设置精灵对象纹理
	sBlock.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!T_end.loadFromFile("date/images/end.jpg"))
	{
		cout << "没有找到小球" << endl;
	}
	S_end.setTexture(T_end);  //设置精灵对象纹理
	S_end.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!T_box.loadFromFile("date/images/box.jpg"))
	{
		cout << "没有找到箱子" << endl;
	}
	S_box.setTexture(T_box);  //设置精灵对象纹理
	S_box.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!T_redbox.loadFromFile("date/images/redbox.jpg"))
	{
		cout << "没有找到箱子" << endl;
	}
	S_redbox.setTexture(T_redbox);  //设置精灵对象纹理
	S_redbox.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);




	gameOver = false;
	gameQuit = false;
	sceneNumber = 2;

}
void Input()
{
	sf::Event event;//event types 包括windows、keyboard、mouse、4类消息
					   //通过bool Window::pollEvent(sf::Event&Event) 从窗口询问（polled）事件
					   //如果有一个事件等待处理，该函数将返回true，并且事件变量将填充(filled)事件数据。
					   //如果不是，则该函数返回false。同样重要的是要更注意，一次可能有多个事件，因此我们必须捕获每个可能的事件。
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();                       //关闭窗口 窗口可以移动、调整大小和最小化。但是如果要关闭，需要自己去调用close（）函数
			gameOver = true;
			gameQuit = true;
		}
	}


}
void Logic()
{

}

void draw()
{
	window.clear();
	//绘制游戏开始界面


	//绘制游戏主界面
	int map[7][9] = {
		{0,0,1,1,1,1,0,0,0},  //0  空地
		{1,1,1,0,0,1,1,0,0},  //1  墙
		{1,0,3,3,0,0,1,1,1},  //3  目的地
		{1,0,7,3,7,0,0,0,1},  //4  箱子
		{1,5,4,4,3,4,4,0,1},  //5  人
		{1,0,0,1,1,0,0,0,1},  //7  箱子+目的地 
		{1,1,1,1,1,1,1,1,1} }; //8  人+目的地

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			switch (map[i][j])
			{
			case 0:
				/*putimage(i * 50, j * 50, &blank);
				sBlock.setPosition(i * 50, j * 50);
				window.draw(sBlock);
				break;
			case 1:
				//putimage(i * 50, j * 50, &wall);
				S_wall.setPosition(i * 50, j * 50);
				window.draw(S_wall);
				break;
			case 3:
				//putimage(i * 50, j * 50, &end);
				S_end.setPosition(i * 50, j * 50);
				window.draw(S_end);
				break;
			case 4:
				//putimage(i * 50, j * 50, &box);
				S_box.setPosition(i * 50, j * 50);
				window.draw(S_box);
				break;
			case 5:
				//putimage(i * 50, j * 50, &people);
				S_people.setPosition(i * 50, j * 50);
				window.draw(S_people);
				break;
			case 7:
				//putimage(i * 50, j * 50, &redbox);
				S_redbox.setPosition(i * 50, j * 50);
				window.draw(S_redbox);
				break;
			case 8:
				//putimage(i * 50, j * 50, &people);
				sBlock.setPosition(i * 50, j * 50);
				window.draw(sBlock);
				break;
			}
		}
		printf("\n");
	}
	window.display();
}


int main()
{
	initial();

	while (window.isOpen() && gameOver == false)
	{
		switch (sceneNumber)
		{
		case 1://开始界面
			Logic();
			Input();
			draw();
			break;
		case 2://游戏界面
			Logic();
			Input();
			draw();
			break;
		default:
			break;
		}
	}
	return 0;
}*/
