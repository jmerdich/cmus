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

#ifndef CMUS_LOCKING_H
#define CMUS_LOCKING_H

#include <pthread.h>

#define CMUS_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
#define CMUS_COND_INITIALIZER PTHREAD_COND_INITIALIZER

void cmus_mutex_lock(pthread_mutex_t *mutex);
void cmus_mutex_unlock(pthread_mutex_t *mutex);
void cmus_mutex_init_recursive(pthread_mutex_t *mutex);

#endif
