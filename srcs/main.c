/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:22:26 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/04 17:29:21 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <test.h>

int main(void)
{
    /* Mandatory part */
    test_ft_strlen();
    test_ft_strcpy();
    test_ft_strcmp();
    test_ft_strdup();
    test_ft_write();
    test_ft_read();

    /* Bonus part */
    test_ft_isspace();
    test_ft_atoi_base();
    test_ft_list_create_elem();
    test_ft_list_push_front();
    test_ft_list_size();
    test_ft_list_remove_if();
    test_ft_list_sort();

    return (0);
}