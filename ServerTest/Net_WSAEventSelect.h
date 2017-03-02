#pragma once
#include "netcomm.h"
class CNet_WSAEventSelect :
	public CNetComm
{
public:
	CNet_WSAEventSelect(void);
	~CNet_WSAEventSelect(void);
};

