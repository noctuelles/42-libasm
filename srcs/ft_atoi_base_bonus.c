/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:51:39 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/04 17:58:40 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stdio.h>
#include <limits.h>

extern unsigned long ft_check_base(const char *base);
extern long ft_get_base_nbr(const char *base, char c);
extern int ft_atoi_base(const char *str, const char *base);

void test_ft_check_base()
{
    assert(ft_check_base("01") == 2);
    assert(ft_check_base("0123456789") == 10);
    assert(ft_check_base("0123456789abcdef") == 16);
    assert(ft_check_base("0123456789ABCDEF") == 16);

    assert(ft_check_base("01234567891") == 0 && "ft_check_base: base with duplicate characters");

    assert(ft_check_base("01234 56789") == 0 && "ft_check_base: base with space character");
    assert(ft_check_base("0123456789+") == 0 && "ft_check_base: base with '+' character");
    assert(ft_check_base("0123456789-") == 0 && "ft_check_base: base with '-' character");
}

void test_ft_get_base_nbr()
{
    assert(ft_get_base_nbr("01", '0') == 0);
    assert(ft_get_base_nbr("01", '1') == 1);

    assert(ft_get_base_nbr("0123456789", '0') == 0);
    assert(ft_get_base_nbr("0123456789", '9') == 9);
    assert(ft_get_base_nbr("01234", '9') == -1);
}

void test_ft_atoi_base()
{
    printf("Testing ft_atoi_base... ");

    test_ft_check_base();
    test_ft_get_base_nbr();

    assert(ft_atoi_base("++123", "0123456789") == 123);
    assert(ft_atoi_base("839271", "0123456789") == 839271);
    assert(ft_atoi_base("1111", "01") == 15);
    assert(ft_atoi_base("\n\t\nFF", "0123456789ABCDEF") == 0xFF);
    assert(ft_atoi_base("ACFF", "0123456789ABCDEF") == 0xACFF);
    assert(ft_atoi_base("       DEADBE", "0123456789ABCDEF") == 0xDEADBE);
    assert(ft_atoi_base("  DEADBE", "0123456789ABCDEF") == 0xDEADBE);
    assert(ft_atoi_base("\v\t10001101011", "01") == 1131);

    assert(ft_atoi_base(" \n  ++-123", "0123456789") == -123);
    assert(ft_atoi_base("++--123", "0123456789") == 123);
    assert(ft_atoi_base("++-- 123", "0123456789") == 0);

    assert(ft_atoi_base("10001101011", "01234567891") == 0 && "ft_atoi_base: invalid base");
    assert(ft_atoi_base("10001101011", "01234  56789") == 0 && "ft_atoi_base: invalid base");
    assert(ft_atoi_base("10001101011", "01234\n56789") == 0 && "ft_atoi_base: invalid base");
    assert(ft_atoi_base("10001101011", "0123-456789") == 0 && "ft_atoi_base: invalid base");
    assert(ft_atoi_base("10001101011", "01234567+9") == 0 && "ft_atoi_base: invalid base");

    printf("OK\n");
}