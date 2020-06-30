NAME =			libasm.a

SRCS =			srcs/ft_strlen.s \
			srcs/ft_strcpy.s \
			srcs/ft_strcmp.s \
			srcs/ft_write.s \
			srcs/ft_read.s \
			srcs/ft_strdup.s

SRCS_BONUS =		srcs_bonus/ft_atoi_base.s \
			srcs_bonus/ft_list_push_front.s \
			srcs_bonus/ft_list_size.s \
			srcs_bonus/ft_list_sort.s \
			srcs_bonus/ft_list_remove_if.s

OBJS =			$(SRCS:.s=.o)

OBJS_BONUS =		$(SRCS_BONUS:.s=.o)

NASM = 			nasm

NASM_FLAGS =		-felf64

CC =			clang

CFLAGS =		-Wall -Werror -Wextra	

EXECUTABLE =		exec_libasm

EXECUTABLE_BONUS =	exec_libasm_bonus

LIBRAIRY =		-L . -lasm -o

#.s.o:			$(SRCS)
#			$(NASM) $(NASM_FLAGS) -s $< -o ${<:.s=.o}

%.o:			%.s
			$(NASM) $(NASM_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
			ar rc $(NAME) $(OBJS)

bonus:			$(OBJS) $(OBJS_BONUS)
			ar rc $(NAME) $(OBJS) $(OBJS_BONUS)

test:			$(NAME)
			$(CC) $(CFLAGS) srcs/main.c $(LIBRAIRY) $(EXECUTABLE) 
			./$(EXECUTABLE)

test_bonus:		bonus
			$(CC) $(CFLAGS) srcs_bonus/main_bonus.c $(LIBRAIRY) $(EXECUTABLE_BONUS)
			./$(EXECUTABLE_BONUS)

clean:			
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean: 		clean
			$(RM) $(EXECUTABLE)
			$(RM) $(EXECUTABLE_BONUS)
			$(RM) $(NAME)

re:			fclean all

re_bonus:		fclean bonus

.PHONY: 		fclean clean all re
