#include "BoxGame.h"



//��ͼ����
static int Map[7][9]
{
	{0,0,1,1,1,1,0,0,0},  //0  �յ�
	{1,1,1,0,0,1,1,0,0},  //1  ǽ
	{1,0,2,2,0,0,1,1,1},  //2  Ŀ�ĵ�
	{1,0,2,3,2,0,0,0,1},  //4  ����
	{1,0,4,4,0,4,4,0,1},  //3  ��
	{1,0,0,1,1,0,0,0,1},  //6  ����+Ŀ�ĵ� 
	{1,1,1,1,1,1,1,1,1},  //5  ��+Ŀ�ĵ�
};

BoxGame::BoxGame()
{
	window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), L"MineSweepwe by ��Ч��");

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
		cout << "û���ҵ�������ͼ" << endl;
	}
	sBackGround.setTexture(tBackGround);      //���þ����������
	sBackGround.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!tPeople.loadFromFile("date/images/people.jpg"))
	{
		cout << "û���ҵ����˹�" << endl;
	}
	sPeople.setTexture(tPeople);          //���þ����������
	sPeople.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!tWall.loadFromFile("date/images/wall.jpg"))
	{
		cout << "û���ҵ�ǽ��" << endl;
	}
	sWall.setTexture(tWall);           //���þ����������
	sWall.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!tBlock.loadFromFile("date/images/blank.jpg"))
	{
		cout << "û���ҵ��ذ�" << endl;
	}
	sBlock.setTexture(tBlock);  //���þ����������
	sBlock.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!tSeed.loadFromFile("date/images/end.jpg"))
	{
		cout << "û���ҵ�С��" << endl;
	}
	sSeed.setTexture(tSeed);  //���þ����������
	sSeed.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!tBox.loadFromFile("date/images/box.jpg"))
	{
		cout << "û���ҵ�����" << endl;
	}
	sBox.setTexture(tBox);  //���þ����������
	sBox.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);


	if (!tRedBox.loadFromFile("date/images/redbox.jpg"))
	{
		cout << "û���ҵ�����" << endl;
	}
	sRedBox.setTexture(tRedBox);  //���þ����������
	sRedBox.setScale(SCALE, SCALE);       //���þ����������
	//S_mainBackground.setOrigin(0, 0);

}

void BoxGame::Input()
{

	int k, l;  //��¼people��λ��

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

		if (event.type==sf::Event::EventType::KeyReleased&&event.key.code==sf::Keyboard::W||event.key.code == sf::Keyboard::Up)   //���ϰ���
		{
			//�������ǿյء�//������������
			if (Map[k][l - 1] == _Block || Map[k][l - 1] == _Seed)
			{
				Map[k][l - 1] += _People;
				Map[k][l] -= _People;
			}
			//�����������ӡ���ͨ�ġ���ġ�
			else if (Map[k][l - 1] == _Box || Map[k][l - 1] == _RedBox)
			{
				//���������ǿյػ�������
				if (Map[k][l - 2] == _Seed || Map[k][l - 2] == _Block)
				{
					Map[k][l - 2] += _Box;
					Map[k][l - 1] -= _Wall;   //�˺�box���һ
					Map[k][l] -= _People;
				}

			}
			
			
		}

		if (event. type == sf::Event::EventType::KeyReleased&&event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)   //���°���
		{
			//��ǰ�ǿյء�//��ǰ��������
			if (Map[k][l + 1] == _Block || Map[k][l + 1] == _Seed)
			{
				Map[k][l + 1] += _People;
				Map[k][l] -= _People;
			}
			//��ǰ�������ӡ���ͨ�ġ���ġ�
			else if (Map[k][l + 1] == _Box || Map[k][l + 1] == _RedBox)
			{
				//����ǰ���ǿյػ�������
				if (Map[k][l + 2] == _Seed || Map[k][l + 2] == _Block)
				{
					Map[k][l + 2] += _Box;
					Map[k][l + 1] -= _Wall;   //�˺�box���һ
					Map[k][l] -= _People;
				}

			
			}
		}

		if (event.type == sf::Event::EventType::KeyReleased&&event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)   //���󰴼�
		{
			//��ǰ�ǿյء�//��ǰ��������
			if (Map[k - 1][l] == _Block || Map[k - 1][l] == _Seed)
			{
				Map[k - 1][l] += _People;
				Map[k][l] -= _People;
			}
			//��ǰ�������ӡ���ͨ�ġ���ġ�
			else if (Map[k - 1][l] == _Box || Map[k - 1][l] == _RedBox)
			{
				//����ǰ���ǿյػ�������
				if (Map[k - 2][l] == _Seed || Map[k - 2][l] == _Block)
				{
					Map[k - 2][l] += _Box;
					Map[k - 1][l] -= _Wall;   //�˺�box���һ
					Map[k][l] -= _People;
				}

			}

			
		}

		if (event.type == sf::Event::EventType::KeyReleased&&event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)    //���Ұ���
		{
			//�����ǿյء�//������������
			if (Map[k + 1][l] == _Block || Map[k + 1][l] == _Seed)
			{
				Map[k + 1][l] += _People;
				Map[k][l] -= _People;
			}
			//�����������ӡ���ͨ�ġ���ġ�
			else if (Map[k + 1][l] == _Box || Map[k + 1][l] == _RedBox)
			{
				//���������ǿյػ�������
				if (Map[k + 2][l] == _Seed || Map[k + 2][l] == _Block)
				{
					Map[k + 2][l] += _Box;
					Map[k + 1][l] -= _Wall;   //�˺�box���һ
					Map[k][l] -= _People;
				}
			}

		}

		if (event.type == sf::Event::EventType::KeyReleased&&event.key.code == sf::Keyboard::Space)   //�ո���ͣ
		{

		}

	}

}

void BoxGame::Draw()
{
	window.clear();
	//������Ϸ��ʼ����

	sBackGround.setPosition(0, 0);
	window.draw(sBackGround);
	//������Ϸ����

	int detaX = WINDOW_WIDTH / 3;
	int detaY = WINDOW_HEIGHT / 4;


	//�������飬���Ƶ�ͼ
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
