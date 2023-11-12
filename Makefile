# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iestero- <iestero-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 11:05:14 by iestero-          #+#    #+#              #
#    Updated: 2023/08/14 09:24:00 by iestero-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variable

NAME				=	push_swap
NAME_BONUS			=	checker

LIBS_DIR			=	libs
LIBPUSHSWAP			=	$(LIBS_DIR)/libPushSwap.a
LIBCHECKER			=	$(LIBS_DIR)/libChecker.a


LIBFT_DIR			=	./libft
LIBFT				=	$(LIBFT_DIR)/libft.a


OBJ_DIR				=	build
OBJBNS_DIR			=	buildbonus
SRC_DIR				=	src
SRCBNS_DIR			= 	srcbonus

INC_DIR				=	inc
INCBONUS_DIR		=	incbonus

OPRTS_DIR			=	operations
UTILS_DIR			=	utils
MAIN_DIR			=	main
ALGO_DIR			=	algo

LDLIBS				=	$(LIBPUSHSWAP) $(LIBFT)
LDLIBS_BONUS		=	$(LIBCHECKER) $(LIBFT)

CC					=	gcc

CFLAGS				=	-g -Wall -Wextra -Werror $(INCLUDES) #$(SANITIZE)
CFLAGS_BONUS		=	-g -Wall -Wextra -Werror $(INCLUDES_BONUS) #$(SANITIZE) 
LDFLAGS				=	$(LDLIBS) #$(SANITIZE)
LDFLAGS_BONUS		=	$(LDLIBS_BONUS) #$(SANITIZE)
INCLUDES			=	-I$(INC_DIR) -I$(addsuffix $(INC_DIR), $(LIBFT_DIR)/)
INCLUDES_BONUS		=	-I$(INCBONUS_DIR) -I$(addsuffix $(INC_DIR), $(LIBFT_DIR)/)

SANITIZE			=	-fsanitize=address

MKDIR				=	mkdir -p
RM					=	rm -f
AR					= 	ar

ARFLAGS 			= 	rsc

# Source

MAIN_FILES	=	push_swap.c


OPRTS_FILES	=	swap.c				\
				rotate.c			\
				reverse_rotate.c	\
				push.c				\


UTILS_FILES = 	list_numbers.c		\
				format_error.c		\
				asign_index.c		\
				nb_abs.c 			\


ALGO_FILES	=	auxiliar_algo.c 	\
				main_algo.c 		\
				move_element.c 		\
				cost.c				\
				position.c			\
				IsSorted.c			\

SRCS_FILES	= 	$(addprefix $(UTILS_DIR)/, $(UTILS_FILES))		\
				$(addprefix $(OPRTS_DIR)/, $(OPRTS_FILES))		\
				$(addprefix $(MAIN_DIR)/, $(MAIN_FILES))		\
				$(addprefix $(ALGO_DIR)/, $(ALGO_FILES))		\

SRCS 		=	$(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS 		=	$(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))
DIRS		=	$(OBJ_DIR)  $(addprefix $(OBJ_DIR)/, $(OPRTS_DIR) $(UTILS_DIR) $(MAIN_DIR) $(ALGO_DIR))

OBJ_MAIN	=	$(addprefix $(OBJ_DIR)/, $(addprefix $(MAIN_DIR)/, $(MAIN_FILES:.c=.o)))

# Source Bonus

MAIN_BONUS_FILES	=	checker_bonus.c

UTILS_BONUS_FILES	=	format_error_bonus.c		\
						IsSorted_bonus.c			\
						list_numbers_bonus.c		\
						execute_operation_bonus.c	\

OPRTS_BONUS_FILES	=	swap_bonus.c				\
						rotate_bonus.c			\
						reverse_rotate_bonus.c	\
						push_bonus.c				\

SRCSBONUS_FILES		=	$(addprefix $(UTILS_DIR)/, $(UTILS_BONUS_FILES))		\
						$(addprefix $(OPRTS_DIR)/, $(OPRTS_BONUS_FILES))		\
						$(addprefix $(MAIN_DIR)/, $(MAIN_BONUS_FILES))			\

SRCSBONUS 			=	$(addprefix $(SRCBNS_DIR)/, $(SRCSBONUS_FILES))
OBJSBONUS 			=	$(addprefix $(OBJBNS_DIR)/, $(SRCSBONUS_FILES:.c=.o))
DIRSBONUS			=	$(OBJBNS_DIR) $(addprefix $(OBJBNS_DIR)/, $(OPRTS_DIR) $(UTILS_DIR) $(MAIN_DIR))

OBJBONUS_MAIN		=	$(addprefix $(OBJBNS_DIR)/, $(addprefix $(MAIN_DIR)/, $(MAIN_BONUS_FILES:.c=.o)))

# Rules

all:				$(NAME)

bonus:				$(NAME_BONUS)

clean:
	make fclean -C $(LIBFT_DIR)
	$(RM) -r $(LIBS_DIR)
	$(RM) -r $(OBJ_DIR)
	$(RM) -r $(OBJBNS_DIR)

fclean:				clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re:					fclean all


# Mandatory

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c | $(DIRS) $(LIBS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):			$(LIBPUSHSWAP) $(LIBFT) $(OBJ_MAIN)
	$(CC) $(OBJ_MAIN) $(LDFLAGS) -o $@	

$(LIBFT):
	make -C $(LIBFT_DIR)

$(LIBPUSHSWAP): 	$(OBJS)
	$(AR) $(ARFLAGS) $@ $(OBJS)

$(DIRS):
	$(MKDIR) $@

$(LIBS_DIR):
	$(MKDIR) $@


# Bonus

$(OBJBNS_DIR)/%.o:		$(SRCBNS_DIR)/%.c | $(DIRSBONUS) $(LIBS_DIR) 
	$(CC) $(CFLAGS_BONUS) -c $< -o $@

$(NAME_BONUS):			$(LIBCHECKER) $(LIBFT) $(OBJBONUS_MAIN)
	$(CC) $(OBJBONUS_MAIN) $(LDFLAGS_BONUS) -o $@	

$(LIBCHECKER): 	$(OBJSBONUS)
	$(AR) $(ARFLAGS) $@ $(OBJSBONUS)

$(DIRSBONUS):
	$(MKDIR) $@

.SILENT:			clean fclean
.PHONY:				all clean fclean re bonus