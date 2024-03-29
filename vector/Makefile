CC			= c++
CFLAGS	= -g3 -Wall -Wextra -Werror -Wno-long-long -std=c++98 -Wshadow -pedantic
CFLAGS	+= -MMD -MP #compiler flags to generate the dependancy file

ROOT		= ../
INCPATH = -I./ -I../ -I../iterator -I../utils -I../stack -I../rbtree -I../tests
OBJDIR	= obj

ACCTEST		= accuracy
PERFTEST	= performance
NAME			= vector_test
PERF			= vector_perf_
ACC				= vector_acc_
STD				?=
NAME_ACC	?=
NAME_PERF	?=

SRC				=	main.cpp \

SRC_ACC		=	main_accuracy.cpp \

SRC_PERF	= main_performance.cpp \

INC				=	vector.hpp \
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

OBJ				= $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJ_ACC		= $(SRC_ACC:%.cpp=$(OBJDIR)/%.o)
OBJ_PERF	= $(SRC_PERF:%.cpp=$(OBJDIR)/%.o)
DEPS			= $(SRC:%.cpp=$(OBJDIR)/%.d)

# VPATH = vector stack utils iterator rbtree tests
vpath %.cpp stack utils iterator rbtree tests
vpath %.hpp stack utils iterator rbtree tests

$(NAME):	$(OBJDIR) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME_ACC):	$(OBJDIR) $(OBJ_ACC)
		$(CC) $(CFLAGS) $(OBJ_ACC) -o $(NAME_ACC)

$(NAME_PERF):	$(OBJDIR) $(OBJ_PERF)
		$(CC) $(CFLAGS) $(OBJ_PERF) -o $(NAME_PERF)

$(ACCTEST):	$(OBJDIR) $(OBJ)
		STD=-DSTD=1 NAME_ACC=$(ACC)std make $(ACC)std
		rm obj/main_accuracy.o
		NAME_ACC=$(ACC)ft make $(ACC)ft
		rm obj/main_accuracy.o

$(PERFTEST): $(OBJDIR) $(OBJ)
		STD=-DSTD=1 NAME_PERF=$(PERF)std make $(PERF)std
		rm obj/main_performance.o
		NAME_PERF=$(PERF)ft make $(PERF)ft
		rm obj/main_performance.o

$(OBJDIR)/%.o: %.cpp
		$(CC) $(CFLAGS) $(STD) -c $< -o $@ $(INCPATH)

clean:
		rm -rf $(OBJDIR)

fclean:	clean
		rm -rf $(NAME)
		rm -rf *_perf_*
		rm -rf *_acc_*
		rm -rf *_test

$(OBJDIR):
		mkdir -p $(OBJDIR)

re:		fclean $(NAME)

-include $(DEPS)
