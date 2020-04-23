#include "BoxGame.h"



//地图数组
static int Map[7][9]
{
	{0,0,1,1,1,1,0,0,0},  //0  空地
	{1,1,1,0,0,1,1,0,0},  //1  墙
	{1,0,2,2,0,0,1,1,1},  //2  目的地
	{1,0,2,3,2,0,0,0,1},  //4  箱子
	{1,0,4,4,0,4,4,0,1},  //3  人
	{1,0,0,1,1,0,0,0,1},  //6  箱子+目的地 
	{1,1,1,1,1,1,1,1,1},  //5  人+目的地
};

BoxGame::BoxGame()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), L"MineSweepwe by 包效尹");

}


BoxGame::~BoxGame()
{

}

void BoxGame::Run()
{
	do
	{
		Initial();

		while (window.isOpen() && gameOver == false)
		{
			Input();

			Logic();

			Draw();

		}
	} while (!gameQuit);
}

void BoxGame::Initial()
{
	if (!tBackGround.loadFromFile("date/images/background2.jpg"))
	{
		cout << "没有找到主背景图" << endl;
	}
	sBackGround.setTexture(tBackGround);      //设置精灵对象纹理
	sBackGround.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!tPeople.loadFromFile("date/images/people.jpg"))
	{
		cout << "没有找到主人公" << endl;
	}
	sPeople.setTexture(tPeople);          //设置精灵对象纹理
	sPeople.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!tWall.loadFromFile("date/images/wall.jpg"))
	{
		cout << "没有找到墙体" << endl;
	}
	sWall.setTexture(tWall);           //设置精灵对象纹理
	sWall.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!tBlock.loadFromFile("date/images/blank.jpg"))
	{
		cout << "没有找到地板" << endl;
	}
	sBlock.setTexture(tBlock);  //设置精灵对象纹理
	sBlock.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!tSeed.loadFromFile("date/images/end.jpg"))
	{
		cout << "没有找到小球" << endl;
	}
	sSeed.setTexture(tSeed);  //设置精灵对象纹理
	sSeed.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!tBox.loadFromFile("date/images/box.jpg"))
	{
		cout << "没有找到箱子" << endl;
	}
	sBox.setTexture(tBox);  //设置精灵对象纹理
	sBox.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);


	if (!tRedBox.loadFromFile("date/images/redbox.jpg"))
	{
		cout << "没有找到箱子" << endl;
	}
	sRedBox.setTexture(tRedBox);  //设置精灵对象纹理
	sRedBox.setScale(SCALE, SCALE);       //设置精灵对象缩放
	//S_mainBackground.setOrigin(0, 0);

}

