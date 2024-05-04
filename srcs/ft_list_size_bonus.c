/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:49:00 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/04 18:01:08 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_bonus.h"
#include <stdio.h>
#include <assert.h>

extern void ft_list_push_front(t_list **begin_list, void *data);
extern size_t ft_list_size(t_list *begin_list);

void test_ft_list_size(void)
{
    t_list *list = NULL;
    int i = 42;

    printf("Testing ft_list_size... ");

    for (size_t j = 0; j < (size_t)i; j++)
    {
        ft_list_push_front(&list, &j);
    }

    assert(ft_list_size(list) == (size_t)i);

    printf("OK!\n");
}