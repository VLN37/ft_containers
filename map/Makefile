CC			= c++
CFLAGS	= -Wall -Wextra -Werror -g3 -std=c++98 -pedantic
NAME		= map

SRC			= main.cpp \

INC			= map.hpp \
					iterator_tree.hpp \
					pair.hpp \
					rbtree.hpp \

INCPATH = -I../iterator -I../utils -I../rbtree

OBJ			= $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJDIR  = obj
vpath %.cpp		= ../utils ../iterator ../rbtree
vpath %.hpp		= ../utils ../iterator ../rbtree

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
