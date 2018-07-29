

#ifndef __OH_TCPSERVER_H__
#define __OH_TCPSERVER_H__

#include "Acceptor.h"
#include "EpollPoller.h"
#include <string>

using std::string;

namespace oh
{

class TcpServer
{
  public:
	typedef EpollPoller::EpollCallback TcpServerCallback;
	TcpServer(const string &ip, unsigned short port);
	TcpServer(unsigned short port);

	void start();
	void stop();

	void setConnectionCallback(TcpServerCallback cb);
	void setMessageCallback(TcpServerCallback cb);
	void setCloseCallback(TcpServerCallback cb);

  private:
	Acceptor acceptor_;
	EpollPoller poller_;

	TcpServerCallback connectionCallback_;
	TcpServerCallback messageCallback_;
	TcpServerCallback closeCallback_;
};

} // namespace oh

#endif