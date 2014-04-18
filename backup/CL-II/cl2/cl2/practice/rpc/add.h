/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _ADD_H_RPCGEN
#define _ADD_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct input_data {
	double a[10];
	int n;
};
typedef struct input_data input_data;

#define ADDPROG 3515
#define ADDVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define ADD 1
extern  double * add_1(input_data *, CLIENT *);
extern  double * add_1_svc(input_data *, struct svc_req *);
extern int addprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define ADD 1
extern  double * add_1();
extern  double * add_1_svc();
extern int addprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_input_data (XDR *, input_data*);

#else /* K&R C */
extern bool_t xdr_input_data ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_ADD_H_RPCGEN */
