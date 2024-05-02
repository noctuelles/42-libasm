/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:33:12 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/02 18:40:05 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <assert.h>
#include <stdio.h>

extern char *ft_strcpy(char *dst, const char *src);

static void assert_ft_strcpy(const char *src)
{
    char dst[1024];
    char ft_dst[1024];

    if (strlen(src) >= 1024)
        return;

    assert(strcmp(ft_strcpy(dst, src), strcpy(ft_dst, src)) == 0);
}

void test_ft_strcpy()
{
    printf("Testing ft_strcpy... ");
    assert_ft_strcpy("");
    assert_ft_strcpy("a");
    assert_ft_strcpy("ab");
    assert_ft_strcpy("abc");
    assert_ft_strcpy("this is a very long string ! my dear god, it's so long !");
    assert_ft_strcpy("this is a very\0 long string !\0 my dear god, it's so long !");
    printf("OK\n");
}