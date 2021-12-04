#ifndef MAIN_H
# define MAIN_H
# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif
# ifndef CLOCK_MONOTONIC_RAW
#  define CLOCK_MONOTONIC_RAW 0
# endif
# ifdef __linux__
#  define MAC_OS 0
#  define A 97
#  define S 115
#  define D 100
#  define W 119
#  define Q 113
#  define E 101
#  define R 114
#  define UP 65362
#  define DW 65364
#  define LF 65361
#  define RG 65363
#  define ESC 65307
#  define CTRL 65507
#  define SPC 32
#  define SHFT 65505
# endif
# ifdef __APPLE__
#  define MAC_OS 1
#  define A 0
#  define S 1
#  define D 2
#  define W 13
#  define Q 12
#  define E 14
#  define R 114
#  define UP 126
#  define DW 125
#  define LF 123
#  define RG 124
#  define ESC 53
#  define CTRL 256
#  define SPC 49
#  define SHFT 257
# endif
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <time.h>
# include <fcntl.h>
# include "structs.h"
# include "key_mouse.h"
# include "img_utils.h"
# include "img_utils2.h"
# include "expire.h"
# include "loader.h"
# include "hud.h"
# include "sprites_utils.h"
# include "sprites_dyn.h"
# include "minimap.h"
# include "sound.h"
# include "math_utils.h"
# include "collisions.h"
# include "gen_wall.h"
# include "skybox.h"
# include "parse_map.h"
# include "renderer.h"
# include "placer.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
#ifdef __APPLE__
# include "mlx/mlx.h"
#endif
#ifdef __linux__
# include <mlx.h>
#endif
#endif