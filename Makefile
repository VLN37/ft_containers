CC		= c++
CFLAGS= -g3 -Wall -Wextra -Werror -Wno-long-long -std=c++98 -Wshadow -pedantic
STD		= -DSTD=1
NAME	= containers
GTEST	= test

SRC		=	main.cpp \

SRCT	=	tests/unit.cpp \

INC		=	vector.hpp \
				vector.tpp \
				vector_constructors.tpp \
				vector_operators.tpp \
				type_traits.hpp \
				iterator.hpp \
				iterator_base.hpp \

OBJ		= $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJDIR	= obj

$(NAME):	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(GTEST):	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(SRCT) -o vecstd $(STD) -I./
		$(CC) $(CFLAGS) $(SRCT) -o vecft -I./

$(OBJDIR)/%.o:	%.cpp $(INC)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -rf $(NAME)

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean $(NAME)
