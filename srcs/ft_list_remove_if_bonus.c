/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:56:46 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/04 18:01:02 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list_bonus.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

extern void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
extern void ft_list_push_front(t_list **begin_list, void *data);
extern size_t ft_list_size(t_list *list);

void free_nothing(void *data)
{
    (void)data;
}

void test_ft_list_remove_if(void)
{
    t_list *list = NULL;

    const char hw[] = "Hello, World!";
    const char foo[] = "foo";
    const char bar[] = "bar";

    printf("Testing ft_list_remove_if... ");

    /* Deleting one element */
    ft_list_push_front(&list, (void *)hw);
    ft_list_push_front(&list, (void *)foo);
    ft_list_push_front(&list, (void *)bar);

    ft_list_remove_if(&list, (void *)foo, strcmp, free_nothing);

    assert(list->data == bar);
    assert(list->next->data == hw);
    assert(ft_list_size(list) == 2);

    ft_list_remove_if(&list, (void *)bar, strcmp, free_nothing);

    assert(list->data == hw);
    assert(ft_list_size(list) == 1);

    ft_list_remove_if(&list, (void *)hw, strcmp, free_nothing);

    assert(list == NULL);
    assert(ft_list_size(list) == 0);

    /* Deleting multiple elements */
    ft_list_push_front(&list, (void *)foo);
    ft_list_push_front(&list, (void *)foo);
    ft_list_push_front(&list, (void *)hw);
    ft_list_push_front(&list, (void *)foo);
    ft_list_push_front(&list, (void *)bar);
    ft_list_push_front(&list, (void *)foo);
    ft_list_push_front(&list, (void *)foo);

    ft_list_remove_if(&list, (void *)foo, strcmp, free_nothing);

    assert(ft_list_size(list) == 2);
    assert(list->data == bar);
    assert(list->next->data == hw);

    printf("OK!\n");
}