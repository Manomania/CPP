########################################################################################################################
#                                                      VARIABLES                                                       #
########################################################################################################################

AUTHOR				:=  maximart
NAME				:=	ex05
HEADER				=	$(INC_DIR)
CC 					:=	c++
CFLAGS 				:=	-Wall -Wextra -Werror
CFLAGS				+=	-std=c++98
AR					:=	ar rcs
RM					:=	rm -f

SRC_F				=	main \
						Harl
HDR_F				=	Harl
SRC					=	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_F)))
OBJ 				=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_F)))
HDR					=	$(addprefix $(INC_DIR), $(addsuffix .hpp, $(HDR_F)))
DEP 				=	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_F)))

########################################################################################################################
#                                                      DIRECTORY                                                       #
########################################################################################################################

SRC_DIR				:=	src/
OBJ_DIR				:=	obj/
INC_DIR				:=	include/

########################################################################################################################
#                                                       TARGETS                                                        #
########################################################################################################################

.print_header:
							$(call DISPLAY_TITLE)
							$(call SEPARATOR)
							$(call BUILD)
							$(call SEPARATOR)

all:					.print_header $(NAME)

clean:					.print_header
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(OBJ_DIR)]:" "$(GREEN)[✓]$(DEF_COLOR)\n"
							@rm -rf $(OBJ_DIR)
							@printf "$(RED)=> Deleted!$(DEF_COLOR)\n"
							$(call SEPARATOR)

fclean: 				clean
							@printf "%$(SPACEMENT)b%b" "$(BLUE)[$(NAME)]:" "$(GREEN)[✓]$(DEF_COLOR)\n"
							@$(RM) $(NAME)
							@printf "$(RED)=> Deleted!$(DEF_COLOR)\n"
							$(call SEPARATOR)

re: 					.print_header fclean all

.PHONY: 				all clean fclean re

########################################################################################################################
#                                                       COMMANDS                                                       #
########################################################################################################################

$(NAME):				$(OBJ)
							@$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o: 			$(SRC_DIR)%.cpp $(INC_DIR)
							@mkdir -p $(dir $@)
							@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
							$(call PROGRESS_BAR_PERCENTAGE)
							$(if $(filter $(COMPILED_SRCS),$(SRCS_TO_COMPILE)),$(call SEPARATOR))

########################################################################################################################
#                                                       COLOURS                                                        #
########################################################################################################################

DEF_COLOR			:=	\033[0;39m
ORANGE				:=	\033[0;33m
GRAY				:=	\033[0;90m
RED					:=	\033[0;91m
GREEN				:=	\033[1;92m
YELLOW				:=	\033[1;93m
BLUE				:=	\033[0;94m
MAGENTA				:=	\033[0;95m
CYAN				:=	\033[0;96m
WHITE				:=	\033[0;97m
PURPLE				:=	\033[0;35m

########################################################################################################################
#                                                       DISPLAY                                                        #
########################################################################################################################

SPACEMENT			:=	-41
COMPILED_SRCS		:=	0
FRAMES				:=	⠋ ⠙ ⠹ ⠸ ⠼ ⠴ ⠦ ⠧ ⠇ ⠏
SLEEP_FRAME			:=	0.001
SRCS_TO_COMPILE		=	$(shell find $(SRC_DIR) -type f -name "*.cpp" -newer $(NAME) 2>/dev/null | wc -l)

ifeq ($(SRCS_TO_COMPILE),0)
	SRCS_TO_COMPILE =	$(shell find $(SRC_DIR) -type f -name "*.cpp" 2>/dev/null | wc -l)
endif

define PROGRESS_BAR_PERCENTAGE
						$(eval COMPILED_SRCS := $(shell expr $(COMPILED_SRCS) + 1))
						@if [ $(COMPILED_SRCS) -eq 1 ]; then \
							printf "$(BLUE)[$(NAME)]:$(DEF_COLOR)\n"; \
						fi
						@percentage=$$(if [ $(SRCS_TO_COMPILE) -eq 0 ]; then echo 0; else echo "scale=0; $(COMPILED_SRCS) * 100 / $(SRCS_TO_COMPILE)" | bc; fi); \
						for frame in $(FRAMES); do \
							printf "\r$$frame Compiling... [%d/%d] %d%%" $(COMPILED_SRCS) $(SRCS_TO_COMPILE) $$percentage; \
							sleep $(SLEEP_FRAME); \
						done; \
						if [ $(COMPILED_SRCS) -eq $(SRCS_TO_COMPILE) ]; then \
							printf "%-42b%b" "\r$(GREEN)Compilation finished [$(COMPILED_SRCS)/$(SRCS_TO_COMPILE)]" "$(GREEN)[✓]$(DEF_COLOR)\n"; \
						fi
endef

#TITLE ASCII ART - SLANT
define	DISPLAY_TITLE
						@echo "$(RED)			   __________  ____ "
						@echo "$(ORANGE)			  / ____/ __ \\/ __ \\"
						@echo "$(YELLOW)			 / /   / /_/ / /_/ /"
						@echo "$(GREEN)			/ /___/ ____/ ____/ "
						@echo "$(BLUE)			\\____/_/   /_/      "
						@printf "$(PURPLE)			                    $(DEF_COLOR)"
endef

define	SEPARATOR
						@printf "\n"
						@echo "$(ORANGE)--------------------------------------------------------------------------$(DEF_COLOR)";
						@printf "\n"
endef

define	BUILD
						@printf "%-47b%b" "$(GREEN)AUTHOR:$(DEF_COLOR)" "$(AUTHOR)\n";
						@printf "%-47b%b" "$(GREEN)NAME:$(DEF_COLOR)" "$(NAME)\n";
						@printf "%-47b%b" "$(GREEN)CC:$(DEF_COLOR)" "$(CC)\n";
						@printf "%-47b%b" "$(GREEN)FLAGS:$(DEF_COLOR)" "$(CFLAGS)\n";
endef

-include $(DEP)
