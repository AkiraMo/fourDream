 ///
 /// @file    game.cc
 /// @author  AkiraMo(motongying941@gmail.com)
 /// @date    2017-10-22 22:12:46
 ///
 
#include <memory.h>

#include "game.h"

void fourDream::addCard(int iGameID, int iCard)
{
	for(int i = 0; i < CARDCOUNT; ++i)
	{
		if(iGameCard[iGameID][i] == 0)
		{
			iGameCard[iGameID][i] = iCard;
		}
	}
}

void fourDream::outCard(int iGameID, int iCard)
{
	bool flag = false;
	int site = 0;
	for(; site < CARDCOUNT; ++site)
	{
		if(iGameCard[iGameID][site] == iCard)
		{
			flag = true;
			break;
		}
	}

	if(!flag)
	{
		return;
	}
	else
	{
		iOutCard[iGameID] = iGameCard[iGameID][site];
		iGameCard[iGameID][site] = 0;
	}
}

bool fourDream::isWin(int iGameID)
{
	for(int i = 0; i < CARDCOUNT - 1; ++i)
	{
		if(iGameCard[iGameID][i] != iGameCard[iGameID][i+1])
		{
			return false;
		}
	}
	return true;
}

void fourDream::reciveMessage(int iGameID, int iCmdID, int iArg)
{
	switch(iCmdID)
	{
	}
}

void fourDream::standup(int iGameID)
{
	bReady[iGameID] = false;
}

void fourDream::sitdown()
{
	::memset(iScore, 0, sizeof(iScore));
}

void fourDream::ready(int iGameID)
{
	bReady[iGameID] = true;
	bool flag = false;
	for(int i = 0; i < PLAYCOUNT; ++i)
	{
		if(!bReady[i])
		{
			flag = true;
			break;
		}
	}

	if(!flag)
	{
		start();
	}
}

void fourDream::start()
{
	//发牌
	
	for(int i = 0; i < PLAYCOUNT; ++i)
	{
		if(isWin(i))
		{
			over();
		}
	}

	//启动定时器函数
	
}

void fourDream::over()
{
	for(int i = 0; i < PLAYCOUNT; ++i)
	{
		if(isWin(i))
		{
			iScore[i] += SCORE;
			if(iGameCard[i][0] == 1)
			{
				iScore[i] += SCORE;
			}
		}
	}

	::memset(bReady, 0, sizeof(bReady));
	::memset(iGameCard, 0, sizeof(iGameCard));
	::memset(iOutCard, 0, sizeof(iOutCard));
}


