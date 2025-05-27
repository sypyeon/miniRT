CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g
NAME		=	miniRT
INCLUDES	=	-I./includes -I./libft -I./minilibx-linux

OBJS_DIR	=	./obj
OBJS		=	$(SOURCES_OBJ)	\
				$(PARSE_OBJ)

SOURCES		= 	main.c
SOURCES_OBJ =	$(addprefix $(OBJS_DIR)/, $(SOURCES:.c=.o))

PARSE_DIR	=	./parse
PARSE_SRC	=	
PARSE_OBJ	=	$(addprefix $(OBJS_DIR)/, $(PARSE_SRC:.c=.o))

MLXDIR		=	./minilibx-linux
MLX			=	$(MLXDIR)/libmlx.a

LIBFTDIR	=	./libft
LIBFT		=	$(LIBFTDIR)/libft.a

vpath %.c	$(PARSE_DIR)

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -lreadline

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
