/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acolin <acolin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 13:22:16 by acolin            #+#    #+#             */
/*   Updated: 2021/10/28 17:25:51 by acolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*procédure tracerSegment(entier x1, entier y1, entier x2, entier y2) est
  déclarer entier dx, dy ;
  déclarer entier e ; // valeur d’erreur
  e  ← x2 - x1 ;        // -e(0,1)
  dx ← e × 2 ;          // -e(0,1)
  dy ← (y2 - y1) × 2 ;  // e(1,0)
  tant que x1 ≤ x2 faire
    tracerPixel(x1, y1) ;
    x1 ← x1 + 1 ;  // colonne du pixel suivant
    si (e ← e - dy) ≤ 0 alors  // erreur pour le pixel suivant de même rangée
      y1 ← y1 + 1 ;  // choisir plutôt le pixel suivant dans la rangée supérieure
      e ← e + dx ;  // ajuste l’erreur commise dans cette nouvelle rangée
    fin si ;
  fin faire ;
  // Le pixel final (x2, y2) n’est pas tracé.
fin procédure ;*/

int	on_click(int button, int x, int y, void *param)
{
	static t_coor coor;
	t_mwin *mwin;

	mwin = (t_mwin *) param;
	if (!coor.x1)
		coor.x1 = x;
	else 
		coor.x2 = x;
	if (!coor.y1)
		coor.y1 = y;
	else
		coor.y2 = y;
	mlx_clear_window(mwin->mlx, mwin->win);
	mlx_string_put(mwin->mlx, mwin->win, 20, 20, 0x00FF0000, ft_itoa(coor.x1));
	mlx_string_put(mwin->mlx, mwin->win, 20, 40, 0x00FF0000, ft_itoa(coor.x2));
	mlx_string_put(mwin->mlx, mwin->win, 20, 60, 0x00FF0000, ft_itoa(coor.y1));
	mlx_string_put(mwin->mlx, mwin->win, 20, 80, 0x00FF0000, ft_itoa(coor.y2));
	if (coor.y1 && coor.y2 && coor.x1 && coor.x2)
	{
		//ft_tracer(coor, param, 0x00FF00FF);
		coor.x1 = 0;
		coor.x2 = 0;
		coor.y1 = 0;
		coor.y2 = 0;
	}
	return (button);
} 

int	main(void)
{
	t_mwin mwin;
	
	mwin.mlx = mlx_init();
	mwin.win = mlx_new_window(mwin.mlx, 500, 500, "fdf");
	mlx_mouse_hook(mwin.win, on_click, &mwin);
	mlx_loop(mwin.mlx);
}