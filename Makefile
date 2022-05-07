CC			= c++
CFLAGS	= -g3 -Wall -Wextra -Werror -Wno-long-long -std=c++98 -Wshadow -pedantic
INCPATH = -I./ -I./vector -I./iterator -I./utils -I./stack -I./rbtree
OBJDIR	= obj
STD			?=
NAME		= containers
NAMET		?=
GTEST		= test

SRC			=	main.cpp \

SRCT		=	unit.cpp \

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
					rbtree.hpp \

OBJ			= $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJT			= $(SRCT:%.cpp=$(OBJDIR)/%.o)

#this bugs when rbtree obj dir is already created -- investigate
VPATH		= vector stack utils iterator rbtree tests

$(NAME):	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAMET):	$(OBJDIR) $(OBJT)
		$(CC) $(CFLAGS) $(OBJT) -o $(NAMET)

$(GTEST):	$(OBJDIR) $(OBJ) tests/unit.cpp
		STD=-DSTD=1 NAMET=accstd make accstd
		rm obj/unit.o
		NAMET=accft make accft
		rm obj/unit.o

$(OBJDIR)/%.o: %.cpp $(INC)
		$(CC) $(CFLAGS) $(STD) -c $< -o $@ $(INCPATH)

clean:
		make -C ./rbtree clean
		rm -rf $(OBJDIR)

fclean:	clean
		rm -rf $(NAME) accft accstd

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean $(NAME)
