#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<Windows.h>
#include<iostream>
#include <sstream>

using namespace sf;
using namespace std;

#define WINDOW_HEIGHT 720	//���ڸ߶�
#define WINDOW_WIDTH 1280	//���ڿ��
#define STAGE_HEIGHT 600    //����߶�
#define STAGE_WIDTH 400  	//������
#define SCALE 1             //���ű���
#define GRIDSIZE 50         //��ͼ��С


typedef enum GridState
{
	_Block,        //��Ϸ�յ�0
	_Wall,         //��Ϸǽ��1
	_Seed,         //���ӣ���ʵ2
	_People,       //����3
	_Box,          //����4
	_PeoSeed,      //����+���� 5
    _RedBox,       //����+���� 6


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
	Vector2i Loadposition;	//��¼�������

	Texture tBackGround, tPeople, tWall, tBlock, tBox, tRedBox, tSeed;  //����
	Sprite  sBackGround, sPeople, sWall, sBlock, sBox, sRedBox, sSeed; //�������


	void Run();

	void Initial();

	void Draw();

	void Input();
	
	void Logic();
};
