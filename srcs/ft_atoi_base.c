/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:51:39 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/02 19:27:54 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>

extern unsigned long ft_check_base(const char *base);

void test_ft_check_base()
{
    printf("\t->Testing ft_check_base... ");

    assert(ft_check_base("01") == 2);
    assert(ft_check_base("0123456789") == 10);
    assert(ft_check_base("0123456789abcdef") == 16);
    assert(ft_check_base("0123456789ABCDEF") == 16);

    assert(ft_check_base("01234567891") == 0 && "ft_check_base: base with duplicate characters");

    assert(ft_check_base("01234 56789") == 0 && "ft_check_base: base with space character");
    assert(ft_check_base("0123456789+") == 0 && "ft_check_base: base with '+' character");
    assert(ft_check_base("0123456789-") == 0 && "ft_check_base: base with '-' character");

    printf("OK!\n");
}

void test_ft_atoi_base()
{
    printf("Testing ft_atoi_base...\n\n");
    test_ft_check_base();
    printf("OK\n");
}