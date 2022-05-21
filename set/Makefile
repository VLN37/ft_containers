CC			= c++
CFLAGS	= -g3 -Wall -Wextra -Werror -Wno-long-long -std=c++98 -pedantic
CFLAGS	+= -MMD -MP #compiler flags to generate the dependancy file

ROOT		= ../
INCPATH = -I../iterator -I../utils -I../rbtree
OBJDIR	= obj

ACCTEST		= accuracy
PERFTEST	= performance
NAME			= set_test
PERF			= set_perf_
ACC				= set_acc_
STD				?=
NAME_ACC	?=
NAME_PERF	?=

SRC				=	main.cpp \

SRC_ACC		=	main_accuracy.cpp \

SRC_PERF	= main_performance.cpp \

INC				=	set.hpp \
						iterator_tree.hpp \
						pair.hpp \
						rbtree.hpp \

OBJ				= $(SRC:%.cpp=$(OBJDIR)/%.o)
OBJ_ACC		= $(SRC_ACC:%.cpp=$(OBJDIR)/%.o)
OBJ_PERF	= $(SRC_PERF:%.cpp=$(OBJDIR)/%.o)
DEPS			= $(SRC:%.cpp=$(OBJDIR)/%.d)

vpath %.cpp ../utils ../iterator ../rbtree
vpath %.hpp ../utils ../iterator ../rbtree

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
