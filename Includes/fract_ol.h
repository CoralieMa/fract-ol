/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmartino <cmartino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:34:14 by cmartino          #+#    #+#             */
/*   Updated: 2023/01/11 14:39:16 by cmartino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FRACT_OL_H
# define FRACT_OL_H

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

/* *************************************** */

#include <stdio.h>

/* *************************************** */

# ifndef WIDTH
#  define WIDTH 810
# endif
# ifndef HEIGHT
#  define HEIGHT 720
# endif
# ifndef ITER_MAX
#  define ITER_MAX 75
# endif 

typedef struct	s_fract {
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	r;
	float	i;
	float	c_r;
	float	c_i;
	float 	zoom_x;
	float	zoom_y;
	float	zoomT;
	float 	pos_x;
	float	pos_y;
	float	zoom;
	float	centrum_x;
	float	centrum_y;
	float	a_x;
	float	a_y;
	int		cpt;
	char	*type;
}				t_fract;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_mlx {
	void	*mlx;
	void	*wind;
	t_fract	*fract;
	t_data	*img;
}				t_mlx;

void	ft_init_wind(t_mlx *mlx);
void	ft_init_img(t_mlx *mlx);
t_fract ft_init_fract(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		ft_key_pressed(int key_code, void *param);
int		ft_exit(int code);
int		ft_zoom(int button, int xm, int ym, t_mlx *mlx);
void	ft_fractal(t_mlx *mlx, int argc, char **argv);
void	ft_mandelbrot(t_mlx *mlx, float zoom);
void	ft_julia(t_mlx *mlx);
float	ft_atof(char *str);
char	*ft_str_tolower(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_put_colors(t_mlx *mlx, int x, int y, int iter);
t_fract ft_init_fract(void);
int	ft_zoom(int keycode, int x_m, int y_m, t_mlx *mlx);

#endif
