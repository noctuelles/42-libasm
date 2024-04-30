/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:22:26 by plouvel           #+#    #+#             */
/*   Updated: 2024/04/30 18:43:09 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <string.h>
#include <stdio.h>

extern unsigned long long ft_strlen(const char *str);
extern char *ft_strcpy(char *dst, const char *src);

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

int main(void)
{
    test_ft_strlen();
    test_ft_strcpy();
    return (0);
}