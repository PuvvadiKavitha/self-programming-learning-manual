#include <iostream>
#include <boost/asio.hpp>
#include <string>

using namespace std;
using namespace boost::asio;

int main() {
	io_service _s;
	ip::tcp::socket _socket(_s);
	//设置要绑定的ip和端口
	ip::tcp::endpoint _loca(ip::address_v4::from_string("127.0.0.1"), 10001);

	boost::system::error_code _errcode;//处理错误
	_socket.connect(_loca, _errcode);//连接服务器

	while (true) {
		char str[1024] = { 0 };
		cout << "please input str:";
		cin >> str;
		cout << endl;
		_socket.write_some(buffer(str), _errcode);//发送
		memset(str, '\0', 1024);
		_socket.read_some(buffer(str), _errcode);//接收
		cout << "receiver:" << str << endl;
	}
	 
	return 0;
}
