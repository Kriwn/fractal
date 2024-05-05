NAME	= fractal
CFLAGS	:= -Wextra -Wall -Werror
# CFLAGS	= -g
LIBMLX	= ./lib/MLX42

HEADERS	= -I ./include -I $(LIBMLX)/include
LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	= ./mlx_utis.c ./fractal.c ./utils.c ./error.c ./mandelbrot.c ./julia.c ./complex.c ./ft_atof.c

SRCS_BONUS	=  ./complex.c  ./mlx_utis.c ./celtic_bonus.c  ./julia.c ./utils_bonus.c  ./error_bonus.c  ./ft_atof.c ./mandelbrot.c  ./fractal_bonus.c

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS)
	@$(CC)  $(CFLAGS) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

bonus: libmlx $(OBJS_BONUS)
	@$(CC)  $(CFLAGS) $(OBJS_BONUS) $(LIBS) $(HEADERS) -o $(NAME)

%.o: %.c $(HEADER_FILE)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx, bonus
