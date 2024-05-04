/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:02:15 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/04 18:02:51 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

extern ssize_t ft_read(int fd, void *buf, size_t count);

static void assert_ft_read(int fd, void *buf, void *sys_buf, size_t count)
{
    lseek(fd, 0, SEEK_SET);

    errno = 0;
    ssize_t ret_ft = ft_read(fd, buf, count);
    int errno_ft = errno;

    lseek(fd, 0, SEEK_SET);

    errno = 0;
    ssize_t ret_sys = read(fd, sys_buf, count);
    int errno_sys = errno;

    assert(ret_ft == ret_sys);
    assert(errno_ft == errno_sys);

    if (ret_ft == -1)
    {
        return;
    }
}

void test_ft_read(void)
{
    unsigned char buf[1024] = {0};
    unsigned char sys_buf[1024] = {0};

    printf("Testing ft_read... ");

    int fd = open("/dev/urandom", O_RDONLY);

    if (fd == -1)
    {
        return;
    }

    assert_ft_read(666, buf, sys_buf, 1024);

    assert_ft_read(fd, buf, sys_buf, 1024);
    assert_ft_read(fd, buf, sys_buf, 10);
    assert_ft_read(fd, buf, sys_buf, 0);
    assert_ft_read(fd, buf, sys_buf, 427);

    close(fd);

    fd = open("./Makefile", O_RDONLY);

    if (fd == -1)
    {
        return;
    }

    assert_ft_read(fd, buf, sys_buf, 25);
    assert(memcmp(buf, sys_buf, 25) == 0);
    assert_ft_read(fd, buf, sys_buf, 1024);
    assert(memcmp(buf, sys_buf, 1024) == 0);

    close(fd);

    printf("OK!\n");
}