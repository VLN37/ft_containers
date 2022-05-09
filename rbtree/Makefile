CC			= c++
CFLAGS	= -Wall -Wextra -Werror -g3 -std=c++98 -pedantic
NAME		= rbtree

SRC			= treemain.cpp \

INC			= rbtree.hpp \
					iterator_tree.hpp \
					pair.hpp \

INCPATH = -I../iterator -I../utils

OBJ			= $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJDIR  = obj
VPATH		= ../utils

$(NAME):	$(OBJDIR) $(OBJ) $(INC)
					$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o:	%.cpp $(INC)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCPATH)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

re:	fclean $(NAME)
