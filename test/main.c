/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:22:26 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/01 16:35:58 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>

extern unsigned long long ft_strlen(const char *str);
extern char *ft_strcpy(char *dst, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

static void assert_ft_strlen(const char *str)
{
    assert(ft_strlen(str) == strlen(str));
}

static void assert_ft_strcpy(const char *src)
{
    char dst[1024];
    char ft_dst[1024];

    assert(strcmp(ft_strcpy(dst, src), strcpy(ft_dst, src)) == 0);
}

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

static void assert_ft_strdup(const char *s)
{
    char *ft_str = ft_strdup(s);
    char *str = strdup(s);

    assert(strcmp(ft_str, str) == 0);

    free(ft_str);
    free(str);
}

static void test_ft_strlen(void)
{
    puts("Testing ft_strlen...");
    assert_ft_strlen("");
    assert_ft_strlen("a");
    assert_ft_strlen("ab");
    assert_ft_strlen("abc");
    assert_ft_strlen("this is a very long string ! my dear god, it's so long !");
    assert_ft_strlen("this is a very\0 long string !\0 my dear god, it's so long !");
    puts("ft_strlen OK");
}

static void test_ft_strcpy(void)
{
    puts("Testing ft_strcpy...");
    assert_ft_strcpy("");
    assert_ft_strcpy("a");
    assert_ft_strcpy("ab");
    assert_ft_strcpy("abc");
    assert_ft_strcpy("this is a very long string ! my dear god, it's so long !");
    assert_ft_strcpy("this is a very long string !\0 my dear god, it's so long !");
    puts("ft_strcpy OK");
}

static void test_ft_strcmp(void)
{
    puts("Testing ft_strcmp...");
    assert_ft_strcmp("", "");
    assert_ft_strcmp("a string", "-");
    assert_ft_strcmp("-", "a string");
    assert_ft_strcmp("a", "b");
    assert_ft_strcmp("b", "a");
    assert_ft_strcmp("a", "a");
    assert_ft_strcmp("a!", "a~");
    assert_ft_strcmp("a~", "a!");
    assert_ft_strcmp("ab", "ab");
    assert_ft_strcmp("abc", "abc");
    assert_ft_strcmp("this is a very long string ! my dear god, it's so long !", "this is a very long string ! my dear god, it's so long !");
    assert_ft_strcmp("this is a very long string !\0 my dear god, it's so long !", "this is a very long string !\0 my dear god, it's so long !");
    puts("ft_strcmp OK");
}

static void test_ft_write(void)
{
    puts("Testing ft_write...");
    assert_ft_write(1, "Hello, World!\n", 14);
    assert_ft_write(666, "Hello, World!\n", 14);
    assert_ft_write(1, NULL, 1234);
    puts("ft_write OK");
}

static void test_ft_strdup(void)
{
    puts("Testing ft_strdup...");
    assert_ft_strdup("");
    assert_ft_strdup("Bonjour !");
    assert_ft_strdup("Hello,\0World!");
    assert_ft_strdup("Hello, World!");
    puts("ft_strdup OK");
}

int main(void)
{
    test_ft_strlen();
    test_ft_strcpy();
    test_ft_strcmp();
    test_ft_write();
    test_ft_strdup();
    return (0);
}