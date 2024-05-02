/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:36:13 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/02 18:40:11 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

extern char *ft_strdup(const char *s);

static void assert_ft_strdup(const char *s)
{
    char *ft_str = ft_strdup(s);
    char *str = strdup(s);

    assert(strcmp(ft_str, str) == 0);

    free(ft_str);
    free(str);
}

void test_ft_strdup(void)
{
    printf("Testing ft_strdup... ");
    assert_ft_strdup("");
    assert_ft_strdup("a");
    assert_ft_strdup("ab");
    assert_ft_strdup("abc");
    assert_ft_strdup("this is a very long string ! my dear god, it's so long !");
    assert_ft_strdup("this is a very\0 long string !\0 my dear god, it's so long !");
    assert_ft_strdup("1234567890");
    printf("OK\n");
}