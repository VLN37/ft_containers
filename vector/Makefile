CC			= c++
CFLAGS	= -g3 -Wall -Wextra -Werror -Wno-long-long -std=c++98 -Wshadow -pedantic
CFLAGS	+= -MMD -MP #compiler flags to generate the dependancy file

ROOT		= ../
INCPATH = -I./ -I../ -I../iterator -I../utils -I../stack -I../rbtree -I../tests
OBJDIR	= obj
STD			?=
NAME		= vec
NAME_ACC	?=
GTEST		= test

SRC			=	main.cpp \

SRC_ACC		=	main_accuracy.cpp \


INC			=	vector.hpp \
					vector_members.tpp \
					vector_constructors.tpp \
					vector_operators.tpp \
					stack.hpp \
					iterator_vector.hpp \
					iterator_base.hpp \
					iterator_funcs.hpp \
					type_traits.hpp \
					algo.hpp \
					pair.hpp \
					rbtree.hpp \

OBJ			= $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJ_ACC	= $(SRC_ACC:%.cpp=$(OBJDIR)/%.o)
DEPS		= $(SRC:%.cpp=$(OBJDIR)/%.d)

# VPATH = vector stack utils iterator rbtree tests
vpath %.cpp stack utils iterator rbtree tests
vpath %.hpp stack utils iterator rbtree tests

$(NAME):	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_ACC):	$(OBJDIR) $(OBJ_ACC)
		$(CC) $(CFLAGS) $(OBJ_ACC) -o $(ROOT)$(NAME_ACC)

$(GTEST):	$(OBJDIR) $(OBJ)
		STD=-DSTD=1 NAME_ACC=accstd make accstd
		rm obj/main_accuracy.o
		NAME_ACC=accft make accft
		rm obj/main_accuracy.o

$(OBJDIR)/%.o: %.cpp
		$(CC) $(CFLAGS) $(STD) -c $< -o $@ $(INCPATH)

clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -rf $(NAME) ../accft ../accstd

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean $(NAME)

-include $(DEPS)
