/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _AVG_H_RPCGEN
#define _AVG_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct add {
	int a;
	int b;
};
typedef struct add add;

#define ADDPROGSAN 1234
#define ADDPROGS 1

#if defined(__STDC__) || defined(__cplusplus)
#define addition 1
extern  int * addition_1(struct add *, CLIENT *);
extern  int * addition_1_svc(struct add *, struct svc_req *);
extern int addprogsan_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define addition 1
extern  int * addition_1();
extern  int * addition_1_svc();
extern int addprogsan_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_add (XDR *, add*);

#else /* K&R C */
extern bool_t xdr_add ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_AVG_H_RPCGEN */
