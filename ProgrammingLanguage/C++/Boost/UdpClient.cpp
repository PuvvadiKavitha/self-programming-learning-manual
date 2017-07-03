#include <iostream>
#include <string>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;


int main() {
	io_service _sa;
	ip::udp::socket _udp_socket(_sa);

	ip::udp::endpoint _local_add(ip::address::from_string("127.0.0.1"), 10001);

	_udp_socket.open(_local_add.protocol());
	
	char _receiver_str[1024] = { 0 };
	while (true) {
		string _send_str;
		cout << "input send str:";
		cin >> _send_str;
		cout << endl;

		cout << "start send..." << endl;
		//send to server
		_udp_socket.send_to(buffer(_send_str.c_str(), _send_str.size()), _local_add);

		cout << "start receiver..." << endl;
		//receiver from server
		_udp_socket.receive_from(buffer(_receiver_str, 1024), _local_add);
		cout << "receiver str:" << _receiver_str << endl;
	}
	 

	return 0;
}
