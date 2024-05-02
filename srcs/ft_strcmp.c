/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:34:18 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/02 18:39:57 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>

extern int ft_strcmp(const char *s1, const char *s2);

static void assert_ft_strcmp(const char *s1, const char *s2)
{
    int ft_res = ft_strcmp(s1, s2);
    int res = strcmp(s1, s2);

    assert(ft_res == res);
}

void test_ft_strcmp()
{
    printf("Testing ft_strcmp... ");
    assert_ft_strcmp("", "");
    assert_ft_strcmp("a", "a");
    assert_ft_strcmp("ab", "ab");
    assert_ft_strcmp("abc", "abc");
    assert_ft_strcmp("283*@&#!*&43CJ", "283*@&#!*&43CJ");
    assert_ft_strcmp("this is a very long string ! my dear god, it's so long !", "this is a very long string ! my dear god, it's so long !");
    assert_ft_strcmp("this is a very\0 long string !\0 my dear god, it's so long !", "this is a very\0 long string !\0 my dear god, it's so long !");
    assert_ft_strcmp("1234567890", "1234567890");
    assert_ft_strcmp("-", "a");
    assert_ft_strcmp("a", "-");
    assert_ft_strcmp("a", "b");
    assert_ft_strcmp("b", "a");
    printf("OK\n");
}