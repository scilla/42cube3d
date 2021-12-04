/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_wall.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scilla <scilla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 16:37:34 by scilla            #+#    #+#             */
/*   Updated: 2021/02/19 16:46:56 by scilla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEN_WALL_H
# define GEN_WALL_H
# include <math.h>
# include "main.h"
# include "structs.h"

void	gen_wall(t_world *world, t_vector vect, int width, t_asset *ass);

#endif