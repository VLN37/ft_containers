CC			= c++
CFLAGS	= -g3 -Wall -Wextra -Werror -Wno-long-long -std=c++98 -pedantic
CFLAGS	+= -MMD -MP #compiler flags to generate the dependancy file

INCPATH = -I stack -I vector -I map -I set -I rbtree -I iterator -I utils
NAME		=	containers

SRC				=	main.cpp \

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

OBJDIR = obj
OBJ			= $(SRC:%.cpp=$(OBJDIR)/%.o)
DEPS		= $(SRC:%.cpp=$(OBJDIR)/%.d)

$(NAME):	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
		$(CC) $(CFLAGS) $(STD) -c $< -o $@ $(INCPATH)

run: $(NAME)
	./containers

test:	$(OBJDIR) $(OBJ)
	make -s --no-print-directory -C vector performance
	make -s --no-print-directory -C vector accuracy
	make -s --no-print-directory -C stack performance
	make -s --no-print-directory -C stack accuracy
	make -s --no-print-directory -C map performance
	make -s --no-print-directory -C map accuracy
	make -s --no-print-directory -C set performance
	make -s --no-print-directory -C set accuracy


clean:
		rm -rf $(OBJDIR)
		make -s -C stack clean
		make -s -C vector clean
		make -s -C set clean
		make -s -C map clean
		make -s -C rbtree clean

fclean:	clean
		rm -rf $(NAME)
		make -s -C stack fclean
		make -s -C vector fclean
		make -s -C set fclean
		make -s -C map fclean
		make -s -C rbtree fclean

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean test
