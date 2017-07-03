#include <iostream>
#include <boost/asio.hpp>
#include <string>

using namespace std;
using namespace boost::asio;

int main() {
	io_service _s;
	ip::tcp::socket _socket(_s);
	//����Ҫ�󶨵�ip�Ͷ˿�
	ip::tcp::endpoint _loca(ip::address_v4::from_string("127.0.0.1"), 10001);

	boost::system::error_code _errcode;//�������
	_socket.connect(_loca, _errcode);//���ӷ�����

	while (true) {
		char str[1024] = { 0 };
		cout << "please input str:";
		cin >> str;
		cout << endl;
		_socket.write_some(buffer(str), _errcode);//����
		memset(str, '\0', 1024);
		_socket.read_some(buffer(str), _errcode);//����
		cout << "receiver:" << str << endl;
	}
	 
	return 0;
}
