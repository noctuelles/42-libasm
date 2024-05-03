/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:22:26 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/03 17:07:42 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

/*extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);

static void assert_ft_strcmp(const char *s1, const char *s2)
{
    int ft_res = ft_strcmp(s1, s2);
    int res = strcmp(s1, s2);

    assert(ft_res == res);
}

static void assert_ft_write(int fd, const void *buf, size_t count)
{
    int errno_ft = 0;
    int errno_sys = 0;

    ssize_t ft_res = ft_write(fd, buf, count);
    errno_ft = errno;
    ssize_t res = write(fd, buf, count);
    errno_sys = errno;

    assert(ft_res == res && "ft_write return value is different from write");
    assert(errno_ft == errno_sys && "ft_write errno is different from write");
}

static void test_ft_write(void)
{
    puts("Testing ft_write...");
    assert_ft_write(1, "Hello, World!\n", 14);
    assert_ft_write(666, "Hello, World!\n", 14);
    assert_ft_write(1, NULL, 1234);
    puts("ft_write OK");
}*/

int main(void)
{
    // test_ft_strlen();
    // test_ft_strcpy();
    // test_ft_strcmp();
    // test_ft_strdup();

    // test_ft_isspace();
    // test_ft_atoi_base();

    // test_ft_list_create_elem();
    // test_ft_list_push_front();
    // test_ft_list_size();

    test_ft_list_remove_if();
    test_ft_list_sort();

    return (0);
}