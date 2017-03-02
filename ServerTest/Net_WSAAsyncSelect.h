#pragma once
#include "netcomm.h"
class CNet_WSAAsyncSelect:
	public CNetComm
{
public:
	CNet_WSAAsyncSelect(void);
	~CNet_WSAAsyncSelect(void);
};

