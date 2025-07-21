CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	miniRT
MLXLIB		=	-Lminilibx-linux -lmlx -lX11 -lXext -lm
INCLUDES	=	-I./includes -I./libft -I./minilibx-linux

OBJS_DIR	=	./obj
OBJS		=	$(MAIN_OBJ) \
				$(UTILS_OBJ) \
				$(SCENE_OBJ) \
				$(HIT_OBJ)	\
				$(RAY_OBJ)

MAIN_DIR	=	./src
MAIN_SRC	= 	main.c
MAIN_OBJ	=	$(addprefix $(OBJS_DIR)/, $(MAIN_SRC:.c=.o))

SCENE_DIR	=	$(MAIN_DIR)/scene
SCENE_SRC	=	scene.c
SCENE_OBJ	=	$(addprefix $(OBJS_DIR)/, $(SCENE_SRC:.c=.o))

TRACE_DIR	=	$(MAIN_DIR)/trace

RAY_DIR		=	$(TRACE_DIR)/ray
RAY_SRC		=	ray.c phong_lighting.c
RAY_OBJ		=	$(addprefix $(OBJS_DIR)/, $(RAY_SRC:.c=.o))

HIT_DIR		=	$(TRACE_DIR)/hit
HIT_SRC		=	hit_sphere.c hit.c normal.c
HIT_OBJ		=	$(addprefix $(OBJS_DIR)/, $(HIT_SRC:.c=.o))

UTILS_DIR	=	$(MAIN_DIR)/utils
UTILS_SRC	=	err_msg.c  ft_convert.c  ft_str.c  obj_utils.c vec_utils2.c	\
				vec_utils3.c  vec_utils.c
UTILS_OBJ	=	$(addprefix $(OBJS_DIR)/, $(UTILS_SRC:.c=.o))

PARSE_DIR	=	$(MAIN_DIR)/parse
PARSE_SRC	=	file_fmt.c	file_validate.c	parse_vec.c
PARSE_OBJ	=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRC:.c=.o))

MLX_U_DIR	=	$(MAIN_DIR)/mlx_utils
MLX_U_SRC	=	mlx_key_binding.c my_mlx_pixel_put.c
MLX_U_OBJ	=	$(addprefix $(OBJS_DIR)/, $(MLX_U_SRC:.c=.o))

MLXDIR		=	./minilibx-linux
MLX			=	$(MLXDIR)/libmlx.a

LIBFTDIR	=	./libft
LIBFT		=	$(LIBFTDIR)/libft.a

vpath %.c	$(UTILS_DIR) $(SCENE_DIR) $(TRACE_DIR) $(MAIN_DIR)	$(HIT_DIR)	\
			$(RAY_DIR)	$(PARSE_DIR)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(MLXLIB)

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(MLX) :
	@make -C $(MLXDIR)

$(LIBFT) :
	@make -C $(LIBFTDIR) all

clean :
	rm -rf $(OBJS_DIR)
	@make -C $(MLXDIR) clean
	@make -C $(LIBFTDIR) clean

fclean : clean
	rm -f $(NAME)
	@make -C $(MLXDIR) clean
	@make -C $(LIBFTDIR) fclean

re : fclean all

.PHONY : all clean fclean re
