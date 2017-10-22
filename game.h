 ///
 /// @file    game.h
 /// @author  AkiraMo(motongying941@gmail.com)
 /// @date    2017-10-22 21:53:13
 ///
#ifndef _GAME_H_
#define _GAME_H_

#define PLAYCOUNT 4
#define CARDCOUNT 4
#define SCORE 10

#include <iostream>
using std::cout;
using std::endl;

class fourDream
{
//游戏本体部分
public:
	void addCard(int iGamerID, int iCard);
	void outCard(int iGamerID, int iCard);

private:
	bool isWin(int iGamerID);

private:
	int iGameCard[PLAYCOUNT][CARDCOUNT];
	int iOutCard[PLAYCOUNT];
	//定时器

//运行机制
public:
	void reciveMessage(int iGamerID, int iCmdID, int iArg);

private:
	void standup(int iGamerID);
	void sitdown();
	void ready(int iGamerID);
	void start();
	void over();
	
private:
	bool bReady[PLAYCOUNT];
	int iScore[PLAYCOUNT];
	//定时器

private:
	//定时器函数
};

#endif
