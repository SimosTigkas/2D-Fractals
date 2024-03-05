NAME = fractol
LIBMLX_PATH = ./MLX42
LIBMLX = $(LIBMLX_PATH)/build/libmlx42.a
LIBFTA_PATH = ./libfta
LIBFTA = $(LIBFTA_PATH)/libft.a
CFLAGS = -Wall -Wextra -Werror -Wunreachable-code -Ofast
HEADERS = -I ./incudes -I ./include -I $(LIBMLX_PATH)/include/ -I "/Users/stigkas/.brew/opt/glfw/include"
LIBS = $(LIBFTA) $(LIBMLX) -L/Users/stigkas/.brew/lib/ -ldl -lglfw -pthread -lm
SRCS = \
	complex_utils.c \
	fractol.c \
	hooks.c \
	init.c \
	render.c \
	utils.c \
	exit_errors.c

OBJS = $(SRCS:.c=.o)
# BONUS_OBJ = $(SRCS_BONUS:.c=.o)
RM = rm -f

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX_PATH) -B $(LIBMLX_PATH)/build && make -C $(LIBMLX_PATH)/build -j4

$(NAME): $(LIBMLX) $(SRCS)
	cd libfta && $(MAKE)
	cc $(CFLAGS) $(HEADERS) $(SRCS) $(LIBS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX_PATH)/build
	cd $(LIBFTA_PATH) && make clean

fclean: clean
	@rm -rf $(NAME)
	cd $(LIBFTA_PATH) && make fclean

re: fclean all

# bonus: $(NAME) $(BONUS_OBJ)
# 	ar crs $(BONUS_OBJ)
# 	cd $(LIBFTA_PATH) && make bonus

.PHONY: all clean fclean re libmlx #bonus
