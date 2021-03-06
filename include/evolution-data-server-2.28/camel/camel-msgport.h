/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*- */
/*
 *  Copyright (C) 1999-2008 Novell, Inc. (www.novell.com)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Street #330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef CAMEL_MSGPORT_H
#define CAMEL_MSGPORT_H

#include <glib.h>

G_BEGIN_DECLS

typedef struct _CamelMsg CamelMsg;
typedef struct _CamelMsgPort CamelMsgPort;

struct _CamelMsg {
	CamelMsgPort *reply_port;
	gint flags;
};

CamelMsgPort *	camel_msgport_new		(void);
void		camel_msgport_destroy		(CamelMsgPort *msgport);
gint		camel_msgport_fd		(CamelMsgPort *msgport);
void		camel_msgport_push		(CamelMsgPort *msgport,
						 CamelMsg *msg);
CamelMsg *	camel_msgport_pop		(CamelMsgPort *msgport);
CamelMsg *	camel_msgport_try_pop		(CamelMsgPort *msgport);
void		camel_msgport_reply		(CamelMsg *msg);

#ifdef HAVE_NSS
struct PRFileDesc * camel_msgport_prfd		(CamelMsgPort *msgport);
#endif

G_END_DECLS

#endif  /* CAMEL_MSGPORT_H */
