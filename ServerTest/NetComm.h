#pragma once
#include "winsock2.h"
#include <iostream>

#pragma comment (lib, "ws2_32.lib")

using namespace std;

class CNetComm
{
public:
	CNetComm(void);
	~CNetComm(void);
	SOCKET m_Socket;

	bool InitNetwork(int nPort);
	SOCKET GetListenSocket(int nPort, int nBacklog = SOMAXCONN);
};

