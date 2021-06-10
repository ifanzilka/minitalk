
F_NONE		= \033[37m
F_BOLD		= \033[1m
F_RED		= \033[31m
F_ORANGE	= \033[38m
F_YELLOW	= \033[33m
F_GREEN		= \033[32m
F_CYAN		= \033[36m
F_BLUE		= \033[34m


NAME = clients
NAME2 = servers

FUN_CLIENT = ./client/main \
			./client/base_fun_1 

FUN_SERV = 	./server/main \
				./server/base_fun_1 

FLAGS = -Wall -Wextra -Werror

SRC = $(addsuffix .c, $(FUN_CLIENT))
BIN = $(addsuffix .o, $(FUN_CLIENT))

SRC2 = $(addsuffix .c, $(FUN_SERV))
BIN2 = $(addsuffix .o, $(FUN_SERV))

all: $(NAME) $(NAME2)

$(NAME): $(BIN)
	gcc $(FLAGS) $(BIN) -o $(NAME)

$(NAME2): $(BIN2)
	gcc $(FLAGS) $(BIN2) -o $(NAME2)

%.o: %.c     
	gcc $(FLAGS) -o $@ -c $<

clean:
	/bin/rm -f ./client/*.o
	/bin/rm -f ./server/*.o

fclean: clean
	/bin/rm -f $(NAME) $(NAME2)

re: fclean all

code:
	@echo " ~~~~~~~~~~~~~~~~"
	@echo "$(F_BOLD)  * Make code, *"
	@echo "$(F_BOLD)   * not war! *"
	@echo "$(F_RED)    ..10101.."
	@echo "$(F_ORANGE)  01    1    10"
	@echo "$(F_YELLOW) 10     0     00"
	@echo "$(F_GREEN) 11   .010.   11"
	@echo "$(F_CYAN) 00 .01 1 01. 10"
	@echo "$(F_BLUE)  010   1   110"
	@echo "$(F_BLUE)    110110101$(F_NONE)"

.PHONY:     all clean fclean re bonus code