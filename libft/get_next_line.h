/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanaa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:12:22 by bchanaa           #+#    #+#             */
/*   Updated: 2024/01/30 17:22:53 by bchanaa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

# if BUFFER_SIZE > SIZE_MAX
#  define BUFFER_SIZE_OK 0
# elif BUFFER_SIZE <= 0
#  define BUFFER_SIZE_OK 0
# else
#  define BUFFER_SIZE_OK 1
# endif

#endif
