/**
 * @file utils/ring_buff/include/ring_buff.h
 * @brief A ring buffer util.
 * @author Peter.Peng <27144363@qq.com>
 * @date 2022
 *
 * Embedded Device Software
 * Copyright (C) 2022 Peter.Peng
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __RING_BUFF_H__
#define __RING_BUFF_H__

#include <stddef.h>
#include <stdint.h>
#include <assert.h>
#include "err.h"

#ifndef DOC_HIDDEN
/**
 * @brief   Ring buffer definition.
 */
typedef struct
{
    int32_t     front;
    int32_t     rear;
    int32_t     size;
    int32_t     cnt;
    uint8_t*    buffer;
} ring_buff_t;

#define is_empty(ring) ((ring)->cnt == 0)
#define is_full(ring)  ((ring)->cnt == (ring)->size)
#endif

/**
 * @brief   Read data and increment the read pointer.
 *
 * @param   ring Pointer to the ring handle.
 * @param   value Pointer to the data to read.
 *
 * @retval  Returns 0 on success, negative error code otherwise.
 */
static inline int32_t ring_buffer_read(ring_buff_t* ring, uint8_t* value)
{
    if (!ring)
    {
        return -EINVAL;
    }

    if (!value)
    {
        return -EINVAL;
    }

    assert(ring->buffer);
    assert(ring->size);

    if (is_empty(ring))
    {
        return -EEMPTY;
    }

    *value = ring->buffer[ring->front];
    ring->front = (ring->front + 1) % ring->size;
    ring->cnt--;

    return 0;
}

/**
 * @brief   Write data and increment the write pointer.
 *
 * @param   ring Pointer to the ring handle.
 * @param   value The data to write.
 *
 * @retval  Returns 0 on success, negative error code otherwise.
 */
static inline int32_t ring_buffer_write(ring_buff_t* ring, uint8_t value)
{
    if (!ring)
    {
        return -EINVAL;
    }

    assert(ring->buffer);
    assert(ring->size);

    if (is_full(ring))
    {
        return -EFULL;
    }

    ring->buffer[ring->rear] = value;
    ring->rear = (ring->rear + 1) % ring->size;
    ring->cnt++;

    return 0;
}

/**
 * @brief   Initialize the ring buffer.
 *
 * @param   ring Pointer to the ring handle.
 * @param   buffer The buffer space.
 * @param   size The buffer size.
 *
 * @retval  Returns 0 on success, negative error code otherwise.
 */
static inline int32_t ring_buffer_init(ring_buff_t* ring,
                                       uint8_t*     buffer,
                                       int32_t      size)
{
    if (!ring)
    {
        return -EINVAL;
    }

    if (!buffer)
    {
        return -EINVAL;
    }

    if (!size)
    {
        return -EINVAL;
    }

    ring->front = 0;
    ring->rear = 0;
    ring->buffer = buffer;
    ring->size = size;
    ring->cnt = 0;

    return 0;
}

#endif /* __RING_BUFF_H__ */
