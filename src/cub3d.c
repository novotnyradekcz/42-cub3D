/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaresov <lmaresov@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:11:29 by rnovotny          #+#    #+#             */
/*   Updated: 2024/11/25 08:57:45 by lmaresov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_controls(void)
{
	printf("\nWelcome to cub3D the game\n\n");
	printf("\tmove forward:\tW\n");
	printf("\tmove backwards:\tS\n");
	printf("\tmove left:\tA\n");
	printf("\tmove right:\tD\n");
	printf("\trotate left:\tleft arrow\n");
	printf("\trotate right:\tright arrow\n\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argv[1] && argc == 2)
	{
		init_game(&game);
		if (check_arg(argv[1], &game))
			return (1);
		if (map_to_game(&game, argv[1]))
			return (1);
		check_walls(&game);
		game_before_beginning(&game);
		init_mlx(&game);
		init_textures(&game);
		init_player_direction(&game);
		print_controls();
		render_images(&game);
		listen_for_input(&game);
		mlx_loop_hook(game.mlx, render, &game);
		mlx_loop(game.mlx);
	}
	else
		write(2, "Usage: ./cub3d map_file\n", 24);
	return (0);
}
