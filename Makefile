NAME = libasm.a
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
OBJS = $(SRCS:.s=.o)
ASM = nasm
ASMFLAGS = -f elf64
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.s
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) test_libasm main.o

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAME) -o test_libasm

.PHONY: all clean fclean re test