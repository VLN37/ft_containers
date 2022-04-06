CC 		= c++
CFLAGS 	=  -g3 -Wall -Wextra -Werror -std=c++98 -Wshadow -pedantic
NAME 	= containers

SRC		=	main.cpp \

INC		=	vector.hpp \
			vector.tpp \
			vector_constructors.tpp \
			vector_operators.tpp \
			type_traits.hpp \
			iterator.hpp \

OBJ		= $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJDIR	= obj

$(NAME):	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o:	%.cpp $(INC)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -rf $(NAME)

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean $(NAME)
