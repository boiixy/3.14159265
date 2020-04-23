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

#define WINDOW_HEIGHT 25	//���ڸ߶�
#define WINDOW_WIDTH 80		//���ڿ��
#define STAGE_HEIGHT 600		//����߶�
#define STAGE_WIDTH 400  	//������
#define SCALE 1

const int width = STAGE_WIDTH;
const int height = STAGE_HEIGHT;
int sceneNumber;
bool  gameOver, gameQuit;

VideoMode mode = VideoMode::getDesktopMode();
sf::RenderWindow window(sf::VideoMode(width, height), ("by lancer"));  //���ô���
Vector2i ViewPos;
Vector2i Loadposition;	//��¼�������

Texture tBackGround, T_people, T_wall, T_blank, T_end, T_box, T_redbox;  //����
Sprite S_mainBackground, S_people, S_wall, sBlock, S_end, S_box, S_redbox;   //�������


////��¼��ͼ
//int map[7][9] = {
//		{0,0,1,1,1,1,0,0,0},  //0  �յ�
//		{1,1,1,0,0,1,1,0,0},  //1  ǽ
//		{1,0,3,3,0,0,1,1,1},  //3  Ŀ�ĵ�
//		{1,0,7,3,7,0,0,0,1},  //4  ����
//		{1,5,4,4,3,4,4,0,1},  //5  ��
//		{1,0,0,1,1,0,0,0,1},  //7  ����+Ŀ�ĵ� 
//		{1,1,1,1,1,1,1,1,1} }; //8  ��+Ŀ�ĵ�


void initial()
{

	window.setFramerateLimit(600);  //���ƴ��ڸ���Ƶ�ʣ�ÿ������Ŀ��֡��
	ViewPos.x = (mode.width - STAGE_WIDTH * SCALE) / 2;
	ViewPos.y = (mode.height - STAGE_HEIGHT * SCALE) / 2;
	window.setPosition(ViewPos);


	if (!tBackGround.loadFromFile("date/images/background2.png"))
	{
		cout << "û���ҵ�������ͼ" << endl;
	}
	S_mainBackground.setTexture(tBackGround);  //���þ����������
	S_mainBackground.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!T_people.loadFromFile("date/images/people.jpg"))
	{
		cout << "û���ҵ����˹�" << endl;
	}
	S_people.setTexture(T_people);  //���þ����������
	S_people.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!T_wall.loadFromFile("date/images/wall.jpg"))
	{
		cout << "û���ҵ�ǽ��" << endl;
	}
	S_wall.setTexture(T_wall);  //���þ����������
	S_wall.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!T_blank.loadFromFile("date/images/blank.jpg"))
	{
		cout << "û���ҵ��ذ�" << endl;
	}
	sBlock.setTexture(T_blank);  //���þ����������
	sBlock.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!T_end.loadFromFile("date/images/end.jpg"))
	{
		cout << "û���ҵ�С��" << endl;
	}
	S_end.setTexture(T_end);  //���þ����������
	S_end.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!T_box.loadFromFile("date/images/box.jpg"))
	{
		cout << "û���ҵ�����" << endl;
	}
	S_box.setTexture(T_box);  //���þ����������
	S_box.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!T_redbox.loadFromFile("date/images/redbox.jpg"))
	{
		cout << "û���ҵ�����" << endl;
	}
	S_redbox.setTexture(T_redbox);  //���þ����������
	S_redbox.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);




	gameOver = false;
	gameQuit = false;
	sceneNumber = 2;

}
void Input()
{
	sf::Event event;//event types ����windows��keyboard��mouse��4����Ϣ
					   //ͨ��bool Window::pollEvent(sf::Event&Event) �Ӵ���ѯ�ʣ�polled���¼�
					   //�����һ���¼��ȴ������ú���������true�������¼����������(filled)�¼����ݡ�
					   //������ǣ���ú�������false��ͬ����Ҫ����Ҫ��ע�⣬һ�ο����ж���¼���������Ǳ��벶��ÿ�����ܵ��¼���
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();                       //�رմ��� ���ڿ����ƶ���������С����С�����������Ҫ�رգ���Ҫ�Լ�ȥ����close��������
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
	//������Ϸ��ʼ����


	//������Ϸ������
	int map[7][9] = {
		{0,0,1,1,1,1,0,0,0},  //0  �յ�
		{1,1,1,0,0,1,1,0,0},  //1  ǽ
		{1,0,3,3,0,0,1,1,1},  //3  Ŀ�ĵ�
		{1,0,7,3,7,0,0,0,1},  //4  ����
		{1,5,4,4,3,4,4,0,1},  //5  ��
		{1,0,0,1,1,0,0,0,1},  //7  ����+Ŀ�ĵ� 
		{1,1,1,1,1,1,1,1,1} }; //8  ��+Ŀ�ĵ�

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
		case 1://��ʼ����
			Logic();
			Input();
			draw();
			break;
		case 2://��Ϸ����
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
