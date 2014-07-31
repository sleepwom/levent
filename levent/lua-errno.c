/* lua-ev.c
 * author: xjdrew
 * date: 2014-07-24
 */
#include <errno.h>
#include <string.h>

#if defined(_WIN32)||defined(_WIN64) 
	#include <winsock2.h>
	#define EWOULDBLOCK             WSAEWOULDBLOCK
	#define EINPROGRESS             WSAEINPROGRESS
	#define EALREADY                WSAEALREADY
	#define ENOTSOCK                WSAENOTSOCK
	#define EDESTADDRREQ            WSAEDESTADDRREQ
	#define EMSGSIZE                WSAEMSGSIZE
	#define EPROTOTYPE              WSAEPROTOTYPE
	#define ENOPROTOOPT             WSAENOPROTOOPT
	#define EPROTONOSUPPORT         WSAEPROTONOSUPPORT
	#define ESOCKTNOSUPPORT         WSAESOCKTNOSUPPORT
	#define EOPNOTSUPP              WSAEOPNOTSUPP
	#define EPFNOSUPPORT            WSAEPFNOSUPPORT
	#define EAFNOSUPPORT            WSAEAFNOSUPPORT
	#define EADDRINUSE              WSAEADDRINUSE
	#define EADDRNOTAVAIL           WSAEADDRNOTAVAIL
	#define ENETDOWN                WSAENETDOWN
	#define ENETUNREACH             WSAENETUNREACH
	#define ENETRESET               WSAENETRESET
	#define ECONNABORTED            WSAECONNABORTED
	#define ECONNRESET              WSAECONNRESET
	#define ENOBUFS                 WSAENOBUFS
	#define EISCONN                 WSAEISCONN
	#define ENOTCONN                WSAENOTCONN
	#define ESHUTDOWN               WSAESHUTDOWN
	#define ETOOMANYREFS            WSAETOOMANYREFS
	#define ETIMEDOUT               WSAETIMEDOUT
	#define ECONNREFUSED            WSAECONNREFUSED
	#define ELOOP                   WSAELOOP
	#define ENAMETOOLONG            WSAENAMETOOLONG
	#define EHOSTDOWN               WSAEHOSTDOWN
	#define EHOSTUNREACH            WSAEHOSTUNREACH
	#define ENOTEMPTY               WSAENOTEMPTY
	#define EPROCLIM                WSAEPROCLIM
	#define EUSERS                  WSAEUSERS
	#define EDQUOT                  WSAEDQUOT
	#define ESTALE                  WSAESTALE
	#define EREMOTE                 WSAEREMOTE
#endif

#include "levent.h"

static int lstrerror(lua_State *L) {
    int errnum = luaL_checkint(L, 1);
    lua_pushstring(L, strerror(errnum));
    return 1;
}

int luaopen_errno_c(lua_State *L) {
        
    luaL_Reg l[] = {
        {"strerror", lstrerror},
        {NULL, NULL}
    };

    luaL_checkversion(L);
	luaL_newlib(L, l);

    ADD_CONSTANT(L, EINVAL);
    ADD_CONSTANT(L, EWOULDBLOCK);
    ADD_CONSTANT(L, EINPROGRESS);
    ADD_CONSTANT(L, EALREADY);
    ADD_CONSTANT(L, EAGAIN);
    ADD_CONSTANT(L, EISCONN);
    ADD_CONSTANT(L, EBADF);
    return 1;
}

