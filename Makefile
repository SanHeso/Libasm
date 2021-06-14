NAME = libasm.a

HEADER = libasm.h

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

OBJS = ${SRCS:.s=.o}

ARCH = ar rcs

NASM = nasm

NFLAGS = -f macho64 -g

GREEN = "\033[0;32m"
CYAN = "\033[0;36m"
EOC = "\033[0m"

all:		$(NAME)

$(NAME):	$(OBJS) $(HEADER)
			@$(ARCH) $(NAME) $^
			@ranlib $(NAME)
			@echo $(CYAN)"$(NAME) is complete!" $(EOC)

%.o:		%.s
			@$(NASM) $(NFLAGS) $<

run:		all
			@gcc main_test.c $(NAME) && ./a.out

clean:
			@rm -f $(OBJS)
			@rm -f a.out
			@echo $(GREEN)"Clean complete!" $(EOC)

fclean:		clean
			@rm -f $(NAME)
			@echo $(GREEN)"Fclean complete!" $(EOC)

re:			fclean all

.PHONY:		all clean fclean re