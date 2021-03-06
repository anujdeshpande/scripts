/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _ECHO_H_RPCGEN
#define _ECHO_H_RPCGEN

#include <rpc/rpc.h>

#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PORTLIMIT 50

struct input {
	char buffer[256];
};
typedef struct input input;

typedef input data;

#define PORTPROG 0x4001
#define PORTVERSION 1

#if defined(__STDC__) || defined(__cplusplus)
#define getechoserver 1
extern  enum clnt_stat getechoserver_1(data *, data *, CLIENT *);
extern  bool_t getechoserver_1_svc(data *, data *, struct svc_req *);
extern int portprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define getechoserver 1
extern  enum clnt_stat getechoserver_1();
extern  bool_t getechoserver_1_svc();
extern int portprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_input (XDR *, input*);
extern  bool_t xdr_data (XDR *, data*);

#else /* K&R C */
extern bool_t xdr_input ();
extern bool_t xdr_data ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_ECHO_H_RPCGEN */
