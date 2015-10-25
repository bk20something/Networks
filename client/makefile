all:
	$(MAKE) -C TCPclient/Debug
	ln -s TCPclient/Debug/client_tcp
	$(MAKE) -C UDPclient/Debug
	ln -s UDPclient/Debug/client_udp 
clean:
	$(MAKE) -C TCPclient/Debug/ clean
	$(MAKE) -C UDPclient/Debug/ clean
	rm client_tcp
	rm client_udp
