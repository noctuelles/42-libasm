/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:30:52 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/02 18:40:23 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <assert.h>

extern unsigned long ft_strlen(const char *str);

static void assert_ft_strlen(const char *str)
{
    assert(ft_strlen(str) == strlen(str));
}

void test_ft_strlen(void)
{
    printf("Testing ft_strlen... ");
    assert_ft_strlen("");
    assert_ft_strlen("a");
    assert_ft_strlen("ab");
    assert_ft_strlen("abc");
    assert_ft_strlen("this is a very long string ! my dear god, it's so long !");
    assert_ft_strlen("this is a very\0 long string !\0 my dear god, it's so long !");
    printf("OK\n");
}