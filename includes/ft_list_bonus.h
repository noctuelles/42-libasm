/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:34:00 by plouvel           #+#    #+#             */
/*   Updated: 2024/05/04 18:05:20 by plouvel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_BONUS_H
#define FT_LIST_BONUS_H

typedef struct s_list
{
    void *data;
    struct s_list *next;
} t_list;

#endif