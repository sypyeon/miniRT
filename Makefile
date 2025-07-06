CC := cc

CFLAGS := -Wall -Wextra -Werror \
	-I/usr/include -Iminilibx-linux -g

BFLAGS := -Lminilibx-linux -lmlx_Linux -L/usr/lib -Iminilibx-linux \
	-Lft_printf -lftprintf -lXext -lX11 -lm -lz

NAME := miniRT

SRCS := src/main.c src/dvec.c src/dvec2.c src/dmatrix.c src/dmatrix2.c \
	src/dmatrix3.c src/dmatrix4.c src/view.c src/view2.c

OBJS := $(patsubst src/%.c,build/%.o,$(SRCS))

all: $(NAME)


$(NAME): $(OBJS)
	make -C minilibx-linux
	make -C ft_printf
	$(CC) $(OBJS) $(BFLAGS) -o $(NAME)


$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $(patsubst build/%.o,src/%.c,$@)
	mkdir -p build
	mv $(patsubst build/%.o,%.o,$@) $@


clean:
	rm -rf build/
	make clean -C minilibx-linux
	make clean -C ft_printf


fclean: clean
	rm -f $(NAME)
	make fclean -C ft_printf


re: fclean all


.PHONY: all clean fclean re
