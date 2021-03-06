/*
 * Copyright 2008-2013 Various Authors
 * Copyright 2004 Timo Hirvonen
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "locking.h"
#include "debug.h"

#include <string.h>

void cmus_mutex_lock(pthread_mutex_t *mutex)
{
	int rc = pthread_mutex_lock(mutex);
	if (unlikely(rc))
		BUG("error locking mutex: %s\n", strerror(rc));
}

void cmus_mutex_unlock(pthread_mutex_t *mutex)
{
	int rc = pthread_mutex_unlock(mutex);
	if (unlikely(rc))
		BUG("error unlocking mutex: %s\n", strerror(rc));
}

void cmus_mutex_init_recursive(pthread_mutex_t *mutex)
{
	pthread_mutexattr_t attr;
	int rc = pthread_mutexattr_init(&attr);
	if (rc)
		goto err;
	rc = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	if (rc)
		goto err;
	rc = pthread_mutex_init(mutex, &attr);
	if (rc)
		goto err;
	return;
err:
	BUG("error initializing recursive mutex: %s\n", strerror(rc));
}
