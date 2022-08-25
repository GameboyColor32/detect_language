##
## PROJECT, 2022
## Makefile
## File description:
## language_detect Makefile
##

NAME	=	detect_language

CC	=	gcc

SRC	=	src/main.c		\

DEF	=	src/sort.c		\
		src/levenshtein.c	\
		src/detect_lang.c	\
		src/load_file.c

OBJ	=	$(SRC:.c=.o)

DOBJ	=	$(DEF:.c=.o)

CFLAGS	=	-std=gnu17 -W -Wall -Wextra -I./include/

LDFLAGS	=

.PHONY	:	all clean fclean re test tests_run test_clean test_fclean test_re

all	:	$(NAME)

$(NAME)	:	$(OBJ) $(DOBJ)
		$(CC) -o $(NAME) $(OBJ) $(DOBJ)

warning	:	CFLAGS += -Werror
warning	:	all

debug	:	CFLAGS += -g -DLOG_DEBUG -DDEBUG
debug	:	all

hard_d	:	CFLAGS += -g3 -DHARD_DEBUG -DLOG_DEBUG -DDEBUG
hard_d	:	all

optimal	:	CFLAGS += -O2 -s
optimal	:	all

clean	:
		rm -f $(OBJ) $(DOBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

#########################################

TEST_NAME	=	unit_test

TEST_SRC	=	tests/test_utils.c

TEST_OBJ	=	$(TEST_SRC:.c=.o)

TEST_LDFLAGS	=	--coverage -lcriterion

test		:	$(TEST_NAME)

$(TEST_NAME)	:	$(TEST_OBJ) $(NAME)
			$(CC) -o $(TEST_NAME) $(DOBJ) $(TEST_OBJ) $(TEST_LDFLAGS)

tests_run	:	test
			$(CC) -o $(TEST_NAME) $(DOBJ) $(TEST_OBJ) $(TEST_LDFLAGS)

test_clean	:
			rm -f $(TEST_OBJ)

test_fclean	:	test_clean
			rm -f $(TEST_NAME)

test_re		:	fclean_test test
