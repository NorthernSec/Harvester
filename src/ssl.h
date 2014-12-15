#ifndef SSL_H
#define SSL_H

/* === INCLUDES === */
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <openssl/rand.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

/* === DATA STRUCTURES === */
typedef struct {
	int		socket;
	SSL		*handle;
	SSL_CTX		*context;
} connection;

/* === FUNCTION PROROTYPES === */

#endif