void BoxGame::Input()
{

	int k, l;  //记录people的位置

	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
			gameQuit = true;
		}
		if (event.type == sf::Event::EventType::KeyReleased&&event.key.code == sf::Keyboard::Escape)
		{
			window.close();
			gameQuit = true;
		}

		for (int i=0;i<7;i++)
			for (int j=0;j<9;j++)
			{
				if (Map[i][j]==_People||Map[i][j]==_PeoSeed)
				{
					k = i;
					l = j;
				}
			}

		if (event.type==sf::Event::EventType::KeyReleased&&event.key.code==sf::Keyboard::W||event.key.code == sf::Keyboard::Up)   //向上按键
		{
			//人左面是空地、//人左面是种子
			if (Map[k][l - 1] == _Block || Map[k][l - 1] == _Seed)
			{
				Map[k][l - 1] += _People;
				Map[k][l] -= _People;
			}
			//人左面是箱子《普通的、红的》
			else if (Map[k][l - 1] == _Box || Map[k][l - 1] == _RedBox)
			{
				//箱子左面是空地或者种子
				if (Map[k][l - 2] == _Seed || Map[k][l - 2] == _Block)
				{
					Map[k][l - 2] += _Box;
					Map[k][l - 1] -= _Wall;   //人和box相差一
					Map[k][l] -= _People;
				}

			}
			
			
		}

		if (event. type == sf::Event::EventType::KeyReleased&&event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)   //向下按键
		{
			//人前是空地、//人前面是种子
			if (Map[k][l + 1] == _Block || Map[k][l + 1] == _Seed)
			{
				Map[k][l + 1] += _People;
				Map[k][l] -= _People;
			}
			//人前面是箱子《普通的、红的》
			else if (Map[k][l + 1] == _Box || Map[k][l + 1] == _RedBox)
			{
				//箱子前面是空地或者种子
				if (Map[k][l + 2] == _Seed || Map[k][l + 2] == _Block)
				{
					Map[k][l + 2] += _Box;
					Map[k][l + 1] -= _Wall;   //人和box相差一
					Map[k][l] -= _People;
				}

			
			}
		}

		if (event.type == sf::Event::EventType::KeyReleased&&event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)   //向左按键
		{
			//人前是空地、//人前面是种子
			if (Map[k - 1][l] == _Block || Map[k - 1][l] == _Seed)
			{
				Map[k - 1][l] += _People;
				Map[k][l] -= _People;
			}
			//人前面是箱子《普通的、红的》
			else if (Map[k - 1][l] == _Box || Map[k - 1][l] == _RedBox)
			{
				//箱子前面是空地或者种子
				if (Map[k - 2][l] == _Seed || Map[k - 2][l] == _Block)
				{
					Map[k - 2][l] += _Box;
					Map[k - 1][l] -= _Wall;   //人和box相差一
					Map[k][l] -= _People;
				}

			}

			
		}

		if (event.type == sf::Event::EventType::KeyReleased&&event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)    //向右按键
		{
			//人下是空地、//人下面是种子
			if (Map[k + 1][l] == _Block || Map[k + 1][l] == _Seed)
			{
				Map[k + 1][l] += _People;
				Map[k][l] -= _People;
			}
			//人下面是箱子《普通的、红的》
			else if (Map[k + 1][l] == _Box || Map[k + 1][l] == _RedBox)
			{
				//箱子下面是空地或者种子
				if (Map[k + 2][l] == _Seed || Map[k + 2][l] == _Block)
				{
					Map[k + 2][l] += _Box;
					Map[k + 1][l] -= _Wall;   //人和box相差一
					Map[k][l] -= _People;
				}
			}

		}

		if (event.type == sf::Event::EventType::KeyReleased&&event.key.code == sf::Keyboard::Space)   //空格暂停
		{

		}

	}

}

void BoxGame::Draw()
{
	window.clear();
	//绘制游戏开始界面

	sBackGround.setPosition(0, 0);
	window.draw(sBackGround);
	//绘制游戏背景

	int detaX = WINDOW_WIDTH / 3;
	int detaY = WINDOW_HEIGHT / 4;


	//遍历数组，绘制地图
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			switch (Map[i][j])
			{
			case _Block:
				/*putimage(i * 50, j * 50, &blank);*/
			    sBlock.setPosition(detaX+i * GRIDSIZE, detaY+j * GRIDSIZE);
				window.draw(sBlock);
				break;
			case _Wall:
				//putimage(i * 50, j * 50, &wall);
				sWall.setPosition(detaX + i * GRIDSIZE, detaY + j * GRIDSIZE);
				window.draw(sWall);
				break;
			case _Seed:
				//putimage(i * 50, j * 50, &end);
				sSeed.setPosition(detaX + i * GRIDSIZE, detaY + j * GRIDSIZE);
				window.draw(sSeed);
				break;
			case _People:
				//putimage(i * 50, j * 50, &people);
				sPeople.setPosition(detaX + i * GRIDSIZE, detaY + j * GRIDSIZE);
				window.draw(sPeople);
				break;
			case _Box:
				//putimage(i * 50, j * 50, &box);
				sBox.setPosition(detaX + i * GRIDSIZE, detaY + j * GRIDSIZE);
				window.draw(sBox);
				break;
			/*case _PeoSeed:
				//putimage(i * 50, j * 50, &redbox);
				sp.setPosition(i * 50, j * 50);
				window.draw(S_redbox);
				break;*/
			case _RedBox:
				//putimage(i * 50, j * 50, &people);
				sRedBox.setPosition(detaX + i * GRIDSIZE, detaY + j * GRIDSIZE);
				window.draw(sRedBox);
				break;
			}
		}
		printf("\n");
	}
	window.display();
}

void BoxGame::Logic()
{

}
