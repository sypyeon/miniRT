CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	miniRT
INCLUDES	=	-I./includes -I./libft -I./minilibx-linux

OBJS_DIR	=	./obj
OBJS		=	$(SOURCES_OBJ)	\
				$(PARSE_OBJ)	\
				$(V_UTIL_OBJ)

SOURCES		= 	main.c
SOURCES_OBJ =	$(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

PARSE_DIR	=	./parse
PARSE_SRC	=	rt_file_format.c	rt_file_validate.c	rt_strtod.c
PARSE_OBJ	=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRC:.c=.o))

V_UTIL_DIR	=	./vector_utils
V_UTIL_SRC	=	rt_min_vec.c	rt_set_vec.c	rt_vec_calculate.c			\
				rt_vec_init.c	rt_vec_length.c	rt_vec_multiply_divide.c	\
				rt_vec_plus_minus.c
V_UTIL_OBJ	=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRC:.c=.o))

UTILS_DIR	=	./utils
UTILS_SRC	=	rt_err_msg.c
UTILS_OBJ	=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRC:.c=.o))

MLXDIR		=	./minilibx-linux
MLX			=	$(MLXDIR)/libmlx.a

LIBFTDIR	=	./libft
LIBFT		=	$(LIBFTDIR)/libft.a

vpath %.c	$(PARSE_DIR) $(UTILS_DIR) $(V_UTIL_DIR)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $@ $^

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
