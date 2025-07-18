CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	miniRT
MLXLIB		=	-Lminilibx-linux -lmlx -lX11 -lXext -lm
INCLUDES	=	-I./includes -I./libft -I./minilibx-linux

OBJS_DIR	=	./obj
OBJS		=	$(MAIN_OBJ) \
				$(UTILS_OBJ) \
				$(SCENE_OBJ) \
				$(PRINT_OBJ) \
				$(HIT_OBJ)	\
				$(RAY_OBJ)

MAIN_DIR	=	./src
MAIN_SRC	= 	main.c
MAIN_OBJ	=	$(addprefix $(OBJS_DIR)/, $(MAIN_SRC:.c=.o))

SCENE_DIR	=	$(MAIN_DIR)/scene
SCENE_SRC	=	canvas.c scene.c object_create.c
SCENE_OBJ	=	$(addprefix $(OBJS_DIR)/, $(SCENE_SRC:.c=.o))

TRACE_DIR	=	$(MAIN_DIR)/trace

RAY_DIR		=	$(TRACE_DIR)/ray
RAY_SRC		=	ray.c phong_lighting.c
RAY_OBJ		=	$(addprefix $(OBJS_DIR)/, $(RAY_SRC:.c=.o))

HIT_DIR		=	$(TRACE_DIR)/hit
HIT_SRC		=	hit_sphere.c hit.c normal.c
HIT_OBJ		=	$(addprefix $(OBJS_DIR)/, $(HIT_SRC:.c=.o))

UTILS_DIR	=	$(MAIN_DIR)/utils
UTILS_SRC	=	vec_utils.c object_utils.c
UTILS_OBJ	=	$(addprefix $(OBJS_DIR)/, $(UTILS_SRC:.c=.o))

PRINT_DIR	=	$(MAIN_DIR)/print
PRINT_SRC	=	print.c
PRINT_OBJ	=	$(addprefix $(OBJS_DIR)/, $(PRINT_SRC:.c=.o))

MLXDIR		=	./minilibx-linux
MLX			=	$(MLXDIR)/libmlx.a

LIBFTDIR	=	./libft
LIBFT		=	$(LIBFTDIR)/libft.a

vpath %.c	$(UTILS_DIR) $(SCENE_DIR) $(TRACE_DIR) $(PRINT_DIR) $(MAIN_DIR)	\
			$(HIT_DIR)	$(RAY_DIR)

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
