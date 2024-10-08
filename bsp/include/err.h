/**
 * @file err.h
 * @brief Generic error number.
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

#ifndef __ERR_H__
#define __ERR_H__

/**
 * @defgroup error_number Error Number
 *
 * @brief Standard error number.
 *
 * @ingroup common_group
 *
 * @{
 *
 */

#define EPERM        1  /**< Operation not permitted */
#define ENOENT       2  /**< No such file or directory */
#define ESRCH        3  /**< No such process */
#define EINTR        4  /**< Interrupted system call */
#define EIO          5  /**< I/O error */
#define ENXIO        6  /**< No such device or address */
#define E2BIG        7  /**< Argument list too long */
#define ENOEXEC      8  /**< Exec format error */
#define EBADF        9  /**< Bad file number */
#define ECHILD      10  /**< No child processes */
#define EAGAIN      11  /**< Try again */
#define ENOMEM      12  /**< Out of memory */
#define EACCES      13  /**< Permission denied */
#define EFAULT      14  /**< Bad address */
#define ENOTBLK     15  /**< Block device required */
#define EBUSY       16  /**< Device or resource busy */
#define EEXIST      17  /**< File exists */
#define EXDEV       18  /**< Cross-device link */
#define ENODEV      19  /**< No such device */
#define ENOTDIR     20  /**< Not a directory */
#define EISDIR      21  /**< Is a directory */
#define EINVAL      22  /**< Invalid argument */
#define ENFILE      23  /**< File table overflow */
#define EMFILE      24  /**< Too many open files */
#define ENOTTY      25  /**< Not a typewriter */
#define ETXTBSY     26  /**< Text file busy */
#define EFBIG       27  /**< File too large */
#define ENOSPC      28  /**< No space left on device */
#define ESPIPE      29  /**< Illegal seek */
#define EROFS       30  /**< Read-only file system */
#define EMLINK      31  /**< Too many links */
#define EPIPE       32  /**< Broken pipe */
#define EDOM        33  /**< Math argument out of domain of func */
#define ERANGE      34  /**< Math result not representable */

#define ENOSUPPORT  101 /**< Not support this operation */
#define EEMPTY      102 /**< Device buffer is empty */
#define EFULL       103 /**< Device buffer is full */
#define ENOCHANGE   104 /**< Data is not changed */

/**
 * @}
 */

#endif /* __ERR_H__ */
