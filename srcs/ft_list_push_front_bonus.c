/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:55:57 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/04 18:00:56 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_bonus.h"
#include <stdio.h>
#include <assert.h>

extern void ft_list_push_front(t_list **begin_list, void *data);

void test_ft_list_push_front(void)
{
    t_list *list = NULL;

    int i = 42;
    const char hw[] = "Hello, World!";
    double d = 3.14;

    printf("Testing ft_list_push_front... ");

    ft_list_push_front(&list, &i);
    assert(list->data == &i);
    assert(list->next == NULL);

    ft_list_push_front(&list, &d);
    assert(list->data == &d);
    assert(list->next->data == &i);
    assert(list->next->next == NULL);

    ft_list_push_front(&list, (void *)hw);
    assert(list->data == hw);
    assert(list->next->data == &d);
    assert(list->next->next->data == &i);

    printf("OK!\n");
}