#include "StdAfx.h"
#include "NetComm.h"



CNetComm::CNetComm(void)
{
	
}


CNetComm::~CNetComm(void)
{
	if(m_Socket !=INVALID_SOCKET){
		closesocket(m_Socket);
	}
}

bool CNetComm::InitNetwork(int nPort)
{
	WSADATA wsd;
	int nErrCode = WSAStartup(MAKEWORD(2,2), &wsd);
	if(nErrCode){
		cout << "WSAStartup failed with error : "<< nErrCode << endl;
	}

	m_Socket = GetListenSocket(nPort, 10);
	if(m_Socket == INVALID_SOCKET)
	{
		WSACleanup();
		return false;
	}
	cout << " >>>>>>>>>>>>>>>> waiting for client's connection "<< endl;
	return true;
	
}
SOCKET CNetComm::GetListenSocket(int nPort, int nBacklog)
{
	//���� ���� ����
	SOCKET hsoListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(hsoListen == INVALID_SOCKET){
		cout << "socket failed, code : "<<WSAGetLastError() << endl;
		return INVALID_SOCKET;
	}

	// ���ε� �ּ� ����
	SOCKADDR_IN sa;
	memset(&sa, 0, sizeof(SOCKADDR_IN));
	sa.sin_family		= AF_INET;
	sa.sin_port			= htons(shPortNo);
	sa.sin_addr.s_addr	= htonl(INADDR_ANY);

	//���� ���ε�
	int lSockRet = bind(hsoListen, (PSOCKADDR)&sa, sizeof(SOCKADDR_IN));
	if(lSockRet == SOCKET_ERROR){
		cout << "bind failed, code : "<<WSAGetLastError() << endl;
		closesocket(hsoListen);
		return INVALID_SOCKET;
	}

	//����
	lSockRet = listen(hsoListen, nBacklog);
	if(lSockRet == SOCKET_ERROR){
		cout << "listen failed, code : "<<WSAGetLastError() << endl;
		closesocket(hsoListen);
		return INVALID_SOCKET;
	}
	return hsoListen;
}


