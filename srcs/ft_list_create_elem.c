/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_create_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:29:52 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/03 11:42:13 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "ft_list.h"

extern t_list *ft_list_create_elem(void *data);

static void assert_ft_list_create_elem(void *data)
{
    t_list *list = ft_list_create_elem(data);

    if (!list)
    {
        return;
    }

    assert(list->data == data);
    assert(list->next == NULL);

    free(list);
}

void test_ft_list_create_elem(void)
{
    printf("Testing ft_list_create_elem... ");
    assert_ft_list_create_elem("Hello, World!");
    assert_ft_list_create_elem(NULL);
    int *i = malloc(sizeof(int));
    if (i == NULL)
    {
        return;
    }
    assert_ft_list_create_elem(i);
    free(i);
    printf("OK!\n");
}