/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:15:28 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/02 18:50:49 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <assert.h>

extern int ft_isspace(int c);

static void assert_isspace(int c)
{
    int ft_res = ft_isspace(c);
    int res = isspace(c);

    if (res != 0)
    {
        res = 1;
    }
    assert(ft_res == res);
}

void test_ft_isspace()
{
    printf("Testing ft_isspace... ");

    for (int i = 0; i < 256; i++)
    {
        assert_isspace(i);
    }

    printf("OK\n");
}