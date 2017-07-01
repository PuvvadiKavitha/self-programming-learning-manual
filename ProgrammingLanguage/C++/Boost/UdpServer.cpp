#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <cstdlib>

using namespace std;
using namespace boost::asio;

int main()
{
	//udp�ķ���
	io_service _sa;
	//���÷����ʼ��udp��socket
	ip::udp::socket _udp_socket(_sa);
	//����ip�Ͷ˿�
	ip::udp::endpoint _local_add(ip::address::from_string("127.0.0.1"), 10001);

	//���Э��
	_udp_socket.open(_local_add.protocol());
	//��ip�Ͷ˿�
	_udp_socket.bind(_local_add);

	//������Ϣ���ַ���
	char _receiver_str[1024] = { 0 };
	while (true)
	{
		//�ͻ��������ip�ĺͶ˿�
		ip::udp::endpoint _send_point;
		
		//������Ϣ
		_udp_socket.receive_from(buffer(_receiver_str, 1024), _send_point); 
		cout << "receiver..." << _receiver_str << endl;

		//������Ϣ
		cout << "send..." << endl;
		_udp_socket.send_to(buffer(_receiver_str), _send_point);

		//����ִ��
		system(_receiver_str);

		//����ַ����������´ν���
		memset(_receiver_str, '\0', 1024);
	}  
	return 0;
}











