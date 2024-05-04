/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:49:48 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/04 18:01:15 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "ft_list_bonus.h"

extern void ft_list_sort(t_list **begin_list, int (*cmp)());
extern void ft_list_push_front(t_list **begin_list, void *data);

static int compare_int(void *a, void *b)
{
    return *(int *)a - *(int *)b;
}

int all()
{
    return 0;
}

static void test_with_ints(void)
{
    t_list *list = NULL;

    int a = 12;
    int b = 13;
    int c = 4;
    int d = 3;

    ft_list_push_front(&list, &d);
    ft_list_push_front(&list, &c);
    ft_list_push_front(&list, &b);
    ft_list_push_front(&list, &a);

    ft_list_sort(&list, compare_int);

    assert(*(int *)list->data == 3);
    assert(*(int *)list->next->data == 4);
    assert(*(int *)list->next->next->data == 12);
    assert(*(int *)list->next->next->next->data == 13);
}

static void test_with_strings(void)
{
    t_list *list = NULL;

    const char *a = "a";
    const char *b = "b";
    const char *c = "c";
    const char *d = "d";

    ft_list_push_front(&list, (void *)a);
    ft_list_push_front(&list, (void *)b);
    ft_list_push_front(&list, (void *)c);
    ft_list_push_front(&list, (void *)d);

    assert(list->data == d);
    assert(list->next->data == c);
    assert(list->next->next->data == b);
    assert(list->next->next->next->data == a);

    ft_list_sort(&list, strcmp);

    assert(list->data == a);
    assert(list->next->data == b);
    assert(list->next->next->data == c);
    assert(list->next->next->next->data == d);
}

void test_ft_list_sort(void)
{
    printf("Testing ft_list_sort... ");
    test_with_ints();
    test_with_strings();
    printf("OK!\n");
}