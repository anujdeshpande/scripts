sudo apt-get install portmap
sudo -i service portmap stop
sudo -i rpcbind -i -w
sudo -i service portmap start
rpcgen port.x
gcc -o server server.c port_svc.c port_xdr.c 
./server
./client 127.0.0.1 127.0.0.1 0 49 
 
 
  
