/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:40:41 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/04 16:57:51 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

extern ssize_t ft_write(int fd, const void *buf, size_t count);

static void assert_ft_write(int fd, const char *str)
{
    errno = 0;
    ssize_t ret_ft = ft_write(fd, str, str != NULL ? strlen(str) : 0);
    int errno_ft = errno;

    errno = 0;
    ssize_t ret_sys = write(fd, str, str != NULL ? strlen(str) : 0);
    int errno_sys = errno;

    assert(ret_ft == ret_sys);
    assert(errno_ft == errno_sys);
}

void test_ft_write(void)
{
    printf("Testing ft_write... ");

    int dev_null = open("/dev/null", O_WRONLY);

    assert_ft_write(dev_null, "");
    assert_ft_write(dev_null, "this is a long string !");
    assert_ft_write(12341, "invalid file descriptor");
    assert_ft_write(dev_null, NULL);

    close(dev_null);

    printf("OK\n");
}