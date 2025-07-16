CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	miniRT
MLXLIB		=	-Lminilibx-linux -lmlx -lX11 -lXext -lm
INCLUDES	=	-I./includes -I./libft -I./minilibx-linux

OBJS_DIR	=	./obj
OBJS		=	$(SOURCES_OBJ)	\
				$(PARSE_OBJ)	\
				$(UTILS_OBJ)	\
				$(C_UTIL_OBJ)	\
				$(V_UTIL_OBJ)	\
				$(SCENE_OBJ)	\
				$(KEYBIND_OBJ)	\
				$(TRACE_OBJ)

SOURCES		= 	main.c
SOURCES_OBJ =	$(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

PARSE_DIR	=	./parse
PARSE_SRC	=	rt_file_format.c	rt_file_validate.c	rt_parse_vector.c	\
				check_parse.c
PARSE_OBJ	=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRC:.c=.o))

SCENE_DIR	=	./scene
SCENE_SRC	=	rt_scene.c
SCENE_OBJ	=	$(addprefix $(OBJS_DIR)/, $(SCENE_SRC:.c=.o))

TRACE_DIR	=	./trace
TRACE_SRC	=	rt_ray.c	rt_hit_sphere.c
TRACE_OBJ	=	$(addprefix $(OBJS_DIR)/, $(TRACE_SRC:.c=.o))

V_UTIL_DIR	=	./utils_vector
V_UTIL_SRC	=	rt_vec_add_sum.c	rt_vec_calculate.c	rt_vec_init.c		\
				rt_vec_len.c		rt_vec_min.c		rt_vec_mult_div.c	\
				rt_vec_set.c
V_UTIL_OBJ	=	$(addprefix $(OBJS_DIR)/, $(V_UTIL_SRC:.c=.o))

C_UTIL_DIR	=	./utils_color
C_UTIL_SRC	=	rt_color_add_sum.c	rt_color_calculate.c	rt_color_init.c	\
				rt_color_len.c		rt_color_min.c			rt_color_mult_div.c\
				rt_color_set.c
C_UTIL_OBJ	=	$(addprefix $(OBJS_DIR)/, $(C_UTIL_SRC:.c=.o))

UTILS_DIR	=	./utils
UTILS_SRC	=	rt_err_msg.c		rt_free_utils.c		rt_strcmp.c			\
				rt_tab_to_space.c	rt_strtod.c
UTILS_OBJ	=	$(addprefix $(OBJS_DIR)/, $(UTILS_SRC:.c=.o))

KEYBIND_DIR	=	./keybind
KEYBIND_SRC	=	rt_identify_keycode.c	rt_keybind.c
KEYBIND_OBJ	=	$(addprefix $(OBJS_DIR)/, $(KEYBIND_SRC:.c=.o))

MLXDIR		=	./minilibx-linux
MLX			=	$(MLXDIR)/libmlx.a

LIBFTDIR	=	./libft
LIBFT		=	$(LIBFTDIR)/libft.a

vpath %.c	$(PARSE_DIR) $(UTILS_DIR) $(V_UTIL_DIR) $(SCENE_DIR) $(TRACE_DIR) \
			$(C_UTIL_DIR) $(KEYBIND_DIR)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^ $(MLXLIB)

$(OBJS_DIR)/%.o : %.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(LIBFTDIR) $(INCLUDES) -o $@ -c $<

$(MLX) :
	@make -C $(MLXDIR)

$(LIBFT) :
	@make -C $(LIBFTDIR) all

clean :
	rm -f $(OBJS)
	@make -C $(MLXDIR) clean
	@make -C $(LIBFTDIR) clean

fclean : clean
	rm -f $(NAME)
	@make -C $(MLXDIR) clean
	@make -C $(LIBFTDIR) fclean

re : fclean all

.PHONY : all clean fclean re
