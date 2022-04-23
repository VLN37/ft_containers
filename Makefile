CC			= c++
CFLAGS	= -g3 -Wall -Wextra -Werror -Wno-long-long -std=c++98 -Wshadow -pedantic
INCPATH = -I./ -I./vector -I./iterator -I./utils -I./stack
STD			= -DSTD=1
NAME		= containers
GTEST		= perfft

SRC			=	main.cpp \

SRCT		=	tests/unit.cpp \

INC			=	vector.hpp \
					vector_members.tpp \
					vector_constructors.tpp \
					vector_operators.tpp \
					stack.hpp \
					iterator.hpp \
					iterator_base.hpp \
					iterator_funcs.hpp \
					type_traits.hpp \
					algo.hpp \
					pair.hpp \

OBJ			= $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJDIR	= obj

VPATH		= vector stack utils iterator

$(NAME):	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(GTEST):	$(OBJDIR) $(OBJ) tests/unit.cpp
		$(CC) $(CFLAGS) $(SRCT) -o perfstd $(STD) $(INCPATH)
		$(CC) $(CFLAGS) $(SRCT) -o perfft $(INCPATH)

$(OBJDIR)/%.o: %.cpp $(INC)
		$(CC) $(CFLAGS) -c $< -o $@ $(INCPATH)

clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -rf $(NAME) perfft perfstd

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean $(NAME)
