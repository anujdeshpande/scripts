 rpcgen -M echo.x
gcc -o server server.c echo_svc.c echo_xdr.c
gcc -o client client.c echo_clnt.c echo_xdr.c
