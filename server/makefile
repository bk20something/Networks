all:
	$(MAKE) -C TCPserver/Debug
	ln -s TCPserver/Debug/server_tcp
	$(MAKE) -C UDPserver/Debug
	ln -s UDPserver/Debug/server_udp 
clean:
	$(MAKE) -C TCPserver/Debug/ clean
	$(MAKE) -C UDPserver/Debug/ clean
	rm server_tcp
	rm server_udp
